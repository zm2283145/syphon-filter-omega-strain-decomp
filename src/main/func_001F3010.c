/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int std_list_imp_voidPtr_size(void);
extern int Vector_Reserve_20C2A0(int, int);

int Vector_Reserve_20C2A0_Thunk_1F3010(int a0, int a1) {
    return Vector_Reserve_20C2A0(a0, a1);
}

int cLList_cSkaSwitchItemPtr_Size(void) {
    return std_list_imp_voidPtr_size();
}
