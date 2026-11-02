/*
 * SFOGame/Source/npc: 16 files, 00156F50-00157DF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00156F50 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { char pad[0xC]; int id; } Ref;
typedef struct { char pad[0x40]; Ref* ref; int id; } RefHolder;

/* Returns the held reference if it is null or still matches the expected id, else 0. */
Ref* cAITarget_GetTargetGameObject(RefHolder* self)
{
    Ref* ref = self->ref;
    unsigned char valid = 1;
    if (!((ref != 0) ^ 1) && ref->id != self->id)
        valid = 0;
    return valid ? ref : 0;
}
static inline void merge_flush_func_00156F50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00156F50 */

/* merge_units: begin func_00156F90 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { char pad[0x24]; unsigned char kind; char pad2[3]; int on; } F6Ev;
extern "C" int* cMessage_Name(F6Ev*);
extern "C" int D_004EE550;
extern "C" void cStateMachine_ChangeState(void*, int, int);
struct F6Obj { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void SetMode(int m, int t); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void Alert(int a, int t); char pad[0x40]; char x44[4]; };
extern "C" unsigned char cNPC_Patrol(F6Obj* self, F6Ev* e)
{
    unsigned char handled = 0;
    int t = *cMessage_Name(e);
    if (t == D_004EE550) {
        unsigned char k = e->kind;
        if (k == 4) {
            if (e->on) {
                cStateMachine_ChangeState(self->x44, 1, 0);
            }
            handled = 1;
        } else if (k == 7) {
            cStateMachine_ChangeState(self->x44, 1, 0);
            self->Alert(1, 20);
        } else if (k == 0) {
            self->SetMode(0, 10);
            handled = 1;
        } else if (k == 1) {
            self->SetMode(1, 10);
            handled = 1;
        }
    }
    return handled;
}
static inline void merge_flush_func_00156F90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00156F90 */

/* merge_units: begin func_001570B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
#include "vslot_pad.h"
/* cNPC::RecommendAIMode: weigh the NPC's chance to hit against the target's threat (plus a
   penalty while reloading or when the target is out of range) and recommend an attack mode. */
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(const cVector& o) { cVector* d = this; const cVector* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
    /* VU0 macro-mode vector ops (COP2), not expressible in C */
    cVector& operator-=(const cVector& o) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(this), "r"(this), "r"(&o) : "memory"); return *this; }
    float Length() const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct cMatrix { cVector r[4]; cMatrix() {} const cVector& GetTranslation() const { return r[3]; } };
