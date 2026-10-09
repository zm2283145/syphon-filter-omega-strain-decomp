/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001F3030(void);
extern int func_001F3760(int);
extern int func_001F3790(int);
extern int func_001F37C0(int);
extern int func_0020B3F0(int, int);

int func_001F3710(int a0, int a1) {
    return func_0020B3F0(a0, a1);
}

int func_001F3720(void) {
    return func_001F3030();
}

int func_001F3730(int a0) {
    func_001F3760(a0);
    *(char*)((char*)a0 + 12) = 1;
    return a0;
}

int func_001F3760(int a0) {
    func_001F3790(a0);
    return a0;
}

int func_001F3790(int a0) {
    func_001F37C0(a0);
    return a0;
}
