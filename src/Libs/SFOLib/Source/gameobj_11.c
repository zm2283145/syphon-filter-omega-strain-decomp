/*
 * Libs/SFOLib/Source/gameobj: 5 files, 00393B80-00393D70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00393B80 */
#pragma push /* merge_units */
/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

extern int std_vector_imp_cSkaSliderValue_resize(void* v, int a1, int a2);
extern int std_vector_imp_cSkaSwitchValue_resize(void* v, int a1, int a2);

int cArray_cSkaSwitchValue_ResizeActual(void* v, int a1, int a2) {
    return std_vector_imp_cSkaSwitchValue_resize(v, a1, a2);
}

int cSkaAnimationSet_SwitchParamCount(char* self) {
    return *(int*)(self + 0x58);
}

/* Clears a two-word pair. */
int* cSkaSwitchValue_ctor(int* p) {
    p[0] = 0;
    p[1] = 0;
    return p;
}

int cArray_cSkaSliderValue_ResizeActual(void* v, int a1, int a2) {
    return std_vector_imp_cSkaSliderValue_resize(v, a1, a2);
}

int cSkaAnimationSet_SliderParamCount(char* self) {
    return *(int*)(self + 0x54);
}
static inline void merge_flush_func_00393B80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00393B80 */

/* merge_units: begin func_00393BD0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC00393BD0 { virtual int v0(); virtual int v1(); virtual int v2(); virtual float v3(); };
extern "C" {
int cSplinedMotion_float_ctor_floatR_floatR(...);                 
static const unsigned int dat_00493460[2] = { 0x0, 0x0 };
static const unsigned int dat_00493468[2] = { 0x0, 0x0 };
extern int D_004DA840;
}
extern "C" int cSkaSliderValue_ctor_float(char *arg0, float farg0) {
    cSplinedMotion_float_ctor_floatR_floatR(arg0, &(*(int*)dat_00493460), &(*(int*)dat_00493468));
    F_(arg0, 0x0, int) = (int)(&D_004DA840);
    F_(arg0, 0x38, signed char) = 0;
    F_(arg0, 0x10, float) = farg0;
    F_(arg0, 0x8, float) = farg0;
    F_(arg0, 0x4, float) = farg0;
    F_(arg0, 0xC, float) = ((VC00393BD0 *)(arg0))->v3();
    return (int)(arg0);
}
static inline void merge_flush_func_00393BD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00393BD0 */

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

/* merge_units: begin func_00393D70 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(details_compressed_pair_imp_cAllocator_cSkaSystem_Request_1_dtor, _cdeque_imp_cSkaSystem_RequestPtr_1_dtor)
static inline void merge_flush_func_00393D70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00393D70 */
