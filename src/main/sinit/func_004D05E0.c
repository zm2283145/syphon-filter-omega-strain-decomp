#include "types.h"
extern char D_004F80F0[];
extern char func_00261080[];
extern char D_004F8190[];
extern char D_004A8068[];
extern char D_0048B0A0[];
extern char D_00493890[];
extern int D_004F8238;
extern char D_004A8078[];
extern char D_0048B0A8[];
extern int D_004F8240;
extern char Script_SetLockColor[];
extern char D_00493880[];
extern char D_004A8088[];
extern char D_00493888[];
extern int D_004F8248;
extern char Script_SetNVLockColor[];
extern char D_004A8098[];
extern int D_004F8250;
extern int __construct_array();
extern int func_003D8A30();
extern int func_003D8740();
void func_004D05E0(void)
{
    __construct_array(D_004F80F0, func_00261080, 0, 0x10, 0xa);
    __construct_array(D_004F8190, func_00261080, 0, 0x10, 0xa);
    D_004F8238 = func_003D8A30(D_004A8068, (int)D_0048B0A0, D_00493890);
    D_004F8240 = func_003D8A30(D_004A8078, (int)D_0048B0A8, D_00493890);
    D_004F8248 = func_003D8740(Script_SetLockColor, D_00493880, D_004A8088, 5, D_00493888, D_00493890, D_00493888, D_00493888, D_00493888);
    D_004F8250 = func_003D8740(Script_SetNVLockColor, D_00493880, D_004A8098, 5, D_00493888, D_00493890, D_00493888, D_00493888, D_00493888);
}
