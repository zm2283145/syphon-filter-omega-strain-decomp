/*
 * main/bullet: 2 files, 002756E0-00275750
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002756E0 */
#pragma push /* merge_units */
#include "bullet_types.h"
extern void PtrVector_Resize(PtrVec* v, int n, int* fill);
#pragma opt_strength_reduction off
/* Removes every occurrence of 'value' from owner->list (swap with the last element), then shrinks it. */
void Bullet_LeavePartnerLists(BulletOwner* owner, int value) {
    int i;
    int last = owner->list.count - 1;
    int fill;
    for (i = 0; last >= i; i++) {
        int* e = &owner->list.data[i];
        if (*e == value) {
            *e = owner->list.data[last];
            last--;
        }
    }
    fill = 0;
    PtrVector_Resize(&owner->list, last + 1, &fill);
}
#pragma opt_strength_reduction reset
#pragma pop /* merge_units */
/* merge_units: end func_002756E0 */

/* merge_units: begin func_00275750 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int* value);
extern int PtrVec_PushBack_275780(PtrVec* v, int* value);

/* Appends 'value' to the list at +0x78. */
void BulletPool_Link(BulletOwner* owner, int value) {
    int tmp[1];

    tmp[0] = value;
    PtrVec_PushBack_275780(&owner->list, tmp);
}

/* push_back(v, *value): PtrVec_Insert at the end */
int PtrVec_PushBack_275780(PtrVec* v, int* value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}
#pragma pop /* merge_units */
/* merge_units: end func_00275750 */