struct cGOBJ { char pad[0xC]; int id; };
static inline bool IsNullNV(void* p) { return !(p != 0); }
static inline int SameRef(const int& a, const int& b) { return (unsigned)(a ^ b) < 1; }
struct cSafePtr {
    cGOBJ* ptr; int id;
    int IsValid() { unsigned char ok = 1; if (!IsNullNV(ptr) && !SameRef(ptr->id, id)) ok = 0; return ok; }
    cGOBJ* Get() { return IsValid() ? ptr : 0; }
};
struct cAITarget {
    cVector targetPositionLastSeen;
    float viewConeRadius, viewConeHalfAngle;
    int nodeGroup, priority;
    unsigned char targetInViewConeFlag : 1, targetInBodyViewConeFlag : 1, targetLOSFlag : 1, targetSeenFlag : 1, targetPositionValid : 1, targetDirectionValid : 1, prevVisibleFlag : 1, targetLOSCheckedLastUpdate : 1;
    char pad21[0x40 - 0x21];
    cSafePtr targetGobj;
    cGOBJ* GetTargetGobj() { return targetGobj.Get(); }
};
struct cWeapon { char pad[0xA0]; unsigned char reloading; };
struct cHuman {
    VPAD32(a) VPAD16(b) VPAD8(c) VPAD2(d) VPAD1(e)
    virtual cMatrix GetMatrix() const;
    char pad4[0x3524 - 4];
    cWeapon* weapon;
};
struct cNPC {
    VPAD32(a) VPAD32(b) VPAD32(c) VPAD4(d) VPAD2(e) VPAD1(f)
    virtual int GetCurrentMode();
    VPAD4(g) VPAD2(h)
    virtual int GetModeForState(int s);
    char pad4[0x1C];
    float accuracy;             /* 0x20 */
    float accuracyScale;        /* 0x24 */
    float GetAccuracy() const { float s = accuracyScale; float a = accuracy; return a * s; }
    char pad28[8];
    cHuman* owner;              /* 0x30 */
    char pad34[0x6C - 0x34];
    float aggression;           /* 0x6C */
    char pad70[0xA4 - 0x70];
    int reloadThreshold;        /* 0xA4 */
    char padA8[0xB8 - 0xA8];
    float attackRange;          /* 0xB8 */
    char padBC[0x1AC - 0xBC];
    cAITarget* target;          /* 0x1AC */
};
extern "C" {
float cAITarget_GetAwarenessThreat(cAITarget* t, cGOBJ* g);
int cWeapon_GetClipAmmo(cWeapon* w, int kind);
int cNPC_RecommendAIMode(cNPC* self);
}
static inline float Scale2(float x, float k) { return x * k; }
static inline bool NeedsReload(cNPC* self) { return self->owner->weapon->reloading || cWeapon_GetClipAmmo(self->owner->weapon, 6) < self->reloadThreshold; }
static inline unsigned char OutOfRange(cNPC* self)
{
    unsigned char outOfRange = 0;
    int currState = self->GetModeForState(0);
    if (!(self->attackRange <= 0.0f) && self->target->targetPositionValid && currState >= 0) {
        cVector delta = self->owner->GetMatrix().GetTranslation();
        float dist;
        dist = (delta -= self->target->targetPositionLastSeen).Length();
        if (currState == self->GetCurrentMode())
            outOfRange = 10.0f + dist > self->attackRange;
        else
            outOfRange = dist < self->attackRange;
    }
    return outOfRange;
}
int cNPC_RecommendAIMode(cNPC* self)
{
    float threat;
    float toHit;
    float d;
    float reloadAdjustment;
    reloadAdjustment = toHit = threat = 0.0f;
    if (self->target->GetTargetGobj()) {
        threat = 0.1f + cAITarget_GetAwarenessThreat(self->target, self->target->GetTargetGobj());
        toHit = 0.1f + Scale2(self->GetAccuracy(), 15.0f);
    }
    if (NeedsReload(self) || OutOfRange(self))
        reloadAdjustment = 1.0f;
    d = toHit * self->aggression - threat - reloadAdjustment;
    if (d < -0.2f)
        return 2;
    if (d > 0.45f)
        return 4;
    return 3;
}
static inline void merge_flush_func_001570B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001570B0 */

