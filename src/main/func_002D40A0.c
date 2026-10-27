#pragma cplusplus on
#include "types.h"
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



