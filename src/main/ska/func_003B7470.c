/* func_003B7470: vector<E>::insert(pos, n, value) for a 32-byte element (int, float, byte, quadword). */
#include "types.h"
#pragma cplusplus on
#pragma inline_depth(8)
inline void* operator new(unsigned int, void* p) { return p; }
#include "tstr_types.h"
struct Q_3B7470 {
    int a[4];
    Q_3B7470(const Q_3B7470& o) { Q_3B7470* d = this; const Q_3B7470* s = &o; __int128 t; void* xx = this; /* dead on purpose: retail keeps this addiu */ asm volatile("lq %0,0(%1)" : "=r"(t) : "r"(s)); asm volatile("sq %0,0(%1)" : : "r"(t), "r"(d) : "memory"); }
    Q_3B7470& operator=(const Q_3B7470& o)
    {
        __int128 t;
        __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(this), "r"(&o) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct E_003B7470 {
    int a;
    float b;
    unsigned char c;
    Q_3B7470 q;
    E_003B7470& operator=(const E_003B7470& o)
    {
        E_003B7470* t = this;
        { void* xx = &t->q; } /* dead on purpose: retail keeps this addiu */
        t->a = o.a; t->b = o.b; t->c = o.c; t->q = o.q;
        return *this;
    }
};

struct V_003B7470 { unsigned int cap; unsigned int count; E_003B7470* data; };
static inline void Construct_3B7470(E_003B7470* p, const E_003B7470* src)
{
    new (p) E_003B7470(*src);
}

extern "C" {
extern char D_004BCE60[];
extern char D_004BCFC8[];
extern char D_004BC4C0[];
void func_003B7A10(V_003B7470* a, V_003B7470* b);
}
extern "C" void func_003B7470(V_003B7470* v, E_003B7470* pos, unsigned int n, const E_003B7470* value)
{
    unsigned int maxN;
    if (n == 0)
        return;
    maxN = 0x300000;
    if (n > maxN || v->count > maxN - n) {
        func_00123BE8(D_00489738->stream, D_004BCE60);
        Libc_Abort();
    }
    unsigned int cap = v->cap; unsigned int cnt_ = v->count;
    if (cnt_ + n <= cap) {
        E_003B7470* end = v->data + cnt_;
        unsigned int after = end - pos;
        if (after < n) {
            E_003B7470* p = end;
            for (; n > after; n--) {
                Construct_3B7470(p, value);
                p++;
                v->count++;
            }
            for (E_003B7470* q = pos; q < end; q++, p++) {
                Construct_3B7470(p, q);
                v->count++;
            }
        } else {
            E_003B7470* src = end - n;
            E_003B7470* dst = end;
            for (; src < end; src++, dst++) {
                Construct_3B7470(dst, src);
                v->count++;
            }
            if (end - (after - n) <= value && value < end)
                value += n;
            E_003B7470* last = pos + (after - n);
            E_003B7470* d = end;
            while (last > pos) {
                --last;
                --d;
                *d = *last;
            }
        }
        {
            const E_003B7470& x = *value;
            while (n) {
                *pos = x;
                --n;
                ++pos;
            }
        }
    } else {
        V_003B7470 tmp;
        E_003B7470* dst;
        unsigned int newCap;
        E_003B7470* src;
        unsigned int* tcap;
        E_003B7470* srcEnd;
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
        tmp.data = (E_003B7470*)TStr_Alloc(newCap * sizeof(E_003B7470), D_004BCFC8, 0x5C);
        tcap = &tmp.cap;
        *tcap = newCap;
        src = v->data;
        srcEnd = src + v->count;
        dst = tmp.data;
        for (; src < pos; src++, dst++) {
            Construct_3B7470(dst, src);
            tmp.count++;
        }
        for (; n; dst++, n--) {
            Construct_3B7470(dst, value);
            tmp.count++;
        }
        for (; src < srcEnd; src++, dst++) {
            Construct_3B7470(dst, src);
            tmp.count++;
        }
        func_003B7A10(&tmp, v);
        {
            E_003B7470* e;
            E_003B7470* b = tmp.data;
            e = b + tmp.count;
            while (e > b)
                --e;
        }
        tmp.count = 0;
        {
            E_003B7470* fp_ = tmp.data;
            if (fp_) {
                if (fp_)
                    TStr_Free((char*)fp_, D_004BC4C0, 0x64);
            }
        }
    }
}
