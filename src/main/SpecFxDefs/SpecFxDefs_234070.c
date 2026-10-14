/*
 * main/SpecFxDefs: range (3 files, 00234070-002340C0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "SpecFxDefs_types.h"

/* merge_units: begin func_00234070 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Container iterator helpers.
 */


Word* func_00234070(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

Word* func_00234080(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00234070(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00234070 */

/* merge_units: begin func_00234090 */
#pragma push /* merge_units */
typedef struct { void* p; } Iter4;
typedef struct { int unk0; int data[1]; } Seq;

/* Writes an iterator pointing at the sequence's data at +4 to *out. */
void func_00234090(Iter4* out, Seq* s)
{
    Iter4 it;
    Iter4 tmp;
    tmp.p = s->data;
    it = tmp;
    out->p = it.p;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00234090(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00234090 */

/* merge_units: begin func_002340C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * List push_back helper and iterator assignment.
 */


extern SpecListPos* List_InsertBefore(SpecListPos* result, void* list, SpecListPos* pos, int* value);

/* push_back on a list whose sentinel node is at +4. */
SpecListPos* func_002340C0(void* list, int* value) {
    SpecListPos end;
    SpecListPos result;

    end.node = (char*)list + 4;
    return List_InsertBefore(&result, list, &end, value);
}

/* Assigns value to *dst; volatile mirrors the original stack temporary. */
int* func_002340F0(int* dst, int value) {
    volatile int tmp = value;

    *dst = tmp;
    return dst;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002340C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002340C0 */
