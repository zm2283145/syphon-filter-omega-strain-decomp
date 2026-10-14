/*
 * main/human: range (2 files, 0019D7D0-0019D8E0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0019D7D0 */
#pragma push /* merge_units */
#pragma cplusplus on
class Chan_b6 {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual float Eval();
    float a4; float cur; float cC; float c10; unsigned char pad[0x3C - 0x14];
};
typedef struct { unsigned char pad[0x80]; Chan_b6* ch; } Anim_b6;
static inline float fmax_b6(float a, float b) { float r; asm { max.s r, a, b } return r; }
static inline float fmin_b6(float a, float b) { float r; asm { min.s r, a, b } return r; }
extern "C" void AnimChannel_Approach(Anim_b6* a, int idx, int wrap, float target, float step)
{
    Chan_b6* c = &a->ch[idx];
    float v = c->cur;
    float d = target - v;
    if (wrap) {
        if (d < -0.5f) {
            d += 1.0f;
        } else if (!(d <= 0.5f)) {
            d += -1.0f;
        }
    }
    v += fmin_b6(fmax_b6(d, -step), step);
    if (wrap) {
        if (v < 0.0f) {
            v += 1.0f;
        } else if (!(v <= 1.0f)) {
            v += -1.0f;
        }
    }
    c->c10 = v;
    c->cur = v;
    c->a4 = v;
    c->cC = c->Eval();
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0019D7D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0019D7D0 */

/* merge_units: begin func_0019D8E0 */
#pragma push /* merge_units */
typedef struct { int unk0; int unk4; unsigned int pending[1]; } D6ActorFlags;
void Actor_SetPendingFlag(D6ActorFlags* a, unsigned char bit, int on)
{
    if (on) {
        a->pending[(unsigned int)bit >> 5] |= 1 << (bit & 0x1F);
    } else {
        a->pending[(unsigned int)bit >> 5] &= ~(1 << (bit & 0x1F));
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0019D8E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0019D8E0 */
