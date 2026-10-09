/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void func_00272280(int);
extern int func_003EEBE0(int, int, int);

int func_00271CD0(int a0) {
    int tmp0;
    int tmp3;
    int tmp6;
    int tmp9;
    int tmp12;
    int tmp15;
    int tmp18;
    int tmp21;
    int tmp24;
    int tmp27;
    int tmp30;
    int tmp33;
    int tmp36;
    int tmp39;
    int tmp42;
    int tmp43;
    int tmp44;

    tmp0 = *(int*)((char*)a0 + 4);
    func_00272280(tmp0);
    tmp3 = *(int*)((char*)a0 + 8);
    func_00272280(tmp3);
    tmp6 = *(int*)((char*)a0 + 12);
    func_00272280(tmp6);
    tmp9 = *(int*)((char*)a0 + 16);
    func_00272280(tmp9);
    tmp12 = *(int*)((char*)a0 + 20);
    func_00272280(tmp12);
    tmp15 = *(int*)((char*)a0 + 24);
    func_00272280(tmp15);
    tmp18 = *(int*)((char*)a0 + 28);
    func_00272280(tmp18);
    tmp21 = *(int*)((char*)a0 + 32);
    func_00272280(tmp21);
    tmp24 = *(int*)((char*)a0 + 36);
    func_00272280(tmp24);
    tmp27 = *(int*)((char*)a0 + 40);
    func_00272280(tmp27);
    tmp30 = *(int*)((char*)a0 + 44);
    func_00272280(tmp30);
    tmp33 = *(int*)((char*)a0 + 48);
    func_00272280(tmp33);
    tmp36 = *(int*)((char*)a0 + 52);
    func_00272280(tmp36);
    tmp39 = *(int*)((char*)a0 + 56);
    func_00272280(tmp39);
    tmp42 = *(int*)(char*)a0;
    tmp43 = *(int*)(char*)tmp42;
    tmp44 = func_003EEBE0(tmp43, 0, 1);
    return tmp44;
}
