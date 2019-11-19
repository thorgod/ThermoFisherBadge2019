// Designed by Michael Leuer 



#include <Arduino.h>

#include <TinyOLED.h>

#include <EEPROM.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>

#include <images.h>
#include <settings.h>
#include <font_score.h>

// The bitmaps for the main blocks
static const int blocks[7] PROGMEM = {
    0x4444, 0x44C0,
    0x4460, 0x0660,
    0x06C0, 0x0E40,
    0x0C60};

// The bitmaps for blocks on the screen
static const uint8_t blockout[16] PROGMEM = {
    0xF8, 0x00, 0x3E, 0x80,
    0x0F, 0xE0, 0x03, 0xF8,
    0x3E, 0x80, 0x0F, 0xE0,
    0x03, 0xF8, 0x3E, 0x00};

// The bitmaps for ghost blocks on the screen
static const uint8_t ghostout[16] PROGMEM = {
    0x88, 0x00, 0x22, 0x80,
    0x08, 0x20, 0x02, 0x88,
    0x22, 0x80, 0x08, 0x20,
    0x02, 0x88, 0x22, 0x00};

// Decode lookup to translate block positions to the 8 columns on the screen
static const uint8_t startDecode[11] PROGMEM = {0, 1, 1, 2, 3, 4, 4, 5, 6, 7, 8};
static const uint8_t endDecode[11] PROGMEM = {1, 2, 3, 3, 4, 5, 6, 6, 7, 8, 8};

void drawGameScreen(int startCol, int endCol, int startRow, int endRow, uint8_t mode);
void displayScore(int score, int xpos, int y);

// Function prototypes - tetris-specific
void playTetris(void);
void handleInput(void);

void drawScreen(int startCol, int endCol, int startRow, int endRow, uint8_t mode);

uint8_t readBlockArray(uint8_t x, uint8_t y);
void writeblockArray(uint8_t x, uint8_t y, bool value);
uint8_t readGhostArray(uint8_t x, uint8_t y);
void writeGhostArray(uint8_t x, uint8_t y, bool value);
void fillGrid(uint8_t value, bool mode);

void rotatePiece(void);
void movePieceDown(void);
void movePieceLeft(void);
void movePieceRight(void);
uint8_t checkCollision(void);
void displayScoreScreen(void);

bool createGhost(void);
void drawGhost(uint8_t action);
void loadPiece(uint8_t pieceNumber, uint8_t row, uint8_t column);
void drawPiece(uint8_t action);

// Variables
struct pieceSpace
{
  uint8_t blocks[4][4];
  int row;
  int column;
};

pieceSpace currentPiece = {0}; // The piece in play
pieceSpace oldPiece = {0};     // Buffer to hold the current piece whilst its manipulated
pieceSpace ghostPiece = {0};   // Current ghost piece

unsigned long moveTime = 0; // Baseline time for current move
unsigned long keyTime = 0;  // Baseline time for current keypress

volatile uint8_t rendering = 0; // Holds the mode of the last keypress (for debounce and stuff)

uint8_t keyLock = 0; // Holds the mode of the last keypress (for debounce and stuff)

uint8_t nextBlockBuffer[8][2]; // The little image of the next block
uint8_t nextPiece = 0;         // The identity of the next piece
uint8_t blockArray[HORIZ][3];  // The uint8_t-array of blocks
uint8_t ghostArray[HORIZ][3];  // The uint8_t-array of ghost pieces
bool stopAnimate;              // True when the game is running

int lastGhostRow = 0; // Buffer to hold previous ghost position - for accurate drawing
int score = 0;        // Score buffer
int topScore = 0;     // High score buffer

bool ghost = 1; // Is the ghost active?

int level = 0; // Current level (increments once per cleared line)

volatile uint8_t screenMode = 0; // 0 Rotation, 1 Tetris, 2 Programing Name,

uint8_t text[16] = {0}; //Variable that stores text to scroll

