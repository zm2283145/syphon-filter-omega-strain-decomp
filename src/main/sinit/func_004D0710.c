#include "types.h"
int func_003D8A30();
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
    D_004F8268 = func_003D8A30("dangerFirstFrame", (int)&D_004F8260, &D_00493888);
    D_004F8270 = func_003D8A30("dangerLastFrame", (int)&D_0048B0B0, &D_00493888);
    D_004F8278 = func_003D8A30("dangerDimFrame", (int)&D_0048B0B8, &D_00493888);
    D_004F8280 = func_003D8A30("RadarPixWid", (int)&D_0048B0C0, &D_00493888);
    D_004F8288 = func_003D8A30("RadarMaxDist", (int)&D_0048B0C8, &D_00493890);
    D_004F8290 = func_003D8A30("RadarMaxScale", (int)&D_0048B0D0, &D_00493890);
    D_004F82A0 = -1;
}
