/*
 * main/guiTextListWidget: range (4 files, 00421430-004215E0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int strcmp(const void *, const void *);

/* merge_units: begin func_00421430 */
#pragma push /* merge_units */
#include "guiTextListWidget_types.h"

extern char* String_CStr(const void* text);

/* Return the selected entry's string data, or null for an invalid index. */
char* func_00421430(TextListWidget* self, int index) {
    if (index < 0 || index >= self->entries.count) {
        return 0;
    }
    return String_CStr(&self->entries.data[index]);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00421430(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00421430 */

/* merge_units: begin func_00421480 */
#pragma push /* merge_units */
static inline TextListEntry* entry_at(TextListWidget* self, int index)
{
    return &self->entries.data[index];
}

/* Return the entry's value, or -1 when the index is outside the list. */
int func_00421480(TextListWidget* self, int index)
{
    if (index < 0 || index >= self->entries.count)
        return -1;
    return entry_at(self, index)->unk0C;
}

/* Change the signed byte only for an existing list entry. */
void func_004214C0(TextListWidget* self, int index, signed char value)
{
    if (index < 0 || index >= self->entries.count)
        return;
    entry_at(self, index)->unk10 = value;
}

/* Preserve the distinct 255 sentinel for invalid indices. */
int func_00421500(TextListWidget* self, int index)
{
    if (index < 0 || index >= self->entries.count)
        return 255;
    return entry_at(self, index)->unk10;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00421480(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00421480 */

/* merge_units: begin func_00421540 */
#pragma push /* merge_units */
typedef struct { char d[20]; } E421540;
typedef struct { char p[0x94]; int count; E421540* items; } O421540;
#if 0 /* merge_units */
extern char* String_CStr(E421540* e);
#endif /* merge_units */
#define String_CStr(a0) (String_CStr((void *)(a0))) /* merge_units */

#pragma opt_strength_reduction off
int func_00421540(O421540* o, const char* name)
{
    int i;
    for (i = 0; i < o->count; i++) {
        if (strcmp(name, String_CStr(&o->items[i])) == 0) {
            return i;
        }
    }
    return -1;
}
#undef String_CStr /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00421540(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00421540 */

/* merge_units: begin func_004215E0 */
#pragma push /* merge_units */
typedef struct { char p[0xC]; int id; char p10[4]; } E4215E0;
typedef struct { char p[0x94]; int count; E4215E0* items; } L4215E0;
#pragma push
#pragma opt_common_subs off
int func_004215E0(L4215E0* l, int id)
{
    int i;
    for (i = 0; i < l->count; i++) if (((E4215E0*)((char*)l->items + i * sizeof(E4215E0)))->id == id) return i;
    return -1;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004215E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004215E0 */
