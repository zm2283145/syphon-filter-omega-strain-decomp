/*
 * SFOGame/Source/human: 3 files, 001B2A80-001B2E90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001B2A80 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
typedef struct V4 { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct M4 { V4 r[4]; } M4;
typedef struct Msg { void* vtable; char pad[0x1C]; unsigned char kind; char pad2[3]; unsigned char b24; char pad3[0xB]; char data[0x40]; } Msg;
extern "C" {
extern char g_TeleportMsgClass[], D_004D9360[];
extern float cVector_X_void(V4*);
extern float cVector_Y_void(V4*);
extern float cVector_Z_void(V4*);
extern void cMatrix_SetWithAxisAngle(M4*, float, float, float, float);
extern void cMessage_ctor_cMessageNameR(Msg* m, void* type);
extern int cMoveMsg_Template_1_HasDeltaPosition(Msg* m);
extern void* func_00133EC0(void* obj);
extern void cVector_Copy_WSet0(V4* out, void* v);
extern void cVector_Copy_WSet1(V4* out, void* v);
extern void cMatrix_ctor_cMatrixR_cVectorR(void* data, void* obj, V4* v);
extern void QueueMessage_cMessageR_cSystemP_int(Msg* m, void* target, int immediate);
extern void cMessage_dtor(Msg* m, int flags);
void cNPCInfoObject_ctor(int* shared);
int cNPCInfoObject_IsActiveOnRemote(int* shared, void* id);
void cNPCInfoObject_dtor(int* shared, short flags);
void cGOBJ_CriticalNextFrame(struct Npc* self, float dt);
void Npc_PreUpdate(struct Npc* self, float dt);
}

/* Npc_PreUpdate: when a net-owned NPC's target marker is not ready yet and
 * the local record is in sync, teleports the NPC to the marker (angle +
 * position) with a TeleportMsg and pushes the matrix to its model, then runs
 * the base pre-logic. Message/matrix code as in cNetNPC_Activate. */
