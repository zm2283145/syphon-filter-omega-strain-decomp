/*
 * main/player: range (3 files, 001758A0-00175980)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_001758A0 */
#pragma push /* merge_units */
#pragma global_optimizer off
typedef struct { char pad[0x4C]; int kind; char pad2[0x3528 - 0x50]; void* inv; } Obj_P;
extern Obj_P* cGOBJ_SOBJ_convert(void* o);
extern int g_HumanActorClassKey;
extern void cInventory_Remove_charP_int(void* inv, int a, int b);
static inline void Do_001758A0(int b, int a, void* o)
{
    Obj_P* p = cGOBJ_SOBJ_convert(o);
    if (p->kind == g_HumanActorClassKey)
        cInventory_Remove_charP_int(p->inv, a, b);
}
int Script_PlayerRemoveItem(int* args)
{
    int b[1];
    int a[1];
    b[0] = args[2];
    a[0] = args[1];
    Do_001758A0(*(int*)b, *(int*)a, (void*)args[0]);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001758A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001758A0 */

/* merge_units: begin func_00175910 */
#pragma push /* merge_units */
#pragma global_optimizer off

extern void cInventory_Add_charP_int(void* inv, int a, int b);
static inline void Do_00175910(int b, int a, void* o)
{
    Obj_P* p = cGOBJ_SOBJ_convert(o);
    if (p->kind == g_HumanActorClassKey)
        cInventory_Add_charP_int(p->inv, a, b);
}
int Script_PlayerAddItem(int* args)
{
    int b[1];
    int a[1];
    b[0] = args[2];
    a[0] = args[1];
    Do_00175910(*(int*)b, *(int*)a, (void*)args[0]);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00175910(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00175910 */

/* merge_units: begin func_00175980 */
#pragma push /* merge_units */
#pragma global_optimizer off
typedef struct {
    void* vtable;
    char base[0x1C];
    unsigned char kind;
    char pad[3];
    int count;
} Msg_SM;
typedef struct { char pad[0x14]; unsigned char local; } Ctl_SM;
typedef struct { char pad[0x30]; Ctl_SM* ctl; char pad2[0x1B8 - 0x34]; int maxNpc; } Plr_SM;
extern char D_004F53F8[];
extern void cMessage_getSOBJClassId();
extern void cMaxActiveNpcCountMsg_dtor();
extern void cMaxActiveNpcCountMsg_Clone();
extern void cMaxActiveNpcCountMsg_Pack();
extern void cMaxActiveNpcCountMsg_GetMsgId();
extern void cNetMsg_Pack();
void * const D_004DAE70[8] = { (void*)0x0, (void*)0x0, (void*)cMaxActiveNpcCountMsg_dtor, (void*)cMaxActiveNpcCountMsg_Clone, (void*)cNetMsg_Pack, (void*)cMessage_getSOBJClassId, (void*)cMaxActiveNpcCountMsg_Pack, (void*)cMaxActiveNpcCountMsg_GetMsgId };
extern char D_004DCF10[];
extern void cMessage_ctor_cMessageNameR(Msg_SM* msg, void* name);
extern void QueueMessage_cMessageR_cSystemP_int(Msg_SM* msg, void* target, int flags);
extern void cMessage_dtor(Msg_SM* msg, int flags);
static inline void SetMax(int n, Plr_SM* p)
{
    if (p->ctl->local) {
        p->maxNpc = n;
    } else {
        Msg_SM msg;
        cMessage_ctor_cMessageNameR(&msg, D_004F53F8);
        msg.count = n;
        msg.vtable = ((char*)D_004DAE70);
        msg.kind = 8;
        QueueMessage_cMessageR_cSystemP_int(&msg, p->ctl, 0);
        msg.vtable = D_004DCF10;
        cMessage_dtor(&msg, 0);
    }
}
int Script_cPlayer_SetMaxActiveNpcCount(int* args)
{
    int n[1];
    n[0] = args[1];
    SetMax(*(int*)n, (Plr_SM*)args[0]);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00175980(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00175980 */
