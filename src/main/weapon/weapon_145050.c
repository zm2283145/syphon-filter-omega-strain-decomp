/*
 * main/weapon: range (2 files, 00145050-001450B0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "weapon_types.h"

/* merge_units: begin func_00145050 */
#pragma push /* merge_units */
void* func_001450B0(void* self); /* gsynth: defined below */
/*
 * Matched functions (byte-identical with the retail executable).
 * Actor inventory and weapon-definition helpers, cOutOfAmmoMsg.
 */


extern int D_004EA160;   /* cOutOfAmmoMsg script type */
#if 0 /* merge_units */
extern cOutOfAmmoMsg* func_001450B0(void* self);
#endif /* merge_units */
#define func_001450B0(a0) ((cOutOfAmmoMsg *)func_001450B0((a0))) /* merge_units */

extern int* cMessage_SOBJ_getClassId(void);
extern void cScriptBase_declareParent(int type, int parentType);

/* volatile mirrors the original stack temporary. */
int Script_cOutOfAmmoMsg_Weapon(WeaponScriptArg* args) {
    volatile int weapon = func_001450B0(args[0].p)->weapon;
    return weapon;
}

/* Registers the cOutOfAmmoMsg script type under its parent type. */
void ScriptType_cOutOfAmmoMsg_Init(void) {
    int* parent = cMessage_SOBJ_getClassId();

    cScriptBase_declareParent(D_004EA160, *parent);
}
#undef func_001450B0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00145050(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00145050 */

/* merge_units: begin func_001450B0 */
#pragma push /* merge_units */
extern int D_004EA158;   /* cOutOfAmmoMsg type id */
extern int* func_001450C0(void);

void* func_001450B0(void* self) {
    return self;
}

int* func_001450C0(void) {
    return &D_004EA158;
}

int cOutOfAmmoMsg_v03(void) {
    return *func_001450C0();
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001450B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001450B0 */
