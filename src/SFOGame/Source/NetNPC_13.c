/*
 * SFOGame/Source/NetNPC: 12 files, 002D3D00-002D4640
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D3D00 */
#pragma push /* merge_units */
#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; } Npc3D00;
typedef struct { char pad[0xC]; int id; } Arg3D00;
void cNetNPC_ResendNewAwarenessMessage(Npc3D00* o, Arg3D00* a)
{
    int id = -1;
    void* n;
    if (!a) { n = o->net; } else { id = a->id; n = o->net; }
    cNetNPCMsgs_SendMessage(n, 0x35, 8, id, 0, 0, 0);
}
static inline void merge_flush_func_002D3D00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D3D00 */

/* merge_units: begin func_002D3D30 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; void* net; } Npc3D30;
extern void cNPC_AddAwarenessOfPlayers(Npc3D30* o);
void cNetNPC_AddAwarenessOfPlayers(Npc3D30* o)
{
    if (NpcAuth_IsLocal())
        cNPC_AddAwarenessOfPlayers(o);
    cNetNPCMsgs_SendMessage(o->net, 4, 8, 0, 0, 0, 0);
}
static inline void merge_flush_func_002D3D30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D3D30 */

/* merge_units: begin func_002D3DA0 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; void* net; char pad2[0x178]; void* body; } Npc3DA0;
typedef struct { char pad[0xC]; int id; } Arg3DA0;
extern void cAITarget_RemoveAwareness(void* body, Arg3DA0* a);
void cNetNPC_RemoveAwareness(Npc3DA0* o, Arg3DA0* a)
{
    if (NpcAuth_IsLocal())
        cAITarget_RemoveAwareness(o->body, a);
    cNetNPCMsgs_SendMessage(o->net, 0x29, 8, a->id, 0, 0, 0);
}
static inline void merge_flush_func_002D3DA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D3DA0 */

/* merge_units: begin func_002D3E20 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; void* net; char pad2[0x178]; void* body; } Npc3E20;
typedef struct { char pad[0xC]; int id; } Arg3E20;
extern void cAITarget_AddAwareness(void* body, Arg3E20* a, int f, float t);
void cNetNPC_AddAwareness(Npc3E20* o, Arg3E20* a)
{
    if (NpcAuth_IsLocal())
        cAITarget_AddAwareness(o->body, a, 1, 0.0f);
    cNetNPCMsgs_SendMessage(o->net, 3, 8, a->id, 0, 0, 0);
}
static inline void merge_flush_func_002D3E20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D3E20 */

/* merge_units: begin func_002D3EB0 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; void* net; } Npc3EB0;
extern void cNPC_ResumeAIMode(Npc3EB0* o);
void cNetNPC_ResumeAIMode(Npc3EB0* o)
{
    if (NpcAuth_IsLocal())
        cNPC_ResumeAIMode(o);
    cNetNPCMsgs_SendMessage(o->net, 2, 8, 0, 0, 0, 0);
}
static inline void merge_flush_func_002D3EB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D3EB0 */

/* merge_units: begin func_002D3F20 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; void* net; } Npc3F20;
extern void cAI_SetTeam(Npc3F20* o, int v);
void func_002D3F20(Npc3F20* o, int v)
{
    cNetNPCMsgs_SendMessage(o->net, 0x24, 8, v, 0, 0, 0);
    if (NpcAuth_IsLocal())
        cAI_SetTeam(o, v);
}
static inline void merge_flush_func_002D3F20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D3F20 */

/* merge_units: begin func_002D3FA0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void func_002D3FA0(void) {
}
static inline void merge_flush_func_002D3FA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D3FA0 */

/* merge_units: begin func_002D3FB0 */
#pragma push /* merge_units */
typedef struct { char pad[8]; int id; } Ref3FB0;
typedef struct { char pad[0x1E0]; Ref3FB0* target; } Obj3FB0;
extern void* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
void* cNetNPC_GetTargetGobj(Obj3FB0* o)
{
    Ref3FB0* r = o->target;
    void* res = 0;
    if (r) {
        int id = r->id;
        res = nGobjManager_LookupGOBJ_cObjectIdR(&id);
    }
    return res;
}
static inline void merge_flush_func_002D3FB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D3FB0 */

/* merge_units: begin func_002D3FF0 */
#pragma push /* merge_units */
#include "loose02_types.h"

extern int cAIPathData_GetNode(int id);

/* True when both the target and the link exist and the link is ready. */
int cNetNPC_IsTargetVisible(Controller2D* self) {
    return self->target != 0 && self->link != 0 && self->link->ready != 0;
}

/* Same test as cNetNPC_IsTargetVisible (separate vtable slot). */
int cNetNPC_TargetPositionValid(Controller2D* self) {
    return self->target != 0 && self->link != 0 && self->link->ready != 0;
}

