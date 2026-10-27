/*
 * SFOGame/Source/human: 1 file, 0019DD80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0019DD80 */
#pragma push /* merge_units */
#pragma opt_pulloutconstants off
#pragma cplusplus on
#pragma inline_depth(10)
#include "types.h"
extern "C" {
typedef struct { char pad[0xDC]; unsigned char dc; } Ctl;
typedef union { int i[4]; __int128 q; } Q4;
typedef struct { char pad[0x10]; char anim[0x10]; } AnimBlk;
typedef struct {
    char pad0[0x2EC0];
    AnimBlk blk;            /* 0x2EC0 */
    char pad2EE0[0x31E0 - 0x2EE0];
    float rate;             /* 0x31E0 */
    char pad31E4[0x3204 - 0x31E4];
    int f3204;              /* 0x3204 */
    char pad3208[0x3210 - 0x3208];
    int f3210;              /* 0x3210 */
    char pad3214[0x3248 - 0x3214];
    int f3248;              /* 0x3248 */
    char pad324C[0x3310 - 0x324C];
    Ctl* ctl;               /* 0x3310 */
} Actor;
typedef struct {
    char pad0[0x3034];
    int f3034;
    char pad3038[8];
    Q4 v3040;
} ActorB;
extern float D_0049CF50;
extern float D_0049CF58;
extern float D_0049CF68;
extern float D_0049CF80;
extern float D_0049CFA0;
extern float D_0049CFB0;
extern float D_0049CFB8;
extern float D_0049CFC0;
extern float D_0049CFE0;
extern void cSkaParams_SetSliderValue_UsingSplineForInterpolation(void* a, int idx, unsigned int n, float target, float dur, float damping);
extern void cSkaParams_SetSliderValue_int_float_float_bool(void* a, int idx, unsigned int n, float target, float rate);
extern float AnimChannel_GetCurrentValue(void* a, int idx);
extern float cSkaSystem_GetSliderValue(void* a, int idx);
extern void cSkaParams_SetSwitchNextGoalState(void* a, int idx, int n);

}
typedef unsigned char u8;
static inline int HasCtl(Actor* a) { u8 r = 0; if (a->ctl && a->ctl->dc) r = 1; return r; }
static inline u8 Flag0(Actor* a) { return (((ActorB*)a)->f3034 & 1) != 0; }
static inline u8 NFlag0(Actor* a) { return !Flag0(a); }
static inline u8 C1(Actor* a) { u8 r = 0; if (HasCtl(a)) { if (NFlag0(a)) r = 1; } return r; }
static inline u8 Bit4(Actor* a) { return ((a->f3210 >> 4) & 1) != 0; }
static inline u8 Bit5(Actor* a) { return ((a->f3210 >> 5) & 1) != 0; }
static inline u8 Bit10(Actor* a) { return ((a->f3210 >> 10) & 1) != 0; }
static inline u8 Bit11(Actor* a) { return ((a->f3210 >> 11) & 1) != 0; }
static inline u8 Bit15(Actor* a) { return ((a->f3248 >> 15) & 1) != 0; }
static inline u8 C2(Actor* a) { u8 r = 1; if (!C1(a)) { if (!Bit4(a)) r = 0; } return r; }
static inline u8 C3(Actor* a) { u8 r = 1; if (!C2(a)) { if (!Bit5(a)) r = 0; } return r; }
static inline u8 C4(Actor* a) { u8 r = 1; if (!C3(a)) { if (!Bit10(a)) r = 0; } return r; }
static inline u8 C5(Actor* a) { u8 r = 1; if (!C4(a)) { if (!Bit11(a)) r = 0; } return r; }
static inline int C6(Actor* a) { u8 r = 1; if (!C5(a)) { if (!Bit15(a)) r = 0; } return r; }
/* 16-byte lq/sq copy idiom (GCC-style asm keeps retail's unfolded address setup) */
static inline void Q4_Zero(Q4* p) { Q4 z; z.i[0] = 0; z.i[1] = 0; z.i[2] = 0; z.i[3] = 0; __int128 q; __asm__ volatile("lq %0,0(%2); sq %0,0(%1)" : "=&r"(q) : "r"(p), "r"(&z) : "memory"); }

extern "C" void cHuman_ClearMotionSettings(Actor* self, int b, int c, int d, int e)
{
    unsigned char busy = C6(self);
    AnimBlk* blk = &self->blk;
    if (!busy || ((self->f3248 >> 15) & 1)) {
        cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 4, 0, 0.0f, D_0049CFB0, 3.0f);
    }
    if ((self->f3204 >> 3) & 1) {
        cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 10, 0, 1.0f, D_0049CFA0, 5.5f);
    } else {
        cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 10, 0, 0.0f, D_0049CFA0, 5.5f);
    }
    if ((self->f3204 >> 4) & 1) {
        cSkaParams_SetSliderValue_int_float_float_bool(blk->anim, 11, 0, 1.0f, self->rate);
    } else {
        cSkaParams_SetSliderValue_int_float_float_bool(blk->anim, 11, 0, 0.0f, self->rate);
    }
    if (!busy) {
        cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 3, 0, 0.0f, D_0049CF80, 3.0f);
    } else {
        cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 3, 0, AnimChannel_GetCurrentValue(blk, 3), -1.0f, 0.0f);
    }
    cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 2, 0, 0.0f, D_0049CF50, 3.0f);
    if (!busy) {
        cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 5, 0, 0.5f, D_0049CF68, 3.0f);
        if (!e) {
            cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 6, 0, 0.5f, D_0049CF58, 3.0f);
        }
        cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 7, 0, 0.0f, D_0049CFC0, 3.0f);
        cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 8, 0, 0.0f, D_0049CFC0, 3.0f);
        cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 9, 0, cSkaSystem_GetSliderValue(blk, 6), D_0049CF58, 3.0f);
    } else {
        cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 5, 0, AnimChannel_GetCurrentValue(blk, 5), -1.0f, 0.0f);
        cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 6, 0, AnimChannel_GetCurrentValue(blk, 6), -1.0f, 0.0f);
        cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 7, 0, AnimChannel_GetCurrentValue(blk, 7), -1.0f, 0.0f);
        cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 8, 0, AnimChannel_GetCurrentValue(blk, 8), -1.0f, 0.0f);
        cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 9, 0, AnimChannel_GetCurrentValue(blk, 9), -1.0f, 0.0f);
    }
    cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 0, 0, 0.5f, D_0049CFE0, 3.0f);
    cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 1, 0, 0.5f, D_0049CFE0, 3.0f);
    if (!b) {
        cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 14, 0, 0.5f, D_0049CFB8, 6.5f);
    }
    if (!d) {
        cSkaParams_SetSliderValue_int_float_float_bool(blk->anim, 17, 0, 0.5f, self->rate);
    }
    {
        Q4_Zero(&((ActorB*)self)->v3040);
    }
    if (!c) {
        cSkaParams_SetSwitchNextGoalState(blk->anim, 3, 0);
    }
}
static inline void merge_flush_func_0019DD80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0019DD80 */
