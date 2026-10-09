/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004E0840[];
extern char D_0055D480[];
extern int Event_Construct(int, int);

int Actor_SendCasAction(int a0, int a1, int a2) {
    Event_Construct(a0, (int)D_0055D480);
    *(int*)((char*)a0) = (int)D_004E0840;
    *(int*)((char*)a0 + 36) = a1;
    *(char*)((char*)a0 + 40) = a2;
    return a0;
}
