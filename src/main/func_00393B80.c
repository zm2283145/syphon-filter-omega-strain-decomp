/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001BD980(int, int, int);
extern int func_001BE020(int, int, int);

int func_00393B80(int a0, int a1, int a2) {
    return func_001BE020(a0, a1, a2);
}

int func_00393B90(char* self) {
    return *(int*)(self + 88);
}

int func_00393BA0(int a0) {
    *(int*)((char*)a0) = 0;
    *(int*)((char*)a0 + 4) = 0;
    return a0;
}

int func_00393BB0(int a0, int a1, int a2) {
    return func_001BD980(a0, a1, a2);
}

int func_00393BC0(char* self) {
    return *(int*)(self + 84);
}
