#include "types.h"

typedef struct { unsigned char flag : 1; unsigned char rest : 7; } FlagByte;
typedef struct { FlagByte b[16]; } FlagRow;
extern FlagRow* D_004EE620;

/* Clears flag bit 0 of byte [col] in row [row] of the global flag table. */
void TeamTable_ClearEnemy(int row, int col)
{
    D_004EE620[row].b[col].flag = 0;
}
