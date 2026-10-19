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
void func_00123BE8(int stream, const char* msg);
void Libc_Abort(void);
void* Mem_Alloc(int pool, int size, char* file, int line);
void Mem_Free(int pool, void* p, char* file, int line);
void Vec4_Copy(Q8180* d, Q8180* s);
void func_00139BB0(void* d, void* s);
void func_00139BA0(void* d, void* s);
void* func_00139BC0(int size, void* p);
void func_00139B00(void* d, void* s);
}
struct CandVec8180 { unsigned int cap; unsigned int count; Cand8180* data; };
static inline void Assign8180(Cand8180* d, Cand8180* s) {
    Vec4_Copy(&d->rows[0], &s->rows[0]);
    Vec4_Copy(&d->rows[1], &s->rows[1]);
    Vec4_Copy(&d->rows[2], &s->rows[2]);
    Vec4_Copy(&d->rows[3], &s->rows[3]);
    d->flag50 = s->flag50;
    func_00139BB0(d->part40, s->part40);
    func_00139BA0(d->part60, s->part60);
    d->flag51 = s->flag51;
    d->flag52 = s->flag52;
}
static inline void Construct8180(Cand8180* d, Cand8180* s) {
    void* p = func_00139BC0(0x70, d);
    if (p) func_00139B00(p, s);
}
static inline const unsigned int& Min8180(const unsigned int& a, const unsigned int& b) {
    return b < a ? b : a;
}
static inline void Free8180(void* p) {
    if (p) {
        AllocGuard g;
        Mem_Free(0, p, D_0049AE20, 0x64);
    }
}
static inline Cand8180* Alloc8180(unsigned int cnt) {
    AllocGuard g;
    return (Cand8180*)Mem_Alloc(0, cnt * sizeof(Cand8180), D_0049AE40, 0x5C);
}
extern "C" void ColQuery_CopyCandidates(CandVec8180* v, Cand8180* first, Cand8180* last) {
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
            func_00123BE8(D_00489738->stream, D_004BD0D0);
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



