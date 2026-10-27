/*
 * SFOGame/Source/SpecFxDefs: 4 files, 00232C00-00232EE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00232C00 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern void* g_LocalPlayer;
extern char D_004A6E38[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void cPlayer_AtmosphericParticleEffect(void* w, void* o);
void* cSnowEffect_ctor(void* p, signed char type, float a, void* src, float b, float c);
void* cCameraAtmosphericEffect_ctor(void* p, signed char type, float a, float b, float c, float d);
}
static inline void* GAlloc(int sz, int line)
{
    AllocGuard g;
    return cMemMan_Allocate(0, sz, D_004A6E38, line);
}
extern "C" void SfxAtmosphericParticleEffect_eEffectName_float_float_float_etc(signed char type, void* src, float a, float b, float c, float d)
{
    void* w = g_LocalPlayer;
    cPlayer_AtmosphericParticleEffect(w, 0);
    if (type == 0x16 || type == 0x17 || type == 0x18) {
        void* p = GAlloc(0xD0, 0x4CD);
        if (p) p = cSnowEffect_ctor(p, type, b, src, c, d);
        cPlayer_AtmosphericParticleEffect(w, p);
    } else {
        void* p = GAlloc(0xC0, 0x4D2);
        if (p) p = cCameraAtmosphericEffect_ctor(p, type, a, b, c, d);
        cPlayer_AtmosphericParticleEffect(w, p);
    }
}
static inline void merge_flush_func_00232C00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00232C00 */

/* merge_units: begin func_00232E00 */
#pragma push /* merge_units */
#include "vu0_ops.h"

typedef struct ListNode232E00 {
    struct ListNode232E00* prev;
    struct ListNode232E00* next;
    struct LightRef232E00* value;
} ListNode232E00;

typedef struct LightRef232E00 {
    void* obj;
    char pad4[5];
    unsigned char enabled;
} LightRef232E00;

typedef struct {
    ListNode232E00* node;
} ListIt232E00;

typedef struct {
    char pad0[0x38];
    int key;
    char pad3C[0x74 - 0x3C];
    char list[8];
} Fx232E00;

typedef struct {
    Vec4 r[4];
} Mtx232E00;

#if 0 /* merge_units */
extern void std_list_cElementPtr_begin_void(ListIt232E00* out, void* list);
#endif /* merge_units */
void std_list_cElementPtr_begin_void(); /* merge_units */

#if 0 /* merge_units */
extern void std_list_cElementPtr_end_void(ListIt232E00* out, void* list);
#endif /* merge_units */
void std_list_cElementPtr_end_void(); /* merge_units */

#if 0 /* merge_units */
extern ListIt232E00* cLListIterator_cElementPtr_ctor_listR(ListIt232E00* dst, ListIt232E00* src);
#endif /* merge_units */
Word * cLListIterator_cElementPtr_ctor_listR(); /* merge_units */

extern void cParticle_Render(void* obj, int key, Mtx232E00* m);

#pragma push
#pragma opt_rotateloops off
void cSnowEffect_Render(Fx232E00* self) {
    ListIt232E00 it;
    ListIt232E00 first;
    ListIt232E00 last;
    ListIt232E00 tmpBegin;
    ListIt232E00 tmpEnd;
    Mtx232E00 m;

    VU0_UnitMatrix(&m);
    std_list_cElementPtr_begin_void(&tmpBegin, self->list);
    cLListIterator_cElementPtr_ctor_listR(&first, &tmpBegin);
    it = first;
    while (std_list_cElementPtr_end_void(&tmpEnd, self->list), cLListIterator_cElementPtr_ctor_listR(&last, &tmpEnd), it.node != last.node) {
        if (it.node->value->obj != 0 && it.node->value->enabled) {
            cParticle_Render(it.node->value->obj, self->key, &m);
        }
        it.node = it.node->next;
    }
}
#pragma pop
static inline void merge_flush_func_00232E00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00232E00 */

/* merge_units: begin func_00232EE0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Container iterator helpers.
 */


