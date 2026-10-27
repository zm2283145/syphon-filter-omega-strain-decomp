/*
 * SFOGame/Source/npc: 3 files, 00158490-00158540
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00158490 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (container helpers instantiated for cNPC).
 */

#include "npc_types.h"

void func_00158490(char* self, int value) {
    *(int*)(self + 0x1C) = value;
}

int cObjectId_GetEncodedValue(Word* self) {
    return self->value;
}
static inline void merge_flush_func_00158490(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00158490 */

/* merge_units: begin func_001584B0 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int cStateMachine_ChangeState(int , int, int);

int cNetworkTransferNpc_ctor_void(int arg0) {
    int var_a0;
    int var_a1;
    int var_v1;

    var_a0 = 0;
    var_v1 = arg0;
    do {
        F_(var_v1, 0x5C, int) = 0;
        F_(var_v1, 0x60, int) = 0;
        var_a0 += 3;
        F_(var_v1, 0x64, int) = 0;
        var_v1 += 0xC;
    } while (var_a0 < 9);
    F_(arg0, 0xF0, int) = 0;
    F_(arg0, 0xF8, int) = 0;
    cStateMachine_ChangeState(arg0 + 0xF0, 0, 0);
    var_a1 = arg0 + 0x1E0;
    F_(arg0, 0x1D0, int) = -1;
    do {
        F_(var_a1, 0x4, int) = -2;
        F_(var_a1, 0x0, int) = 0;
        F_(var_a1, 0x8, int) = -1;
        var_a1 += 0x40;
    } while (var_a1 != (arg0 + 0x2E0));
    return arg0;
}
static inline void merge_flush_func_001584B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001584B0 */

/* merge_units: begin func_00158540 */
#pragma push /* merge_units */
/* Returns the word at +0x30 (the owning actor if this is a cNPC). */
NpcActor* cNPC_Human(cNPC* self) {
    return self->actor;
}
static inline void merge_flush_func_00158540(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00158540 */
