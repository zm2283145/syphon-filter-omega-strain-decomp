/*
 * main/guiTextListWidget: 6 files, 00422020-004220A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00422020 */
#pragma push /* merge_units */
#include "types.h"

/* String object: three words, zeroed before construction. */
typedef struct StrObj {
    int w0;
    int w1;
    int w2;
} StrObj;

extern int strlen(const char* s); /* strlen */
extern void String_Reserve(StrObj* str, int capacity);
extern void String_Replace(StrObj* str, int pos, int count, const char* first, const char* last, char alloc);

/* String constructor from a C string. */
StrObj* func_00422020(StrObj* self, const char* cstr) {
    volatile char alloc[4];
    int len;
    self->w0 = 0;
    self->w1 = 0;
    self->w2 = 0;
    len = strlen(cstr);
    String_Reserve(self, len);
    String_Replace(self, 0, 0, cstr, cstr + len, alloc[0]);
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00422020 */

/* merge_units: begin func_004220A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "string_replace_range.h"

extern "C" { char D_004BF550[] = "basic_string: out_of_range"; }
extern "C" { char D_004BF570[] = "basic_string: length_error"; }
DEFINE_STRING_REPLACE_RANGE(func_004220A0, D_004BF550, D_004BF570, D_0049ADE0, 0x5C, D_0049AE90, 0x64, D_00494130, D_00494138, func_00125FE8, String_Assign)
#pragma pop /* merge_units */
/* merge_units: end func_004220A0 */

/* merge_units: begin func_00422590 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "short_string_assign.h"

/* Assign one string to another. */
DEFINE_SHORT_STRING_ASSIGN(func_00422590)
#pragma pop /* merge_units */
/* merge_units: end func_00422590 */

/* merge_units: begin func_00422620 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "string_reserve.h"

extern "C" { char D_004BF590[] = "basic_string::reserve length_error"; }
DEFINE_STRING_RESERVE(func_00422620, D_004BF590, D_0049ADE0, 0x5C, D_0049AE90, 0x64)
#pragma pop /* merge_units */
/* merge_units: end func_00422620 */

/* merge_units: begin func_00422960 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "stream_string_dtor.h"

/* Destroy a string holder: free heap storage, optionally delete. */
DEFINE_STREAM_STRING_DTOR(func_00422960)
#pragma pop /* merge_units */
/* merge_units: end func_00422960 */

/* merge_units: begin func_00422A50 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "guiTextListWidget_types.h"
#include "tstr_types.h"

extern "C" {
void func_0013BCB0(void* d, const void* s);
extern char D_004BF5C0[];
extern char D_004BF618[];
void func_00422F10(TextListEntry* d, unsigned int n, const TextListEntry* v);
void func_00422F80(TextListEntry* f, TextListEntry* l, TextListEntry* d);
}

typedef struct Vec22 {
    unsigned int cap;
    unsigned int count;
    TextListEntry* data;
} Vec22;

extern "C" {
void func_00422ED0(Vec22* a, Vec22* b);
void func_00423000(Vec22* v, int flag);
}

static inline void construct(TextListEntry* p, const TextListEntry* v)
{
    if (p) {
        func_0013BCB0(p, v);
        p->unk0C = v->unk0C;
        p->unk10 = v->unk10;
    }
}

#define T TextListEntry
extern "C" void func_00422A50(Vec22* v, T* pos, unsigned int n, const T* value)
{
    if (n == 0)
        return;
    if (n > 0x4CCCCC || v->count > 0x4CCCCC - n) {
        func_00123BE8(D_00489738->stream, D_004BF5C0);
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
            func_00422F80(pos, pos + (after - n), end);
        }
        func_00422F10(pos, n, value);
    } else {
        Vec22 tmp;
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
            if (newCap < 0x266666)
                newCap *= 2;
            else
                newCap = 0x4CCCCC;
        }
        *tdata = (T*)TStr_Alloc(newCap * sizeof(T), D_004BF618, 0x5C);
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
        func_00422ED0(&tmp, v);
        func_00423000(&tmp, -1);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00422A50 */
