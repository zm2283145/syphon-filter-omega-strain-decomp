/*
 * main/npc: 3 files, 00148250-00148380
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00148250 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_00148250(PtrVec* a, PtrVec* b) {
    if (a != b) {
        int t;
        int* p;
        t = a->unk0;
        a->unk0 = b->unk0;
        b->unk0 = t;
        p = a->data;
        a->data = b->data;
        b->data = p;
        t = a->count;
        a->count = b->count;
        b->count = t;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00148250 */

/* merge_units: begin func_00148290 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
class LP_8290 {
public:
    VPAD2(a)
    virtual void SetSource(void* src);
};
extern "C" {
LP_8290* LosProvider_Get(void);
void LosProvider_ClearExclusions(LP_8290* lp, int a);
void LosProvider_AddExclusion(LP_8290* lp, void* obj);
void Los_TraceImmediate(void* a, void* b, void* c, void* d, LP_8290* lp, int g, unsigned char h, unsigned char i, int j, unsigned char k);
}
extern "C" void LosMgr_TraceBullet(void* unused, void* a, void* b, void* c, void* d, void* e1, void* e2, int g, unsigned char h, unsigned char i, int j, unsigned char k)
{
    LP_8290* lp = LosProvider_Get();
    lp->SetSource(c);
    LosProvider_ClearExclusions(lp, 0);
    if (e1)
        LosProvider_AddExclusion(lp, e1);
    if (e2)
        LosProvider_AddExclusion(lp, e2);
    Los_TraceImmediate(a, b, c, d, lp, g, h, i, j, k);
}
#pragma pop /* merge_units */
/* merge_units: end func_00148290 */

/* merge_units: begin func_00148380 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_buffer_dtor.h"

extern "C" { char D_0049B3F8[] = "allocator.hh"; }
DEFINE_GUARDED_BUFFER_CALL_DTOR(func_00148380, func_00148470, D_0049B3F8)
#pragma pop /* merge_units */
/* merge_units: end func_00148380 */
