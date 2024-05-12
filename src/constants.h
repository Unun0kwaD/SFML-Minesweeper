#pragma once

#define SCALE 3.0f
#define CELLS_X 10
#define CELLS_Y 10
#define TEXTURE_SIZE 16
#define CELL_SIZE SCALE * TEXTURE_SIZE
#define WINDOW_WIDTH CELL_SIZE * CELLS_X
#define WINDOW_HEIGHT CELL_SIZE * CELLS_Y
#define MINES 20

#define EMPTY 8
#define HIDDEN 9
#define MINE 10
#define FLAG 11
