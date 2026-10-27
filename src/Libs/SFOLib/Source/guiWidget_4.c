/*
 * Libs/SFOLib/Source/guiWidget: 1 file, 0041F150
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin guiWidget_41F150 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

struct Child {
    virtual void v00();
    virtual void MethodC(); /* +0xC */
};

typedef struct ListNode {
    struct ListNode* prev;  /* +0x00 */
    struct ListNode* next;  /* +0x04 */
    struct Widget* data;    /* +0x08 */
} ListNode;
typedef struct ListIter { ListNode* node; } ListIter;
typedef struct NodeList { int unk0; } NodeList;
typedef struct Widget {
    char pad[0x14];
    unsigned short flags;   /* +0x14 */
    char pad16[0x28 - 0x16];
    NodeList children;          /* +0x28 */
    char pad2C[0x44 - 0x2C];
    Child* child;           /* +0x44 */
} Widget;
extern "C" void std_list_deleter_voidPtr_begin_void(ListIter* out, NodeList* list);  /* list.begin() */
extern "C" void std_list_GuiWidgetPtr_generic_iterator_ctor(ListIter* out, ListIter* in);    /* iterator -> const_iterator */
extern "C" void std_list_GuiWidgetPtr_end(ListIter* out, NodeList* list);  /* list.end() */
extern "C" void cLListIterator_GuiWidgetPtr_ctor_listR(ListIter* out, ListIter* in);    /* iterator -> const_iterator */

/* Sets flag 0x1 and notifies every child widget in the +0x28 list (child +0x44, virtual +0xC). */
extern "C" void GuiWidget_onAdd(Widget* self)
{
    ListIter endIt;
    ListIter beginIt;
    ListIter it;
    ListIter last;
    ListNode* node;
    self->flags |= 1;
    std_list_deleter_voidPtr_begin_void(&beginIt, &self->children);
    std_list_GuiWidgetPtr_generic_iterator_ctor(&it, &beginIt);
    node = it.node;
    std_list_GuiWidgetPtr_end(&endIt, &self->children);
    cLListIterator_GuiWidgetPtr_ctor_listR(&last, &endIt);
    if (node != last.node) {
    do {
    node->data->child->MethodC();
    node = node->next;
    std_list_GuiWidgetPtr_end(&endIt, &self->children);
    cLListIterator_GuiWidgetPtr_ctor_listR(&last, &endIt);
    } while (node != last.node);
    }
}
static inline void merge_flush_guiWidget_41F150(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end guiWidget_41F150 */
