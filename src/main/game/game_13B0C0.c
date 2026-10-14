/*
 * main/game: 6 files, 0013B0C0-0013B270
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0013B0C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

IntPair* func_0013B0C0(IntPair* p) {
    p->a = 0;
    p->b = 0;
    return p;
}

Byte3* func_0013B0D0(Byte3* b) {
    b->b0 = 0;
    b->b2 = 0;
    return b;
}
#pragma pop /* merge_units */
/* merge_units: end func_0013B0C0 */

/* merge_units: begin func_0013B0E0 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct S { V4 a; V4 b; V4 c; V4 d; V4 e; unsigned char f; unsigned char g; unsigned char h; V4 i; } S;
/* GCC-style volatile lq/sq quad copy (c57da idiom): keeps the unfolded addiu address regs */
static inline void V4_Copy(V4* d, const V4* s) { __int128 q; __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
S* func_0013B0E0(S* d, const S* s)
{
    V4_Copy(&d->a, &s->a);
    V4_Copy(&d->b, &s->b);
    V4_Copy(&d->c, &s->c);
    V4_Copy(&d->d, &s->d);
    d->f = s->f;
    V4_Copy(&d->e, &s->e);
    V4_Copy(&d->i, &s->i);
    d->g = s->g;
    d->h = s->h;
    return d;
}
#pragma pop /* merge_units */
/* merge_units: end func_0013B0E0 */

/* merge_units: begin func_0013B160 */
#pragma push /* merge_units */
void func_0013B160(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* func_0013B170(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_0013B180(Iter* out, PtrVec* v) {
    out->p = v->data;
}
#pragma pop /* merge_units */
/* merge_units: end func_0013B160 */

/* merge_units: begin func_0013B190 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "payload_message_clone.h"

extern "C" { char D_0049AED0[] = "los.hh"; }
DEFINE_PAYLOAD_MESSAGE_CLONE(func_0013B190, 0xD0, D_0049AED0, 0x1A8, D_004D91C0, func_0013B010)
#pragma pop /* merge_units */
/* merge_units: end func_0013B190 */

/* merge_units: begin func_0013B260 */
#pragma push /* merge_units */
/* clear(): count = 0. */
void func_0013B260(PtrVec* v) {
    v->count = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0013B260 */

/* merge_units: begin func_0013B270 */
#pragma push /* merge_units */
#pragma cplusplus on
struct E1EEEC0 { int w[4]; };
struct V1EEEC0 { int capacity; int count; E1EEEC0* data; };
extern "C" void func_0013B2E0(E1EEEC0* e, int flags);
extern "C" void func_0013B270(V1EEEC0* v)
{
    E1EEEC0* first = v->data;
    E1EEEC0* last = first + v->count;
    while (first < last) {
        --last;
        func_0013B2E0(last, -1);
    }
    v->count = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0013B270 */
