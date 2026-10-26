#pragma cplusplus on
#include "types.h"
#include "tstr_types.h"
/* std_vector_imp_tRankInfo_insert: vector<DosEntry>::insert(pos, n, value) for the 36-byte dossier entries
 * (Global_cAgentData__RegisterDossier pushes through it); vector_insert_fill_t.h body with the end/after
 * declarations split (declaring after first gives retail's register order). */
struct E_00338B60 { int m0; int m1; int m2; int m3; char s[16]; int key; };
struct std_vector_imp_tRankInfo_insert_V { unsigned int cap; unsigned int count; E_00338B60* data; };
static inline void std_vector_imp_tRankInfo_insert_Construct(E_00338B60* p, const E_00338B60* src)
{
    if (p)
        *p = *src;
}
extern "C" {
extern char D_004B9320[];
extern char D_004B9928[];
void std_swap_vectordeleterR_vectordeleterR_32(std_vector_imp_tRankInfo_insert_V* a, std_vector_imp_tRankInfo_insert_V* b);
void std_vector_deleter_tRankInfo_dtor(std_vector_imp_tRankInfo_insert_V* v, int flags);
}
extern "C" void std_vector_imp_tRankInfo_insert(std_vector_imp_tRankInfo_insert_V* v, E_00338B60* pos, unsigned int n, const E_00338B60* value)
{
    if (n == 0)
        return;
    if (n > 0x2AAAAA || v->count > 0x2AAAAA - n) {
        Libc_Fprintf(D_00489738->stream, D_004B9320);
        Libc_Abort();
    }
    if (v->count + n <= v->cap) {
        unsigned int after;
        E_00338B60* end = v->data + v->count;
        after = end - pos;
        if (after < n) {
            E_00338B60* p = end;
            for (; after < n; n--) {
                std_vector_imp_tRankInfo_insert_Construct(p, value);
                p++;
                v->count++;
            }
            for (E_00338B60* q = pos; q < end; q++, p++) {
                std_vector_imp_tRankInfo_insert_Construct(p, q);
                v->count++;
            }
        } else {
            E_00338B60* src = end - n;
            E_00338B60* dst = end;
            for (; src < end; src++, dst++) {
                std_vector_imp_tRankInfo_insert_Construct(dst, src);
                v->count++;
            }
            if (end - (after - n) <= value && value < end)
                value += n;
            E_00338B60* last = pos + (after - n);
            E_00338B60* d = end;
            while (pos < last) {
                --last;
                --d;
                *d = *last;
            }
        }
        if (n) do {
            *pos = *value;
            --n;
            ++pos;
        } while (n);
    } else {
        std_vector_imp_tRankInfo_insert_V tmp;
        E_00338B60* dst;
        unsigned int newCap;
        E_00338B60** tdata;
        E_00338B60* src;
        unsigned int* tcount;
        E_00338B60* srcEnd;
        unsigned int need;
        tcount = &tmp.count;
        tdata = &tmp.data;
        tmp.cap = 0;
        *tcount = 0;
        *tdata = 0;
        need = v->count + n;
        newCap = v->cap ? v->cap : 1;
        while (need > newCap) {
            if (newCap < 0x155555)
                newCap *= 2;
            else
                newCap = 0x2AAAAA;
        }
        *tdata = (E_00338B60*)TStr_Alloc(newCap * sizeof(E_00338B60), D_004B9928, 0x5C);
        tmp.cap = newCap;
        src = v->data;
        srcEnd = src + v->count;
        dst = *tdata;
        for (; src < pos; src++, dst++) {
            std_vector_imp_tRankInfo_insert_Construct(dst, src);
            (*tcount)++;
        }
        for (; n; n--, dst++) {
            std_vector_imp_tRankInfo_insert_Construct(dst, value);
            (*tcount)++;
        }
        for (; src < srcEnd; src++, dst++) {
            std_vector_imp_tRankInfo_insert_Construct(dst, src);
            (*tcount)++;
        }
        std_swap_vectordeleterR_vectordeleterR_32(&tmp, v);
        std_vector_deleter_tRankInfo_dtor(&tmp, -1);
    }
}
