/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "bullet_types.h"

extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int* value);
extern int func_00275780(PtrVec* v, int* value);

/* Appends 'value' to the list at +0x78. */
void func_00275750(BulletOwner* owner, int value) {
    int tmp[1];

    tmp[0] = value;
    func_00275780(&owner->list, tmp);
}

/* push_back(v, *value) */
int func_00275780(PtrVec* v, int* value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}
