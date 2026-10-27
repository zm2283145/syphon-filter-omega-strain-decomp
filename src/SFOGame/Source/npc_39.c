/*
 * SFOGame/Source/npc: 5 files, 00156F50-001573D0
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
void NetGetMyClientIndex(int* p, int v);
void cNetObjectMgr_RemoveFromTerrainActivation(void* o);
void cDeactivateMsg_SendDeactivated(void* m, int a, int b);
void cMessage_ctor_cMessageNameR(void* m, void* type);
void cNetObj_SendMessage_int_cMessageR_int_int(int a, void* m, int b, int c);
void cMessage_dtor(void* m, int f);
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
#pragma pop /* merge_units */
/* merge_units: end func_00157510 */
