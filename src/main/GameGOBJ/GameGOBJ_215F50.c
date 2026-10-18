/*
 * main/GameGOBJ: range (4 files, 00215F50-00216AE0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_00215F50 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
extern char D_004DB040[];
extern char D_004A4550[];
extern unsigned char D_005721C8;
void func_002EC2A8(int a);
void** func_002151B0(void* v, int i);
void FileMan_Release(void* p, int flag);
void func_001736C0(void* p, int flag);
void func_0013A040(void* p, int flag);
void func_00145F10(void* p, int flag);
void func_00215E40(void* p, int flag);
void* cPathedGOBJ_dtor(void* p, int flag);
void operator_delete(void* p);
}
struct ElevSnd { char pad[0x48]; char a[0xE4 - 0x48]; char b[0x190 - 0xE4]; };
struct ElevHandle { char pad[0xC]; unsigned char c; char padD[0x1C - 0xD]; int h; };
struct cElevatorGOBJ {
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
static inline void Free_215F50(void* p, int line) { AllocGuard g; Mem_Free(0, p, D_004A4550, line); }
static inline void SndDtor(ElevSnd* s) { if (s) { FileMan_Release(s->b, -1); FileMan_Release(s->a, -1); } }
extern "C" cElevatorGOBJ* cElevatorGOBJ_dtor(cElevatorGOBJ* self, short flag)
{
    if (self) {
        int i;
        self->vt = D_004DB040;
        if (D_005721C8) {
            ElevHandle* d = self->p128;
            if (d) {
                if (d->c) func_002EC2A8(d->h);
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
            void* p = *func_002151B0(self->mF8, i);
            Free_215F50(p, 0x5D8);
            self->p100[i] = 0;
        }
        SndDtor(&self->snd[3]);
        SndDtor(&self->snd[2]);
        SndDtor(&self->snd[1]);
        SndDtor(&self->snd[0]);
        if (self->m118) func_001736C0(self->m118, -1);
        if (self->m108) func_0013A040(self->m108, -1);
        if (self->mF8) func_00145F10(self->mF8, -1);
        if (self->mE8) func_00215E40(self->mE8, -1);
        cPathedGOBJ_dtor(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00215F50(void) {}
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
extern Obj* Object_LookupById(int* id);
extern int ObjectAction_SendKind7(Obj* obj, int action, cInteractGOBJ* target, int arg, float time);
void cInteractGOBJ_BuddyClimbPairing(cInteractGOBJ* self, Notice* msg);
}
void cInteractGOBJ_BuddyClimbPairing(cInteractGOBJ* self, Notice* msg)
{
    int id;
    Obj* o;
    int i;
    float d0;
    float d1;
    if (self->xB0) return;
    id = msg->who;
    o = Object_LookupById(&id);
    if (self->riders[0] == o) {
        self->riders[0] = 0;
        if (self->x94) {
            ObjectAction_SendKind7(o, 0x36, self, 0, -1.0f);
        } else {
            ObjectAction_SendKind7(o, 0x32, self, 0, -1.0f);
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
            ObjectAction_SendKind7(o, 0x35, self, 0, -1.0f);
            return;
        } else {
            ObjectAction_SendKind7(o, 0x31, self, 0, -1.0f);
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
        ObjectAction_SendKind7(o, 0x38, self, 0, -1.0f);
        ObjectAction_SendKind7(self->riders[0], 0x37, self, 0, -1.0f);
        return;
    }
    if (self->x94) {
        ObjectAction_SendKind7(self->riders[0], 0x38, self, 0, -1.0f);
        ObjectAction_SendKind7(o, 0x37, self, 0, -1.0f);
        self->x94 = 0;
        return;
    }
    ObjectAction_SendKind7(o, 0x34, self, 0, -1.0f);
    ObjectAction_SendKind7(self->riders[0], 0x33, self, 0, -1.0f);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00216230(void) {}
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
extern int D_004F5440;
extern int D_0055A1D8;
extern char D_004DAF10[];
int* Event_GetType(void* ev);
void Event_Construct(void* m, void* type);
void Event_Send(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
#if 0 /* merge_units */
Obj_216580* Object_LookupById(int* id);
#endif /* merge_units */
#define Object_LookupById(a0) ((Obj_216580 *)Object_LookupById((a0))) /* merge_units */

