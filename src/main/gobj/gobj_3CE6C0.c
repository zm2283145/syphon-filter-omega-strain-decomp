/*
 * main/gobj: range (2 files, 003CE6C0-003CE730)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "gobj_types.h"

/* merge_units: begin func_003CE6C0 */
#pragma push /* merge_units */
Rel* FrameTreeEntry_Construct(Rel* r, int* a, int* b); /* gsynth: defined below */
typedef struct { int value; } Key;
typedef struct { int a; int b; } KeyPair;
typedef struct { int a; int b; int c; } Entry12;
typedef struct { int value; } InsertResult;

#if 0 /* merge_units */
extern void FrameTreeEntry_Construct(Entry12* out, Key* key, KeyPair* pair);
#endif /* merge_units */
#define FrameTreeEntry_Construct(a0, a1, a2) ((void)FrameTreeEntry_Construct((void *)(a0), (void *)(a1), (void *)(a2))) /* merge_units */

extern void FrameTree_Find(InsertResult* out, void* self, Entry12* entry);

/* Builds an entry from copies of key and pair and inserts a copy of it into self. */
void func_003CE6C0(void* self, Key* key, KeyPair* pair)
{
    KeyPair pairCopy;
    Entry12 entry;
    Entry12 entryCopy;
    Key keyCopy;
    InsertResult result;
    pairCopy.a = pair->a;
    pairCopy.b = pair->b;
    keyCopy.value = key->value;
    FrameTreeEntry_Construct(&entry, &keyCopy, &pairCopy);
    entryCopy.a = entry.a;
    entryCopy.b = entry.b;
    entryCopy.c = entry.c;
    FrameTree_Find(&result, self, &entryCopy);
}
#undef FrameTreeEntry_Construct /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CE6C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CE6C0 */

/* merge_units: begin func_003CE730 */
#pragma push /* merge_units */
/*
 * Matched functions from gobj.cc (byte-identical with the retail executable).
 */


/* Builds a three-word record from one word of a and two words of b. */
Rel* FrameTreeEntry_Construct(Rel* r, int* a, int* b) {
    r->a = a[0];
    r->b = b[0];
    r->c = b[1];
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CE730(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CE730 */
