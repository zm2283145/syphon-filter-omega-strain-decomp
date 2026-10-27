#pragma bool off
#include "types.h"

typedef struct CurveE6 { char pad[0x3C]; } CurveE6;
typedef struct ChannelsE6 { CurveE6* data; int count; } ChannelsE6;

extern CurveE6** std_vector_deleter_cSkaSliderValue_data(ChannelsE6* self);
extern void cSplinedMotion_float_NextFrame(CurveE6* c, float dt, float rate);

static inline int CurveE6_Ne(CurveE6* a, CurveE6* b) { return (a == b) ^ 1; }

/* Advances every scalar curve channel. */
void cSkaSliderValueList_NextFrame(ChannelsE6* self, float dt, float rate)
{
    CurveE6* it = *std_vector_deleter_cSkaSliderValue_data(self);
    CurveE6* end = *std_vector_deleter_cSkaSliderValue_data(self) + self->count;
    for (; CurveE6_Ne(it, end); it++) {
        cSplinedMotion_float_NextFrame(it, dt, rate);
    }
}