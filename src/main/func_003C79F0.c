#include "types.h"
#pragma cplusplus on
#pragma inline_depth(8)
#pragma opt_propagation off
#include "tstr_types.h"
/* std_vector_imp_cCollisionEdge_insert: vector<E>::insert(pos, n, value) for the 0x60-byte human collision buffer
 * element of Vector_Reserve_1EF6C0 (Vector_Reserve_1EF6C0.c): in-place shift/fill, or grow, copy
 * and swap. */
/* Quadword member copies: lq/sq through volatile asm, as in Vector_Reserve_1EF6C0.c (no C form keeps
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
void HumanColBufB_Dtor(V1EF6C0* a, int f);
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
        HumanColBufB_Dtor(&tmp, -1);
    }
}
