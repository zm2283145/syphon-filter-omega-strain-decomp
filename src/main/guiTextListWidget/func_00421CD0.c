#pragma cplusplus on
/* Preserve allocator-guard inlining through the nested vector cleanup. */
#pragma inline_depth(8)

#include "guiTextListWidget_types.h"
#include "alloc_guard.h"

extern "C" {
extern char D_004E0D20[];
extern char D_0049AF00[];
void func_00423000(TextListEntryVec* entries, int flags);
void func_0013A040(void* state, int flags);
void GuiWidget_Destroy(TextRenderWidget* self, int flags);
void Mem_Free(int pool, void* allocation, char* file, int line);
void operator_delete(void* allocation);
}

static inline void destroy_storage(TextListEntryVec* entries)
{
    if (entries)
        func_00423000(entries, 0);
}

static inline void destroy_vector(TextListEntryVec* entries)
{
    if (entries)
        destroy_storage(entries);
}

/* Destroy both vector layers before optional object deletion. */
extern "C" TextListEntryVec* func_00421CD0(TextListEntryVec* self, short deleteFlag)
{
    if (self) {
        destroy_vector(self);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}

/* Destroy vector storage before optional object deletion. */
extern "C" TextListEntryVec* func_00421D40(TextListEntryVec* self, short deleteFlag)
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
extern "C" TextRenderWidget* func_00421DA0(TextRenderWidget* self, short deleteFlag)
{
    if (self) {
        self->vtable = D_004E0D20;
        destroy_state(self->baseState);
        GuiWidget_Destroy(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}

static inline void free_buffer(TextListEntry* data)
{
    if (data) {
        AllocGuard guard;
        Mem_Free(0, data, D_0049AF00, 0x64);
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
