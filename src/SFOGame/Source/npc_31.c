/*
 * SFOGame/Source/npc: 7 files, 00158A80-00159560
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00158A80 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x14]; unsigned char used; char pad15[3]; } E_8A80;
extern E_8A80 D_004EA1D0[16];
extern int g_MaxActiveNpcCount;
extern int D_004EA358;
extern int D_004EA380;
extern float WorthShootingThreshold;
int cDME_GetTime(int a);
void cNPC_SystemInit(void)
{
    int i;
    D_004EA358 = 0;
    g_MaxActiveNpcCount = 4;
    WorthShootingThreshold = 0.5f;
    for (i = 0; i < 16; i++)
        D_004EA1D0[i].used = 0;
    D_004EA380 = cDME_GetTime(1);
}
static inline void merge_flush_func_00158A80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00158A80 */

/* merge_units: begin func_00158B10 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (container helpers instantiated for cNPC).
 */

#include "npc_types.h"

extern void std_list_deleter_cLookAtListItem_ctor(void* self);

void* cNPC_cActiveSlot_ctor(void* self) {
    std_list_deleter_cLookAtListItem_ctor(self);
    return self;
}
static inline void merge_flush_func_00158B10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00158B10 */

/* merge_units: begin func_00158B40 */
#pragma push /* merge_units */
#pragma cplusplus on

#define std_list_deleter_voidPtr_erase_listdeleter_listdeleter std_list_deleter_cLookAtListItem_erase
#include "obj_list_dtor.h"

DEFINE_OBJ_LIST_DTOR(std_list_cLookAtListItem_dtor)
static inline void merge_flush_func_00158B40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00158B40 */

