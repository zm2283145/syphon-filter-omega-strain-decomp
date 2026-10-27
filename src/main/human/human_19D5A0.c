/*
 * main/human: range (2 files, 0019D5A0-0019D640)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0019D5A0 */
#pragma push /* merge_units */
typedef struct { char pad[0x10]; float f10; } Src_D640;
typedef struct {
    char pad[0x1C]; float f1C; float f20; float f24; float f28; float f2C; Src_D640* p30; float f34;
} Ch_D640;
void cSplinedMotion_float_RestartTransition(Ch_D640* c, float d); /* gsynth: defined below */typedef struct {
    char pad0[0x10];
    float target;
    float damping;
    char pad18[0x20];
    unsigned char active;
    char pad39[3];
} B7_Chan;
typedef struct { char pad[0x80]; B7_Chan* chans; } B7_Anim;
#if 0 /* merge_units */
extern void cSplinedMotion_float_RestartTransition(B7_Chan* ch, float d);
#endif /* merge_units */
#define cSplinedMotion_float_RestartTransition(a0, a1) (cSplinedMotion_float_RestartTransition((void *)(a0), (a1))) /* merge_units */

void cSkaParams_SetSliderValue_UsingSplineForInterpolation(B7_Anim* a, int idx, unsigned int n, float target, float dur, float damping)
{
    B7_Chan* ch = &a->chans[idx];
    ch->target = target;
    ch->damping = damping;
    cSplinedMotion_float_RestartTransition(ch, dur);
    { float fn = n; float z = 0.0f; ch->active = fn != z; }
}
#undef cSplinedMotion_float_RestartTransition /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0019D5A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0019D5A0 */

/* merge_units: begin func_0019D640 */
#pragma push /* merge_units */
void cSplinedMotion_float_RestartTransition(Ch_D640* c, float d) {
    float s;
    if (d >= 0.0f) {
        s = d * c->f2C;
        c->f1C = c->f1C * s;
        c->f24 = c->f24 * s;
        c->f28 = d;
        c->f2C = d != 0.0f ? 1.0f / d : 0.0f;
        c->f34 = c->p30->f10;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0019D640(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0019D640 */
