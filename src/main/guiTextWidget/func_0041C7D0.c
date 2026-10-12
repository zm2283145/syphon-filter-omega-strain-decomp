#include "types.h"
typedef struct { char p[0x11]; unsigned char b11, b12; } S41C7D0;
typedef struct { void* vt; char p4[0x44]; int f48; int f4C; int f50; int f54; char p58[8]; float f60, f64, f68; char p6C[4]; int f70; unsigned char b74, b75, b76; char p77; S41C7D0* f78; } W41C7D0;
extern void GuiWidget_ctor(W41C7D0* w);
extern char D_004E0AC0[];
W41C7D0* func_0041C7D0(W41C7D0* w)
{
    GuiWidget_ctor(w);
    w->vt = D_004E0AC0;
    w->f48 = 0;
    w->f4C = 0;
    w->f50 = 0;
    w->f68 = 1.0f;
    w->f64 = 1.0f;
    w->f60 = 1.0f;
    w->f54 = 0;
    w->f70 = 0;
    w->f78 = 0;
    w->b75 = 0;
    w->b76 = 0;
    w->b74 = 0;
    if (w->f78) {
        w->f78->b12 = w->b74 == 0;
        w->f78->b11 = w->b74 == 2;
    }
    return w;
}
