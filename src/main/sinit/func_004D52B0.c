#include "types.h"
int __register_global_object();
int Script_SetTexture();
int Script_DecTexture();
int Script_IncTexture();
int func_0037F8D0();
int func_0037F9D0();
int Script_RegisterNative_2();
extern char D_00493880;
extern char D_00493888;
extern char D_00493898;
extern char D_005381E0;
extern char D_005381F0;
extern int D_00539310;
extern int D_00539318;
extern int D_00539320;
void func_004D52B0(void) {
    func_0037F9D0(&D_005381F0);
    __register_global_object(&D_005381F0, func_0037F8D0, &D_005381E0);
    D_00539310 = Script_RegisterNative_2(Script_IncTexture, &D_00493880, "IncTexture", 1, &D_00493898);
    D_00539318 = Script_RegisterNative_2(Script_DecTexture, &D_00493880, "DecTexture", 1, &D_00493898);
    D_00539320 = Script_RegisterNative_2(Script_SetTexture, &D_00493880, "SetTexture", 2, &D_00493898, &D_00493888);
}
