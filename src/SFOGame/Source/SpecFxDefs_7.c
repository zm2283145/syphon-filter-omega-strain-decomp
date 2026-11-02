/*
 * SFOGame/Source/SpecFxDefs: 4 files, 00234860-00234BB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00234860 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "obj_list_dtor.h"

/* Destroy an object list: erase all nodes, optionally delete. */
DEFINE_OBJ_LIST_DTOR(std_list_cElementPtr_dtor_void)
static inline void merge_flush_func_00234860(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00234860 */

/* merge_units: begin func_002348E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(10)

#include "types.h"

struct V4 {
    float x, y, z, w;
    V4() {}
    V4(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V4(const V4& o) { V4* d = this; const V4* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); }
    V4& operator=(const V4& o) { V4* d = this; const V4* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
} __attribute__((aligned(16)));

struct Box0 { V4 lo, hi; };
struct Box : Box0 {
    Box() { Init(); }
    void Init() {
        lo.x = 3.4028235e38f; lo.y = 3.4028235e38f; lo.z = 3.4028235e38f; lo.w = 1.0f;
        hi.x = -3.4028235e38f; hi.y = -3.4028235e38f; hi.z = -3.4028235e38f; hi.w = 1.0f;
    }
    void Extend(V4* p) { V4* l = &lo; V4* h = &hi; __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); lqc2 $vf3, 0x0(%2); vmini.xyz $vf1, $vf1, $vf3; vmax.xyz $vf2, $vf2, $vf3; sqc2 $vf1, 0x0(%0); sqc2 $vf2, 0x0(%1)" : : "r"(l), "r"(h), "r"(p) : "memory"); }
    void Grow(float h) {
        V4 p(-h, -h, -h, 1.0f);
        Extend(&p);
        V4 q(h, h, h, 1.0f);
        Extend(&q);
    }
    void Reset() {
        lo = V4(3.4028235e38f, 3.4028235e38f, 3.4028235e38f, 1.0f);
        hi = V4(-3.4028235e38f, -3.4028235e38f, -3.4028235e38f, 1.0f);
    }
};

typedef struct { int x0; int x4; int x8; } L_SF;
typedef struct { int a; int b; } FxDef;
typedef struct { unsigned char flag; char pad[7]; } FxFlag;
typedef struct { char pad[0xC]; int xC; } PDef;

struct SnowSelf {
    int f0; char p4[43]; signed char f2F; char p30[48]; int f60; int f64; short f68; char p6A[6]; int f70;
    L_SF list;
    Box box;
    V4 last;
    float fB0;
    float size;
    float fB8;
    int fBC;
    int weight;
    int c4;
    signed char id;
};

extern "C" {
extern char D_004DF860[];
extern char SnowField_vtable[];
extern FxFlag D_004F7A54[];
extern FxDef SpecFxTable[];
extern char D_0053B544[];
int nGobjManager_GetNextId(int*, int);
int cGOBJ_ctor(SnowSelf*, int*, int, int*);
void std_list_deleter_voidPtr_ctor_void(L_SF*);
#if 0 /* merge_units */
void std_list_deleter_voidPtr_erase_listdeleter_listdeleter(int* out, L_SF* l, int* first, int** last);
#endif /* merge_units */
#define std_list_deleter_voidPtr_erase_listdeleter_listdeleter(a0, a1, a2, a3) (std_list_deleter_voidPtr_erase_listdeleter_listdeleter((ObjListNode * *)(a0), (ObjList *)(a1), (ObjListNode * *)(a2), (ObjListNode * *)(a3))) /* merge_units */


#if 0 /* merge_units */
PDef** cLList_cParticleDefinitionPtr_opIndex(void* p, int n);
#endif /* merge_units */
void* cLList_cParticleDefinitionPtr_opIndex(void* self, int n); /* merge_units */
#define cLList_cParticleDefinitionPtr_opIndex(a0, a1) ((PDef * *)cLList_cParticleDefinitionPtr_opIndex((a0), (a1))) /* merge_units */

void RainSnowPool_Create(int w);
}

