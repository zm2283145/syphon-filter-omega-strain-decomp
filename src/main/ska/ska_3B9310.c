/*
 * main/ska: range (3 files, 003B9310-003B94D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003B9310 */
#pragma push /* merge_units */
#pragma cplusplus on

typedef union Str {
    struct { unsigned int word; unsigned int length; char* data; } l;
    struct { unsigned int isLong : 1; unsigned int length : 7; } s;
    char inl[12];
} Str;

typedef struct Alloc { char unused; } Alloc;

extern "C" {
Str* String_Replace(Str* s, unsigned int pos, unsigned int n, const char* first, const char* last, Alloc a);
void func_00123BE8(int, const char*);
void Libc_Abort(void);
extern char* D_00489738;
}

template <class T> static inline const T& Min(const T& a, const T& b) { return b < a ? b : a; }

extern "C" Str* func_003B9310(Str* self, unsigned int pos, unsigned int n1, const Str* str, unsigned int pos2, unsigned int n2)
{
    unsigned int rem;
    Alloc a;
    const char* data;
    unsigned int len;
    if (!(str->l.word & 1)) {
        data = (const char*)str + 1;
        len = (unsigned char)str->s.length;
    } else {
        data = str->l.data;
        len = str->l.length;
    }
    if (len < pos2) {
        func_00123BE8(*(int*)(D_00489738 + 0xC), "basic_string: out_of_range");
        Libc_Abort();
    }
    data += pos2;
    rem = len - pos2; n2 = Min(n2, rem);
    return String_Replace(self, pos, n1, data, data + n2, a);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B9310(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B9310 */

/* merge_units: begin func_003B9410 */
#pragma push /* merge_units */
#pragma cplusplus on


extern "C" unsigned int func_003B9410(const Str* self, const char* s, unsigned int pos, unsigned int n)
{
    const char* data;
    unsigned int len;
    if (!(self->l.word & 1)) {
        data = (const char*)self + 1;
        len = (unsigned char)self->s.length;
    } else {
        data = self->l.data;
        len = self->l.length;
    }
    if (len >= n) {
        const char* last;
        const char* p;
        if (len - n < pos) pos = len - n;
        last = s + n;
        for (p = data + pos; ; --p) {
            const char* g = p;
            const char* f = s;
            for (; f < last; ++f, ++g)
                if (*f != *g) goto next;
            return p - data;
        next:
            if (!(data < p)) break;
        }
    }
    return (unsigned int)-1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B9410(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B9410 */

/* merge_units: begin func_003B94D0 */
#pragma push /* merge_units */
typedef struct LCNode_c7 { struct LCNode_c7* prev; struct LCNode_c7* next; int data; } LCNode_c7;
typedef struct { LCNode_c7* node; } LCIter_c7;
extern void func_0013B160(LCIter_c7* out, void* list);
extern LCIter_c7* List_InsertBefore(LCIter_c7* out, void* list, LCIter_c7* pos, int* value);
void List_CopyRange(void* list, LCIter_c7 first, LCIter_c7 last) { LCNode_c7* n; for (n = first.node; n != last.node; n = n->next) { LCIter_c7 res; LCIter_c7 pos; func_0013B160(&pos, list); List_InsertBefore(&res, list, &pos, &n->data); } }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B94D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B94D0 */
