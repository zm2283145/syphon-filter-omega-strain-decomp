/*
 * main/AgentData: range (2 files, 003379C0-00337A30)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003379C0 */
#pragma push /* merge_units */
typedef struct { int a, b, c; } G4_In;
typedef struct { char a; G4_In b; unsigned char c; } G4_E14;
extern void func_0033A9E0(G4_In* d, G4_In* s);
void func_003379C0(G4_E14* p, unsigned int n, G4_E14* v)
{
    for (; n != 0; n--, p++) {
        p->a = v->a;
        func_0033A9E0(&p->b, &v->b);
        p->c = v->c;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003379C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003379C0 */

/* merge_units: begin func_00337A30 */
#pragma push /* merge_units */
typedef struct { int cap; int size; char* buf; } V3A9E0;
typedef struct { signed char a; V3A9E0 v; unsigned char b; } E37A30;
#if 0 /* merge_units */
extern V3A9E0* func_0033A9E0(V3A9E0* d, V3A9E0* s);
#endif /* merge_units */
#define func_0033A9E0(a0, a1) (func_0033A9E0((void *)(a0), (void *)(a1))) /* merge_units */

E37A30* func_00337A30(E37A30* first, E37A30* last, E37A30* result)
{
    while (first < last) {
        --last;
        --result;
        result->a = last->a;
        func_0033A9E0(&result->v, &last->v);
        result->b = last->b;
    }
    return result;
}
#undef func_0033A9E0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00337A30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00337A30 */
