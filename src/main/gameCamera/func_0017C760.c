#include "types.h"
typedef struct { char pad[4]; float f4; float f8; float vel; float f10; float f14; } D2_Curve;
static inline float d2_max(float a, float b) { float r; asm { max.s r, a, b } return r; }
void Curve_SetVelocity(D2_Curve* c, float dt, float scale) {
    c->vel = scale * (c->f8 - c->f4);
    c->vel *= d2_max(0.0f, 1.0f - c->f14 * dt);
}