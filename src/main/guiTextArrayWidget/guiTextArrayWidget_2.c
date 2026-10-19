/*
 * main/guiTextArrayWidget: 4 files, 00426870-00426D40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00426870 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: guiTextArrayWidget.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "guiTextArrayWidget_types.h"

extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int value);

/* push_back on a pointer vector. */
int func_00426870(PtrVec* v, int value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}

Vec4* func_00426890(Vec4* v, float x, float y, float z, float w) {
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
    return v;
}

void* func_004268B0(void* self) {
    return self;
}

Rel* func_004268C0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end func_00426870 */

/* merge_units: begin func_004268E0 */
#pragma push /* merge_units */
#pragma cplusplus on
/* Keep allocator guards inlined through the nested cleanup layers. */
#pragma inline_depth(8)
#include "alloc_guard.h"

extern "C" {
extern char D_004BF790[];
extern char D_0049AF00[];
extern "C" void GuiTextArrayWidget_IsType();
extern "C" void GuiWidget_FocusPrev();
extern "C" void GuiWidget_FocusNext();
extern "C" void GuiWidget_FocusLast();
extern "C" void GuiWidget_FocusFirst();
extern "C" void GuiWidget_BubbleActivate();
extern "C" void GuiWidget_Update();
extern "C" void GuiWidget_OnEvent();
extern "C" void GuiWidget_ClearFlag4();
extern "C" void GuiWidget_SetFlag4();
extern "C" void GuiWidget_Deinit();
extern "C" void func_0041F210();
extern "C" void func_004235C0();
extern "C" void func_004235E0();
extern "C" void func_00423610();
extern "C" void func_00423660();
extern "C" void GuiArrayWidget_Draw();
extern "C" void GuiArrayWidget_OnInput();
extern "C" void GuiArrayWidget_OnLoseFocus();
extern "C" void GuiArrayWidget_OnGainFocus();
extern "C" void func_00425BB0();
extern "C" void GuiTextArrayWidget_DrawCell();
extern "C" void GuiTextArrayWidget_Sleep();
extern "C" void GuiTextArrayWidget_Wake();
extern "C" void GuiTextArrayWidget_Init();
extern "C" void GuiTextArrayWidget_SetDims();
extern void * const D_004E0DC0[];
extern char D_004E0D20[];
void func_00428090(TextArrayRow* row, int flags);
void func_004263C0(guiTextArrayWidget* self);
void String_Dtor(void* string, int flags);
TextArrayStore* func_00426BD0(TextArrayStore* store, short flags);
void func_0013B2E0(void* state, int flags);
void GuiWidget_Destroy(guiTextArrayWidget* self, int flags);
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
        String_Dtor(string, 0);
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
        GuiWidget_Destroy(self, 0);
    }
}

/* Destroy rows, the rendering child and pointer storage before the grid base. */
extern "C" guiTextArrayWidget* func_00426940(guiTextArrayWidget* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E0DC0);
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
void * const D_004E0DC0[30] = { (void*)0x0, (void*)0x0, (void*)func_00426940, (void*)GuiTextArrayWidget_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiTextArrayWidget_Wake, (void*)GuiTextArrayWidget_Sleep, (void*)GuiArrayWidget_OnGainFocus, (void*)GuiArrayWidget_OnLoseFocus, (void*)GuiArrayWidget_OnInput, (void*)GuiArrayWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiWidget_Update, (void*)GuiWidget_OnEvent, (void*)func_0041F210, (void*)GuiWidget_FocusFirst, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)func_00425BB0, (void*)GuiTextArrayWidget_IsType, (void*)GuiTextArrayWidget_SetDims, (void*)func_00423660, (void*)func_00423610, (void*)GuiTextArrayWidget_DrawCell, (void*)func_004235E0, (void*)func_004235C0, (void*)0x0 };
#pragma pop /* merge_units */
/* merge_units: end func_004268E0 */

/* merge_units: begin func_00426CC0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern char D_004E0DC0[];   /* guiTextArrayWidget vtable */
#endif /* merge_units */
#define D_004E0DC0 ((char*)&D_004E0DC0) /* merge_units */

extern void* GuiArrayWidget_ctor(void* self);
extern Rel* func_00427000(Rel* r);

/* guiTextArrayWidget constructor. */
guiTextArrayWidget* guiTextArrayWidget_ctor(guiTextArrayWidget* self) {
    TextArrayStore* store;

    GuiArrayWidget_ctor(self);
    store = &self->store;
    self->vtable = D_004E0DC0;
    func_00427000((Rel*)store);
    store->unk0C = 1;
    self->unk90 = 0;
    self->count = 0;
    self->unk98 = 2;
    self->color[0] = 1.0f;
    self->color[1] = 1.0f;
    self->color[2] = 1.0f;
    self->color[3] = 1.0f;
    return self;
}
#undef D_004E0DC0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00426CC0 */

/* merge_units: begin func_00426D40 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_00426D40, func_00426DA0)
#pragma pop /* merge_units */
/* merge_units: end func_00426D40 */
