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
extern "C" void func_0013B180(ListIter* out, NodeList* list);  /* list.begin() */
extern "C" void func_0028C0B0(ListIter* out, ListIter* in);    /* iterator -> const_iterator */
extern "C" void func_0028C0A0(ListIter* out, NodeList* list);  /* list.end() */
extern "C" void func_0028C090(ListIter* out, ListIter* in);    /* iterator -> const_iterator */

/* Sets flag 0x1 and notifies every child widget in the +0x28 list (child +0x44, virtual +0xC). */
extern "C" void func_0041F150(Widget* self)
{
    ListIter endIt;
    ListIter beginIt;
    ListIter it;
    ListIter last;
    ListNode* node;
    self->flags |= 1;
    func_0013B180(&beginIt, &self->children);
    func_0028C0B0(&it, &beginIt);
    node = it.node;
    func_0028C0A0(&endIt, &self->children);
    func_0028C090(&last, &endIt);
    if (node != last.node) {
    do {
    node->data->child->MethodC();
    node = node->next;
    func_0028C0A0(&endIt, &self->children);
    func_0028C090(&last, &endIt);
    } while (node != last.node);
    }
}
