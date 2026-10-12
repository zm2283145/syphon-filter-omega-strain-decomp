#include "types.h"
int Script_RegisterVariable();
extern char D_0048B2D0;
extern char D_0048B2D8;
extern char D_0048B2E0;
extern char D_0048B2E8;
extern char D_00493888;
extern char D_00493890;
extern int D_004FFB18;
extern int D_004FFB20;
extern int D_004FFB28;
extern int D_004FFB30;
void func_004D1E20(void) {
    D_004FFB18 = Script_RegisterVariable("TremorCamFactor", (int)&D_0048B2D0, &D_00493890);
    D_004FFB20 = Script_RegisterVariable("TremorMinRumble", (int)&D_0048B2D8, &D_00493888);
    D_004FFB28 = Script_RegisterVariable("TremorMaxRumble", (int)&D_0048B2E0, &D_00493888);
    D_004FFB30 = Script_RegisterVariable("TremorRandPct", (int)&D_0048B2E8, &D_00493890);
}
