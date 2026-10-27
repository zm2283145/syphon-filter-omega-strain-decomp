#include "types.h"
typedef struct { char pad[0x54]; float v; } X3460;
static inline float clamp_3460(float x, float lo, float hi) { asm { max.s lo, x, lo
 min.s lo, lo, hi } return lo; }
void func_00243460(X3460* t, float x) {
    t->v = clamp_3460(x, 0.0f, 1.0f);
}
