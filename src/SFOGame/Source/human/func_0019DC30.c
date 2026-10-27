#include "types.h"
typedef struct { char pad[0x810]; int flags; } Ctl;
typedef struct { char pad[0x10]; char anim[0x10]; } AnimBlk;
typedef struct {
    char pad0[0x2EC0];
    AnimBlk blk;            /* 0x2EC0 */
    char pad2EE0[0x31C0 - 0x2EE0];
    float lean;             /* 0x31C0 */
    char pad31C4[0xC];
    float speed;            /* 0x31D0 */
    char pad31D4[0x34];
    int flags3208;          /* 0x3208 */
    char pad320C[0x3C];
    int flags3248;          /* 0x3248 */
    char pad324C[0xC4];
    Ctl* ctl;               /* 0x3310 */
} Actor;
extern float D_0049CF58;
extern void cHuman_ClearMotionSettings(Actor* a, int b, int c, int d, int e);
extern void cSkaParams_SetSliderValue_UsingSplineForInterpolation(void* a, int idx, unsigned int n, float target, float dur, float damping);
/* Picks the lean-channel target (left/right/neutral) from the lean value and controller flags. */
void cHuman_Hang_NextFrame(Actor* self)
{
    AnimBlk* blk = &self->blk;
    float t;
    if (0.0f == self->speed) {
        self->flags3208 |= 1;
    }
    cHuman_ClearMotionSettings(self, 0, 0, 0, 1);
    if (self->lean < -0.75f && self->ctl && ((self->ctl->flags >> 10) & 1)) {
        t = 0.0f;
        self->flags3248 |= 0x100;
    } else if (!(self->lean <= 0.75f) && self->ctl && ((self->ctl->flags >> 11) & 1)) {
        t = 1.0f;
        self->flags3248 |= 0x200;
    } else {
        t = 0.5f;
        self->flags3248 &= ~0x100;
        self->flags3248 &= ~0x200;
    }
    cSkaParams_SetSliderValue_UsingSplineForInterpolation(blk->anim, 6, 0, t, D_0049CF58, 3.0f);
}
