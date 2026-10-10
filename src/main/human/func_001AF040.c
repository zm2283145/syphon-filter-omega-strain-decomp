/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

struct AnimSlot {
    virtual void v00(); virtual void v01(); virtual void v02();
    virtual float Evaluate(); /* +0x14 */
    float start;   /* +0x04 */
    float current; /* +0x08 */
    float value;   /* +0x0C */
    float target;  /* +0x10 */
};

/* Resets the slot start/current/target to v and re-evaluates its value; returns the slot. */
extern "C" AnimSlot* AnimChannels_ClearCount(AnimSlot* self, float v)
{
    self->target = v;
    self->current = v;
    self->start = v;
    self->value = self->Evaluate();
    return self;
}