volatile uint8_t currentPositionText = 0; //Current Position on editing (For screenMode 2)
volatile uint8_t rotationNumber = 0;      //0 Thermo Logo, 1 Text+Re:Inv, 2 AWS Logo, 3 Text+Thermo Fisher

// Arduino stuff
void setup()
{
  randomSeed(analogRead(1));
  DDRB = 0b00000000;       // set PB1 as output (for the speaker)
  PCMSK = 0b00011010;      // pin change mask: listen to portb bit 1
  GIMSK |= 0b00100000;     // enable PCINT interrupt
  MCUCR |= B00000010;      //watch for rising edge
  sei();                   // enable all interrupts
  TinyOLED.ssd1306_init(); // initialise the screen
  keyLock = 0;

  for (uint8_t m = 0; m < 16; m++)
  {
    text[m] = EEPROM.read(m + 3);
    if (text[m] == 0xFF)
    {
      text[m] = 0;
    }
  }
}

unsigned int readVcc()
{
// Read 1.1V reference against AVcc
// set the reference to Vcc and the measurement to the internal 1.1V reference
#if defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
  ADMUX = _BV(REFS0) | _BV(MUX4) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
#elif defined(__AVR_ATtiny24__) || defined(__AVR_ATtiny44__) || defined(__AVR_ATtiny84__)
  ADMUX = _BV(MUX5) | _BV(MUX0);
#elif defined(__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)
  ADMUX = _BV(MUX3) | _BV(MUX2);
#else
  ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
#endif

  //_delay_ms(100); // Wait for Vref to settle
  ADCSRA |= _BV(ADSC); // Start conversion
  while (bit_is_set(ADCSRA, ADSC))
    ; // measuring

  uint8_t low = ADCL;  // must read ADCL first - it then locks ADCH
  uint8_t high = ADCH; // unlocks both

  long result = (high << 8) | low;

  result = (1125300L / result); // Calculate Vcc (in mV); 1125300 = 1.1*1023*1000
  return (unsigned int)result;  // Vcc in millivolts
}

void checkMode()
{
  if (keyLock == 2 && digitalRead(BUTTON_ZERO) == PRESSON && millis() - keyTime > 300)
  {

    screenMode = 2;
    TinyOLED.ssd1306_fillscreen(0x00);
    TinyOLED.charTest(0, 0, text);

    TinyOLED.ssd1306_char_f8x8(16, 2, "TXT");
    delay(500);
    //TinyOLED.ssd1306_fillscreen(0x00);
    while (true)
    {
      if (keyLock == 2 && digitalRead(BUTTON_ZERO) == PRESSON && millis() - keyTime > 300)
      {
        for (uint8_t m = 0; m < 16; m++)
        {
          EEPROM.write(m + 3, text[m]);
        }

        //TinyOLED.ssd1306_fillscreen(0x00);
        TinyOLED.ssd1306_char_f8x8(0, 2, "SAVED");
        screenMode = 0;
        delay(1000);
        break;
      }
    }
  }
  else if (keyLock == 1 && digitalRead(BUTTON_TWO) == PRESSON && millis() - keyTime > 300)
  {
    screenMode = 1;
    TinyOLED.ssd1306_fillscreen(0x00);
    playTetris();
    screenMode = 0;
  }
  else if (keyLock == 3 && digitalRead(BUTTON_ONE) == PRESSON && millis() - keyTime > 300)
  {
    TinyOLED.ssd1306_fillscreen(0x00);
    TinyOLED.ssd1306_char_f8x8(75, 0, "BAT MV");
    TinyOLED.ssd1306_char_f8x8(0, 2, "BY MIKE LEUER");

    displayScore(readVcc(), 0, 117);

    delay(2000);
  }
}
void showScreen()
{
  switch (rotationNumber)
  {
  case 0:
    TinyOLED.draw_bmp(0, 0, 128, 4, img_a_bits); //THERMO LOGO
    break;

  case 1:
    TinyOLED.ssd1306_fillscreen(0x00);
    TinyOLED.charTest(0, 0, text);
    TinyOLED.ssd1306_char_f8x8(8, 2, "THERMO FISHER");

    break;

  case 2:
    TinyOLED.draw_bmp(0, 0, 128, 4, img_b_bits); //AWS LOGO
    break;

  case 3:
    for (uint8_t m = 0; m < 16; m++)
    {
      if (rotationNumber != 3)
      {
        break;
      }
      TinyOLED.charTest(m * 8, 0, text);
      TinyOLED.ssd1306_char_f8x8(m * 8, 2, "AWS RE.INVENT   ");
      checkMode();
      delay(31);
    }
    break;
  }
}
//Main Loop
void loop()
{
  showScreen();

  if (rotationNumber == 3)
  {
    rotationNumber = 0;
  }
  else
  {
    rotationNumber++;
    checkMode();
    delay(500);
  }
}

