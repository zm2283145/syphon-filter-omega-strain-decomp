/*
 * main/GuiAgentInfo: range (2 files, 00363680-003636C0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "GuiAgentInfo_types.h"

/* merge_units: begin func_00363680 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

/* Virtual-call view of Curve: only the slots used here are named (vtable offset in comments). */
struct Curve {
    virtual void v00(); virtual void v01(); virtual void v02();
    virtual float Evaluate(); /* +0x14 */
    float start;   /* +0x04 */
    float current; /* +0x08 */
    float value;   /* +0x0C */
    float target;  /* +0x10 */
};

/* Sets start/current/target to v, re-evaluates the value (virtual +0x14) and returns self. */
extern "C" Curve* AnimChannels_ClearCount_363680(Curve* self, float v)
{
    self->target = v;
    self->current = v;
    self->start = v;
    self->value = self->Evaluate();
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00363680(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00363680 */

/* merge_units: begin func_003636C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiAgentInfo.cc. Functions are named by address
 * until real names are known.
 */


extern int Curve_Bind(void* binding, CurveSegment* segment);
extern int Curve_InitConstant(CurveSegment* segment, int from, int to, float t);
#pragma explicit_zero_data on
static float D_00492EE8 = 0.0f;
#pragma explicit_zero_data reset
static const float dat_00492EF0[24] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 2.8026e-45f, 0.0f, 2.8026e-45f, 0.0f, 2.8026e-45f, 0.0f, 2.8026e-45f, 0.0f, 2.8026e-45f, 0.0f, 0.0f, 0.0f };
extern char D_004DA380[];   /* CurveChannel base vtable */
extern char D_004DA840[];   /* AnimChannel vtable */

/* AnimChannel constructor (inline copy emitted in this unit). */
AnimChannel* AnimChannel_Ctor(AnimChannel* self) {
    self->base.vtable = D_004DA380;
    self->base.previous = D_00492EE8;
    self->base.current = D_00492EE8;
    self->base.target = (*(float*)dat_00492EF0);
    self->base.rate = D_00492EE8;
    self->base.damping = 0.0f;
    Curve_InitConstant(&self->base.segment, (int)&D_00492EE8, (int)&(*(float*)dat_00492EF0), 0.0f);
    Curve_Bind(self->base.binding, &self->base.segment);
    self->base.vtable = D_004DA840;
    self->wrap = 0;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003636C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003636C0 */
