/*
 * main/npc: range (3 files, 0014D2E0-0014D310)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "npc_types.h"
#include "types.h"

/* merge_units: begin func_0014D2E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */


/* vtable slot 0x2A: returns the AI controller. */
NpcAi* cNPC_v2A(cNPC* self) {
    return self->ai;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014D2E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014D2E0 */

/* merge_units: begin func_0014D2F0 */
#pragma push /* merge_units */
typedef struct {
    char pad[0x20];
    unsigned char lo : 4;
    unsigned char flag : 1;
} NPCInfo;
typedef struct { char pad[0x1AC]; NPCInfo* info; } NPC;

/* Returns bit 4 of the NPC info flags byte. */
int cNPC_v29(NPC* self)
{
    return self->info->flag;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014D2F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014D2F0 */

/* merge_units: begin func_0014D310 */
#pragma push /* merge_units */
typedef struct { char pad[0x20]; unsigned char b0 : 1; unsigned char b1 : 1; unsigned char b2 : 1; } NpcFlags;
typedef struct { char pad[0x1AC]; NpcFlags* flags; } cNPC_0014D310;

/* cNPC virtual 0x2B: returns 1 if flag bits 0 and 2 are both set. */
int cNPC_v2B(cNPC_0014D310* self)
{
    return self->flags->b0 && self->flags->b2;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014D310(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014D310 */
