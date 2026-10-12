#include "types.h"
typedef struct { char p[0x48]; int sel; unsigned char vis[4]; int x0[2]; int x1[2]; unsigned char b60; char p61[3]; int v; int lo; int hi; int f70; } W43F150;
extern void func_0041DF00(W43F150* w, int kind, int pos, int z);
#pragma push
static inline float Mul43F150(float a, float b) { return a * b; }
static inline int Lerp43F150(int a, int b, float t) { return a + (int)Mul43F150(t, (float)(b - a)); }
void func_0043F150(W43F150* w, unsigned char b, int v, int lo, int hi, int f70)
{
    w->b60 = b;
    w->v = v;
    w->lo = lo;
    w->hi = hi;
    w->f70 = f70;
    if (w->vis[w->sel]) {
        int lo2 = w->lo;
int x0 = w->x0[w->sel];
        func_0041DF00(w, 10, Lerp43F150(x0, w->x1[w->sel], (float)(w->v - lo2) / (float)(w->hi - lo2)), 0);
    }
}
#pragma pop
