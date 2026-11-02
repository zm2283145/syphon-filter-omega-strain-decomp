/*
 * SFOGame/Source/GameGOBJ: 8 files, 00215E40-00216C50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00215E40 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(std_vector_cGameGOBJPtr_dtor)
static inline void merge_flush_func_00215E40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00215E40 */

/* merge_units: begin func_00215F30 */
#pragma push /* merge_units */
/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

Rel* std_vector_cGameGOBJPtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_00215F30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00215F30 */

/* merge_units: begin func_00215F50 */
#pragma push /* merge_units */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
#if 0 /* merge_units */
int cMemMan_Deallocate();
#endif /* merge_units */


#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
extern char D_004DB040[];
extern char D_004A4550[];
extern unsigned char g_IsMultiplayer;
void NetFreeObject(int a);
void** std_vector_charPtr_opIndex_uint(void* v, int i);
#if 0 /* merge_units */
void cFileMan_dtor(void* p, int flag);
#endif /* merge_units */
void* cFileMan_dtor(void* entry, int flags); /* merge_units */
#define cFileMan_dtor(a0, a1) ((void)cFileMan_dtor((a0), (a1))) /* merge_units */

void std_vector_cHotboxPtr_dtor(void* p, int flag);
void func_0013A040(void* p, int flag);
void std_vector_charPtr_dtor_void(void* p, int flag);
#if 0 /* merge_units */
void std_vector_cGameGOBJPtr_dtor(void* p, int flag);
#endif /* merge_units */
#define std_vector_cGameGOBJPtr_dtor(a0, a1) ((void)std_vector_cGameGOBJPtr_dtor((BufHolder *)(a0), (short)(a1))) /* merge_units */

