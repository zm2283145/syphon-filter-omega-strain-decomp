#include "types.h"
typedef struct { int a[4]; unsigned char active; float t; float dur; float frac; } S178;
void func_00178440(S178* s, float dt) {
    if (s->active) {
        s->t += dt;
        if (s->t < s->dur) {
            s->frac = s->t / s->dur;
        } else {
            s->t = 0.0f;
            s->dur = 0.0f;
            s->frac = 1.0f;
            s->active = 0;
        }
    }
}