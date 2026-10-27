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
