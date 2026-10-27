/*
 * SFOGame/Source/npc: 6 files, 00154650-00155350
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00154650 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc.
 */

#include "types.h"

int cGobjController_GetVelocity(void) {
    return 0;
}
static inline void merge_flush_func_00154650(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00154650 */

/* merge_units: begin func_00154660 */
#pragma push /* merge_units */
#pragma cplusplus on
struct M_00154660 { char pad[0x30]; char v[0x10]; M_00154660() {} char* Pos() { return v; } };
struct Brain_00154660 { char pad[0x5C]; int f5C; };
struct Ctl_00154660 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual int IsPlayer(); virtual int IsAi();
    char pad4[0x1B0 - 4]; Brain_00154660* p1B0;
};
struct Act_00154660 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual M_00154660 GetA(); virtual void v57(); virtual void v58(); virtual M_00154660 GetB();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual unsigned char GetState();
    char pad4[0x58 - 4]; Ctl_00154660* ctl;
};
struct Bits_00154660 { unsigned char lo : 6; unsigned char b6 : 1; unsigned char b7 : 1; };
struct Self_00154660 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64();
    virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
    virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74();
    virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
    virtual float GetF(int a); virtual void v81(); virtual void v82(); virtual void v83(); virtual void Reset();
    char pad4[0x2C]; int f30; char pad34[0x2C]; float f60; int f64; char pad68[0x80];
    int fE8; char padEC[8]; int fF4; char padF8[0x40]; int f138; char pad13C[5]; Bits_00154660 bits141;
    char pad142[0x1B0 - 0x142]; Brain_00154660* p1B0;
};
struct Ev_00154660 { char pad[0x24]; unsigned char b24; };
extern "C" {
extern int D_004EE550;
extern int D_004ED9B8;
extern char g_Game[];
extern char g_NpcRouteMgr[];
extern int g_NpcRegionTable[];
int* cMessage_Name(Ev_00154660* ev);
void* cSystemContainer_GetSystem(void* a, void* b);
void cPathSystem_ClearRequests(void* svc, int a);
void cPathNavigator_Request_int(Brain_00154660* b, int a);
Act_00154660* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
int cGOBJ_Team(Act_00154660* a);
int cAIPathData_GetGroupIndex(void* v, int z);
void cPathNavigator_Request_cVectorR_int(Brain_00154660* b, void* v, int z);
}
extern "C" unsigned char cNPC_ScriptControl(Self_00154660* self, Ev_00154660* ev)
{
    unsigned char handled = 0;
    int t = *cMessage_Name(ev);
    if (t == D_004EE550) {
        if (ev->b24 == 0) {
            float f;
            cPathSystem_ClearRequests(cSystemContainer_GetSystem(g_Game, g_NpcRouteMgr), self->f30);
            if (self->f138 >= 0) {
                cPathNavigator_Request_int(self->p1B0, self->f138);
            } else if (self->fF4 != -1) {
                int id[1];
                Act_00154660* a;
                id[0] = self->fF4;
                a = nGobjManager_LookupGOBJ_cObjectIdR(id);
                if (a && (unsigned char)a->GetState() == 3) {
                    int z;
                    unsigned char r = 0;
                    Ctl_00154660* c = a->ctl;
                    if (c && c->IsPlayer())
                        r = 1;
                    if (r) {
                        z = g_NpcRegionTable[cGOBJ_Team(a)];
                    } else if (a->ctl && a->ctl->IsAi()) {
                        z = a->ctl->p1B0->f5C;
                    } else {
                        z = self->p1B0->f5C;
                        z = cAIPathData_GetGroupIndex(a->GetA().Pos(), z);
                    }
                    cPathNavigator_Request_cVectorR_int(self->p1B0, a->GetB().Pos(), z);
                    self->fE8 = -1;
                }
            }
            f = self->GetF(2);
            if (self->f64 < 11) {
                self->f60 = f;
                self->f64 = 10;
                self->bits141.b6 = 0;
            }
            handled = 1;
        } else if (ev->b24 == 1) {
            if (self->f64 < 11)
                self->f64 = 10;
            handled = 1;
        }
    } else {
        int t2 = *cMessage_Name(ev);
        if (t2 == D_004ED9B8) {
        if (ev->b24 == 2)
            self->Reset();
        }
    }
    return handled;
}
static inline void merge_flush_func_00154660(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00154660 */

/* merge_units: begin func_001548F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
#include "vslot_pad.h"
/* cNPC_Flee: flee-mode message handler - start a node search away from the current position,
   retarget on hits, and resume the flee timer. */
struct V4 { __int128 q; V4() {} };
struct Mat { V4 r[4]; Mat() {} };
struct GObj {
    VPAD32(a) VPAD16(b) VPAD8(c) VPAD2(d) VPAD1(e)
    virtual Mat GetMatrix();
};
struct Bits20 { unsigned char b0 : 1; unsigned char b1 : 1; unsigned char b2 : 1; unsigned char hi : 5; };
struct Obj_548F0 { char pad0[0xC]; int serial; };
struct Hdl_548F0 { Obj_548F0* obj; int serial; };
struct Target_548F0 { V4 pos; char pad10[0x10]; Bits20 bits20; char pad21[0x40 - 0x21]; Hdl_548F0 h; };
struct Self_548F0 {
    VPAD16(a) VPAD8(b) VPAD2(c) virtual int CanSee(Obj_548F0* o);
    VPAD8(d) VPAD4(e) virtual int Busy();
    VPAD4(f) VPAD1(g) virtual void SetMovement(int a, int b);
    VPAD16(h) VPAD8(i) VPAD2(j) virtual void Attack(Obj_548F0* o, int a, float t);
    char pad4[0x2C];
    GObj* obj;              /* 0x30 */
    char pad34[0xE0 - 0x34];
    int fE0;                /* 0xE0 */
    int fE4;                /* 0xE4 */
    int fE8;                /* 0xE8 */
    char padEC[0x13F - 0xEC];
    unsigned char f13F;     /* 0x13F */
    char pad140[0x1AC - 0x140];
    Target_548F0* target;   /* 0x1AC */
    int f1B0;               /* 0x1B0 */
};
struct Ev_548F0 { char pad[0x24]; signed char kind; char pad25[3]; int f28; };
extern "C" {
#if 0 /* merge_units */
int* cMessage_Name(Ev_548F0* ev);
#endif /* merge_units */
#define cMessage_Name(a0) (cMessage_Name((Ev_00154660 *)(a0))) /* merge_units */

int cPathSystem_IsRequestBeingProcessed(void* svc, GObj* id);
int cPathNavigator_GetGroupIndexForPatrolPath(int r);
unsigned char cPathSystem_RequestNodeIndexFromGroup(float d, void* svc, GObj* obj, void* e0, V4* pos, V4* tgt, int reg, int n, int k, long m);
void cNodePickerParameters_ctor_float_float_bool(float a, float b, void* out, int k);
unsigned char cNPC_Flee(Self_548F0* self, Ev_548F0* ev);
}

/* quadword copy (lq/sq), the retail V4 copy */
static inline void QC(void* d0, const void* s0) { void* d = d0; __int128 t; const void* s = s0; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
/* target position, or an explicit override point (always null here: retail keeps the dead
   `bnez zero` arm) */
static inline void CopyOr(V4* d, Self_548F0* self, V4* a) { if (!a) QC(d, &self->target->pos); else QC(d, a); }
static inline bool Reached(Target_548F0* t) { bool r = false; if (t->bits20.b0) { unsigned char b = t->bits20.b2; if (b) r = true; } return r; }
static inline int IsNullNV(void* p) { return (p != 0) ^ 1; }
static inline int DiffNV(int a, int b) { return a ^ b; }
static inline int SameNV(int a, int b) { return (unsigned)DiffNV(a, b) < 1; }
static inline Obj_548F0* Get(Target_548F0* t)
{
    unsigned char ok = 1;
    if (!IsNullNV(t->h.obj) && !SameNV(t->h.obj->serial, t->h.serial))
        ok = 0;
    { unsigned char k = ok; return k ? t->h.obj : 0; }
}
static inline void Run(Self_548F0* self, void* svc, char* e0)
{
    V4 pos;
    V4 tgt;
    GObj* o;
    { Mat m = self->obj->GetMatrix(); Mat* pm = &m; QC(&pos, &pm->r[3]); }
    CopyOr(&tgt, self, (V4*)0);
    o = self->obj;
    cPathSystem_RequestNodeIndexFromGroup(10000.0f, svc, o, e0, &pos, &tgt, cPathNavigator_GetGroupIndexForPatrolPath(self->f1B0), 6, 2, -1);
}
static inline void Search(Self_548F0* self, void* svc)
{
    char e0[0x10];
    cNodePickerParameters_ctor_float_float_bool(0.0f, -10000.0f, e0, 0);
    Run(self, svc, e0);
    self->f13F = 2;
}

unsigned char cNPC_Flee(Self_548F0* self, Ev_548F0* ev)
{
    unsigned char handled = 0;
    int t = *cMessage_Name(ev);
    if (t == D_004EE550) {
        if ((unsigned char)ev->kind == 3) {
            if (!(unsigned char)self->Busy() && Reached(self->target)) {
                void* svc = cSystemContainer_GetSystem(g_Game, g_NpcRouteMgr);
                if (!cPathSystem_IsRequestBeingProcessed(svc, self->obj))
                    Search(self, svc);
            }
            self->fE8 = 60;
        } else if ((unsigned char)ev->kind == 0) {
            void* svc;
            self->fE8 = 60;
            self->SetMovement(0, 20);
            self->fE0 = -1;
            self->fE4 = -1;
            svc = cSystemContainer_GetSystem(g_Game, g_NpcRouteMgr);
            if (!cPathSystem_IsRequestBeingProcessed(svc, self->obj))
                Search(self, svc);
            handled = 1;
        } else if ((unsigned char)ev->kind == 1) {
            self->SetMovement(1, 20);
        }
    } else {
      int t2 = *cMessage_Name(ev);
      if (t2 == D_004ED9B8) {
        if ((unsigned char)ev->kind == 7) {
            if (ev->f28 == 10 && Get(self->target) && self->CanSee(Get(self->target)) && !Reached(self->target))
                self->Attack(Get(self->target), 0, 1.0f);
        } else if ((unsigned char)ev->kind == 6) {
            self->fE8 = 1;
        }
      }
    }
    return handled;
}
#undef cMessage_Name /* merge_units */
static inline void merge_flush_func_001548F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001548F0 */

/* merge_units: begin func_00154DD0 */
#pragma push /* merge_units */
/* cNPC_SearchLook: search-mode message handler (look around, walk the search route, resume) */
#pragma cplusplus on
struct Bits60 { unsigned char b0 : 1; unsigned char b1 : 1; unsigned char b2 : 1; unsigned char b3 : 1; unsigned char hi : 4; };
struct Route_S { char pad[0x4C]; int f4C; char pad50[0xC]; int f5C; Bits60 bits60; };
struct Target_S { char pad[0x18]; int f18; char pad1C[4]; Bits60 bits20; };
struct Obj_S { char pad[0x4C]; int f4C; };
struct Slot_S { int f0; unsigned char b4; char pad5[0xF]; };
struct Self_S {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64();
    virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
    virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74();
    virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
    virtual void v80(); virtual void v81(); virtual void v82(); virtual void LookFor(float t, int n); virtual void Resume();
    char pad4[0x2C]; int f30; char pad34[0x10]; char brain[0x28]; float aggression; char pad70[0x30];
    int fA0; char padA4[0x18]; int bitsBC[8]; int fDC_pad; int fE0; int fE4; int fE8; int fEC;
    char padF0[0x68]; unsigned char b158; char pad159[7]; int f160; unsigned char b164; char pad165;
    unsigned char b166; char pad167; unsigned char b168; char pad169[0xF]; Slot_S slots[1];
    char padSlots[0x1AC - 0x178 - 0x14]; Target_S* target; Route_S* route; char pad1B4[0x1C]; Obj_S* facing;
};
struct Ev_S { char pad[0x24]; unsigned char kind; char pad25[3]; int f28; };
extern "C" {
extern int D_004EA770;
#if 0 /* merge_units */
int* cMessage_Name(Ev_S* ev);
#endif /* merge_units */
#define cMessage_Name(a0) (cMessage_Name((Ev_00154660 *)(a0))) /* merge_units */

#if 0 /* merge_units */
int cPathSystem_IsRequestBeingProcessed(void* svc, int id);
#endif /* merge_units */
#define cPathSystem_IsRequestBeingProcessed(a0, a1) (cPathSystem_IsRequestBeingProcessed((a0), (GObj *)(a1))) /* merge_units */

#if 0 /* merge_units */
void cPathNavigator_Request_cVectorR_int(Route_S* r, Target_S* t, int node);
#endif /* merge_units */
#define cPathNavigator_Request_cVectorR_int(a0, a1, a2) (cPathNavigator_Request_cVectorR_int((Brain_00154660 *)(a0), (void *)(a1), (a2))) /* merge_units */

void cNPC_MoveToAttackNode(Self_S* self);
void cStateMachine_ChangeState(void* brain, int mode, int arg);
void cNPC_SetMoveMode(Self_S* self, int a, int b);
Obj_S* cNPC_GetMostDenseLookAtGobj(Self_S* self);
void cNPC_NewLookAtList(Self_S* self, int a, int b, int c);
void cNPC_AddLinkedNodesToLookAt(Self_S* self, int node, int a, int b, float t);
}

static inline bool Idle(Self_S* self) { return !self->b166; }
static inline bool Reached_00154DD0(Target_S* t) { return t->bits20.b0 && t->bits20.b2; }
static inline bool Visited(Self_S* self, int i)
{
    bool r = 1;
    if (i >= 0)
        r = (self->bitsBC[i / 32] >> (i & 31)) & 1;
    return r;
}

extern "C" unsigned char cNPC_SearchLook(Self_S* self, Ev_S* ev)
{
    unsigned char handled = 0;
    int t = *cMessage_Name(ev);
    if (t == D_004EE550) {
        unsigned char k = ev->kind;
        if (k == 3) {
            if (self->fEC == 2) {
                self->fE8 = 1;
                if (Idle(self)) {
                    self->fEC = 0;
                    self->fE8 = -1;
                    if (self->fA0 < 100) {
                        if (self->route->bits60.b3) {
                            Obj_S* o;
                            self->facing = 0;
                            o = cNPC_GetMostDenseLookAtGobj(self);
                            if (o && o->f4C == D_004EA770)
                                self->facing = o;
                            cStateMachine_ChangeState(self->brain, 0, 0);
                        } else {
                            self->Resume();
                        }
                    }
                }
            }
        } else if (k == 4) {
            if (Reached_00154DD0(self->target)) {
                cNPC_SetMoveMode(self, 0, 20);
                if (self->aggression < 0.9f)
                    cStateMachine_ChangeState(self->brain, 3, 0);
                else
                    cStateMachine_ChangeState(self->brain, 4, 0);
            }
        } else if (k == 7) {
            cStateMachine_ChangeState(self->brain, 1, 0);
        } else if (k == 0) {
            if (Reached_00154DD0(self->target)) {
                if (self->aggression < 0.9f)
                    cStateMachine_ChangeState(self->brain, 3, 0);
                else
                    cStateMachine_ChangeState(self->brain, 4, 0);
            } else {
                self->fE8 = -1;
                self->fEC = 0;
                self->fE0 = -1;
                self->fE4 = -1;
                if (self->route->f5C >= 0) {
                    int node;
                    Target_S* t = self->target;
                    node = t->f18;
                    if (Visited(self, node)) {
                        if (self->b158) {
                            void* svc = cSystemContainer_GetSystem(g_Game, g_NpcRouteMgr);
                            if (node >= 0 && !cPathSystem_IsRequestBeingProcessed(svc, self->f30))
                                cPathNavigator_Request_cVectorR_int(self->route, t, node);
                        }
                    } else {
                        cNPC_MoveToAttackNode(self);
                    }
                }
            }
            self->fEC = 0;
            handled = 1;
        } else if (k == 1) {
            if (self->fEC == 2) {
                if (self->slots[self->b164].f0 < 21) {
                    int* t = &self->slots[self->b164].f0;
                    if (*t < 21) { self->slots[self->b164].b4 = 0; *t = 0; }
                    self->b166 = 0;
                    self->f160 = 0;
                    if (self->b168)
                        self->Resume();
                }
            }
        }
    } else {
      int t2 = *cMessage_Name(ev);
      if (t2 == D_004ED9B8) {
        unsigned char k = ev->kind;
        if (k == 6) {
            self->fE8 = 1;
            self->fEC = 2;
            cNPC_NewLookAtList(self, 1, 1, 20);
            cNPC_AddLinkedNodesToLookAt(self, self->route->f5C, -1, -1, 3.0f);
        } else if (k == 5) {
            if (self->fEC == 1) {
                int n = self->route->f4C;
                if (n >= 0) {
                    self->fE8 = 1;
                    self->fEC = 2;
                    self->LookFor(10.0f, 10);
                    cNPC_NewLookAtList(self, 1, 1, 20);
                    cNPC_AddLinkedNodesToLookAt(self, self->route->f5C, n, -1, 2.0f);
                } else {
                    self->fEC = 0;
                }
            }
        } else if (k == 7) {
            if (ev->f28 == 10 && self->fEC == 0)
                self->fEC = 1;
        }
      }
    }
    return handled;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00154DD0(void) {}
#undef cMessage_Name /* merge_units */
#undef cPathSystem_IsRequestBeingProcessed /* merge_units */
#undef cPathNavigator_Request_cVectorR_int /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00154DD0 */

/* merge_units: begin func_001552B0 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; int serial; char pad10[0x3C]; int type; } Tgt_552B0;
typedef struct { Tgt_552B0* target; int serial; } Hdl_552B0;
typedef struct { char pad[0x40]; Hdl_552B0 h; } Ai_552B0;
typedef struct { char pad[0x158]; unsigned char f158; char pad159[0x53]; Ai_552B0* ai; } Npc_552B0;
extern int g_HumanActorClassKey;
extern Tgt_552B0* cSafePtr_cGOBJ_opCast_cGOBJPtr(Hdl_552B0* h);
unsigned char cNPC_SearchAvailable(Npc_552B0* self)
{
    unsigned char r = 1;
    unsigned char ok;
    int isNull;
    Tgt_552B0* t;
    Ai_552B0* ai;
    if (!self->f158)
        r = 0;
    ai = self->ai;
    t = ai->h.target;
    isNull = !t;
    ok = 1;
    if (!isNull)
        if (t->serial != ai->h.serial)
            ok = 0;
    if (ok ? t : 0) {
        Tgt_552B0* p = cSafePtr_cGOBJ_opCast_cGOBJPtr(&ai->h);
        if (p->type != g_HumanActorClassKey)
            r = 0;
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001552B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001552B0 */

/* merge_units: begin func_00155350 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
/* cNPC_Attack: attack-mode message handler - close in on / keep the target in range, approach
   or route to its node, ask for ammo, take cover on posture changes, and react to perception. */
/* quadword copy (lq/sq): a 128-bit move C cannot express, the retail vector copy */
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct V { float x, y, z, w; V() {} V(const V& o) { V* d = this; Q16(d, &o); } V& operator=(const V& o) { V* d = this; Q16(d, &o); return *this; } } __attribute__((aligned(16)));
struct M { V r[4]; V& T() { return r[3]; } } __attribute__((aligned(16)));
struct Ctl { VPAD16(a) VPAD2(b) VPAD1(c) virtual int IsHuman(); };
struct Obj { char pad0[0xC]; int serial; char pad10[0x48]; Ctl* ctrl; };
struct Ai {
    V pos;
    char pad10[8];
    int node;               /* 0x18 */
    char pad1C[4];
    unsigned char b0 : 1; unsigned char b1 : 1; unsigned char b2 : 1; unsigned char b3 : 1; unsigned char b4 : 1;
    char pad21[0x1F];
    Obj* obj;               /* 0x40 */
    int serial;             /* 0x44 */
    int IsValid() { unsigned char ok = 1; if (!IsNullNV(obj) && !SameNV(obj->serial, serial)) ok = 0; return ok; }
    Obj* Get() { return IsValid() ? obj : 0; }
};
struct Route { char pad0[0x50]; int f50; char pad54[8]; int node; };
struct PNode { char pad[0x7C]; int node; };
struct Inv { char pad[0xA0]; unsigned char bA0; };
struct GObj_00155350 { VPAD32(a) VPAD16(b) VPAD8(c) VPAD2(d) VPAD1(e) virtual M GetMatrix(); char pad4[0x3520]; Inv* inv; };
/* retail copies the posture pair as one word (sh/sh to a temp, then lw/sw) */
struct Pair { short a, b; Pair(short x, short y) { a = x; b = y; } Pair& operator=(const Pair& o) { *(int*)this = *(const int*)&o; return *this; } };
struct Npc {
    VPAD32(a) VPAD4(b) VPAD2(c) VPAD1(d) virtual int Busy();
    VPAD4(e) VPAD1(f) virtual void SetMovement(int a, int b);
    char pad4[0x2C];
    GObj_00155350* obj;              /* 0x30 */
    char pad34[0x10];
    char brain[0x60];       /* 0x44 */
    int clipMin;            /* 0xA4 */
    char padA8[0x14];
    int bitsBC[8];          /* 0xBC */
    char padDC[4];
    int fE0;                /* 0xE0 */
    int fE4;                /* 0xE4 */
    int fE8;                /* 0xE8 */
    int fEC;                /* 0xEC */
    char padF0[0x20];
    Pair pair;              /* 0x110 */
    char pad114[0x2B];
    unsigned char f13F;     /* 0x13F */
    char pad140[0x18];
    unsigned char b158;     /* 0x158 */
    char pad159[0x53];
    Ai* target;             /* 0x1AC */
    Route* route;           /* 0x1B0 */
};
struct Ev { char pad[0x24]; signed char kind; char pad25[3]; int f28; };
extern "C" {
extern char g_ActorActionMsgClass[], D_004E0840[];
#if 0 /* merge_units */
int* cMessage_Name(Ev* ev);
#endif /* merge_units */
#define cMessage_Name(a0) (cMessage_Name((Ev_00154660 *)(a0))) /* merge_units */

#if 0 /* merge_units */
int cPathSystem_IsRequestBeingProcessed(void* svc, GObj_00155350* id);
#endif /* merge_units */
#define cPathSystem_IsRequestBeingProcessed(a0, a1) (cPathSystem_IsRequestBeingProcessed((a0), (GObj *)(a1))) /* merge_units */

#if 0 /* merge_units */
void cPathNavigator_Request_cVectorR_int(Route* r, Ai* t, int node);
#endif /* merge_units */
#define cPathNavigator_Request_cVectorR_int(a0, a1, a2) (cPathNavigator_Request_cVectorR_int((Brain_00154660 *)(a0), (void *)(a1), (a2))) /* merge_units */

#if 0 /* merge_units */
void cNPC_MoveToAttackNode(Npc* self);
#endif /* merge_units */
#define cNPC_MoveToAttackNode(a0) (cNPC_MoveToAttackNode((Self_S *)(a0))) /* merge_units */

#if 0 /* merge_units */
void cNPC_SetMoveMode(Npc* self, int a, int b);
#endif /* merge_units */
#define cNPC_SetMoveMode(a0, a1, a2) (cNPC_SetMoveMode((Self_S *)(a0), (a1), (a2))) /* merge_units */

unsigned char cNPC_RecommendAIMode(Npc* self);
void cNPC_MoveToCoverNode(Npc* self);
int cWeapon_GetClipAmmo(Inv* inv, int slot);
PNode* cAIPathData_GetNode(int n);
void cMessage_ctor_cMessageNameR(void*, void*);
void QueueMessage_cMessageR_cSystemP_int(void*, void*, int);
void cMessage_dtor(void*, int);
unsigned char cNPC_Attack(Npc* self, Ev* ev);
}

#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX
struct MsgB {
    void* vtable; void* type; int pad8[5]; int flags; unsigned char kind; char pad21[3];
    MsgB(void* t) { cMessage_ctor_cMessageNameR(this, t); }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgB() { cMessage_dtor(this, 0); }
};
struct MsgI : MsgB {
    int id; unsigned char sub; char pad29[3];
    MsgI(int i, unsigned char s) : MsgB(g_ActorActionMsgClass) { vtable = D_004E0840; id = i; sub = s; }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgI() { vtable = D_004E0840; }
};

/* VU0 macro-mode vector ops (COP2), not expressible in C */
static inline void Sub(V* r, V* a, V* b) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
static inline float Len(V* a) { float r = 0.0f; int t; __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(a) : "memory"); return r; }
static inline float LenSq(V* a) { float r = 0.0f; int t; __asm__ volatile("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(a) : "memory"); return r; }
static inline void AskAmmo(Npc* self) { MsgI m(60, 0); QueueMessage_cMessageR_cSystemP_int(&m, self->obj, 0); }
static inline void QD(void* d0, const void* s0) { void* d = d0; __int128 q; const void* s = s0; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline bool OnPNode(Npc* self, PNode* pn) { int tn = self->target->node; return pn->node == tn; }
static inline bool OnNode2(Route* r, Ai* t) { int tn = t->node; return r->node == tn; }
static inline bool OnNode(Npc* self) { int tn = self->target->node; return self->route->node == tn; }
static inline unsigned char Engaged(Ai* ai) { unsigned char f = 0; if (ai->b0) { unsigned char b = ai->b2; if (b) f = 1; } return f; }
static inline bool Visited_00155350(Npc* self, int i) { bool r = 1; if (i >= 0) r = (self->bitsBC[i / 32] >> (i & 31)) & 1; return r; }
static inline void Offset(Npc* self, V* p) { { M m = self->obj->GetMatrix(); M* pm = &m; QD(p, &pm->r[3]); } Sub(p, p, &self->target->pos); }

unsigned char cNPC_Attack(Npc* self0, Ev* ev0)
{
    V d2;
    V d3;
    V d5;
    Ev* ev; int t; Npc* self; bool low; unsigned char handled;
    self = self0;
    ev = ev0;
    handled = 0;
    t = *cMessage_Name(ev);
    if (t == D_004EE550) {
        if ((unsigned char)ev->kind == 2) {
            if (self->target->b3 && Engaged(self->target)) {
                float len;
                Offset(self, &d2);
                len = Len(&d2);
                if ((unsigned char)self->Busy() && len < 30.0f && OnNode2(self->route, self->target))
                    cNPC_SetMoveMode(self, 0, 20);
            }
            handled = 1;
        } else if ((unsigned char)ev->kind == 3) {
            float len;
            Offset(self, &d3);
            len = Len(&d3);
            if (Engaged(self->target)) {
                if (!(unsigned char)self->Busy() && !(len <= 40.0f)) {
                    if (!Visited_00155350(self, self->target->node)) {
                        cNPC_MoveToAttackNode(self);
                    } else if (OnNode(self)) {
                        if (self->target->Get()->ctrl && self->target->Get()->ctrl->IsHuman())
                            handled = 1;
                    } else {
                        handled = 1;
                    }
                }
            } else {
                if (!(unsigned char)self->Busy())
                    handled = 1;
                low = 1;
                {
                    Inv* inv = self->obj->inv;
                    if (!inv->bA0 && !(cWeapon_GetClipAmmo(inv, 6) < self->clipMin))
                        low = 0;
                }
                if (low)
                    AskAmmo(self);
            }
            if (handled) {
                self->f13F = 4;
                if (Visited_00155350(self, self->target->node)) {
                    Ai* tg = self->target;
                    int node = tg->node;
                    if (self->b158) {
                        void* svc = cSystemContainer_GetSystem(g_Game, g_NpcRouteMgr);
                        if (node >= 0 && !cPathSystem_IsRequestBeingProcessed(svc, self->obj))
                            cPathNavigator_Request_cVectorR_int(self->route, tg, node);
                    }
                } else {
                    cNPC_MoveToAttackNode(self);
                }
            }
            self->fE8 = 40;
            handled = 1;
            self->fEC++;
        } else if ((unsigned char)ev->kind == 4) {
            self->fE8 = 1;
            if (Engaged(self->target))
                self->fEC = 0;
            handled = 1;
        } else if ((unsigned char)ev->kind == 8) {
            if (cNPC_RecommendAIMode(self) == 2) {
                cNPC_MoveToCoverNode(self);
                self->pair = Pair(4, 2);
            }
        } else if ((unsigned char)ev->kind == 7) {
            handled = 1;
            self->fE8 = 1;
        } else if ((unsigned char)ev->kind == 0) {
            if (self->target->b4)
                self->fE8 = 1;
            else
                self->fE8 = -1;
            self->fEC = 0;
            self->SetMovement(2, 20);
            handled = 1;
            self->fE0 = -1;
            self->fE4 = -1;
        } else if ((unsigned char)ev->kind == 0) {
            /* retail tests kind 0 a second time here (bnez), so this arm is unreachable */
            self->SetMovement(1, 20);
        }
    } else {
        int t2 = *cMessage_Name(ev);
        if (t2 == D_004ED9B8) {
            if ((unsigned char)ev->kind == 5) {
                float l2;
                Offset(self, &d5);
                l2 = LenSq(&d5);
                if (Engaged(self->target) && (unsigned char)self->Busy() && l2 < 900.0f)
                    cNPC_SetMoveMode(self, 0, 20);
            } else if ((unsigned char)ev->kind == 1 || (unsigned char)ev->kind == 3) {
            } else if ((unsigned char)ev->kind == 2) {
                if (self->pair.a == 4 && self->pair.b != 4)
                    cStateMachine_ChangeState(self->brain, self->pair.b, 0);
            } else if ((unsigned char)ev->kind == 7) {
                if (ev->f28 == 10) {
                    int n = self->route->f50;
                    if (n >= 0) { PNode* pn = cAIPathData_GetNode(n); if (OnPNode(self, pn))
                        self->SetMovement(2, 20); }
                }
            }
        }
    }
    return handled;
}
#undef cMessage_Name /* merge_units */
#undef cPathSystem_IsRequestBeingProcessed /* merge_units */
#undef cPathNavigator_Request_cVectorR_int /* merge_units */
#undef cNPC_MoveToAttackNode /* merge_units */
#undef cNPC_SetMoveMode /* merge_units */
static inline void merge_flush_func_00155350(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00155350 */
