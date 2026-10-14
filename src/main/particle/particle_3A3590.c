/*
 * main/particle: range (2 files, 003A3590-003A35C0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "iter_return_copy.h"

/* merge_units: begin func_003A3590 */
#pragma push /* merge_units */
/* Return the begin iterator. */
DEFINE_ITER_BEGIN(func_003A3590)
#pragma pop /* merge_units */
/* merge_units: end func_003A3590 */

/* merge_units: begin func_003A35C0 */
#pragma push /* merge_units */
#pragma opt_propagation off

/* Look up a resource by its lower-cased short name (up to 16 chars, stops at '.'). */
typedef struct { __int128 q; } Name_3A35C0;
extern Name_3A35C0 D_0053BAB0;
extern char String_ToLower(char c);
extern void func_003A3430(void* self, char* name);

void func_003A35C0(void* self, const char* s)
{
    Name_3A35C0* name = &D_0053BAB0;
    unsigned int i;
    char* o;
    int c;
    name->q = 0;
    for (i = 0, o = (char*)name; i < 16 && (c = s[i]) != 0 && c != '.'; i++)
        *o++ = String_ToLower(c);
    func_003A3430(self, (char*)name);
}
#pragma opt_propagation reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003A35C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003A35C0 */
