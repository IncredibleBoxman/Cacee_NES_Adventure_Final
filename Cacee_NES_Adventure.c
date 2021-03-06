// angle frame before, frame after
//sprites can be multiple bricks
// or can be background image

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
// include NESLIB header
#include "neslib.h"



// include CC65 NES Header (PPU)
#include <nes.h>





// 0 = horizontal mirroring
// 1 = vertical mirroring
#define NES_MIRRORING 1

// VRAM update buffer
#include "vrambuf.h"
//#link "vrambuf.c"


extern const byte Title_Screen_pal[16];
extern const byte Title_Screen_rle[];

extern const byte Test_Screen_pal[16];
extern const byte Test_Screen_rle[];

extern const byte Test_Screen2_pal[16];
extern const byte Test_Screen2_rle[];

extern const byte Test_Screen3_pal[16];
extern const byte Test_Screen3_rle[];

extern const byte Game_Over_Screen_pal[16];
extern const byte Game_Over_Screen_rle[];

extern const byte Win_Screen_pal[16];
extern const byte Win_Screen_rle[];

extern const byte Boss_Screen_pal[16];
extern const byte Boss_Screen_rle[];

extern const byte Boss_Screen2_pal[16];
extern const byte Boss_Screen2_rle[];



// link the pattern table into CHR ROM






//#link "chr_generic.s"

//#link "Title_Screen.s"

//#link "Test_Screen.s"

//#link "Test_Screen2.s"


//#link "Test_Screen3.s"

//#link "Boss_screen.s"


//#link "Boss_screen2.s"



//#link "Game_Over_Screen.s"

//#link "Win_Screen.s"







//#link "famitone2.s"


void __fastcall__ famitone_update(void);

//#link "journey_to_silius.s"
extern char journey_to_silius_music_data[];
// CREDIT FOR JOURNEY GOES TO FAMISTUDIO, THIS IS 
// ONE OF THEIR DEFAULT SONGS


//#link "rickroll.s"
extern char rickroll_music_data[];
// credit for rickroll goes to Amilgi
// http://famitracker.com/forum/posts.php?id=5856


//#link "megalovania.s"
extern char megalovania_music_data[];
// CREDIT FOR MEGALOVANIA GOES TO mentlegen
// http://forums.famitracker.com/viewtopic.php?f=9&t=4834&p=23911&hilit=megalovania#p23911


//#link "my_lost_soul_danmaku.s"
extern char my_lost_soul_danmaku_music_data[];
// CREDIT FOR MY LOST SOUL GOES TO DRILLIMATION
// http://forums.famitracker.com/viewtopic.php?f=8&t=4865&p=23965&hilit=sad+song#p23965


//#link "Shatterhand.s"
extern char Shatterhand_music_data[];








//#link "custom_sounds.s"
extern char custom_sounds[];
// CREDIT FOR CUSTOM SOUNDS GOES TO TUI
// https://forums.nesdev.com/viewtopic.php?f=6&t=20147&sid=111cfdada42e9a915581c29a7721757d


// create easy to track tile/attr for metasprites 
#define TILE 0xd8
#define ATTR 0x00

#define TILE2 0xdc
#define ATTR2 0x02
///// METASPRITES


///// METASPRITES

// define a 2x2 metasprite
#define cacee(name,code,pal)\
const unsigned char name[]={\
        0,      0,      (code)+0,   pal, \
        0,      8,      (code)+1,   pal, \
        8,      0,      (code)+2,   pal, \
        8,      8,      (code)+3,   pal, \
        128};

// define a 2x2 metasprite, flipped horizontally
#define cacee_flip(name,code,pal)\
const unsigned char name[]={\
        8,      0,      (code)+0,   (pal)|OAM_FLIP_H, \
        8,      8,      (code)+1,   (pal)|OAM_FLIP_H, \
        0,      0,      (code)+2,   (pal)|OAM_FLIP_H, \
        0,      8,      (code)+3,   (pal)|OAM_FLIP_H, \
        128};

#define thwomp(name,code,pal)\
const unsigned char name[]={\
        0,      0,      (code)+0,   pal, \
        0,      8,      (code)+1,   pal, \
        8,      0,      (code)+2,   pal, \
        8,      8,      (code)+3,   pal, \
        128};

#define powerup(name,code,pal)\
const unsigned char name[]={\
        0,      0,      (code)+0,   pal, \
        0,      8,      (code)+1,   pal, \
        8,      0,      (code)+2,   pal, \
        8,      8,      (code)+3,   pal, \
        128};

#define door(name,code,pal)\
const unsigned char name[]={\
        0,      0,      (code)+0,   pal, \
        0,      8,      (code)+1,   pal, \
        8,      0,      (code)+2,   pal, \
        8,      8,      (code)+3,   pal, \
        128};
