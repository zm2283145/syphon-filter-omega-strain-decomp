#pragma cplusplus on
#pragma peephole off
#pragma opt_loop_invariants off
#include "types.h"
#include "tstr_types.h"

struct E1C49F0 { int w[3]; unsigned char b; };
struct V1C49F0 { unsigned int cap; unsigned int count; E1C49F0* data; };
extern "C" {
extern char D_0049F2C0[];
extern char D_0049F358[];
void std_vector_pod_int_ctor(E1C49F0* d, const E1C49F0* s);
void std_copy_backward_cArray_int_copy_backward(E1C49F0* first, E1C49F0* last, E1C49F0* dlast);
void std_fill_n_cArray_int_int_fill_n(E1C49F0* first, unsigned int n, const E1C49F0* value);
void std_swap_vectordeleterR_vectordeleterR_11(V1C49F0* a, V1C49F0* b);
void func_00139EE0(V1C49F0* v, int flags);
}
static inline void Construct1C49F0(E1C49F0* p, const E1C49F0* src)
{
    if (p)
        { std_vector_pod_int_ctor(p, src); p->b = src->b; }
}

extern "C" void std_vector_imp_cArray_int_insert(V1C49F0* v, E1C49F0* pos, unsigned int n, const E1C49F0* value)
{
    if (n == 0)
        return;
    if (n > 0x600000 || v->count > 0x600000 - n) {
        Libc_Fprintf(D_00489738->stream, D_0049F2C0);
        Libc_Abort();
    }
    if (v->count + n <= v->cap) {
        unsigned int off_ = v->count * sizeof(E1C49F0); E1C49F0* data_ = v->data;
        unsigned int after = ((E1C49F0*)((char*)data_ + off_)) - pos;
        if (after < n) {
            E1C49F0* p = ((E1C49F0*)((char*)data_ + off_));
            for (; after < n; n--) {
                Construct1C49F0(p, value);
                p++;
                v->count++;
            }
            for (E1C49F0* q = pos; q < ((E1C49F0*)((char*)data_ + off_)); q++, p++) {
                Construct1C49F0(p, q);
                v->count++;
            }
        } else {
            E1C49F0* src = ((E1C49F0*)((char*)data_ + off_)) - n;
            E1C49F0* dst = ((E1C49F0*)((char*)data_ + off_));
            for (; src < ((E1C49F0*)((char*)data_ + off_)); src++, dst++) {
                Construct1C49F0(dst, src);
                v->count++;
            }
            if (((E1C49F0*)((char*)data_ + off_)) - (after - n) <= value && value < ((E1C49F0*)((char*)data_ + off_)))
                value += n;
            std_copy_backward_cArray_int_copy_backward(pos, pos + (after - n), ((E1C49F0*)((char*)data_ + off_)));
        }
        std_fill_n_cArray_int_int_fill_n(pos, n, value);
    } else {
        V1C49F0 tmp;
        E1C49F0* dst;
        unsigned int newCap;
        E1C49F0** tdata;
        E1C49F0* src;
        unsigned int* tcount;
        E1C49F0* srcEnd;
        unsigned int need;
        tcount = &tmp.count;
        tdata = &tmp.data;
        tmp.cap = 0;
        *tcount = 0;
        *tdata = 0;
        need = v->count + n;
        newCap = v->cap ? v->cap : 1;
        while (need > newCap) {
            if (newCap < 0x300000)
                newCap *= 2;
            else
                newCap = 0x600000;
        }
        *tdata = (E1C49F0*)TStr_Alloc(newCap * sizeof(E1C49F0), D_0049F358, 0x5C);
        tmp.cap = newCap;
        src = v->data;
        srcEnd = src + v->count;
        dst = *tdata;
        for (; src < pos; src++, dst++) {
            Construct1C49F0(dst, src);
            (*tcount)++;
        }
        for (; n; n--, dst++) {
            Construct1C49F0(dst, value);
            (*tcount)++;
        }
        for (; src < srcEnd; src++, dst++) {
            Construct1C49F0(dst, src);
            (*tcount)++;
        }
        std_swap_vectordeleterR_vectordeleterR_11(&tmp, v);
        func_00139EE0(&tmp, -1);
    }
}


