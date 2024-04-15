#pragma once
#include <raylib.h>
#include <deque>

#define TITLE_SIZE 50
#define SCREEN_W 1300
#define SCREEN_H 800

#define OVERLAY_COLOR {255,255,255,200}
typedef enum Game { TETRIS, SNAKE, FRUIT_BASKET, INVADOR, MENU };

//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
//MENU
//----------------------------------------------------------------------------------------------------------------------
#define MN_GAP 50
#define MN_PADDING 5
#define GAME_BOX_W 400
#define GAME_BOX_H 250
#define GAME_BOX_1_X (SCREEN_W / 2 - GAME_BOX_W - MN_PADDING * 2 - MN_GAP / 2)
#define GAME_BOX_2_X (GAME_BOX_1_X + GAME_BOX_W + MN_GAP)
#define	GAME_BOX_1_Y 150
#define	GAME_BOX_2_Y (GAME_BOX_1_Y + GAME_BOX_H + MN_PADDING * 2 + MN_GAP)

//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
//TETRIS GAME 
//----------------------------------------------------------------------------------------------------------------------
#define TT_GAP 50
#define TT_PADDING 5
#define TT_NUM_ROWS 20
#define TT_NUM_COLS 10
#define TT_CELL_SIZE 30

#define TT_SIDEBAR_WIDTH (TT_CELL_SIZE * 4)
#define TT_BOARD_WIDTH (TT_CELL_SIZE * TT_NUM_COLS) + (TT_PADDING * 2)
#define TT_BOARD_HEIGHT (TT_CELL_SIZE * TT_NUM_ROWS) + TT_PADDING

#define TT_Y 120
#define TT_BOARD_X (SCREEN_W / 2 - (TT_BOARD_WIDTH + TT_PADDING) / 2 - TT_SIDEBAR_WIDTH / 2 - TT_GAP / 2)
#define TT_CELL_X (TT_BOARD_X + TT_PADDING)
#define TT_SIDEBAR_X (TT_BOARD_X + TT_BOARD_WIDTH + TT_GAP)

// Sidebar
#define TT_SIDEBAR_GAP 20
#define TT_NEXT_BLOCK_HEIGHT (TT_SIDEBAR_WIDTH)
#define TT_NEXT_BLOCK_Y (TT_Y + TT_CELL_SIZE + TT_SIDEBAR_GAP)
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
//SNAKE GAME 
//----------------------------------------------------------------------------------------------------------------------
#define SNAKE_cellSize 25
#define SNAKE_cellCount 20
#define SNAKE_Offset 150