cacee(caceeRStand, 0xd8, 0);
cacee(caceeRRun1, 0xdc, 0);
cacee(caceeRRun2, 0xe0, 0);
cacee(caceeRRun3, 0xe4, 0);
cacee(caceeRJump, 0xe8, 0);
cacee(caceeRClimb, 0xec, 0);
cacee(caceeRSad, 0xf0, 0);

cacee_flip(caceeLStand, 0xd8, 0);
cacee_flip(caceeLRun1, 0xdc, 0);
cacee_flip(caceeLRun2, 0xe0, 0);
cacee_flip(caceeLRun3, 0xe4, 0);
cacee_flip(caceeLJump, 0xe8, 0);
cacee_flip(caceeLClimb, 0xec, 0);
cacee_flip(caceeLSad, 0xf0, 0);

thwomp(thwompRStand, 0xc8, 3);

powerup(powerupRStand, 0xd0, 2);

door(doorRStand, 0xc4, 1);

// define a 2x2 metasprites
const unsigned char cacee[]={
        0,      0,      TILE+0,   ATTR, 
        0,      8,      TILE+1,   ATTR, 
        8,      0,      TILE+2,   ATTR, 
        8,      8,      TILE+3,   ATTR, 
        128};



const unsigned char* const caceeRunSeq[16] = {
  caceeLRun1, caceeLRun2, caceeLRun3, 
  caceeLRun1, caceeLRun2, caceeLRun3, 
  caceeLRun1, caceeLRun2,
  caceeRRun1, caceeRRun2, caceeRRun3, 
  caceeRRun1, caceeRRun2, caceeRRun3, 
  caceeRRun1, caceeRRun2,
};

const unsigned char* const caceeStandSeq[2] = {
  caceeLStand, 
  caceeRStand, 
};




/*{pal:"nes",layout:"nes"}*/
const char PALETTE[32] = { 
  0x03,			// screen color

  0x11,0x30,0x27,0x00,	// background palette 0
  0x1C,0x20,0x2C,0x00,	// background palette 1
  0x00,0x10,0x20,0x00,	// background palette 2
  0x26,0x16,0x26,0x00,	// background palette 3

  0x2A,0x16,0x27,0x00,	// sprite palette 0
  0x00,0x19,0x2C,0x00,	// sprite palette 1
  0x0D,0x16,0x27,0x00,	// sprite palette 2
  0x16,0x0D,0x0D	// sprite palette 3
};


byte sprite = 0x02;



byte sprite_y1 = 100;

byte sprite_y2 = 108;

byte bullet_sprite =  0x7f;


// pause variable
static unsigned char game_paused;



// number of actors (4 h/w sprites each)
#define NUM_ACTORS 1

// actor x/y positions
byte actor_x[NUM_ACTORS];
byte actor_y[NUM_ACTORS];
// actor x/y deltas per frame (signed)
sbyte actor_dx[NUM_ACTORS];
sbyte actor_dy[NUM_ACTORS];

//shot x delta (signed)

// thwomp x/y position
byte thwomp_x;
byte thwomp_y;

//thwomp x/y deltas per frame (signed)
sbyte thwomp_dx;
sbyte thwomp_dy;
///default thwomp height
sbyte def_thwomp_y;

//boss x delta per frame (signed)
int boss_dx;
//boss counter
int boss_count = 0;

//boss head bytes
byte boss_head;

//boss see byte

byte boss_see;
// bool for boss phases
bool boss_phase_1 = true;
bool boss_phase_2 = true;

// count for boss screens

byte boss_screen = 0;

// stars x and y coordinates

byte powerup_x;
byte powerup_y; 

byte starOne_x = 145;
byte starOne_y = 120;

byte starTwo_x = 80;
byte starTwo_y = 120;

byte starThree_x = 160;
byte starThree_y = 105;
//min and max X screen values
byte MINX;
byte MAXX;

// game bool value
bool game = true;
// if cacee is facing right bool
bool right = true; 
// if its first time loading first level bool
bool first = true;

bool twoLeft = true;

bool jump = false;

bool levelChange;
bool starOne = true;
bool starTwo = true;
bool starThree = true;
bool onPlatform;
// if our boss is left bool
bool boss_left = false;

bool boss1 = true;
bool boss2 = false; 
//score value
byte score = 0;
// lives value
byte lives = 3; 

// level value

int level;

char i;	// actor index
char oam_id;	// sprite ID
char pad;// controller flags
char pad_new;

byte ground= 200;
byte def_ground = 200; 
byte jumpHeight = 40;
byte gravity = 2;
byte shooting_dx = 4;
byte shooting_dx_left = -4;


byte iFrames = 0;
// used for for loops that require int
byte num;
// used to determine the x value of collision; 
byte collision;

//Used for moving boss

//platform struct
typedef struct Platform{
  byte _x;		// platforms x/y positions
  byte _y;		
  byte sprite; 
  
};
//fill our struct with 10 to use
struct Platform platform_one[10];

