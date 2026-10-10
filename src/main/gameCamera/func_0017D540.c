#include "types.h"
typedef struct { int pad0; float v; } F17D540_t;
static inline float F17D540_Max(float a, float b) {
    float r;
    asm {
        mov.s r, a
        max.s r, b, r
    }
    return r;
}
int func_0017D540(F17D540_t* p, float dt) {
    float old = p->v;
    p->v -= dt;
    p->v = F17D540_Max(p->v, 0.0f);
    return old > 0.0f && p->v == 0.0f;
}