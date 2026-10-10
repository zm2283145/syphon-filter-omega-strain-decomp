/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

struct Child {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void Method20(); /* +0x20 */
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
extern "C" void func_0013B180(ListIter* out, NodeList* list);  /* list.begin() */
extern "C" void func_0028C0B0(ListIter* out, ListIter* in);    /* iterator -> const_iterator */
extern "C" void func_0028C0A0(ListIter* out, NodeList* list);  /* list.end() */
extern "C" void func_0028C090(ListIter* out, ListIter* in);    /* iterator -> const_iterator */

/* For every other widget in the +0x28 list: clears flag 0x2 and notifies its child (+0x44, virtual +0x20). */
extern "C" void func_0028C1D0(Widget* self)
{
    ListIter endIt;
    ListIter beginIt;
    ListIter it;
    ListIter last;
    ListNode* node;
    NodeList* list;
    if (self) {
    func_0013B180(&beginIt, &self->children);
    func_0028C0B0(&it, &beginIt);
    node = it.node;
    list = &self->children;
    func_0028C0A0(&endIt, list);
    func_0028C090(&last, &endIt);
    if (node != last.node) {
    do {
    Widget* w = node->data;
    if (w != self) {
    w->flags &= ~2;
    node->data->child->Method20();
    }
    node = node->next;
    func_0028C0A0(&endIt, list);
    func_0028C090(&last, &endIt);
    } while (node != last.node);
    }
    }
}
