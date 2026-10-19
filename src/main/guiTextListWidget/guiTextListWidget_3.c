/*
 * main/guiTextListWidget: 2 files, 00421BF0-00421CD0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00421BF0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

/* Virtual-call view of WidgetV: only the slots used here are named (vtable offset in comments). */
struct WidgetV {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void Method5C(int a, int b); /* +0x5C */
};

typedef struct Anim { char pad[0xC]; unsigned char enabled; /* +0xC */ } Anim;

typedef struct Widget {
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
} Widget;

extern char D_004E0C80[];
extern "C" void GuiArrayWidget_ctor(Widget* self);
extern "C" void func_00421F10(Anim* anim);

/* Constructor: base init, vtable D_004E0C80, animation sub-object, default mode 2 and colour/scale defaults. */
extern "C" Widget* GuiTextListWidget_ctor(Widget* self)
{
    Anim* anim;
    GuiArrayWidget_ctor(self);
    self->vtable = D_004E0C80;
    anim = &self->anim;
    func_00421F10(anim);
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
#pragma pop /* merge_units */
/* merge_units: end func_00421BF0 */

/* merge_units: begin func_00421CD0 */
#pragma push /* merge_units */
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
#pragma pop /* merge_units */
/* merge_units: end func_00421CD0 */
