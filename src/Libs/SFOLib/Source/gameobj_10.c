/*
 * Libs/SFOLib/Source/gameobj: 4 files, 003939B0-00393A40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003939B0 */
#pragma push /* merge_units */
#include "gobj_types.h"
#include "types.h"

/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 */


/* Address of the value stored at +8 of the current node. */
char* cLListIterator_cSkaTransPlaybackPtr_opMul(Iter16* it) {
    return it->p + 8;
}

void cLList_cSkaTransPlaybackPtr_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003939B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003939B0 */

/* merge_units: begin func_003939D0 */
#pragma push /* merge_units */
Rel* std_vector_cTreeNode_cSkaSystemPtrPtr_ctor(Rel* r); /* gsynth: defined below */typedef struct { char pad[0xC]; unsigned char flag; } Sub;
typedef struct { int v; int z; Sub sub; } S;
#if 0 /* merge_units */
extern void std_vector_cTreeNode_cSkaSystemPtrPtr_ctor(Sub*);
#endif /* merge_units */
#define std_vector_cTreeNode_cSkaSystemPtrPtr_ctor(a0) ((void)std_vector_cTreeNode_cSkaSystemPtrPtr_ctor((Rel *)(a0))) /* merge_units */


/* Constructor: copies a value, clears a field, inits the sub-object and sets its flag. */
S* cTreeNode_cSkaSystemPtr_ctor(S* s, int* v) { Sub* sub = &s->sub; s->v = *v; s->z = 0; std_vector_cTreeNode_cSkaSystemPtrPtr_ctor(sub); sub->flag = 1; return s; }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003939D0(void) {}
#undef std_vector_cTreeNode_cSkaSystemPtrPtr_ctor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003939D0 */

/* merge_units: begin func_00393A20 */
#pragma push /* merge_units */
Rel* std_vector_cTreeNode_cSkaSystemPtrPtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00393A20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00393A20 */

/* merge_units: begin func_00393A40 */
#pragma push /* merge_units */
typedef struct RgSub { char p[0x8]; char a[0x10]; char b[0x18]; char c[0x18]; } RgSub;
typedef struct RgFlag { char p[0xC]; unsigned char on; } RgFlag;
typedef struct RgObj {
    int one; float f4; char p8[0xC]; int z14; char p18[4]; float s1c; int arg; void* model;
    unsigned char b28, b29; char p2a[0x42]; char col6c[0xC]; char col78[0x10]; char p88[0x18]; char rootA0[4];
} RgObj;
typedef struct RgT1 { char p[0x48]; } RgT1;
typedef struct RgT2 { char p[0x8]; } RgT2;
static const float dat_00493470[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
extern void cSkaCrossFadeDuration_ctor_void(void*);
extern void func_00393CE0(void*);
extern void std_list_deleter_voidPtr_ctor_void(void*);
extern void cArray_cSkaSliderValue_ctor(void*);
extern void std_vector_cSkaSwitchValue_ctor(void*);
extern void cSkaAnimAnchorList_ctor_void(void*);
extern void func_00393C60(void*, void*);
extern void* cSkaAnimationSet_AnimAnchorNameList(void*);
extern void cSkaAnimAnchorList_Reset(void*, void*);
extern void cSkaSliderValue_ctor_float(RgT1*, float);
extern void* cSkaAnimationSet_SliderParamCount(void*);
extern void cArray_cSkaSliderValue_ResizeActual(void*, void*, RgT1*);
extern void cSkaSliderValue_dtor(RgT1*, int);
extern void cSkaSwitchValue_ctor(RgT2*);
extern void* cSkaAnimationSet_SwitchParamCount(void*);
extern void cArray_cSkaSwitchValue_ResizeActual(void*, void*, RgT2*);
extern void cSkaSwitchValue_dtor(RgT2*, int);
RgObj* cSkaParams_ctor(RgObj* o, int arg, void* model)
{
    RgSub* sub;
    RgFlag* fl;
    o->one = 1;
    o->f4 = (*(float*)dat_00493470);
    o->z14 = 0;
    o->s1c = 1.0f;
    o->arg = arg;
    sub = (RgSub*)&o->model;
    o->model = model;
    o->b28 = 0;
    o->b29 = 0;
    cSkaCrossFadeDuration_ctor_void(sub->a);
    func_00393CE0(sub->b);
    func_00393CE0(sub->c);
    std_list_deleter_voidPtr_ctor_void(o->col6c);
    cArray_cSkaSliderValue_ctor(o->col78);
    fl = (RgFlag*)o->p88;
    std_vector_cSkaSwitchValue_ctor(fl);
    fl->on = 1;
    cSkaAnimAnchorList_ctor_void(o->rootA0);
    if (model) {
        func_00393C60(&o->model, model);
        cSkaAnimAnchorList_Reset(o->rootA0, cSkaAnimationSet_AnimAnchorNameList(model));
        {
            RgT1 t1;
            cSkaSliderValue_ctor_float(&t1, 0.0f);
            cArray_cSkaSliderValue_ResizeActual(o->col78, cSkaAnimationSet_SliderParamCount(model), &t1);
            cSkaSliderValue_dtor(&t1, -1);
        }
        {
            RgT2 t2;
            cSkaSwitchValue_ctor(&t2);
            cArray_cSkaSwitchValue_ResizeActual(o->p88, cSkaAnimationSet_SwitchParamCount(model), &t2);
            cSkaSwitchValue_dtor(&t2, -1);
        }
    }
    return o;
}
static inline void merge_flush_func_00393A40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00393A40 */
