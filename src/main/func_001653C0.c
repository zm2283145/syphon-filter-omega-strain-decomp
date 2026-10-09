/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0055A278[];
extern int Global_SetInterfaceFont(int);
extern int func_001698C0(void);

int Script_SetInterfaceFont(int a0) {
    unsigned char tmp0;

    tmp0 = *(unsigned char*)(char*)a0;
    Global_SetInterfaceFont(tmp0);
    return 0;
}

int Global_SetInterfaceFont(int a0) {
    int tmp0;
    int tmp2;

    tmp0 = func_001698C0();
    tmp2 = *(int*)((char*)(((a0 & 255) << 2) + tmp0) + 640);
    *(int*)D_0055A278 = tmp2;
    return tmp0;
}
