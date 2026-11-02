/*
 * Libs/SFOLib/Source/ska: 4 files, 003AA7B0-003AACC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003AA7B0 */
#pragma push /* merge_units */
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
#if 0 /* merge_units */
void std_swap_vectordeleterR_vectordeleterR_38(SkelVec* a, SkelVec* b);
#endif /* merge_units */
void std_swap_vectordeleterR_vectordeleterR_38(PtrVec* a, PtrVec* b); /* merge_units */
#define std_swap_vectordeleterR_vectordeleterR_38(a0, a1) (std_swap_vectordeleterR_vectordeleterR_38((PtrVec *)(a0), (PtrVec *)(a1))) /* merge_units */

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
#undef std_swap_vectordeleterR_vectordeleterR_38 /* merge_units */
static inline void merge_flush_func_003AA7B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AA7B0 */

/* merge_units: begin func_003AACC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void std_swap_vectordeleterR_vectordeleterR_38(PtrVec* a, PtrVec* b) {
    if (a != b) {
        int t;
        int* p;
        t = a->unk0;
        a->unk0 = b->unk0;
        b->unk0 = t;
        p = a->data;
        a->data = b->data;
        b->data = p;
        t = a->count;
        a->count = b->count;
        b->count = t;
    }
}
static inline void merge_flush_func_003AACC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AACC0 */

/* merge_units: begin func_003AAD00 */
#pragma push /* merge_units */
typedef struct Vec3AD { float x; float y; float z; } Vec3AD;
typedef struct { int capacity; int count; Vec3AD *data; } Vec3ADVector;
Vec3AD *std_vector_imp_cBoneScale_erase(Vec3ADVector *v, Vec3AD *first, Vec3AD *last)
{
    Vec3AD *end;
    Vec3AD *s;
    Vec3AD *d;
    if (first == last)
        return first;
    end = v->data + v->count;
    if (end - last != 0) {
        d = first;
        s = last;
        while (s < end) {
            d->x = s->x;
            d->y = s->y;
            d->z = s->z;
            s++;
            d++;
        }
    }
    v->count -= last - first;
    return first;
}
static inline void merge_flush_func_003AAD00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AAD00 */

/* merge_units: begin func_003AAEE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_insert_fill_t.h"
struct E_003AAEE0 { float x, y, z; };
extern "C" { char D_004BCD30[] = "allocator.hh"; }
DEFINE_VECTOR_INSERT_FILL_T(std_vector_imp_cBoneScale_insert, E_003AAEE0, 0x800000, 0x400000, D_004BCD10, D_004BCD30, 0x5C, std_swap_vectordeleterR_vectordeleterR_39, std_vector_deleter_cBone_dtor)
static inline void merge_flush_func_003AAEE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AAEE0 */