static inline FxDef* GetDef_(int id)
{
    if ((unsigned int)id < 41) return &SpecFxTable[id];
    return 0;
}
static inline FxDef* GetDef(signed char id)
{
    if (!D_004F7A54[id].flag) return 0;
    return GetDef_(id);
}

extern "C" SnowSelf* cSnowEffect_ctor(SnowSelf* self, signed char id, int weight, float a, float b, float c)
{
    int gid;
    int z;
    int r;
    int first;
    int* last;
    int* lp;
    nGobjManager_GetNextId(&gid, 0xE7);
    z = 0;
    cGOBJ_ctor(self, &gid, 4, &z);
    self->f0 = (int)D_004DF860;
    self->f60 = -1;
    self->f64 = 0;
    self->f68 = 0;
    self->f70 = 0x3F800000;
    self->f2F = 1;
    self->f0 = (int)SnowField_vtable;
    std_list_deleter_voidPtr_ctor_void(&self->list);
    lp = &self->list.x4;
    self->box.Init();
    last = lp;
    first = self->list.x8;
    { int** pl = &last; int* pf = &first; int* pr = &r; L_SF* ll = &self->list; std_list_deleter_voidPtr_erase_listdeleter_listdeleter(pr, ll, pf, pl); }
    self->id = id;
    self->fB0 = a;
    self->size = b;
    self->fB8 = c;
    self->weight = weight;
    self->box.Reset();
    self->box.Grow(0.5f * self->size);
    self->fBC = 0;
    self->c4 = GetDef(id)->a;
    if (self->c4 >= 0) {
        PDef** pp = cLList_cParticleDefinitionPtr_opIndex(D_0053B544, self->c4);
        if (*pp) self->fBC = (*pp)->xC;
        RainSnowPool_Create(weight);
    }
    return self;
}
#undef std_list_deleter_voidPtr_erase_listdeleter_listdeleter /* merge_units */
#undef cLList_cParticleDefinitionPtr_opIndex /* merge_units */
static inline void merge_flush_func_002348E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002348E0 */

/* merge_units: begin func_00234BB0 */
#pragma push /* merge_units */
typedef struct LNode00234BB0 { struct LNode00234BB0* prev; struct LNode00234BB0* next; char data[1]; } LNode00234BB0;
typedef struct { int pad; LNode00234BB0* head; } LHdr00234BB0;
typedef struct { LNode00234BB0* node; } LIt00234BB0;
extern LHdr00234BB0* std_list_deleter_voidPtr_tail(void* self);
extern void std_list_deleter_voidPtr_generic_iterator_ctor_nodeP(LIt00234BB0* it, LNode00234BB0* n);
void* cLList_cParticleDefinitionPtr_opIndex(void* self, int n)
{
    LIt00234BB0 it;
    LNode00234BB0* p;
    std_list_deleter_voidPtr_generic_iterator_ctor_nodeP(&it, std_list_deleter_voidPtr_tail(self)->head);
    p = it.node;
    if (n >= 0) {
        while (n > 0) {
            p = p->next;
            n--;
        }
    } else {
        while (n < 0) {
            p = p->prev;
            n++;
        }
    }
    return p->data;
}
static inline void merge_flush_func_00234BB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00234BB0 */

