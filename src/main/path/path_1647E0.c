/*
 * main/path: range (2 files, 001647E0-00164850)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "guarded_buffer_dtor.h"
#pragma pop

/* merge_units: begin func_001647E0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct E_47E0 { int a[8]; };
struct V_47E0 {
    int cap; unsigned int count; E_47E0* data;
    unsigned int size() const { return count; }
    E_47E0* begin() { return data; }
    E_47E0* end() { return data + count; }
};
extern "C" void Vector_Insert_164CA0(V_47E0* v, E_47E0* pos, unsigned int n, void* val);
extern "C" void func_00164BD0(V_47E0* v, E_47E0* first, E_47E0* last);
extern "C" void func_001647E0(V_47E0* v, unsigned int n, void* val)
{
    if (v->size() < n)
        Vector_Insert_164CA0(v, v->end(), n - v->size(), val);
    else if (n < v->size())
        func_00164BD0(v, v->begin() + n, v->end());
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001647E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001647E0 */

/* merge_units: begin func_00164850 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
char D_0049C240[] = "allocator.hh";
}
DEFINE_GUARDED_BUFFER_CALL_DTOR(func_00164850, func_001651F0, D_0049C240)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00164850(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00164850 */