uint8_t readBlockArray(uint8_t x, uint8_t y)
{
  if (y < 8)
  {
    return ((blockArray[x][0] & B00000001 << y) >> y);
  }
  else if (y > 15)
  {
    return ((blockArray[x][2] & B00000001 << (y - 15)) >> (y - 15));
  }
  else
  {
    return ((blockArray[x][1] & B00000001 << (y - 8)) >> (y - 8));
  }
}

void writeblockArray(uint8_t x, uint8_t y, bool value)
{
  uint8_t arr = 0;
  if (y < 8)
  {
    // do nothing
  }
  else if (y > 15)
  {
    arr = 2;
    y -= 15;
  }
  else
  {
    arr = 1;
    y -= 8;
  }
  if (value == 1)
    blockArray[x][arr] |= B00000001 << y;
  else
    blockArray[x][arr] &= (B11111110 << y) | (B01111111 >> (7 - y));
}

uint8_t readGhostArray(uint8_t x, uint8_t y)
{
  if (y < 8)
  {
    return ((ghostArray[x][0] & B00000001 << y) >> y);
  }
  else if (y > 15)
  {
    return ((ghostArray[x][2] & B00000001 << (y - 15)) >> (y - 15));
  }
  else
  {
    return ((ghostArray[x][1] & B00000001 << (y - 8)) >> (y - 8));
  }
}

void writeGhostArray(uint8_t x, uint8_t y, bool value)
{
  uint8_t arr = 0;
  if (y < 8)
  {
    // do nothing
  }
  else if (y > 15)
  {
    arr = 2;
    y -= 15;
  }
  else
  {
    arr = 1;
    y -= 8;
  }
  if (value == 1)
    ghostArray[x][arr] |= B00000001 << y;
  else
    ghostArray[x][arr] &= (B11111110 << y) | (B01111111 >> (7 - y));
}

void fillGrid(uint8_t value, bool mode)
{
  for (char r = 0; r < VERTMAX; r++)
  {
    for (char c = 0; c < HORIZ; c++)
    {
      if (mode == GHOST)
        writeGhostArray(c, r, value);
      else
        writeblockArray(c, r, value);
    }
  }
}

void rotatePiece(void)
{
  uint8_t blocks[4][4];

  memcpy(oldPiece.blocks, currentPiece.blocks, 16);
  oldPiece.row = currentPiece.row;
  oldPiece.column = currentPiece.column;

  for (uint8_t i = 0; i < 4; ++i)
  {
    for (uint8_t j = 0; j < 4; ++j)
    {
      blocks[j][i] = currentPiece.blocks[4 - i - 1][j];
    }
  }
  oldPiece = currentPiece;
  memcpy(currentPiece.blocks, blocks, 16);
  if (checkCollision())
    currentPiece = oldPiece;
  else
  {
    drawGhost(ERASE);
    if (createGhost())
      drawGhost(DRAW);
  }
}

