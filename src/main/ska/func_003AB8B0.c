#pragma bool off
#include "types.h"

typedef struct CurveE6 { char pad[0x3C]; } CurveE6;
typedef struct ChannelsE6 { CurveE6* data; int count; } ChannelsE6;

extern CurveE6** func_003AB960(ChannelsE6* self);
extern void ScalarCurve_Advance(CurveE6* c, float dt, float rate);

static inline int CurveE6_Ne(CurveE6* a, CurveE6* b) { return (a == b) ^ 1; }

/* Advances every scalar curve channel. */
void AnimChannels_Update(ChannelsE6* self, float dt, float rate)
{
    CurveE6* it = *func_003AB960(self);
    CurveE6* end = *func_003AB960(self) + self->count;
    for (; CurveE6_Ne(it, end); it++) {
        ScalarCurve_Advance(it, dt, rate);
    }
}