/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int ActiveList_RemoveObject(char* world, int camera);
extern char D_004FFB50[]; /* world object */
extern int func_00131320(char* world, int camera); /* push camera */

int cNIEventOBJ_DeactivateCamera(int camera) {
    return ActiveList_RemoveObject(D_004FFB50, camera);
}

int cNIEventOBJ_ActivateCamera(int camera) {
    return func_00131320(D_004FFB50, camera);
}

void* func_0017A5F0(char* self) {
    return self + 0xB10;
}
