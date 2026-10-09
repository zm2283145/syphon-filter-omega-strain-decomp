/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004EE5D8[];
extern char D_004EE5E0[];
extern char D_00555070[];
extern int func_0022F170(void);
extern int func_0026ED30(void);
extern int func_0026ED70(void);
extern int func_0026EDF0(void);
extern int func_0026EE30(void);
extern int func_0026EEC0(void);
extern int func_0026EF10(void);
extern int func_0026EF50(void);
extern int func_0026EF90(void);
extern int func_0026F030(void);
extern int func_0026F080(void);
extern int func_0026F0B0(void);
extern int func_0026F0F0(void);
extern int func_003D9400(int, int);
extern void func_003D9440(int, int);
extern int ScriptFilter_Dispatch(int, int, int);

int func_0016AC20(void) {
    int tmp0;
    int tmp2;
    int tmp3;
    int tmp6;
    int tmp8;
    int tmp9;
    int tmp12;
    int tmp14;
    int tmp15;
    int tmp18;
    int tmp20;
    int tmp21;
    int tmp24;
    int tmp26;
    int tmp27;
    int tmp30;
    int tmp32;
    int tmp33;
    int tmp36;
    int tmp38;
    int tmp39;
    int tmp42;
    int tmp44;
    int tmp45;
    int tmp48;
    int tmp50;
    int tmp51;
    int tmp54;
    int tmp56;
    int tmp57;
    int tmp60;
    int tmp62;
    int tmp63;
    int tmp66;
    int tmp68;
    int tmp69;
    int tmp72;
    int tmp74;
    int tmp75;
    int tmp76;

    tmp0 = func_0022F170();
    tmp2 = *(int*)D_004EE5E0;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
    tmp6 = func_0026F0F0();
    tmp8 = *(int*)D_004EE5E0;
    tmp9 = *(int*)(char*)tmp6;
    func_003D9400(tmp8, tmp9);
    tmp12 = func_0026F0B0();
    tmp14 = *(int*)D_004EE5E0;
    tmp15 = *(int*)(char*)tmp12;
    func_003D9400(tmp14, tmp15);
    tmp18 = func_0026F080();
    tmp20 = *(int*)D_004EE5E0;
    tmp21 = *(int*)(char*)tmp18;
    func_003D9400(tmp20, tmp21);
    tmp24 = func_0026F030();
    tmp26 = *(int*)D_004EE5E0;
    tmp27 = *(int*)(char*)tmp24;
    func_003D9400(tmp26, tmp27);
    tmp30 = func_0026EF90();
    tmp32 = *(int*)D_004EE5E0;
    tmp33 = *(int*)(char*)tmp30;
    func_003D9400(tmp32, tmp33);
    tmp36 = func_0026EF50();
    tmp38 = *(int*)D_004EE5E0;
    tmp39 = *(int*)(char*)tmp36;
    func_003D9400(tmp38, tmp39);
    tmp42 = func_0026EF10();
    tmp44 = *(int*)D_004EE5E0;
    tmp45 = *(int*)(char*)tmp42;
    func_003D9400(tmp44, tmp45);
    tmp48 = func_0026EEC0();
    tmp50 = *(int*)D_004EE5E0;
    tmp51 = *(int*)(char*)tmp48;
    func_003D9400(tmp50, tmp51);
    tmp54 = func_0026EE30();
    tmp56 = *(int*)D_004EE5E0;
    tmp57 = *(int*)(char*)tmp54;
    func_003D9400(tmp56, tmp57);
    tmp60 = func_0026EDF0();
    tmp62 = *(int*)D_004EE5E0;
    tmp63 = *(int*)(char*)tmp60;
    func_003D9400(tmp62, tmp63);
    tmp66 = func_0026ED70();
    tmp68 = *(int*)D_004EE5E0;
    tmp69 = *(int*)(char*)tmp66;
    func_003D9400(tmp68, tmp69);
    tmp72 = func_0026ED30();
    tmp74 = *(int*)D_004EE5E0;
    tmp75 = *(int*)(char*)tmp72;
    tmp76 = func_003D9400(tmp74, tmp75);
    return tmp76;
}

int func_0016AD70(void) {
    return (int)D_004EE5D8;
}

int func_0016AD80(void) {
    int tmp0;

    tmp0 = *(int*)D_004EE5D8;
    return tmp0;
}

int func_0016AD90(int a0, int a1) {
    return ScriptFilter_Dispatch((int)D_00555070, a0, a1);
}
