#include "types.h"
int Script_RegisterVariable();
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
void func_004D0710(void) {
    D_004F8268 = Script_RegisterVariable("dangerFirstFrame", (int)&D_004F8260, &D_00493888);
    D_004F8270 = Script_RegisterVariable("dangerLastFrame", (int)&D_0048B0B0, &D_00493888);
    D_004F8278 = Script_RegisterVariable("dangerDimFrame", (int)&D_0048B0B8, &D_00493888);
    D_004F8280 = Script_RegisterVariable("RadarPixWid", (int)&D_0048B0C0, &D_00493888);
    D_004F8288 = Script_RegisterVariable("RadarMaxDist", (int)&D_0048B0C8, &D_00493890);
    D_004F8290 = Script_RegisterVariable("RadarMaxScale", (int)&D_0048B0D0, &D_00493890);
    D_004F82A0 = -1;
}
