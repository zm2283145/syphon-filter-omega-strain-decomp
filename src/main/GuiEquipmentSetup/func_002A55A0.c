#include "types.h"

typedef struct CellFlags {
    unsigned char set : 1;
    unsigned char rest : 7;
} CellFlags;

typedef struct CellRow {
    CellFlags cells[16];
} CellRow;

extern CellRow* D_004EE620;

/* Marks cell (row, col) in the D_004EE620 grid. */
void func_002A55A0(int row, int col) {
    D_004EE620[row].cells[col].set = 1;
}