/* merge_units: begin func_00158BC0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop
#include "vslot_pad.h"

#pragma opt_propagation off
#pragma cplusplus on
extern "C" {
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void cScriptVars_initScriptlet(void* p, int v);
void* cAITarget_ctor(void* p, void* owner);
void* cPathNavigator_ctor(void* p, void* owner, int n, int v);
int Libc_Rand(void);
extern char D_0049C088[];
extern char D_0049B670[];
}

struct Trk_8BC0 {
    int a;
    int b;
    int c;
    Trk_8BC0() { a = 0; b = 0; c = -1; }
    static void* operator new(unsigned int sz, int line)
    {
        void* p;
        if (g_ProfileLockEnabled) Alloc_Lock(9);
        g_ProfileLockDepth++;
        p = cMemMan_Allocate(0, sz, D_0049C088, line);
        if (g_ProfileLockEnabled) EnableIntc(9);
        g_ProfileLockDepth--;
        return p;
    }
};

static inline void* NpcNew_8BC0(int sz, int line)
{
    void* p;
    if (g_ProfileLockEnabled) Alloc_Lock(9);
    g_ProfileLockDepth++;
    p = cMemMan_Allocate(0, sz, D_0049B670, line);
    if (g_ProfileLockEnabled) EnableIntc(9);
    g_ProfileLockDepth--;
    return p;
}

struct Own_8BC0 {
    char p0[0x14];
    unsigned char x14;
    char p15[0x3264 - 0x15];
    int x3264;
    char p3268[0x3524 - 0x3268];
    unsigned char* x3524;
    char p3528[0x3548 - 0x3528];
    int x3548;
};

struct Npc_8BC0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
    virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
    virtual float v80(int);
    virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84();
    virtual void v85(int, float, float);
};

struct NpcD_8BC0 {
    void* vt;
    char p4[0x14 - 4];
    unsigned char x14;
    char p15[0x18 - 0x15];
    Trk_8BC0* x18;
    char p1C[0x60 - 0x1C];
    float x60;
    int x64;
    char p68[0x6C - 0x68];
    float x6C;
    char p70[0x78 - 0x70];
    float x78;
    int x7C;
    float x80;
    char p84[0x90 - 0x84];
    float x90;
    float x94;
    char p98[0x9C - 0x98];
    int x9C;
    int xA0;
    char pA4[0xAC - 0xA4];
    int xAC;
    char pB0[0xB8 - 0xB0];
    int xB8;
    int xBC[9];
    int xE0;
    int xE4;
    char pE8[0x114 - 0xE8];
    int x114;
    int x118;
    int x11C;
    int x120;
    int x124;
    int x128;
    char p12C[0x130 - 0x12C];
    int x130;
    int x134;
    int x138;
    unsigned char x13C;
    unsigned char x13D;
    unsigned char x13E;
    char p13F[0x141 - 0x13F];
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
};

union U4 { int i; float f; };
extern "C" void cNPC_Init(Npc_8BC0* self, Own_8BC0* own)
{
    char* t = (char*)self;
    if (own->x3264) {
        if (!*(Trk_8BC0**)(t + 0x18)) {
            *(Trk_8BC0**)(t + 0x18) = new (0x49) Trk_8BC0;
        }
        cScriptVars_initScriptlet(*(Trk_8BC0**)(t + 0x18), own->x3264);
    }
    if (!*(void**)(t + 0x1AC)) {
        void* p = NpcNew_8BC0(0x60, 0x741);
        if (p) p = cAITarget_ctor(p, self);
        *(void**)(t + 0x1AC) = p;
    }
    if (!*(void**)(t + 0x1B0)) {
        void* p = NpcNew_8BC0(0x80, 0x745);
        if (p) p = cPathNavigator_ctor(p, own, 100, own->x3548);
        *(void**)(t + 0x1B0) = p;
    }
    own->x3524[0x99] = 1;
    *(int*)(t + 0x1B4) = 0;
    *(int*)(t + 0x120) = -1;
    *(int*)(t + 0x11C) = -1;
    *(unsigned char*)(t + 0x13D) = 0;
    *(unsigned char*)(t + 0x13E) = 1;
    *(int*)(t + 0x118) = 0;
    *(int*)(t + 0x130) = 0;
    *(int*)(t + 0x134) = 0;
    *(int*)(t + 0x9C) = -1;
    *(int*)(t + 0x64) = -1;
    *(int*)(t + 0xA0) = 0;
    *(int*)(t + 0xAC) = 0;
    *(int*)(t + 0xE0) = -1;
    *(int*)(t + 0xE4) = -1;
    *(float*)(t + 0x80) = 100.0f;
    *(int*)(t + 0x160) = 0;
    *(unsigned char*)(t + 0x164) = 0;
    *(int*)(t + 0x124) = 0;
    *(int*)(t + 0x128) = 0;
    *(unsigned char*)(t + 0x17C) = 0;
    *(int*)(t + 0x178) = 0;
    *(unsigned char*)(t + 0x1A8) = 0;
    *(unsigned char*)(t + 0x190) = 0;
    *(int*)(t + 0x18C) = 0;
    *(unsigned char*)(t + 0x1A9) = 0;
    *(unsigned char*)(t + 0x1A4) = 0;
    *(int*)(t + 0x1A0) = 0;
    *(unsigned char*)(t + 0x1AA) = 0;
    *(float*)(t + 0x6C) = 0.25f + 0.5f * (Libc_Rand() / 2147483648.0f);
    self->v85(0x14, 0.0f, 200.0f);
    *(int*)(t + 0x7C) = 0;
    *(float*)(t + 0x78) = -1.0f;
    *(int*)(t + 0x114) = 0;
    {
        int i = 0;
        char* q = t;
        do {
            *(int*)(q + 0xBC) = -1;
            *(int*)(q + 0xC0) = -1;
            *(int*)(q + 0xC4) = -1;
            i += 3;
            q += 12;
        } while (i < 9);
    }
    {
        float f = self->v80(1);
        NpcD_8BC0* d = (NpcD_8BC0*)self;
        int a = d->x64 > 0;

        if (!a) {
            d->x60 = f;
            d->x64 = 0;
            d->b6 = 0;
        }
    }
    {
        NpcD_8BC0* d = (NpcD_8BC0*)self;
        int h __attribute__((aligned(16)));
        int* p = &h;
        *(int*)(t + 0x1C8) = 0;
        h = -1;
        *(int*)(t + 0x1CC) = *p;
        d->x90 = 4.0f;
        d->x94 = 35.0f;
        d->b4 = 1;
        d->xB8 = 0;
        *(int*)(t + 0x1C4) = 0;
        *(float*)(t + 0x1C0) = 999999.0f;
        d->x13C = 0;
        d->x138 = -1;
        d->b2 = 1;
        *(unsigned char*)(t + 0x159) = 1;
        d->b5 = 1;
        d->b7 = 0;
        own->x14 = 1;
        d->x14 = 1;
        *(float*)(t + 0x144) = 2.0f;
        *(unsigned char*)(t + 0x1D5) = 0;
        *(unsigned char*)(t + 0x1D4) = 0;
        *(unsigned char*)(t + 0x1D6) = 0;
        *(int*)(t + 0x154) = 0;
        *(unsigned char*)(t + 0x169) = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00158BC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00158BC0 */

