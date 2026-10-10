#include "types.h"

/* Library code: matches with EE-GCC 2.95 -O2 (check.py --gcc). */

typedef struct LNode { struct LNode* next; struct LNode* prev; } LNode;

/* Unlinks a node from a doubly-linked list. */
void func_002ED8D8(LNode* n)
{
    n->next->prev = n->prev;
    n->prev->next = n->next;
}