void std_list_cElementPtr_end_void(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* cLListIterator_cElementPtr_ctor_listR(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cElementPtr_begin_void(Iter* out, PtrVec* v) {
    out->p = v->data;
}
static inline void merge_flush_func_00232EE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00232EE0 */

/* merge_units: begin func_00232F10 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(10)
#include "vslot_pad.h"

struct V4 {
    float x, y, z, w;
    V4() {}
    V4(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V4(const V4& o) { V4* d = this; const V4* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); }
    V4& operator=(const V4& o) { V4* d = this; const V4* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
} __attribute__((aligned(16)));

struct M4 { V4 r0, r1, r2, r3; V4& Pos() { return r3; } V4& Fwd() { return r1; } };

static inline void OpS(V4* pr, const V4* pa, const V4* pb)
{
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(pr), "r"(pa), "r"(pb) : "memory");
}
static inline V4 operator-(const V4& a, const V4& b) { V4 r; OpS(&r, &a, &b); return r; }
static inline void OpA(V4* pr, const V4* pa, const V4* pb)
{
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(pr), "r"(pa), "r"(pb) : "memory");
}
static inline V4 operator+(const V4& a, const V4& b) { V4 r; OpA(&r, &a, &b); return r; }
static inline void OpMZ(V4* pr, const V4* pa, float s)
{
    __int128 t = 0;
    __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(pr), "r"(pa), "f"(s) : "memory");
}
static inline V4 operator*(const V4& a, float s) { V4 r; OpMZ(&r, &a, s); return r; }
static inline void OpMZ2(V4* pr, const V4* pa, float s)
{
    __int128 t = 0;
    __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%1); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%2); .set reorder" : "+r"(t) : "r"(pa), "r"(pr), "f"(s) : "memory");
}
static inline V4 Mul2(const V4& a, float s) { V4 r; OpMZ2(&r, &a, s); return r; }
static inline V4 Mid(const V4& a, const V4& b) { return Mul2(a + b, 0.5f); }
static inline void MidTo(V4* out, const V4& a, const V4& b) { *out = Mid(a, b); }
static inline void MidToM(V4* out, const V4& a, const V4& b) { MidTo(out, a, b); }

static inline float Length(V4 v)
{
    float r = 0.0f;
    int t;
    V4* p = &v;
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
static inline float Sqrt(float x)
{
    float r = 0.0f;
    asm { sqrt.s r, x }
    return r;
}

static inline float Abs(float x) { float r = 0.0f; asm { abs.s r, x } return r; }
static inline void operator+=(V4& a, const V4& b) { OpA(&a, &a, &b); }
static inline void AddXYZ(V4* a, const V4* b)
{
    __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); vadd.xyz $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(a), "r"(b) : "memory");
}
static inline V4 MkMkV4(float x, float y, float z, float w) { V4 r; r.x = x; r.y = y; r.z = z; r.w = w; return r; }

struct Box0 { V4 lo, hi;
    Box0& operator=(const Box0& o) { __int128 t0; __int128 t1; Box0* d = this; const Box0* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); sq %1, 0x10(%2)" : "=&r"(t0), "=&r"(t1) : "r"(d), "r"(s) : "memory"); return *this; }
};
struct Box : Box0 {
    Box() {
        lo.x = 3.4028235e38f; lo.y = 3.4028235e38f; lo.z = 3.4028235e38f; lo.w = 1.0f;
        hi.x = -3.4028235e38f; hi.y = -3.4028235e38f; hi.z = -3.4028235e38f; hi.w = 1.0f;
    }
    void Extend(V4* p) { V4* l = &lo; V4* h = &hi; __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); lqc2 $vf3, 0x0(%2); vmini.xyz $vf1, $vf1, $vf3; vmax.xyz $vf2, $vf2, $vf3; sqc2 $vf1, 0x0(%0); sqc2 $vf2, 0x0(%1)" : : "r"(l), "r"(h), "r"(p) : "memory"); }
    void Reset() {
        lo = V4(3.4028235e38f, 3.4028235e38f, 3.4028235e38f, 1.0f);
        hi = V4(-3.4028235e38f, -3.4028235e38f, -3.4028235e38f, 1.0f);
    }
};
static inline unsigned char Overlap(Box0* a, Box0* b)
{
    V4* ahi = &a->hi;
    V4* blo = &b->lo;
    V4* bhi = &b->hi;
    int r;
    asm {
        .set noreorder
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(bhi)
        vsub.xyz vf3, vf2, vf1
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni r, vi17
        andi r, r, 0xE0
        bnel r, zero, done
        addi r, zero, 0
        lqc2 vf1, 0(ahi)
        lqc2 vf2, 0(blo)
        vsub.xyz vf3, vf1, vf2
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni r, vi17
        andi r, r, 0xE0
        bnel r, zero, done
        addi r, zero, 0
        addi r, zero, 1
    done:
        .set reorder
    }
    return r;
}
static inline V4 BoxDelta(const V4* p, const Box0* b)
{
    V4 r;
    int f1, f2, t;
    __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%4); lqc2 $vf2, 0x0(%5); lqc2 $vf3, 0x0(%6); vsub.xyz $vf4, $vf2, $vf1; vnop; vnop; vnop; vnop; vnop; cfc2.ni %0, $vi17; vsub.xyz $vf5, $vf1, $vf3; vnop; vnop; vnop; vnop; vnop; cfc2.ni %1, $vi17; vmulx.xyzw $vf6, $vf0, $vf0x; andi %2, %0, 0x80; beql %2, $0, 1f; vaddx.x $vf6, $vf4, $vf0x; andi %2, %1, 0x80; beql %2, $0, 1f; vaddx.x $vf6, $vf5, $vf0x; 1: andi %2, %0, 0x40; beql %2, $0, 2f; vaddx.y $vf6, $vf4, $vf0x; andi %2, %1, 0x40; beql %2, $0, 2f; vaddx.y $vf6, $vf5, $vf0x; 2: andi %2, %0, 0x20; beql %2, $0, 3f; vaddx.z $vf6, $vf4, $vf0x; andi %2, %1, 0x20; beql %2, $0, 3f; vaddx.z $vf6, $vf5, $vf0x; 3: sqc2 $vf6, 0x0(%3); .set reorder"
        : "=r"(f1), "=r"(f2), "=r"(t) : "r"(&r), "r"(p), "r"(&b->lo), "r"(&b->hi) : "memory");
    return r;
}

static inline float Dist(const V4* p, const Box0* b) { return Length(BoxDelta(p, b)); }
static inline void SetCP(M4* m, Box0* b, V4 c) { MidTo(&c, b->lo, b->hi); m->r3 = c; }
class Cam10 {
public:
    VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) VPAD1(e)
    virtual V4 GetPos();
    virtual M4 GetMtx();
};
struct CamF { char pad[0x60]; float f60; };
class Obj10 {
public:
    VPAD32(a)
    virtual Box0* GetBox();
    VPAD32(b) VPAD1(c)
    virtual int Contains(V4* p);
    char pad[0x8C];
    int type;
};
struct Tracer10;
struct Entry10 {
    Tracer10* t;
    Obj10* obj;
    unsigned char active;
    unsigned char vis;
};
struct LNode10 { LNode10* prev; LNode10* next; Entry10* value; };
struct It10 { LNode10* n; It10() {} It10(const It10& o) { n = o.n; } It10& operator=(const It10& o) { n = o.n; return *this; } Entry10*& operator*() { return n->value; } };
struct ONode10 { ONode10* prev; ONode10* next; Obj10* value; };
struct OIt10 { ONode10* n; };
struct Eq10 {};
struct Pred10 { Eq10 op; Entry10** ref; Pred10(const Eq10& e, Entry10** r) : op(e), ref(r) {} };
typedef struct { int a; int b; } FxDef;
typedef struct { unsigned char flag; char pad[7]; } FxFlag;

struct Self10 {
    char p0[0x74];
    char list[0xC];
    V4 extA;
    V4 extB;
    V4 last;
    float fB0;
    float size;
    float fB8;
    int pad;
    int weight;
    int c4;
    signed char id;
};

extern "C" {
extern FxFlag D_004F7A54[];
extern FxDef SpecFxTable[];
extern char D_004A6F38[];
extern char g_CameraObject[];
extern char g_HotboxList[];
extern char D_0053B5C0[];
Cam10** cLList_cCAMERA_GOBJPtr_Front(void* p);
#if 0 /* merge_units */
void std_list_cElementPtr_end_void(It10* out, void* list);
#endif /* merge_units */
#define std_list_cElementPtr_end_void(a0, a1) (std_list_cElementPtr_end_void((Iter *)(a0), (Tree *)(a1))) /* merge_units */


#if 0 /* merge_units */
It10* cLListIterator_cElementPtr_ctor_listR(It10* dst, It10* src);
#endif /* merge_units */
#define cLListIterator_cElementPtr_ctor_listR(a0, a1) ((It10 *)cLListIterator_cElementPtr_ctor_listR((Word *)(a0), (Word *)(a1))) /* merge_units */


#if 0 /* merge_units */
void std_list_cElementPtr_begin_void(It10* out, void* list);
#endif /* merge_units */
#define std_list_cElementPtr_begin_void(a0, a1) (std_list_cElementPtr_begin_void((Iter *)(a0), (PtrVec *)(a1))) /* merge_units */


void std_list_deleter_voidPtr_end_void(It10* out, void* list);
void func_00234070(It10* dst, It10* src);
void std_list_deleter_voidPtr_begin_void_2(ONode10** out, void* list);
void std_list_cHotboxPtr_generic_iterator_1_ctor(OIt10* dst, ONode10* n);
void std_list_cHotboxPtr_end_void_2(OIt10* out, void* list);
void func_00234080(OIt10* dst, OIt10* src);
void std_list_cElementPtr_push_back_cElementPR(void* list, Entry10** v);
void std_list_imp_voidPtr_remove_if(void* list, Pred10 p);
void cParticle_dtor(Tracer10* t, int n);
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
Tracer10* cParticle_ctor(void* p, int id, M4* m, float scale);
void cParticle_NextFrame(Tracer10* t, float dt, M4* m, int z);
void cParticle_SetBoxData_cGOBJP_float_float_float_etc(Tracer10* t, float a, float b, Cam10* cam, float c, int flag);
void func_003A3340(Tracer10* t, Cam10* cam, Box0* box, bool flag);
void cParticle_SetBoxData_float_float(Tracer10* t, float s, float f);
void cWind_NextFrame(void* p, float dt);
Box func_00234110(Box0* a, Box0* b);
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
struct F10 { float f; };
static inline void AssignIt(It10* out, LNode10* n) { It10 v; v.n = n; F10* s = (F10*)&v; F10* d = (F10*)out; *d = *s; }
static inline void BegI_(It10* out, void* l) { It10 t; std_list_cElementPtr_begin_void(&t, l); cLListIterator_cElementPtr_ctor_listR(out, &t); }
static inline void BegI(It10* out, void* l) { BegI_(out, l); }
static inline void BegW(It10* out, void* l) { BegI(out, l); }
static inline void Begin(It10* out, void* l) { It10 t2; BegW(&t2, l); F10* s = (F10*)&t2; F10* d = (F10*)out; *d = *s; }
static inline void EndI_(It10* out, void* l) { It10 t; std_list_cElementPtr_end_void(&t, l); cLListIterator_cElementPtr_ctor_listR(out, &t); }
static inline void EndI(It10* out, void* l) { EndI_(out, l); }
static inline void End(It10* out, void* l) { EndI(out, l); }
static inline bool NotEnd(It10* it, void* l) { It10 end; End(&end, l); return it->n != end.n; }
static inline void OBegI_(OIt10* out, void* l) { ONode10* raw; std_list_deleter_voidPtr_begin_void_2(&raw, l); std_list_cHotboxPtr_generic_iterator_1_ctor(out, raw); }
static inline void OBegI(OIt10* out, void* l) { OBegI_(out, l); }
static inline void OBegin0(OIt10* out, void* l) { OIt10 t; OBegI(&t, l); *out = t; }
static inline void OBegin(OIt10* out, void* l) { OBegin0(out, l); }
static inline void OEndI_(OIt10* out, void* l) { OIt10 e; std_list_cHotboxPtr_end_void_2(&e, l); func_00234080(out, &e); }
static inline void OEndI(OIt10* out, void* l) { OEndI_(out, l); }
static inline void OEndW(OIt10* out, void* l) { OEndI(out, l); }
static inline bool ONotEnd(OIt10* it, void* l) { OIt10 e2; OEndW(&e2, l); return it->n != e2.n; }
static inline void EndBI_(It10* out, void* l) { It10 t; std_list_deleter_voidPtr_end_void(&t, l); func_00234070(out, &t); }
static inline void EndBI(It10* out, void* l) { EndBI_(out, l); }
static inline void EndB0(It10* out, void* l) { It10 t2; EndBI(&t2, l); *out = t2; }
static inline void EndB(It10* out, void* l) { EndB0(out, l); }
static inline void UM(void* p) {
    void* d = p;
    __int128 t;
    __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(d) : "memory");
}
static inline void FreeTracer(Tracer10* t)
{
    if (t) {
        AllocGuard g2;
        cParticle_dtor(t, -1);
        cMemMan_Deallocate(0, t, D_004A6F38, 0x14F);
    }
}
static inline void FreeEntry(Entry10* e, int line)
{
    AllocGuard g;
    if (e) {
        FreeTracer(e->t);
    }
    cMemMan_Deallocate(0, e, D_004A6E38, line);
}
static inline void Erase10_(void* l, Entry10** v) { Eq10 eq; std_list_imp_voidPtr_remove_if(l, Pred10(eq, v)); }
static inline void Erase10W(void* l, Entry10** v) { Erase10_(l, v); }
static inline void Erase10(void* l, Entry10** v) { Erase10W(l, v); }
static inline Entry10* NewEntry(int line)
{
    Entry10* e;
    {
        AllocGuard g;
        e = (Entry10*)cMemMan_Allocate(0, 0xC, D_004A6E38, line);
    }
    if (e) e->t = 0;
    return e;
}
static inline Tracer10* MakeTracer(Self10* self, M4* m, int line)
{
    void* p;
    {
        AllocGuard g;
        p = cMemMan_Allocate(0, 0x70, D_004A6E38, line);
    }
    if (p) p = cParticle_ctor(p, GetDef(self->id)->a, m, 1.0f);
    return (Tracer10*)p;
}
static inline Entry10* NewEntryM(int line) { return NewEntry(line); }
static inline Tracer10* MakeTracerM(Self10* self, M4* m, int line) { return MakeTracer(self, m, line); }
static inline void FreeEntryM(Entry10* e, int line) { FreeEntry(e, line); }

extern "C" void SnowField_Update(Self10* self, float dt)
{
    It10 it;
    OIt10 oit;
    Entry10* ne;
    It10 bestIt;
    It10 cur;
    int cnt;
    int total;
    float best;
    float scale;
    Cam10* cam;
    Entry10* e;

    cam = *cLList_cCAMERA_GOBJPtr_Front(g_CameraObject);
    if (cam && self->c4 >= 0) {
        M4 m;
        UM(&m);
        V4 camPos = cam->GetPos();
        float h = 0.5f * self->size;
        camPos += cam->GetMtx().Fwd() * h;
        Box0 big;
        big.lo = self->extA;
        big.hi = self->extB;
        AddXYZ(&big.lo, &camPos);
        AddXYZ(&big.hi, &camPos);
        V4 p1 = camPos;
        V4 p2 = camPos;
        if (!(camPos.x - self->last.x <= 0.0f)) {
            p1 = camPos + V4(self->size, 0.0f, 0.0f, 0.0f);
        } else {
            p1 = camPos - V4(self->size, 0.0f, 0.0f, 0.0f);
        }
        if (!(camPos.y - self->last.y <= 0.0f)) {
            p2 = camPos + V4(0.0f, self->size, 0.0f, 0.0f);
        } else {
            p2 = camPos - V4(0.0f, self->size, 0.0f, 0.0f);
        }
        Box box;
        cnt = 0;
        box.Reset();
        for (Begin(&it, self->list); NotEnd(&it, self->list); it.n = it.n->next) {
            e = *it;
            if (!e->active) {
                if (!(box.lo.x <= box.hi.x) || Overlap(e->obj->GetBox(), &box)) {
                    Box0* b = e->obj->GetBox();
                    if (b->lo.x <= b->hi.x) {
                        box.Extend(&b->lo);
                        box.Extend(&b->hi);
                    }
                }
            } else {
                cnt++;
            }
        }

        char* gl = g_HotboxList;

        for (OBegin(&oit, gl); ONotEnd(&oit, gl); oit.n = oit.n->next) {
            Obj10* o = oit.n->value;
            if (o->type == 0xE) {
                bool found = 0;
                for (Begin(&it, self->list); NotEnd(&it, self->list); it.n = it.n->next) {
                    if ((*it)->obj == o && (*it)->active) { found = 1; continue; }
                    asm { .set noat }
                }
                if (!found && Overlap(o->GetBox(), &big)) {
                    ne = NewEntryM(0x432);
                    if (ne) {
                        m.r3 = camPos;
                        ne->t = MakeTracerM(self, &m, 0x436);
                        ne->obj = o;
                        ne->active = 1;
                        std_list_cElementPtr_push_back_cElementPR(self->list, &ne);
                    }
                }
            }
        }

        total = 0;
        Begin(&it, self->list);
        best = 0.0f;
        EndB(&bestIt, self->list);
        while (NotEnd(&it, self->list)) {
            cur = it;
            Entry10* e3 = *cur;
            it.n = it.n->next;
            if (e3->active) {
                float d = Dist(&camPos, e3->obj->GetBox());
                if (!(d <= self->size + 0.5f * self->size)) {
                    FreeEntryM(e3, 0x451);
                    Erase10(self->list, &cur.n->value);
                } else {
                    Box tmp;
                    Obj10* o = e3->obj;
                    if (Overlap(o->GetBox(), &big)) {
                        e3->vis = 1;
                        total += self->weight;
                    } else {
                        if (!(d <= best) && !o->Contains(&p1) && !o->Contains(&p2)) {
                            best = d;
                            AssignIt(&bestIt, cur.n);
                        }
                        e3->vis = 0;
                    }
                }
            } else {
                total += self->weight;
            }
        }
        void* l = self->list;
        if (*(int*)l > 4) {
            if (NotEnd(&bestIt, l)) {
                Entry10* e3 = *bestIt;
                FreeEntryM(e3, 0x485);
                Erase10(self->list, &bestIt.n->value);
            }
        }
        scale = 1.0f;
        if (total > 0) scale = (float)self->weight / (float)total;
        cWind_NextFrame(D_0053B5C0, dt);
        for (Begin(&it, self->list); NotEnd(&it, self->list); it.n = it.n->next) {
            e = *it;
            if (e->t && e->vis) {
                cParticle_SetBoxData_cGOBJP_float_float_float_etc(e->t, self->fB0, self->size, cam, self->fB8, self->id != 0x16);
                Box b2;
                b2 = func_00234110(&big, e->obj->GetBox());
                SetCP(&m, &b2, V4());
                func_003A3340(e->t, cam, &b2, self->id != 0x16);
                cParticle_SetBoxData_float_float(e->t, scale, ((CamF*)*cLList_cCAMERA_GOBJPtr_Front(g_CameraObject))->f60);
                cParticle_NextFrame(e->t, dt, &m, 0);
            }
        }
        self->last = camPos;
    }
}
#undef std_list_cElementPtr_end_void /* merge_units */
#undef cLListIterator_cElementPtr_ctor_listR /* merge_units */
#undef std_list_cElementPtr_begin_void /* merge_units */
static inline void merge_flush_func_00232F10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00232F10 */
