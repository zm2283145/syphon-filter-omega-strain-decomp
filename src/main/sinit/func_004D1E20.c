#include "types.h"
int cScriptBase_registerGlobalVar();
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
void StaticInit_tremor(void) {
    D_004FFB18 = cScriptBase_registerGlobalVar("TremorCamFactor", (int)&D_0048B2D0, &D_00493890);
    D_004FFB20 = cScriptBase_registerGlobalVar("TremorMinRumble", (int)&D_0048B2D8, &D_00493888);
    D_004FFB28 = cScriptBase_registerGlobalVar("TremorMaxRumble", (int)&D_0048B2E0, &D_00493888);
    D_004FFB30 = cScriptBase_registerGlobalVar("TremorRandPct", (int)&D_0048B2E8, &D_00493890);
}
