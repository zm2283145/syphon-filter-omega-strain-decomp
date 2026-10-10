#include "types.h"

typedef struct FlagByte {
    unsigned char set : 1;
    unsigned char rest : 7;
} FlagByte;

typedef FlagByte FlagRow[16];

extern FlagRow* D_004EE620;

/* Sets bit 0 of entry [row][col] in the 16-column flag table. */
void func_00465D80(int row, int col) {
    D_004EE620[row][col].set = 1;
}
