#include "types.h"
#pragma cplusplus on
#include "tstr_types.h"
struct SkelNode { int w[0x1D0 / 4]; };
struct SkelVec { unsigned int cap; unsigned int count; SkelNode* data; };
extern "C" {
void cBone_ctor_cBoneR(SkelNode* d, const SkelNode* s);
void cBone_opAssign(SkelNode* d, const SkelNode* s);
extern char D_004BCD10[];
extern char D_004BC510[];
extern char D_004BC4F0[];
void std_swap_vectordeleterR_vectordeleterR_38(SkelVec* a, SkelVec* b);
void std_vector_deleter_cBone_clear(SkelVec* v);
}
static inline void cBone_ctor_void(SkelNode* p, const SkelNode* src)
{
    if (p)
        cBone_ctor_cBoneR(p, src);
}
extern "C" void std_vector_imp_cBone_insert(SkelVec* v, SkelNode* pos, unsigned int n, const SkelNode* value)
{
    if (n == 0)
        return;
    if (n > 0x34F72 || v->count > 0x34F72 - n) {
        Libc_Fprintf(D_00489738->stream, D_004BCD10);
        Libc_Abort();
    }
    if (v->count + n <= v->cap) {
        SkelNode* p; SkelNode* q; SkelNode* src; SkelNode* dst; SkelNode* end;
        end = v->data + v->count;
        unsigned int after = end - pos;
        if (after < n) {
            p = end;
            for (; after < n; n--) {
                cBone_ctor_void(p, value);
                p++;
                v->count++;
            }
            for (q = pos; q < end; q++, p++) {
                cBone_ctor_void(p, q);
                v->count++;
            }
        } else {
            src = end - n;
            dst = end;
            for (; src < end; src++, dst++) {
                cBone_ctor_void(dst, src);
                v->count++;
            }
            if (end - (after - n) <= value && value < end)
                value += n;
            SkelNode* last = pos + (after - n);
            SkelNode* d = end;
            while (pos < last) {
                --d;
                --last;
                cBone_opAssign(d, last);
            }
        }
        if (n) do {
            cBone_opAssign(pos, value);
            --n;
            ++pos;
        } while (n);
    } else {
        SkelVec tmp;
        SkelNode* dst;
        unsigned int newCap;
        SkelNode** tdata;
        SkelNode* src;
        unsigned int* tcount;
        SkelNode* srcEnd;
        unsigned int need;
        tcount = &tmp.count;
        tdata = &tmp.data;
        tmp.cap = 0;
        *tcount = 0;
        *tdata = 0;
        need = v->count + n;
        newCap = v->cap ? v->cap : 1;
        while (need > newCap) {
            if (newCap < 0x1A7B9)
                newCap *= 2;
            else
                newCap = 0x34F72;
        }
        *tdata = (SkelNode*)TStr_Alloc(newCap * sizeof(SkelNode), D_004BC510, 0x5C);
        tmp.cap = newCap;
        src = v->data;
        srcEnd = src + v->count;
        dst = *tdata;
        for (; src < pos; src++, dst++) {
            cBone_ctor_void(dst, src);
            (*tcount)++;
        }
        for (; n; n--, dst++) {
            cBone_ctor_void(dst, value);
            (*tcount)++;
        }
        for (; src < srcEnd; src++, dst++) {
            cBone_ctor_void(dst, src);
            (*tcount)++;
        }
        std_swap_vectordeleterR_vectordeleterR_38(&tmp, v);
        std_vector_deleter_cBone_clear(&tmp);
        {
            SkelNode* fp_ = tmp.data;
            if (fp_) {
                if (fp_)
                    TStr_Free((char*)fp_, D_004BC4F0, 0x64);
            }
        }
    }
}


