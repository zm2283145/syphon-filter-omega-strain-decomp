#include "types.h"
extern int D_0048B0E0;
typedef struct { char pad[0x60]; int v; } T262470;
void func_00262470(T262470* p, float f) {
    p->v = (int)((float)D_0048B0E0 * f / 100.0f);
}