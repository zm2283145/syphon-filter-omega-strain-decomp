/*
 * main/npc: range (2 files, 0014BCE0-0014BCF0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "npc_types.h"
#include "types.h"

/* merge_units: begin func_0014BCE0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */


/* vtable slot 0x59: SetFiringThreshold; returns the previous value. */
float cNPC_SetFiringThreshold(cNPC* self, float threshold) {
    float old;

    old = self->firingThreshold;
    self->firingThreshold = threshold;
    return old;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014BCE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014BCE0 */

/* merge_units: begin func_0014BCF0 */
#pragma push /* merge_units */
typedef struct Target78 {
    char pad00[0x78];
    int id; /* 0x78 */
} Target78;

typedef struct cNPC_35 {
    char pad000[0x44];
    char state44[0xFB];      /* 0x044 */
    unsigned char kind;      /* 0x13F */
    char pad140[0x70];
    void* brain;             /* 0x1B0 */
} cNPC_35;

extern void cStateMachine_ChangeState(void* state, int kind, int value);
extern void cPathNavigator_Request_int(void* brain, int id);

/* cNPC virtual 0x35: records an event kind (< 7) and forwards the target. */
void cNPC_SetMode(cNPC_35* self, int kind, Target78* target) {
    if ((unsigned char)kind < 7) {
        cStateMachine_ChangeState(self->state44, (unsigned char)kind, 100);
        if (target) {
            self->kind = kind;
            cPathNavigator_Request_int(self->brain, target->id);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014BCF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014BCF0 */