/* merge_units: begin func_00234C40 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(10)
#include "vslot_pad.h"
#include "alloc_guard.h"
#include "vu0_ops.h"

struct V4_00234C40 {
    float x, y, z, w;
    V4_00234C40() {}
    V4_00234C40(const V4_00234C40& o) { V4_00234C40* d = this; const V4_00234C40* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); }
    V4_00234C40& operator=(const V4_00234C40& o) { V4_00234C40* d = this; const V4_00234C40* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
} __attribute__((aligned(16)));

struct M4 { V4_00234C40 r0, r1, r2, r3; V4_00234C40& Pos() { return r3; } V4_00234C40& Fwd() { return r1; } };

static inline void OpS(V4_00234C40* pr, const V4_00234C40* pa, const V4_00234C40* pb)
{
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(pr), "r"(pa), "r"(pb) : "memory");
}
static inline V4_00234C40 operator-(const V4_00234C40& a, const V4_00234C40& b) { V4_00234C40 r; OpS(&r, &a, &b); return r; }
static inline void OpA(V4_00234C40* pr, const V4_00234C40* pa, const V4_00234C40* pb)
{
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(pr), "r"(pa), "r"(pb) : "memory");
}
static inline V4_00234C40 operator+(const V4_00234C40& a, const V4_00234C40& b) { V4_00234C40 r; OpA(&r, &a, &b); return r; }
static inline void OpMZ(V4_00234C40* pr, const V4_00234C40* pa, float s)
{
    __int128 t = 0;
    __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(pr), "r"(pa), "f"(s) : "memory");
}
static inline V4_00234C40 operator*(const V4_00234C40& a, float s) { V4_00234C40 r; OpMZ(&r, &a, s); return r; }

static inline float Length(V4_00234C40 v)
{
    float r = 0.0f;
    int t;
    V4_00234C40* p = &v;
    asm {
        lqc2 vf1, 0x0(p)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vsqrt Q, vf3w
        vwaitq
        vaddq.x vf4, vf0, Q
        qmfc2.ni t, vf4
        mtc1 t, r
    }
    return r;
}
static inline void NormalizeLen(V4_00234C40* v, float* len)
{
    __int128 t = 0; float* l = len;
    asm {
        lqc2 vf1, 0x0(v)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vsqrt Q, vf3w
        vwaitq
        vaddq.x vf4, vf0, Q
        vdiv Q, vf0w, vf4x
        vwaitq
        vmulq.xyz vf1, vf1, Q
        sqc2 vf1, 0x0(v)
        qmfc2.ni t, vf4
        sw t, 0x0(l)
    }
}
static inline float Sqrt(float x)
{
    float r = 0.0f;
    asm { sqrt.s r, x }
    return r;
}

static inline float Abs(float x) { float r = 0.0f; asm { abs.s r, x } return r; }
class CamObj {
public:
    VPAD32(a) VPAD16(b) VPAD8(c) VPAD2(d) VPAD1(e)
    virtual M4 GetMtx();
};

struct Tracer4C { char pad[0x5C]; float alpha; };
struct Entry4C {
    Tracer4C* t;
    int pad[3];
    V4_00234C40 pos;
    Entry4C() { t = 0; }
};
struct LNode4C { LNode4C* prev; LNode4C* next; Entry4C* value; };
struct It4C { LNode4C* n; Entry4C*& operator*() { return n->value; } };
struct Eq4C {};
struct Pred4C { Eq4C op; Entry4C** ref; Pred4C(const Eq4C& e, Entry4C** r) : op(e), ref(r) {} };

struct Self4C {
    char p0[0x74];
    char list[0x1C];
    V4_00234C40 lastPos;
    int count;
    float spacing;
    float minDist;
    float fadeStart;
    float radius;
    float alpha;
};

extern "C" {
extern char D_004A6E38[];
extern char D_004A6F48[];
extern char g_CameraObject[];
CamObj** cLList_cCAMERA_GOBJPtr_Front(void* p);
void std_list_cElementPtr_push_back_cElementPR_2(void* list, Entry4C** v);
void std_list_cElementPtr_end_void_2(It4C* out, void* list);
It4C* cLListIterator_cElementPtr_ctor_listR_2(It4C* dst, It4C* src);
void std_list_cElementPtr_begin_void_2(It4C* out, void* list);
void std_list_imp_voidPtr_remove_if(void* list, Pred4C p);
void cParticle_dtor(Tracer4C* t, int n);
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
void* cMemMan_Allocate(int pool, int size, char* file, int line);
Tracer4C* cParticle_ctor(void* p, int id, M4* m, float scale);
void cParticle_NextFrame(Tracer4C* t, M4* m, float dt, int z);
int Libc_Rand(void);
float Libc_Atan2f(float y, float x);
float Libc_Sinf(float a);
float Libc_Cosf(float a);
}
static inline FxDef* GetDef_00234C40(int id)
{
    if (!D_004F7A54[id].flag) return 0;
    return GetDef_(id);
}
struct F4C { float f; };
static inline void Begin0(It4C* out, void* l) { It4C t; std_list_cElementPtr_begin_void_2(&t, l); cLListIterator_cElementPtr_ctor_listR_2(out, &t); }
static inline void BeginM2(It4C* o, void* l) { Begin0(o, l); }
static inline void BeginM(It4C* o, void* l) { BeginM2(o, l); }
static inline void Begin(It4C* out, void* l) { It4C t2; BeginM(&t2, l); F4C* s = (F4C*)&t2; F4C* d = (F4C*)out; *d = *s; }
static inline void End(It4C* out, void* l) { It4C t; std_list_cElementPtr_end_void_2(&t, l); cLListIterator_cElementPtr_ctor_listR_2(out, &t); }
static inline void EndM2(It4C* o, void* l) { End(o, l); }
static inline void EndM(It4C* o, void* l) { EndM2(o, l); }
static inline bool NotEnd(It4C* it, void* l) { It4C end; EndM(&end, l); return it->n != end.n; }
static inline Entry4C* NewEntry(int line)
{
    Entry4C* e;
    {
        AllocGuard g;
        e = (Entry4C*)cMemMan_Allocate(0, 0x20, D_004A6E38, line);
    }
    if (e) e->t = 0;
    return e;
}
static inline float Fade(Self4C* self, float d)
{
    float a = self->alpha;
    if (!(d < self->radius)) {
        a = 0.0f;
    } else if (!(d <= self->fadeStart)) {
        a *= 1.0f - (d - self->fadeStart) / (self->radius - self->fadeStart);
    }
    return a;
}

static inline void UM(void* p) {
    void* d = p;
    __int128 t;
    __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(d) : "memory");
}
#define FXID(s) (*(signed char*)((char*)(s) + 0x80))
static inline void FreeTracer(Tracer4C* t)
{
    if (t) {
        AllocGuard g2;
        cParticle_dtor(t, -1);
        cMemMan_Deallocate(0, t, D_004A6F48, 0x12A);
    }
}
static inline void FreeEntry(Entry4C* e)
{
    AllocGuard g;
    if (e) {
        FreeTracer(e->t);
    }
    cMemMan_Deallocate(0, e, D_004A6E38, 0x2F7);
}
static inline Tracer4C* MakeTracer(Self4C* self, M4* m, int line)
{
    void* p;
    {
        AllocGuard g;
        p = cMemMan_Allocate(0, 0x70, D_004A6E38, line);
    }
    if (p) p = cParticle_ctor(p, GetDef_00234C40(FXID(self))->a, m, 1.0f);
    return (Tracer4C*)p;
}
static inline void Erase4C(void* l, Entry4C** v) { Eq4C eq; std_list_imp_voidPtr_remove_if(l, Pred4C(eq, v)); }

static inline void FreeEntryM(Entry4C* e) { FreeEntry(e); }
static inline void Erase4CM2(void* l, Entry4C** v) { Erase4C(l, v); }
static inline void Erase4CM(void* l, Entry4C** v) { Erase4CM2(l, v); }
static inline Entry4C* NewEntryM(int line) { return NewEntry(line); }
static inline Tracer4C* MakeTracerM(Self4C* self, M4* m, int line) { return MakeTracer(self, m, line); }
static inline unsigned char IsZ3(void* v) {
    int k, f; int r = 0;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyz vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xE
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        bne k, f, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}
static inline float Frand() { int r = Libc_Rand(); return 4.656613e-10f * (float)r; }
extern "C" void cCameraAtmosphericEffect_NextFrame(Self4C* self, float dt)
{
    M4 m;
    float len;
    It4C it;
    It4C cit;
    Entry4C* ne;
    Entry4C* ne2;
    FxDef* def;
    CamObj* cam;
    V4_00234C40 camPos;
    float heading;
    int n;
    int i;
    int k;
    bool found;
    Entry4C* e;
    float a;

    UM(&m);
    def = GetDef_00234C40(FXID(self));
    cam = *cLList_cCAMERA_GOBJPtr_Front(g_CameraObject);
    if (!def || def->a < 0 || !cam) return;
    camPos = cam->GetMtx().Pos();
    V4_00234C40 dir = camPos - self->lastPos;
    if (IsZ3(&dir)) {
        dir = cam->GetMtx().Fwd();
        len = 0.0f;
    } else {
        NormalizeLen(&dir, &len);
    }
    heading = Libc_Atan2f(-dir.x, dir.y);

    for (Begin(&it, self->list); NotEnd(&it, self->list); ) {
        cit = it;
        e = *cit;
        it.n = it.n->next;
        {
            float d = Length(camPos - e->pos);
            float al = self->alpha;
            if (!(d <= 10.0f + self->radius)) {
                Erase4CM(self->list, &cit.n->value);
                FreeEntryM(e);
            } else {
                if (!(d < self->radius)) {
                    al = 0.0f;
                } else if (!(d <= self->fadeStart)) {
                    al *= 1.0f - (d - self->fadeStart) / (self->radius - self->fadeStart);
                }
                e->t->alpha = al;
            }
        }
    }

    if (*(int*)self->list == 0) {
        n = (int)(5.0f * self->radius / self->minDist);
        for (i = 0; i < n; i++) {
            ne = NewEntryM(0x30C);
            if (ne) {
                float r1 = Frand();
                float ang = 6.2831855f * Frand();
                Tracer4C* t;
                V4_00234C40 off;
                off.x = Libc_Cosf(ang);
                off.y = Libc_Sinf(ang);
                off.z = 0.0f;
                off.w = 0.0f;
                r1 = self->radius * Sqrt(r1);
                m.Pos() = cam->GetMtx().Pos() + off * r1;
                t = MakeTracerM(self, &m, 0x318);
                ne->t = t;
                ne->pos = m.r3;
                ne->t->alpha = Fade(self, Length(camPos - ne->pos));
                std_list_cElementPtr_push_back_cElementPR_2(self->list, &ne);
            }
        }
    }

    for (k = 0; k < self->count; k++) {
        V4_00234C40 spot;
        found = 0;
        a = self->spacing * (float)(k - (self->count >> 1));
        a += heading;
        for (;;) {
            if (!(a <= 3.1415927f)) {
                a += -6.2831855f;
            } else if (a < -3.1415927f) {
                a += 6.2831855f;
            } else {
                break;
            }
        }
        spot.z = camPos.z - self->lastPos.z;
        { float s = Libc_Sinf(a); spot.x = -s * (1.0f - Abs(spot.z)); }
        { float c = Libc_Cosf(a); spot.y = c * (1.0f - Abs(spot.z)); }
        spot.w = 0.0f;
        spot = camPos + spot * self->radius;
        for (Begin(&it, self->list); NotEnd(&it, self->list); it.n = it.n->next) {
            if (Length((*it)->pos - spot) < self->minDist) {
                found = 1;
                break;
            }
        }
        if (!found) {
            ne2 = NewEntryM(0x342);
            if (ne2) {
                Tracer4C* t;
                m.Pos() = spot;
                t = MakeTracerM(self, &m, 0x346);
                ne2->t = t;
                ne2->t->alpha = 0.0f;
                ne2->pos = m.r3;
                std_list_cElementPtr_push_back_cElementPR_2(self->list, &ne2);
            }
        }
    }

    for (Begin(&it, self->list); NotEnd(&it, self->list); it.n = it.n->next) {
        Entry4C* e3 = *it;
        m.Pos() = e3->pos;
        cParticle_NextFrame(e3->t, &m, dt, 0);
    }
    self->lastPos = camPos;
}
static inline void merge_flush_func_00234C40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00234C40 */