/* merge_units: begin func_001573D0 */
#pragma push /* merge_units */
#pragma cplusplus on
class G2Sub157 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(); virtual int IsB();
};
class G2Ctl157 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21();
    virtual void SetActive(int on);
};
class G2Npc157 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46();
    virtual void Deactivate(int v);
    char pad4[0x2C];
    G2Ctl157* ctl;
    char pad34[0x141 - 0x34];
    unsigned char lo : 7;
    unsigned char dead : 1;
};
typedef struct { char pad[0xC]; unsigned int id; char pad10[0x48]; G2Sub157* sub; } G2Gen157;
extern "C" {
extern unsigned char g_IsMultiplayer;
void cNPCInfoObject_ctor(int* t);
int cNPCInfoObject_GetOwner_cObjectIdR(int* t, unsigned int* id);
void cNPCInfoObject_dtor(int* t, int f);
}
static inline unsigned char G2IsA(G2Gen157* g) { unsigned char r = 0; if (g->sub && g->sub->IsA()) r = 1; return r; }
static inline unsigned char G2IsB(G2Gen157* g) { unsigned char r = 0; if (g->sub && g->sub->IsB()) r = 1; return r; }
extern "C" void cNPC_Deactivate_cGOBJP(G2Npc157* n, G2Gen157* g)
{
    if (n->dead) return;
    if (g_IsMultiplayer) {
        int v = -1;
        if (g) {
            if (G2IsA(g) || G2IsB(g)) {
                int tmp[1];
                cNPCInfoObject_ctor(tmp);
                v = cNPCInfoObject_GetOwner_cObjectIdR(tmp, &g->id);
                cNPCInfoObject_dtor(tmp, -1);
            } else {
                v = ((g->id & 0x7F000000) >> 24) - 1;
            }
        }
        n->Deactivate(v);
    } else {
        n->ctl->SetActive(1);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001573D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001573D0 */

/* merge_units: begin func_00157510 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { void* vt; char pad04[0x2C]; } Msg1_7510;
typedef struct { void* vt; char pad04[0x20]; int f24; signed char b28; char pad29[7]; } Msg2_7510;
extern "C" {
extern int D_00494178;
extern int D_005721A8;
extern unsigned char D_0055C780[];
extern char D_00572198[];
extern char D_00582760[];
extern char D_004E0E80[];
extern char D_004E0F00[];
void cNPC_SetEnabled(void* self, int a, int b);
#if 0 /* merge_units */
void NetGetMyClientIndex(int* p, int v);
#endif /* merge_units */
int NetGetMyClientIndex(int* id, int session); /* merge_units */
#define NetGetMyClientIndex(a0, a1) ((void)NetGetMyClientIndex((a0), (a1))) /* merge_units */

void cNetObjectMgr_RemoveFromTerrainActivation(void* o);
void cDeactivateMsg_SendDeactivated(void* m, int a, int b);
void cMessage_ctor_cMessageNameR(void* m, void* type);
void cNetObj_SendMessage_int_cMessageR_int_int(int a, void* m, int b, int c);
#if 0 /* merge_units */
void cMessage_dtor(void* m, int f);
#endif /* merge_units */
void* cMessage_dtor(void* self, short deleteFlag); /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((a0), (short)(a1))) /* merge_units */

}
class Body_7510 {
public:
    VPAD16(a) VPAD4(b) VPAD2(c)
    virtual void SetActive(int on);
    VPAD4(d) VPAD2(e)
    virtual int IsLocal();
    char pad[0x8];
    int cC;
    char pad10[0x1C];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
};
typedef struct { char pad[0x30]; Body_7510* body; } Npc_7510;
static inline int LocalId_7510(void)
{
    int a = D_005721A8;
    if (g_IsMultiplayer) {
        if (D_00494178 == -1)
            NetGetMyClientIndex(&D_00494178, a);
        return D_00494178;
    }
    return 0;
}
static inline bool CanActivate_7510(Body_7510* b) { return b->b2D && b->b2C && !b->b2E; }
extern "C" void cNPC_DeactivateGlobal(Npc_7510* self)
{
    Body_7510* b;
    int i;
    unsigned char* p;
    cNPC_SetEnabled(self, -1, 0);
    b = self->body;
    if (CanActivate_7510(b))
        b->SetActive(1);
    cNetObjectMgr_RemoveFromTerrainActivation(self->body);
    if (!self->body->IsLocal()) {
        for (i = 0, p = D_0055C780; i < 4; i++, p++) {
            if (*p == 2) {
                if (i != LocalId_7510()) {
                    Msg1_7510 m1;
                    Msg2_7510 m2;
                    cMessage_ctor_cMessageNameR(&m1, D_00572198);
                    m1.vt = D_004E0E80;
                    cDeactivateMsg_SendDeactivated(&m1, self->body->cC, i);
                    m1.vt = D_004E0E80;
                    cMessage_dtor(&m1, 0);
                    cMessage_ctor_cMessageNameR(&m2, D_00582760);
                    m2.vt = D_004E0F00;
                    m2.f24 = -1;
                    m2.b28 = 1;
                    cNetObj_SendMessage_int_cMessageR_int_int(self->body->cC, &m2, -1, i);
                    m2.vt = D_004E0F00;
                    cMessage_dtor(&m2, 0);
                }
            }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00157510(void) {}
#undef NetGetMyClientIndex /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00157510 */

/* merge_units: begin func_001576F0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop

#pragma cplusplus on

DEFINE_VTABLE_BASE_DTOR(cNetTerrainActivation_dtor, D_004E0F00, cMessage_dtor)
static inline void merge_flush_func_001576F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001576F0 */

/* merge_units: begin func_00157750 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_VTABLE_BASE_DTOR(cDeactivateMsg_dtor, D_004E0E80, cMessage_dtor)
static inline void merge_flush_func_00157750(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00157750 */

/* merge_units: begin func_001577B0 */
#pragma push /* merge_units */
#pragma cplusplus on
class NPC_77B0 {
public:
    VPAD32(a) VPAD8(b) VPAD4(c) VPAD2(d)
    virtual void Reset();
};
#if 0 /* merge_units */
extern "C" void cNPC_SetEnabled(NPC_77B0* self, int a, int b);
#endif /* merge_units */
#define cNPC_SetEnabled(a0, a1, a2) (cNPC_SetEnabled((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern "C" int cNPC_GetEnabled(NPC_77B0* self, int a);
#endif /* merge_units */
extern "C" int cNPC_GetEnabled(void* self, int a); /* merge_units */
#define cNPC_GetEnabled(a0, a1) (cNPC_GetEnabled((void *)(a0), (a1))) /* merge_units */

extern "C" void cNPC_DeactivateLocal(NPC_77B0* self, int a)
{
    cNPC_SetEnabled(self, a, 0);
    if (!cNPC_GetEnabled(self, -1))
        self->Reset();
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001577B0(void) {}
#undef cNPC_SetEnabled /* merge_units */
#undef cNPC_GetEnabled /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001577B0 */

/* merge_units: begin func_00157800 */
#pragma push /* merge_units */
#pragma cplusplus on
class G3Sub157 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(); virtual int IsB();
};
class G3Ctl157 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20();
    virtual void SetActive(int on);
};
class G3Npc157 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual int IsAlive();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47();
    virtual void Activate(int v);
    char pad4[0x2C];
    G3Ctl157* ctl;
};
typedef struct { char pad[0xC]; unsigned int id; char pad10[0x48]; G3Sub157* sub; } G3Gen157;
extern "C" {
}
static inline unsigned char G3IsA(G3Gen157* g) { unsigned char r = 0; if (g->sub && g->sub->IsA()) r = 1; return r; }
static inline unsigned char G3IsB(G3Gen157* g) { unsigned char r = 0; if (g->sub && g->sub->IsB()) r = 1; return r; }
extern "C" void cNPC_Activate_cGOBJP(G3Npc157* n, G3Gen157* g)
{
    if (g_IsMultiplayer) {
        if (n->IsAlive()) {
            int v = -1;
            if (g) {
                if (G3IsA(g) || G3IsB(g)) {
                    int tmp[1];
                    cNPCInfoObject_ctor(tmp);
                    v = cNPCInfoObject_GetOwner_cObjectIdR(tmp, &g->id);
                    cNPCInfoObject_dtor(tmp, -1);
                } else {
                    v = ((g->id & 0x7F000000) >> 24) - 1;
                }
            }
            n->Activate(v);
        }
    } else {
        n->ctl->SetActive(1);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00157800(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00157800 */

/* merge_units: begin func_00157940 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
int cNPC_GetEnabled(void* self, int a);

#if 0 /* merge_units */
void NetGetMyClientIndex(int* p, int v);
#endif /* merge_units */
#define NetGetMyClientIndex(a0, a1) ((void)NetGetMyClientIndex((a0), (a1))) /* merge_units */

void cNetObjectMgr_AddActivate(void* ctl, int v);
}
typedef struct { char pad[0xC]; unsigned int flags; } Obj_7940;
class NPC_7940 {
public:
    VPAD32(a) VPAD16(b) VPAD8(c) VPAD2(d)
    virtual Obj_7940* GetBody();
    char pad[0x2C];
    void* ctl;
};
static inline int DefaultBody()
{
    int a = D_005721A8;
    if (g_IsMultiplayer) {
        if (D_00494178 == -1)
            NetGetMyClientIndex(&D_00494178, a);
        return D_00494178;
    }
    return 0;
}
extern "C" void cNPC_Activate_int(NPC_7940* self, int v)
{
    int r = cNPC_GetEnabled(self, -1);
    if (v >= 0) {
        cNPC_SetEnabled(self, v, 1);
    } else {
        Obj_7940* o;
        cNPC_SetEnabled(self, -1, 1);
        o = self->GetBody();
        if (o) {
            v = ((o->flags & 0x7F000000) >> 24) - 1;
        } else {
            v = DefaultBody();
        }
    }
    if (!r)
        cNetObjectMgr_AddActivate(self->ctl, v);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00157940(void) {}
#undef NetGetMyClientIndex /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00157940 */

/* merge_units: begin func_00157A40 */
#pragma push /* merge_units */
#pragma cplusplus on
/* cNPC_WantsToBeActive: false while the actor is in state 2/3 and the NPC is busy */
struct Pt1SbActor {
    VPAD32(a) VPAD32(b)
    virtual unsigned char GetMoveState();
};
struct Pt1SbNpc {
    VPAD32(a) VPAD32(b) VPAD16(c) VPAD4(d) VPAD2(e) VPAD1(f)
    virtual int IsBusy();
    char pad4[0x30 - 4];
    Pt1SbActor* actor;
};
static inline unsigned char Pt1Sb_Moving(Pt1SbNpc* n)
{
    unsigned char s = n->actor->GetMoveState();
    return s == 2 || s == 3;
}
static inline int Pt1Sb_Not(bool x) { return x ^ 1; }
static inline int Pt1Sb_NotI(int x) { return (x != 0) ^ 1; }
extern "C" unsigned char cNPC_WantsToBeActive(Pt1SbNpc* n)
{
    unsigned char r = 1;
    if (!Pt1Sb_Not(Pt1Sb_Moving(n)))
        if (!Pt1Sb_NotI(n->IsBusy()))
            r = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00157A40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00157A40 */

/* merge_units: begin func_00157AD0 */
#pragma push /* merge_units */
#pragma cplusplus on

class Actor_7AD0 {
public:
    VPAD16(p) VPAD4(q) VPAD2(r)
    virtual void Deactivate(int v);
    VPAD4(s) VPAD2(t)
    virtual int IsLinked();
    VPAD32(u) VPAD2(w)
    virtual unsigned char GetState();
    char pad[0x2C - 4];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    bool Busy() { return b2D && b2C && !b2E; }
};

typedef struct { char pad[4]; int begin; int end; char padC[8]; unsigned char b14; } Look_7AD0;

typedef struct { char pad[4]; unsigned int magic; } Obj_7AD0;

typedef struct { void* vtable; char pad[0x20]; Actor_7AD0* actor; unsigned char flag; } Msg_7AD0;

typedef struct cNPC_7AD0 {
    char pad[0x30];
    Actor_7AD0* actor;
    char pad34[0x150 - 0x34];
    int id;
    char pad154[0x159 - 0x154];
    unsigned char dead;
    char pad15A[0x1B0 - 0x15A];
    int route;
    char pad1B4[4];
    Look_7AD0* look;
} cNPC_7AD0;

struct Empty_7AD0 { char c; };
struct Pred_7AD0 {
    Empty_7AD0 e;
    cNPC_7AD0** self;
    Pred_7AD0(const Empty_7AD0& c, cNPC_7AD0** s) : e(c), self(s) {}
};

extern "C" {
extern char D_004A4A68[];
extern char D_004DB600[];
extern char D_004DB660[];
extern PtrVec g_NpcDeadList;
extern char g_Game[];
extern char g_NpcRouteMgr[];
extern int cSystemContainer_GetSystem(void* a, void* b);
extern void cPathSystem_ClearRequests(int mgr, Actor_7AD0* actor);
extern void cPathNavigator_Deactivate(int route);
extern void cAI_Deactivate(cNPC_7AD0* self);
extern void std_list_imp_voidPtr_remove_if(PtrVec* v, Pred_7AD0 p);
extern void cNPC_RemoveFromActiveList(Actor_7AD0* actor);
extern void std_list_deleter_cLookAtListItem_erase(int* result, Look_7AD0* obj, int* end, int** begin);
extern Obj_7AD0* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(Msg_7AD0* msg, void* name);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */

extern void QueueMessage_cMessageR_cSystemP_int(Msg_7AD0* msg, void* target, int flags);
#if 0 /* merge_units */
extern void cMessage_dtor(Msg_7AD0* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */

extern void cGOBJ_GetClosestPlayer(Actor_7AD0* actor, float* out);
}

inline void LookClear_7AD0(Look_7AD0* obj)
{
    int* begin = &obj->begin;
    int end = obj->end;
    int result;
    std_list_deleter_cLookAtListItem_erase(&result, obj, &end, &begin);
}

extern "C" void cNPC_Deactivate_void(cNPC_7AD0* self)
{
    float dist;
    int result;
    int end;
    int* begin;
    Empty_7AD0 e;
    unsigned char state;
    unsigned char ok;

    if (self->dead) {
        return;
    }
    if (self->actor && self->actor->Busy()) {
        self->actor->Deactivate(1);
        return;
    }
    {
        int mgr = cSystemContainer_GetSystem(g_Game, g_NpcRouteMgr);
        cPathSystem_ClearRequests(mgr, self->actor);
    }
    cPathNavigator_Deactivate(self->route);
    cAI_Deactivate(self);
    std_list_imp_voidPtr_remove_if(&g_NpcDeadList, Pred_7AD0(e, &self));
    cNPC_RemoveFromActiveList(self->actor);
    if (Look_7AD0* l = self->look) {
        begin = &l->begin;
        end = l->end;
        std_list_deleter_cLookAtListItem_erase(&result, l, &end, &begin);
        self->look->b14 = 0;
    }
    if (self->actor->IsLinked()) {
        Obj_7AD0* o = nGobjManager_LookupGOBJ_cObjectIdR(&self->id);
        if (o && o->magic == 0xBEBAAFDE) {
            Actor_7AD0* a = self->actor;
            Msg_7AD0 msg;
            cMessage_ctor_cMessageNameR(&msg, D_004A4A68);
            msg.vtable = D_004DB600;
            msg.flag = 1;
            msg.actor = a;
            QueueMessage_cMessageR_cSystemP_int(&msg, o, 0);
            msg.vtable = D_004DB660;
            cMessage_dtor(&msg, 0);
        }
    }
    if (self->actor) {
        state = self->actor->GetState();
        ok = state == 2 || state == 3;
        if (ok) {
            cGOBJ_GetClosestPlayer(self->actor, &dist);
        }
    }
    self->dead = 1;
}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_00157AD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00157AD0 */

/* merge_units: begin func_00157D20 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "vtable2_base_dtor.h"
#pragma pop
#pragma push
#pragma cplusplus on
#pragma pop

#pragma cplusplus on

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(func_00157D20, D_004DB600, D_004DB660, cMessage_dtor)
static inline void merge_flush_func_00157D20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00157D20 */

/* merge_units: begin func_00157D90 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_VTABLE_BASE_DTOR(cGeneratorMessageBase_dtor, D_004DB660, cMessage_dtor)
static inline void merge_flush_func_00157D90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00157D90 */

/* merge_units: begin func_00157DF0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

#pragma cplusplus on
struct NpcV {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual int s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62(int);
    virtual void s63();
    virtual void s64();
    virtual void s65();
    virtual void s66();
    virtual void s67();
    virtual void s68();
    virtual void s69();
    virtual void s70();
    virtual void s71();
    virtual void s72();
    virtual void s73();
    virtual void s74();
    virtual void s75();
    virtual void s76();
    virtual void s77();
    virtual void s78();
    virtual void s79();
    virtual void s80();
    virtual void s81();
    virtual void s82();
    virtual void s83();
    virtual void s84();
    virtual void s85();
    virtual void s86();
    virtual void s87();
    virtual void s88();
    virtual void s89();
    virtual void s90();
    virtual void s91();
    virtual void s92();
    virtual void s93();
    virtual void s94();
    virtual void s95();
    virtual void s96();
    virtual void s97();
    virtual void s98();
    virtual void s99();
    virtual void s100();
    virtual void s101();
    virtual void s102();
    virtual int s103();
    virtual void s104();
    virtual void s105(int);
    virtual void s106();
};
struct ActV {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21(int);
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual int s29();
};
typedef struct { char pad[0x14]; unsigned char used; char pad15[3]; } LookSlot;
typedef struct Actor : ActV {
    char pad4[0x8];
    int id;
    char pad10[0x1C];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    char pad2F[0x3524 - 0x2F];
    int inv;
} Actor;
typedef struct Npc : NpcV {
    char pad4[0x2C];
    Actor *actor;
    char pad34[0x68 - 0x34];
    int u68;
    char pad6C[0x84 - 0x6C];
    int u84;
    int u88;
    float u8C;
    char pad90[0xA4 - 0x90];
    int burst;
    int uA8;
    char padAC[4];
    int uB0;
    int uB4;
    char padB8[0xE8 - 0xB8];
    int uE8;
    char padEC[0x138 - 0xEC];
    int node;
    char pad13C[5];
    unsigned char f0 : 1;
    unsigned char f1 : 1;
    unsigned char f2 : 1;
    unsigned char f3 : 1;
    unsigned char f4 : 1;
    unsigned char f5 : 1;
    unsigned char f6 : 1;
    unsigned char f7 : 1;
    char pad142[0x158 - 0x142];
    unsigned char u158;
    unsigned char active;
    char pad15A[0x166 - 0x15A];
    unsigned char u166;
    char pad167[0x1AC - 0x167];
    int view;
    int path;
    char pad1B4[4];
    LookSlot *slot;
    int u1BC;
    float u1C0;
    int u1C4;
    char pad1C8[0x1D0 - 0x1C8];
    int u1D0;
} Npc;
typedef struct {
    void *vt;
    char pad4[0x20];
    int id;
    signed char b28;
    char pad29[0x30 - 0x29];
} Msg;

extern "C" {
extern LookSlot D_004EA1D0[16];
#if 0 /* merge_units */
extern char g_NpcDeadList[];
#endif /* merge_units */
#define g_NpcDeadList ((char*)&g_NpcDeadList) /* merge_units */

#if 0 /* merge_units */
extern unsigned char D_0055C780[4];
#endif /* merge_units */
#define D_0055C780 ((unsigned char*)&D_0055C780) /* merge_units */


int cHuman_IsHoldingGun(Actor *a);
#if 0 /* merge_units */
void cMessage_ctor_cMessageNameR(Msg *m, void *type);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */

void cNPC_cActiveSlot_Init(LookSlot *s);
void std_list_cNPCPtr_push_back(void *list, Npc **npc);
int cAIPathData_GetNode(int n);
void cPathNavigator_Activate(int p);
void cAITarget_Activate(int v);
void cNPC_AddToActiveList(Actor *a);
int Libc_Rand(void);
#if 0 /* merge_units */
void cNetObj_SendMessage_int_cMessageR_int_int(int id, Msg *m, int a, int b);
#endif /* merge_units */
#define cNetObj_SendMessage_int_cMessageR_int_int(a0, a1, a2, a3) (cNetObj_SendMessage_int_cMessageR_int_int((a0), (void *)(a1), (a2), (a3))) /* merge_units */

int cWeapon_GetClipSize(int inv, int w);
int cWeapon_IsFullyAutomatic(int inv);
void cAI_Activate(Npc *npc);
#if 0 /* merge_units */
void cMessage_dtor(Msg *m, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */

int NetGetMyClientIndex(int *id, int session);
}

#define LOCALID(X) { int ld_a = D_005721A8; if (g_IsMultiplayer) { if (D_00494178 == -1) NetGetMyClientIndex(&D_00494178, ld_a); X = D_00494178; } else X = 0; }

extern "C" void cNPC_Activate_void(Npc *self)
{
bool ok;
    int i;
    int v;

    if (self->active) {
        Actor *a = self->actor;
        ok = a->b2D != 0 && a->b2C != 0 && !(a->b2E != 0);
        if (!ok) {
            if (self->s15()) {
                Actor *b = self->actor;
                b->s21(1);
            }
        } else {
            if (self->s15())
                cNPC_AddToActiveList(self->actor);
            else
                std_list_cNPCPtr_push_back(g_NpcDeadList, &self);
            self->slot = D_004EA1D0;
            for (i = 0; i < 16; i++) {
                if (!D_004EA1D0[i].used) {
                    D_004EA1D0[i].used = 1;
                    self->slot = &D_004EA1D0[i];
                    break;
                }
            }
            cNPC_cActiveSlot_Init(self->slot);
            self->u166 = 0;
            if (self->uE8 < 0)
                self->uE8 = 0;
            cAI_Activate(self);
            cAITarget_Activate(self->view);
            cPathNavigator_Activate(self->path);
            if (self->node >= 0) {
                self->s62(cAIPathData_GetNode(self->node));
                self->node = -1;
            }
            {
                Actor *a2 = self->actor;
                if (cHuman_IsHoldingGun(a2)) {
                    int inv = a2->inv;
                    int n;
                    self->burst = (self->actor->id & 7) + 3;
                    if (Libc_Rand() & 1)
                        self->burst++;
                    n = self->burst;
                    if (cWeapon_GetClipSize(inv, 6) < n) {
                        v = cWeapon_GetClipSize(inv, 6) / 2;
                        self->burst = v <= 0 ? 1 : v;
                    }
                } else {
                    self->burst = 0;
                }
            }
            self->uA8 = 0;
            self->u158 = 1;
            self->u1BC = 0;
            self->u68 = 0;
            self->u84 = 0;
            self->u88 = 0;
            self->u1C0 = 999999.0f;
            self->u1C4 = 0;
            self->u1D0 = 0;
            if (!cWeapon_IsFullyAutomatic(self->actor->inv))
                self->u8C = 0.2f + 0.01f * (float)(unsigned int)(self->actor->id & 0xF);
            else
                self->u8C = 0.0f;
            if (self->f5) {
                self->f5 = 0;
                self->uB0 = self->s103();
                self->s106();
                self->uB4 = self->s103();
                self->s105(self->uB0);
            }
            {
                Actor *a3 = self->actor;
                if (!a3->s29()) {
                    int j;
                    unsigned char *p = D_0055C780;
                    for (j = 0; j < 4; j++, p++) {
                        if (*p == 2) {
                            int me;
                            LOCALID(me);
                            if (j != me) {
                                int id;
                                Msg m;
                                LOCALID(id);
                                cMessage_ctor_cMessageNameR(&m, D_00582760);
                                m.vt = D_004E0F00;
                                m.id = id;
                                m.b28 = 0;
                                cNetObj_SendMessage_int_cMessageR_int_int(self->actor->id, &m, -1, j);
                                m.vt = D_004E0F00;
                                cMessage_dtor(&m, 0);
                            }
                        }
                    }
                }
            }
            self->active = 0;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00157DF0(void) {}
#undef g_NpcDeadList /* merge_units */
#undef D_0055C780 /* merge_units */
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cNetObj_SendMessage_int_cMessageR_int_int /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00157DF0 */

/* merge_units: begin func_00158350 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
void* cMemMan_Allocate(int pool, int size, char* file, int line);
extern char D_0049B670[];
extern char D_0051EE58[];
extern "C" void cMessage_getSOBJClassId();
extern "C" void cNetCopyMsg_dtor();
extern "C" void cNetCopyMsg_Clone();
extern "C" void cNetCopyMsg_Pack();
void * const D_004DE110[8] = { (void*)0x0, (void*)0x0, (void*)cNetCopyMsg_dtor, (void*)cNetCopyMsg_Clone, (void*)cNetCopyMsg_Pack, (void*)cMessage_getSOBJClassId, (void*)0x0, (void*)0x0 };
#if 0 /* merge_units */
void cMessage_ctor_cMessageNameR(void* p, char* name);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((a0), (void *)(a1))) /* merge_units */


void cNetworkTransferNpc_ctor_void(void* p);
int cSystem_GetObjectID_void(void* p);
int cObjectId_GetEncodedValue(int v);
void func_00148B50(void* p, void* npc);
void func_00158490(void* p, int v);
}
class Snd_8350 { public: VPAD16(a) VPAD4(b) virtual void Stop(); };
typedef struct { char pad[0x58]; Snd_8350* snd; } Ctl_8350;
typedef struct { char pad[0x30]; Ctl_8350* ctl; } NPC_8350;
typedef struct { void* vt; char pad[0x20]; int x24; } Ev_8350;
#pragma opt_common_subs off
static inline void Ev_Init(Ev_8350* p, Ctl_8350* c)
{
    cMessage_ctor_cMessageNameR(p, D_0051EE58);
    p->vt = ((char*)D_004DE110);
    cNetworkTransferNpc_ctor_void((char*)p + 0x30);
    p->x24 = cObjectId_GetEncodedValue(cSystem_GetObjectID_void(c));
}
extern "C" Ev_8350* cNPC_GetCopyMsg(NPC_8350* self)
{
    Snd_8350* s = self->ctl->snd;
    if (s)
        s->Stop();
    if (g_IsMultiplayer) {
        Ev_8350* p;
        {
            AllocGuard g;
            p = (Ev_8350*)cMemMan_Allocate(0, 0x310, D_0049B670, 0x80C);
        }
        if (p) {
            Ev_Init(p, self->ctl);
            func_00148B50((char*)p + 0x30, self);
            func_00158490(p, 0x40);
        }
        return p;
    }
    return 0;
}
#pragma opt_common_subs reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00158350(void) {}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00158350 */
