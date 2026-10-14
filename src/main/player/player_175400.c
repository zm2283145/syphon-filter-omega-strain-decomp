/*
 * main/player: range (3 files, 00175400-001754F0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00175400 */
#pragma push /* merge_units */
typedef struct { char pad[0x4C]; int kind; char pad2[0x33B4 - 0x50]; int bodies; } Plr_5400;
extern Plr_5400* PlayerSlots_Get(int i);
extern int D_0049D010;
int Script_SetPlayerBodies(int* args)
{
    unsigned char f = ((unsigned char)(args[0] != 0) != 0) ^ 1;
    int i;
    for (i = 0; i < 4; i++) {
        Plr_5400* p = PlayerSlots_Get(i);
        if (p && p->kind == D_0049D010)
            p->bodies = f;
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00175400(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00175400 */

/* merge_units: begin func_00175480 */
#pragma push /* merge_units */
typedef struct { char pad[0x4C]; int team; } C3Ent175480;
#if 0 /* merge_units */
extern C3Ent175480* PlayerSlots_Get(int i);
#endif /* merge_units */
#define PlayerSlots_Get(a0) ((C3Ent175480 *)PlayerSlots_Get((a0))) /* merge_units */

extern void Actor_SetInvulnerable(C3Ent175480* e, int on);
int Script_SetPlayerInvulnerability(int* args)
{
    int on = args[0] != 0;
    int i;
    C3Ent175480* e;
    for (i = 0; i < 4; i++) {
        e = PlayerSlots_Get(i);
        if (e != 0 && e->team == D_0049D010) {
            Actor_SetInvulnerable(e, on);
        }
    }
    return 0;
}
#undef PlayerSlots_Get /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00175480(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00175480 */

/* merge_units: begin func_001754F0 */
#pragma push /* merge_units */
typedef struct {
    void* vtable;
    char base[0x18];
    int x1C;
    unsigned char kind;
    char pad[0xB];
    int a;
} Msg_RB;
typedef struct { char pad[0xC]; int id; char pad2[0x4C - 0x10]; int kind; } Plr_RB;
extern char D_004F80A8[];
extern void Message_GetScriptTypeKey();
extern void func_001755D0();
extern void func_0025DDE0();
extern void func_0025E080();
void * const D_004DC7D0[8] = { (void*)0x0, (void*)0x0, (void*)func_001755D0, (void*)func_0025DDE0, (void*)func_0025E080, (void*)Message_GetScriptTypeKey, (void*)0x0, (void*)0x0 };
extern void Event_Construct(Msg_RB* msg, void* name);
extern void Event_Send(Msg_RB* msg, void* target, int flags);
extern void cMessage_dtor(Msg_RB* msg, int flags);
extern Plr_RB* GObj_IdentityB(void* o);
int Script_RestoreBody(void** args)
{
    Plr_RB* p = GObj_IdentityB(args[0]);
    if (p->kind == D_0049D010) {
        Msg_RB m1;
        Msg_RB m2;
        Event_Construct(&m1, D_004F80A8);
        m1.vtable = ((char*)D_004DC7D0);
        m1.a = p->id;
        m1.kind = 0x15;
        m1.x1C = 0x40;
        Event_Construct(&m2, D_004F80A8);
        m2.vtable = ((char*)D_004DC7D0);
        m2.a = p->id;
        Event_Send(&m2, p, 0);
        m2.vtable = ((char*)D_004DC7D0);
        cMessage_dtor(&m2, 0);
        m1.vtable = ((char*)D_004DC7D0);
        cMessage_dtor(&m1, 0);
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001754F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001754F0 */
