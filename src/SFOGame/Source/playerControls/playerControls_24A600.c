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
int cPlayerControls_ExitCrawl_cHumanR(void* self, TryStandActor_e8* actor); /* gsynth: defined below */typedef struct { char pad0[0x4C]; int type; } CzZone;
extern int g_HumanActorClassKey;
#if 0 /* merge_units */
extern int cPlayerControls_ExitCrawl_cHumanR(void* p, CzZone* z);
#endif /* merge_units */
#define cPlayerControls_ExitCrawl_cHumanR(a0, a1) (cPlayerControls_ExitCrawl_cHumanR((a0), (void *)(a1))) /* merge_units */

static inline CzZone* Cz(CzZone* z) { return (z && z->type == g_HumanActorClassKey) ? z : 0; } int cPlayerControls_ExitCrawl_cGOBJP(void* p, CzZone* z) { CzZone* c = Cz(z); if (c) return cPlayerControls_ExitCrawl_cHumanR(p, c); return 0; }
#undef cPlayerControls_ExitCrawl_cHumanR /* merge_units */
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
extern unsigned char cPlayerControls_EnterCrawl(PlayerInput_24A660* p, Obj_24A660* o);
unsigned char cPlayerControls_StayInCrawl(PlayerInput_24A660* p, Obj_24A660* o) {
    if ((p->flags >> 4) & 1) {
        o = (o && o->type == g_HumanActorClassKey) ? o : 0;
        if (o)
            return cPlayerControls_EnterCrawl(p, o);
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


extern char g_ActorActionMsgClass[];
extern char D_004E0840[];
extern void cMessage_ctor_cMessageNameR(TryStandMsg_e8* msg, void* name);
extern void QueueMessage_cMessageR_cSystemP_int(TryStandMsg_e8* msg, void* target, int flags);
extern void cMessage_dtor(TryStandMsg_e8* msg, int flags);
int cPlayerControls_ExitCrawl_cHumanR(void* self, TryStandActor_e8* actor)
{
    int blocked = ((actor->flags >> 4) & 1) && actor->phys && actor->phys->crouchBlock;
    if (!blocked) {
        TryStandMsg_e8 msg;
        cMessage_ctor_cMessageNameR(&msg, g_ActorActionMsgClass);
        msg.vtable = D_004E0840;
        msg.action = 10;
        msg.b20 = 1;
        msg.b28 = 0;
        QueueMessage_cMessageR_cSystemP_int(&msg, actor, 1);
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