void* cPathedGOBJ_dtor(void* p, int flag);
#if 0 /* merge_units */
void operator_delete(void* p);
#endif /* merge_units */
#define operator_delete(a0) (operator_delete((a0))) /* merge_units */

}
struct ElevSnd { char pad[0x48]; char a[0xE4 - 0x48]; char b[0x190 - 0xE4]; };
struct ElevHandle { char pad[0xC]; unsigned char c; char padD[0x1C - 0xD]; int h; };
struct cElevatorGOBJ_00215F50 {
    void* vt;
    char pad4[0xD0 - 4];
    void* pD0;
    char padD4[0xE8 - 0xD4];
    char mE8[0x10];
    char mF8[4];
    int nFC;
    void** p100;
    char pad104[4];
    char m108[0x10];
    char m118[0x10];
    ElevHandle* p128;
    char pad12C[0x150 - 0x12C];
    ElevSnd snd[4];
};
#pragma opt_strength_reduction off
static inline void Free_215F50(void* p, int line) { AllocGuard g; cMemMan_Deallocate(0, p, D_004A4550, line); }
static inline void SndDtor(ElevSnd* s) { if (s) { cFileMan_dtor(s->b, -1); cFileMan_dtor(s->a, -1); } }
extern "C" cElevatorGOBJ_00215F50* cElevatorGOBJ_dtor(cElevatorGOBJ_00215F50* self, short flag)
{
    if (self) {
        int i;
        self->vt = D_004DB040;
        if (g_IsMultiplayer) {
            ElevHandle* d = self->p128;
            if (d) {
                if (d->c) NetFreeObject(d->h);
                else Free_215F50(d, 0xCAD);
                self->p128 = 0;
            }
        } else {
            if (self->p128) {
                void* t = *(void* volatile*)&self->pD0;
                self->pD0 = 0;
                self->p128 = 0;
            }
        }
        for (i = 0; i < self->nFC; i++) {
            void* p = *std_vector_charPtr_opIndex_uint(self->mF8, i);
            Free_215F50(p, 0x5D8);
            self->p100[i] = 0;
        }
        SndDtor(&self->snd[3]);
        SndDtor(&self->snd[2]);
        SndDtor(&self->snd[1]);
        SndDtor(&self->snd[0]);
        if (self->m118) std_vector_cHotboxPtr_dtor(self->m118, -1);
        if (self->m108) func_0013A040(self->m108, -1);
        if (self->mF8) std_vector_charPtr_dtor_void(self->mF8, -1);
        if (self->mE8) std_vector_cGameGOBJPtr_dtor(self->mE8, -1);
        cPathedGOBJ_dtor(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00215F50(void) {}
#undef cFileMan_dtor /* merge_units */
#undef std_vector_cGameGOBJPtr_dtor /* merge_units */
#undef operator_delete /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00215F50 */

/* merge_units: begin func_00216230 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Vec { float x, y, z, w; };
struct Ctl {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual void Update(); /* +0x58 */
    char pad04[0x44];
    float x48;
    char pad4C[4];
    unsigned char dirty;
};
struct Obj {
    char pad00[0x50];
    Ctl* ctl;
    Ctl* GetCtl() { Ctl* c = ctl; if (c->dirty) c->Update(); return c; }
};
struct Src {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36();
    virtual Vec GetPos(); /* +0xE4 */
};
struct cInteractGOBJ {
    char pad00[0x94];
    unsigned char x94;
    char pad95[0x13];
    Src* xA8;
    char padAC[4];
    unsigned char xB0;
    char padB1[3];
    Obj* riders[2];
};
struct Notice { char pad[0x30]; int who; };
static inline float Fabs(float x) { float r; asm { abs.s r, x } return r; }
extern "C" {
#if 0 /* merge_units */
extern Obj* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
#endif /* merge_units */
void* nGobjManager_LookupGOBJ_cObjectIdR(int*); /* merge_units */
#define nGobjManager_LookupGOBJ_cObjectIdR(a0) ((Obj *)nGobjManager_LookupGOBJ_cObjectIdR((a0))) /* merge_units */

#if 0 /* merge_units */
extern int nCAS_PerformAction_WithObject_cSystemP_eAction_cGOBJP_float_etc(Obj* obj, int action, cInteractGOBJ* target, int arg, float time);
#endif /* merge_units */
int nCAS_PerformAction_WithObject_cSystemP_eAction_cGOBJP_float_etc(void*, int, void*, int, float); /* merge_units */
#define nCAS_PerformAction_WithObject_cSystemP_eAction_cGOBJP_float_etc(a0, a1, a2, a3, a4) (nCAS_PerformAction_WithObject_cSystemP_eAction_cGOBJP_float_etc((void *)(a0), (a1), (void *)(a2), (a3), (a4))) /* merge_units */

void cInteractGOBJ_HandleBuddyClimb(cInteractGOBJ* self, Notice* msg);
}
void cInteractGOBJ_HandleBuddyClimb(cInteractGOBJ* self, Notice* msg)
{
    int id;
    Obj* o;
    int i;
    float d0;
    float d1;
    if (self->xB0) return;
    id = msg->who;
    o = nGobjManager_LookupGOBJ_cObjectIdR(&id);
    if (self->riders[0] == o) {
        self->riders[0] = 0;
        if (self->x94) {
            nCAS_PerformAction_WithObject_cSystemP_eAction_cGOBJP_float_etc(o, 0x36, self, 0, -1.0f);
        } else {
            nCAS_PerformAction_WithObject_cSystemP_eAction_cGOBJP_float_etc(o, 0x32, self, 0, -1.0f);
        }
        self->x94 = 0;
        return;
    }
    for (i = 1; i < 2; i++) {
        if (self->riders[i] == o) return;
    }
    if (self->riders[0] == 0) {
        if (self->xA8 == 0) return;
        float d;
        {
            Ctl* c = o->GetCtl();
            d = self->xA8->GetPos().z - c->x48;
        }
        self->riders[0] = o;
        if (Fabs(d) < 5.0f) {
            self->x94 = 1;
            nCAS_PerformAction_WithObject_cSystemP_eAction_cGOBJP_float_etc(o, 0x35, self, 0, -1.0f);
            return;
        } else {
            nCAS_PerformAction_WithObject_cSystemP_eAction_cGOBJP_float_etc(o, 0x31, self, 0, -1.0f);
            return;
        }
    }
    if (self->riders[1]) return;
    {
        Ctl* c = self->riders[0]->GetCtl();
        d0 = self->xA8->GetPos().z - c->x48;
    }
    {
        Ctl* c = o->GetCtl();
        d1 = self->xA8->GetPos().z - c->x48;
    }
    if (Fabs(d0) < 5.0f && Fabs(d1) < 5.0f) return;
    self->xB0 = 1;
    self->riders[1] = o;
    if (Fabs(d1) < 5.0f) {
        nCAS_PerformAction_WithObject_cSystemP_eAction_cGOBJP_float_etc(o, 0x38, self, 0, -1.0f);
        nCAS_PerformAction_WithObject_cSystemP_eAction_cGOBJP_float_etc(self->riders[0], 0x37, self, 0, -1.0f);
        return;
    }
    if (self->x94) {
        nCAS_PerformAction_WithObject_cSystemP_eAction_cGOBJP_float_etc(self->riders[0], 0x38, self, 0, -1.0f);
        nCAS_PerformAction_WithObject_cSystemP_eAction_cGOBJP_float_etc(o, 0x37, self, 0, -1.0f);
        self->x94 = 0;
        return;
    }
    nCAS_PerformAction_WithObject_cSystemP_eAction_cGOBJP_float_etc(o, 0x34, self, 0, -1.0f);
    nCAS_PerformAction_WithObject_cSystemP_eAction_cGOBJP_float_etc(self->riders[0], 0x33, self, 0, -1.0f);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00216230(void) {}
#undef nGobjManager_LookupGOBJ_cObjectIdR /* merge_units */
#undef nCAS_PerformAction_WithObject_cSystemP_eAction_cGOBJP_float_etc /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00216230 */

/* merge_units: begin func_00216580 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Msg_216580 {
    virtual void Destroy(int f);
    virtual Msg_216580* Clone();
};
struct Obj_216580 { char pad0[0xC]; int id; };
struct Rel_216580 { int a; int n; void** c; };
struct cInteractGOBJ_216580 {
    void* vtable;
    char pad04[0x94];
    Rel_216580 x98;
    unsigned char xA4;
    char padA5[0xB];
    unsigned char xB0;
    char padB1[3];
    Obj_216580* riders[2];
    Msg_216580* xBC;
};
struct In_216580 {
    void* vtable;
    char pad04[0x20];
    unsigned char kind;
    char pad25[7];
    Obj_216580* who;
    int id;
};
struct In2_216580 {
    void* vtable;
    char pad04[0x20];
    int kind;
    char pad28[4];
    Obj_216580* who;
};
struct LiftMsg_216580 { void* vtable; char base[0x1C]; unsigned char b20; char pad21[3]; int kind; int floor; int from; int to; char pad34[0xC]; };
extern "C" {
extern unsigned char D_005721C0;
extern int g_TriggerMsgKey;
extern int g_CasEventMsgClass;
extern char D_004DAF10[];
int* cMessage_Name(void* ev);
void cMessage_ctor_cMessageNameR(void* m, void* type);
void QueueMessage_cMessageR_cSystemP_int(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
#if 0 /* merge_units */
Obj_216580* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
#endif /* merge_units */
#define nGobjManager_LookupGOBJ_cObjectIdR(a0) ((Obj_216580 *)nGobjManager_LookupGOBJ_cObjectIdR((a0))) /* merge_units */


#if 0 /* merge_units */
int nCAS_PerformAction_WithObject_cSystemP_eAction_cGOBJP_float_etc(Obj_216580* obj, int action, cInteractGOBJ_216580* target, int arg, float time);
#endif /* merge_units */
#define nCAS_PerformAction_WithObject_cSystemP_eAction_cGOBJP_float_etc(a0, a1, a2, a3, a4) (nCAS_PerformAction_WithObject_cSystemP_eAction_cGOBJP_float_etc((void *)(a0), (a1), (void *)(a2), (a3), (a4))) /* merge_units */


#if 0 /* merge_units */
void cInteractGOBJ_HandleBuddyClimb(cInteractGOBJ_216580* self, In_216580* msg);
#endif /* merge_units */
#define cInteractGOBJ_HandleBuddyClimb(a0, a1) (cInteractGOBJ_HandleBuddyClimb((cInteractGOBJ *)(a0), (Notice *)(a1))) /* merge_units */


void func_003E6690(Obj_216580* o, int f);
int cGOBJ_HandleMessage(cInteractGOBJ_216580* self, void* ev);
}
static inline void* At_216580(Rel_216580* r, unsigned int i) { return r->c[i]; }
static inline int IsAuth_216580(void) { return g_IsMultiplayer ? D_005721C0 : 1; }
static inline int ObjId_216580(Obj_216580* o) { return o ? o->id : 0; }
static inline void Free_216580(Msg_216580* p, int line)
{
    AllocGuard g;
    p->Destroy(-1);
    cMemMan_Deallocate(0, p, D_004A4550, line);
}
extern "C" int cInteractGOBJ_HandleMessage(cInteractGOBJ_216580* self, In_216580* m)
{
    int t = *cMessage_Name(m);
    if (t == g_TriggerMsgKey) {
        if (!self->xBC) {
            int id = m->id;
            Obj_216580* o = nGobjManager_LookupGOBJ_cObjectIdR(&id);
            int k = m->kind;
            if (o) {
                switch (k) {
                case 7:
                    cInteractGOBJ_HandleBuddyClimb(self, m);
                    break;
                case 3:
                case 2:
                    break;
                default:
                    nCAS_PerformAction_WithObject_cSystemP_eAction_cGOBJP_float_etc(o, 0x25, self, 0, -1.0f);
                    self->xBC = ((Msg_216580*)m)->Clone();
                    break;
                }
            }
        }
        return 1;
    }
    t = *cMessage_Name(m);
    if (t == g_CasEventMsgClass) {
        In2_216580* m2 = (In2_216580*)m;
        switch (m2->kind) {
        case 14:
            if (self->xBC) {
                int i;
                for (i = 0; i < self->x98.n; i++)
                    QueueMessage_cMessageR_cSystemP_int(self->xBC, At_216580(&self->x98, i), 0);
                Free_216580(self->xBC, 0x4ED);
                self->xBC = 0;
            }
            break;
        case 13: {
            Obj_216580* who;
            int i;
            if (self->xBC) {
                Free_216580(self->xBC, 0x4F7);
                self->xBC = 0;
            }
            who = m2->who;
            self->xB0 = 0;
            for (i = 0; i < 2; i++) {
                Obj_216580* r = self->riders[i];
                if (r && r != who)
                    func_003E6690(r, 1);
                self->riders[i] = 0;
            }
            if (IsAuth_216580()) {
                LiftMsg_216580 msg;
                Obj_216580* w = m2->who;
                LiftMsg_216580* p = &msg;
                cMessage_ctor_cMessageNameR(p, &g_TriggerMsgKey);
                msg.floor = 0;
                msg.vtable = D_004DAF10;
                msg.kind = 3;
                p->to = ObjId_216580(w);
                p->from = ObjId_216580(0);
                msg.b20 = 1;
                QueueMessage_cMessageR_cSystemP_int(&msg, self, 0);
                msg.vtable = D_004DAF10;
                cMessage_dtor(&msg, 0);
            }
            break;
        }
        case 15: {
            Obj_216580* who;
            unsigned char any;
            int i;
            if (self->xBC) {
                Free_216580(self->xBC, 0x526);
                self->xBC = 0;
            }
            who = m2->who;
            any = 0;
            for (i = 0; i < 2; i++) {
                Obj_216580* r = self->riders[i];
                if (r == who)
                    self->riders[i] = 0;
                else if (r)
                    any = 1;
            }
            if (!any)
                self->xB0 = 0;
            if (IsAuth_216580()) {
                LiftMsg_216580 msg;
                Obj_216580* w = m2->who;
                LiftMsg_216580* p = &msg;
                cMessage_ctor_cMessageNameR(p, &g_TriggerMsgKey);
                msg.floor = 0;
                msg.vtable = D_004DAF10;
                msg.kind = 2;
                p->to = ObjId_216580(w);
                p->from = ObjId_216580(0);
                msg.b20 = 1;
                QueueMessage_cMessageR_cSystemP_int(&msg, self, 0);
                msg.vtable = D_004DAF10;
                cMessage_dtor(&msg, 0);
            }
            break;
        }
        }
        return 1;
    }
    return cGOBJ_HandleMessage(self, m);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00216580(void) {}
#undef nGobjManager_LookupGOBJ_cObjectIdR /* merge_units */
#undef nCAS_PerformAction_WithObject_cSystemP_eAction_cGOBJP_float_etc /* merge_units */
#undef cInteractGOBJ_HandleBuddyClimb /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00216580 */

/* merge_units: begin func_00216AE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_strength_reduction off
struct Obj_00216AE0 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v3A(); virtual void v3B();
    virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F();
    virtual void v40(); virtual void v41();
    virtual void Activate(int on); /* +0x110 */
    char pad[0x64];
    int x68;
};
struct Rel_00216AE0 { int a; int b; Obj_00216AE0** c; Obj_00216AE0*& at(int i) { return c[i]; } };
struct RelFlag_00216AE0 { Rel_00216AE0 rel; unsigned char flag; };
struct cInteractGOBJ_00216AE0 {
    void* vtable;
    char pad04[0x64];
    int x68;
    char pad6C[4];
    int x70;
    Rel_00216AE0 x74;
    char pad80[0x14];
    unsigned char x94;
    char pad95[3];
    RelFlag_00216AE0 x98;
    Obj_00216AE0* xA8;
    Obj_00216AE0* xAC;
    unsigned char xB0;
    char padB1[3];
    int xB4;
    int xB8;
    int xBC;
};
extern "C" {
extern void cGameGOBJ_ctor(cInteractGOBJ_00216AE0* self, void* a1, void* a2, int kind);
#if 0 /* merge_units */
extern Rel_00216AE0* std_vector_cGameGOBJPtr_ctor(Rel_00216AE0* r);
#endif /* merge_units */
#define std_vector_cGameGOBJPtr_ctor(a0) ((Rel_00216AE0 *)std_vector_cGameGOBJPtr_ctor((Rel *)(a0))) /* merge_units */

extern void std_vector_pod_int_resize(Rel_00216AE0* v, int n, int* fill);
extern char D_004DB160[];
cInteractGOBJ_00216AE0* cInteractGOBJ_ctor(cInteractGOBJ_00216AE0* self, void* a1, void* a2);
}
cInteractGOBJ_00216AE0* cInteractGOBJ_ctor(cInteractGOBJ_00216AE0* self, void* a1, void* a2)
{
    int i;
    cGameGOBJ_ctor(self, a1, a2, 5);
    self->vtable = D_004DB160;
    {
        RelFlag_00216AE0* rf = &self->x98;
        std_vector_cGameGOBJPtr_ctor(&rf->rel);
        rf->flag = 1;
    }
    if (self->x70) {
        {
            int fill = 0;
            std_vector_pod_int_resize(&self->x98.rel, self->x70 - 2, &fill);
        }
        self->xA8 = self->x74.at(self->x70 - 2);
        self->xAC = self->x74.at(self->x70 - 1);
        self->x70 -= 2;
        for (i = 0; i < self->x70; i++) {
            self->x98.rel.c[i] = self->x74.c[i];
            self->x98.rel.c[i]->Activate(0);
            if (self->x98.rel.c[i]->x68 == 3) {
                self->x68 = 7;
            }
        }
        {
            int fill = 0;
            std_vector_pod_int_resize(&self->x74, 0, &fill);
        }
        self->x70 = 0;
    }
    self->xBC = 0;
    self->xB0 = 0;
    self->x94 = 0;
    self->xB4 = 0;
    self->xB8 = 0;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00216AE0(void) {}
#undef std_vector_cGameGOBJPtr_ctor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00216AE0 */

/* merge_units: begin func_00216C50 */
#pragma push /* merge_units */
/* Sets the word at +0x6C. */
void cGameGOBJ_SetParent(char* self, int value) {
    *(int*)(self + 0x6C) = value;
}
static inline void merge_flush_func_00216C50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00216C50 */

/* merge_units: begin func_00216C60 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
#include "sound_event.h"
#pragma inline_depth(8)
#pragma opt_propagation off

struct Qt { float x, y, z, w; } __attribute__((aligned(16)));

struct V {
    float x, y, z, w;
    V() {}
    /* empty asm barrier: keeps a dead zero register (retail daddu v0,zero,zero after the copy) */
    V(const V& o) { const __int128* s = (const __int128*)&o; __int128* d = (__int128*)this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; int z = 0; __asm__ volatile("" : "+r"(z)); }
    V& operator=(const V& o) { __int128* d = (__int128*)this; const __int128* s = (const __int128*)&o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; return *this; }
    V operator*(float k) const { V r; V* rp = &r; const V* tp = this; __int128 t = 0; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%1); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%2); .set reorder" : "+r"(t) : "r"(tp), "r"(rp), "f"(k) : "memory"); return r; }
    V& operator-=(const V& o) { V* tp = this; const V* op = &o; __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(tp), "r"(op) : "memory"); return *this; }
    V& operator+=(const V& o) { V* d = this; V* a = this; const V* b = &o; __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%2)" : : "r"(a), "r"(b), "r"(d) : "memory"); return *this; }
} __attribute__((aligned(16)));

