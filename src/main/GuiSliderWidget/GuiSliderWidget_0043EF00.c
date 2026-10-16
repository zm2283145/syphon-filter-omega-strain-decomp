#include "types.h"
typedef struct { char p[0x48]; int sel; unsigned char vis[4]; int x0[2]; int x1[2]; char p60[4]; int v; int lo; int hi; } W43EF00;
extern void GuiWidget_BroadcastEvent(W43EF00* w, int kind, int pos, int z);
#pragma push
static inline float Mul43EF00(float a, float b) { return a * b; }
static inline int Lerp43EF00(int a, int b, float t) { return a + (int)Mul43EF00(t, (float)(b - a)); }
void func_0043EF00(W43EF00* w, int sel)
{
    w->sel = sel;
    if (w->vis[w->sel]) {
        int lo = w->lo;
int x0 = w->x0[w->sel];
        GuiWidget_BroadcastEvent(w, 10, Lerp43EF00(x0, w->x1[w->sel], (float)(w->v - lo) / (float)(w->hi - lo)), 0);
    }
}
#pragma pop
