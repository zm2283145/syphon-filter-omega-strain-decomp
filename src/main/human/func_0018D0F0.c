/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

/* Virtual-call view of AnimSlot: only the slots used here are named (vtable offset in comments). */
struct AnimSlot {
    virtual void v00(); virtual void v01(); virtual void v02();
    virtual float Evaluate(); /* +0x14 */
    float start;   /* +0x04 */
    float current; /* +0x08 */
    float value;   /* +0x0C */
    float target;  /* +0x10 */
    char pad14[0x3C - 0x14];
}; /* size 0x3C */

typedef struct AnimChannel { char pad[0x80]; AnimSlot* slots; } AnimChannel;

/* Sets slot i directly to v (start/current/target) and re-evaluates its value. */
extern "C" void AnimChannel_SetDirect(AnimChannel* self, int i, float v)
{
    AnimSlot* slot = &self->slots[i];
    slot->target = v;
    slot->current = v;
    slot->start = v;
    slot->value = slot->Evaluate();
}