//bullet struct
typedef struct Bullets{
  byte _x;		// bullet x/y positions
  byte _y;
  byte _dx;
  byte sprite; 
  bool right; 
  
};

//fill our struct with 10 to use
struct Bullets bullet[10];




void setup_graphics() {
  // clear sprites
  oam_hide_rest(0);
  // set palette colors
  pal_all(PALETTE);
  // turn on PPU
  ppu_on_all();
}

void fade_in() {
  byte vb;
  for (vb=0; vb<=4; vb++) {
    // set virtual bright value
    pal_bright(vb);
    // wait for 4/60 sec
    //ppu_wait_frame();
   // ppu_wait_frame();
   // ppu_wait_frame();
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ppu_wait_frame();
  }
}
void show_screen(const byte* pal, const byte* rle) {
  // disable rendering
  ppu_off();
  // set palette, virtual bright to 0 (total black)
  pal_bg(pal);
  pal_bright(0);
  // unpack nametable into the VRAM
  vram_adr(0x2000);
  vram_unrle(rle);
  // enable rendering
  ppu_on_all();
  // fade in from black
  fade_in();
}
void title()
{
  
  bool bool1 = true;
  char pad;
  
  setup_graphics();
  ppu_off();
  show_screen(Title_Screen_pal, Title_Screen_rle);
  
  // Loop until user hits Start, then enters game state. 
 
  while (bool1) {
    pad = pad_trigger(0);
    if (pad & PAD_START) 
    {
      
      ppu_off();
      vram_adr(NAMETABLE_A);
      vram_fill(0,1024);
      bool1 = false; 
      ppu_on_all();
    }
  }
  music_play(0);
}

//
void create_platforms(byte x, byte y, byte z)
{
  platform_one[z]._x = x;
  platform_one[z]._y = y;
  //platform_one[z].sprite = sprite;
  
  platform_one[z+1]._x = x+8;
  platform_one[z+1]._y = y;
 // platform_one[z+1].sprite = sprite;
}

void clear_platforms()
{
  for (num = 0; num<= 10; num++)
 {
    platform_one[num]._x = NULL;
    platform_one[num]._y = NULL;
    //platform_one[num].sprite = NULL; 
  }
}






//this is our starting level platforms
void level_one_platforms() {
  
  create_platforms(70, 175, 0);
  
  create_platforms(105, 145, 2);
  
  create_platforms(140, 120, 4);
  //platform_one[0]._x = 70;
  //platform_one[0]._y = 173;
  //platform_one[0].sprite = sprite;
  
  //platform_one[1]._x = 78;
  //platform_one[1]._y = 173;
  //platform_one[1].sprite = sprite;
}

void level_two_platforms() {
  create_platforms(90, 175, 0);
  
  create_platforms(125, 145, 2);
  
  create_platforms(80, 120, 4); 
}

void level_three_platforms() {
  create_platforms(85, 175, 0);
  
  create_platforms(55, 150, 2);
  
  create_platforms(85, 120, 4); 
  
  create_platforms(100, 90, 6);
  
  create_platforms(160, 105, 8);
  
  
}

void level_four_platforms()
{
  create_platforms(118, 175, 0);
  
  create_platforms(86, 145, 2);
  
  create_platforms(150, 145, 4);
}

void create_bullet(byte x, byte y, byte z)
{
  bullet[z]._x = x;
  bullet[z]._y = y;
  if(right)
  {
    bullet[z]._dx = shooting_dx; 
  }
  else
  {
    bullet[z]._dx = shooting_dx_left;
  }
  bullet[z].sprite = bullet_sprite;
  
}

//void clear_bullet( byte z)
//{
//  bullet[z]._x = NULL;
//  bullet[z]._y = NULL;
//  bullet[z].sprite = NULL; 
//}



// setup PPU and tables



//This checks if player has collided with a platform and returns true if so.
void platform_collision(){
  // loops through all our struct of platforms
  for( num = 0; num <= 20; num++)
  {
    //checks if actor has collided with our platforms
    if(((platform_one[num]._x >= actor_x[0]-4 && platform_one[num]._x <= actor_x[0]+8)
        && (platform_one[num]._y >= actor_y[0]-2 && platform_one[num]._y <= actor_y[0]+4))) //collision detected
    {
      collision = platform_one[num]._y;
      onPlatform = true;
      
            
    }
  
  }
  
}

bool thwomp_see(byte x, byte y){
  if (thwomp_x == x && thwomp_y < y)
  {
    return true;
  }
  else
    return false;
}

bool thwomp_collision()
{
  if(((thwomp_x >= actor_x[0]-4 && thwomp_x <= actor_x[0]+8)&& (thwomp_y >= actor_y[0]-2 && thwomp_y <= actor_y[0]+4))) //collision detected
  {
    
    return true;      
  }
  else
    return false;
}

