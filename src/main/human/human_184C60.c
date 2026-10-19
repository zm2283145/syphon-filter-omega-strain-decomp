/*
 * main/human: range (4 files, 00184C60-00184CC0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "human_types.h"

/* merge_units: begin func_00184C60 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void Npc_v1B(Actor* actor, int value) {
    ActorLink3584* link = actor->unk3584;

    if (link != 0) {
        link->unk32 = value;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00184C60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00184C60 */

/* merge_units: begin func_00184C80 */
#pragma push /* merge_units */
typedef struct { char pad[0x32]; unsigned char b32; } Sub32;
typedef struct { char pad[0x3584]; Sub32* sub; } Obj3584;

/* Returns sub->b32, or 0 if there is no sub object. */
unsigned char Npc_v1C(Obj3584* self)
{
    if (self->sub)
        return self->sub->b32;
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00184C80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00184C80 */

/* merge_units: begin func_00184CA0 */
#pragma push /* merge_units */
typedef struct Sub33 {
    char pad[0x33];
    unsigned char value;
} Sub33;

typedef struct Holder3584 {
    char pad[0x3584];
    Sub33* sub;
} Holder3584;

/* Returns sub->value (byte at +0x33) or 0 when the sub-object at +0x3584 is absent. */
int Npc_v1A(Holder3584* self) {
    Sub33* sub = self->sub;
    if (sub) {
        return sub->value;
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00184CA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00184CA0 */

/* merge_units: begin func_00184CC0 */
#pragma push /* merge_units */
int Npc_v04(void) {
    return 1;
}

unsigned char Actor_IsReplica(Actor* actor) {
    return actor->unk3598;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00184CC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00184CC0 */
