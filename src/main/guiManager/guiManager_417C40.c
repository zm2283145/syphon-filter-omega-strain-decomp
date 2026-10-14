/*
 * main/guiManager: 2 files, 00417C40-00417C60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00417C40 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Rel* func_00417C40(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end func_00417C40 */

/* merge_units: begin func_00417C60 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "tstr_types.h"

struct E7C60 { char s[0xC]; signed char c; int a; int b; };
struct V7C60 { unsigned int cap; unsigned int count; E7C60* data; };
extern "C" {
extern char D_004BF080[];
extern char D_004BF0B0[];
void func_0013BCB0(void* d, const void* s);
E7C60* func_004181C0(E7C60* first, E7C60* last, E7C60* result);
void func_00418150(E7C60* p, unsigned int n, const E7C60* v);
void func_00418110(V7C60* a, V7C60* b);
void func_00418240(V7C60* v, int f);
}

static inline void construct(E7C60* p, const E7C60* s)
{
    if (p) {
        func_0013BCB0(p, s);
        p->c = s->c;
        p->a = s->a;
        p->b = s->b;
    }
}

#define T E7C60
extern "C" void func_00417C60(V7C60* v, T* pos, unsigned int n, const T* value)
{
    if (n == 0)
        return;
    if (n > 0x400000 || v->count > 0x400000 - n) {
        func_00123BE8(D_00489738->stream, D_004BF080);
        func_00121B60();
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
            func_004181C0(pos, pos + (after - n), end);
        }
        func_00418150(pos, n, value);
    } else {
        V7C60 tmp;
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
            if (newCap < 0x200000)
                newCap *= 2;
            else
                newCap = 0x400000;
        }
        *tdata = (T*)TStr_Alloc(newCap * sizeof(T), D_004BF0B0, 0x5C);
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
        func_00418110(&tmp, v);
        func_00418240(&tmp, -1);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00417C60 */
