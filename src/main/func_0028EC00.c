/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0055DDA0[];
extern int func_00403310(int);
extern void func_0040F540(void);
extern int func_004147A0(void);
extern int func_0041EBF0(int);
extern int func_0041F090(int);

int func_0028EC00(int a0) {
    int tmp4;

    func_00403310((int)D_0055DDA0);
    func_0040F540();
    tmp4 = func_0041F090(a0);
    return tmp4;
}

int func_0028EC40(int a0) {
    int tmp2;
    int tmp4;

    func_0041EBF0(a0);
    tmp2 = func_004147A0();
    tmp4 = *(int*)((char*)tmp2 + 104);
    *(int*)((char*)tmp2 + 104) = (tmp4 & -13);
    return tmp2;
}
