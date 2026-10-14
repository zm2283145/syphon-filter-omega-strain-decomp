#include "types.h"
#pragma cplusplus on
#include "tstr_types.h"
struct Q_240DE0 {
    int a[4];
    Q_240DE0& operator=(const Q_240DE0& o)
    {
        __int128 t;
        __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(this), "r"(&o) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct E_00240DE0 {
    float f;
    Q_240DE0 a, b, c;
    E_00240DE0& operator=(const E_00240DE0& o)
    {
        E_00240DE0* t = this;
        t->f = o.f; t->a = o.a; t->b = o.b; t->c = o.c;
        return *this;
    }
};
struct V_00240DE0 { unsigned int cap; unsigned int count; E_00240DE0* data; };
static inline void Construct_240DE0(E_00240DE0* p, const E_00240DE0* src)
{
    if (p)
        *p = *src;
}
extern "C" {
extern char D_004A6FE0[];
extern char D_004A7158[];
extern char D_004A7188[];
void func_002413F0(V_00240DE0* a, V_00240DE0* b);
}
extern "C" void func_00240DE0(V_00240DE0* v, E_00240DE0* pos, unsigned int n, const E_00240DE0* value)
{
    unsigned int maxN;
    if (n == 0)
        return;
    maxN = 0x180000;
    if (n > maxN || v->count > maxN - n) {
        func_00123BE8(D_00489738->stream, D_004A6FE0);
        func_00121B60();
    }
    unsigned int cap = v->cap; unsigned int cnt_ = v->count;
    if (cnt_ + n <= cap) {
        E_00240DE0* end = v->data + cnt_;
        unsigned int after = end - pos;
        if (after < n) {
            E_00240DE0* p = end;
            for (; n > after; n--) {
                Construct_240DE0(p, value);
                p++;
                v->count++;
            }
            for (E_00240DE0* q = pos; q < end; q++, p++) {
                Construct_240DE0(p, q);
                v->count++;
            }
        } else {
            E_00240DE0* src = end - n;
            E_00240DE0* dst = end;
            for (; src < end; src++, dst++) {
                Construct_240DE0(dst, src);
                v->count++;
            }
            if (end - (after - n) <= value && value < end)
                value += n;
            E_00240DE0* last = pos + (after - n);
            E_00240DE0* d = end;
            while (last > pos) {
                --last;
                --d;
                *d = *last;
            }
        }
        {
            const E_00240DE0& x = *value;
            while (n) {
                *pos = x;
                --n;
                ++pos;
            }
        }
    } else {
        V_00240DE0 tmp;
        E_00240DE0* dst;
        unsigned int newCap;
        E_00240DE0* src;
        unsigned int* tcap;
        E_00240DE0* srcEnd;
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
        tmp.data = (E_00240DE0*)TStr_Alloc(newCap * sizeof(E_00240DE0), D_004A7158, 0x5C);
        tcap = &tmp.cap;
        *tcap = newCap;
        src = v->data;
        srcEnd = src + v->count;
        dst = tmp.data;
        for (; src < pos; src++, dst++) {
            Construct_240DE0(dst, src);
            tmp.count++;
        }
        for (; n; dst++, n--) {
            Construct_240DE0(dst, value);
            tmp.count++;
        }
        for (; src < srcEnd; src++, dst++) {
            Construct_240DE0(dst, src);
            tmp.count++;
        }
        func_002413F0(&tmp, v);
        {
            E_00240DE0* e;
            E_00240DE0* b = tmp.data;
            e = b + tmp.count;
            while (e > b)
                --e;
        }
        tmp.count = 0;
        {
            E_00240DE0* fp_ = tmp.data;
            if (fp_) {
                if (fp_)
                    TStr_Free((char*)fp_, D_004A7188, 0x64);
            }
        }
    }
}
