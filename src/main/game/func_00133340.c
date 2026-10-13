#include "types.h"
typedef struct { char pad[0x1E8]; unsigned long long last; } World_133340;
extern int D_00533870;
extern unsigned long long D_00533878;
extern float func_001002D0(unsigned long long x);
static inline float clamp_133340(float x, float lo, float hi) { asm { max.s lo, x, lo
 min.s lo, lo, hi } return lo; }
float World_GetElapsedTime(World_133340* w) {
    unsigned long long now = D_00533878 + (unsigned int)(int)((float)(unsigned int)(*(volatile int*)0x10000800 + D_00533870) / 5.76f);
    float dt = func_001002D0(now - w->last) / 100000.0f;
    dt = clamp_133340(dt, 0.0f, 0.05f);
    w->last = now;
    return dt;
}