/* Stores the id and caches its lookup. */
void cNetNPC_NodeReachedByLocalNpc(Controller2D* self, int id) {
    self->unk208 = id;
    self->unk1E8 = cAIPathData_GetNode(id);
}
static inline void merge_flush_func_002D3FF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D3FF0 */

/* merge_units: begin func_002D40A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
typedef struct V4 { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct M4 { V4 r[4]; } M4;
typedef struct Obj Obj;

struct Obj { VPAD16(a) VPAD4(b) VPAD1(c) virtual void f5C(int); char p4[8]; unsigned short hC; char pE[0x2C - 0xE]; unsigned char b2C; unsigned char b2D; unsigned char b2E; };
typedef struct Self Self;

struct Self {
    VPAD8(a) VPAD4(b) VPAD2(c) VPAD1(d) virtual int f44(); char p4[0x30 - 4]; Obj* obj; char p34[0x84 - 0x34]; int x84; char p88[4]; float f8C;
    char p90[0x159 - 0x90]; unsigned char b159; char p15A[0x1AC - 0x15A]; void* x1AC; void* x1B0;
    char p1B4[0x1EE - 0x1B4]; unsigned char b1EE; char p1EF; char vec[0x14]; int x204; int x208; int x20C;
    char p210[4]; unsigned char bf0 : 1; unsigned char bf1 : 1;
};
typedef struct Tgt { char p0[0x40]; float ang; float px, py, pz; } Tgt;
typedef struct Ctl { char p0[0x3524]; void* inv; char p3528[0x3584 - 0x3528]; Tgt* tgt; } Ctl;
typedef struct Msg { void* vtable; char pad[0x1C]; unsigned char kind; char pad2[3]; unsigned char b24; char pad3[0xB]; char data[0x40]; } Msg;
extern "C" {
extern char g_NpcDeadList[], g_TeleportMsgClass[], D_004D9360[];
extern void cNPC_AddToActiveList(Obj*);
extern void std_list_cNPCPtr_push_back(void*, Self**);
extern Ctl* cNPC_Human(Self*);
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
extern int cWeapon_IsFullyAutomatic(void*);
extern void cAITarget_Activate(void*);
extern void cPathNavigator_Activate(void*);
extern void func_0014FC60(Self*);
extern void cPathNavigator_Request_int_int_cVectorP(void*, int, int, void*);
}
/* bool-returning wrapper keeps the sltu/xori + beqz form */
static inline bool Idle(Obj* o) { return !(o->b2E != 0); }
/* volatile lq/sq quad copy idiom keeps the unfolded address registers */
static inline void V4_Copy(V4* d, const V4* s) { __int128 q; __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
extern "C" void cNetNPC_Activate(Self* self)
{
    if (self->b159) {
        Obj* o = self->obj;
        bool b = 0; bool a = 0;
        if (o->b2D && o->b2C) a = 1;
        if (a && Idle(o)) b = 1;
        if (!b) {
            if (self->f44()) {
                self->obj->f5C(1);
            }
        } else {
            if (self->f44()) {
                cNPC_AddToActiveList(self->obj);
            } else {
                std_list_cNPCPtr_push_back(g_NpcDeadList, &self);
            }
            if (cNPC_Human(self) && cNPC_Human(self)->tgt) {
                V4 pos;
                float ang;
                M4 mtx;
                Msg msg;
                V4 axis;
                Msg* m;
                V4 a2;
                V4 b2;
                V4* v;
                Tgt* t = cNPC_Human(self)->tgt;
                pos.x = t->px;
                pos.y = t->py;
                pos.z = t->pz;
                ang = cNPC_Human(self)->tgt->ang;
                axis.x = 0.0f;
                axis.y = 0.0f;
                axis.z = 1.0f;
                axis.w = 1.0f;
                cMatrix_SetWithAxisAngle(&mtx, cVector_X_void(&axis), cVector_Y_void(&axis), cVector_Z_void(&axis), ang);
                V4_Copy(&mtx.r[3], &pos);
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
                QueueMessage_cMessageR_cSystemP_int(&msg, self->obj, 1);
                self->b1EE = 0;
                msg.vtable = D_004D9360;
                cMessage_dtor(&msg, 0);
            }
            if (!cWeapon_IsFullyAutomatic(cNPC_Human(self)->inv)) {
                self->f8C = 0.2f + 0.01f * (float)(unsigned int)(self->obj->hC & 0xF);
            } else {
                self->f8C = 0.0f;
            }
            self->x84 = 0;
            cAITarget_Activate(self->x1AC);
            cPathNavigator_Activate(self->x1B0);
            func_0014FC60(self);
            if (self->bf1) {
                if (self->x20C >= 0) {
                    cPathNavigator_Request_int_int_cVectorP(self->x1B0, self->x208, self->x20C, 0);
                } else {
                    cPathNavigator_Request_int_int_cVectorP(self->x1B0, self->x208, -1, self->vec);
                }
                self->bf1 = 0;
            }
            self->x204 = 0;
        }
        self->b159 = 0;
    }
}
static inline void merge_flush_func_002D40A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D40A0 */

/* merge_units: begin func_002D4460 */
#pragma push /* merge_units */
#pragma cplusplus on

class Actor_4460 {
public:
    VPAD16(p) VPAD4(q) VPAD2(r)
    virtual void SetActive(int on);
    char pad4[0x2C - 4];
    unsigned char x2C;
    unsigned char x2D;
    unsigned char x2E;
};

struct Empty_4460 { char c; };
class cNPC_4460;
struct Pred_4460 {
    Empty_4460 e;
    cNPC_4460** self;
    Pred_4460(const Empty_4460& c, cNPC_4460** s) : e(c), self(s) {}
};

class cNPC_4460 {
public:
    VPAD8(p) VPAD4(q) VPAD2(r) VPAD1(s)
    virtual int IsLocal();
    char pad4[0x2C];
    Actor_4460* actor;
    char pad34[0x141 - 0x34];
    unsigned char b1 : 7;
    unsigned char net : 1;
    char pad142[0x150 - 0x142];
    unsigned short id;
    char pad152[0x159 - 0x152];
    unsigned char done;
};

typedef struct {
    void* vtable; void* type; unsigned int magic; unsigned int time; int unk10; void* target;
    unsigned int stampKind; int flags; unsigned char kind; unsigned char pad21[3];
    Actor_4460* actor;
    unsigned char flag;
} Msg_4460;

typedef struct { char pad[4]; unsigned int magic; } Obj_4460;

extern "C" {
extern char D_004A4A68[];
extern char D_004DB600[];
extern char D_004DB660[];
extern char g_NpcDeadList[];
void cNPC_RemoveFromActiveList(Actor_4460* a);
void std_list_imp_voidPtr_remove_if(void* v, Pred_4460 p);
#if 0 /* merge_units */
Obj_4460* nGobjManager_LookupGOBJ_cObjectIdR(unsigned short* id);
#endif /* merge_units */
#define nGobjManager_LookupGOBJ_cObjectIdR(a0) ((Obj_4460 *)nGobjManager_LookupGOBJ_cObjectIdR((int *)(a0))) /* merge_units */

#if 0 /* merge_units */
void cMessage_ctor_cMessageNameR(void* msg, void* type);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((Msg *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void QueueMessage_cMessageR_cSystemP_int(void* msg, void* target, int immediate);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((Msg *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
void cMessage_dtor(void* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((Msg *)(a0), (a1))) /* merge_units */

void cNPCInfoObject_ctor(int* t);
int cNPCInfoObject_GetOwner_cObjectIdR(int* t, void* id);
void cNetObjectMgr_RemoveFromTerrainActivation(Actor_4460* a);
void cNPCInfoObject_dtor(int* t, int f);
}

static inline bool IsAlive_4460(Actor_4460* a) { return a->x2D && a->x2C && !a->x2E; }

extern "C" void cNetNPC_Deactivate(cNPC_4460* self)
{
    int t;
    Empty_4460 e;
    if (!self->done) {
        Actor_4460* a = self->actor;
        if (a && IsAlive_4460(a)) {
            a->SetActive(1);
            return;
        }
        cNPC_RemoveFromActiveList(a);
            std_list_imp_voidPtr_remove_if(g_NpcDeadList, Pred_4460(e, &self));
        if (self->id) {
            Obj_4460* o = nGobjManager_LookupGOBJ_cObjectIdR(&self->id);
            if (o && o->magic == 0xBEBAAFDE) {
                Msg_4460 m;
                Actor_4460* act = self->actor;
                cMessage_ctor_cMessageNameR(&m, D_004A4A68);
                m.vtable = D_004DB600;
                m.flag = 1;
                m.actor = act;
                QueueMessage_cMessageR_cSystemP_int(&m, o, 0);
                m.vtable = D_004DB660;
                cMessage_dtor(&m, 0);
            }
        } else if (self->IsLocal()) {
            cNPCInfoObject_ctor(&t);
            cNPCInfoObject_GetOwner_cObjectIdR(&t, (char*)self->actor + 0xC);
            if (self->net) cNetObjectMgr_RemoveFromTerrainActivation(self->actor);
            cNPCInfoObject_dtor(&t, -1);
        }
        self->done = 1;
    }
}
#undef nGobjManager_LookupGOBJ_cObjectIdR /* merge_units */
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_002D4460(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D4460 */

/* merge_units: begin func_002D4640 */
#pragma push /* merge_units */
extern float cWeapon_SetAmmoNpcDeath(int arg);
extern int cAITarget_dtor(int arg);

int func_002D4640(Controller2D* self) {
    cWeapon_SetAmmoNpcDeath(self->owner->unk3524);
    return cAITarget_dtor(self->unk1AC);
}
static inline void merge_flush_func_002D4640(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D4640 */
