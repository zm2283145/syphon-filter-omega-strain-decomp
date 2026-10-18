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
extern "C" void func_0028C0B0(ListIter* out, ListIter* in);
extern "C" void func_0028C0A0(ListIter* out, NodeList* list);
extern "C" void func_0028C090(ListIter* out, ListIter* in);
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
        func_0028C0B0(&it, &beginIt);
        node = it.node;
        func_0028C0A0(&endIt, list);
        func_0028C090(&last, &endIt);
        if (node != last.node) {
            do {
                func_002A5470(node->data, off);
                node = node->next;
                func_0028C0A0(&endIt, list);
                func_0028C090(&last, &endIt);
            } while (node != last.node);
        }
    }
}