#if 0 /* merge_units */
int ObjectAction_SendKind7(Obj_216580* obj, int action, cInteractGOBJ_216580* target, int arg, float time);
#endif /* merge_units */
#define ObjectAction_SendKind7(a0, a1, a2, a3, a4) (ObjectAction_SendKind7((Obj *)(a0), (a1), (cInteractGOBJ *)(a2), (a3), (a4))) /* merge_units */

#if 0 /* merge_units */
void cInteractGOBJ_BuddyClimbPairing(cInteractGOBJ_216580* self, In_216580* msg);
#endif /* merge_units */
#define cInteractGOBJ_BuddyClimbPairing(a0, a1) (cInteractGOBJ_BuddyClimbPairing((cInteractGOBJ *)(a0), (Notice *)(a1))) /* merge_units */

void func_003E6690(Obj_216580* o, int f);
int Object_HandleMessage(cInteractGOBJ_216580* self, void* ev);
}
static inline void* At_216580(Rel_216580* r, unsigned int i) { return r->c[i]; }
static inline int IsAuth_216580(void) { return D_005721C8 ? D_005721C0 : 1; }
static inline int ObjId_216580(Obj_216580* o) { return o ? o->id : 0; }
static inline void Free_216580(Msg_216580* p, int line)
{
    AllocGuard g;
    p->Destroy(-1);
    Mem_Free(0, p, D_004A4550, line);
}
extern "C" int cInteractGOBJ_v01(cInteractGOBJ_216580* self, In_216580* m)
{
    int t = *Event_GetType(m);
    if (t == D_004F5440) {
        if (!self->xBC) {
            int id = m->id;
            Obj_216580* o = Object_LookupById(&id);
            int k = m->kind;
            if (o) {
                switch (k) {
                case 7:
                    cInteractGOBJ_BuddyClimbPairing(self, m);
                    break;
                case 3:
                case 2:
                    break;
                default:
                    ObjectAction_SendKind7(o, 0x25, self, 0, -1.0f);
                    self->xBC = ((Msg_216580*)m)->Clone();
                    break;
                }
            }
        }
        return 1;
    }
    t = *Event_GetType(m);
    if (t == D_0055A1D8) {
        In2_216580* m2 = (In2_216580*)m;
        switch (m2->kind) {
        case 14:
            if (self->xBC) {
                int i;
                for (i = 0; i < self->x98.n; i++)
                    Event_Send(self->xBC, At_216580(&self->x98, i), 0);
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
                Event_Construct(p, &D_004F5440);
                msg.floor = 0;
                msg.vtable = D_004DAF10;
                msg.kind = 3;
                p->to = ObjId_216580(w);
                p->from = ObjId_216580(0);
                msg.b20 = 1;
                Event_Send(&msg, self, 0);
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
                Event_Construct(p, &D_004F5440);
                msg.floor = 0;
                msg.vtable = D_004DAF10;
                msg.kind = 2;
                p->to = ObjId_216580(w);
                p->from = ObjId_216580(0);
                msg.b20 = 1;
                Event_Send(&msg, self, 0);
                msg.vtable = D_004DAF10;
                cMessage_dtor(&msg, 0);
            }
            break;
        }
        }
        return 1;
    }
    return Object_HandleMessage(self, m);
}
#undef Object_LookupById /* merge_units */
#undef ObjectAction_SendKind7 /* merge_units */
#undef cInteractGOBJ_BuddyClimbPairing /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00216580(void) {}
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
struct RelFlag { Rel_00216AE0 rel; unsigned char flag; };
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
    RelFlag x98;
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
extern Rel_00216AE0* func_00215F30(Rel_00216AE0* r);
extern void PtrVector_Resize(Rel_00216AE0* v, int n, int* fill);
extern char D_004DB160[];
cInteractGOBJ_00216AE0* cInteractGOBJ_ctor(cInteractGOBJ_00216AE0* self, void* a1, void* a2);
}
cInteractGOBJ_00216AE0* cInteractGOBJ_ctor(cInteractGOBJ_00216AE0* self, void* a1, void* a2)
{
    int i;
    cGameGOBJ_ctor(self, a1, a2, 5);
    self->vtable = D_004DB160;
    {
        RelFlag* rf = &self->x98;
        func_00215F30(&rf->rel);
        rf->flag = 1;
    }
    if (self->x70) {
        {
            int fill = 0;
            PtrVector_Resize(&self->x98.rel, self->x70 - 2, &fill);
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
            PtrVector_Resize(&self->x74, 0, &fill);
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
#pragma pop /* merge_units */
/* merge_units: end func_00216AE0 */
