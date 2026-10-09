/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DA930[];
extern char D_00542B60[];
extern int Event_Construct(int, int);

float func_0018A2C0(char* self) {
    return *(float*)(self + 156);
}

float func_0018A2D0(char* self) {
    return *(float*)(self + 152);
}

void* func_0018A2E0(char* self) {
    return self + 76;
}

signed char func_0018A2F0(signed char* self) {
    return self[72];
}

int AnimEvent_Construct(int a0) {
    Event_Construct(a0, (int)D_00542B60);
    *(int*)((char*)a0) = (int)D_004DA930;
    *(int*)((char*)a0 + 36) = 0;
    *(char*)((char*)a0 + 40) = 0;
    *(int*)((char*)a0 + 44) = 0;
    *(char*)((char*)a0 + 48) = 0;
    *(int*)((char*)a0 + 52) = 0;
    return a0;
}

int func_0018A350(int a0, int a1) {
    *(float*)((char*)a0) = *(float*)(char*)a1;
    *(float*)((char*)a0 + 4) = *(float*)((char*)a1 + 4);
    *(float*)((char*)a0 + 8) = *(float*)((char*)a1 + 8);
    *(float*)((char*)a0 + 12) = *(float*)((char*)a1 + 12);
    return a0;
}
