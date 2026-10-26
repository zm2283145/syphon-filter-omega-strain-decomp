/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int String_CStr(int);

int String_CStr_Thunk(int a0) {
    return String_CStr(a0);
}

void* details_compressed_pair_imp_rep_s_2_first_void(void* self) {
    return self;
}
