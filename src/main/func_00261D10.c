/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void cFireObj_v08(int a0) {
    *(char*)((char*)a0 + 44) = 1;
}

void cFireObj_v09(char* self) {
    self[44] = 0;
}
