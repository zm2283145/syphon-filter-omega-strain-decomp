/*
 * main/playerControls: range (3 files, 0024A600-0024A6E0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0024A600 */
#pragma push /* merge_units */
typedef struct { char pad[0x3D2]; unsigned char crouchBlock; } TryStandPhys_e8;
typedef struct {
    char pad[0x3204];
    int flags;                  /* 0x3204 */
    char pad3208[0x3310 - 0x3208];
    TryStandPhys_e8* phys;      /* 0x3310 */
} TryStandActor_e8;
int PlayerInput_TryStand(void* self, TryStandActor_e8* actor); /* gsynth: defined below */typedef struct { char pad0[0x4C]; int type; } CzZone;
extern int D_0049D010;
#if 0 /* merge_units */
extern int PlayerInput_TryStand(void* p, CzZone* z);
#endif /* merge_units */
#define PlayerInput_TryStand(a0, a1) (PlayerInput_TryStand((a0), (void *)(a1))) /* merge_units */

static inline CzZone* Cz(CzZone* z) { return (z && z->type == D_0049D010) ? z : 0; } int PlayerInput_OnCrouchZoneExit(void* p, CzZone* z) { CzZone* c = Cz(z); if (c) return PlayerInput_TryStand(p, c); return 0; }
#undef PlayerInput_TryStand /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0024A600(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0024A600 */

/* merge_units: begin func_0024A660 */
#pragma push /* merge_units */
typedef struct {
    char p00[0x3C];
    int flags;
} PlayerInput_24A660;
typedef struct {
    char p00[0x4C];
    int type;
} Obj_24A660;
extern unsigned char PlayerInput_Crouch(PlayerInput_24A660* p, Obj_24A660* o);
unsigned char PlayerInput_OnCrouchZoneEnter(PlayerInput_24A660* p, Obj_24A660* o) {
    if ((p->flags >> 4) & 1) {
        o = (o && o->type == D_0049D010) ? o : 0;
        if (o)
            return PlayerInput_Crouch(p, o);
        return 0;
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0024A660(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0024A660 */

/* merge_units: begin func_0024A6E0 */
#pragma push /* merge_units */
typedef struct {
    void* vtable;
    char base[0x1C];
    unsigned char b20;  /* 0x20 */
    char pad21[3];
    int action;         /* 0x24 */
    unsigned char b28;  /* 0x28 */
} TryStandMsg_e8;


extern char D_0055D480[];
extern char D_004E0840[];
extern void Event_Construct(TryStandMsg_e8* msg, void* name);
extern void Event_Send(TryStandMsg_e8* msg, void* target, int flags);
extern void cMessage_dtor(TryStandMsg_e8* msg, int flags);
int PlayerInput_TryStand(void* self, TryStandActor_e8* actor)
{
    int blocked = ((actor->flags >> 4) & 1) && actor->phys && actor->phys->crouchBlock;
    if (!blocked) {
        TryStandMsg_e8 msg;
        Event_Construct(&msg, D_0055D480);
        msg.vtable = D_004E0840;
        msg.action = 10;
        msg.b20 = 1;
        msg.b28 = 0;
        Event_Send(&msg, actor, 1);
        msg.vtable = D_004E0840;
        cMessage_dtor(&msg, 0);
        return 1;
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0024A6E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0024A6E0 */
