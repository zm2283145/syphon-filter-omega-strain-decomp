/*
 * main/interface_model: 3 files, 003F43C0-003F44E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003F43C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void cAnimator_Update(void) {
}
#pragma pop /* merge_units */
/* merge_units: end func_003F43C0 */

/* merge_units: begin func_003F43D0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct B7_Ramp {
    virtual void v0(); virtual void v1();
    virtual void SetValue(float v); /* +0x10 */
    float value;
    float min;
    float max;
    float vel;
    unsigned char pingpong;
};
extern "C" void IeElement_UpdateAnimation(B7_Ramp* r, float dt)
{
    if (r->vel != 0.0f) {
        r->value += r->vel * dt;
        if (r->vel > 0.0f) {
            if (r->value > r->max) {
                if (r->pingpong) {
                    r->vel = -r->vel;
                    r->value = r->max;
                } else if (r->min == r->max) {
                    r->vel = 0.0f;
                    r->value = r->max;
                } else {
                    r->value = r->min;
                }
            }
        } else {
            if (r->value < r->min) {
                if (r->pingpong) {
                    r->vel = -r->vel;
                    r->value = r->min;
                } else if (r->min == r->max) {
                    r->vel = 0.0f;
                    r->value = r->min;
                } else {
                    r->value = r->max;
                }
            }
        }
        r->SetValue(r->value);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003F43D0 */

/* merge_units: begin func_003F44E0 */
#pragma push /* merge_units */
typedef struct { int f0; float f4; float f8; float fC; float f10; char b14; } S3F44E0;
void IeElement_Fade(S3F44E0* s, float x) {
    s->f8 = x;
    s->fC = x;
    if (s->f4 <= x) {
        s->f10 = 1.0f;
    } else {
        s->f10 = -1.0f;
    }
    s->b14 = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003F44E0 */
