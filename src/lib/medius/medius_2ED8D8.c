/*
 * lib/medius: 2 files, 002ED8D8-002ED8F8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002ED8D8 */
#include "types.h"

/* Library code: matches with EE-GCC 2.95 -O2 (check.py --gcc). */

typedef struct LNode { struct LNode* next; struct LNode* prev; } LNode;

/* Unlinks a node from a doubly-linked list. */
void GridRemoveGrid(LNode* n)
{
    n->next->prev = n->prev;
    n->prev->next = n->next;
}
/* merge_units: end func_002ED8D8 */

/* merge_units: begin func_002ED8F8 */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int GridGetFirstPlayerRef(int a0) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 84);
    return tmp0;
}
/* merge_units: end func_002ED8F8 */
