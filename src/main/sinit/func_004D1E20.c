#include "types.h"
int func_003D8A30();
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
    D_004FFB18 = func_003D8A30("TremorCamFactor", (int)&D_0048B2D0, &D_00493890);
    D_004FFB20 = func_003D8A30("TremorMinRumble", (int)&D_0048B2D8, &D_00493888);
    D_004FFB28 = func_003D8A30("TremorMaxRumble", (int)&D_0048B2E0, &D_00493888);
    D_004FFB30 = func_003D8A30("TremorRandPct", (int)&D_0048B2E8, &D_00493890);
}
