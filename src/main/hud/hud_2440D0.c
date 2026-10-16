/*
 * main/hud: range (6 files, 002440D0-002442E0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_002440D0 */
#pragma push /* merge_units */
typedef struct { float v[4]; } Vec4_002440D0;
typedef struct { char pad[0x10]; float m[4][4]; } Obj;
extern int D_004F7DA0[];
extern Vec4_002440D0 IeNode_GetRect(int a, float b);

void Hud_InitCalloutRects(Obj* p)
{
    int i;
    Vec4_002440D0 v;
    for (i = 0; i < 4; i++) {
        v = IeNode_GetRect(D_004F7DA0[i], 10.0f);
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
extern void IeElement_Fade(void* p, float x);
typedef struct { char pad[0x70]; void* meter; } D6Hud;
void Hud_SetArmorMeter(D6Hud* hud, int cur, int max)
{
    if (hud->meter) {
        IeElement_Fade(hud->meter, 45.0f * (((float)max - (float)cur) / (float)max));
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00244180(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00244180 */

/* merge_units: begin func_002441E0 */
#pragma push /* merge_units */
typedef struct { char pad[0x6C]; void* widget; } H_2441E0;
#if 0 /* merge_units */
extern void IeElement_Fade(void* w, float v);
#endif /* merge_units */
#define IeElement_Fade(a0, a1) (IeElement_Fade((a0), (a1))) /* merge_units */

void Hud_SetHealthMeter(H_2441E0* h, int cur, int max) {
    if (h->widget != 0) {
        IeElement_Fade(h->widget, 45.0f * (((float)max - (float)cur) / (float)max));
    }
}
#undef IeElement_Fade /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002441E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002441E0 */

/* merge_units: begin func_00244240 */
#pragma push /* merge_units */
void Hud_ClearTargetLock(int arg0); /* gsynth: defined below */
#if 0 /* merge_units */
extern void Hud_ClearTargetLock(int);
#endif /* merge_units */
#define Hud_ClearTargetLock(a0) (Hud_ClearTargetLock((a0))) /* merge_units */

extern void func_003E9730(int);

void Hud_OnTargetChanged(int a0) {
    int s0;
    int cond;

    s0 = a0;
    a0 = *(int*)((char*)a0 + 100);
    cond = a0 == 0;
    if (cond) goto L00244268;
    func_003E9730(a0);
L00244268:;
    a0 = s0;
    Hud_ClearTargetLock(a0);
    goto ret;
ret:;
}
#undef Hud_ClearTargetLock /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00244240(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00244240 */

/* merge_units: begin func_00244280 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int IeElement_Release(int);                               
int HudTracker_Kill(int);                               

#pragma opt_common_subs off
void Hud_ClearTargetLock(int arg0) {
    int temp_a0;
    int temp_a0_2;

    temp_a0 = F_(arg0, 0x68, int);
    if (temp_a0 != 0) {
        if (F_(arg0, 0x64, int) == 0) {
            IeElement_Release(temp_a0);
        }
        F_(arg0, 0x68, int) = 0;
    }
    temp_a0_2 = F_(arg0, 0x64, int);
    if (temp_a0_2 != 0) {
        HudTracker_Kill(temp_a0_2);
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
extern void Hud_GetLockColour(Buf_42E0* out, float t);
extern void IeElement_SetColour(void* p, Buf_42E0* b);
extern void IeElement_EvaluateAt(void* p, float f);

void func_002442E0(Obj_42E0* o, float t) {
    Buf_42E0 b;
    if (o->p68) {
        Hud_GetLockColour(&b, 1.0f - t);
        IeElement_SetColour(o->p68, &b);
        if (t < 0.95f) IeElement_EvaluateAt(o->p68, 15.0f * t);
        else IeElement_EvaluateAt(o->p68, 15.0f);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002442E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002442E0 */
