#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
typedef struct V4 { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct M4 { V4 r[4]; } M4;
typedef struct Msg { void* vtable; char pad[0x1C]; unsigned char kind; char pad2[3]; unsigned char b24; char pad3[0xB]; char data[0x40]; } Msg;
extern "C" {
extern char g_TeleportMsgClass[], D_004D9360[];
extern float Vec4_GetX(V4*);
extern float Vec4_GetY(V4*);
extern float Vec4_GetZ(V4*);
extern void Mtx_MakeAxisRotation(M4*, float, float, float, float);
extern void Event_Construct(Msg* m, void* type);
extern int TeleportMsg_IsMode3(Msg* m);
extern void* func_00133EC0(void* obj);
extern void func_0015A400(V4* out, void* v);
extern void Vec4_CopyAsPoint(V4* out, void* v);
extern void Mtx_SetRotationTranslation(void* data, void* obj, V4* v);
extern void Event_Send(Msg* m, void* target, int immediate);
extern void cMessage_dtor(Msg* m, int flags);
void func_00436C00(int* shared);
int func_004340C0(int* shared, void* id);
void func_00436BA0(int* shared, short flags);
void Actor_BasePreLogic(struct Npc* self, float dt);
void Npc_PreUpdate(struct Npc* self, float dt);
}

/* Npc_PreUpdate: when a net-owned NPC's target marker is not ready yet and
 * the local record is in sync, teleports the NPC to the marker (angle +
 * position) with a TeleportMsg and pushes the matrix to its model, then runs
 * the base pre-logic. Message/matrix code as in func_002D40A0. */
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
        func_00436C00(&shared);
        void* idp = &self->id;
        if (func_004340C0(&shared, idp)) {
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
            Mtx_MakeAxisRotation(&mtx, Vec4_GetX(&axis), Vec4_GetY(&axis), Vec4_GetZ(&axis), ang);
            pos.w = 1.0f;
            V4_Copy(&mtx.r[3], &pos);
            {
                if (AllFree(self)) {
                    m = &msg;
                    Event_Construct(m, g_TeleportMsgClass);
                    m->vtable = D_004D9360;
                    m->b24 = 2;
                    if (TeleportMsg_IsMode3(m)) {
                        func_0015A400(&a2, func_00133EC0(&mtx));
                        v = &a2;
                    } else {
                        Vec4_CopyAsPoint(&b2, func_00133EC0(&mtx));
                        v = &b2;
                    }
                    Mtx_SetRotationTranslation(m->data, &mtx, v);
                    msg.kind = 1;
                    Event_Send(&msg, self, 1);
                    msg.vtable = D_004D9360;
                    cMessage_dtor(&msg, 0);
                }
            }
            self->model->SetMatrix(&mtx);
        }
        func_00436BA0(&shared, -1);
    }
    Actor_BasePreLogic(self, dt);
}
