/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001D8730(void);
extern int func_001D8900(void);

int func_001D86D0(int a0) {
    *(int*)((char*)a0) = 0;
    *(int*)((char*)a0 + 4) = 0;
    *(int*)((char*)a0 + 12) = 0;
    *(int*)((char*)a0 + 16) = 0;
    *(int*)((char*)a0 + 20) = 0;
    *(int*)((char*)a0 + 24) = 0;
    *(int*)((char*)a0 + 28) = 0;
    *(char*)((char*)a0 + 32) = 0;
    return a0;
}

int func_001D8700(int a0) {
    *(int*)((char*)a0) = 0;
    *(int*)((char*)a0 + 4) = 0;
    return a0;
}

int func_001D8710(void) {
    return func_001D8730();
}

int func_001D8720(void) {
    return func_001D8900();
}
