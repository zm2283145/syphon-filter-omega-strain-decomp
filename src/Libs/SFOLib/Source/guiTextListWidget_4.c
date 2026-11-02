/*
 * Libs/SFOLib/Source/guiTextListWidget: 14 files, 00421290-00421F10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00421290 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "guiTextListWidget_types.h"
#include "guiTextWidget_types.h"

extern "C" {
void cString_ctor_void(void* string);
GuiStreamString* std_basic_string_char_char_traits_char_ctor_charP(GuiStreamString* string, const char* text);
void std_basic_string_char_char_traits_char_assign_basicstringR(void* destination, const void* source);
void String_Dtor(void* string, int flags);
void std_vector_imp_Item_insert(TextListEntryVec* entries, TextListEntry* position,
                   int count, const TextListEntry* value);
#if 0 /* merge_units */
void GuiArrayWidget_SetSelected(TextRenderWidget* self, int first, int second);
#endif /* merge_units */
void GuiArrayWidget_SetSelected(void*, int, int); /* merge_units */
#define GuiArrayWidget_SetSelected(a0, a1, a2) (GuiArrayWidget_SetSelected((void *)(a0), (a1), (a2))) /* merge_units */

void operator_delete(void* allocation);
}

/* Append an owned text entry and notify the list of its new row count. */
extern "C" int GuiTextListWidget_AddItem(TextRenderWidget* self, const char* text,
                            int value, signed char style)
{
    if (!text)
        return 0;
    GuiStreamString temporary;
    TextListEntry entry;
    cString_ctor_void(entry.text);
    std_basic_string_char_char_traits_char_ctor_charP(&temporary, text);
    std_basic_string_char_char_traits_char_assign_basicstringR(entry.text, &temporary);
    String_Dtor(&temporary, 0);
    entry.unk0C = value;
    entry.unk10 = style;
    std_vector_imp_Item_insert(&self->entries, self->entries.data + self->entries.count, 1, &entry);
    ((TextListLayout*)self)->set_extent(1, self->entries.count);
    GuiArrayWidget_SetSelected(self, 0, 0);
    String_Dtor(entry.text, 0);
    return 1;
}

static inline void destroy_entry(TextListEntry* entry)
{
    if (entry)
        String_Dtor(entry->text, 0);
}

