/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int ObjMarkerRecord_Init(int a0) {
    *(int*)((char*)a0) = 0;
    *(int*)((char*)a0 + 4) = 0;
    *(int*)((char*)a0 + 8) = 0;
    *(char*)((char*)a0 + 12) = 0;
    *(int*)((char*)a0 + 24) = -2;
    *(int*)((char*)a0 + 20) = 0;
    *(int*)((char*)a0 + 28) = 0;
    *(int*)((char*)a0 + 32) = 0;
    *(int*)((char*)a0 + 36) = 0;
    *(int*)((char*)a0 + 40) = 0;
    *(int*)((char*)a0 + 44) = 0;
    *(int*)((char*)a0 + 48) = 0;
    return a0;
}
