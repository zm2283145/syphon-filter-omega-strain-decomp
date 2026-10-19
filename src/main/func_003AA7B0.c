#include "types.h"
#pragma cplusplus on
#include "tstr_types.h"
struct SkelNode { int w[0x1D0 / 4]; };
struct SkelVec { unsigned int cap; unsigned int count; SkelNode* data; };
extern "C" {
void SkelNode_Assign(SkelNode* d, const SkelNode* s);
void SkelNode_CopyConstruct(SkelNode* d, const SkelNode* s);
extern char D_004BCD10[];
extern char D_004BC510[];
extern char D_004BC4F0[];
void func_003AACC0(SkelVec* a, SkelVec* b);
void func_00396B80(SkelVec* v);
}
static inline void SkelNode_Construct(SkelNode* p, const SkelNode* src)
{
    if (p)
        SkelNode_Assign(p, src);
}
extern "C" void func_003AA7B0(SkelVec* v, SkelNode* pos, unsigned int n, const SkelNode* value)
{
    if (n == 0)
        return;
    if (n > 0x34F72 || v->count > 0x34F72 - n) {
        func_00123BE8(D_00489738->stream, D_004BCD10);
        Libc_Abort();
    }
    if (v->count + n <= v->cap) {
        SkelNode* p; SkelNode* q; SkelNode* src; SkelNode* dst; SkelNode* end;
        end = v->data + v->count;
        unsigned int after = end - pos;
        if (after < n) {
            p = end;
            for (; after < n; n--) {
                SkelNode_Construct(p, value);
                p++;
                v->count++;
            }
            for (q = pos; q < end; q++, p++) {
                SkelNode_Construct(p, q);
                v->count++;
            }
        } else {
            src = end - n;
            dst = end;
            for (; src < end; src++, dst++) {
                SkelNode_Construct(dst, src);
                v->count++;
            }
            if (end - (after - n) <= value && value < end)
                value += n;
            SkelNode* last = pos + (after - n);
            SkelNode* d = end;
            while (pos < last) {
                --d;
                --last;
                SkelNode_CopyConstruct(d, last);
            }
        }
        if (n) do {
            SkelNode_CopyConstruct(pos, value);
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
            SkelNode_Construct(dst, src);
            (*tcount)++;
        }
        for (; n; n--, dst++) {
            SkelNode_Construct(dst, value);
            (*tcount)++;
        }
        for (; src < srcEnd; src++, dst++) {
            SkelNode_Construct(dst, src);
            (*tcount)++;
        }
        func_003AACC0(&tmp, v);
        func_00396B80(&tmp);
        {
            SkelNode* fp_ = tmp.data;
            if (fp_) {
                if (fp_)
                    TStr_Free((char*)fp_, D_004BC4F0, 0x64);
            }
        }
    }
}


