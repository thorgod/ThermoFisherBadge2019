
// What level does the game start on
#define STARTLEVEL 30
// The multiplying factor that sets how the speed scales with level (one level increment for every row cleared)
#define LEVELFACTOR 4
// The number of milliseconds before each drop (baseline)
#define DROPDELAY 200

// Mode settings for functions with multiple purposes
#define NORMAL 0
#define GHOST 1
#define FULL 0
#define PARTIAL 1
#define DRAW 0
#define ERASE 1

// The horizontal width of the playing area
#define HORIZ 5
// The vertical visible space of the playing area
#define VERTDRAW 19
// The size of the array of blocks (some are outside visible area to allow them to drop in from off screen)
#define VERTMAX 24

// The horizontal position where pieces begin
#define STARTX 0
// The vertical position where pieces begin
#define STARTY 19

//What port the button is on
#define BUTTON_ZERO 1
#define BUTTON_ONE 3
#define BUTTON_TWO 4

//What is on vs off. (Pullup or Pulldown)
#define PRESSON 0x0
#define PRESSOFF 0x1