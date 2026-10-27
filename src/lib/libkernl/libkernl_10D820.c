/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int Newlib_Errno(void);

int Libc_Open(void) {
    int tmp0;

    tmp0 = Newlib_Errno();
    *(int*)((char*)tmp0) = 5;
    return -1;
}

int Libc_Close(void) {
    return -1;
}
