/*
 * main/GuiKeyboard: 2 files, 003299D0-00329A70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003299D0 */
#pragma push /* merge_units */
typedef struct { int a, b, c; } S29930;
typedef struct { S29930 s0; int c; S29930 s1; unsigned char d; int e, f, g; } E2C;
extern void func_00329930(S29930* dst, S29930* src);E2C* func_003299D0(E2C* first, E2C* last, E2C* result)
{
    while (first < last) {
        --last;
        --result;
        func_00329930(&result->s0, &last->s0);
        result->c = last->c;
        func_00329930(&result->s1, &last->s1);
        result->d = last->d;
        result->e = last->e;
        result->f = last->f;
        result->g = last->g;
    }
    return result;
}
#pragma pop /* merge_units */
/* merge_units: end func_003299D0 */

/* merge_units: begin func_00329A70 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "vector_insert_fill_obj.h"

extern "C" { char D_004B88B0[] = "allocator.hh"; }
DEFINE_VECTOR_INSERT_FILL_OBJ(func_00329A70, 0x20, 0x300000, 0x180000, D_004B8810, D_004B88B0, 0x5C, func_00139BC0, func_0032A050, func_00329FD0, func_00329EF0, func_00329EB0, func_0032A2F0)
#pragma pop /* merge_units */
/* merge_units: end func_00329A70 */
