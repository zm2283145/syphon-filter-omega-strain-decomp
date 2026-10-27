/*
 * SFOGame/Source/human: 1 file, 0019D950
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0019D950 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct Actor;
typedef struct { char pad[0x10]; char anim[0x10]; } AnimBlk;
typedef struct Lnk { char pad[0xC]; int id; } Lnk;
struct Actor {
    char pad0[0x2EC0];
    AnimBlk blk;            /* 0x2EC0 */
    char pad2EE0[0x31C4 - 0x2EE0];
    float f31C4;            /* 0x31C4 */
    char pad31C8[0x31D0 - 0x31C8];
    float speed;            /* 0x31D0 */
    float f31D4;            /* 0x31D4 */
    char pad31D8[0x3208 - 0x31D8];
    int flags3208;          /* 0x3208 */
    char pad320C[0x324C - 0x320C];
    int f324C;              /* 0x324C */
    char pad3250[0x3478 - 0x3250];
    Actor* link;            /* 0x3478 */
    int linkId;             /* 0x347C */
};
extern "C" {
extern float D_0049CFB8;
/* float target declared before n: int/float args use separate registers, this order only changes arg scheduling */
void cSkaParams_SetSliderValue_UsingSplineForInterpolation(void* a, int idx, float target, unsigned int n, float dur, float damping);
void cSkaParams_SetSwitchNextGoalState(void* a, int idx, int n);
void cHuman_ClearMotionSettings(Actor* self, int b, int c, int d, int e);
}
static inline bool LnkIsA(Actor* l, Actor* a) { return ((Lnk*)l)->id == a->linkId; }
static inline bool LinkOk(Actor* a) { return !a->link || LnkIsA(a->link, a); }
static inline Actor* Link(Actor* a) { return LinkOk(a) ? a->link : 0; }
static inline float Clamp(float x, float z, float o) { float lo = z; float hi = o; float r; asm { max.s r, x, lo; min.s r, r, hi } return r; }
static inline float MulF(float a, float b) { return a * b; }
static inline void SetFlag(Actor* a, unsigned char on) {
    if (on) a->flags3208 |= 1;
    else a->flags3208 &= ~1;
}
extern "C" void cHuman_CarryBody_NextFrame(Actor* self)
{
    if (!((self->f324C >> 3) & 1)) return;
    bool hold = 0;
    if (Link(self)) {
        int mode = 0;
        float t = 0.5f;
        if (!(self->speed <= 0.0f)) {
            if (!(self->f31C4 <= 0.0f)) {
                mode = 1;
            } else if (self->f31C4 < 0.0f) {
                mode = 2;
            } else {
                hold = 1;
            }
        } else {
            if (!((self->f324C >> 1) & 1) && !(0.0f == self->f31D4)) {
                t = Clamp(0.5f - self->f31D4 * MulF(1.0f, 0.22207667f), 0.0f, 1.0f);
            }
            hold = 1;
        }
        {
            AnimBlk* blk = &self->blk;
            cSkaParams_SetSwitchNextGoalState(blk->anim, 4, mode);
            cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 14, t, 0, D_0049CFB8, 6.5f);
        }
        {
            AnimBlk* blk = &Link(self)->blk;
            cSkaParams_SetSwitchNextGoalState(blk->anim, 4, mode);
            cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 14, t, 0, D_0049CFB8, 6.5f);
        }
        unsigned char h = hold;
        SetFlag(self, h);
        cHuman_ClearMotionSettings(self, 1, 0, 0, 0);
        SetFlag(Link(self), h);
        cHuman_ClearMotionSettings(Link(self), 1, 0, 0, 0);
    } else {
        self->flags3208 &= ~1;
        cHuman_ClearMotionSettings(self, 1, 0, 0, 0);
    }
}
static inline void merge_flush_func_0019D950(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0019D950 */
