/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int func_001396D0(int, int);
extern int func_00173970(LinkList* list);

int func_00173900(int a0, int a1) {
    return func_001396D0(a0, a1);
}

Rel* func_00173910(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

/* List constructor: empty, sentinel node at +4 linked to itself. */
LinkList* LinkList_Ctor(LinkList* list) {
    list->count = 0;
    func_00173970(list);
    list->sentinel.prev = &list->sentinel;
    list->sentinel.next = &list->sentinel;
    return list;
}
