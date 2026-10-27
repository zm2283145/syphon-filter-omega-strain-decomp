/*
 * SFOGame/Source/npc: 3 files, 0015A3A0-0015A430
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0015A3A0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop
#include "types.h"
#include "vc_copy.h"

#pragma cplusplus on

DEFINE_VTABLE_BASE_DTOR(cHotboxMsg_dtor, D_004D9940, cMessage_dtor)
static inline void merge_flush_func_0015A3A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015A3A0 */

/* merge_units: begin func_0015A400 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_;
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
V4_ cVector_Copy_WSet0(const V4_* v) {
    V4_ t;
    float zf = 0.0f;
    V4_* d = &t;
    VCopyF(d, v);
    {
        V4_* e = &t;
        e->w = zf;
        return *e;
    }
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0015A400(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0015A400 */

/* merge_units: begin func_0015A430 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

/* True when the message's mode byte is 3. */
int cMoveMsg_Template_1_HasDeltaPosition(NpcAiMsg* msg) {
    return (unsigned int)(msg->aiMode ^ 3) < 1U;
}
static inline void merge_flush_func_0015A430(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015A430 */
