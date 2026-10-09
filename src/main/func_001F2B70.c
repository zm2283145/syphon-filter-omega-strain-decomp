/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DFBB0[];
extern void func_001F2BE0(int, int);
extern int func_001F3070(int);
extern int MotionNode_BaseCtor(int, int, int);

int func_001F2B70(int a0, int a1, int a2, int a3) {
    MotionNode_BaseCtor(a0, 3, a3);
    *(int*)((char*)a0) = (int)D_004DFBB0;
    *(int*)((char*)a0 + 32) = a1;
    func_001F3070((a0 + 36));
    func_001F2BE0(a2, (a0 + 36));
    return a0;
}
