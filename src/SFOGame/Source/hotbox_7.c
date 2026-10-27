/*
 * main/hotbox: range (4 files, 00170160-00170460)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "message_pack.h"

/* merge_units: begin func_00170160 */
#pragma push /* merge_units */
#define PACK_BODY(e, b) MP_I(b, 8) = MP_I(e, 0x24); MP_I(b, 0xC) = MP_I(e, 0x28); MP_I(b, 0x10) = MP_I(e, 0x2C); MP_I(b, 0x14) = MP_I(MP_P(e, 0x30), 0xC);

DEFINE_MESSAGE_PACK(cHotboxMsg_Pack, 0x18, D_004EE6A0, PACK_BODY)
#pragma pop /* merge_units */
/* merge_units: end func_00170160 */

/* merge_units: begin func_00170200 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { int f0; int f4; int f8; int fC; int f10; int f14; } Pk70200;
typedef struct { void* vt; char p4[0x20]; int f24; int f28; int f2C; void* f30; } Msg70200;
typedef struct { char p0[0x24]; unsigned char action; } Hb70200;
typedef struct { char p0[0x98]; int f98; } Obj70200;
extern "C" {
extern unsigned char D_005723C8;
extern unsigned char D_005721D0;
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
extern char D_004EE698[], D_004D9940[];
extern void cMessage_ctor_cMessageNameR(Msg70200* e, void* type);
extern Obj70200* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
extern void QueueMessage_cMessageR_cSystemP_int_int(Msg70200*, void*, int, int);
extern void cMessage_dtor(Msg70200*, int);
}
#pragma define_section GUARD_70200_DTOR ".dtors_drop" far_absolute RX
struct Guard_70200 {
    Guard_70200() { if (!D_005723C8) D_005723C8 = 1; }
    __declspec(weak) __declspec(GUARD_70200_DTOR) ~Guard_70200() { D_005723C8 = 0; }
};
#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" int cHotboxMsg_HotBoxMsgCallback(int a0, int a1, int a2, Pk70200* arg) {
    Guard_70200 g;
    if (D_005721D0) {
        Msg70200 msg;
        int id1;
        int id0;
        Obj70200* obj;
        Pk70200* p = arg;
        Msg70200* m;
        m = &msg;
        cMessage_ctor_cMessageNameR(m, D_004EE698);
        msg.vt = D_004D9940;
        msg.f24 = p->f8;
        msg.f28 = p->fC;
        msg.f2C = p->f10;
        id0 = p->f14;
        m->f30 = nGobjManager_LookupGOBJ_cObjectIdR(&id0);
        id1 = p->f4;
        obj = nGobjManager_LookupGOBJ_cObjectIdR(&id1);
        if (obj) {
            QueueMessage_cMessageR_cSystemP_int_int(&msg, obj, 0, 0);
            if (g_IsMultiplayer ? D_005721C0 : 1) {
                int act = (unsigned char)msg.f24;
                if (act == 0) {
                    obj->f98++;
                    if (obj->f98 > 3) obj->f98 = 3;
                } else if (act == 2) {
                    obj->f98--;
                    if (obj->f98 < 0) obj->f98 = 0;
                }
            }
        }
        msg.vt = D_004D9940;
        cMessage_dtor(&msg, 0);
    }
    return 0x18;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00170200(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00170200 */

/* merge_units: begin func_00170360 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; int idC; int id10; char pad14[0x7C]; int f90; } Obj_0360;
int cNetObj_AddSystem(int, int, Obj_0360*);
Obj_0360* cHotboxMan_CreateInteractBox(int, int, int, int);
int NetGetMyClientIndex(int*, int);
int NetGetPeerToPeerHostClientIndex(int, int*);
extern int D_00494178;
extern int g_HotboxTracker;
extern int D_005721A8;
#pragma inline_depth(10)
static inline int LocalId_0360(void)
{
    int r;
    int a = D_005721A8; /* read before the flag test: retail loads it ahead of the branch */
    if (g_IsMultiplayer) {
        if (D_00494178 == -1) NetGetMyClientIndex(&D_00494178, a);
        r = D_00494178;
    } else r = 0;
    return r;
}
static inline int NetId_0360(void)
{
    int id;
    int ok = g_IsMultiplayer ? D_005721C0 : 1;
    if (ok) {
        id = LocalId_0360();
    } else {
        int tmp[1];
        NetGetPeerToPeerHostClientIndex(D_005721A8, tmp);
        id = tmp[0];
    }
    return id;
}
void MakeNPCNetInteractable(int arg0, int* arg1)
{
    Obj_0360* o = cHotboxMan_CreateInteractBox(g_HotboxTracker, arg0, 1, 0);
    o->idC = *arg1;
    o->id10 = *arg1;
    if (g_IsMultiplayer) {
        int t = o->id10;
        cNetObj_AddSystem(t, NetId_0360(), o);
    }
    o->f90 = 3;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00170360(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00170360 */

/* merge_units: begin func_00170460 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; int id; char pad10[0x80]; int mode; } T_0460;
typedef struct { char pad[0xC]; int id; } O_0460;
typedef struct { char pad[0x30]; O_0460* obj; } S_0460;
#if 0 /* merge_units */
extern void* g_HotboxTracker;
#endif /* merge_units */
#define g_HotboxTracker (*(void **)&g_HotboxTracker) /* merge_units */

extern char g_RuntimeHotboxes[];
#if 0 /* merge_units */
T_0460* cHotboxMan_CreateInteractBox(void* mgr, O_0460* obj, int a, int b);
#endif /* merge_units */
#define cHotboxMan_CreateInteractBox(a0, a1, a2, a3) ((T_0460 *)cHotboxMan_CreateInteractBox((int)(a0), (int)(a1), (a2), (a3))) /* merge_units */

void std_vector_cHotboxPtr_push_back(void* list, T_0460** pt);
void cNetNPCMsgs_SendMessage(O_0460* obj, int type, int size, int a, int b, int c, int d);
T_0460* Global_MakeNPCInteractable(S_0460* self)
{
    T_0460* t = cHotboxMan_CreateInteractBox(g_HotboxTracker, self->obj, 1, 0);
    t->mode = 3;
    std_vector_cHotboxPtr_push_back(g_RuntimeHotboxes, &t);
    if (g_IsMultiplayer)
        cNetNPCMsgs_SendMessage(self->obj, 0x2A, 4, self->obj->id, t->id, 0, 0);
    return t;
}
#undef g_HotboxTracker /* merge_units */
#undef cHotboxMan_CreateInteractBox /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00170460(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00170460 */
