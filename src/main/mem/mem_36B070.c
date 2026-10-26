/*
 * main/mem: 2 files, 0036B070-0036B090
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0036B070 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

unsigned int D_00492F68[2] = { 0x1, 0x0 };

void cMemMan_DisallowConsolidation(void) {
    (*(unsigned char*)D_00492F68) = 0;
}

void cMemMan_AllowConsolidation(void) {
    (*(unsigned char*)D_00492F68) = 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_0036B070 */

/* merge_units: begin func_0036B090 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x814]; int handle; } H36B090;
extern H36B090 D_00533CB0[4];
extern int cMemBin_HaveAllocationInRange(H36B090* h, void* a, void* b);
int cMemMan_HaveAllocationInRange(void* a, void* b)
{
    int i;
    H36B090* h = D_00533CB0;
    for (i = 0; i < 4; i++, h++) {
        if (h->handle != -1 && cMemBin_HaveAllocationInRange(h, a, b)) return 1;
    }
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0036B090 */
