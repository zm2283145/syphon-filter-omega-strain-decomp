/*
 * main/interface_manager: range (2 files, 00413800-00413850)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "interface_manager_types.h"

/* merge_units: begin func_00413800 */
#pragma push /* merge_units */
typedef struct { char* begin; char* end; char* cap; } String;
typedef struct { int unk0; int count; String* data; } StringVec;

extern void String_Dtor(String* s, int flags);

/* Removes the last string of the vector and destroys it. */
void StringVec_PopBack(StringVec* self)
{
    String* last = &self->data[--self->count];
    if (last)
        String_Dtor(last, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00413800(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00413800 */

/* merge_units: begin func_00413850 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * interface_manager.cc
 */


/* Address of record `index`. */
IfRec12* func_00413850(IfRecVec* v, int index) {
    return v->data + index;
}

/* Number of records. */
int func_00413870(IfRecVec* v) {
    return v->count;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00413850(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00413850 */
