/*
 * main/guiTextListWidget: range (2 files, 004211C0-00421210)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_004211C0 */
#pragma push /* merge_units */
typedef struct { char* begin; char* end; char* cap; } String;
typedef struct { String name; int unkC; int unk10; } NamedEntry;
typedef struct { int unk0; int count; NamedEntry* data; } EntryVec;

extern void String_Dtor(String* s, int flags);

static inline void NamedEntry_dtor(NamedEntry* e)
{
    if (e)
        String_Dtor(&e->name, 0);
}

/* Removes the last entry of the vector and destroys it. */
void cArray_Item_PopBack(EntryVec* self)
{
    NamedEntry* last = &self->data[--self->count];
    if (last)
        NamedEntry_dtor(last);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004211C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004211C0 */

/* merge_units: begin func_00421210 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: guiTextListWidget.cc. Functions are named by address
 * until real names are known.
 */

#include "guiTextListWidget_types.h"

extern void* std_basic_string_char_char_traits_char_assign_basicstringR(void* dst, void* src);

/* TextListEntry copy constructor. */
TextListEntry* GuiTextListWidget_Item_opAssign(TextListEntry* self, TextListEntry* src) {
    std_basic_string_char_char_traits_char_assign_basicstringR(self, src);
    self->unk0C = src->unk0C;
    self->unk10 = src->unk10;
    return self;
}

TextListEntry* std_vector_Item_opIndex(TextListEntryVec* v, int i) {
    return v->data + i;
}

int cArray_Item_Size(char* self) {
    return *(int*)(self + 4);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00421210(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00421210 */
