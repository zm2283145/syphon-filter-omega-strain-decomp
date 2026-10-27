/*
 * main/GuiFrontendCanvas: 3 files, 00465E90-00465F20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00465E90 */
#pragma push /* merge_units */
#include "types.h"

/* strcmp */
extern int strcmp(const char* a, const char* b);
/* "GuiFrontendCanvas" */

/* GuiFrontendCanvas type check: true when name equals the class name "GuiFrontendCanvas". */
int GuiFrontendCanvas_IsClass(void* self, const char* name) {
    return strcmp("GuiFrontendCanvas", name) == 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00465E90 */

/* merge_units: begin func_00465EC0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(GuiCommonCanvas_dtor, D_004E1A20, GuiCanvas_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00465EC0 */

/* merge_units: begin func_00465F20 */
#pragma push /* merge_units */
typedef struct { char tag; } Alloc;
typedef struct { char* begin; char* end; char* cap; } String;

extern int strlen(const char* s); /* strlen */
extern void std_basic_string_char_char_traits_char_reserve(String* self, int n);
extern void std_basic_string_char_char_traits_char_do_replace(String* self, char* at, int unused, const char* first, const char* last, Alloc alloc);

/* Constructs a string from a C string; returns self. */
String* String_CtorCStr_465F20(String* self, const char* s)
{
    int len;
    Alloc alloc;
    self->begin = 0;
    self->end = 0;
    self->cap = 0;
    len = strlen(s);
    std_basic_string_char_char_traits_char_reserve(self, len);
    std_basic_string_char_char_traits_char_do_replace(self, 0, 0, s, s + len, alloc);
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00465F20 */
