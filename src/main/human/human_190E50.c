/*
 * main/human: range (2 files, 00190E50-00190E60)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "float_to_int.h"

/* merge_units: begin func_00190E50 */
#pragma push /* merge_units */
/* Convert a float to int. */
DEFINE_FLOAT_TO_INT(func_00190E50)
#pragma pop /* merge_units */
/* merge_units: end func_00190E50 */

/* merge_units: begin func_00190E60 */
#pragma push /* merge_units */
typedef struct { unsigned int kind; char pad[0x2C]; char a[0x10]; char b[0x30]; char c[1]; } O_190E60;
void* func_00190E60(O_190E60* o)
{
    if (o->kind >= 3) return o->c;
    if (o->kind == 2) return o->b;
    return o->a;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00190E60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00190E60 */