typedef struct Tgt { char p0[0x40]; float ang; float px, py, pz; } Tgt;
struct Slot { char p0[0xB0]; int busy; };
struct Model { VPAD1(a) virtual void SetMatrix(M4* m); };
struct Npc {
    char p0[0xC]; int id; char p10[0x14 - 0x10]; unsigned char b14; char p15[0x2C - 0x15];
    unsigned char b2C; unsigned char b2D; unsigned char b2E; char p2F[0x50 - 0x2F]; Model* model;
    char p54[0x3290 - 0x54]; Slot* slots[3]; char p329C[0x3584 - 0x329C]; Tgt* tgt;
};
static inline bool Idle(Npc* o) { return !(o->b2E != 0); }
static inline bool Has(Slot* s) { return s->busy != 0; }
static inline unsigned char UHas(Slot* s) { return s->busy != 0; }
static inline unsigned char UHas2(Slot* s) { return UHas(s); }
static inline bool Free(Slot* s) { return !(Has(s) != 0); }
static inline bool Free1(Slot* s) { return !(UHas2(s) != 0); }
static inline bool AllFree(Npc* n) { bool r = 0; bool c = 0; if (Free1(n->slots[0]) && Free(n->slots[1])) c = 1; if (c && Free(n->slots[2])) r = 1; return r; }
static inline void V4_Copy(V4* d, const V4* s) { __int128 q; __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
extern "C" void Npc_PreUpdate(Npc* self, float dt)
{
    bool b = 0; bool a = 0;
    if (self->b2D && self->b2C) a = 1;
    if (a && Idle(self)) b = 1;
    if (!b && !self->b14 && self->tgt) {
        int shared;
        cNPCInfoObject_ctor(&shared);
        void* idp = &self->id;
        if (cNPCInfoObject_IsActiveOnRemote(&shared, idp)) {
            V4 pos;
            float ang;
            M4 mtx;
            Msg msg;
            V4 axis;
            Msg* m;
            V4 a2;
            V4 b2;
            V4* v;
            Tgt* t = self->tgt;
            pos.x = t->px;
            pos.y = t->py;
            pos.z = t->pz;
            ang = self->tgt->ang;
            axis.x = 0.0f;
            axis.y = 0.0f;
            axis.z = 1.0f;
            axis.w = 1.0f;
            cMatrix_SetWithAxisAngle(&mtx, cVector_X_void(&axis), cVector_Y_void(&axis), cVector_Z_void(&axis), ang);
            pos.w = 1.0f;
            V4_Copy(&mtx.r[3], &pos);
            {
                if (AllFree(self)) {
                    m = &msg;
                    cMessage_ctor_cMessageNameR(m, g_TeleportMsgClass);
                    m->vtable = D_004D9360;
                    m->b24 = 2;
                    if (cMoveMsg_Template_1_HasDeltaPosition(m)) {
                        cVector_Copy_WSet0(&a2, func_00133EC0(&mtx));
                        v = &a2;
                    } else {
                        cVector_Copy_WSet1(&b2, func_00133EC0(&mtx));
                        v = &b2;
                    }
                    cMatrix_ctor_cMatrixR_cVectorR(m->data, &mtx, v);
                    msg.kind = 1;
                    QueueMessage_cMessageR_cSystemP_int(&msg, self, 1);
                    msg.vtable = D_004D9360;
                    cMessage_dtor(&msg, 0);
                }
            }
            self->model->SetMatrix(&mtx);
        }
        cNPCInfoObject_dtor(&shared, -1);
    }
    cGOBJ_CriticalNextFrame(self, dt);
}
static inline void merge_flush_func_001B2A80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B2A80 */

/* merge_units: begin func_001B2D20 */
#pragma push /* merge_units */
#pragma cplusplus on
/* sync the equipped weapon with the networked item entity */
struct WSlot_B2D20 { int id; int pad[3]; };
struct Inv_B2D20 {
    char pad0[8]; WSlot_B2D20 slots[6]; char pad68[0x84 - 0x68]; unsigned char cur;
    int CurId() { return cur != 6 ? slots[cur].id : -1; }
};
struct Base_B2D20 { char pad0[0x1C]; };
struct Item_B2D20 { char pad0[6]; short id; short GetId() { return id; } };
struct Ent_B2D20 : Base_B2D20, Item_B2D20 { };
struct NetRec_B2D20 { char pad0[0x10]; Ent_B2D20* ent; };
struct Obj_B2D20 {
    char pad0[0xC];
    int netId;
    char pad10[4];
    unsigned char remote;
    char pad15[0x3524 - 0x15];
    Inv_B2D20* inv;
    char pad3528[0x3584 - 0x3528];
    Ent_B2D20* ent;
};
extern "C" {
NetRec_B2D20* cNetObj_GetNetSystem(int id);
void cWeapon_Select(Inv_B2D20* inv, int id);
void cHuman_CheckForChangedWeapons(Obj_B2D20* o);
}
static inline Item_B2D20* AsItem(Ent_B2D20* e) { return e; }
void cHuman_CheckForChangedWeapons(Obj_B2D20* o)
{
    if (!o->remote) {
        if (!o->ent) {
            NetRec_B2D20* n = cNetObj_GetNetSystem(o->netId);
            if (n && n->ent) o->ent = n->ent;
        }
        if (AsItem(o->ent)) {
            if (o->inv->CurId() != AsItem(o->ent)->GetId())
                cWeapon_Select(o->inv, AsItem(o->ent)->id);
        }
    } else {
        if (AsItem(o->ent)) {
            if (o->inv->CurId() != AsItem(o->ent)->GetId())
                AsItem(o->ent)->id = o->inv->CurId();
        }
    }
}
static inline void merge_flush_func_001B2D20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B2D20 */

/* merge_units: begin func_001B2E90 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "human_types.h"
class Vis {
public:
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int IsOn();
};
struct Net { char pad[0x24]; int w24; };
class Act {
public:
    VPAD16(a) VPAD4(b) VPAD2(c)
    virtual void Fn60(int);
    char pad4[0xC - 0x4];
    unsigned int wC;
    char pad10[0x14 - 0x10];
    unsigned char b14;
    char pad15[0x58 - 0x15];
    Vis* p58;
    char pad5C[0x3584 - 0x5C];
    Net* p3584;
};
struct Agent { char pad[0xB70]; unsigned char bB70; };
struct Color { float r, g, b, a; };
extern "C" {
extern unsigned char D_00572418[];
extern unsigned char D_0055C780[];
extern char D_0055C7A0[];
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
extern char D_0049E8B0[];
extern char g_Game[];
extern char* g_Hud;
extern void* g_ActorList;
char* nGlobalization_GetString_charP(char*);
char* cGameSystem_GetClientPlayerName(char*, int);
int sprintf(char*, const char*, ...);
void cInfoBar_AddMessage(char*, char*, Color*, int, int);
void cHuman_PlayQuip(Act*, int);
Agent* cGameSystem_GetAgentData(char*, int);
void cNetObj_RemovePlayer_int(int);
void cAssocArray_int_netSystemField_End(Iter*, char*);
void cAssocArray_int_netSystemField_Find(Iter*, char*, int*);
int cAssocArray_int_netSystemField_Iterator_opNe(Iter*, Iter*);
int cAssocArray_int_netSystemField_Erase(char*, Iter*);
void cBaseObjList_Remove(void*, Act*);
void cSystem_ActualScheduleDelete(Act*, float);
void NetFreeObject(int);
void func_00257040(int);
}
static inline bool IsOn(Act* a)
{
    bool on = 0;
    if (a->p58 && a->p58->IsOn()) on = 1;
    return on;
}
static inline int PIdx(Act* a)
{
    return ((a->wC & 0x7F000000) >> 24) - 1;
}
static inline int NetIdx(Act* a)
{
    if (g_IsMultiplayer) {
        if (IsOn(a)) return PIdx(a);
        return -1;
    }
    return 0;
}
static inline unsigned char Mp()
{
    if (g_IsMultiplayer) return D_005721C0;
    return 1;
}
extern "C" bool cHuman_CheckForDisconnectedNetworkedPlayer(Act* a)
{
    bool ret = 0;
    int idx;
    if (IsOn(a) && !a->b14) {
        idx = PIdx(a);
        if (D_00572418[idx]) {
            char buf[0x100];
            Color c;
            int key;
            int pl = NetIdx(a);
            char* fmt = nGlobalization_GetString_charP(D_0049E8B0);
            sprintf(buf, fmt, cGameSystem_GetClientPlayerName(g_Game, pl));
            c.r = 1.0f;
            c.g = 0.0f;
            c.b = 0.0f;
            c.a = 1.0f;
            cInfoBar_AddMessage(g_Hud + 0x100, buf, &c, 1, 0);
            cHuman_PlayQuip(a, 3);
            D_0055C780[idx] = 0;
            cGameSystem_GetAgentData(g_Game, idx)->bB70 = 0;
            cNetObj_RemovePlayer_int(idx);
            key = a->wC;
            {
                Iter e, f;
                cAssocArray_int_netSystemField_End(&e, D_0055C7A0);
                cAssocArray_int_netSystemField_Find(&f, D_0055C7A0, &key);
                if (cAssocArray_int_netSystemField_Iterator_opNe(&e, &f)) {
                    Iter g;
                    cAssocArray_int_netSystemField_Find(&g, D_0055C7A0, &key);
                    cAssocArray_int_netSystemField_Erase(D_0055C7A0, &g);
                }
            }
            cBaseObjList_Remove(g_ActorList, a);
            cSystem_ActualScheduleDelete(a, 0.1f);
            a->Fn60(1);
            ret = 1;
            {
                unsigned char mp = Mp();
                if (mp && a->p3584) NetFreeObject(a->p3584->w24);
            }
            func_00257040(idx);
        }
    }
    return ret;
}
static inline void merge_flush_func_001B2E90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B2E90 */
