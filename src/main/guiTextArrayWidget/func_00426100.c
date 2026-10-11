#pragma cplusplus on

#include "guiTextArrayWidget_types.h"
#include "alloc_guard.h"

extern "C" {
extern char D_004BF790[];
extern char D_004BF7A8[];
void func_00424A50(guiTextArrayWidget* self);
void func_00424A90(guiTextArrayWidget* self);
void func_00424BC0(guiTextArrayWidget* self);
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
void Mem_Free(int pool, void* allocation, char* file, int line);
void func_00138B70(void* string, int flags);
TextArrayWidgetChild* func_003D0940(TextArrayWidgetChild* child, int x, int y,
                                  int width, int height, int resource, float* color);
void* func_00414790(void);
int func_00418420(void* manager, const char* name);
unsigned int func_0036A2F0(int resource);
void func_00424820(guiTextArrayWidget* self, unsigned int height);
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

/* Deactivate the grid base and release the optional text-rendering child. */
extern "C" void func_00426100(guiTextArrayWidget* self)
{
    func_00424A50(self);
    TextArrayWidgetChild* child = self->unk90;
    if (child) {
        {
            AllocGuard guard;
            destroy_child(child);
            Mem_Free(0, child, D_004BF790, 0x7B);
        }
        self->unk90 = 0;
    }
}

/* Create a text child for the current resource and copy the array's display state. */
extern "C" void func_004261D0(guiTextArrayWidget* self)
{
    func_00424A90(self);
    if (self->count) {
        TextArrayWidgetChild* child;
        {
            AllocGuard guard;
            child = (TextArrayWidgetChild*)Mem_Alloc(0, sizeof(TextArrayWidgetChild),
                                                    D_004BF790, 0x6C);
        }
        if (child)
            child = func_003D0940(child, 0, 0, 10, 10, self->count, self->color);
        self->unk90 = child;
        self->unk90->enabled = 1;
        self->unk90->state = self->unk98;
        self->unk90->active = 1;
    }
}

/* Resolve the default resource, refresh row height and update an existing child. */
extern "C" void func_004262D0(guiTextArrayWidget* self)
{
    func_00424BC0(self);
    self->count = func_00418420(func_00414790(), D_004BF7A8);
    if (self->count) {
        func_00424820(self, func_0036A2F0(self->count) + 4);
        if (self->unk90)
            self->unk90->resource = self->count;
    }
}
