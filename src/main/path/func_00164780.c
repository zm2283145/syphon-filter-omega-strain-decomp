#include "types.h"

typedef struct LNode { struct LNode* unk0; struct LNode* prev; struct LNode* next; } LNode;
typedef struct { char pad[8]; LNode* node; char pad2[0x10]; int count; } LOwner;

/* Unlinks the owner's node from its doubly linked list, decrements the count and returns the node. */
LNode* func_00164780(LOwner* self)
{
    LNode* node = self->node;
    LNode* next;
    LNode* prev;
    prev = node->prev;
    next = node->next;
    next->prev = prev;
    prev->next = next;
    self->count--;
    return node;
}
