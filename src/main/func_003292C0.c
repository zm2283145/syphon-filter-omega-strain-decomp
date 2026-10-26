/* std_vector_imp_Slide_insert: vector<T>::insert(pos, n, value) for a 0x2C-byte element holding two strings
 * (copy-constructed by String_CopyCtor); same shape as std_vector_imp_GuiAnimationTrack_insert. */
#pragma cplusplus on
#include "tstr_types.h"

struct E_3292C0 { char s[0xC]; int x0C; char t[0xC]; unsigned char x1C; int x20; int x24; int x28; };
struct V_3292C0 { unsigned int cap; unsigned int count; E_3292C0* data; };
extern "C" {
extern char D_004B8810[];
extern char D_004B88C0[];
void String_CopyCtor(void* d, const void* s);
E_3292C0* std_copy_backward_Slide_copy_backward(E_3292C0* first, E_3292C0* last, E_3292C0* result);
void std_fill_n_Slide_int_fill_n(E_3292C0* p, unsigned int n, const E_3292C0* v);
void std_swap_vectordeleterR_vectordeleterR_26(V_3292C0* a, V_3292C0* b);
void std_vector_deleter_Slide_dtor(V_3292C0* v, int f);
}

static inline void construct(E_3292C0* p, const E_3292C0* s)
{
    if (p) {
        String_CopyCtor(p, s);
        p->x0C = s->x0C;
        String_CopyCtor(p->t, s->t);
        p->x1C = s->x1C;
        p->x20 = s->x20;
        p->x24 = s->x24;
        p->x28 = s->x28;
    }
}

#define T E_3292C0
extern "C" void std_vector_imp_Slide_insert(V_3292C0* v, T* pos, unsigned int n, const T* value)
{
    if (n == 0)
        return;
    if (n > 0x22E8BA || v->count > 0x22E8BA - n) {
        Libc_Fprintf(D_00489738->stream, D_004B8810);
        Libc_Abort();
    }
    if (v->count + n <= v->cap) {
        T* p; T* q; T* src; T* dst; T* end;
        end = v->data + v->count;
        unsigned int after = end - pos;
        if (after < n) {
            p = end;
            for (; after < n; n--) {
                construct(p, value);
                p++;
                v->count++;
            }
            for (q = pos; q < end; q++, p++) {
                construct(p, q);
                v->count++;
            }
        } else {
            src = end - n;
            dst = end;
            for (; src < end; src++, dst++) {
                construct(dst, src);
                v->count++;
            }
            if (end - (after - n) <= value && value < end)
                value += n;
            std_copy_backward_Slide_copy_backward(pos, pos + (after - n), end);
        }
        std_fill_n_Slide_int_fill_n(pos, n, value);
    } else {
        V_3292C0 tmp;
        T* dst;
        unsigned int newCap;
        T** tdata;
        T* src;
        unsigned int* tcount;
        T* srcEnd;
        unsigned int need;
        tcount = &tmp.count;
        tdata = &tmp.data;
        tmp.cap = 0;
        *tcount = 0;
        *tdata = 0;
        need = v->count + n;
        newCap = v->cap ? v->cap : 1;
        while (need > newCap) {
            if (newCap < 0x11745D)
                newCap *= 2;
            else
                newCap = 0x22E8BA;
        }
        *tdata = (T*)TStr_Alloc(newCap * sizeof(T), D_004B88C0, 0x5C);
        tmp.cap = newCap;
        src = v->data;
        srcEnd = src + v->count;
        dst = *tdata;
        for (; src < pos; src++, dst++) {
            construct(dst, src);
            (*tcount)++;
        }
        for (; n; n--, dst++) {
            construct(dst, value);
            (*tcount)++;
        }
        for (; src < srcEnd; src++, dst++) {
            construct(dst, src);
            (*tcount)++;
        }
        std_swap_vectordeleterR_vectordeleterR_26(&tmp, v);
        std_vector_deleter_Slide_dtor(&tmp, -1);
    }
}