/* merge_units: begin func_00159020 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
#pragma opt_rebuildconditionals off

struct V_A {
    float x, y, z, w;
    V_A() {}
    V_A(const V_A& o) { V_A* d = this; const V_A* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    V_A& operator=(const V_A& o) { V_A* d = this; const V_A* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); return *this; }
    void Sub3(const V_A& a, const V_A& b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(this), "r"(&a), "r"(&b) : "memory"); }
    void Sub(const V_A& b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%0); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%1)" : : "r"(&b), "r"(this) : "memory"); }
    float LenSq() const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory");
        return r;
    }
    void Normalize() {
        __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(this) : "memory");
    }
    float Dot(const V_A& b) const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%3); vmul.xyzw $vf3, $vf1, $vf2; mtsah $0, 6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2.ni %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this), "r"(&b) : "memory");
        return r;
    }
} __attribute__((aligned(16)));

struct M_A { V_A r[4]; const V_A& Up() const { return r[1]; } };

struct HObj_A { char pad[0xC]; int id; };

struct Actor_A {
    VPAD32(p) VPAD8(q) VPAD4(r) VPAD2(s)
    virtual V_A GetPos(int which);
    VPAD8(t) VPAD1(u)
    virtual M_A GetMtx();
    VPAD4(w) VPAD2(x) VPAD1(y)
    virtual unsigned char GetState();
    char pad04[0x14 - 4];
    unsigned char b14;
    char pad15[0x38 - 0x15];
    int x38;
    char pad3C[0x3204 - 0x3C];
    int x3204;
    char pad3208[0x354C - 0x3208];
    HObj_A* hobj;
    int hid;
};

struct Npc_A {
    VPAD32(p) VPAD32(q) VPAD16(r) VPAD4(s) VPAD2(t) VPAD1(u)
    virtual int IsActive();
    char pad04[0x30 - 4];
    Actor_A* actor;
    char pad34[0x114 - 0x34];
    int x114;
};

struct Cam_A {
    VPAD16(p) VPAD4(q)
    virtual void Update();
    char pad04[0x40 - 4];
    V_A pos;
    unsigned char b50;
};
struct CamHolder_A { char pad[0x50]; Cam_A* cam; };

struct Node_A { Node_A* prev; Node_A* next; Npc_A* npc; };
struct ItP_A { Node_A* p; };
struct It_A { ItP_A q; };
struct NpcList_A { int count; };

extern "C" {
extern NpcList_A g_NpcDeadList;
extern char g_CameraObject[];
extern float g_LevelFarDistance;
extern unsigned char g_IsMultiplayer;
#if 0 /* merge_units */
void std_list_cNPCPtr_begin(It_A* out, NpcList_A* l);
#endif /* merge_units */
void std_list_cNPCPtr_begin(Iter* out, PtrVec* v); /* merge_units */
#define std_list_cNPCPtr_begin(a0, a1) (std_list_cNPCPtr_begin((Iter *)(a0), (PtrVec *)(a1))) /* merge_units */

void std_list_cNPCPtr_end(It_A* out, NpcList_A* l);
It_A* cLListIterator_cNPCPtr_ctor_listR(It_A* dst, It_A* src);
#if 0 /* merge_units */
CamHolder_A** cLList_cCAMERA_GOBJPtr_Front(void* v);
#endif /* merge_units */
int* cLList_cCAMERA_GOBJPtr_Front(PtrVec* v); /* merge_units */
#define cLList_cCAMERA_GOBJPtr_Front(a0) ((CamHolder_A * *)cLList_cCAMERA_GOBJPtr_Front((PtrVec *)(a0))) /* merge_units */

#if 0 /* merge_units */
int func_00159570(void* v);
#endif /* merge_units */
int func_00159570(Word* self); /* merge_units */
#define func_00159570(a0) (func_00159570((Word *)(a0))) /* merge_units */

Actor_A* cNetObj_GetPlayer(int i);
float Libc_Cosf(float a);
}

static inline bool Eq(int x, int y) { return x == y; }
static inline bool HOk(Actor_A* a)
{
    return !a->hobj || Eq(a->hobj->id, a->hid);
}
static inline Actor_A* WeakGet(Actor_A* a)
{
    return HOk(a) ? (Actor_A*)a->hobj : 0;
}

#define AVAIL(n) (!WeakGet((n)->actor) && ((n)->x114 != 7 || !(((n)->actor->x3204 >> 7) & 1)))


