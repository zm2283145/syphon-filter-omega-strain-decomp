#include "types.h"
typedef struct { char p[0x10]; int f10; int f14; } D43F850;
typedef struct { char p[0x4C]; unsigned char vis[4]; int x0[2]; int x1[2]; } W43F850;
extern void GuiWidget_Init(W43F850* w);
extern int GuiWidget_SendEvent(W43F850* w, W43F850* src, int kind, int a, int out);
extern char D_004C01D0[];
extern char D_004C01E0[];
static int D_004976C0[] = { (int)D_004C01D0, (int)D_004C01E0 };
void GuiSliderWidget_Init(W43F850* w)
{
    int i;
    D43F850* d[1];
    GuiWidget_Init(w);
    for (i = 0; i < 2; i++) {
        d[0] = 0;
        if (GuiWidget_SendEvent(w, w, 4, D_004976C0[i], (int)d) && d[0]) {
            w->vis[i] = 1;
            w->x0[i] = d[0]->f10;
            w->x1[i] = d[0]->f14;
        }
    }
}
