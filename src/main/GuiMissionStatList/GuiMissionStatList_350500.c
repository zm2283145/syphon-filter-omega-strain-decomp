/*
 * main/GuiMissionStatList: 4 files, 00350500-003505A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00350500 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(func_00350500, D_004DEEE0, func_00426940)
#pragma pop /* merge_units */
/* merge_units: end func_00350500 */

/* merge_units: begin func_00350560 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GuiMissionStatList class-name getter (vtable D_004DEEE0 slot 19).
 */

#include "loose03_types.h"

char D_004BAD40[] = "GuiMissionStatList";       /* "GuiMissionStatList" */

/* Returns the class name string "GuiMissionStatList". */
const char* GuiMissionStatList_GetClassName(void) {
    return D_004BAD40;
}
#pragma pop /* merge_units */
/* merge_units: end func_00350560 */

/* merge_units: begin func_00350570 */
#pragma push /* merge_units */
extern int strcmp(void* obj);
/* True when strcmp returns 0 for the global object "GuiMissionStatList". */
int func_00350570(void)
{
    return strcmp("GuiMissionStatList") == 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00350570 */

/* merge_units: begin func_003505A0 */
#pragma push /* merge_units */
typedef struct String3 {
    char* begin;
    char* end;
    char* cap;
} String3;

extern int strlen(const char* s); /* strlen */
extern void String_Reserve(String3* str, int len);
extern void String_Replace(String3* str, int a, int b, const char* first, const char* last, signed char tag);

/* String constructor from a C string. */
String3* func_003505A0(String3* str, const char* s) {
    volatile signed char tag[4]; /* empty tag argument, never initialized */
    int len;
    str->begin = 0;
    str->end = 0;
    str->cap = 0;
    len = strlen(s);
    String_Reserve(str, len);
    String_Replace(str, 0, 0, s, s + len, tag[0]);
    return str;
}
#pragma pop /* merge_units */
/* merge_units: end func_003505A0 */
