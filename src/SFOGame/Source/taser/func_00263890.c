#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma always_inline on
#pragma inline_depth(10)
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c) { void* xx = this; float d = 0.0f; x = a; y = b; z = c; w = d; }
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { V* d = this; const V* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
    V(const V& o, int) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M {
    V r0, r1, r2, t;
    M() {}
    M(const M& o) { M* d = this; __int128 qa; __int128 qb; const M* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
    M& operator=(const M& o) { M* d = this; __int128 qa; const M* s = &o; __int128 qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); return *this; }
    void Unit() { M* d = this; int t; __asm__ volatile("sqc2 vf0, 0x30(%1); qmfc2.ni %0, vf0; pcpyud %0, %0, zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(d) : "memory"); }
} __attribute__((aligned(16)));
static inline void SetVX(V* d, const V& o) { const void* xx = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(&o) : "memory"); }
static inline void SetV(V* d, const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(&o) : "memory"); }
static inline void MulV(V* v, const M* m) { __asm__ volatile("lqc2 $vf8, 0x0(%0); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(v), "r"(m) : "memory"); }
static inline void Add(V* r, const V* a, const V* b) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
static inline V operator*(const V& v, float k) { V r; int t; __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%1); mfc1 %0, %3; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%2); .set reorder" : "=&r"(t) : "r"(&v), "r"(&r), "f"(k) : "memory"); return r; }
struct VI { float x, y, z, w; VI() {}
    VI(const VI& o) { VI* d = this; const VI* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
} __attribute__((aligned(16)));
struct VA { float x, y, z, w; VA() {}
    VA(const VA& o) { VA* d = this; const VA* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
} __attribute__((aligned(16)));
struct VB { float x, y, z, w; VB() {}
    VB(const VB& o) { VB* d = this; const VB* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
} __attribute__((aligned(16)));
static inline VI MulI(const V& v, float k) { VI r; int t; __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%1); mfc1 %0, %3; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%2); .set reorder" : "=&r"(t) : "r"(&v), "r"(&r), "f"(k) : "memory"); return r; }
static inline VB MulB(const V& v, float k) { VB r; int t; __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%1); mfc1 %0, %3; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%2); .set reorder" : "=&r"(t) : "r"(&v), "r"(&r), "f"(k) : "memory"); return r; }
static inline VA ScaleR(const V& v, float k) { __int128 z = 0; VA r; int t; __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%1); mfc1 %0, %3; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%2); .set reorder" : "=&r"(t) : "r"(&v), "r"(&r), "f"(k) : "memory"); return r; }
static inline void Add2(V* pr, const V* pa, const V* pb) { __asm__ volatile("lqc2 vf1, 0x0(%0); lqc2 vf2, 0x0(%2); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%1)" : : "r"(pa), "r"(pr), "r"(pb) : "memory"); }
static inline V operator+(VA a, VB b) { V r; Add2(&r, (V*)&a, (V*)&b); return r; }
static inline V& operator+=(V& a, VI b) { Add(&a, &a, (V*)&b); return a; }
static inline float LenSq(const V& v) { int t; __asm__ volatile("lqc2 vf1, 0x0(%1); vaddw.x vf3, vf0, vf0w; vmul.xyz vf2, vf1, vf1; vmulax.x ACC, vf3, vf2x; vmadday.x ACC, vf3, vf2y; vmaddz.x vf4, vf3, vf2z; qmfc2.ni %0, vf4" : "=r"(t) : "r"(&v) : "memory"); float f; __asm__ volatile("mtc1 %1, %0" : "=f"(f) : "r"(t)); return f; }

struct C3 { float x, y, z; };
struct V4 { float x, y, z, w; V4(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; } V4(const C3& c, float d = 0.0f) { x = c.x; y = c.y; z = c.z; w = d; } };

typedef struct HStr { char d[0x9C]; } HStr;
typedef struct HSnd {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    HStr s78;
    HStr s114;
    char pad1B0[0x10];
} __attribute__((aligned(16))) HSnd;

#define V8(n) virtual void n##0(); virtual void n##1(); virtual void n##2(); virtual void n##3(); virtual void n##4(); virtual void n##5(); virtual void n##6(); virtual void n##7();
struct HTarget {
    V8(a)
    char pad4[8];
    int serial;
    char pad10[0x3260 - 0x10];
    unsigned char x3260;
};
struct HIface {
    V8(a) V8(b)
    virtual void c0(); virtual void c1(); virtual void c2(); virtual void c3(); virtual void c4(); virtual void c5(); virtual void c6();
    virtual void GetMtx(M* m, int a, int b);
};
typedef struct HActor {
    char pad0[0x14];
    unsigned char f14;
    char pad15[0x58 - 0x15];
    HIface* p58;
} HActor;
struct Beam { char pad0[0x14]; float x14; float x18; char pad1c[4]; V4 col; void SetCol(const V4& v) { col.x = v.x; col.y = v.y; col.z = v.z; col.w = v.w; } };
static inline void SetCol(Beam* b, const V4& v) { b->col.x = v.x; b->col.y = v.y; b->col.z = v.z; b->col.w = v.w; }
struct Pt { V pos; V vel; V acc; V pad; };
struct TVec { int unk0; int count; Pt* data; };
struct Arr { Pt* data; Pt& operator[](int i) { Arr* t = this; return t->data[i]; }
    Pt& Back(int n) { Arr* t = this; Pt* e = t->data + n; return e[-1]; } };
struct Seg { void* tr; float t; int pad8; int padC; M m; };
typedef struct LNode { struct LNode* prev; struct LNode* next; char pad8[8]; Seg data; } LNode;
typedef struct LHead { LNode* prev; LNode* next; } LHead;
struct It { LNode* n; It() {} It(LNode* p) : n(p) {} It(LNode* p, int) { void* xx = this; n = p; } It(const It& o) { void* xx = this; n = o.n; } It& operator=(const It& o) { n = o.n; return *this; } };

typedef struct HeldItem {
    void* def;
    HActor* actor;
    unsigned char state;
    char pad9[3];
    Beam* beam;
    int pad10;
    int count;
    Arr pos;
    int pad1C;
    int list;
    LHead head;
    HTarget* hp;
    int hserial;
    char pad34[8];
    int x3C;
    V x40;
    char pad50[0xB4 - 0x50];
    float xB4;
    float xB8;
    unsigned char bBC;
    unsigned char bBD;
} HeldItem;

extern "C" {
extern void QueueMessage_cMessageR_cSystemP_int(void* msg, void* target, int immediate);
extern void cMessage_dtor(void* msg, int flags);
extern void cHuman_SetParticleEffect(HTarget* a, int kind, int b, float f);
extern void cPlaySoundMsg_ctor_cSndFxR(HSnd* e, void* preset, void* owner);
extern void cFileMan_dtor(HStr* s, int flag);
extern LHead* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_6(LHead* p);
extern LNode* std_list_deleter_TaserPulse_tail(int* list);
extern void std_list_deleter_TaserPulse_generic_iterator_ctor(It* it, LNode* n);
extern void std_list_deleter_TaserPulse_erase_listdeleter(It* res, int* list, It* pos);
extern void std_list_deleter_TaserPulse_insert(It* res, int* list, It* pos, Seg* e);
extern void cParticle_dtor(void* p, int flag);
extern void cMemMan_Deallocate(int pool, void* p, char* file, int line);
extern void* cMemMan_Allocate(int pool, int size, char* file, int line);
extern int Libc_Rand(void);
extern void cAirTaser_Release(HeldItem* s);
extern int cAirTaser_LosBlocked(HeldItem* s);
extern int* cSystem_GetObjectID_void(HTarget* t);
extern int opEq(int* a, int* b);
extern int cSKM_GOBJ_GetSkeleton_void(HTarget* t);
extern M cSkeleton_GetBoneToWorldMatrix(int model, int node);
extern void cSkeleton_GetBoneToWorldTranslation(V* out, int model, int node);
extern void cAirTaser_PointsToLocal(HeldItem* s, V* p);
extern void cAirTaser_AddTension(HeldItem* s, int flag, float dt);
extern Pt* std_vector_TaserPoint_opIndex(int* v, int i);
extern void cAirTaser_PointsToWorld(HeldItem* s, V* p);
extern void cAirTaser_SmoothLine(HeldItem* s, int a, float f);
extern void cParticle_NextFrame(void* t, float dt, M* m, int z);
extern void* cParticle_ctor(void* p, int id, M* m, float f);
extern int cParticleSystem_GetEffectID(void* a, char* b);
extern void SfxParticleEffect_eEffectName_cMatrixR(int id, M* m);

extern signed char ActorNodeCodeTable[];
extern char D_004A81E8[];
extern char D_004A8200[];
extern char D_004DAE30[];
extern char D_004F1470[];
extern char D_004F1610[];
extern char g_Game[];
extern char D_0053B540[];
extern signed char D_004F8360;
extern M D_004F8370;
extern float D_0048B118;
extern float D_0048B120;
extern float D_0048B188;
extern float D_0048B190;
extern float D_0048B198;
extern float D_0048B1A0;
extern float D_0048B1C0;
}

static inline bool HSame(HTarget* t, const int* s) { return t->serial == *s; }
static inline bool HValid(HeldItem* h) { return !h->hp || HSame(h->hp, &h->hserial); }
static inline HTarget* Handle_Get(HeldItem* h) { return HValid(h) ? h->hp : 0; }
static inline bool HValid2(HeldItem* h) { return !h->hp || opEq(cSystem_GetObjectID_void(h->hp), &h->hserial); }
static inline HTarget* Handle_Get2(HeldItem* h) { return HValid2(h) ? h->hp : 0; }


static inline V SkelPos(HTarget* t) { V v; cSkeleton_GetBoneToWorldTranslation(&v, cSKM_GOBJ_GetSkeleton_void(t), ActorNodeCodeTable[0]); return v; }
static inline void MulV3(V* o, const V* v, const M* m) { __asm__ volatile("lqc2 $vf8, 0x0(%2); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(o), "r"(m), "r"(v) : "memory"); }
static inline void XformBy(V* v, const M& m) { const M* pm = &m; MulV3(v, v, &m); }
static inline void XformBone(V* p, HTarget* t, unsigned char b) { XformBy(p, cSkeleton_GetBoneToWorldMatrix(cSKM_GOBJ_GetSkeleton_void(t), ActorNodeCodeTable[b])); }
static inline int BoneId(unsigned char b) { return ActorNodeCodeTable[b]; }
static inline M BoneR(HTarget* t, unsigned char b) { return cSkeleton_GetBoneToWorldMatrix(cSKM_GOBJ_GetSkeleton_void(t), ActorNodeCodeTable[b]); }
#pragma enumsalwaysint off
enum BoneE { BONE_0 = 0, BONE_MAX = 0xFF };
#pragma enumsalwaysint reset
static inline M BoneRE(HTarget* t, BoneE b) { return cSkeleton_GetBoneToWorldMatrix(cSKM_GOBJ_GetSkeleton_void(t), ActorNodeCodeTable[b]); }
static inline M BoneR2(HTarget* t, int b) { return cSkeleton_GetBoneToWorldMatrix(cSKM_GOBJ_GetSkeleton_void(t), ActorNodeCodeTable[(unsigned char)b]); }
static inline void SetSkel(M* fx, HTarget* t) { V v; cSkeleton_GetBoneToWorldTranslation(&v, cSKM_GOBJ_GetSkeleton_void(t), ActorNodeCodeTable[0]); fx->t = v; }
struct SegT { void* tr; float t; int pad8; int padC; M m; SegT(void* p, const M& mm) : tr(p), t(0.0f), m(mm) {} };
static inline void PushBack(int* l, LHead* h, const SegT& v) { It res; It where((LNode*)h, 0); It* pw = &where; std_list_deleter_TaserPulse_insert(&res, l, pw, (Seg*)&v); }
static inline void* NewMem(int sz, int line) { AllocGuard g; return cMemMan_Allocate(0, sz, D_004A81E8, line); }
static inline void PushBack2(int* l, LHead* h, const SegT& v) { PushBack(l, h, v); }
static inline void Del(void* p, int line) {
    AllocGuard g;
    cParticle_dtor(p, -1);
    cMemMan_Deallocate(0, p, D_004A81E8, line);
}

static inline It Begin(LHead* h) { It r; r.n = details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_6(h)->next; return r; }
static inline It End(int* l) { It e; std_list_deleter_TaserPulse_generic_iterator_ctor(&e, std_list_deleter_TaserPulse_tail(l)); return e; }
static inline It End2(int* l) { return End(l); }
static inline bool operator!=(const It& a, const It& b) { return a.n != b.n; }
static inline It Erase(int* l, const It& where) { It res; It tmp = where; std_list_deleter_TaserPulse_erase_listdeleter(&res, l, &tmp); return res; }

static inline void SetV0(V* d, const V& o) { SetV(d, o); }
static inline VA SR0(const V& v, float k) { return ScaleR(v, k); }
static inline VI MI0(const V& v, float k) { return MulI(v, k); }
static inline void Integrate(HeldItem* s, float dt) {
        int n = s->count;
        for (int i = 1; i < n; i++) {
            std_vector_TaserPoint_opIndex(&s->pad10, i)->vel += MI0(std_vector_TaserPoint_opIndex(&s->pad10, i)->acc, dt);

        }
}
static inline float Inv(const V& v) { float l = 0.0f; l = LenSq(v); return 1.0f / l; }
static inline void SetBeam(HeldItem* s, const C3& c) {
            float k = D_0048B188;
            Beam* bb = s->beam;
            bb->x14 = k;
            Beam* b = s->beam;
            b->SetCol(V4(c));
            float l = 0.0f;
            l = LenSq(V(c.x, c.y, c.z, 0.0f));
            b->x18 = 1.0f / l;
}
extern "C" void cAirTaser_UpdateShock(HeldItem* s, float dt)
{
    if (Handle_Get(s) && !(s->actor->f14 && cAirTaser_LosBlocked(s)) && s->count > 0) {
        if (s->x3C > -1) {
            V p(s->x40, 0);
            XformBy(&p, BoneRE(Handle_Get2(s), (BoneE)s->x3C));

            s->pos.Back(s->count).pos = p;
        }
        M mtx;
        s->actor->p58->GetMtx(&mtx, 0, 0);
        cAirTaser_PointsToLocal(s, &mtx.t);
        cAirTaser_AddTension(s, 1, dt);
        Integrate(s, dt);
        cAirTaser_PointsToWorld(s, &mtx.t);
        cAirTaser_SmoothLine(s, 0, D_0048B1C0);
        float big = 2147483648.0f; float r = (float)Libc_Rand() / (1.0f + big);
        C3 c;
        c.x = r;
        c.y = r;
        c.z = 1.0f;
        if (s->beam) {
            SetBeam(s, c);
        }
        s->xB4 += dt;
        s->xB8 += dt;
        for (It it = Begin(&s->head); it != End(&s->list); ) {
            Seg* e = &it.n->data;
            e->t += dt * D_0048B190;
            int lc = s->count - 1;
            if (e->t >= (float)lc) {
                Del(e->tr, 0x229);
                it = Erase(&s->list, it);
            } else {
                M m2;
                m2 = mtx;
                float fr = e->t - (float)(int)e->t;
                V q = SR0(s->pos[(int)e->t].pos, 1.0f - fr) + MulB(std_vector_TaserPoint_opIndex(&s->pad10, (int)(1.0f + e->t))->pos, fr);

                SetV0(&m2.t, q);
                { M* pe = &e->m; const M* ps = &m2; *pe = *ps; }
                cParticle_NextFrame(e->tr, dt, &m2, 0);
                it.n = it.n->next;
            }
        }
        if (!(s->xB8 <= D_0048B198)) {
            void* p;
            s->xB8 = 0.0f;
            p = NewMem(0x70, 0x23B);
            if (p) p = cParticle_ctor(p, cParticleSystem_GetEffectID(D_0053B540, D_004A8200), &mtx, D_0048B1A0);
            PushBack2(&s->list, &s->head, SegT(p, mtx));

        }
        if (!s->bBC) {
            if (!(s->xB4 <= D_0048B120)) {
                void* preset = Handle_Get(s)->x3260 == 1 ? D_004F1610 : D_004F1610;
                HSnd a;
                HSnd b;
                cPlaySoundMsg_ctor_cSndFxR(&a, preset, Handle_Get(s));
                a.flag = 1;
                QueueMessage_cMessageR_cSystemP_int(&a, g_Game, 0);
                cPlaySoundMsg_ctor_cSndFxR(&b, D_004F1470, Handle_Get(s));
                b.flag = 1;
                QueueMessage_cMessageR_cSystemP_int(&b, g_Game, 0);
                if (!D_004F8360) D_004F8360 = 1;
                D_004F8370.Unit();
                { V sk; cSkeleton_GetBoneToWorldTranslation(&sk, cSKM_GOBJ_GetSkeleton_void(Handle_Get(s)), ActorNodeCodeTable[0]); SetVX(&D_004F8370.t, sk); }

                SfxParticleEffect_eEffectName_cMatrixR(10, &D_004F8370);
                cHuman_SetParticleEffect(Handle_Get(s), 0, 1, 1.0f);
                s->bBC = 1;
                b.vt = D_004DAE30;
                cFileMan_dtor(&b.s114, -1);
                cFileMan_dtor(&b.s78, -1);
                cMessage_dtor(&b, 0);
                a.vt = D_004DAE30;
                cFileMan_dtor(&a.s114, -1);
                cFileMan_dtor(&a.s78, -1);
                cMessage_dtor(&a, 0);
            } else if (!(s->xB4 <= D_0048B118)) {
                s->bBD = 1;
            }
        }
    } else {
        cAirTaser_Release(s);
    }
}
