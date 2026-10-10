#include "types.h"
typedef struct { unsigned char flag : 1; unsigned char rest : 7; } Bits00465D50;
typedef struct { Bits00465D50 slots[16]; } Row00465D50;
extern Row00465D50* D_004EE620;
/* Clear the low flag bit of slot (row, col). */
void func_00465D50(int row, int col)
{
    D_004EE620[row].slots[col].flag = 0;
}
