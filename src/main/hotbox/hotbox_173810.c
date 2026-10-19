/*
 * main/hotbox: 2 files, 00173810-00173900
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00173810 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(func_00173810)
#pragma pop /* merge_units */
/* merge_units: end func_00173810 */

/* merge_units: begin func_00173900 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int PtrVec_Reserve(int, int);
extern int func_00173970(LinkList* list);

int PtrVec_Reserve_Thunk_173900(int a0, int a1) {
    return PtrVec_Reserve(a0, a1);
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
#pragma pop /* merge_units */
/* merge_units: end func_00173900 */
