#include "types.h"
typedef struct { char p[0x48]; int sel; unsigned char vis[4]; int x0[2]; int x1[2]; char p60[4]; int v; int lo; int hi; } W43EFA0;
extern void func_0041E040(void* w, int kind, int v, int z);
extern void func_0041DF00(W43EFA0* w, int kind, int pos, int z);
#pragma push
static inline float Mul43EFA0(float a, float b) { return a * b; }
static inline int Lerp43EFA0(int a, int b, float t) { return a + (int)Mul43EFA0(t, (float)(b - a)); }
void func_0043EFA0(W43EFA0* w, int notify)
{
    if (w->vis[w->sel]) {
        int lo = w->lo;
int x0 = w->x0[w->sel];
        func_0041DF00(w, 10, Lerp43EFA0(x0, w->x1[w->sel], (float)(w->v - lo) / (float)(w->hi - lo)), 0);
        if (notify) func_0041E040(w, 0x1D, w->v, 0);
    }
}
#pragma pop
