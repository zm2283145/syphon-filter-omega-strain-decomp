/*
 * main/GuiEquipmentModify: 2 files, 002C4400-002C44B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002C4400 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "guarded_new.h"

/* Factory: allocate a 0x960-byte object and construct it. */
extern "C" { char D_004AC6D8[] = "guiWidget.hh"; }
DEFINE_GUARDED_NEW_CTOR(GuiEquipmentModify_Create, 0x960, D_004AC6D8, GuiEquipmentModify_ctor)
#pragma pop /* merge_units */
/* merge_units: end func_002C4400 */

/* merge_units: begin func_002C44B0 */
#pragma push /* merge_units */
typedef struct { int words[3]; } SsoString;
typedef struct { char unused; } Allocator; /* empty allocator object passed by value */
extern int strlen(const char* s); /* strlen */
extern void String_Reserve(SsoString* s, int capacity);
extern void* String_Replace(SsoString* s, int pos, int count, const char* first, const char* last, Allocator alloc);

/* String constructor from a C string. */
SsoString* func_002C44B0(SsoString* self, const char* text)
{
    Allocator alloc;
    int len;
    self->words[0] = 0;
    self->words[1] = 0;
    self->words[2] = 0;
    len = strlen(text);
    String_Reserve(self, len);
    String_Replace(self, 0, 0, text, text + len, alloc);
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_002C44B0 */