void movePieceDown(void)
{

  memcpy(oldPiece.blocks, currentPiece.blocks, 16);
  oldPiece.row = currentPiece.row;
  oldPiece.column = currentPiece.column;

  currentPiece.row--;

  //check collision
  if (checkCollision())
  {
    currentPiece.row = oldPiece.row;
    drawPiece(DRAW);
    uint8_t totalRows = 0;

    for (uint8_t row = 0; row < VERTMAX; row++)
    { // scan the whole block (it's quick - there's no drawing to do)
      bool rowFull = 1;
      for (uint8_t col = 0; col < HORIZ; col++)
      { // scan across this row - every column
        if (readBlockArray(col, row) == 0)
          rowFull = 0; // if we hit any blank spaces, the row's not full
      }
      if (rowFull)
      {
        totalRows++;
        for (uint8_t col = 0; col < HORIZ; col++)
          writeblockArray(col, row, 0);                      // write zeros across this whole row
        drawGameScreen(0, HORIZ - 1, row, row + 1, PARTIAL); // draw the row we're removing (for animation)
        delay(30);                                           // delay slightly to make the deletion of rows visible
        for (uint8_t dropCol = 0; dropCol < HORIZ; dropCol++)
        { // for every column
          for (uint8_t dropRow = row; dropRow < VERTMAX - 1; dropRow++)
            writeblockArray(dropCol, dropRow, readBlockArray(dropCol, dropRow + 1)); // drop everything down as many as the row's we've cleared
        }
        row--; // we need to check this row again as it could now have things in it!
      }
    }
    level += totalRows;
    switch (totalRows)
    {
    case 1:
      score += 1;
      break;
    case 2:
      score += 5;
      break;
    case 3:
      score += 10;
      break;
    case 4:
      score += 20;
    }
    drawGameScreen(0, 10, 0, VERTDRAW, FULL);
    displayScore(score, 0, 117);
    loadPiece(nextPiece, STARTY, STARTX);
    if (checkCollision())
    {
      stopAnimate = true;
    }
    else
    {
      loadPiece(nextPiece, STARTY, STARTX);
      drawGhost(ERASE);
      if (createGhost())
        drawGhost(DRAW);
    }
    nextPiece = random(1, 8);
  }
  drawGhost(ERASE);
  if (createGhost())
    drawGhost(DRAW);
}

void movePieceLeft(void)
{
  oldPiece = currentPiece;
  currentPiece.column = currentPiece.column - 1;
  //check collision
  if (checkCollision())
  {
    currentPiece = oldPiece; // back to where it was
  }
  else
  {
    drawGhost(ERASE);
    if (createGhost())
      drawGhost(DRAW);
  }
}

void movePieceRight(void)
{
  oldPiece = currentPiece;
  currentPiece.column = currentPiece.column + 1;
  //check collision
  if (checkCollision())
  {
    currentPiece = oldPiece; // back to where it was
  }
  else
  {
    drawGhost(ERASE);
    if (createGhost())
      drawGhost(DRAW);
  }
}

uint8_t checkCollision(void)
{
  uint8_t pieceRow = 0;
  uint8_t pieceColumn = 0;

  for (int c = currentPiece.column; c < currentPiece.column + 4; c++)
  {
    for (int r = currentPiece.row; r < currentPiece.row + 4; r++)
    {
      if (currentPiece.blocks[pieceColumn][pieceRow])
      {
        if (c < 0)
          return 2;
        if (c > 4)
          return 1;
        if (r < 0)
          return 1;
        if (c >= 0 && r >= 0 && c < HORIZ && r < VERTMAX)
        {
          if (readBlockArray(c, r))
          {
            return 1; //is it on landed blocks?
          }
        }
      }
      pieceRow++;
    }
    pieceRow = 0;
    pieceColumn++;
  }
  return 0;
}

