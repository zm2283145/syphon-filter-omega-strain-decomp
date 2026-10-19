/*
 * main/guiTextListWidget: 6 files, 004213E0-00421650
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004213E0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

struct Widget {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void Method5C(int a, int b); /* +0x5C */
    char pad04[0x94 - 4];
    int unk94; /* +0x94 */
};

extern "C" void GuiArrayWidget_Select(Widget* self, int a, int b);

/* Calls virtual +0x5C(1, +0x94) then GuiArrayWidget_Select(self, 0, 0). */
extern "C" void GuiTextListWidget_Refresh(Widget* self)
{
    self->Method5C(1, self->unk94);
    GuiArrayWidget_Select(self, 0, 0);
}
#pragma pop /* merge_units */
/* merge_units: end func_004213E0 */

/* merge_units: begin func_00421430 */
#pragma push /* merge_units */
#include "guiTextListWidget_types.h"

extern char* String_CStr(const void* text);

/* Return the selected entry's string data, or null for an invalid index. */
char* GuiTextListWidget_GetItemText(TextListWidget* self, int index) {
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
int GuiTextListWidget_GetItemId(TextListWidget* self, int index)
{
    if (index < 0 || index >= self->entries.count)
        return -1;
    return entry_at(self, index)->unk0C;
}

/* Change the signed byte only for an existing list entry. */
void GuiTextListWidget_SetStyle(TextListWidget* self, int index, signed char value)
{
    if (index < 0 || index >= self->entries.count)
        return;
    entry_at(self, index)->unk10 = value;
}

/* Preserve the distinct 255 sentinel for invalid indices. */
int GuiTextListWidget_GetStyle(TextListWidget* self, int index)
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
#define String_CStr(a0) (String_CStr((const void *)(a0))) /* merge_units */


#pragma opt_strength_reduction off
int GuiTextListWidget_FindByText(O421540* o, const char* name)
{
    int i;
    for (i = 0; i < o->count; i++) {
        if (strcmp(name, String_CStr(&o->items[i])) == 0) {
            return i;
        }
    }
    return -1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00421540(void) {}
#undef String_CStr /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00421540 */

/* merge_units: begin func_004215E0 */
#pragma push /* merge_units */
typedef struct { char p[0xC]; int id; char p10[4]; } E4215E0;
typedef struct { char p[0x94]; int count; E4215E0* items; } L4215E0;
#pragma push
#pragma opt_common_subs off
int GuiTextListWidget_FindById(L4215E0* l, int id)
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

/* merge_units: begin func_00421650 */
#pragma push /* merge_units */
typedef struct Child5B {
    char pad00[0x5B];
    unsigned char state; /* 0x5B */
} Child5B;

typedef struct Parent421650 {
    char pad00[0xA0];
    Child5B* child;      /* 0xA0 */
    char padA4[0x4D];
    unsigned char state; /* 0xF1 */
} Parent421650;

/* Sets the state byte and mirrors it into the child, if any. */
void GuiTextListWidget_SetF1(Parent421650* obj, unsigned char state) {
    obj->state = state;
    if (obj->child) {
        obj->child->state = obj->state;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00421650 */
