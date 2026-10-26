/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int String_CopyCtor(L4FlagVec*, int);

int std_make_pair_cString_uchar(L4FlagVec* v, int a1, int flag) {
    int ret = String_CopyCtor(v, a1);

    v->unk0C = flag;
    return ret;
}
