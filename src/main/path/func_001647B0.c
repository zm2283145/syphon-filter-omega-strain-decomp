#include "types.h"

typedef struct LNode { int unk0; struct LNode* next; struct LNode* prev; } LNode;
typedef struct { char pad[8]; LNode* node; char pad2[0x10]; int count; } LOwner;

/* Unlinks the owner's current node from its doubly linked list and decrements the count. */
LNode* func_001647B0(LOwner* o)
{
    LNode* node = o->node;
    LNode* prev;
    LNode* next;
    next = node->next;
    prev = node->prev;
    prev->next = next;
    next->prev = prev;
    o->count--;
    return node;
}
