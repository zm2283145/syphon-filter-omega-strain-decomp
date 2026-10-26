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
extern "C" unsigned char SFOLibInit_AllowPlayer(void)
{
    return room_available();
}
#pragma pop /* merge_units */
/* merge_units: end func_0042B770 */

/* merge_units: begin func_0042B800 */
#pragma push /* merge_units */
extern void operator_delete(void* allocation);

/* Empty deleting destructor; the object's concrete type is not yet known. */
void* cDME_dtor(void* self, short deleteFlag) {
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
extern int NetGetLocalTime(void* obj);

void* cDME_ctor(void* self) {
    D_005721B0 = 0;
    NetGetLocalTime(D_005724B8);
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0042B850 */

/* merge_units: begin func_0042B890 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(cArray_tServerPtr_dtor, std_vector_imp_tServerPtr_1_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_0042B890 */
