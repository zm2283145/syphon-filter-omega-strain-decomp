/*
 * SFOGame/Source/hud: 9 files, 00244070-002440D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00244070 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hud.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* cConstLListIterator_tCalloutPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
static inline void merge_flush_func_00244070(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00244070 */

/* merge_units: begin func_00244080 */
#pragma push /* merge_units */
#include "iter_return_copy.h"

/* Return the end iterator. */
DEFINE_ITER_END(std_list_tCalloutPtr_end_void_2)
static inline void merge_flush_func_00244080(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00244080 */

/* merge_units: begin func_002440B0 */
#pragma push /* merge_units */
#include "hud_types.h"

/* Stores value into *dst; volatile mirrors the original stack temporary. */
int* std_list_tCalloutPtr_generic_iterator_1_ctor(int* dst, int value) {
    volatile int tmp = value;

    *dst = tmp;
    return dst;
}
static inline void merge_flush_func_002440B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002440B0 */

/* merge_units: begin func_002440D0 */
#pragma push /* merge_units */
typedef struct { float v[4]; } Vec4_002440D0;
typedef struct { char pad[0x10]; float m[4][4]; } Obj;
extern int D_004F7DA0[];
extern Vec4_002440D0 cInterfaceModel_GetBounds(int a, float b);

void Hud_InitCalloutRects(Obj* p)
{
    int i;
    Vec4_002440D0 v;
    for (i = 0; i < 4; i++) {
        v = cInterfaceModel_GetBounds(D_004F7DA0[i], 10.0f);
        p->m[i][0] = v.v[0];
        p->m[i][1] = v.v[1];
        p->m[i][2] = v.v[2];
        p->m[i][3] = v.v[3];
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002440D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002440D0 */

/* merge_units: begin func_00244180 */
#pragma push /* merge_units */
extern void cAnimator_AnimateTo(void* p, float x);
typedef struct { char pad[0x70]; void* meter; } D6Hud;
void cHud_SetArmor(D6Hud* hud, int cur, int max)
{
    if (hud->meter) {
        cAnimator_AnimateTo(hud->meter, 45.0f * (((float)max - (float)cur) / (float)max));
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00244180(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00244180 */

/* merge_units: begin func_002441E0 */
#pragma push /* merge_units */
typedef struct { char pad[0x6C]; void* widget; } H_2441E0;
extern void cAnimator_AnimateTo(void* w, float v);

void cHud_SetHealth(H_2441E0* h, int cur, int max) {
    if (h->widget != 0) {
        cAnimator_AnimateTo(h->widget, 45.0f * (((float)max - (float)cur) / (float)max));
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002441E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002441E0 */

/* merge_units: begin func_00244240 */
#pragma push /* merge_units */
void cHud_ClearTarget(int arg0); /* gsynth: defined below */
extern void cHud_ClearTarget(int);

extern void HudLockTracker_Changed(int);

void cHud_ClearTargetNow(int a0) {
    int s0;
    int cond;

    s0 = a0;
    a0 = *(int*)((char*)a0 + 100);
    cond = a0 == 0;
    if (cond) goto L00244268;
    HudLockTracker_Changed(a0);
L00244268:;
    a0 = s0;
    cHud_ClearTarget(a0);
    goto ret;
ret:;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00244240(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00244240 */

/* merge_units: begin func_00244280 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int cInterfaceElement_Destroy(int);                               
int cIE_GOBJ_AnimateOff(int);                               

#pragma opt_common_subs off
void cHud_ClearTarget(int arg0) {
    int temp_a0;
    int temp_a0_2;

    temp_a0 = F_(arg0, 0x68, int);
    if (temp_a0 != 0) {
        if (F_(arg0, 0x64, int) == 0) {
            cInterfaceElement_Destroy(temp_a0);
        }
        F_(arg0, 0x68, int) = 0;
    }
    temp_a0_2 = F_(arg0, 0x64, int);
    if (temp_a0_2 != 0) {
        cIE_GOBJ_AnimateOff(temp_a0_2);
        F_(arg0, 0x64, int) = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00244280(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00244280 */

/* merge_units: begin func_002442E0 */
#pragma push /* merge_units */
typedef struct { char pad[0x68]; void* p68; } Obj_42E0;
typedef struct { float v[4]; } Buf_42E0;
extern void nHud_ComputeColor(Buf_42E0* out, float t);
extern void cInterfaceElement_SetFilterColor(void* p, Buf_42E0* b);
extern void cAnimator_SetFrame(void* p, float f);

void cHud_SetToHit(Obj_42E0* o, float t) {
    Buf_42E0 b;
    if (o->p68) {
        nHud_ComputeColor(&b, 1.0f - t);
        cInterfaceElement_SetFilterColor(o->p68, &b);
        if (t < 0.95f) cAnimator_SetFrame(o->p68, 15.0f * t);
        else cAnimator_SetFrame(o->p68, 15.0f);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002442E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002442E0 */
