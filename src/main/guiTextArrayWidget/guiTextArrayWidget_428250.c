/*
 * main/guiTextArrayWidget: 3 files, 00428250-00428450
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00428250 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char unused; } Alloc0041BCE0; /* empty allocator object passed by value */
typedef struct { unsigned long long isLong : 1; unsigned long long size : 7; } Short0041BCE0;
typedef union { unsigned int flags; Short0041BCE0 s; struct { int f0; int length; char* data; } l; } Str0041BCE0;
extern void String_Replace(Str0041BCE0* str, int pos, int count, int a, int b, Alloc0041BCE0 alloc);
/* Forward (0, size) of the string to String_Replace. */
void func_00428250(Str0041BCE0* s, int a, int b)
{
    Alloc0041BCE0 alloc;
    int len;
    if (s->flags & 1) {
        len = s->l.length;
    } else {
        len = (unsigned char)s->s.size;
    }
    String_Replace(s, 0, len, a, b, alloc);
}
#pragma pop /* merge_units */
/* merge_units: end func_00428250 */

/* merge_units: begin func_004282A0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "guiTextArrayWidget_types.h"

extern "C" {
TextArrayCell* func_004283C0(TextArrayCell* first, TextArrayCell* last,
                            TextArrayCell* destination);
void func_004267B0(TextArrayCell* cell, int flags);
}

/* Compact surviving cells, destroy the vacated tail and update the live count. */
extern "C" TextArrayCell* func_004282A0(TextArrayRow* self, TextArrayCell* first,
                                     TextArrayCell* last)
{
    if (first == last)
        return first;
    TextArrayCell* end = self->data + self->count;
    int tailCount = end - last;
    if (tailCount)
        func_004283C0(last, end, first);
    TextArrayCell* tail = first + tailCount;
    while (tail < end) {
        func_004267B0(tail, -1);
        ++tail;
    }
    self->count -= last - first;
    return first;
}

/* Copy cells forward with string ownership and aligned color assignment. */
extern "C" TextArrayCell* func_004283C0(TextArrayCell* first, TextArrayCell* last,
                                     TextArrayCell* destination)
{
    while (first < last) {
        copy_text_array_cell(destination, first);
        ++first;
        ++destination;
    }
    return destination;
}
#pragma pop /* merge_units */
/* merge_units: end func_004282A0 */

/* merge_units: begin func_00428450 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "tstr_types.h"

extern "C" {
void func_0013BCB0(void* d, const void* s);
extern char D_004BF830[];
extern char D_004BF878[];
void func_00428A00(TextArrayCell* d, unsigned int n, const TextArrayCell* v);
TextArrayCell* func_00428A80(TextArrayCell* f, TextArrayCell* l, TextArrayCell* d);
}

typedef struct CellVec {
    unsigned int cap;
    unsigned int count;
    TextArrayCell* data;
} CellVec;

extern "C" {
void func_004289C0(CellVec* a, CellVec* b);
void func_00428090(CellVec* v, int flag);
}

static inline void construct(TextArrayCell* p, const TextArrayCell* v)
{
    if (p) {
        func_0013BCB0(p, v);
        p->flags = v->flags;
        p->attribute = *(const signed char*)&v->attribute;
        p->text = v->text;
        p->color.x = v->color.x;
        p->color.y = v->color.y;
        p->color.z = v->color.z;
        p->color.w = v->color.w;
    }
}

#define T TextArrayCell
/* vector<TextArrayCell>::insert(pos, n, value) */
extern "C" void func_00428450(CellVec* v, T* pos, unsigned int n, const T* value)
{
    if (n == 0)
        return;
    if (n > 0x200000 || v->count > 0x200000 - n) {
        func_00123BE8(D_00489738->stream, D_004BF830);
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
            func_00428A80(pos, pos + (after - n), end);
        }
        func_00428A00(pos, n, value);
    } else {
        CellVec tmp;
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
            if (newCap < 0x100000)
                newCap *= 2;
            else
                newCap = 0x200000;
        }
        *tdata = (T*)TStr_Alloc(newCap * sizeof(T), D_004BF878, 0x5C);
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
        func_004289C0(&tmp, v);
        func_00428090(&tmp, -1);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00428450 */
