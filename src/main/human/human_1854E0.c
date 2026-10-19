/*
 * main/human: range (3 files, 001854E0-001855C0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vtable2_base_dtor.h"
#pragma pop

/* merge_units: begin func_001854E0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cNetForceHolsterMsg_dtor, D_004DA9B0, D_004DCF10, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_001854E0 */

/* merge_units: begin func_00185550 */
#pragma push /* merge_units */
typedef struct { char pad[0x4C]; int classKey; char pad50[0x3524 - 0x50]; void* weapons; } G_185550;
typedef union { int i; unsigned char b; } A_185550;
extern int g_HumanActorClassKey;
extern G_185550* GObj_IdentityB(int handle);
extern void Global_SetHardpointVis(void* w, unsigned char hp, unsigned char vis);
int Script_SetHardpointVis(A_185550* args)
{
    unsigned char vis = args[2].i != 0;
    unsigned char hp = args[1].b;
    G_185550* g = GObj_IdentityB(args[0].i);
    if (g && g->classKey == g_HumanActorClassKey) Global_SetHardpointVis(g->weapons, hp, vis);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00185550(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00185550 */

/* merge_units: begin func_001855C0 */
#pragma push /* merge_units */
typedef struct { int pad0; int pad4; int id; int padC; } Slot_1855C0;
typedef struct { Slot_1855C0 s[8]; char pad80[4]; unsigned char cur; } W_1855C0;
typedef struct { char pad[0x4C]; int classKey; char pad50[0x3524 - 0x50]; W_1855C0* weapons; } G_1855C0;
#if 0 /* merge_units */
extern G_1855C0* GObj_IdentityB(int handle);
#endif /* merge_units */
#define GObj_IdentityB(a0) ((G_1855C0 *)GObj_IdentityB((a0))) /* merge_units */

int Script_GetActiveWeapon(int* args)
{
    volatile int r;
    G_1855C0* g = GObj_IdentityB(args[0]);
    int v = -1;
    if (g && g->classKey == g_HumanActorClassKey) {
        W_1855C0* w = g->weapons;
        v = (w->cur != 6) ? w->s[w->cur].id : -1;
    }
    r = v;
    return r;
}
#undef GObj_IdentityB /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001855C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001855C0 */
