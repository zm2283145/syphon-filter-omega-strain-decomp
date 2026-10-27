/*
 * Libs/SFOLib/Source/man: 1 file, 00385330
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00385330 */
#pragma push /* merge_units */
#include "types.h"

/* Result block filled by cMan_GetGunBarrelMatrix_WithoutFlippingAxes; the quadword at +0x30 is returned. */
typedef struct Result385 {
    char pad[0x30];
    Q value;
} Result385;

extern void cMan_GetGunBarrelMatrix_WithoutFlippingAxes(void* src, Result385* out);

/* Computes a result block from src and copies its quadword at +0x30 to out. */
void cMan_GetGunBarrelEnd(Q* out, void* src) {
    Result385 result;
    cMan_GetGunBarrelMatrix_WithoutFlippingAxes(src, &result);
    *out = result.value;
}
static inline void merge_flush_func_00385330(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00385330 */
