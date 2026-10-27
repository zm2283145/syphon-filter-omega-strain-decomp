/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int std_vector_imp_cLosRequest_cCollisionModelList_Game_init(Rel*, int, int);

/* Zeroes the three words, then initializes from (a1, a2) via std_vector_imp_cLosRequest_cCollisionModelList_Game_init. */
Rel* std_vector_imp_cLosRequest_cCollisionModelList_Game_ctor(Rel* r, int a1, int a2) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    std_vector_imp_cLosRequest_cCollisionModelList_Game_init(r, a1, a2);
    return r;
}

/* Clears bytes +0x60, +0x62 and words +0x80, +0x84. */
char* cLosResult_ctor_void(char* self) {
    self[96] = 0;
    self[98] = 0;
    *(int*)(self + 128) = 0;
    *(int*)(self + 132) = 0;
    return self;
}
