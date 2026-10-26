/*
 * main/npc: range (2 files, 00158BC0-00159020)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop
#include "vslot_pad.h"

/* merge_units: begin func_00158BC0 */
#pragma push /* merge_units */
#pragma opt_propagation off
#pragma cplusplus on
extern "C" {
void* Mem_Alloc(int pool, int size, char* file, int line);
void Script_LookupResource(void* p, int v);
void* NpcPerception_Construct(void* p, void* owner);
void* NpcPath_Construct(void* p, void* owner, int n, int v);
int Random_Next(void);
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
        p = Mem_Alloc(0, sz, D_0049C088, line);
        if (g_ProfileLockEnabled) Alloc_Unlock(9);
        g_ProfileLockDepth--;
        return p;
    }
};

static inline void* NpcNew_8BC0(int sz, int line)
{
    void* p;
    if (g_ProfileLockEnabled) Alloc_Lock(9);
    g_ProfileLockDepth++;
    p = Mem_Alloc(0, sz, D_0049B670, line);
    if (g_ProfileLockEnabled) Alloc_Unlock(9);
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
extern "C" void NpcAi_Construct(Npc_8BC0* self, Own_8BC0* own)
{
    char* t = (char*)self;
    if (own->x3264) {
        if (!*(Trk_8BC0**)(t + 0x18)) {
            *(Trk_8BC0**)(t + 0x18) = new (0x49) Trk_8BC0;
        }
        Script_LookupResource(*(Trk_8BC0**)(t + 0x18), own->x3264);
    }
    if (!*(void**)(t + 0x1AC)) {
        void* p = NpcNew_8BC0(0x60, 0x741);
        if (p) p = NpcPerception_Construct(p, self);
        *(void**)(t + 0x1AC) = p;
    }
    if (!*(void**)(t + 0x1B0)) {
        void* p = NpcNew_8BC0(0x80, 0x745);
        if (p) p = NpcPath_Construct(p, own, 100, own->x3548);
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
    *(float*)(t + 0x6C) = 0.25f + 0.5f * (Random_Next() / 2147483648.0f);
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
void std_list_cNPCPtr_begin(It_A* out, NpcList_A* l);
void std_list_cNPCPtr_end(It_A* out, NpcList_A* l);
It_A* cLListIterator_cNPCPtr_ctor_listR(It_A* dst, It_A* src);
CamHolder_A** List_Front(void* v);
int func_00159570(void* v);
Actor_A* PlayerSlots_Get(int i);
float Math_Cos(float a);
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
            Cam_A* c = (func_00159570(g_CameraObject) ? *List_Front(g_CameraObject) : 0)->cam;
            if (c->b50)
                c->Update();
            pos.Sub(c->pos);
            float d = pos.LenSq();
            if (d < 400.0f || (self->actor->x38 != 0x80 && d < maxSq)) {
                ok = false;
            } else if (g_IsMultiplayer) {
                for (int i = 0; i < 4; i++) {
                    Actor_A* p = PlayerSlots_Get(i);
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
                            if (!(fwd.Dot(pos) + (1.0f - Math_Cos(0.7853982f)) <= 1.0f)) {
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
#pragma pop /* merge_units */
/* merge_units: end func_00159020 */
