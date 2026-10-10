#pragma cplusplus on

#include "guiTextListWidget_types.h"
#include "alloc_guard.h"

extern "C" {
extern char D_004BF530[];
extern char D_0049AF00[];
extern char D_004E0C80[];
extern char D_004E0D20[];
void* func_00414790(void);
void* func_00418420(void* manager, const char* name);
char* func_0036A2F0(void* resource);
void func_00424820(TextRenderWidget* self, void* dimensions);
void func_00424A50(TextRenderWidget* self);
void func_00424A90(TextRenderWidget* self);
void func_00424BC0(TextRenderWidget* self);
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
void Mem_Free(int pool, void* allocation, char* file, int line);
void func_00138B70(void* string, int flags);
TextRenderChild* func_003D0940(TextRenderChild* self, int x, int y,
                             int width, int height, void* resource,
                             TextRenderStyle* style);
void func_00423000(TextListEntryVec* entries, int flags);
void func_0013B2E0(void* state, int flags);
void func_0041F370(TextRenderWidget* self, int flags);
void func_0013B340(TextListEntryVec* entries, int flags);
void operator_delete(void* allocation);
}

static inline void destroy_string(void* string)
{
    if (string)
        func_00138B70(string, 0);
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
    Mem_Free(0, child, D_004BF530, line);
}

static inline void destroy_entry_storage(TextListEntryVec* entries)
{
    if (entries)
        func_00423000(entries, 0);
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
        func_0013B2E0(self->baseState, -1);
        func_0041F370(self, 0);
    }
}

/* Resolve the named text resource and apply its dimensions when available. */
extern "C" void func_00421690(TextRenderWidget* self, const char* name)
{
    self->resource = func_00418420(func_00414790(), name);
    if (self->resource)
        func_00424820(self, func_0036A2F0(self->resource) + 4);
}

/* Release the optional text child after the base widget is deactivated. */
extern "C" void func_00421700(TextRenderWidget* self)
{
    func_00424A50(self);
    TextRenderChild* child = self->child;
    if (child) {
        release_child(child, 0x45);
        self->child = 0;
    }
}

/* Lazily construct the text child and synchronize its active state. */
extern "C" void func_004217D0(TextRenderWidget* self)
{
    func_00424A90(self);
    if (!self->child) {
        TextRenderChild* child;
        {
            AllocGuard guard;
            child = (TextRenderChild*)Mem_Alloc(0, sizeof(TextRenderChild),
                                              D_004BF530, 0x37);
        }
        if (child)
            child = func_003D0940(child, 0, 0, (int)self->width, (int)self->height,
                                 self->resource, &self->styles[0]);
        self->child = child;
    }
    self->child->enabled = 1;
    self->child->active = 1;
    self->child->mode = self->mode;
    self->child->state = self->state;
}

/* Restore the default resource after the base widget reset. */
extern "C" void func_004218F0(TextRenderWidget* self)
{
    func_00424BC0(self);
    self->resource = func_00418420(func_00414790(), 0);
    if (self->resource)
        func_00424820(self, func_0036A2F0(self->resource) + 4);
}

/* Destroy the owned text child, entries and base widget before optional deletion. */
extern "C" TextRenderWidget* func_00421950(TextRenderWidget* self, short deleteFlag)
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
        func_0013B340(entries, 0);
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
        Mem_Free(0, data, D_0049AF00, 0x64);
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