bool powerup_collision()
{
  if(((powerup_x >= actor_x[0]-4 && powerup_x <= actor_x[0]+8)&& (powerup_y >= actor_y[0]-2 && powerup_y <= actor_y[0]+4))) //collision detected
  {
    sfx_play(2,1);
    score+= 1; 
    return true;      
  }
  else 
    return false;
}



  




 

//set actor x and y
void startingSpace()
{
   
  actor_x[0] = 12;
  actor_y[0] = 200;
  actor_dx[0] = 0;
  actor_dy[0] = 0;
}

void startingSpaceR()
{
  actor_x[0] = 220;
  actor_y[0] = 200;
  actor_dx[0] = 0;
  actor_dy[0] = 0;
}

void create_thwomp(byte x, byte y)
{
  thwomp_x = x;
  def_thwomp_y = y;
  thwomp_y = def_thwomp_y;
}
void clear_thwomp()
{
  thwomp_x = NULL;
  def_thwomp_y = NULL;
  thwomp_y = NULL;
}

void create_powerup(byte x, byte y)
{
  powerup_x = x;
  powerup_y = y;
}

void clear_powerup()
{
  powerup_x = NULL;
  powerup_y = NULL;
}
void levelOne()
{
  ppu_off();
  clear_platforms();
  clear_thwomp();
  //clear_powerup();
  setup_graphics();
  show_screen(Test_Screen_pal, Test_Screen_rle);
  level_one_platforms();
  create_thwomp(190, 95);
  if(starOne)
  {
    create_powerup(starOne_x, starOne_y);
  }
  
  //check if its our first load into game
  if(first)
  {
    // if it is, set are initial starting state and set first to false
    startingSpace();
    first = false;
  }
  // if its not, then we must be coming from right set right starting space
  else
  {
    startingSpaceR();
    //sfx_play(4,2);
  }
  
    
  
  level = 1;
  
}
// level 2
void levelTwo()
{
  ppu_off();
  clear_platforms();
  clear_thwomp();
  setup_graphics();
  show_screen(Test_Screen2_pal, Test_Screen2_rle);
  level_two_platforms();
  
  create_thwomp(100, 43);
  if(starTwo)
  {
    create_powerup(starTwo_x, starTwo_y);
  }
  //sfx_play(3,2);
  if (twoLeft)
  {
    twoLeft = false;
    startingSpace();
    
  }
  else
  {
    twoLeft = true;
    startingSpaceR();
     
  }
    
  level = 2;
  
}
// level 3 
void levelThree()
{
  ppu_off();
  clear_platforms();
  clear_thwomp();
  setup_graphics();
  show_screen(Test_Screen3_pal, Test_Screen3_rle);
  level_three_platforms();
  create_thwomp(130, 120);
  if(starThree)
  {
    create_powerup(starThree_x, starThree_y);
  }
  //sfx_play(3,2);
  startingSpace();
  level = 3;
  
  
}

void bossRoom()
{
  ppu_off();
  clear_platforms();
  clear_thwomp();
  setup_graphics();
  music_stop();
  //famitone_init(my_lost_soul_danmaku_music_data);
  famitone_init(Shatterhand_music_data);
  music_play(0);
  show_screen(Boss_Screen2_pal, Boss_Screen2_rle);
  level_four_platforms();
  create_thwomp(200, 120);
  startingSpace(); 
  
  level = 4; 
}


  

void game_reset()
{
  
  thwomp_y = def_thwomp_y;
  thwomp_dy = 0;
  boss_dx = 0; 
  boss_count = 0;
  boss_phase_1 = true;
  boss_phase_2 = true;
  boss_screen = 0; 
  boss1 = true;
  boss2 = false; 
  first = true;
  starOne = true;
  starTwo = true;
  starThree = true; 
  level = 1; 
  levelOne();
  lives = 3;
  score = 0;
  ground = def_ground;
  
}

void game_over()
{
  bool game_over = true;
  char pad; 
 
  music_stop();
  //famitone_init(my_lost_soul_danmaku_music_data);
  famitone_init(my_lost_soul_danmaku_music_data);
  music_play(0);
  setup_graphics();
  ppu_off();
  show_screen(Game_Over_Screen_pal, Game_Over_Screen_rle);
  ppu_on_all();

 
  while(game_over) 
  { 
    pad = pad_trigger(0);
    if (pad & PAD_START) 
    {
      
      ppu_off();
      
      vram_adr(NAMETABLE_A);
      vram_fill(0,1024);
      
      
      game_over = false;
      music_stop();
      famitone_init(journey_to_silius_music_data);
      music_play(0); 
      ppu_on_all();
      
    }
  }
  
  // reset lives and score and variables
  setup_graphics();
  game_reset();
  
}

