#include "types.h"
typedef struct { char pad[0x1E8]; unsigned long long last; } World_133340;
extern int g_TimerAccum;
extern unsigned long long g_TickCounter64;
extern float _f_ulltof(unsigned long long x);
static inline float clamp_133340(float x, float lo, float hi) { asm { max.s lo, x, lo
 min.s lo, lo, hi } return lo; }
float cGameSystem_UpdateTimeStep(World_133340* w) {
    unsigned long long now = g_TickCounter64 + (unsigned int)(int)((float)(unsigned int)(*(volatile int*)0x10000800 + g_TimerAccum) / 5.76f);
    float dt = _f_ulltof(now - w->last) / 100000.0f;
    dt = clamp_133340(dt, 0.0f, 0.05f);
    w->last = now;
    return dt;
}