// Interrupt handlers - to make sure every button press is caught promptly!
ISR(PCINT0_vect)
{ // PB0 pin button interrupt

  if (digitalRead(BUTTON_ONE) == PRESSON)
  { //Right
    if (screenMode == 2)
    {
      text[currentPositionText]++;
      if (text[currentPositionText] > 29)
      {
        text[currentPositionText] = 0;
      }
    }
    if (screenMode == 0)
    {
      rotationNumber++;
      if (rotationNumber == 4)
      {
        rotationNumber = 0;
      }
      showScreen();
    }

    keyLock = 3;
    keyTime = millis();
  }
  else if (digitalRead(BUTTON_ZERO) == PRESSON)
  { //Up
    if (screenMode == 2)
    {
      currentPositionText++;
      if (currentPositionText == 16)
      {
        currentPositionText = 0;
      }
      TinyOLED.ssd1306_fillscreen(0x00);
    }

    keyLock = 2;
    keyTime = millis();
  }
  else if (digitalRead(BUTTON_TWO) == PRESSON)
  {
    if (screenMode == 2)
    {
      text[currentPositionText]--;
      if (text[currentPositionText] == 0)
      {
        text[currentPositionText] = 29;
      }
    }
    keyLock = 1;
    keyTime = millis();
  }

  if (screenMode == 1)
  {
    rendering = 1;
    handleInput();
    rendering = 0;
  }
  if (screenMode == 2)
  {

    TinyOLED.charTest(0, 0, text);
    TinyOLED.ssd1306_char_f8x8((uint8_t)(8 * currentPositionText), 2, "/");
    delay(200);
  }
}

void handleInput(void)
{

  //checks if button is simply pressed once and not held down
  if (digitalRead(BUTTON_ZERO) == PRESSOFF && digitalRead(BUTTON_ONE) == PRESSOFF && digitalRead(BUTTON_TWO) == PRESSOFF)
  {
    if (keyLock == 2 && millis() - keyTime < 300)
    { // rotate piece = 2
      drawPiece(ERASE);
      rotatePiece();
      drawPiece(DRAW);
      drawGameScreen(currentPiece.column, currentPiece.column + 4, currentPiece.row, currentPiece.row + 4, PARTIAL);
    }
    else if (keyLock == 1)
    { // right move = 1
      drawPiece(ERASE);
      movePieceRight();
      drawPiece(DRAW);
      drawGameScreen(currentPiece.column - 1, currentPiece.column + 4, currentPiece.row, currentPiece.row + 4, PARTIAL);
    }
    else if (keyLock == 3)
    { //3rd button // left move = 3
      drawPiece(ERASE);
      movePieceLeft();
      drawPiece(DRAW);
      drawGameScreen(currentPiece.column, currentPiece.column + 5, currentPiece.row, currentPiece.row + 4, PARTIAL);
    }
    keyLock = 0;
  }

  delay(30);
}

void displayScore(int score, int xpos, int y)
{
  uint8_t scoreOut[6];
  scoreOut[3] = (score % 10);
  scoreOut[2] = ((score / 10) % 10);
  scoreOut[1] = ((score / 100) % 10);
  scoreOut[0] = ((score / 1000) % 10);

  for (uint8_t x = xpos; x < xpos + 4; x++)
  {
    TinyOLED.ssd1306_setpos(y, x);
    TinyOLED.ssd1306_send_data_start();
    for (uint8_t lxn = 0; lxn < 8; lxn++)
    {
      TinyOLED.ssd1306_send_uint8_t(pgm_read_byte(&font[scoreOut[x - xpos]][7 - lxn]));
    }
    TinyOLED.ssd1306_send_data_stop();
  }
}

void drawGameScreen(int startCol, int endCol, int startRow, int endRow, uint8_t mode)
{
  drawScreen(startCol, endCol, startRow, endRow, mode);

  if (mode == PARTIAL)
  {
    if (ghostPiece.row < lastGhostRow)
    { // ghost has moved down :)
      drawScreen(startCol, endCol, ghostPiece.row, lastGhostRow + 4, mode);
    }
    else
    { // ghost has moved up (presumably!)
      drawScreen(startCol, endCol, lastGhostRow, ghostPiece.row + 4, mode);
    }
  }
}

