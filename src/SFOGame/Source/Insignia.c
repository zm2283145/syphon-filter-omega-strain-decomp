/*
 * SFOGame/Source/Insignia: 1 file, 00266BA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00266BA0 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#pragma inline_depth(8)
inline void* operator new(unsigned int, void* p) { return p; }
#include "tstr_types.h"
struct Q_266BA0 {
    int a[4];
    Q_266BA0(const Q_266BA0& o) { Q_266BA0* d = this; const Q_266BA0* s = &o; __int128 t; asm volatile("lq %0,0(%1)" : "=r"(t) : "r"(s)); asm volatile("sq %0,0(%1)" : : "r"(t), "r"(d) : "memory"); }
    Q_266BA0& operator=(const Q_266BA0& o)
    {
        Q_266BA0* d = this; const Q_266BA0* s = &o; __int128 t; asm volatile("lq %0,0(%1)" : "=r"(t) : "r"(s)); asm volatile("sq %0,0(%1)" : : "r"(t), "r"(d) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct F4_266BA0 {
    float x, y, z, w;
    F4_266BA0(const F4_266BA0& o) { x = o.x; y = o.y; z = o.z; w = o.w; }
    F4_266BA0& operator=(const F4_266BA0& o) { const F4_266BA0* s = &o; F4_266BA0* d = this; __int128 t; asm volatile("lq %0,0(%1)" : "=r"(t) : "r"(s)); asm volatile("sq %0,0(%1)" : : "r"(t), "r"(d) : "memory"); return *this; }
};
struct E_00266BA0 {
    Q_266BA0 a, b, c;
    F4_266BA0 d;
    E_00266BA0(const E_00266BA0& o) : a(o.a), b(o.b), c(o.c), d(o.d) {}
    E_00266BA0& operator=(const E_00266BA0& o)
    {
        a = o.a; b = o.b; c = o.c; d = o.d;
        return *this;
    }
};

struct V_00266BA0 { unsigned int cap; unsigned int count; E_00266BA0* data; };
static inline void Construct_266BA0(E_00266BA0* p, const E_00266BA0* src)
{
    new (p) E_00266BA0(*src);
}

extern "C" {
extern char D_004A8220[];
extern char D_004A8250[];
extern char D_004A8260[];
void std_swap_vectordeleterR_vectordeleterR_24(V_00266BA0* a, V_00266BA0* b);
}
extern "C" void std_vector_imp_TaserPoint_insert(V_00266BA0* v, E_00266BA0* pos, unsigned int n, const E_00266BA0* value)
{
    unsigned int maxN;
    if (n == 0)
        return;
    maxN = 0x180000;
    if (n > maxN || v->count > maxN - n) {
        Libc_Fprintf(D_00489738->stream, D_004A8220);
        Libc_Abort();
    }
    unsigned int cap = v->cap; unsigned int cnt_ = v->count;
    if (cnt_ + n <= cap) {
        E_00266BA0* end = v->data + cnt_;
        unsigned int after = end - pos;
        if (after < n) {
            E_00266BA0* p = end;
            for (; n > after; n--) {
                Construct_266BA0(p, value);
                p++;
                v->count++;
            }
            for (E_00266BA0* q = pos; q < end; q++, p++) {
                Construct_266BA0(p, q);
                v->count++;
            }
        } else {
            E_00266BA0* src = end - n;
            E_00266BA0* dst = end;
            for (; src < end; src++, dst++) {
                Construct_266BA0(dst, src);
                v->count++;
            }
            if (end - (after - n) <= value && value < end)
                value += n;
            E_00266BA0* last = pos + (after - n);
            E_00266BA0* d = end;
            while (last > pos) {
                --last;
                --d;
                *d = *last;
            }
        }
        {
            const E_00266BA0& x = *value;
            while (n) {
                *pos = x;
                --n;
                ++pos;
            }
        }
    } else {
        V_00266BA0 tmp;
        E_00266BA0* dst;
        unsigned int newCap;
        E_00266BA0* src;
        unsigned int* tcap;
        E_00266BA0* srcEnd;
        unsigned int need;
        tmp.cap = 0;
        tmp.count = 0;
        tmp.data = 0;
        need = v->count + n;
        newCap = v->cap ? v->cap : 1;
        while (need > newCap) {
            if (newCap < maxN / 2)
                newCap *= 2;
            else
                newCap = maxN;
        }
        tmp.data = (E_00266BA0*)TStr_Alloc(newCap * sizeof(E_00266BA0), D_004A8260, 0x5C);
        tcap = &tmp.cap;
        *tcap = newCap;
        src = v->data;
        srcEnd = src + v->count;
        dst = tmp.data;
        for (; src < pos; src++, dst++) {
            Construct_266BA0(dst, src);
            tmp.count++;
        }
        for (; n; dst++, n--) {
            Construct_266BA0(dst, value);
            tmp.count++;
        }
        for (; src < srcEnd; src++, dst++) {
            Construct_266BA0(dst, src);
            tmp.count++;
        }
        std_swap_vectordeleterR_vectordeleterR_24(&tmp, v);
        {
            E_00266BA0* e;
            E_00266BA0* b = tmp.data;
            e = b + tmp.count;
            while (e > b)
                --e;
        }
        tmp.count = 0;
        {
            E_00266BA0* fp_ = tmp.data;
            if (fp_) {
                if (fp_)
                    TStr_Free((char*)fp_, D_004A8250, 0x64);
            }
        }
    }
}
static inline void merge_flush_func_00266BA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00266BA0 */
