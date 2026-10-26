/*
 * main/human: range (2 files, 0018D0F0-0018D140)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "human_types.h"

/* merge_units: begin func_0018D0F0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

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

typedef struct AnimChannel_0018D0F0 { char pad[0x80]; AnimSlot* slots; } AnimChannel_0018D0F0;

/* Sets slot i directly to v (start/current/target) and re-evaluates its value. */
extern "C" void AnimChannel_SetDirect(AnimChannel_0018D0F0* self, int i, float v)
{
    AnimSlot* slot = &self->slots[i];
    slot->target = v;
    slot->current = v;
    slot->start = v;
    slot->value = slot->Evaluate();
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0018D0F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0018D0F0 */

/* merge_units: begin func_0018D140 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern void cHumanIkRoutine_StopUpperBodyAnimation(void*);

/* Release the secondary component if flagged (bit 8 of flags324C), then clear the flag. */
void Actor_ReleaseSecondary(Actor* actor) {
    void* secondary = actor->secondary;

    if (secondary != 0 && ((actor->flags324C >> 8) & 1) != 0) {
        cHumanIkRoutine_StopUpperBodyAnimation(secondary);
        actor->flags324C &= ~0x100;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0018D140(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0018D140 */
