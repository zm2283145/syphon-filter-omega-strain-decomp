/*
 * main/guiWidget: 3 files, 0041F5B0-0041F740
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0041F5B0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "gui_traversal_types.h"

extern "C" {
void func_00135C90(ChildList* list, int flags);
void ObjectList_EraseRange(ChildIterator* result, ChildList* list,
                          ChildIterator* first, ChildIterator* last);
void operator_delete(void* allocation);
}

static inline void destroy_list_base(ChildList* list)
{
    if (list)
        func_00135C90(list, 0);
}

static inline void erase_all(ChildList* list)
{
    if (list) {
        ChildIterator result;
        ChildIterator first;
        ChildIterator last;
        last.node = (ChildNode*)&list->sentinel;
        first.node = list->first;
        ObjectList_EraseRange(&result, list, &first, &last);
    }
}

/* Destroy the child-list base and optionally release its allocation. */
extern "C" ChildList* func_0041F5B0(ChildList* self, short deleteFlag)
{
    if (self) {
        destroy_list_base(self);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}

/* Erase the full list up to its embedded sentinel before optional deletion. */
extern "C" ChildList* func_0041F610(ChildList* self, short deleteFlag)
{
    if (self) {
        erase_all(self);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0041F5B0 */

/* merge_units: begin func_0041F690 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet (address lies just after
 * guiWidget.cc's known range); functions are named by address until real
 * names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern char D_004E09B0[];         /* base widget vtable */
extern char D_004E0B40[];         /* GuiWidget vtable */
extern int D_00572130;            /* widget instance counter */
extern int ScalarCollection_Init(L4ScalarCollection*);

/* GuiWidget constructor. */
GuiWidget* GuiWidget_ctor(GuiWidget* self) {
    self->vtable = D_004E09B0;
    D_00572130 = D_00572130 + 1;
    self->vtable = D_004E0B40;
    self->unk04 = 0;
    self->unk08 = 0;
    self->unk0C = 0;
    ScalarCollection_Init(&self->children);
    self->unk34 = 0;
    self->unk38 = 0;
    self->unk3C = 0;
    self->unk40 = 0;
    self->flags = 38;
    self->unk10 = -1;
    self->parent = 0;
    self->unk20 = 0;
    self->unk24 = 0;
    self->unk34 = 0;
    self->unk38 = 0;
    self->unk3C = 0;
    self->unk40 = 0;
    self->self = self;
    self->unk16 = 0;
    self->unk18 = 0;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0041F690 */

/* merge_units: begin func_0041F740 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_0041F740, func_002CCD00)
#pragma pop /* merge_units */
/* merge_units: end func_0041F740 */
