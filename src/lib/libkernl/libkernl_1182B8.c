#include "types.h"

/* Library code: matches with EE-GCC 2.95 -O2 (check.py --gcc). */

typedef struct { unsigned int state; int pad[3]; } Entry;
extern Entry* D_00487868;
extern unsigned int D_0048786C;
extern Entry D_004E9AC8[];

/* Clears an entry of one of two tables (negative index selects the fixed 32-entry table); -0x69 if out of range. */
int func_001182B8(int index)
{
    Entry* table;
    unsigned int count;
    if (index < 0) {
        index &= 0x7FFFFFFF;
        table = D_004E9AC8;
        count = 0x20;
    } else {
        table = D_00487868;
        count = D_0048786C;
    }
    if ((unsigned int)index < count) {
        table[index].state = 0;
        return 0;
    }
    return -0x69;
}
