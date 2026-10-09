/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void func_003A7310(void);
extern void func_003A7FE0(void);
extern void func_003A80F0(int);
extern int func_003A85E0(void);

void func_001C9670(int a0, int a1) {
    func_003A80F0(a1);
}

void func_001C9680(void) {
    int v0;
    int cond;

    func_003A7FE0();
    func_003A7310();
L001C9698:;
    v0 = func_003A85E0();
    cond = v0 != 0;
    if (cond) goto L001C9698;
    goto ret;
ret:;
}
