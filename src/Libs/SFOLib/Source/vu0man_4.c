/*
 * Libs/SFOLib/Source/vu0man: 3 files, 003C8180-003C8550
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003C8180 */
#pragma push /* merge_units */
#include "types.h"
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
extern Err8180* D_00489738;
extern char D_004BD0D0[];
extern char D_0049AE20[];
extern char D_0049AE40[];
void Libc_Fprintf(int stream, const char* msg);
void Libc_Abort(void);
void* cMemMan_Allocate(int pool, int size, char* file, int line);
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
