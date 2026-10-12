#include "types.h"
extern char D_004F80F0[];
extern char func_00261080[];
extern char D_004F8190[];
extern char D_0048B0A0[];
extern char D_00493890[];
extern int D_004F8238;
extern char D_0048B0A8[];
extern int D_004F8240;
extern char Script_SetLockColor[];
extern char D_00493880[];
extern char D_00493888[];
extern int D_004F8248;
extern char Script_SetNVLockColor[];
extern int D_004F8250;
extern int __construct_array();
extern int Script_RegisterVariable();
extern int Script_RegisterNative_2();
void func_004D05E0(void)
{
    __construct_array(D_004F80F0, func_00261080, 0, 0x10, 0xa);
    __construct_array(D_004F8190, func_00261080, 0, 0x10, 0xa);
    D_004F8238 = Script_RegisterVariable("lockAlpha", (int)D_0048B0A0, D_00493890);
    D_004F8240 = Script_RegisterVariable("NVlockAlpha", (int)D_0048B0A8, D_00493890);
    D_004F8248 = Script_RegisterNative_2(Script_SetLockColor, D_00493880, "SetLockColor", 5, D_00493888, D_00493890, D_00493888, D_00493888, D_00493888);
    D_004F8250 = Script_RegisterNative_2(Script_SetNVLockColor, D_00493880, "SetNVLockColor", 5, D_00493888, D_00493890, D_00493888, D_00493888, D_00493888);
}
