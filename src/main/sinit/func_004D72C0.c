#include "types.h"
extern void FreeList_Push(void*);
extern int D_004BF6B0;
extern int D_004BF6B4;
extern int D_004BF6B8;
extern int D_004BF6BC;
extern int D_004BF6C0;
extern int D_004BF6C4;
extern int D_004BF6C8;
extern int D_004BF6CC;
extern int D_004BF6D0;
extern int D_004BF6D4;
extern int D_004BF6D8;
extern int D_004BF6DC;
extern char D_004E0D98;
extern void* D_00572168;
extern void* D_00572170;
void func_004D72C0(void) {
    D_004BF6B4 = 0;
    D_004BF6B8 = 0;
    D_004BF6B0 = 1065353216;
    D_004BF6DC = 1056964608;
    D_00572170 = &D_004E0D98;
    D_00572168 = "GuiArrayWidget";
    D_004BF6BC = 1065353216;
    D_004BF6C0 = 1065353216;
    D_004BF6C4 = 1065353216;
    D_004BF6C8 = 0;
    D_004BF6CC = 1065353216;
    D_004BF6D8 = 1065353216;
    D_004BF6D0 = 0;
    D_004BF6D4 = 0;
    FreeList_Push(&D_00572168);
}
