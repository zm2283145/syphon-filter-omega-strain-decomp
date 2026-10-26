/*
 * main/guiWidget: 5 files, 0041F210-0041F5B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin guiWidget_41F210 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "guiTextWidget_types.h"

extern "C" {
GuiStreamString* String_CtorCStr_13B480(GuiStreamString* result, const char* text);
void String_AssignString(GuiStreamString* destination, const GuiStreamString* source);
void String_Dtor(GuiStreamString* string, int flags);
}

static inline const char* read_string(char** cursor)
{
    const char* start = *cursor;
    while (*(*cursor)++)
        ;
    return start;
}

static inline void read_flag(GuiWidgetStreamRecord* self, char** cursor, unsigned short mask)
{
    unsigned short enabled = *(unsigned short*)*cursor;
    *cursor += 2;
    if (enabled)
        self->flags |= mask;
    else
        self->flags &= ~mask;
}

/* Load the widget name, four aligned coordinates and two flag words. */
extern "C" int GuiWidget_Load(GuiWidgetStreamRecord* self, char** cursor)
{
    GuiStreamString name;
    String_CtorCStr_13B480(&name, read_string(cursor));
    String_AssignString(&self->name, &name);
    String_Dtor(&name, 0);
    *cursor = (char*)(((unsigned int)*cursor + 3) & ~3u);
    self->first = *(float*)*cursor;
    *cursor += 4;
    self->second = *(float*)*cursor;
    *cursor += 4;
    self->third = *(float*)*cursor;
    *cursor += 4;
    self->fourth = *(float*)*cursor;
    *cursor += 4;
    read_flag(self, cursor, 2);
    read_flag(self, cursor, 4);
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end guiWidget_41F210 */

/* merge_units: begin func_0041F370 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "gui_traversal_types.h"
#include "alloc_guard.h"

struct GuiOwnedObject {
    virtual ~GuiOwnedObject();
};

extern "C" {
extern char D_004E0B40[];
extern char D_004E09B0[];
extern int D_00572130;
ChildIterator List_Begin(ChildList* list);
void std_list_GuiWidgetPtr_generic_iterator_ctor(ChildIterator* result, const ChildIterator& source);
ChildIterator std_list_GuiWidgetPtr_end(ChildList* list);
void cLListIterator_GuiWidgetPtr_ctor_listR(ChildIterator* result, const ChildIterator& source);
void cLList_GuiWidgetPtr_dtor(ChildList* list, int flags);
#if 0 /* merge_units */
void String_Dtor(void* string, int flags);
#endif /* merge_units */
#define String_Dtor(a0, a1) (String_Dtor((GuiStreamString *)(a0), (a1))) /* merge_units */

void Mem_Free(int pool, void* allocation, char* file, int line);
void operator_delete(void* allocation);
}

static inline void destroy_owned(GuiOwnedObject* object, int line)
{
    object->~GuiOwnedObject();
    Mem_Free(0, object, "guiWidget.cc", line);
}

static inline bool has_child(ChildNode* node, ChildList* list, ChildIterator* end)
{
    cLListIterator_GuiWidgetPtr_ctor_listR(end, std_list_GuiWidgetPtr_end(list));
    return node != end->node;
}

static inline void destroy_children(ChildList* list)
{
    if (list)
        cLList_GuiWidgetPtr_dtor(list, 0);
}

static inline void destroy_name(void* name)
{
    if (name)
        String_Dtor(name, 0);
}

static inline void destroy_base(TraversalWidget* self)
{
    if (self) {
        *(void**)self = D_004E09B0;
        D_00572130--;
    }
}

/* Destroy owned children and a separate handler under the allocator guard. */
extern "C" TraversalWidget* GuiWidget_Destroy(TraversalWidget* self, short deleteFlag)
{
    if (self) {
        ChildIterator end;
        ChildIterator begin;
        GuiOwnedObject* child;
        ChildNode* node;
        *(void**)self = D_004E0B40;
        std_list_GuiWidgetPtr_generic_iterator_ctor(&begin, List_Begin(&self->children));
        node = begin.node;
        while (has_child(node, &self->children, &end)) {
            child = (GuiOwnedObject*)node->widget;
            {
                AllocGuard guard;
                destroy_owned(child, 0x58);
            }
            node = node->next;
        }
        GuiOwnedObject* handler = (GuiOwnedObject*)self->handler;
        if (handler != (GuiOwnedObject*)self) {
            AllocGuard guard;
            destroy_owned(handler, 0x5C);
        }
        destroy_children(&self->children);
        destroy_name(self->name);
        destroy_base(self);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
#undef String_Dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0041F370 */

/* merge_units: begin func_0041F5B0 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
void func_00135C90(ChildList* list, int flags);
void ObjectList_EraseRange(ChildIterator* result, ChildList* list,
                          ChildIterator* first, ChildIterator* last);
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
DEFINE_BASE_DTOR_CHAIN(func_0041F740, std_list_GuiWidgetPtr_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_0041F740 */
