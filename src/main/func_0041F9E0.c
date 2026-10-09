/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern L4FreeNode* D_00572118;    /* free-list head */

/* Pushes node onto the free list. */
void FreeList_Push(L4FreeNode* node) {
    node->next = D_00572118;
    D_00572118 = node;
}
