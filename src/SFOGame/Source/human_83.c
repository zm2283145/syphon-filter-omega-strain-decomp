/*
 * SFOGame/Source/human: 2 files, 001A36C0-001A3730
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001A36C0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cNetBackpackMsg_dtor, D_004DCEF0, D_004DCF10, cMessage_dtor)
static inline void merge_flush_func_001A36C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A36C0 */

/* merge_units: begin func_001A3730 */
#pragma push /* merge_units */
typedef struct Human3468 {
    char pad[0x3468];
    unsigned char flagA;
    unsigned char flagB;
    char pad2[0x3528 - 0x346A];
    int handle;
} Human3468;

extern int ItemInv_Any(int handle);

/* True when neither flag is set and ItemInv_Any(handle) returns 0 (as a byte). */
int cHuman_CanPackBeDeleted(Human3468* h) {
    int result = !(h->flagA != 0 || h->flagB != 0);
    if (result) {
        result = (unsigned char)ItemInv_Any(h->handle) == 0;
    }
    return result;
}
static inline void merge_flush_func_001A3730(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001A3730 */