void drawScreen(int startCol, int endCol, int startRow, int endRow, uint8_t mode)
{
  uint8_t temp = 0;
  uint8_t separator = 0;
  uint8_t reader = 0;
  uint8_t blockReader = 0;

  if (startCol < 0)
    startCol = 0;
  if (endCol > 10)
    endCol = 10;
  if (startRow < 0)
    startRow = 0;
  if (endRow > VERTDRAW)
    endRow = VERTDRAW;

  uint8_t startScreenCol = pgm_read_byte(&startDecode[startCol]);
  uint8_t endScreenCol = pgm_read_byte(&endDecode[endCol]);

  for (uint8_t col = startScreenCol; col < endScreenCol; col++)
  {
    if (col < 4)
      reader = col;
    else if (col < 7)
      reader = col + 1;
    else
      reader = col + 2;
    blockReader = 2 * col;
    TinyOLED.ssd1306_setpos(startRow * 6, col); // Start from the end of this column (working up the screen) on the required row
    TinyOLED.ssd1306_send_data_start();
    if (startRow == 0)
      TinyOLED.ssd1306_send_uint8_t(B11111111);
    else
    {
      if (col == 0)
        TinyOLED.ssd1306_send_uint8_t(B00000001);
      else if (col == 4)
        TinyOLED.ssd1306_send_uint8_t(B10000000);
      else
        TinyOLED.ssd1306_send_uint8_t(B00000000);
    }
    for (uint8_t r = startRow; r < endRow; r++)
    { // For each row in the array of tetris blocks
      for (uint8_t piece = 0; piece < 5; piece++)
      { // for each of the 5 filled lines of the block
        if (col == 0)
          temp = B00000001;
        else if (col == 3)
          temp = B10000000;
        else
          temp = 0x00;    // if we're on the far left, draw the left wall, on the far right draw the right wall, otherwise its a blank separator between blocks
        separator = temp; // we'll need this again later!

        if (readBlockArray(reader, r))
        {
          temp = temp | pgm_read_byte(&blockout[blockReader]);
        }
        if (readBlockArray(reader + 1, r))
        {
          temp = temp | pgm_read_byte(&blockout[blockReader + 1]);
        }

        if (ghost)
        {
          if (readGhostArray(reader, r) && (piece == 0 || piece == 4))
          {
            temp = temp | pgm_read_byte(&blockout[blockReader]);
          }
          else if (readGhostArray(reader, r))
          {
            temp = temp | pgm_read_byte(&ghostout[blockReader]);
          }

          if (readGhostArray(reader + 1, r) && (piece == 0 || piece == 4))
          {
            temp = temp | pgm_read_byte(&blockout[blockReader + 1]);
          }
          else if (readGhostArray(reader + 1, r))
          {
            temp = temp | pgm_read_byte(&ghostout[blockReader + 1]);
          }
        }
        TinyOLED.ssd1306_send_uint8_t(temp);
      }
      TinyOLED.ssd1306_send_uint8_t(separator); // between blocks - same one as we used at the start
    }
    //if (mode == FULL) if (col > 5) for (uint8_t blockline = 0; blockline < 8; blockline++) ssd1306_send_uint8_t(nextBlockBuffer[blockline][col - 6]);
    TinyOLED.ssd1306_send_data_stop();
  }
}

bool createGhost(void)
{
  uint8_t tempRow = currentPiece.row;

  if (currentPiece.row < 3)
    return 0;

  currentPiece.row -= 2;
  while (checkCollision() == 0)
    currentPiece.row--;

  memcpy(ghostPiece.blocks, currentPiece.blocks, 16);
  ghostPiece.row = currentPiece.row + 1;
  ghostPiece.column = currentPiece.column;
  currentPiece.row = tempRow;

  if (ghostPiece.row > currentPiece.row - 3)
    return 0;
  else
    return 1;
}

