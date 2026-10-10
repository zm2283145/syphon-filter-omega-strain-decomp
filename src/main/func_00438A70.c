#include "types.h"

extern void* D_00497550;
extern unsigned char D_00582D00;
extern void* D_00497558;
extern int func_002EC7D0(void* a, void* b);

/* Registers (a, b) as the active pair if func_002EC7D0 accepts them; returns 1 on success. */
unsigned char func_00438A70(void* a, void* b)
{
    unsigned char ok = 0;
    if (func_002EC7D0(a, b) == 0) {
        D_00497550 = a;
        ok = 1;
        D_00582D00 = 1;
        D_00497558 = b;
    }
    return ok;
}
