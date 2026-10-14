/*
 * main/GuiAgentCreate: range (2 files, 0028C1D0-0028C2A0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0028C1D0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0028C1D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0028C1D0 */

/* merge_units: begin func_0028C2A0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

struct Child_0028C2A0 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual void Method1C(); /* +0x1C */
};

typedef struct ListNode_0028C2A0 {
    struct ListNode_0028C2A0* prev;  /* +0x00 */
    struct ListNode_0028C2A0* next;  /* +0x04 */
    struct Widget_0028C2A0* data;    /* +0x08 */
} ListNode_0028C2A0;
typedef struct ListIter_0028C2A0 { ListNode_0028C2A0* node; } ListIter_0028C2A0;
typedef struct Widget_0028C2A0 {
    char pad[0x14];
    unsigned short flags;   /* +0x14 */
    char pad16[0x28 - 0x16];
    NodeList children;          /* +0x28 */
    char pad2C[0x44 - 0x2C];
    Child_0028C2A0* child;           /* +0x44 */
} Widget_0028C2A0;
#if 0 /* merge_units */
extern "C" void func_0013B180(ListIter_0028C2A0* out, NodeList* list);  /* list.begin() */
#endif /* merge_units */
#define func_0013B180(a0, a1) (func_0013B180((ListIter *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern "C" void func_0028C0B0(ListIter_0028C2A0* out, ListIter_0028C2A0* in);    /* iterator -> const_iterator */
#endif /* merge_units */
#define func_0028C0B0(a0, a1) (func_0028C0B0((ListIter *)(a0), (ListIter *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern "C" void func_0028C0A0(ListIter_0028C2A0* out, NodeList* list);  /* list.end() */
#endif /* merge_units */
#define func_0028C0A0(a0, a1) (func_0028C0A0((ListIter *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern "C" void func_0028C090(ListIter_0028C2A0* out, ListIter_0028C2A0* in);    /* iterator -> const_iterator */
#endif /* merge_units */
#define func_0028C090(a0, a1) (func_0028C090((ListIter *)(a0), (ListIter *)(a1))) /* merge_units */


/* For every other widget in the +0x28 list: sets flag 0x2, notifies its child (+0x44, virtual +0x1C), sets 0x4 and clears 0x80. */
extern "C" void func_0028C2A0(Widget_0028C2A0* self)
{
    ListIter_0028C2A0 endIt;
    ListIter_0028C2A0 beginIt;
    ListIter_0028C2A0 it;
    ListIter_0028C2A0 last;
    ListNode_0028C2A0* node;
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
    Widget_0028C2A0* w = node->data;
    if (w != self) {
    w->flags |= 2;
    node->data->child->Method1C();
    node->data->flags |= 4;
    node->data->flags &= ~0x80;
    }
    node = node->next;
    func_0028C0A0(&endIt, list);
    func_0028C090(&last, &endIt);
    } while (node != last.node);
    }
    }
}
#undef func_0013B180 /* merge_units */
#undef func_0028C0B0 /* merge_units */
#undef func_0028C0A0 /* merge_units */
#undef func_0028C090 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0028C2A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0028C2A0 */