/* Destroy an entry's string before optionally freeing the entry itself. */
extern "C" TextListEntry* GuiTextListWidget_Item_dtor(TextListEntry* self, short deleteFlag)
{
    if (self) {
        destroy_entry(self);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
#undef GuiArrayWidget_SetSelected /* merge_units */
static inline void merge_flush_func_00421290(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00421290 */

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

#if 0 /* merge_units */
extern "C" void GuiArrayWidget_SetSelected(Widget* self, int a, int b);
#endif /* merge_units */
#define GuiArrayWidget_SetSelected(a0, a1, a2) (GuiArrayWidget_SetSelected((void *)(a0), (a1), (a2))) /* merge_units */



/* Calls virtual +0x5C(1, +0x94) then GuiArrayWidget_SetSelected(self, 0, 0). */
extern "C" void GuiTextListWidget_UpdateSize(Widget* self)
{
    self->Method5C(1, self->unk94);
    GuiArrayWidget_SetSelected(self, 0, 0);
}
#undef GuiArrayWidget_SetSelected /* merge_units */
static inline void merge_flush_func_004213E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004213E0 */

/* merge_units: begin func_00421430 */
#pragma push /* merge_units */
extern char* std_basic_string_char_char_traits_char_c_str(const void* text);

/* Return the selected entry's string data, or null for an invalid index. */
char* GuiTextListWidget_GetItemText(TextListWidget* self, int index) {
    if (index < 0 || index >= self->entries.count) {
        return 0;
    }
    return std_basic_string_char_char_traits_char_c_str(&self->entries.data[index]);
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
void GuiTextListWidget_SetItemState(TextListWidget* self, int index, signed char value)
{
    if (index < 0 || index >= self->entries.count)
        return;
    entry_at(self, index)->unk10 = value;
}

/* Preserve the distinct 255 sentinel for invalid indices. */
int GuiTextListWidget_GetItemState(TextListWidget* self, int index)
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
extern char* std_basic_string_char_char_traits_char_c_str(E421540* e);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_c_str(a0) (std_basic_string_char_char_traits_char_c_str((const void *)(a0))) /* merge_units */





#pragma opt_strength_reduction off
int GuiTextListWidget_FindItem_charP(O421540* o, const char* name)
{
    int i;
    for (i = 0; i < o->count; i++) {
        if (strcmp(name, std_basic_string_char_char_traits_char_c_str(&o->items[i])) == 0) {
            return i;
        }
    }
    return -1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00421540(void) {}
#undef std_basic_string_char_char_traits_char_c_str /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00421540 */

/* merge_units: begin func_004215E0 */
#pragma push /* merge_units */
typedef struct { char p[0xC]; int id; char p10[4]; } E4215E0;
typedef struct { char p[0x94]; int count; E4215E0* items; } L4215E0;
#pragma push
#pragma opt_common_subs off
int GuiTextListWidget_FindItem_int(L4215E0* l, int id)
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
static inline void merge_flush_func_00421650(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00421650 */

/* merge_units: begin func_00421670 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#pragma pop
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

/* Copy the state byte to the optional child widget. */
void GuiTextListWidget_SetTextFormat(TextListWidget* self, unsigned char state)
{
    self->state = state;
    if (self->child)
        self->child->state = state;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00421670(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00421670 */

/* merge_units: begin func_00421690 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
extern char D_0049AF00[];
extern char D_004E0C80[];
extern char D_004E0D20[];
void* Gui_Manager(void);
void* GuiManager_GetFont(void* manager, const char* name);
unsigned int cFont_GetCharH(void* resource);
void GuiArrayWidget_SetRowHeight(TextRenderWidget* self, unsigned int height);
void GuiArrayWidget_onSleep(TextRenderWidget* self);
void GuiArrayWidget_onWake(TextRenderWidget* self);
void GuiArrayWidget_onAdd(TextRenderWidget* self);
void* cMemMan_Allocate(int pool, unsigned int size, char* file, int line);
TextRenderChild* cTextArea_ctor(TextRenderChild* self, int x, int y,
                             int width, int height, void* resource,
                             TextRenderStyle* style);
#if 0 /* merge_units */
void std_vector_deleter_Item_dtor(TextListEntryVec* entries, int flags);
#endif /* merge_units */
void* std_vector_deleter_Item_dtor(void* self, short deleteFlag); /* merge_units */
#define std_vector_deleter_Item_dtor(a0, a1) ((void)std_vector_deleter_Item_dtor((void *)(a0), (short)(a1))) /* merge_units */

void cArray_int_dtor(void* state, int flags);
void GuiWidget_dtor(TextRenderWidget* self, int flags);
void std_vector_imp_int_1_dtor(TextListEntryVec* entries, int flags);
}

static inline void destroy_string(void* string)
{
    if (string)
        String_Dtor(string, 0);
}

static inline void destroy_child(TextRenderChild* child)
{
    if (child)
        destroy_string(child->text);
}

static inline void release_child(TextRenderChild* child, int line)
{
    AllocGuard guard;
    destroy_child(child);
    cMemMan_Deallocate(0, child, "guiTextListWidget.cc", line);
}

static inline void destroy_entry_storage(TextListEntryVec* entries)
{
    if (entries)
        std_vector_deleter_Item_dtor(entries, 0);
}

static inline void destroy_entry_base(TextListEntryVec* entries)
{
    if (entries)
        destroy_entry_storage(entries);
}

static inline void destroy_entries(TextListEntryVec* entries)
{
    if (entries)
        destroy_entry_base(entries);
}

static inline void destroy_widget_base(TextRenderWidget* self)
{
    if (self) {
        self->vtable = D_004E0D20;
        cArray_int_dtor(self->baseState, -1);
        GuiWidget_dtor(self, 0);
    }
}

/* Resolve the named text resource and apply its padded row height when available. */
extern "C" void GuiTextListWidget_SetFont(TextRenderWidget* self, const char* name)
{
    self->resource = GuiManager_GetFont(Gui_Manager(), name);
    if (self->resource)
        GuiArrayWidget_SetRowHeight(self, cFont_GetCharH(self->resource) + 4);
}

/* Release the optional text child after the base widget is deactivated. */
extern "C" void GuiTextListWidget_onSleep(TextRenderWidget* self)
{
    GuiArrayWidget_onSleep(self);
    TextRenderChild* child = self->child;
    if (child) {
        release_child(child, 0x45);
        self->child = 0;
    }
}

/* Lazily construct the text child and synchronize its active state. */
extern "C" void GuiTextListWidget_onWake(TextRenderWidget* self)
{
    GuiArrayWidget_onWake(self);
    if (!self->child) {
        TextRenderChild* child;
        {
            AllocGuard guard;
            child = (TextRenderChild*)cMemMan_Allocate(0, sizeof(TextRenderChild),
                                              "guiTextListWidget.cc", 0x37);
        }
        if (child)
            child = cTextArea_ctor(child, 0, 0, (int)self->width, (int)self->height,
                                 self->resource, &self->styles[0]);
        self->child = child;
    }
    self->child->enabled = 1;
    self->child->active = 1;
    self->child->mode = self->mode;
    self->child->state = self->state;
}

/* Restore the default resource after the base widget reset. */
extern "C" void GuiTextListWidget_onAdd(TextRenderWidget* self)
{
    GuiArrayWidget_onAdd(self);
    self->resource = GuiManager_GetFont(Gui_Manager(), 0);
    if (self->resource)
        GuiArrayWidget_SetRowHeight(self, cFont_GetCharH(self->resource) + 4);
}

/* Destroy the owned text child, entries and base widget before optional deletion. */
extern "C" TextRenderWidget* GuiTextListWidget_dtor(TextRenderWidget* self, short deleteFlag)
{
    if (self) {
        self->vtable = D_004E0C80;
        TextRenderChild* child = self->child;
        if (child)
            release_child(child, 0x27);
        destroy_entries(&self->entries);
        destroy_widget_base(self);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}

static inline void destroy_vector_base(TextListEntryVec* entries)
{
    if (entries)
        std_vector_imp_int_1_dtor(entries, 0);
}

/* Destroy the vector base before optionally releasing the vector itself. */
extern "C" TextListEntryVec* func_00421AA0(TextListEntryVec* self, short deleteFlag)
{
    if (self) {
        destroy_vector_base(self);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}

/* Keep the allocator guard inlined through the vector's cleanup layers. */
#pragma inline_depth(8)

static inline void free_entry_buffer(TextListEntry* data)
{
    if (data) {
        AllocGuard guard;
        cMemMan_Deallocate(0, data, D_0049AF00, 0x64);
    }
}

static inline void release_entry_buffer(TextListEntryVec* entries)
{
    if (entries) {
        TextListEntry* data = entries->data;
        if (data)
            free_entry_buffer(data);
    }
}

/* Release allocated entry storage before optional vector deletion. */
extern "C" TextListEntryVec* func_00421B00(TextListEntryVec* self, short deleteFlag)
{
    if (self) {
        release_entry_buffer(self);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00421690(void) {}
#undef std_vector_deleter_Item_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00421690 */

/* merge_units: begin func_00421BF0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

/* Virtual-call view of WidgetV: only the slots used here are named (vtable offset in comments). */
struct WidgetV {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void Method5C(int a, int b); /* +0x5C */
};

typedef struct Anim { char pad[0xC]; unsigned char enabled; /* +0xC */ } Anim;

typedef struct Widget_00421BF0 {
    void* vtable;           /* +0x00 */
    char pad04[0x14 - 4];
    unsigned short flags;   /* +0x14 */
    char pad16[0x58 - 0x16];
    unsigned char mode;     /* +0x58 */
    char pad59[0x90 - 0x59];
    Anim anim;              /* +0x90 */
    char pad9D[0xA0 - 0x9D];
    int unkA0;              /* +0xA0 */
    unsigned char flagA4;   /* +0xA4 */
    char padA5[3];
    int unkA8;              /* +0xA8 */
    int padAC;
    float scale[4];         /* +0xB0 */
    float offset[4];        /* +0xC0 */
    float tint[4];          /* +0xD0 */
    float color[4];         /* +0xE0 */
    unsigned char flagF0;   /* +0xF0 */
    unsigned char flagF1;   /* +0xF1 */
} Widget_00421BF0;
extern "C" void GuiArrayWidget_ctor(Widget_00421BF0* self);
#if 0 /* merge_units */
extern "C" void std_vector_Item_ctor(Anim* anim);
#endif /* merge_units */
extern "C" Rel* std_vector_Item_ctor(Rel* r); /* merge_units */
#define std_vector_Item_ctor(a0) ((void)std_vector_Item_ctor((Rel *)(a0))) /* merge_units */


/* Constructor: base init, vtable D_004E0C80, animation sub-object, default mode 2 and colour/scale defaults. */
extern "C" Widget_00421BF0* GuiTextListWidget_ctor(Widget_00421BF0* self)
{
    Anim* anim;
    GuiArrayWidget_ctor(self);
    self->vtable = D_004E0C80;
    anim = &self->anim;
    std_vector_Item_ctor(anim);
    anim->enabled = 1;
    self->flags |= 0x80;
    self->mode = 2;
    ((WidgetV*)self)->Method5C(1, 0);
    self->unkA0 = 0;
    self->unkA8 = 0;
    self->flagF1 = 0;
    self->flagA4 = 0;
    self->scale[0] = 1.0f;
    self->scale[1] = 1.0f;
    self->scale[2] = 1.0f;
    self->scale[3] = 1.0f;
    self->offset[0] = 0.0f;
    self->offset[1] = 1.0f;
    self->offset[2] = 0.0f;
    self->offset[3] = 1.0f;
    self->tint[0] = 0.6f;
    self->tint[1] = 0.6f;
    self->tint[2] = 0.6f;
    self->tint[3] = 1.0f;
    self->color[0] = 1.0f;
    self->color[1] = 1.0f;
    self->color[2] = 1.0f;
    self->color[3] = 1.0f;
    self->flagF0 = 0;
    return self;
}
#undef std_vector_Item_ctor /* merge_units */
static inline void merge_flush_func_00421BF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00421BF0 */

/* merge_units: begin func_00421CD0 */
#pragma push /* merge_units */
#pragma cplusplus on
/* Preserve allocator-guard inlining through the nested vector cleanup. */
#pragma inline_depth(8)

extern "C" {
#if 0 /* merge_units */
void std_vector_deleter_Item_dtor(TextListEntryVec* entries, int flags);
#endif /* merge_units */
#define std_vector_deleter_Item_dtor(a0, a1) ((void)std_vector_deleter_Item_dtor((void *)(a0), (short)(a1))) /* merge_units */

void func_0013A040(void* state, int flags);
#if 0 /* merge_units */
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
#endif /* merge_units */

}

static inline void destroy_storage(TextListEntryVec* entries)
{
    if (entries)
        std_vector_deleter_Item_dtor(entries, 0);
}

static inline void destroy_vector(TextListEntryVec* entries)
{
    if (entries)
        destroy_storage(entries);
}

/* Destroy both vector layers before optional object deletion. */
extern "C" TextListEntryVec* cArray_Item_dtor(TextListEntryVec* self, short deleteFlag)
{
    if (self) {
        destroy_vector(self);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}

/* Destroy vector storage before optional object deletion. */
extern "C" TextListEntryVec* std_vector_Item_dtor(TextListEntryVec* self, short deleteFlag)
{
    if (self) {
        destroy_storage(self);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}

static inline void destroy_state(void* state)
{
    if (state)
        func_0013A040(state, -1);
}

/* Restore the base vtable and destroy layout state before the widget base. */
extern "C" TextRenderWidget* GuiArrayWidget_dtor_421DA0(TextRenderWidget* self, short deleteFlag)
{
    if (self) {
        self->vtable = D_004E0D20;
        destroy_state(self->baseState);
        GuiWidget_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}

static inline void free_buffer(TextListEntry* data)
{
    if (data) {
        AllocGuard guard;
        cMemMan_Deallocate(0, data, D_0049AF00, 0x64);
    }
}

static inline void release_buffer(TextListEntryVec* entries)
{
    if (entries) {
        TextListEntry* data = entries->data;
        if (data)
            free_buffer(data);
    }
}

static inline void release_base(TextListEntryVec* entries)
{
    if (entries)
        release_buffer(entries);
}

/* Release the entry buffer through both base layers before optional deletion. */
extern "C" TextListEntryVec* func_00421E20(TextListEntryVec* self, short deleteFlag)
{
    if (self) {
        release_base(self);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
#undef std_vector_deleter_Item_dtor /* merge_units */
static inline void merge_flush_func_00421CD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00421CD0 */

/* merge_units: begin func_00421F10 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: guiTextListWidget.cc. Functions are named by address
 * until real names are known.
 */


Rel* std_vector_Item_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_00421F10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00421F10 */

/* merge_units: begin func_00421F30 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "direct_base_dtor.h"
#pragma pop

#pragma cplusplus on

/* Deleting destructor that runs the base destructor. */
DEFINE_DIRECT_BASE_DTOR(std_vector_imp_Item_dtor, std_vector_deleter_Item_dtor)
static inline void merge_flush_func_00421F30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00421F30 */

/* merge_units: begin func_00421F90 */
#pragma push /* merge_units */
typedef struct { char pad[0x14]; } G4_E14;
typedef struct { int x; int size; G4_E14* data; } G4_Vec;
#if 0 /* merge_units */
extern void String_Dtor(G4_E14* e, int f);
#endif /* merge_units */
#define String_Dtor(a0, a1) (String_Dtor((void *)(a0), (a1))) /* merge_units */

static inline void destroy_(G4_E14* p) { if (p) String_Dtor(p, 0); }
void std_vector_deleter_Item_clear(G4_Vec* v)
{
    G4_E14* b = v->data;
    G4_E14* e = b + v->size;
    while (b < e) {
        G4_E14* p = --e;
        if (p) destroy_(p);
    }
    v->size = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00421F90(void) {}
#undef String_Dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00421F90 */
