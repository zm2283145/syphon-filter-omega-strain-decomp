/*
 * main/human: range (4 files, 00189590-00189840)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00189590 */
#pragma push /* merge_units */
typedef struct { int pad0; int cur[2]; int dirty[2]; } Bits_189740;
void AnimPriority_Helper0(Bits_189740* b, int bit, unsigned char on); /* gsynth: defined below */typedef struct { int top; int bits[1]; } E7PSet;
void AnimPriority_Helper1(E7PSet* s); /* gsynth: defined below */void AnimPriority_Helper2(unsigned int* bits, int idx, int set); /* gsynth: defined below */extern unsigned char AnimPriority_Helper3(void* bits, int index);
#if 0 /* merge_units */
extern void AnimPriority_Helper2(void* p, int index, int v);
#endif /* merge_units */
#define AnimPriority_Helper2(a0, a1, a2) (AnimPriority_Helper2((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void AnimPriority_Helper1(void* p);
#endif /* merge_units */
#define AnimPriority_Helper1(a0) (AnimPriority_Helper1((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void AnimPriority_Helper0(void* p, int index, unsigned char on);
#endif /* merge_units */
#define AnimPriority_Helper0(a0, a1, a2) (AnimPriority_Helper0((void *)(a0), (a1), (a2))) /* merge_units */

extern float D_004A03E0;
typedef struct {
    char pad[0x374];
    float f374;
    char pad378[0x9C0 - 0x378];
    unsigned char b9C0;
} Sub3310;
typedef struct {
    char pad[0x320C];
    char prio[0x3310 - 0x320C];
    Sub3310* s3310;
} Act;
static inline void Prio_(char* p, signed char k) {
    unsigned char on;
    char* q = p;
    on = AnimPriority_Helper3(q + 0xC, k);
    AnimPriority_Helper2(q + 4, k, 0);
    AnimPriority_Helper1(q);
    AnimPriority_Helper0(q, k, on);
}
void func_00189590(Act* a, signed char k) {
    switch (k) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        break;
    case 5:
        Prio_(a->prio, 5);
        if (a->s3310) {
            a->s3310->b9C0 = 0;
            a->s3310->f374 = D_004A03E0;
        }
        break;
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 20:
    case 21:
    case 22:
    case 27:
    case 28:
        break;
    case 29:
    case 30:
        Prio_(a->prio, k);
        break;
    case 31:
        break;
    }
}
#undef AnimPriority_Helper2 /* merge_units */
#undef AnimPriority_Helper1 /* merge_units */
#undef AnimPriority_Helper0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00189590(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00189590 */

/* merge_units: begin func_00189740 */
#pragma push /* merge_units */
static inline int Get_189740(int* a, int bit) { return (a[bit/32] >> (bit&31)) & 1; }
static inline void Set_189740(int* a, int bit) { a[bit/32] |= 1 << (bit&31); }
void AnimPriority_Helper0(Bits_189740* b, int bit, unsigned char on) { if (on != (Get_189740(b->cur, bit) != 0)) Set_189740(b->dirty, bit); }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00189740(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00189740 */

/* merge_units: begin func_001897A0 */
#pragma push /* merge_units */
static inline unsigned char E7Has(E7PSet* s, int n) { return ((s->bits[n / 32] >> (n & 31)) & 1) != 0; }
void AnimPriority_Helper1(E7PSet* s) {
    int i;
    for (i = 31; i >= 0 && !E7Has(s, i); i--) {
    }
    if (!E7Has(s, i)) {
        s->top = -1;
    } else {
        s->top = i;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001897A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001897A0 */

/* merge_units: begin func_00189840 */
#pragma push /* merge_units */
void AnimPriority_Helper2(unsigned int* bits, int idx, int set) {
    if (set) {
        bits[idx / 32] |= 1 << (idx & 31);
    } else {
        bits[idx / 32] &= ~(1 << (idx & 31));
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00189840(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00189840 */
