#pragma cplusplus on
/* Keep allocator guards inlined through the nested cleanup layers. */
#pragma inline_depth(8)

#include "guiTextArrayWidget_types.h"
#include "alloc_guard.h"

extern "C" {
extern char D_004BF790[];
extern char D_0049AF00[];
extern char D_004E0DC0[];
extern char D_004E0D20[];
void func_00428090(TextArrayRow* row, int flags);
void func_004263C0(guiTextArrayWidget* self);
void func_00138B70(void* string, int flags);
TextArrayStore* func_00426BD0(TextArrayStore* store, short flags);
void func_0013B2E0(void* state, int flags);
void func_0041F370(guiTextArrayWidget* self, int flags);
void func_0013B340(TextArrayStore* store, int flags);
void Mem_Free(int pool, void* allocation, char* file, int line);
void operator_delete(void* allocation);
}

/* Destroy the row's cell vector before optional deletion. */
extern "C" TextArrayRow* func_004268E0(TextArrayRow* self, short deleteFlag)
{
    if (self) {
        func_00428090(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}

static inline void destroy_string(void* string)
{
    if (string)
        func_00138B70(string, 0);
}

static inline void destroy_child(TextArrayWidgetChild* child)
{
    if (child)
        destroy_string(child->string);
}

static inline void release_child(TextArrayWidgetChild* child)
{
    AllocGuard guard;
    destroy_child(child);
    Mem_Free(0, child, D_004BF790, 0x1F);
}

static inline void destroy_store(TextArrayStore* store)
{
    if (store)
        func_00426BD0(store, -1);
}

static inline void destroy_widget_base(guiTextArrayWidget* self)
{
    if (self) {
        self->vtable = D_004E0D20;
        func_0013B2E0(self->baseState, -1);
        func_0041F370(self, 0);
    }
}

/* Destroy rows, the rendering child and pointer storage before the grid base. */
extern "C" guiTextArrayWidget* func_00426940(guiTextArrayWidget* self, short deleteFlag)
{
    if (self) {
        self->vtable = D_004E0DC0;
        func_004263C0(self);
        TextArrayWidgetChild* child = self->unk90;
        if (child)
            release_child(child);
        destroy_store(&self->store);
        destroy_widget_base(self);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}

static inline void destroy_vector_base(TextArrayStore* store)
{
    if (store)
        func_0013B340(store, 0);
}

/* Destroy the pointer vector's base before optional deletion. */
extern "C" TextArrayStore* func_00426A80(TextArrayStore* self, short deleteFlag)
{
    if (self) {
        destroy_vector_base(self);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}

static inline void free_buffer(TextArrayRow** data)
{
    if (data) {
        AllocGuard guard;
        Mem_Free(0, data, D_0049AF00, 0x64);
    }
}

static inline void release_buffer(TextArrayStore* store)
{
    if (store) {
        TextArrayRow** data = store->unk08;
        if (data)
            free_buffer(data);
    }
}

/* Release pointer storage before optional vector deletion. */
extern "C" TextArrayStore* func_00426AE0(TextArrayStore* self, short deleteFlag)
{
    if (self) {
        release_buffer(self);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}

static inline void release_base(TextArrayStore* store)
{
    if (store)
        release_buffer(store);
}

/* Release pointer storage through both base layers before optional deletion. */
extern "C" TextArrayStore* func_00426BD0(TextArrayStore* self, short deleteFlag)
{
    if (self) {
        release_base(self);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
