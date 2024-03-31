#pragma once

#define TITLE_SIZE 50
#define SCREEN_W 1300
#define SCREEN_H 700

#define OVERLAY_COLOR {255,255,255,200}

//----------------------------------------------------------------------------------------------------------------------
//MENU
//----------------------------------------------------------------------------------------------------------------------
#define GAME_BOX_SIZE 100
#define GAME_BOX_1_OSX 

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

#define TT_BOARD_OFFSET_X (SCREEN_W / 2 - (TT_BOARD_WIDTH + TT_PADDING) / 2 - TT_SIDEBAR_WIDTH / 2 - TT_GAP / 2)
#define TT_BOARD_OFFSET_Y 80
#define TT_CELL_OFFSET_X (TT_BOARD_OFFSET_X + TT_PADDING)
#define TT_CELL_OFFSET_Y 80
#define TT_SIDEBAR_OFFSET_X (TT_BOARD_OFFSET_X + TT_BOARD_WIDTH + TT_GAP)
#define TT_SIDEBAR_OFFSET_Y 80

// Sidebar
#define TT_SIDEBAR_GAP 20
#define TT_NEXT_BLOCK_HEIGHT (TT_SIDEBAR_WIDTH)
#define TT_NEXT_BLOCK_OFFSET_Y (TT_SIDEBAR_OFFSET_Y + TT_CELL_SIZE + TT_SIDEBAR_GAP)
//----------------------------------------------------------------------------------------------------------------------