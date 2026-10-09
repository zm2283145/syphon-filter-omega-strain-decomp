/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DACB0[];
extern char D_004F2CC0[];
extern int func_001004B0(int, int, int, int, int);
extern int func_001C9F10(int, int);
extern int func_001C9F80(int);
extern int func_003CB4B0(int, int);

int func_001C9EA0(int a0) {
    func_003CB4B0(a0, (int)D_004F2CC0);
    *(int*)((char*)a0) = (int)D_004DACB0;
    func_001004B0((a0 + 48), (int)func_001C9F80, (int)func_001C9F10, 432, 50);
    *(int*)((char*)a0 + 21672) = 0;
    *(int*)((char*)a0 + 21676) = 0;
    *(int*)((char*)a0 + 21680) = 0;
    *(char*)((char*)a0 + 32) = 0;
    return a0;
}
