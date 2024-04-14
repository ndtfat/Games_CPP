#pragma once
#include <raylib.h>
#include <deque>

#define TITLE_SIZE 50
#define SCREEN_W 1300
#define SCREEN_H 700

#define OVERLAY_COLOR {255,255,255,200}

//----------------------------------------------------------------------------------------------------------------------
//TETRIS GAME 
//----------------------------------------------------------------------------------------------------------------------
#define GAP 50
#define PADDING 5
#define NUM_ROWS 20
#define NUM_COLS 10
#define CELL_SIZE 30

#define TETRIS_SIDEBAR_WIDTH (CELL_SIZE * 4)
#define BOARD_WIDTH (CELL_SIZE * NUM_COLS) + (PADDING * 2)
#define BOARD_HEIGHT (CELL_SIZE * NUM_ROWS) + PADDING

#define BOARD_OFFSET_X (SCREEN_W / 2 - (BOARD_WIDTH + PADDING) / 2 - TETRIS_SIDEBAR_WIDTH / 2 - GAP / 2)
#define BOARD_OFFSET_Y 80
#define CELL_OFFSET_X (BOARD_OFFSET_X + PADDING)
#define CELL_OFFSET_Y 80
#define TETRIS_SIDEBAR_OFFSET_X (BOARD_OFFSET_X + BOARD_WIDTH + GAP)
#define TETRIS_SIDEBAR_OFFSET_Y 80

// Sidebar
#define SIDEBAR_GAP 20
#define NEXT_BLOCK_HEIGHT (TETRIS_SIDEBAR_WIDTH)
#define NEXT_BLOCK_OFFSET_Y (TETRIS_SIDEBAR_OFFSET_Y + CELL_SIZE + SIDEBAR_GAP)




//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
//SNAKE GAME 
//----------------------------------------------------------------------------------------------------------------------
#define cellSize 25
#define cellCount 20
#define Offset 150