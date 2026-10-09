/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FFB50[]; /* world object */
extern int Global_RequestLevelEnd(void);
extern int func_0012FA60(char* world, int);

int Script_RequestLevelEnd(void) {
    Global_RequestLevelEnd();
    return 0;
}

int Global_RequestLevelEnd(void) {
    return func_0012FA60(D_004FFB50, 0);
}
