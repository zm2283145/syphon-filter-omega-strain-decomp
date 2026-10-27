/*
 * main/path: range (2 files, 00164780-001647B0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00164780 */
#pragma push /* merge_units */
typedef struct LNode { struct LNode* unk0; struct LNode* prev; struct LNode* next; } LNode;
typedef struct { char pad[8]; LNode* node; char pad2[0x10]; int count; } LOwner;

/* Unlinks the owner's node from its doubly linked list, decrements the count and returns the node. */
LNode* cPriorityQueue_cPathCell_Pop(LOwner* self)
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00164780(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00164780 */

/* merge_units: begin func_001647B0 */
#pragma push /* merge_units */
typedef struct LNode_001647B0 { int unk0; struct LNode_001647B0* next; struct LNode_001647B0* prev; } LNode_001647B0;
typedef struct { char pad[8]; LNode_001647B0* node; char pad2[0x10]; int count; } LOwner_001647B0;

/* Unlinks the owner's current node from its doubly linked list and decrements the count. */
LNode_001647B0* cPriorityQueue_cNodeIndex_Pop(LOwner_001647B0* o)
{
    LNode_001647B0* node = o->node;
    LNode_001647B0* prev;
    LNode_001647B0* next;
    next = node->next;
    prev = node->prev;
    prev->next = next;
    next->prev = prev;
    o->count--;
    return node;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001647B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001647B0 */
