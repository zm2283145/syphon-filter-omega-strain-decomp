#include "types.h"
int Script_SetPickupTextColor();
int Script_RegisterNative_2();
extern char D_00493880;
extern char D_00493888;
extern char D_00493890;
extern int g_PickupTextColour;
extern int D_004F7E74;
extern int D_004F7E78;
extern int D_004F7E7C;
extern int D_004F7E88;
void StaticInit_PickupTextColour(void) {
    g_PickupTextColour = 1050253722;
    D_004F7E74 = 1057803469;
    D_004F7E78 = 1061158912;
    D_004F7E7C = 1065353216;
    D_004F7E88 = Script_RegisterNative_2(Script_SetPickupTextColor, &D_00493880, "SetPickupTextColor", 4, &D_00493888, &D_00493888, &D_00493888, &D_00493890);
}
