#include "types.h"
typedef struct { char p[0x48]; int sel; unsigned char vis[4]; int x0[2]; int x1[2]; char p60[4]; int v; int lo; int hi; } W43F070;
extern void func_0041E040(void* w, int kind, int v, int z);
extern void func_0041DF00(W43F070* w, int kind, int pos, int z);
#pragma push
static inline float Mul43F070(float a, float b) { return a * b; }
static inline int Lerp43F070(int a, int b, float t) { return a + (int)Mul43F070(t, (float)(b - a)); }
void func_0043F070(W43F070* w, int v)
{
    w->v = v < w->lo ? w->lo : (w->hi < v ? w->hi : v);
    if (w->vis[w->sel]) {
        int lo = w->lo;
int x0 = w->x0[w->sel];
        func_0041DF00(w, 10, Lerp43F070(x0, w->x1[w->sel], (float)(w->v - lo) / (float)(w->hi - lo)), 0);
        func_0041E040(w, 0x1D, w->v, 0);
    }
}
#pragma pop
