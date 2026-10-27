/*
 * main/gameobj: range (2 files, 00393C50-00393CC0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "gobj_types.h"

/* merge_units: begin func_00393C50 */
#pragma push /* merge_units */
/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 */


extern Rel* std_vector_imp_cSkaSliderValue_ctor(Rel* r);

void* cSkaAnimationSet_AnimAnchorNameList(char* self) {
    return self + 4;
}

void func_00393C60(int* self, int value) {
    *self = value;
}

Rel* std_vector_cSkaSwitchValue_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

RelFlag* cArray_cSkaSliderValue_ctor(RelFlag* r) {
    std_vector_imp_cSkaSliderValue_ctor(&r->rel);
    r->flag = 1;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00393C50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00393C50 */

/* merge_units: begin func_00393CC0 */
#pragma push /* merge_units */
extern Quad4Ext* std_deque_cSkaSystem_Request_ctor(Quad4Ext* q);
extern Quad4Ext* func_00393D40(Quad4Ext* q);
extern Quad4* cdeque_cSkaSystem_RequestPtr_ctor(Quad4* q);

Rel* std_vector_imp_cSkaSliderValue_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

Quad4Ext* func_00393CE0(Quad4Ext* q) {
    std_deque_cSkaSystem_Request_ctor(q);
    return q;
}

Quad4Ext* std_deque_cSkaSystem_Request_ctor(Quad4Ext* q) {
    func_00393D40(q);
    return q;
}

Quad4Ext* func_00393D40(Quad4Ext* q) {
    cdeque_cSkaSystem_RequestPtr_ctor(&q->q);
    q->unk10 = 0;
    q->unk14 = 0;
    return q;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00393CC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00393CC0 */
