/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int Script_cNPC_ForceOnRadar(int a0) {
    *(char*)((char*)*(int*)(char*)a0 + 52) = ((unsigned int)(0) < (unsigned int)(*(int*)((char*)a0 + 4)));
    return 0;
}
