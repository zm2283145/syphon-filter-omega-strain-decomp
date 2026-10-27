/*
 * Libs/SFOLib/Source/text: 1 file, 003D0E40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin gobj_3D0E40 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { int words[3]; } String;
typedef struct { float x, y, z, w; } Vec4f;
typedef struct { String name; int id; Vec4f v; float a; float b; int extra[4]; } Entry;
typedef struct { int unk0; int list; int head; } Obj;
extern void std_basic_string_char_char_traits_char_ctor_charP(String* s, const char* text);
extern void std_list_deleter_cText_insert(void* result, void* list, int* where, Entry* entry);
extern void String_Dtor(String* s, int flags);

/* Appends a named entry (id, vector, two floats) to the object's list. */
void cTextSystem_Print_charP_cFontR_tRGBAR_float_etc(Obj* self, const char* name, int id, Vec4f* v, float a, float b)
{
    int where;
    int result;
    Entry entry;
    std_basic_string_char_char_traits_char_ctor_charP(&entry.name, name);
    entry.id = id;
    entry.v.x = v->x;
    entry.v.y = v->y;
    entry.v.z = v->z;
    entry.v.w = v->w;
    entry.a = a;
    entry.b = b;
    where = (int)&self->head;
    std_list_deleter_cText_insert(&result, &self->list, &where, &entry);
    String_Dtor(&entry.name, 0);
}
static inline void merge_flush_gobj_3D0E40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end gobj_3D0E40 */
