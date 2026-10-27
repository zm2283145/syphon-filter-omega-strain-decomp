/*
 * main/guiTextListWidget: range (2 files, 00421670-00421690)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "guiTextListWidget_types.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

/* merge_units: begin func_00421670 */
#pragma push /* merge_units */
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
void String_Dtor(void* string, int flags);
TextRenderChild* cTextArea_ctor(TextRenderChild* self, int x, int y,
                             int width, int height, void* resource,
                             TextRenderStyle* style);
void std_vector_deleter_Item_dtor(TextListEntryVec* entries, int flags);
void cArray_int_dtor(void* state, int flags);
void GuiWidget_dtor(TextRenderWidget* self, int flags);
void std_vector_imp_int_1_dtor(TextListEntryVec* entries, int flags);
void operator_delete(void* allocation);
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
#pragma pop /* merge_units */
/* merge_units: end func_00421690 */
