/*
 * Libs/SFOLib/Source/DME: 1 file, 0042B4E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin DME_42B4E0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "network_admission.h"

/* Report whether any retry slot has a valid deadline at or beyond the threshold. */
extern "C" bool func_0042B4E0(void)
{
    bool unavailable = true;
    unsigned int threshold = retry_threshold();
    if ((D_00572428 >= 0x0FFFFFFE || D_00572428 < threshold) &&
        (D_0057242C >= 0x0FFFFFFE || D_0057242C < threshold) &&
        (D_00572430 >= 0x0FFFFFFE || D_00572430 < threshold))
        unavailable = false;
    return unavailable;
}
static inline void merge_flush_DME_42B4E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end DME_42B4E0 */
