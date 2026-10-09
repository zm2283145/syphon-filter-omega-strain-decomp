/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern signed char* D_005061D0; /* read cursor into a byte stream */

int func_0012F370(void) {
    return 0;
}

/* Reads one byte from the stream and stores it as a bool (nonzero -> 1). */
void Stream_ReadBool(char* out) {
    signed char* p;
    signed char b;

    p = D_005061D0;
    b = *p;
    D_005061D0 = p + 1;
    *out = b != 0;
}

/* Reads one byte from the stream. */
void Stream_ReadByte(char* out) {
    signed char* p;
    signed char b;

    p = D_005061D0;
    b = *p;
    D_005061D0 = p + 1;
    *out = b;
}
