/*
 * main/GameGOBJ: range (3 files, 0021C190-0021C330)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vector_insert_fill_v2.h"
#pragma pop

/* merge_units: begin func_0021C190 */
#pragma push /* merge_units */
/* func_0021C190: 16-byte-element vector erase(first, last). Hand-matched (auto1 family seed). */
#pragma opt_unroll_loops off
#pragma opt_dead_assignments off
#pragma opt_rotateloops off
typedef struct { int x[4]; } __attribute__((aligned(16))) E16_C190;
typedef struct { int pad; int size; E16_C190* data; } Vec_C190;
E16_C190* func_0021C190(Vec_C190* v, E16_C190* first, E16_C190* last)
{
    E16_C190* end;
    int n;
    E16_C190* p;
    if (first == last) return first;
    end = v->data + v->size;
    n = end - last;
    if (n != 0) {
        E16_C190* s;
        E16_C190* d;
        d = first; s = last;
        while (s < end) *d++ = *s++;
    }
    p = first + n;
    while (p < end) p = (E16_C190*)((char*)p + 16);
    v->size -= last - first;
    return first;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021C190(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021C190 */

/* merge_units: begin func_0021C260 */
#pragma push /* merge_units */
/* func_0021C260: 16-byte-element vector erase(first, last). Hand-matched (auto1 family seed). */
#pragma opt_unroll_loops off
#pragma opt_dead_assignments off
#pragma opt_rotateloops off

E16_C190* func_0021C260(Vec_C190* v, E16_C190* first, E16_C190* last)
{
    E16_C190* end;
    int n;
    E16_C190* p;
    if (first == last) return first;
    end = v->data + v->size;
    n = end - last;
    if (n != 0) {
        E16_C190* s;
        E16_C190* d;
        d = first; s = last;
        while (s < end) *d++ = *s++;
    }
    p = first + n;
    while (p < end) p = (E16_C190*)((char*)p + 16);
    v->size -= last - first;
    return first;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021C260(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021C260 */

/* merge_units: begin func_0021C330 */
#pragma push /* merge_units */
#pragma cplusplus on
struct E_0021C330 { __int128 q; ~E_0021C330() {} };
#define VIF2_COPY(d, s) (*(d) = *(s))
/* whole-function settings; left in effect because C++ code generation is deferred to end of file */
#pragma opt_rotateloops off
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_dead_code off
#pragma opt_loop_invariants off
static char D_004A4650[] = "vector::insert length error\n";
DEFINE_VECTOR_INSERT_FILL_V2(Vector_Insert_21C330, E_0021C330, 0x600000, D_004A4650, D_004A49E8, 0x5C, func_0021C7E0, extern char D_004A49F8[];, VIF2_FREE(E_0021C330, D_004A49F8, 0x64), VIF2_COPY, VIF2_COPY)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021C330(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021C330 */