// our win function
void winner()
{
  //setup variables and stop music
  bool game_over = true;
  char pad; 
  music_stop();
  famitone_init(megalovania_music_data);
  music_play(0);
  setup_graphics();
  ppu_off();
  show_screen(Win_Screen_pal, Win_Screen_rle);
  //while we are on this screen check if player hit start
  while(game_over) 
  { 
    pad = pad_trigger(0);
    if (pad & PAD_START) 
    {
      
      ppu_off();
      vram_adr(NAMETABLE_A);
      vram_fill(0,1024);
      
      
      
      game_over = false;
      music_stop();
      famitone_init(journey_to_silius_music_data);
      music_play(0); 
      ppu_on_all();
      
    }
  }
  // reset lives and score and variables
  setup_graphics();
  game_reset();
}


	


// main program


void draw_score()
{
  oam_id = oam_spr(176, 10, 83, 2, oam_id);
  oam_id = oam_spr(184, 10, 67, 2, oam_id);
  oam_id = oam_spr(192, 10, 79, 2, oam_id);
  oam_id = oam_spr(200, 10, 82, 2, oam_id);
  oam_id = oam_spr(208, 10, 69, 2, oam_id);
  oam_id = oam_spr(216, 10, 58, 2, oam_id);
  oam_id = oam_spr(224, 10, (score/10%10)+48, 2, oam_id);
  oam_id = oam_spr(232, 10, (score%10)+48, 2, oam_id);
}

void draw_lives()
{
  oam_id = oam_spr(16, 10, 76, 1, oam_id);
  oam_id = oam_spr(24, 10, 73, 1, oam_id);
  oam_id = oam_spr(32, 10, 86, 1, oam_id);
  oam_id = oam_spr(40, 10, 69, 1, oam_id);
  oam_id = oam_spr(48, 10, 83, 1, oam_id);
  oam_id = oam_spr(56, 10, 58, 1, oam_id);
  oam_id = oam_spr(64, 10, (lives%10)+48, 1, oam_id);
}

byte draw_boss(sbyte dx)
{
  // Boss left side square lines
  oam_id = oam_spr(200-dx, 150, 163, 3, oam_id);
  oam_id = oam_spr(200-dx, 142, 163, 3, oam_id);
  // Boss head
  oam_id = oam_spr(208-dx, 142, 252, 3, oam_id);
  oam_id = oam_spr(208-dx, 150, 253, 3, oam_id);
  oam_id = oam_spr(216-dx, 142, 254, 3, oam_id);
  oam_id = oam_spr(216-dx, 150, 255, 3, oam_id);
  //Boss top side square lines
  oam_id = oam_spr(208-dx, 134, 161, 3, oam_id);
  oam_id = oam_spr(216-dx, 134, 161, 3, oam_id);
  
  // Boss right side square lines
  oam_id = oam_spr(224-dx, 150, 162, 3, oam_id);
  oam_id = oam_spr(224-dx, 142, 162, 3, oam_id);
  
  //Boss UFO HEAD BASE
  oam_id = oam_spr(224-dx, 158, 1, 1, oam_id);
  oam_id = oam_spr(216-dx, 158, 1, 1, oam_id);
  oam_id = oam_spr(208-dx, 158, 1, 1, oam_id);
  oam_id = oam_spr(200-dx, 158, 1, 1, oam_id);
  
  //Boss UFO 2nd tier
  oam_id = oam_spr(224-dx, 166, 1, 1, oam_id);
  oam_id = oam_spr(216-dx, 166, 1, 1, oam_id);
  oam_id = oam_spr(208-dx, 166, 1, 1, oam_id);
  oam_id = oam_spr(200-dx, 166, 1, 1, oam_id);
  oam_id = oam_spr(192-dx, 166, 1, 1, oam_id);
  oam_id = oam_spr(232-dx, 166, 1, 1, oam_id);
  
  //Boss UFO 3rd tier 
  oam_id = oam_spr(224-dx, 174, 1, 1, oam_id);
  oam_id = oam_spr(216-dx, 174, 1, 1, oam_id);
  oam_id = oam_spr(208-dx, 174, 1, 1, oam_id);
  oam_id = oam_spr(200-dx, 174, 1, 1, oam_id);
  oam_id = oam_spr(192-dx, 174, 1, 1, oam_id);
  oam_id = oam_spr(232-dx, 174, 1, 1, oam_id);
  oam_id = oam_spr(184-dx, 174, 1, 1, oam_id);
  oam_id = oam_spr(240-dx, 174, 1, 1, oam_id);
  
  //boss "fire" left side
  oam_id = oam_spr(192-dx, 182, 169, 2, oam_id);
  oam_id = oam_spr(200-dx, 182, 169, 2, oam_id);
  oam_id = oam_spr(184-dx, 190, 169, 2, oam_id);
  oam_id = oam_spr(192-dx, 190, 169, 2, oam_id);
  
  //boss "fire" right side
  
  oam_id = oam_spr(232-dx, 182, 170, 2, oam_id);
  oam_id = oam_spr(240-dx, 182, 170, 2, oam_id);
  oam_id = oam_spr(232-dx, 190, 170, 2, oam_id);
  oam_id = oam_spr(240-dx, 190, 170, 2, oam_id);
  return 208-dx;
}


