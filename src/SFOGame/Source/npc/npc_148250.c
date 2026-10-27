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

void std_swap_vectordeleterR_vectordeleterR_2(PtrVec* a, PtrVec* b) {
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
LP_8290* cLosRequest_cCollisionModelList_Game_GetCollisionModelList(void);
void cCollisionModelList_Resize_ExclusionList(LP_8290* lp, int a);
void cCollisionModelList_PushBack_ExclusionList(LP_8290* lp, void* obj);
void nCollision_DetectForIntersectionBetweenRayAndFaces(void* a, void* b, void* c, void* d, LP_8290* lp, int g, unsigned char h, unsigned char i, int j, unsigned char k);
}
extern "C" void cLosManager_cCollisionModelList_Game_PerformImmediateRayIntersectionTest(void* unused, void* a, void* b, void* c, void* d, void* e1, void* e2, int g, unsigned char h, unsigned char i, int j, unsigned char k)
{
    LP_8290* lp = cLosRequest_cCollisionModelList_Game_GetCollisionModelList();
    lp->SetSource(c);
    cCollisionModelList_Resize_ExclusionList(lp, 0);
    if (e1)
        cCollisionModelList_PushBack_ExclusionList(lp, e1);
    if (e2)
        cCollisionModelList_PushBack_ExclusionList(lp, e2);
    nCollision_DetectForIntersectionBetweenRayAndFaces(a, b, c, d, lp, g, h, i, j, k);
}
#pragma pop /* merge_units */
/* merge_units: end func_00148290 */

/* merge_units: begin func_00148380 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_buffer_dtor.h"

extern "C" { char D_0049B3F8[] = "allocator.hh"; }
DEFINE_GUARDED_BUFFER_CALL_DTOR(std_vector_deleter_Record_dtor, std_vector_deleter_Record_clear, D_0049B3F8)
#pragma pop /* merge_units */
/* merge_units: end func_00148380 */
