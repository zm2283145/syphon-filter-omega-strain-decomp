#include "types.h"
typedef struct H1LadPhys {
    char pad000[0x99C];
    unsigned char blockTop;      /* 0x99C */
    unsigned char blockBottom;   /* 0x99D */
    unsigned char pad99E;
    unsigned char snapped;       /* 0x99F */
} H1LadPhys;
typedef struct H1Actor62A0 {
    char pad0000[0x31B5];
    unsigned char slideHeld;     /* 0x31B5 */
    unsigned char exitHeld;      /* 0x31B6 */
    char pad31B7[0x31C8 - 0x31B7];
    float stickY;                /* 0x31C8 */
    char pad31CC[0x31D8 - 0x31CC];
    float slideAmount;           /* 0x31D8 */
    char pad31DC[0x3210 - 0x31DC];
    int padFlags;                /* 0x3210 */
    char pad3214[0x3310 - 0x3214];
    H1LadPhys* phys;             /* 0x3310 */
} H1Actor62A0;
static inline float h1_fabs(float x) { asm { abs.s x, x } return x; }

/* Climb intent: slide / up / down, plus the three requested values. */
void func_004762A0(H1Actor62A0* self, unsigned char* outSlide, unsigned char* outUp, unsigned char* outDown,
                   unsigned char* slide, unsigned char* up, unsigned char* down) {
    H1LadPhys* p = self->phys;
    unsigned char centered;
    unsigned char blockTop;
    unsigned char blockBottom;
    unsigned char onRung;
    unsigned char aligned;
    blockTop = 0;
    if (p != 0 && p->blockTop) blockTop = 1;
    blockBottom = 0;
    if (p != 0 && p->blockBottom) blockBottom = 1;
    onRung = p != 0 && p->snapped;
    aligned = onRung; if (aligned) aligned = ((self->padFlags >> 13) & 1) != 0;
    centered = aligned; if (aligned) centered = h1_fabs(self->stickY) < 0.5f;    *slide = (self->slideHeld || self->slideAmount > 0.75f) && !self->exitHeld;
    *up = !*slide && self->stickY > 0.0f && !centered && !self->exitHeld;
    *down = !*slide && self->stickY < 0.0f && !centered && !self->exitHeld;
    *outSlide = *slide && !blockTop;
    *outUp = *up && !blockBottom;
    *outDown = *down && !blockTop;
}