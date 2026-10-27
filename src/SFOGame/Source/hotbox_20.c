/*
 * SFOGame/Source/hotbox: 3 files, 00172930-001729B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00172930 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cAddCheckpointMsg_dtor, D_004DB8D0, cMessage_dtor)
static inline void merge_flush_func_00172930(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00172930 */

/* merge_units: begin func_00172990 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int* std_vector_cGOBJPtr_opIndex(PtrVec* v, int i) {
    return v->data + i;
}

void cHotbox_Render(void) {
}
static inline void merge_flush_func_00172990(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00172990 */

/* merge_units: begin func_001729B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
class O_29B0 {
public:
    VPAD16(a) VPAD8(b) VPAD1(c)
    virtual int Handle();
    char pad[0x8C];
    int state;
};
struct Ev_29B0 { char pad[0x24]; unsigned char kind; };
extern "C" {
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
}
struct T_29B0 { int id; bool operator==(const T_29B0& o) const { return id == o.id; } };
extern "C" { extern T_29B0 g_TriggerMsgKey; T_29B0* cMessage_Name(Ev_29B0* e); }
extern "C" int cHotbox_IsDeliverable(O_29B0* self, Ev_29B0* e)
{
    int ok = g_IsMultiplayer ? D_005721C0 : 1;
    if (ok && self->state == 8 && *cMessage_Name(e) == g_TriggerMsgKey && e->kind == 4)
        return self->Handle();
    return 1;
}
static inline void merge_flush_func_001729B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001729B0 */