extern "C" bool Npc_IsDeadRemovalAllowed(Npc_A* self)
{
    bool result = false;
    if (self->actor->GetState() == 3 && self->IsActive() && AVAIL(self)) {
        bool ok = true;
        Actor_A* found = 0;
        NpcList_A* l = &g_NpcDeadList;
        if (l->count > 3) {
            It_A it;
            It_A b;
            It_A e;
            It_A bi;
            It_A ei;
            std_list_cNPCPtr_begin(&bi, l);
            cLListIterator_cNPCPtr_ctor_listR(&b, &bi);
            it = b;
            goto cond;
            do {
                {
                    Npc_A* n = it.q.p->npc;
                    if (n->IsActive() && AVAIL(n)) {
                        found = it.q.p->npc->actor;
                        break;
                    }
                }
                it.q.p = it.q.p->next;
            cond:
                std_list_cNPCPtr_end(&ei, &g_NpcDeadList);
                cLListIterator_cNPCPtr_ctor_listR(&e, &ei);
            } while (it.q.p != e.q.p);
        }
        if (found != self->actor) {
            float maxSq = g_LevelFarDistance * g_LevelFarDistance;
            V_A pos = self->actor->GetPos(-1);
            Cam_A* c = (func_00159570(g_CameraObject) ? *cLList_cCAMERA_GOBJPtr_Front(g_CameraObject) : 0)->cam;
            if (c->b50)
                c->Update();
            pos.Sub(c->pos);
            float d = pos.LenSq();
            if (d < 400.0f || (self->actor->x38 != 0x80 && d < maxSq)) {
                ok = false;
            } else if (g_IsMultiplayer) {
                for (int i = 0; i < 4; i++) {
                    Actor_A* p = cNetObj_GetPlayer(i);
                    if (p && !p->b14) {
                        pos = self->actor->GetPos(-1);
                        pos.Sub3(pos, p->GetPos(-1));
                        if (pos.LenSq() < 400.0f) {
                            ok = false;
                            break;
                        }
                        if (pos.LenSq() < maxSq) {
                            V_A fwd = p->GetMtx().Up();
                            pos.Normalize();
                            if (!(fwd.Dot(pos) + (1.0f - Libc_Cosf(0.7853982f)) <= 1.0f)) {
                                ok = false;
                                break;
                            }
                        }
                    }
                }
            }
        }
        result = ok;
    }
    return result;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00159020(void) {}
#undef std_list_cNPCPtr_begin /* merge_units */
#undef cLList_cCAMERA_GOBJPtr_Front /* merge_units */
#undef func_00159570 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00159020 */

/* merge_units: begin func_00159560 */
#pragma push /* merge_units */
/* Address of the second word of the vector's first element. */
int* cLList_cCAMERA_GOBJPtr_Front(PtrVec* v) {
    return v->data + 2;
}

int func_00159570(Word* self) {
    return self->value;
}

void std_list_cNPCPtr_begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
static inline void merge_flush_func_00159560(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00159560 */

/* merge_units: begin func_00159590 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
#pragma opt_rebuildconditionals off
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { void* xx = this; x = a; y = b; z = c; w = d; }
    V(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M {
    V r0, r1, r2, t;
    M() {}
    V* T() { return &t; }
};
static inline void VSub(V* o, V* a, V* b)
{
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(o), "r"(a), "r"(b) : "memory");
}
static inline float AbsN(float x) { float r; asm { abs.s r, x } return r; }
static inline float AbsZ(float x) { float r = 0.0f; asm { abs.s r, x } return r; }

struct Obj;
struct Npc;
struct HObj { char pad[0xC]; int id; };
struct H { Obj* p; int serial; };
struct LNode { int unk0; LNode* next; H* h; };
struct RecR { int f0; int f4; int f8; char bC; };
struct WEnt { int a; int b; int c; int d; };
struct Wpn { WEnt e[8]; char p80[4]; unsigned char b84; };
struct Y { char pad[0x2C8]; float f2C8; };
struct X { char pad[0x310]; unsigned char b310; unsigned char b311; };
struct Tab { char pad[0x4C]; unsigned char b4C; char pad2[3]; };
struct G {
    VPAD16(a) VPAD4(b)
    virtual void V58();
    char pad4[0xC];
    M m;
    unsigned char b50;
    M* GetMtx() { if (b50) V58(); return &m; }
};
struct Obj {
    VPAD16(a) VPAD4(b) VPAD2(c)
    virtual void V60(int);
    VPAD32(d) VPAD4(e)
    virtual M VF4();
    VPAD4(f)
    virtual unsigned char GetMode();
    bool IsDead() { bool r; unsigned char m = GetMode(); r = true; if (m != 3 && m != 2) r = false; return r; }
    char pad4[8];
    int id;
    int f10;
    unsigned char b14;
    char pad15[0x17];
    bool b2C;
    bool b2D;
    bool b2E;
    char pad2F[0x15];
    int f44;
    char pad48[8];
    G* f50;
    char pad54[4];
    Npc* npc58;
    char pad5C[0x320C - 0x5C];
    int f320C;
    char p3210[0x3310 - 0x3210];
    Y* f3310;
    X* f3314;
    char p3318[0x33A5 - 0x3318];
    unsigned char b33A5;
    char p33A6[0x3524 - 0x33A6];
    Wpn* f3524;
    char p3528[0x3584 - 0x3528];
    RecR* f3584;
};
static inline bool U8(unsigned char v) { return v; }
struct PFlags { unsigned char b0 : 1; unsigned char b1 : 1; unsigned char b2 : 1; unsigned char b3 : 1; unsigned char rest : 4; };
struct Perc { char pad[0x20]; PFlags f20; char pad21[0x1F]; H h40; bool B2() { return U8(f20.b2); } };
struct Sensed { char pad[0x20]; unsigned char b20; char p21[3]; float f24; char p28[0x11]; unsigned char b39; };
struct Path { V v0; V v10; char pad20[0x30]; int f50; };
struct F1B4 {
    VPAD32(a) VPAD32(b) VPAD2(c)
    virtual int V110(V*);
    char pad4[0x8C];
    int f90;
};
struct Npc {
    VPAD8(a) VPAD4(b) VPAD2(c) VPAD1(d)
    virtual int V44();
    VPAD4(e) VPAD2(f)
    virtual void V60(Obj*, int, int);
    VPAD8(g) VPAD1(h)
    virtual unsigned char V88();
    VPAD8(i) VPAD2(j)
    virtual int VB4();
    VPAD32(k) VPAD8(l)
    virtual void V158();
    VPAD8(m) VPAD4(n) VPAD2(o) VPAD1(p)
    virtual void V198(float, int, int);
    char pad4[0x2C];
    Obj* actor;
    char pad34[0x2C];
    float f60;
    char pad64[0x18];
    float f7C;
    char pad80[0x24];
    int fA4;
    char padA8[0x40];
    int fE8;
    char padEC[0x30];
    int f11C;
    char pad120[4];
    int f124;
    float f128;
    char pad12C[4];
    int f130;
    char pad134[8];
    unsigned char b13C;
    char pad13D[4];
    PFlags f141;
    char pad142[0x12];
    float f154;
    unsigned char b158;
    char pad159[0x53];
    Perc* perc;
    Path* path;
    F1B4* f1B4;
    char pad1B8[4];
    float f1BC;
    float f1C0;
    float f1C4;
};
struct MBase { void* vtable; };
struct Msg : MBase { char pad[0x1C]; unsigned char kind; char pad2[3]; unsigned char b24; char pad3[0xB]; char data[0x40]; };
extern "C" {
extern char g_TeleportMsgClass[], D_004D9360[], D_004EE550[], D_004D9340[], D_004EE698[], D_004D9940[];
void cMessage_ctor_cMessageNameR(void* m, void* type);
void cMessage_dtor(void* m, int flags);
}
struct MsgA : MBase {
    char pad[0x20]; unsigned char b24; char pad2[3]; int f28;
    MsgA(unsigned char m) { MsgA* p = this; cMessage_ctor_cMessageNameR(p, D_004EE550); p->vtable = D_004D9340; p->b24 = m; p->f28 = -1; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~MsgA() { vtable = D_004D9340; cMessage_dtor(this, 0); }
};
struct MsgB : MBase {
    char pad[0x20]; int f24; int f28; int f2C; Obj* f30;
    MsgB(int a, int b, Obj* c) { MsgB* p = this; cMessage_ctor_cMessageNameR(p, D_004EE698); p->vtable = D_004D9940; p->f24 = a; p->f28 = b; p->f30 = c; p->f2C = 0; }
    MsgB(int a, F1B4* s, Obj* c);
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~MsgB() { vtable = D_004D9940; cMessage_dtor(this, 0); }
};

extern "C" {
extern Tree g_NpcThinkList;
extern int g_VideoFrameCounter;
extern int D_004EA3A0;
#if 0 /* merge_units */
extern Npc* D_004EA358;
#endif /* merge_units */
#define D_004EA358 (*(Npc **)&D_004EA358) /* merge_units */

extern unsigned char D_005721D0;
extern Tab SecondaryStateTable[];
void std_list_cActiveListItemPtr_begin_void(Iter* out, Tree* t);
Word* cLListIterator_cActiveListItemPtr_ctor(Word* dst, Word* src);
void std_list_cActiveListItemPtr_end_void(Iter* out, Tree* t);
void cAI_NextFrame(Npc* self, float dt);
void cNPC_DoAction(Npc* self, unsigned char type, int prio, float f);
void cNPC_UpdateMovement(Npc* self);
void cAITarget_Update(Perc* p, float dt);
Sensed* cAITarget_GetAwareness(Perc* p, Obj* o);
int cAITarget_TestPointInViewCone(Perc* p, Perc* q, int a, int b);
void* cAIPathData_GetNode(int id);
void cPathNavigator_AdjustPathForTeleport(Path* p, int id);
V* cVector_ctor_float_float_float_float(V* v, float x, float y, float z, float w);
void cVector_GetNormalized_void(V* out, V* v);
void cVector_Cross(V* out, V* a, V* b);
int cVector_IsZeroXYZ(V* v);
V* cVector_Normalize_void(V* v);
V* cVector_ctor_cVectorR(V* d, V* s);
void cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(M* m, V* a, V* b, V* c, V* t);
void cMatrix_MakeLookAtMatrix_cVectorR(M* m, V* a);
void cMatrix_SetUnit(M* m);
V cNode_GetLoc(void* node);
int cMoveMsg_Template_1_HasDeltaPosition(void* m);
V* func_00133EC0(M* m);
void cVector_Copy_WSet0(V* out, V* v);
void cVector_Copy_WSet1(V* out, V* v);
void cMatrix_ctor_cMatrixR_cVectorR(void* data, M* obj, V* v);
void QueueMessage_cMessageR_cSystemP_int(const MBase& m, void* target, int immediate);
void cNPC_UpdateLookAt(Npc* self, float dt);
void cNPC_HandleWeaponAiming(Npc* self);
void cNPC_HandleWeaponFiring(Npc* self, float dt);
unsigned char cNPC_Update(Npc* self, const MsgA& m);
#if 0 /* merge_units */
int Npc_IsDeadRemovalAllowed(Npc* self);
#endif /* merge_units */
#define Npc_IsDeadRemovalAllowed(a0) ((int)Npc_IsDeadRemovalAllowed((Npc_A *)(a0))) /* merge_units */

void cNPC_NextFrame(Npc* self, float dt);
}

static inline void FCopy(float* d, float* s) { float* ss = s; float* dd = d; *dd = *ss; }

static inline bool Valid(H* h)
{
    Obj* t = h->p;
    int isNull = (t != 0) ^ 1;
    bool ok = true;
    if (!isNull)
        if ((t->id == h->serial) == false)
            ok = false;
    return ok != false;
}
static inline Obj* Get(H* h)
{
    Obj* r; if (Valid(h)) r = *(Obj* volatile*)&h->p; else r = 0; return r;
}
static inline bool ValidP(Perc* p)
{
    Obj* t = p->h40.p;
    int isNull = (t != 0) ^ 1;
    bool ok = true;
    if (!isNull)
        if ((t->id == p->h40.serial) == false)
            ok = false;
    return ok != false;
}
static inline Obj* GetP(Perc* p)
{
    Obj* r; if (ValidP(p)) r = *(Obj* volatile*)&p->h40.p; else r = 0; return r;
}
static inline int PathId(Npc* s) { return s->path->f50; }
static inline bool NotE(Obj* o) { return !(o->b2E != 0); }
static inline bool Active(Obj* o)
{
    bool b = 0;
    bool a = 0;
    if (o->b2D && o->b2C) a = 1;
    if (a && NotE(o)) b = 1;
    return b;
}
static inline bool Dead(Obj* o)
{
    unsigned char m = o->GetMode();
    return m == 3 || m == 2;
}
static inline bool TabOk(Tab* t) { return t->b4C; }
static inline bool PairOk(X* x)
{
    bool r = 0;
    if (TabOk(&SecondaryStateTable[x->b310]) && TabOk(&SecondaryStateTable[x->b311])) r = 1;
    return r;
}
static inline int SightSelf(Perc* p, int b) { Perc* q = p; return cAITarget_TestPointInViewCone(q, p, 1, b); }
static inline bool Ready(Y* y) { return y->f2C8 >= 0.5f; }
static inline void LookFrame(M* m, V* dir, const V& up)
{
    V c;
    cVector_Cross(&c, dir, (V*)&up);
    if (!cVector_IsZeroXYZ(&c)) {
        V f;
        V r;
        V u;
        V w;
        cVector_GetNormalized_void(&f, dir);
        cVector_ctor_cVectorR(&r, cVector_Normalize_void(&c));
        cVector_Cross(&u, &r, &f);
        cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(m, &r, &f, &u, cVector_ctor_float_float_float_float(&w, 0.0f, 0.0f, 0.0f, 1.0f));
    } else if (!cVector_IsZeroXYZ(dir)) {
        cMatrix_MakeLookAtMatrix_cVectorR(m, dir);
    } else {
        cMatrix_SetUnit(m);
    }
}
static inline void TeleInit(Msg* m, M* mtx)
{
    V a2;
    V b2;
    V* v;
    if (cMoveMsg_Template_1_HasDeltaPosition(m)) {
        cVector_Copy_WSet0(&a2, func_00133EC0(mtx));
        v = &a2;
    } else {
        cVector_Copy_WSet1(&b2, func_00133EC0(mtx));
        v = &b2;
    }
    cMatrix_ctor_cMatrixR_cVectorR(m->data, mtx, v);
}

inline MsgB::MsgB(int a, F1B4* s, Obj* c) { MsgB* p = this; int b = s->f90; cMessage_ctor_cMessageNameR(p, D_004EE698); p->vtable = D_004D9940; p->f24 = a; p->f28 = b; p->f30 = c; p->f2C = 0; }
extern "C" void cNPC_NextFrame(Npc* self, float dt)
{
    LNode* it;
    int tmp;
    Word w;
    int tmp2;
    Word w2;
    Iter b;
    Iter e;
    V d;
    M mtx;
    V fwd;
    Msg msg;
    bool leader = 0;
    Obj* actor = self->actor;
    int fr = g_VideoFrameCounter;
    if (D_004EA3A0 == fr) {} else {
        float best = -1.0f;
        std_list_cActiveListItemPtr_begin_void(&b, &g_NpcThinkList);
        cLListIterator_cActiveListItemPtr_ctor(&w, (Word*)&b);
        { int v = w.value; tmp = v; }
        FCopy((float*)&it, (float*)&tmp);
        while (std_list_cActiveListItemPtr_end_void(&e, &g_NpcThinkList), cLListIterator_cActiveListItemPtr_ctor(&w2, (Word*)&e), *(volatile int*)&tmp2 = w2.value, *(int*)&it != *(volatile int*)&tmp2) {
            Obj* o = Get(it->h);
            if (o && Active(o)) {
                Npc* n = o->npc58;
                if (n && n->V44() && n->V88() == 1) {
                    float f = n->f1BC;
                    if (!(f <= best)) {
                        D_004EA358 = n;
                        best = f;
                    }
                }
            }
            it = it->next;
        }
        D_004EA3A0 = g_VideoFrameCounter;
    }
    if (D_004EA358 == self) leader = 1;
    if (!(self->f7C <= 0.0f)) {
        self->f7C -= dt;
        if (self->f7C <= 0.0f) self->V158();
    }
    cAI_NextFrame(self, dt);
    if (!(self->f128 <= 0.0f)) {
        self->f128 -= dt;
        if (self->f128 <= 0.0f && (self->f124 & 8)) cNPC_DoAction(self, 0xB, 0x64, 0.0f);
    }
    cNPC_UpdateMovement(self);
    {
        Obj* tgt = GetP(self->perc);
        RecR* rec;
        Obj* a;
        if (g_IsMultiplayer && (a = self->actor)) {
            rec = 0;
            if (D_005721D0) rec = a->f3584;
            if (rec) {
                if (tgt) {
                    rec->f8 = tgt->id;
                    rec->f4 = tgt->f10;
                    rec->bC = self->f11C;
                } else {
                    rec->f8 = -1;
                    rec->f4 = -1;
                    rec->bC = -1;
                }
            }
        }
        {
            bool c = 0;
            if (self->perc->f20.b0 && self->perc->B2()) c = 1;
            if (!c || (tgt && !Active(tgt)) || self->actor->IsDead()) tgt = 0;
        }
        {
            Wpn* wp = actor->f3524;
            unsigned char k = wp->b84;
            int arg;
            if (k != 6) arg = wp->e[k].c;
            else arg = -1;
            self->V60(tgt, arg, self->f11C);
        }
    }
    if (!self->actor->IsDead()) {
        if (leader) {
            cAITarget_Update(self->perc, self->f1BC);
            if (GetP(self->perc) && !self->VB4() && !self->f130 && self->perc->f20.b3) {
                if (self->actor->f3314 ? PairOk(self->actor->f3314) : 0) {
                    Sensed* r = cAITarget_GetAwareness(self->perc, GetP(self->perc));
                    if (r && r->b39 && r->f24 < 1.0f && (r->b20 == 3 || r->b20 == 4)) {
                        if (SightSelf(self->perc, GetP(self->perc)->f44 >> 1))
                            self->V198(0.0f, self->fA4, -1);
                    }
                }
            }
            if (!g_IsMultiplayer || self->actor->b14) {
                Y* y;
                if ((!self->b158 || ((y = self->actor->f3310) ? Ready(y) : 0)) && self->b13C == 1 && !(self->f60 <= 0.0001f) && !self->actor->b33A5 && self->actor->f320C != 0x1A && self->actor->f320C != 0x10) {
                    V* dp = &d;
                    Path* p = self->path;
                    float ax = AbsN(p->v10.x);
                    float ay = AbsN(p->v10.y);
                    float az = AbsN(p->v10.z);
                    float c;
                    *dp = p->v0;
                    VSub(&d, &d, self->actor->VF4().T());
                    if (!(ax <= ay)) {
                        if (!(ax <= az)) c = AbsZ(d.x);
                        else c = AbsZ(d.z);
                    } else {
                        if (!(ay <= az)) c = AbsZ(d.y);
                        else c = AbsZ(d.z);
                    }
                    if (!(self->f1C0 <= c)) {
                        self->f1C0 = c;
                        self->f1C4 = 0.0f;
                    } else {
                        if (!(self->f1C4 <= 2.0f) && self->path->f50 >= 0) {
                            void* node = cAIPathData_GetNode(PathId(self));
                            cPathNavigator_AdjustPathForTeleport(*(Path* volatile*)&self->path, PathId(self));
                            fwd = self->path->v10;
                            fwd.z = 0.0f;
                            LookFrame(&mtx, &fwd, V(0.0f, 0.0f, 1.0f, 0.0f));
                            mtx.t = cNode_GetLoc(node);
                            {
                                Msg* m = &msg;
                                cMessage_ctor_cMessageNameR(m, g_TeleportMsgClass);
                                m->vtable = D_004D9360;
                                m->b24 = 2;
                                TeleInit(m, &mtx);
                                msg.kind = 1;
                                QueueMessage_cMessageR_cSystemP_int(msg, self->actor, 1);
                                self->f1C4 = 0.0f;
                                self->f1C0 = 999999.0f;
                                msg.vtable = D_004D9360;
                                cMessage_dtor(&msg, 0);
                            }
                        }
                        self->f1C4 += self->f1BC;
                    }
                } else {
                    self->f1C4 = 0.0f;
                    self->f1C0 = 999999.0f;
                }
            }
        }
        cNPC_UpdateLookAt(self, dt);
        cNPC_HandleWeaponAiming(self);
        cNPC_HandleWeaponFiring(self, dt);
        if (self->fE8 > 0) {
            self->fE8--;
            if (self->fE8 == 0) QueueMessage_cMessageR_cSystemP_int(MsgA(3), self, 0);
        }
        cNPC_Update(self, MsgA(2));
        if (leader && self->f1B4) {
            G* g = actor->f50;
            if (self->f1B4->V110(g->GetMtx()->T())) {
                if (!self->f141.b3) {
                    QueueMessage_cMessageR_cSystemP_int(MsgB(0, self->f1B4->f90, actor), self->f1B4, 0);
                    self->f141.b3 = 1;
                }
            } else if (self->f141.b3) {
                QueueMessage_cMessageR_cSystemP_int(MsgB(2, self->f1B4, actor), self->f1B4, 0);
                self->f141.b3 = 0;
            }
        }
    } else if (Npc_IsDeadRemovalAllowed(self)) {
        self->actor->V60(1);
    } else {
        cNPC_HandleWeaponFiring(self, dt);
    }
    if (leader) self->f1BC = 0.0f;
    self->f1BC += dt;
    if (!(self->f154 <= 0.0f)) self->f154 -= dt;
}
#undef D_004EA358 /* merge_units */
#undef Npc_IsDeadRemovalAllowed /* merge_units */
static inline void merge_flush_func_00159590(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00159590 */
