#pragma cplusplus on
#include "types.h"
struct Vec2 { float x, y; Vec2() {} Vec2(float ax, float ay) { x = ax; y = ay; } Vec2& operator+=(const Vec2& o) { x += o.x; y += o.y; return *this; } };
typedef struct ListNode {
    struct ListNode* prev;
    struct ListNode* next;
    struct Widget* data;
} ListNode;
typedef struct ListIter { ListNode* node; } ListIter;
typedef struct NodeList { int unk0; } NodeList;
typedef struct Widget {
    char pad[0x28];
    NodeList children;
    char pad2C[0x34 - 0x2C];
    float x, y;
} Widget;
extern "C" void List_Begin(ListIter* out, NodeList* list);
extern "C" void std_list_GuiWidgetPtr_generic_iterator_ctor(ListIter* out, ListIter* in);
extern "C" void std_list_GuiWidgetPtr_end(ListIter* out, NodeList* list);
extern "C" void cLListIterator_GuiWidgetPtr_ctor_listR(ListIter* out, ListIter* in);
extern "C" void GuiWidget_SetPos(Widget* w, float x, float y);
static inline void SetPos(Widget* w, Vec2 v) { GuiWidget_SetPos(w, v.x, v.y); }
extern "C" void func_002A5470(Widget* w, Vec2 off)
{
    ListIter last;
    ListIter it;
    ListIter beginIt;
    ListIter endIt;
    NodeList* list;
    ListNode* node;
    if (w) {
        Vec2 p(w->x, w->y);
        p += off;
        SetPos(w, p);
        list = &w->children;
        List_Begin(&beginIt, list);
        std_list_GuiWidgetPtr_generic_iterator_ctor(&it, &beginIt);
        node = it.node;
        std_list_GuiWidgetPtr_end(&endIt, list);
        cLListIterator_GuiWidgetPtr_ctor_listR(&last, &endIt);
        if (node != last.node) {
            do {
                func_002A5470(node->data, off);
                node = node->next;
                std_list_GuiWidgetPtr_end(&endIt, list);
                cLListIterator_GuiWidgetPtr_ctor_listR(&last, &endIt);
            } while (node != last.node);
        }
    }
}



