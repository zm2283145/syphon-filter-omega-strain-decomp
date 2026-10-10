#include "types.h"
typedef struct { int x0; int x4; int x8; int xC; } Slot143C50;
typedef struct { Slot143C50 s[6]; } Inv143C50;
extern void func_00142C50(Inv143C50*, int);
void func_00143C50(Inv143C50* inv) {
    int slot = 6;
    int i;
    for (i = 0; i < 6; i++) {
        if (inv->s[i].x8 != -1) { slot = (unsigned char)i; break; }
    }
    if ((unsigned char)slot != 6) func_00142C50(inv, slot);
}