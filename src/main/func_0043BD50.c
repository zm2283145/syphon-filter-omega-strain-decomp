#include "types.h"
typedef struct { char p[0x48]; unsigned char vis; char p49[3]; int x0; int x1; char p54[4]; int v; int lo; int hi; } W43BD50;
extern void func_0041DF00(W43BD50* w, int kind, int pos, int z);
#pragma push
static inline float Mul43BD50(float a, float b) { return a * b; }
static inline int Lerp43BD50(int a, int b, float t) { return a + (int)Mul43BD50(t, (float)(b - a)); }
void func_0043BD50(W43BD50* w, int horiz)
{
    if (w->vis) {
        int lo = w->lo;
int x0 = w->x0;
        func_0041DF00(w, horiz ? 10 : 11, Lerp43BD50(x0, w->x1, (float)(w->v - lo) / (float)(w->hi - lo)), 0);
    }
}
#pragma pop
