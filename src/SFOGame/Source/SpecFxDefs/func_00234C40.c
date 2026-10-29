#pragma cplusplus on
#pragma inline_depth(10)

#include "types.h"
#include "vslot_pad.h"
#include "alloc_guard.h"
#include "vu0_ops.h"

struct V4 {
    float x, y, z, w;
    V4() {}
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
static inline void NormalizeLen(V4* v, float* len)
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
    V4 pos;
    Entry4C() { t = 0; }
};
struct LNode4C { LNode4C* prev; LNode4C* next; Entry4C* value; };
struct It4C { LNode4C* n; Entry4C*& operator*() { return n->value; } };
struct Eq4C {};
struct Pred4C { Eq4C op; Entry4C** ref; Pred4C(const Eq4C& e, Entry4C** r) : op(e), ref(r) {} };
typedef struct { int a; int b; } FxDef;
typedef struct { unsigned char flag; char pad[7]; } FxFlag;

struct Self4C {
    char p0[0x74];
    char list[0x1C];
    V4 lastPos;
    int count;
    float spacing;
    float minDist;
    float fadeStart;
    float radius;
    float alpha;
};

extern "C" {
extern FxFlag D_004F7A54[];
extern FxDef SpecFxTable[];
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

static inline FxDef* GetDef_(int id)
{
    if ((unsigned int)id < 41) return &SpecFxTable[id];
    return 0;
}
static inline FxDef* GetDef(int id)
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
    if (p) p = cParticle_ctor(p, GetDef(FXID(self))->a, m, 1.0f);
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
    V4 camPos;
    float heading;
    int n;
    int i;
    int k;
    bool found;
    Entry4C* e;
    float a;

    UM(&m);
    def = GetDef(FXID(self));
    cam = *cLList_cCAMERA_GOBJPtr_Front(g_CameraObject);
    if (!def || def->a < 0 || !cam) return;
    camPos = cam->GetMtx().Pos();
    V4 dir = camPos - self->lastPos;
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
                V4 off;
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
        V4 spot;
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
