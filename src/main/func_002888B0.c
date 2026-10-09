/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FFB50[];
extern int func_001302F0(int);
extern int func_0041F150(int);

int* func_002888B0(PtrVec* v, int i) {
    return v->data + i;
}

Rel* func_002888C0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int func_002888E0(int a0) {
    int tmp2;

    func_0041F150(a0);
    tmp2 = func_001302F0((int)D_004FFB50);
    *(char*)((char*)a0 + 72) = ((unsigned int)(0) < (unsigned int)(tmp2));
    return tmp2;
}
