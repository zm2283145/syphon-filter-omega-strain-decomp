#include "types.h"
typedef struct { char p[0x48]; unsigned char vis; char p49[3]; int x0; int x1; unsigned char b54; char p55[3]; int v; int lo; int hi; } W43BC70;
extern void func_0041DF00(W43BC70* w, int kind, int pos, int z);
#pragma push
static inline float Mul43BC70(float a, float b) { return a * b; }
static inline int Lerp43BC70(int a, int b, float t) { return a + (int)Mul43BC70(t, (float)(b - a)); }
void func_0043BC70(W43BC70* w, unsigned char b, int v, int lo, int hi)
{
    w->b54 = b;
    w->lo = hi < lo ? hi : lo;
    w->hi = hi < lo ? lo : hi;
    w->v = v < w->lo ? w->lo : (w->hi < v ? w->hi : v);
    if (w->vis) {
        int lo = w->lo;
int x0 = w->x0;
        func_0041DF00(w, 10, Lerp43BC70(x0, w->x1, (float)(w->v - lo) / (float)(w->hi - lo)), 0);
    }
}
#pragma pop