void main() {
  
  
 
  //score = 0;
  //lives = 3; 
  
  boss_dx = 0;
 
 
  

  // setup graphics
  setup_graphics();
  
  

  //PLAY MUSIC 
  famitone_init(journey_to_silius_music_data);
  
  // Set custom sounds
  sfx_init(custom_sounds); 
   // set music callback function for NMI
  nmi_set_callback(famitone_update);
  // play music
  //music_play(0);
  
  title();

  // loop until game is over
  
  //load up our level 1 
  
  levelOne();
  
  game_paused=FALSE;
  while (game) {
    
    levelChange = false;
    // set our minx and maxx values
    MINX = 10;
    MAXX = 225;
    // start with OAMid/sprite 0
    oam_id = 0;
    
    
    //if we've reached the right side of the screen transition based on 
    // what level we are currently at
    if (actor_x[0] >= MAXX)
      {
      
      	if(level == 1)
        {
          if(!starOne)
          {
          levelChange = true;
          twoLeft = true;
      	  levelTwo();
          }
          else
          {
            actor_x[0] == MAXX;
          }
        }
        else if (level == 2)
        {
          if(!starTwo)
          {
            levelChange = true;
            levelThree();
          } 
        }
      else if (level == 3)
        {
          if (!starThree)
          {
            levelChange = true;
            bossRoom();
          }
        }
      else
      {
        actor_x[0] == MAXX;
      }
        
        
      }
    // if we've reached the left side of the screen transition based on
    // what level we are currently at
     else if (actor_x[0] <= MINX)
      {
       
        if(level == 2)
        {
          levelChange = true;
          levelOne();
        }
        else if(level == 3)
        {
          levelChange = true;
          twoLeft = false;
          levelTwo();
        }
       else
       {
         actor_x[0] == MINX;
       }
        
        
        
      }
    
   
     
    
    
     //if we've changed levels, destroy thwomps
    
    // loop through our platforms. 
    
    if(level == 1)
    {
      // LEGACY CODE, HARDCODED PLATFORMS INSTEAD OF RLE
     // for (i = 0; i<= 5; i++)
     // {
      // add 17 to y in order for us to stand on top of platform
       //oam_id = oam_spr(platform_one[i]._x, platform_one[i]._y+17, platform_one[i].sprite, 0x01, oam_id);
       //oam_id = oam_spr(platform_one[i]._x, platform_one[i]._y+17, platform_one[i].sprite, 0x01, oam_id);
        
     // }
      oam_id = oam_meta_spr(thwomp_x, thwomp_y, oam_id, thwompRStand);
      if (powerup_collision())
      {
        starOne = false;
        clear_powerup();
      }
      if (starOne)
      {
        oam_id = oam_meta_spr(powerup_x, powerup_y, oam_id, powerupRStand);
        oam_id = oam_meta_spr(MAXX+8, 200, oam_id, doorRStand); 
      }
    }
    
    else if(level == 2)
    {
      // LEGACY CODE, HARDCODED PLATFORMS INSTEAD OF RLE
      //for (i = 0; i<= 5; i++)
     // {
      // add 17 to y in order for us to stand on top of platform
        //oam_id = oam_spr(platform_one[i]._x, platform_one[i]._y+17, platform_one[i].sprite, 0x01, oam_id);
        //oam_id = oam_spr(platform_one[i]._x, platform_one[i]._y+17, platform_one[i].sprite, 0x01, oam_id);
        
        
        
    //  }
      oam_id = oam_meta_spr(thwomp_x, thwomp_y, oam_id, thwompRStand);
      
      if (powerup_collision())
      {
        starTwo = false;
        clear_powerup();
      }
      if (starTwo)
        {
          oam_id = oam_meta_spr(powerup_x, powerup_y, oam_id, powerupRStand);
          oam_id = oam_meta_spr(MAXX+8, 200, oam_id, doorRStand); 
        }
    }
    
    else if(level == 3)
    {
      
      // LEGACY CODE, HARDCODED PLATFORMS INSTEAD OF RLE
     // for (i = 0; i<= 9; i++)
      //{
      // add 17 to y in order for us to stand on top of platform
       //oam_id = oam_spr(platform_one[i]._x, platform_one[i]._y+17, platform_one[i].sprite, 0x01, oam_id);
        //oam_id = oam_spr(platform_one[i]._x, platform_one[i]._y+17, platform_one[i].sprite, 0x01, oam_id);
        
     // }
      oam_id = oam_meta_spr(thwomp_x, thwomp_y, oam_id, thwompRStand);
        //check if we've grabbed the star yet
      
      if (powerup_collision())
      {
        starThree = false;
        clear_powerup();
      }
        if (starThree)
        {
          
          oam_id = oam_meta_spr(powerup_x, powerup_y, oam_id, powerupRStand);
          oam_id = oam_meta_spr(MAXX+8, 200, oam_id, doorRStand); 
        }
    }
    //boss level
    else if (level ==4)
    {
      
      //draw our boss and move it with boss_dx
      boss_head = draw_boss(boss_dx);
      if (boss1)
      {
        clear_platforms();
        boss1 = false;
      }
      if(boss2)
      {
        clear_platforms();
        boss2 = false;
      }
      if (boss1 && boss2)
      {
        clear_platforms();
        boss1 = false;
        boss2 = false; 
      }
      
      // our boss uses a moving thwomp to attack! Depending on if 
      // thwomp sees us or not, changes the X. If does't see us then
      // it follows boss, if it does see us then it crashes down.
      if (!thwomp_see(actor_x[0], actor_y[0]))
      {
        thwomp_x = boss_head; 
      }
      else
      {
        boss_see = boss_head;
        thwomp_x = boss_see;
      }
      
      oam_id = oam_meta_spr(thwomp_x, thwomp_y, oam_id, thwompRStand);
      
      //if our count is 7 then boss will take a break so you can shoot him.
      if (boss_count == 7)
    {
      
      boss_dx = boss_dx;
      //  spawn platforms if boss 2 is false (its always false except when
      // boss phases change
        if (!boss2)
        {
          
          // This creates our RLE platforms, but only does this once so 
          // it's not constantly flashing. 
          if (boss_screen == 0)
          {
            level_four_platforms();
            show_screen(Boss_Screen_pal, Boss_Screen_rle);
            boss_screen = 1; 
          }
        }
      // phase 1 break
      if (score >= 10 && boss_phase_1)
      {
        // sets variables for next phase and removes RLE platforms once so its not flashing
        boss_count = 0;
        boss_phase_1 = false;
        boss2 = true;
        show_screen(Boss_Screen2_pal, Boss_Screen2_rle);
        boss_screen = 0;
      }
        //phase 2 break
      else if ( score>= 20 && boss_phase_2)
      {
        // sets variables for next phase and removes RLE platforms once so its not flashing
        show_screen(Boss_Screen2_pal, Boss_Screen2_rle);
        boss_count = 0;
        boss_phase_2 = false; 
        boss2 = true; 
        boss_screen = 0;
      }
    }
    else
    {
      // move our boss if he needs to move
    if ( boss_left )
      boss_dx -= gravity;
      if (boss_dx > 167)
      {
        boss_left = true;
        boss_count = boss_count +1; 
      }
    else if (!boss_left )
      boss_dx += gravity;
      if (boss_dx < 10)
      {
        boss_left = false;
        boss_count = boss_count +1; 
      }
    }
      
      
    }
    
    //LEGACY CODE
     // oam_id = oam_spr(platform_one[i]._x, platform_one[i]._y, platform_one[i].sprite, 0x00, oam_id);
   //  
    // displays our current level for debug purposes
    //oam_id = oam_spr(100, 100, 48+level, level, oam_id);
    // END LEGACY CODE
    
    // 1 player controller setup. 
      pad_new = pad_trigger(0);
      pad = pad_state(0);
      
      // move actor[i] left/right
      if (pad&PAD_LEFT && actor_x[0]>10) 
      {
        actor_dx[0]=-2;
        right = false;
      }
      else if (pad&PAD_RIGHT && actor_x[0]<230)
      {
        actor_dx[0]=2;
        right = true;
      }
      
      else actor_dx[0]=0;
      
      //Make Cacee Jump
      
      if (pad_new & PAD_A & !game_paused &&  actor_y[0] == ground)			//Prototype jumping
      { 
        sfx_play(6,2);
        jump = true; 
        actor_dy[0]=-gravity;
       
        
      }
    //Shoot our guns pew pew
    if (pad_new & PAD_B && !game_paused)			
    { 
      
      //play our gunshot sound
        sfx_play(8,1);
        //if we are facing right, spawn bullet on right
        if(right)
        {
          create_bullet(actor_x[0]+12, actor_y[0]+5, 0);
          oam_id = oam_spr(bullet[0]._x, bullet[0]._y, bullet_sprite, 0x04, oam_id);
          
        }
      //if we are facing left, spawn bullet on left. 
        else
        {
          create_bullet(actor_x[0]-4, actor_y[0]+5, 0);
          oam_id = oam_spr(bullet[0]._x, bullet[0]._y, bullet_sprite, 0x04, oam_id);
          
        }
      
      
    }
        
        
    
    
    
    
    
      
    
    
    //it start was released and then pressed, toggle pause mode

    if(pad_new&PAD_START)
    {
      game_paused^=TRUE;
      music_pause(game_paused);
    }

    //don't process anything in pause mode, just display latest game state
    
    if(game_paused) 
    {
      
      continue;
    }
      
    
    // if we have are on top of the platform
    platform_collision();
    if (onPlatform)
    {
      // set ground to platform height 
      if (!jump)
      {
      ground = collision;
      onPlatform = false;
        
      }
      
    }
    // if we are not on top of the platform, and our actor is higher than default ground, and our actor 
    else if ((!onPlatform && actor_y[0] < def_ground ) || (actor_x[0]-4 > platform_one[0]._x) || (actor_x[0]+4 < platform_one[0]._x) )
    {
      // set ground back to default
      if (!jump)
      {
        
      ground = def_ground;
      }

    }
   
    
    
    //fall if we are above ground 
    if (actor_y[0] < ground-jumpHeight)
    {
      jump = false; 
      actor_dy[0] = gravity; 
    }
   
    
    
    // draw and move cacee
    for (i=0; i<1; i++) {
      byte runseq = actor_x[i] & 7;
      
      
      
      //if cacee is not moving
      if (actor_dx[i] == 0)
      {
        // If facing right, draw right standing
        if(right)
          oam_id = oam_meta_spr(actor_x[i], actor_y[i], oam_id, caceeStandSeq[1]);
        // else draw left standing
        else
          oam_id = oam_meta_spr(actor_x[i], actor_y[i], oam_id, caceeStandSeq[0]);
      }
      // If cacee is moving
      else{
        //If Cacee is moving to the right, increase runseq to use R animation
        if (actor_dx[i] >= 0)
      {
        runseq+=8;
      }
      //animate running based on runseq and move cacee
      oam_id = oam_meta_spr(actor_x[i], actor_y[i], oam_id, caceeRunSeq[runseq]);
      actor_x[i] += actor_dx[i];
      actor_y[i] += actor_dy[i];
       
      }
      if(actor_y[i] <= ground)
      {
      actor_y[i] += actor_dy[i];
      }
      //Set actor back on Plane after jumping if he falls too far
      if(actor_y[i] >= ground)
      {
        actor_y[i] = ground;
        
      }
      // draw our bullets moving
      
      bullet[0]._x += bullet[0]._dx;
      oam_id = oam_spr(bullet[0]._x, bullet[0]._y, bullet_sprite, 0x04, oam_id);
       
      if (thwomp_see(actor_x[i], actor_y[i]))
      {
        thwomp_dy = gravity +2; 
        oam_id = oam_meta_spr(thwomp_x, thwomp_y, oam_id, thwompRStand);
      }
      thwomp_y += thwomp_dy;
      // if thwomp has hit the ground, start rising again.
      
      if( thwomp_y >= def_ground)
      {
        if (iFrames == 0)
        {
          sfx_play(9,3);
        }
        thwomp_y = def_ground;
        thwomp_dy = -1; 
      }
      // if thwomp has reached its default height then stop rising
      if(thwomp_y == def_thwomp_y)
        thwomp_dy = 0;
      if(levelChange)
      {
        thwomp_y = def_thwomp_y;
        thwomp_dy = 0;
        oam_id = oam_meta_spr(thwomp_x, thwomp_y, oam_id, thwompRStand);
      }
      if(iFrames == 0) 
      {
        if(thwomp_collision())
        {
          sfx_play(9,3);
          lives -= 1;
           
          iFrames = 60;
        }
      }
      else
      {
        iFrames -= 1; 
      }
      
      //if our lives has gone below one we have lost and its game over
      if (lives < 1)
      {
        // run our game over
        game_over();
        
        
        
      }
      // if we have a score of 30, then we win 
      if (score == 30)
      {
        //run our winner 
        winner();
      }
      
      
      
      
      
    }
    
    
    //move bulle
      bullet[0]._x += bullet[0]._dx; 
    
    //if bullet has reached MAXX, despawn
    if (bullet[0]._x >= MAXX)
    {
      
      
      bullet[0]._x = NULL;
      bullet[0]._y = NULL;
      bullet[0].sprite = NULL;
      
    }
    // if bullet has reached MINX, despawn
    if (bullet[0]._x <= MINX)
    {
      bullet[0]._x = NULL;
      bullet[0]._y = NULL;
      bullet[0].sprite = NULL;
      
    }
    
    // IF bullet has hit the boss in the head, DESPAWN and add score
    if (bullet[0]._x <= boss_head & bullet[0]._y == 142 || bullet[0]._x <= boss_head & bullet[0]._y == 150)
    {
      
      
      bullet[0]._x = NULL;
      bullet[0]._y = NULL;
      bullet[0].sprite = NULL;
      
      score++;
    }
    
    //Draws and updates Scoreboard
    draw_score();
    
    //Draws and updates Lives
    draw_lives();
    
    // hide rest of sprites
    // if we haven't wrapped oam_id around to 0
    if (oam_id!=0) oam_hide_rest(oam_id);
    // wait for next frame
    ppu_wait_frame();
  }
}