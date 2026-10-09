/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0048C4CD[];   /* library version string "1.32.0089" */
extern char* String_Copy(char* dst, const char* src);

/* Copies the version string into buf; returns 23 on a null argument. */
int func_002E9320(char* buf) {
    int result = 23;

    if (buf != 0) {
        String_Copy(buf, D_0048C4CD);
        result = 0;
    }
    return result;
}
