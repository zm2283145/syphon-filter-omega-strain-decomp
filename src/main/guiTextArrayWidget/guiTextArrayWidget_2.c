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

extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int value);

/* push_back on a pointer vector. */
int std_vector_cArray_tTextElementPtr_push_back(PtrVec* v, int value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}

Vec4* tRGBA_ctor_float_float_float_float(Vec4* v, float x, float y, float z, float w) {
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
    return v;
}

void* tRGBA_ctor_void(void* self) {
    return self;
}

Rel* std_vector_tTextElement_ctor(Rel* r) {
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
extern "C" void GuiTextArrayWidget_IsClass();
extern "C" void GuiWidget_FindPrevFocus();
extern "C" void GuiWidget_FindNextFocus();
extern "C" void GuiWidget_FindLastFocus();
extern "C" void GuiWidget_FindFirstFocus();
extern "C" void GuiWidget_onAction();
extern "C" void GuiWidget_onAdvanceTime();
extern "C" void GuiWidget_onMessage();
extern "C" void GuiWidget_onDeactivate();
extern "C" void GuiWidget_onActivate();
extern "C" void GuiWidget_onRemove();
extern "C" void GuiWidget_Load();
extern "C" void GuiArrayWidget_onElementLoseFocus();
extern "C" void GuiArrayWidget_onElementGainFocus();
extern "C" void GuiArrayWidget_onRowRender();
extern "C" void GuiArrayWidget_onColumnRender();
extern "C" void GuiArrayWidget_onRender();
extern "C" void GuiArrayWidget_onInput();
extern "C" void GuiArrayWidget_onLoseFocus();
extern "C" void GuiArrayWidget_onGainFocus();
extern "C" void GuiTextArrayWidget_GetClassName();
extern "C" void GuiTextArrayWidget_onElementRender();
extern "C" void GuiTextArrayWidget_onSleep();
extern "C" void GuiTextArrayWidget_onWake();
extern "C" void GuiTextArrayWidget_onAdd();
extern "C" void GuiTextArrayWidget_SetSize();
extern void * const D_004E0DC0[];
extern char D_004E0D20[];
void std_vector_deleter_tTextElement_dtor(TextArrayRow* row, int flags);
void GuiTextArrayWidget_DestroyTextArray(guiTextArrayWidget* self);
void String_Dtor(void* string, int flags);
TextArrayStore* std_vector_cArray_tTextElementPtr_dtor(TextArrayStore* store, short flags);
void cArray_int_dtor(void* state, int flags);
void GuiWidget_dtor(guiTextArrayWidget* self, int flags);
void std_vector_imp_int_1_dtor(TextArrayStore* store, int flags);
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
void operator_delete(void* allocation);
}

/* Destroy the row's cell vector before optional deletion. */
extern "C" TextArrayRow* std_vector_imp_tTextElement_dtor(TextArrayRow* self, short deleteFlag)
{
    if (self) {
        std_vector_deleter_tTextElement_dtor(self, 0);
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
    cMemMan_Deallocate(0, child, D_004BF790, 0x1F);
}

static inline void destroy_store(TextArrayStore* store)
{
    if (store)
        std_vector_cArray_tTextElementPtr_dtor(store, -1);
}

static inline void destroy_widget_base(guiTextArrayWidget* self)
{
    if (self) {
        self->vtable = D_004E0D20;
        cArray_int_dtor(self->baseState, -1);
        GuiWidget_dtor(self, 0);
    }
}

/* Destroy rows, the rendering child and pointer storage before the grid base. */
extern "C" guiTextArrayWidget* GuiTextArrayWidget_dtor(guiTextArrayWidget* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004E0DC0);
        GuiTextArrayWidget_DestroyTextArray(self);
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
        std_vector_imp_int_1_dtor(store, 0);
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
        cMemMan_Deallocate(0, data, D_0049AF00, 0x64);
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
extern "C" TextArrayStore* std_vector_cArray_tTextElementPtr_dtor(TextArrayStore* self, short deleteFlag)
{
    if (self) {
        release_base(self);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E0DC0[30] = { (void*)0x0, (void*)0x0, (void*)GuiTextArrayWidget_dtor, (void*)GuiTextArrayWidget_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiTextArrayWidget_onWake, (void*)GuiTextArrayWidget_onSleep, (void*)GuiArrayWidget_onGainFocus, (void*)GuiArrayWidget_onLoseFocus, (void*)GuiArrayWidget_onInput, (void*)GuiArrayWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiWidget_onAdvanceTime, (void*)GuiWidget_onMessage, (void*)GuiWidget_Load, (void*)GuiWidget_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiTextArrayWidget_GetClassName, (void*)GuiTextArrayWidget_IsClass, (void*)GuiTextArrayWidget_SetSize, (void*)GuiArrayWidget_onColumnRender, (void*)GuiArrayWidget_onRowRender, (void*)GuiTextArrayWidget_onElementRender, (void*)GuiArrayWidget_onElementGainFocus, (void*)GuiArrayWidget_onElementLoseFocus, (void*)0x0 };
#pragma pop /* merge_units */
/* merge_units: end func_004268E0 */

/* merge_units: begin func_00426CC0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern char D_004E0DC0[];   /* guiTextArrayWidget vtable */
#endif /* merge_units */
#define D_004E0DC0 ((char*)&D_004E0DC0) /* merge_units */

extern void* GuiArrayWidget_ctor(void* self);
extern Rel* std_vector_cArray_tTextElementPtr_ctor(Rel* r);

/* guiTextArrayWidget constructor. */
guiTextArrayWidget* GuiTextArrayWidget_ctor(guiTextArrayWidget* self) {
    TextArrayStore* store;

    GuiArrayWidget_ctor(self);
    store = &self->store;
    self->vtable = D_004E0DC0;
    std_vector_cArray_tTextElementPtr_ctor((Rel*)store);
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
DEFINE_BASE_DTOR_CHAIN(cArray_cArray_tTextElementPtr_dtor, std_vector_imp_cArray_tTextElementPtr_1_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00426D40 */
