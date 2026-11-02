/*
 * Libs/SFOLib/Source/vu0man: 5 files, 003C7880-003C8180
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003C7880 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct V {
    float x, y, z, w;
    V() {}
    ~V() {}
    V(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct W {
    float x, y, z, w;
    W() {}
    W& operator=(const W& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct B { unsigned char d; };
struct E {
    V a, b, c;
    B d;
    float e;
    V f;
    W g;
};
/* vector<E>::erase(first, last): 96-byte element, tail copied down, empty dtors. */
struct EVec { int cap; int count; E* data; };
static inline E* Copy(E* first, E* last, E* dest) {
    while (first < last) { *dest = *first; ++first; ++dest; }
    return dest;
}
extern "C" E* std_vector_imp_cCollisionEdge_erase(EVec* self, E* first, E* last)
{
    if (first == last)
        return first;
    E* end = self->data + self->count;
    int tailCount = end - last;
    if (tailCount)
        Copy(last, end, first);
    E* tail = first + tailCount;
    while (tail < end) {
        tail->~E();
        ++tail;
    }
    self->count -= last - first;
    return first;
}
static inline void merge_flush_func_003C7880(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C7880 */

/* merge_units: begin func_003C79F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
#pragma opt_propagation off
#include "tstr_types.h"
/* std_vector_imp_cCollisionEdge_insert: vector<E>::insert(pos, n, value) for the 0x60-byte human collision buffer
 * element of std_vector_imp_cCollisionEdge_reserve (std_vector_imp_cCollisionEdge_reserve.c): in-place shift/fill, or grow, copy
 * and swap. */
/* Quadword member copies: lq/sq through volatile asm, as in std_vector_imp_cCollisionEdge_reserve.c (no C form keeps
 * retail's 128-bit moves); the unused xx keeps retail's dead member-address addiu. The local
 * declaration order in each copy picks retail's registers. */
struct V4q {
    float x, y, z, w;
    V4q(const V4q& o) { void* xx = this; __int128 t; V4q* d = this; const V4q* s = &o; asm volatile("lq %0,0(%1)" : "=r"(t) : "r"(s)); asm volatile("sq %0,0(%1)" : : "r"(t), "r"(d) : "memory"); }
    V4q& operator=(const V4q& o) { void* xx = this; __int128 t; V4q* d = this; const V4q* s = &o; asm volatile("lq %0,0(%1)" : "=r"(t) : "r"(s)); asm volatile("sq %0,0(%1)" : : "r"(t), "r"(d) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct V4r {
    float x, y, z, w;
    V4r(const V4r& o) { void* xx = this; V4r* d = this; const V4r* s = &o; __int128 t; asm volatile("lq %0,0(%1)" : "=r"(t) : "r"(s)); asm volatile("sq %0,0(%1)" : : "r"(t), "r"(d) : "memory"); }
    V4r& operator=(const V4r& o) { void* xx = this; V4r* d = this; const V4r* s = &o; __int128 t; asm volatile("lq %0,0(%1)" : "=r"(t) : "r"(s)); asm volatile("sq %0,0(%1)" : : "r"(t), "r"(d) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct F2 { float x, y; };
/* The empty default ctor (B1) and ctor/dtor pair (W1) make the copy constructor member-wise
 * while assignment stays a block move, as retail copies them. */
struct B1 { unsigned char d; B1() {} };
struct W1 {
    F2 g;
    int h;
    W1() {}
    /* weak, dropped section: no out-of-line copy of the empty destructor */
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~W1() {}
    W1& operator=(const W1& o) { W1* d = this; const W1* s = &o; __int128 t; asm volatile("lq %0,0(%1)" : "=r"(t) : "r"(s)); asm volatile("sq %0,0(%1)" : : "r"(t), "r"(d) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct E1EF6C0 {
    V4q a;
    V4q b;
    V4q c;
    B1 d;
    float e;
    V4r f;
    W1 g;
} __attribute__((aligned(16)));
struct V1EF6C0 { unsigned int cap; unsigned int count; E1EF6C0* data; };
extern "C" {
extern char D_004BD0B0[];
extern char D_004A0548[];
void std_swap_vectordeleterR_vectordeleterR_13(V1EF6C0* a, V1EF6C0* b);
void std_vector_deleter_cCollisionEdge_dtor(V1EF6C0* a, int f);
void std_vector_imp_cCollisionEdge_insert(V1EF6C0* v, E1EF6C0* pos, unsigned int n, const E1EF6C0* value);
}
inline void* operator new(unsigned int, void* p) { return p; }
static inline void Construct(E1EF6C0* p, const E1EF6C0* s)
{
    new (p) E1EF6C0(*s);
}
static inline void Fill(E1EF6C0* p, unsigned int n, const E1EF6C0* v) { for (; n; --n, ++p) *p = *v; }
#define T E1EF6C0
extern "C" void std_vector_imp_cCollisionEdge_insert(V1EF6C0* v, T* pos, unsigned int n, const T* value)
{
    unsigned int mx;
    if (n == 0)
        return;
    mx = 0x100000;
    if (n > mx || v->count > mx - n) {
        Libc_Fprintf(D_00489738->stream, D_004BD0B0);
        Libc_Abort();
    }
    unsigned int cap = v->cap;
    if (!(v->count + n > cap)) {
        T* end = v->data + v->count;
        unsigned int after = end - pos;
        if (after < n) {
            T* p = end;
            for (; n > after; n--) {
                Construct(p, value);
                p++;
                v->count++;
            }
            for (T* q = pos; q < end; q++, p++) {
                Construct(p, q);
                v->count++;
            }
        } else {
            T* src = end - n;
            T* dst = end;
            for (; src < end; src++, dst++) {
                Construct(dst, src);
                v->count++;
            }
            if (end - (after - n) <= value && value < end)
                value += n;
            T* last = pos + (after - n);
            T* d = end;
            while (last > pos) {
                --last;
                --d;
                *d = *last;
            }
        }
        Fill(pos, n, value);
    } else {
        V1EF6C0 tmp;
        T* dst;
        unsigned int newCap;
        T* src;
        T* srcEnd;
        unsigned int need;
        tmp.cap = 0;
        tmp.count = 0;
        tmp.data = 0;
        need = v->count + n;
        newCap = v->cap ? v->cap : 1;
        while (need > newCap) {
            if (newCap < mx / 2)
                newCap *= 2;
            else
                newCap = mx;
        }
        tmp.data = (T*)TStr_Alloc(newCap * sizeof(T), D_004A0548, 0x5C);
        { unsigned int* pc = &tmp.cap; *pc = newCap; }
        src = v->data;
        srcEnd = src + v->count;
        dst = tmp.data;
        for (; src < pos; src++, dst++) {
            Construct(dst, src);
            tmp.count++;
        }
        for (; n; dst++, n--) {
            Construct(dst, value);
            tmp.count++;
        }
        for (; src < srcEnd; src++, dst++) {
            Construct(dst, src);
            tmp.count++;
        }
        std_swap_vectordeleterR_vectordeleterR_13(&tmp, v);
        std_vector_deleter_cCollisionEdge_dtor(&tmp, -1);
    }
}
static inline void merge_flush_func_003C79F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C79F0 */

/* merge_units: begin func_003C8180 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
struct Err8180 { int pad[3]; int stream; };
struct Q8180 { int w[4]; };
struct Cand8180 {
    Q8180 rows[4];
    char part40[0x10];
    unsigned char flag50;
    unsigned char flag51;
    unsigned char flag52;
    char pad53[0xD];
    int part60[4];
};
extern "C" {
#if 0 /* merge_units */
extern Err8180* D_00489738;
#endif /* merge_units */
#define D_00489738 (*(Err8180 **)&D_00489738) /* merge_units */

extern char D_004BD0D0[];
extern char D_0049AE20[];
extern char D_0049AE40[];
void Libc_Fprintf(int stream, const char* msg);
void Libc_Abort(void);
#if 0 /* merge_units */
void* cMemMan_Allocate(int pool, int size, char* file, int line);
#endif /* merge_units */
#define cMemMan_Allocate(a0, a1, a2, a3) (cMemMan_Allocate((a0), (unsigned int)(a1), (a2), (a3))) /* merge_units */

void cMemMan_Deallocate(int pool, void* p, char* file, int line);
void cVector_opAssign(Q8180* d, Q8180* s);
void cCollisionModel_FaceProperties_opAssign(void* d, void* s);
void cCollisionModel_FaceLocator_opAssign(void* d, void* s);
void* opNew_uint_voidP(int size, void* p);
void cCollisionFace_ctor_cCollisionFaceR(void* d, void* s);
}
struct CandVec8180 { unsigned int cap; unsigned int count; Cand8180* data; };
static inline void Assign8180(Cand8180* d, Cand8180* s) {
    cVector_opAssign(&d->rows[0], &s->rows[0]);
    cVector_opAssign(&d->rows[1], &s->rows[1]);
    cVector_opAssign(&d->rows[2], &s->rows[2]);
    cVector_opAssign(&d->rows[3], &s->rows[3]);
    d->flag50 = s->flag50;
    cCollisionModel_FaceProperties_opAssign(d->part40, s->part40);
    cCollisionModel_FaceLocator_opAssign(d->part60, s->part60);
    d->flag51 = s->flag51;
    d->flag52 = s->flag52;
}
static inline void Construct8180(Cand8180* d, Cand8180* s) {
    void* p = opNew_uint_voidP(0x70, d);
    if (p) cCollisionFace_ctor_cCollisionFaceR(p, s);
}
static inline const unsigned int& Min8180(const unsigned int& a, const unsigned int& b) {
    return b < a ? b : a;
}
static inline void Free8180(void* p) {
    if (p) {
        AllocGuard g;
        cMemMan_Deallocate(0, p, D_0049AE20, 0x64);
    }
}
static inline Cand8180* Alloc8180(unsigned int cnt) {
    AllocGuard g;
    return (Cand8180*)cMemMan_Allocate(0, cnt * sizeof(Cand8180), D_0049AE40, 0x5C);
}
extern "C" void std_vector_imp_cCollisionFace_do_assign(CandVec8180* v, Cand8180* first, Cand8180* last) {
    Cand8180* d;
    Cand8180* e;
    unsigned int n = last - first;
    if (n <= v->cap) {
        unsigned int m = Min8180(n, v->count);
        d = v->data;
        e = d + m;
        for (; d < e; d++, first++)
            Assign8180(d, first);
        if (n < v->count) {
            v->count = n;
        } else if (v->count < n) {
            for (; first != last; first++, d++) {
                Construct8180(d, first);
                v->count++;
            }
        }
    } else {
        if (n > 0xDB6DB) {
            Libc_Fprintf(D_00489738->stream, D_004BD0D0);
            Libc_Abort();
        }
        v->count = 0;
        if (v->data) {
            Free8180(v->data);
            v->data = 0;
            v->cap = 0;
        }
        Cand8180** pdata = &v->data;
        *pdata = Alloc8180(n);
        v->cap = n;
        d = v->data;
        for (; first != last; first++, d++) {
            Construct8180(d, first);
            v->count++;
        }
    }
}
#undef D_00489738 /* merge_units */
#undef cMemMan_Allocate /* merge_units */
static inline void merge_flush_func_003C8180(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C8180 */

/* merge_units: begin func_003C84D0 */
#pragma push /* merge_units */
extern char D_00537F80[];
extern unsigned long long* cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_int_etc(void* q, int a, int b, int c, int d, int e);
extern void cDmaMan_Kick(void* q, int a);

/* Queues a 64-bit packet built from table[index] | 0x14000000 and flushes it. */
void cVU0Man_RunProg(unsigned int* table, int index) {
    unsigned long long* p = cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_int_etc(D_00537F80, 0, 1, 0, 0, 1);
    *p = table[index] | 0x14000000;
    cDmaMan_Kick(D_00537F80, 0);
}
static inline void merge_flush_func_003C84D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C84D0 */

/* merge_units: begin func_003C8550 */
#pragma push /* merge_units */
#pragma opt_unroll_loops off
typedef struct {
    int key;
    unsigned int ofs;
} Pair8550;
typedef struct {
    int count;
    Pair8550 pairs[20];
} Group8550;
typedef struct {
    unsigned int base[7];
    int group[7];
    int f38;
    char pad[0x94 - 0x3C];
} Obj8550;
extern Group8550 D_00493530[];
extern unsigned int D_004937E0[];
extern void* memset(void*, int, unsigned int);
Obj8550* cVU0Man_ctor(Obj8550* o)
{
    int i;
    int j;
    unsigned int k;
    unsigned int acc;
    int n;
    Pair8550* p;
    Group8550* g;
    unsigned int* b;
    unsigned int* end;

    memset(o, 0, sizeof(Obj8550));
    o->f38 = -1;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < D_00493530[i].count; j++) {
            o->group[D_00493530[i].pairs[j].key] = i;
        }
    }
    k = 0;
    acc = 0;
    n = 0;
    g = D_00493530;
    b = o->base;
    end = D_004937E0;
    for (; n < 7; n++, b++) {
        *b = acc;
        p = &g->pairs[k];
        if (k < g->count - 1) {
            acc += (g->pairs[k + 1].ofs - p->ofs) / 8;
        } else {
            acc += (*end - p->ofs) / 8;
        }
        k++;
        if (k == g->count) {
            g++;
            end++;
            k = 0;
            acc = 0;
        }
    }
    return o;
}
static inline void merge_flush_func_003C8550(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C8550 */
