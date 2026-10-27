#include "types.h"
#pragma opt_propagation off
static inline float fmax_EA70(float a, float b) { float r; asm { max.s r, a, b } return r; }
typedef struct { char p0[0xE4]; float a; char p1[0x1B4-0xE8]; float b; char p2[0x2A4-0x1B8]; float c; char p3[0x374-0x2A8]; float d; } XEA70;
float cHandIkTargetList_GetTransitionTimeLeftForBothHands(XEA70* s) {
    float c; float d; float m1; float a; float b; c = s->c; d = s->d; m1 = fmax_EA70(c, d); a = s->a; b = s->b; return fmax_EA70(fmax_EA70(a, b), m1);
}