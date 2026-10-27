/*
 * SFOGame/Source/humanIk: 1 file, 001CA7D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001CA7D0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x324]; float a; float b; } S1CA7D0;
void cHumanIkRoutine_ApplyGunRecoil_float_float(S1CA7D0* p, float a, float b)
{
    p->a = a;
    if (b <= 4.0f) {
        p->b = 0.0f;
    } else {
        p->b = b;
        p->b = b - -30.0f;
        p->b *= 0.018027762f;
        {
            float v = p->b;
            float lo = 0.0f;
            float hi = 1.0f;
            asm {
                max.s v, v, lo
                min.s v, v, hi
            }
            p->b = v;
        }
    }
}
static inline void merge_flush_func_001CA7D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CA7D0 */
