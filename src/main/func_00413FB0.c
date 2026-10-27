#pragma cplusplus on
#pragma peephole off
#pragma opt_loop_invariants off
#include "types.h"
#include "tstr_types.h"

struct E413FB0 { int w[3]; };
struct V413FB0 { unsigned int cap; unsigned int count; E413FB0* data; };
extern "C" {
extern char D_004BEF70[];
extern char D_004BEFA0[];
void std_basic_string_char_char_traits_char_ctor_basicstringR(E413FB0* d, const E413FB0* s);
void std_copy_backward_cString_copy_backward(E413FB0* first, E413FB0* last, E413FB0* dlast);
void func_00414410(E413FB0* first, unsigned int n, const E413FB0* value);
void std_swap_vectordeleterR_vectordeleterR_48(V413FB0* a, V413FB0* b);
void std_vector_deleter_cString_dtor(V413FB0* v, int flags);
}
static inline void Construct413FB0(E413FB0* p, const E413FB0* src)
{
    if (p)
        std_basic_string_char_char_traits_char_ctor_basicstringR(p, src);
}

extern "C" void std_vector_imp_cString_insert(V413FB0* v, E413FB0* pos, unsigned int n, const E413FB0* value)
{
    if (n == 0)
        return;
    if (n > 0x800000 || v->count > 0x800000 - n) {
        Libc_Fprintf(D_00489738->stream, D_004BEF70);
        Libc_Abort();
    }
    if (v->count + n <= v->cap) {
        unsigned int off_ = v->count * sizeof(E413FB0); E413FB0* data_ = v->data;
        unsigned int after = ((E413FB0*)((char*)data_ + off_)) - pos;
        if (after < n) {
            E413FB0* p = ((E413FB0*)((char*)data_ + off_));
            for (; after < n; n--) {
                Construct413FB0(p, value);
                p++;
                v->count++;
            }
            for (E413FB0* q = pos; q < ((E413FB0*)((char*)data_ + off_)); q++, p++) {
                Construct413FB0(p, q);
                v->count++;
            }
        } else {
            E413FB0* src = ((E413FB0*)((char*)data_ + off_)) - n;
            E413FB0* dst = ((E413FB0*)((char*)data_ + off_));
            for (; src < ((E413FB0*)((char*)data_ + off_)); src++, dst++) {
                Construct413FB0(dst, src);
                v->count++;
            }
            if (((E413FB0*)((char*)data_ + off_)) - (after - n) <= value && value < ((E413FB0*)((char*)data_ + off_)))
                value += n;
            std_copy_backward_cString_copy_backward(pos, pos + (after - n), ((E413FB0*)((char*)data_ + off_)));
        }
        func_00414410(pos, n, value);
    } else {
        V413FB0 tmp;
        E413FB0* dst;
        unsigned int newCap;
        E413FB0** tdata;
        E413FB0* src;
        unsigned int* tcount;
        E413FB0* srcEnd;
        unsigned int need;
        tcount = &tmp.count;
        tdata = &tmp.data;
        tmp.cap = 0;
        *tcount = 0;
        *tdata = 0;
        need = v->count + n;
        newCap = v->cap ? v->cap : 1;
        while (need > newCap) {
            if (newCap < 0x400000)
                newCap *= 2;
            else
                newCap = 0x800000;
        }
        *tdata = (E413FB0*)TStr_Alloc(newCap * sizeof(E413FB0), D_004BEFA0, 0x5C);
        tmp.cap = newCap;
        src = v->data;
        srcEnd = src + v->count;
        dst = *tdata;
        for (; src < pos; src++, dst++) {
            Construct413FB0(dst, src);
            (*tcount)++;
        }
        for (; n; n--, dst++) {
            Construct413FB0(dst, value);
            (*tcount)++;
        }
        for (; src < srcEnd; src++, dst++) {
            Construct413FB0(dst, src);
            (*tcount)++;
        }
        std_swap_vectordeleterR_vectordeleterR_48(&tmp, v);
        std_vector_deleter_cString_dtor(&tmp, -1);
    }
}


