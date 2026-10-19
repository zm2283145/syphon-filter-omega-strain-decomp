/*
 * main/gameobj: range (2 files, 00395EB0-00396000)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "tstr_types.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "vector_destroy_dtor.h"
#pragma pop

/* merge_units: begin func_00395EB0 */
#pragma push /* merge_units */
#pragma cplusplus on

struct SkelNode395EB0 { char p[0x1D0]; };
struct V395EB0 { unsigned int cap; unsigned int count; SkelNode395EB0* data; };
extern "C" {
extern char D_004BC460[];
extern char D_004BC510[];
void SkelNode_Assign(SkelNode395EB0* d, const SkelNode395EB0* s);
}

extern "C" void func_00395EB0(V395EB0* v, unsigned int n, const SkelNode395EB0* val)
{
    if (n) {
        if (n > 0x34F72) {
            func_00123BE8(D_00489738->stream, D_004BC460);
            Libc_Abort();
        }
        SkelNode395EB0** pd = &v->data;
        *pd = (SkelNode395EB0*)TStr_Alloc(n * sizeof(SkelNode395EB0), D_004BC510, 0x5C);
        v->cap = n;
        SkelNode395EB0* p = v->data;
        SkelNode395EB0* e = p + n;
        for (; p < e; p++) {
            if (p) SkelNode_Assign(p, val);
            v->count++;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00395EB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00395EB0 */

/* merge_units: begin func_00396000 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a vector: destroy elements, free the buffer, optionally delete. */
extern "C" {
char D_004BC500[] = "allocator.hh";
}
DEFINE_VECTOR_DESTROY_DTOR_FILE(func_00396000, func_00396B70, D_004BC500)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00396000(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00396000 */
