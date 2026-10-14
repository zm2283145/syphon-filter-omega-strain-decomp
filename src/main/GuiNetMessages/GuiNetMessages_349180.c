/*
 * main/GuiNetMessages: range (3 files, 00349180-003491C0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int strcmp(const void *, const void *);
int strlen(const char *);

/* merge_units: begin func_00349180 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiNetMessages.cc. Functions are named by address
 * until real names are known.
 */



int func_00349180(void) {
    return (int)"GuiNetMessageArray";
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00349180(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00349180 */

/* merge_units: begin func_00349190 */
#pragma push /* merge_units */
char D_004BA520[] = "GuiNetMessageArray"; /* "GuiNetMessageArray" */

/* GuiNetMessageArray::IsA: returns 1 if the given class name is "GuiNetMessageArray". */
int GuiNetMessageArray_IsType(void* self, const char* name)
{
    return strcmp(D_004BA520, name) == 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00349190(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00349190 */

/* merge_units: begin func_003491C0 */
#pragma push /* merge_units */
typedef struct { char unused; } Alloc003491C0; /* empty allocator object passed by value */
typedef struct { int w0, w4, w8; } Str003491C0;
extern void String_Reserve(Str003491C0* str, int n);
extern void String_Replace(Str003491C0* str, int pos, int count, const char* first, const char* last, Alloc003491C0 alloc);
/* Construct a string from a C string. */
Str003491C0* func_003491C0(Str003491C0* str, const char* s)
{
    Alloc003491C0 alloc;
    int n;
    str->w0 = 0;
    str->w4 = 0;
    str->w8 = 0;
    n = strlen(s);
    String_Reserve(str, n);
    String_Replace(str, 0, 0, s, s + n, alloc);
    return str;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003491C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003491C0 */
