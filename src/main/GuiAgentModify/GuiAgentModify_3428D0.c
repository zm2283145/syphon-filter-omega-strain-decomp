/*
 * main/GuiAgentModify: range (3 files, 003428D0-00342DC0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003428D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)

/* Camera preset blend: eases the current camera preset toward the selected table entry. */

extern "C" {
float Math_StepEighth(float* p, float a, float b);
float Math_StepAngleEighth(float target, float cur, float* maxStep);
}
struct Fl { float v; Fl& operator=(const Fl& o) { v = o.v; return *this; } operator float() const { return v; } Fl& operator=(float x) { v = x; return *this; } };
struct CamE {
    char name[16];
    int id;
    Fl f0, f1, f2, f3, f4, f5, f6;
};
struct CamMgr { char pad[0x11C10]; CamE e[1]; };
extern "C" CamMgr g_AgentPartCache;
struct CamOwner { char pad[0x2E10]; signed char sel[8]; };
struct CamT {
    char pad0[0x8C];
    CamOwner* owner;
    char pad90[0xA0 - 0x90];
    CamE cur;
    char padD0[0xE0 - 0xD0];
    int c0;
    char padE4[0xF0 - 0xE4];
    int d0;
    char padF4[0x10D - 0xF4];
    signed char ed;
};
static inline void GetE(CamT* t, CamE& o) {
    if (t->d0 == 0) o = g_AgentPartCache.e[t->owner->sel[t->ed]];
    else o = g_AgentPartCache.e[0];
}

extern "C" void GuiAgentModify_CameraApproach(CamT* t)
{
    if (t->c0) {
        float acc = 0.0f;
        CamE e; GetE(t, e);
        t->cur.f0 = Math_StepEighth(&acc, e.f0, t->cur.f0);
        t->cur.f1 = Math_StepEighth(&acc, e.f1, t->cur.f1);
        t->cur.f2 = Math_StepEighth(&acc, e.f2, t->cur.f2);
        t->cur.f3 = Math_StepEighth(&acc, e.f3, t->cur.f3);
        t->cur.f4 = Math_StepAngleEighth(e.f4, t->cur.f4, &acc);
        t->cur.f5 = Math_StepAngleEighth(e.f5, t->cur.f5, &acc);
        t->cur.f6 = Math_StepAngleEighth(e.f6, t->cur.f6, &acc);
        t->c0++;
        if (acc < 0.0001f) {
            t->c0 = 0;
            GetE(t, t->cur);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003428D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003428D0 */

/* merge_units: begin func_00342CD0 */
#pragma push /* merge_units */
extern int g_Pad0HeldMask;

typedef struct {
    char pad0[0xCC];
    float angle;
    char padD0[0xE0 - 0xD0];
    int locked;
} Obj;

void GuiWidget_Update(Obj *o, float dt);

#pragma push
#pragma opt_propagation off
void GuiAgentModify_Update(Obj *o, float dt)
{
    int flags;
    float step;
    GuiWidget_Update(o, dt);
    flags = g_Pad0HeldMask;
    step = 3.1415927f * (dt / 30.0f);
    if (o->locked == 0) {
        if (flags & 1) {
            o->angle += step;
            if (o->angle > 3.1415927f) {
                o->angle -= 6.2831855f;
            }
        }
        if (flags & 2) {
            o->angle -= step;
            if (o->angle < -3.1415927f) {
                o->angle += 6.2831855f;
            }
        }
    }
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00342CD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00342CD0 */

/* merge_units: begin func_00342DC0 */
#pragma push /* merge_units */
#pragma push
#pragma opt_propagation off
void GuiAgentModify_UserInterfaceRotate(Obj *o, float dt)
{
    int flags = g_Pad0HeldMask;
    float step = 3.1415927f * (dt / 30.0f);
    if (o->locked == 0) {
        if (flags & 1) {
            o->angle += step;
            if (o->angle > 3.1415927f) {
                o->angle -= 6.2831855f;
            }
        }
        if (flags & 2) {
            o->angle -= step;
            if (o->angle < -3.1415927f) {
                o->angle += 6.2831855f;
            }
        }
    }
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00342DC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00342DC0 */
