/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int Component_BaseInit(int);
extern char D_004D9CF0[];
extern int InputState_Ctor(int);

int PlayerComponent_Construct(int a0) {
    Component_BaseInit(a0);
    *(int*)((char*)a0) = (int)D_004D9CF0;
    InputState_Ctor((a0 + 80));
    *(int*)((char*)a0 + 416) = 0;
    *(int*)((char*)a0 + 448) = 0;
    *(int*)((char*)a0 + 436) = 0;
    *(int*)((char*)a0 + 432) = 0;
    *(int*)((char*)a0 + 424) = 0;
    *(int*)((char*)a0 + 428) = 0;
    *(char*)((char*)a0 + 444) = 0;
    *(int*)((char*)a0 + 440) = -1;
    *(int*)((char*)a0 + 420) = 0;
    return a0;
}
