/*
 * main/human: range (3 files, 0018A6E0-0018A810)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0018A6E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Word* func_0018A6E0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_0018A6F0(Iter* out, Tree* t) {
    out->p = &t->header;
}

int* func_0018A700(int* pair, int second) {
    pair[0] = 0;
    pair[1] = second;
    return pair;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0018A6E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0018A6E0 */

/* merge_units: begin func_0018A710 */
#pragma push /* merge_units */
typedef struct Rec14 {
    char b[0x14];
} Rec14;
typedef struct Vec14 {
    int unk0;
    int count;
    Rec14* data;
} Vec14;
Vec14* func_0018A810(Vec14* self, Vec14* other); /* gsynth: defined below */
typedef struct { int a; int b; } Pair;
typedef struct { char pad[0xC]; unsigned char flag; } Tail;
typedef struct {
    unsigned char kind;
    char pad[3];
    Pair pairs[7];
    Tail tail;
} Obj;
extern void __construct_array(void* array, void (*ctor)(void*), void (*dtor)(void*), int size, int count);
extern void func_0018A210(void* p);
extern void func_0018A870(void* p);
#if 0 /* merge_units */
extern void func_0018A810(Tail* dst, Tail* src);
#endif /* merge_units */
#define func_0018A810(a0, a1) ((void)func_0018A810((void *)(a0), (void *)(a1))) /* merge_units */


/* Copy constructor. */
Obj* func_0018A710(Obj* self, Obj* src)
{
    int i;
    Tail* tail;
    Pair* dst;
    self->kind = src->kind;
    dst = self->pairs;
    __construct_array(dst, func_0018A870, func_0018A210, 8, 7);
    for (i = 0; i < 7; i++) {
        dst[i].a = src->pairs[i].a;
        dst[i].b = src->pairs[i].b;
    }
    tail = &self->tail;
    func_0018A810(tail, &src->tail);
    tail->flag = src->tail.flag;
    return self;
}
#undef func_0018A810 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0018A710(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0018A710 */

/* merge_units: begin func_0018A810 */
#pragma push /* merge_units */
/* Empty tag object passed by value (an allocator in the original C++). */
typedef struct Tag {
    signed char unused;
} Tag;

extern void Array_CopyRange20(Vec14*, Rec14*, Rec14*, Tag);

/* Copy-constructs a vector of 20-byte records. */
Vec14* func_0018A810(Vec14* self, Vec14* other) {
    Tag tag;
    self->unk0 = 0;
    self->count = 0;
    self->data = 0;
    Array_CopyRange20(self, other->data, other->data + other->count, tag);
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0018A810(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0018A810 */
