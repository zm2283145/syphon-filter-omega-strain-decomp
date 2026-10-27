#include "types.h"
int cScriptBase_registerGlobalVar();
extern char D_0048B0B0;
extern char D_0048B0B8;
extern char D_0048B0C0;
extern char D_0048B0C8;
extern char D_0048B0D0;
extern char D_00493888;
extern char D_00493890;
extern char D_004F8260;
extern int D_004F8268;
extern int D_004F8270;
extern int D_004F8278;
extern int D_004F8280;
extern int D_004F8288;
extern int D_004F8290;
extern int D_004F82A0;
void StaticInit_hud_radar(void) {
    D_004F8268 = cScriptBase_registerGlobalVar("dangerFirstFrame", (int)&D_004F8260, &D_00493888);
    D_004F8270 = cScriptBase_registerGlobalVar("dangerLastFrame", (int)&D_0048B0B0, &D_00493888);
    D_004F8278 = cScriptBase_registerGlobalVar("dangerDimFrame", (int)&D_0048B0B8, &D_00493888);
    D_004F8280 = cScriptBase_registerGlobalVar("RadarPixWid", (int)&D_0048B0C0, &D_00493888);
    D_004F8288 = cScriptBase_registerGlobalVar("RadarMaxDist", (int)&D_0048B0C8, &D_00493890);
    D_004F8290 = cScriptBase_registerGlobalVar("RadarMaxScale", (int)&D_0048B0D0, &D_00493890);
    D_004F82A0 = -1;
}
