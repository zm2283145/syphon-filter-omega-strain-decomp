/*
 * main/playerControls: range (2 files, 0024FB50-0024FBC0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "vtable2_base_dtor.h"
#pragma pop
#include "types.h"

/* merge_units: begin func_0024FB50 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_VTABLE2_BASE_DTOR(func_0024FB50, D_004E0120, D_004E0840, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_0024FB50 */

/* merge_units: begin func_0024FBC0 */
#pragma push /* merge_units */
typedef struct { unsigned char active; unsigned char passive; char pad[0x9E]; } D6EdgeReq;
typedef struct { char pad[0x3E0]; D6EdgeReq req[1]; } D6EdgeOwner;
void EdgeRequest_Latch(D6EdgeOwner* o, signed char idx, unsigned char passive)
{
    D6EdgeReq* e = (D6EdgeReq*)((char*)o + 0x3E0) + idx;
    if (e->active) {
        e->passive = e->passive && passive;
    } else {
        e->passive = passive;
    }
    e->active = 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0024FBC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0024FBC0 */