void loadPiece(uint8_t pieceNumber, uint8_t row, uint8_t column)
{
  uint8_t incr = 0;

  pieceNumber--;

  for (uint8_t lxn = 0; lxn < 4; lxn++)
  {
    for (uint8_t lxn2 = 0; lxn2 < 4; lxn2++)
    {
      if (((1 << incr) & pgm_read_word(&blocks[pieceNumber])) >> incr == 1)
      {
        currentPiece.blocks[lxn][lxn2] = 1;
      }
      else
        currentPiece.blocks[lxn][lxn2] = 0;
      incr++;
    }
  }
  currentPiece.row = row;
  currentPiece.column = column;
}

void drawPiece(uint8_t action)
{
  for (uint8_t lxn = 0; lxn < 4; lxn++)
  {
    for (uint8_t lxn2 = 0; lxn2 < 4; lxn2++)
    {
      if (currentPiece.blocks[lxn][lxn2] == 1)
      {
        if (action == DRAW)
          writeblockArray(currentPiece.column + lxn, currentPiece.row + lxn2, 1);
        else if (action == ERASE)
          writeblockArray(currentPiece.column + lxn, currentPiece.row + lxn2, 0);
      }
    }
  }
}

void drawGhost(uint8_t action)
{
  for (uint8_t lxn = 0; lxn < 4; lxn++)
  {
    for (uint8_t lxn2 = 0; lxn2 < 4; lxn2++)
    {
      if (ghostPiece.blocks[lxn][lxn2] == 1)
      {
        if (action == DRAW)
          writeGhostArray(ghostPiece.column + lxn, ghostPiece.row + lxn2, 1);
        else if (action == ERASE)
        {
          writeGhostArray(ghostPiece.column + lxn, ghostPiece.row + lxn2, 0);
          lastGhostRow = ghostPiece.row;
        }
      }
    }
  }
}

void playTetris(void)
{
  stopAnimate = 0;
  score = 0;
  keyLock = 0;

  fillGrid(0, NORMAL);
  fillGrid(0, GHOST);

  loadPiece(random(1, 8), STARTY, STARTX);
  drawPiece(DRAW);
  if (createGhost())
    drawGhost(DRAW);
  drawGhost(DRAW);
  nextPiece = random(1, 8);
  /* TO fill in
  if (false)
  {
    for (uint8_t cl = 0; cl < 100; cl++)
    {
      drawPiece(ERASE);
      movePieceDown();
      if (random(1, 8) > 4)
        movePieceLeft();
      drawPiece(DRAW);
    }
  }*/
  // Reset the level
  level = STARTLEVEL;

  drawGameScreen(0, 10, 0, VERTDRAW, FULL);
  displayScore(score, 0, 117);

  while (stopAnimate == 0)
  {

    if (rendering == 0)
    {
      cli();
      drawPiece(ERASE);
      movePieceDown();
      drawPiece(DRAW);
      drawGameScreen(currentPiece.column, currentPiece.column + 4, currentPiece.row, currentPiece.row + 5, PARTIAL);
      moveTime = millis();
      if (level * LEVELFACTOR > DROPDELAY)
        level = DROPDELAY / LEVELFACTOR;
      sei();

      while ((signed)(millis() - moveTime) < (signed)(DROPDELAY - level * LEVELFACTOR))
      {

        // Wait for next drop
      }
    }
  }
  displayScoreScreen();
}

void displayScoreScreen()
{
  TinyOLED.ssd1306_fillscreen(0x00);

  bool newHigh = false;
  topScore = EEPROM.read(0);
  topScore = topScore << 8;
  topScore = topScore | EEPROM.read(1);

  if (score > topScore)
  {
    topScore = score;
    EEPROM.write(1, score & 0xFF);
    EEPROM.write(0, (score >> 8) & 0xFF);
    newHigh = true;
  }

  TinyOLED.ssd1306_char_f8x8(60, 0, "SCORE.");
  displayScore(score, 0, 117);
  if (newHigh)
  {
    TinyOLED.ssd1306_char_f8x8(0, 2, "NEWHIGHSCORE-");
  }
}