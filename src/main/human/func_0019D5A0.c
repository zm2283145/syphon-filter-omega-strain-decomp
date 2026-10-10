#include "types.h"
typedef struct {
    char pad0[0x10];
    float target;
    float damping;
    char pad18[0x20];
    unsigned char active;
    char pad39[3];
} B7_Chan;
typedef struct { char pad[0x80]; B7_Chan* chans; } B7_Anim;
extern void AnimChannel_SetDuration(B7_Chan* ch, float d);
void AnimChannel_SetTarget(B7_Anim* a, int idx, unsigned int n, float target, float dur, float damping)
{
    B7_Chan* ch = &a->chans[idx];
    ch->target = target;
    ch->damping = damping;
    AnimChannel_SetDuration(ch, dur);
    { float fn = n; float z = 0.0f; ch->active = fn != z; }
}