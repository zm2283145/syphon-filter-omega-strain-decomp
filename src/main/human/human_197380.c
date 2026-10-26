/*
 * main/human: range (2 files, 00197380-00197440)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00197380 */
#pragma push /* merge_units */
typedef struct { void* vtable; char base[0x20]; int id; signed char b; char pad29[3]; } Msg_197380;
typedef struct { char pad[0x4C]; int classKey; } G_197380;
extern int g_HumanActorClassKey;
extern char D_004EEEE8[];
extern char D_004DA8F0[];
extern char D_004DCF10[];
extern signed char* D_005061D0;
extern void Event_Construct(Msg_197380* msg, void* name);
extern void cMessage_dtor(Msg_197380* msg, int flags);
extern void NetStream_ReadObject(int* out);
extern void Melee_StartAttack(G_197380* g, int id, int b);
static inline void ReadS8_197380(signed char* out) { signed char v = *D_005061D0; D_005061D0++; *out = v; }
static inline void ReadI_197380(int* out) { int t; NetStream_ReadObject(&t); *out = t; }
void MeleeMsg_CreateFromNet(G_197380* g)
{
    Msg_197380 msg;
    signed char* bp;
    int* ip;
    Event_Construct(&msg, D_004EEEE8);
    msg.vtable = D_004DA8F0;
    {
        int t;
        NetStream_ReadObject(&t);
        bp = &msg.b;
        ip = &msg.id;
        ReadS8_197380(bp);
        *ip = t;
    }
    if (g && g->classKey == g_HumanActorClassKey) Melee_StartAttack(g, *ip, *bp != 0);
    msg.vtable = D_004DCF10;
    cMessage_dtor(&msg, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00197380(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00197380 */

/* merge_units: begin func_00197440 */
#pragma push /* merge_units */
typedef struct { void* vtable; char base[0x20]; int id; char pad28[8]; Q pos; } Msg_197440;
extern char D_004EEED0[];
extern char D_004DA8D0[];
#if 0 /* merge_units */
extern void Event_Construct(Msg_197440* msg, void* name);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(Msg_197440* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

extern void Script_ReadU32(int* out);
extern void cNetMsg_GetVector(Q* out);
extern void* Actor_GetHumanClassKeyPtr(void);
extern int cGOBJ_CheckSubclassID(void* self, void* key);
extern void Actor_StartStarThrow(void* self, int* id, Q* pos);
void StarThrowMsg_CreateFromNet(void* self)
{
    Msg_197440 msg;
    int* ip;
    Q* qp;
    Event_Construct(&msg, D_004EEED0);
    msg.vtable = D_004DA8D0;
    ip = &msg.id;
    *ip = -1;
    Script_ReadU32(ip);
    qp = &msg.pos;
    cNetMsg_GetVector(qp);
    if (self && cGOBJ_CheckSubclassID(self, Actor_GetHumanClassKeyPtr())) Actor_StartStarThrow(self, ip, qp);
    msg.vtable = D_004DCF10;
    cMessage_dtor(&msg, 0);
}
#undef Event_Construct /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00197440(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00197440 */
