/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int Loc_GetTextById(int);
extern int Loc_FindKey(int);

int Loc_FindKeyThunk(int a0) {
    return Loc_FindKey(a0);
}

int Loc_LookupText(int a0) {
    int tmp0;
    int tmp2;

    tmp0 = Loc_FindKey(a0);
    tmp2 = Loc_GetTextById(tmp0);
    return tmp2;
}