static inline void CopyM(void* dd, const void* ss) { void* d = dd; __int128 qa, qb; const void* s = ss; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
struct M {
    V r0, r1, r2, r3;
    M() {}
    M(const M& o) { CopyM(this, &o); }
    M(const Qt& q)
    {
        M* m = this;
        const Qt* qp = &q;
        __asm__ volatile(
            "lqc2 $vf1, 0x0(%1); vadd.xyzw $vf2, $vf1, $vf1; vaddw.xyz $vf3, $vf0, $vf0w; vmulx.w $vf8, $vf0, $vf0x; vmulx.w $vf9, $vf0, $vf0x;"
            "vmuly.xyzw $vf5, $vf1, $vf2y; vmulz.xyzw $vf6, $vf1, $vf2z; vmulx.xyzw $vf4, $vf1, $vf2x; vmulx.w $vf10, $vf0, $vf0x;"
            "vsubay.x $ACC, $vf3, $vf5y; vmsubz.x $vf8, $vf3, $vf6z; vsubw.x $vf9, $vf5, $vf6w; vaddw.x $vf10, $vf6, $vf5w;"
            "vaddw.y $vf8, $vf4, $vf6w; vsubax.y $ACC, $vf3, $vf4x; vmsubz.y $vf9, $vf3, $vf6z; vsubw.y $vf10, $vf6, $vf4w;"
            "vsubw.z $vf8, $vf4, $vf5w; vaddw.z $vf9, $vf5, $vf4w; vsubax.z $ACC, $vf3, $vf4x; vmsuby.z $vf10, $vf3, $vf5y;"
            "sqc2 $vf0, 0x30(%0); sqc2 $vf8, 0x0(%0); sqc2 $vf9, 0x10(%0); sqc2 $vf10, 0x20(%0)"
            : : "r"(m), "r"(qp) : "memory");
    }
    float* f() { return (float*)this; }
    const float* f() const { return (const float*)this; }
};

struct Plc : M {
    Plc(const M& m, const V& pos)
    {
        r0.x = m.r0.x; r0.y = m.r0.y; r0.z = m.r0.z;
        r1.x = m.r1.x; r1.y = m.r1.y; r1.z = m.r1.z;
        r2.x = m.r2.x; r2.y = m.r2.y; r2.z = m.r2.z;
        r0.w = m.r0.w; r1.w = m.r1.w; r2.w = m.r2.w;
        r3 = pos;
    }
};

static inline M MMul(M& a, M& b) { M r; M* rp = &r; M* bp = &b; M* ap = &a; __asm__ volatile("lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); lqc2 $vf8, 0x0(%2); lqc2 $vf9, 0x10(%2); lqc2 $vf10, 0x20(%2); lqc2 $vf11, 0x30(%2); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; vmulax.xyzw $ACC, $vf4, $vf9x; vmadday.xyzw $ACC, $vf5, $vf9y; vmaddaz.xyzw $ACC, $vf6, $vf9z; vmaddw.xyzw $vf13, $vf7, $vf9w; vmulax.xyzw $ACC, $vf4, $vf10x; vmadday.xyzw $ACC, $vf5, $vf10y; vmaddaz.xyzw $ACC, $vf6, $vf10z; vmaddw.xyzw $vf14, $vf7, $vf10w; vmulax.xyzw $ACC, $vf4, $vf11x; vmadday.xyzw $ACC, $vf5, $vf11y; vmaddaz.xyzw $ACC, $vf6, $vf11z; vmaddw.xyzw $vf15, $vf7, $vf11w; sqc2 $vf12, 0x0(%0); sqc2 $vf13, 0x10(%0); sqc2 $vf14, 0x20(%0); sqc2 $vf15, 0x30(%0)" : : "r"(rp), "r"(ap), "r"(bp) : "memory"); return r; }

struct Src_00216C60 {
    VPAD16(a) VPAD4(b)
    virtual void Refresh();
    char pad4[0xC];
    M xform;
    unsigned char dirty;
    M* Xform() { if (dirty) Refresh(); return &xform; }
};

struct Kid { char pad0[0x49]; unsigned char type; };
struct Cursor { int cur; int dir; };
struct Arr { int a; int n; int c; int d; int Size() { return n; } };

struct PathObj {
    VPAD32(a) VPAD2(b) VPAD1(c)
    virtual void SetPlacementI(M* p);
    VPAD4(d) VPAD1(e)
    virtual void SetPlacement(M* p);
    char pad4[0x4C];
    Src_00216C60* src;
    char pad54[0x1C];
    int nKids;
    char pad74[8];
    Kid** kids;
    char pad80[0x18];
    int nPts;
    char pad9C[8];
    Arr rots;
    Arr segs;
    float delay;
    float wait;
    int stopAt;
    Cursor* cur;
    float speed;
    int mode;
    unsigned char done;
    char padDD[3];
    float t;
    void* snd;
};

extern "C" {
extern char g_Game[];
extern char D_004DAE30[];
#if 0 /* merge_units */
extern char g_TriggerMsgKey[];
#endif /* merge_units */
#define g_TriggerMsgKey ((char*)&g_TriggerMsgKey) /* merge_units */

extern char D_004F5450[];
extern char D_004DAE90[];
void cGOBJ_NextFrame(PathObj* o, float dt);
void PathObj_GetPoint(PathObj* o, V* out, int i);
void cMatrix_Copy_InvertRotTrans(M* out, M* in);
Qt* func_002181C0(Arr* v, int i);
int func_002181D0(Arr* v);
float* func_002181E0(Arr* v, int i);
int func_002181F0(Arr* v);
void cPathedGOBJ_TransformAttached(PathObj* o, M m, int f);
M cPathedGOBJ_GetAdjustedRot(PathObj* o, int a, int b, float t);
}

static inline int ObjId(Kid* o) { return o ? *(int*)((char*)o + 0xC) : 0; }

struct LiftMsg {
    CMSG_HEADER;
    int mkind;
    int floor;
    int from;
    int to;
    char pad34[4];
    LiftMsg(int k, int f)
    {
        LiftMsg* p = this;
        cMessage_ctor_cMessageNameR(p, g_TriggerMsgKey);
        p->vtable = D_004DAF10;
        p->mkind = k;
        p->floor = f;
        p->to = ObjId(0);
        p->from = ObjId(0);
    }
    void Send(void* to) { QueueMessage_cMessageR_cSystemP_int(this, to, 0); }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~LiftMsg() { vtable = D_004DAF10; cMessage_dtor(this, 0); }
};

struct Notice_00216C60 {
    CMSG_HEADER;
    int nkind;
    int arg;
    char pad2C[4];
    Notice_00216C60(int k, int a) { Notice_00216C60* p = this; cMessage_ctor_cMessageNameR(p, D_004F5450); p->vtable = D_004DAE90; p->nkind = k; p->arg = a; }
    Notice_00216C60(Cursor* c) { Notice_00216C60* p = this; int a = c->cur; cMessage_ctor_cMessageNameR(p, D_004F5450); p->vtable = D_004DAE90; p->nkind = 0; p->arg = a; }
    void Send(void* to) { QueueMessage_cMessageR_cSystemP_int(this, to, 0); }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Notice_00216C60() { vtable = D_004DAE90; cMessage_dtor(this, 0); }
};

static inline void Notify(PathObj* o, int kind, int arg) { Notice_00216C60 n(o->cur); n.Send(o); }

static inline int Clamp0(int i) { if (i < 0) i = 0; return i; }
static inline Qt* RotAt(PathObj* o, int idx)
{
    int i = Clamp0(idx);
    Qt* q;
    if (i < func_002181D0(&o->rots)) q = func_002181C0(&o->rots, i);
    else q = func_002181C0(&o->rots, func_002181D0(&o->rots) - 1);
    return q;
}
static inline float* SegAt(PathObj* o, int idx)
{
    int i = Clamp0(idx);
    float* q;
    if (i < func_002181F0(&o->segs)) q = func_002181E0(&o->segs, i);
    else q = func_002181E0(&o->segs, func_002181F0(&o->segs) - 1);
    return q;
}

extern "C" void cPathedGOBJ_NextFrame(PathObj* self, float dt)
{
    if (self->done || !self->nPts) {
        cGOBJ_NextFrame(self, dt);
        return;
    }
    if (self->wait > 0.0f) {
        self->wait -= dt;
        if (self->wait > 0.0f) return;
        if (self->snd) {
            SoundEventP ev;
            cPlaySoundMsg_ctor_cSndFxR(&ev, self->snd, self);
            ev.kind = 1;
            QueueMessage_cMessageR_cSystemP_int(&ev, g_Game, 1);
            ev.vtable = D_004DAE30;
            cFileMan_dtor(&ev.req.b, -1);
            cFileMan_dtor(&ev.req.a, -1);
            cMessage_dtor(&ev, 0);
        }
        for (int i = 0; i < self->nKids; i++) {
            if (self->kids[i]->type == 0xB) LiftMsg(0, 0).Send(self->kids[i]);
        }
    }
    float seg;
    if (self->cur->dir == 1) {
        seg = *SegAt(self, self->cur->cur);
    } else {
        if (self->cur->cur == -1) self->cur->cur = 0;
        if (self->cur->dir == -1 && self->cur->cur == 0) self->cur->dir = 0;
        if (self->cur->cur == self->segs.Size() && self->cur->dir == 1) self->cur->dir = 0;
        if (self->cur->cur >= self->segs.Size()) self->cur->cur = self->segs.Size() - 1;
        seg = *SegAt(self, self->cur->cur + self->cur->dir);
    }
    self->t += self->speed * dt / seg;
    if (self->t > 1.0f) self->t = 1.0f;
    V p0;
    PathObj_GetPoint(self, &p0, self->cur->cur);
    V p1;
    PathObj_GetPoint(self, &p1, self->cur->cur + self->cur->dir);
    p1 -= p0;
    V delta = p1 * self->t;
    if (self->t == 1.0f) {
        self->cur->cur += self->cur->dir;
        Notice_00216C60(2, self->cur->cur).Send(self);
        if (self->cur->cur == self->stopAt) {
            M inv;
            cMatrix_Copy_InvertRotTrans(&inv, self->src->Xform());
            V pt;
            PathObj_GetPoint(self, &pt, self->stopAt);
            Plc p(M(*RotAt(self, self->stopAt)), pt);
            self->SetPlacement(&p);
            cPathedGOBJ_TransformAttached(self, MMul(p, inv), 1);
            self->done = 1;
            Notify(self, 0, self->cur->cur);
            self->stopAt = -1;
            self->t = 0.0f;
        } else {
            self->t = 0.0f;
            int c = self->cur->cur;
            c = (c < self->rots.Size()) ? c : self->rots.Size() - 1;
            switch (self->mode) {
            case 1:
                if (self->cur->cur >= self->nPts - 1) {
                    self->done = 1;
                    Notify(self, 0, self->cur->cur);
                    self->wait = 0.0f;
                    self->cur->dir = -1;
                    self->cur->cur = self->nPts - 1;
                    M inv;
                    cMatrix_Copy_InvertRotTrans(&inv, self->src->Xform());
                    V pt;
                    PathObj_GetPoint(self, &pt, self->cur->cur);
                    Plc p(M(*RotAt(self, c)), pt);
                    self->SetPlacement(&p);
                    cPathedGOBJ_TransformAttached(self, MMul(p, inv), 1);
                } else if (self->cur->cur <= 0) {
                    M inv;
                    cMatrix_Copy_InvertRotTrans(&inv, self->src->Xform());
                    V pt;
                    PathObj_GetPoint(self, &pt, 0);
                    Plc p(M(*RotAt(self, 0)), pt);
                    self->SetPlacement(&p);
                    cPathedGOBJ_TransformAttached(self, MMul(p, inv), 1);
                    self->done = 1;
                    Notify(self, 0, self->cur->cur);
                    self->wait = 0.0f;
                    self->cur->dir = 1;
                    self->cur->cur = 0;
                }
                break;
            case 2:
                if (self->cur->cur >= self->nPts - 1) {
                    self->cur->cur = 0;
                    self->wait = self->delay;
                    M inv;
                    cMatrix_Copy_InvertRotTrans(&inv, self->src->Xform());
                    V pt;
                    PathObj_GetPoint(self, &pt, self->cur->cur);
                    Plc p(M(*RotAt(self, c)), pt);
                    self->SetPlacement(&p);
                    cPathedGOBJ_TransformAttached(self, MMul(p, inv), 1);
                }
                break;
            case 3:
                if (self->cur->cur >= self->nPts - 1) {
                    self->wait = self->delay;
                    self->cur->dir = -1;
                    self->cur->cur = self->nPts - 1;
                } else if (self->cur->cur <= 0) {
                    V pt;
                    PathObj_GetPoint(self, &pt, 0);
                    M p(*RotAt(self, 0));
                    p.r3 = pt;
                    self->SetPlacement(&p);
                    self->done = 1;
                    Notify(self, 0, self->cur->cur);
                    self->t = 1.0f;
                    self->wait = 0.0f;
                    self->cur->dir = 1;
                    self->cur->cur = 0;
                }
                break;
            case 4: {
                M inv;
                cMatrix_Copy_InvertRotTrans(&inv, self->src->Xform());
                V pt;
                PathObj_GetPoint(self, &pt, self->cur->cur);
                Plc p(M(*RotAt(self, c)), pt);
                self->SetPlacement(&p);
                cPathedGOBJ_TransformAttached(self, MMul(p, inv), 1);
                self->done = 1;
                Notify(self, 0, self->cur->cur);
                self->t = 1.0f;
                break;
            }
            }
        }
    } else {
        int next = self->cur->cur + self->cur->dir;
        V pt;
        PathObj_GetPoint(self, &pt, self->cur->cur);
        pt += delta;
        M inv;
        cMatrix_Copy_InvertRotTrans(&inv, self->src->Xform());
        Plc p(cPathedGOBJ_GetAdjustedRot(self, next, self->cur->cur, self->t), pt);
        self->SetPlacementI(&p);
        cPathedGOBJ_TransformAttached(self, MMul(p, inv), 0);
    }
    cGOBJ_NextFrame(self, dt);
}
#undef g_TriggerMsgKey /* merge_units */
static inline void merge_flush_func_00216C60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00216C60 */
