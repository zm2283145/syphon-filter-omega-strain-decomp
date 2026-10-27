/*
 * main/human: range (2 files, 0019F450-0019F6C0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_0019F450 */
#pragma push /* merge_units */
#pragma cplusplus on
static inline bool Not(unsigned char v) { return !(v != 0); }
struct Phys { char pad[0xDC]; unsigned char bDC; };
struct Actor {
    VPAD32(a) VPAD16(b) VPAD8(c) VPAD4(d) VPAD2(e)
    virtual void Damage(Actor* src, int a, int b, int c, int d, int e, float amt);
    VPAD1(f)
    virtual unsigned char GetState();
    char pad4[0x10];
    unsigned char active;
    char pad15[0x40 - 0x15];
    float x40;
    char pad44[0x30A4 - 0x44];
    float lastY;
    float fallDist;
    char pad30AC[0x3210 - 0x30AC];
    int flags;
    char pad3214[0x3290 - 0x3214];
    void* root;
    char pad3294[0x3310 - 0x3294];
    Phys* phys;
    char pad3314[0x3398 - 0x3314];
    int x3398;
    char pad339C[0x33A5 - 0x339C];
    unsigned char b33A5;
    bool InWater() {
        bool r = false;
        if (phys && phys->bDC) r = true;
        return r;
    }
    bool Bit21() { return Not(Not((flags >> 21) & 1)); }
    bool IsDown() { unsigned char s = GetState(); return s == 2 || s == 3; }
};
extern "C" {
extern void* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void*);
extern float* cQuatVec_Translation(void*);
extern float D_0049CEF0;
extern float D_0049CEF8;
extern float D_0049CF00;
extern float D_0049CF08;
extern float D_0049CF18;
}
extern "C" void cHuman_DetectForAndHandleHarmfulFalls(Actor* a, int resetY)
{
    if (a->active) {
        float* p = cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(a->root));
        float d = a->lastY - p[2];
        if (a->InWater()) {
            if (d > D_0049CF18) {
                if (!a->IsDown())
                    a->Damage(a, 1, 0xF, 0, 0, 0, (float)(int)a->x40);
            }
        } else {
            bool c = a->Bit21() || a->Bit21() || a->b33A5;
            float lo = c ? D_0049CF00 : D_0049CEF0;
            float hi = c ? D_0049CF08 : D_0049CEF8;
            if (d > 0.0f) {
                a->fallDist = d;
                if (d > lo) {
                    float amt;
                    if (d > hi)
                        amt = (float)(int)a->x40;
                    else
                        {
                            float t = (d - lo) * (1.0f / (hi - lo));
                            amt = t * (float)a->x3398;
                        }
                    a->Damage(a, 1, 0xC, 0, 0, 0, amt);
                }
            }
        }
    }
    if (a->InWater()) {
        if (resetY)
            a->lastY = cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(a->root))[2];
    } else {
        a->lastY = -3.4028235e38f;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0019F450(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0019F450 */

/* merge_units: begin func_0019F6C0 */
#pragma push /* merge_units */
#pragma opt_common_subs off
typedef struct { int top; int words[1]; } C3PSet19F;
typedef struct {
    char pad0[0x320C];
    C3PSet19F set;
} C3Ag19F;
extern void Actor_ShiftPriorityHistory(void* a, void* b);
extern void func_0019F7E0(void* a);
extern void cBitArray_34_opAssign(void* a, void* b);
extern void Actor_ReactToActionChanges(C3Ag19F* p);
extern void Actor_ClearAction(C3Ag19F* p, int idx);
extern void cHuman_JumpFallLand_NextFrame(C3Ag19F* p, float dt);
static const unsigned int dat_0049D5E0[2] = { 0x15111005, 0x1F };
static inline int C3PTest19F(C3PSet19F* s, int n)
{
    return (*(int*)((char*)s + (n / 32) * 4 + 4) >> (n & 31)) & 1;
}
void cHuman_ActionModes_NextFrame(C3Ag19F* p, float dt)
{
    int cur;
    int i;
    Actor_ShiftPriorityHistory((char*)p + 0x3234, (char*)p + 0x3220);
    Actor_ShiftPriorityHistory((char*)p + 0x3220, (char*)p + 0x320C);
    func_0019F7E0((char*)p + 0x320C);
    cBitArray_34_opAssign((char*)p + 0x3258, (char*)p + 0x3250);
    cBitArray_34_opAssign((char*)p + 0x3250, (char*)p + 0x3248);
    Actor_ReactToActionChanges(p);
    cur = p->set.top;
    for (i = 0; i < 5; i++) {
        int idx = ((signed char*)dat_0049D5E0)[i];
        if (idx != cur && C3PTest19F(&p->set, idx)) {
            Actor_ClearAction(p, idx);
        }
    }
    cHuman_JumpFallLand_NextFrame(p, dt);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0019F6C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0019F6C0 */
