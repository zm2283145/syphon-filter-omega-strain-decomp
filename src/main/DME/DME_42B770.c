/*
 * main/DME: 4 files, 0042B770-0042B890
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0042B770 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "network_admission.h"

/* Test admission flags and the current player count without reserving a slot. */
extern "C" unsigned char func_0042B770(void)
{
    return room_available();
}
#pragma pop /* merge_units */
/* merge_units: end func_0042B770 */

/* merge_units: begin func_0042B800 */
#pragma push /* merge_units */
extern void operator_delete(void* allocation);

/* Empty deleting destructor; the object's concrete type is not yet known. */
void* func_0042B800(void* self, short deleteFlag) {
    if (self != 0 && deleteFlag > 0) {
        operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0042B800 */

/* merge_units: begin func_0042B850 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies between DME.cc (ends 0x0042ACD0) and nellymoser_wrapper.c.
 */

#include "types.h"

extern char D_005721B0;
extern char D_005724B8[];
extern int func_002EBC48(void* obj);

void* func_0042B850(void* self) {
    D_005721B0 = 0;
    func_002EBC48(D_005724B8);
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0042B850 */

/* merge_units: begin func_0042B890 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_0042B890, func_0042B8F0)
#pragma pop /* merge_units */
/* merge_units: end func_0042B890 */
