/*
 * main/ai: range (2 files, 0016E0A0-0016E160)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0016E0A0 */
#pragma push /* merge_units */
typedef struct {
    char pad[0x18];
    int unk18;
    int unk1C;
    unsigned char lo : 4;
    unsigned char f4 : 1;
    unsigned char f5 : 1;
    unsigned char hi : 2;
    unsigned char f0 : 1;
    unsigned char rest : 7;
    char pad22[0xE];
    char coll[0xC];
    int owner;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
} Obj;
extern void ScalarCollection_Init(void* coll);
extern void NpcPerception_SetTarget(Obj* self, int a, int b);
extern void NpcPerception_Clear(Obj* self);

/* Constructor: initialises the collection, ids and flag bits, then resets state. */
Obj* NpcPerception_Construct(Obj* self, int owner)
{
    unsigned char off = 0;
    ScalarCollection_Init(self->coll);
    self->owner = owner;
    self->unk44 = -2;
    self->unk40 = 0;
    self->unk4C = -2;
    self->unk48 = 0;
    self->unk1C = -1;
    NpcPerception_SetTarget(self, 0, 0);
    self->f4 = off;
    self->f5 = off;
    self->f0 = off;
    self->unk18 = -1;
    NpcPerception_Clear(self);
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016E0A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016E0A0 */

/* merge_units: begin func_0016E160 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Copies the second word of a pair over the first.
 */


typedef struct WordPair {
    int first;
    int second;
} WordPair;

void NpcAi_ApplyModeRequest(WordPair* p) {
    p->first = p->second;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016E160(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016E160 */
