#include "types.h"
extern void FreeList_Push(void*);
extern char D_004C2460;
extern char D_004E1790;
extern char D_004E17A0;
extern void* D_00586230;
extern void* D_00586238;
extern void* D_00586240;
extern void* D_00586248;
void StaticInit_GuiEndGameAwardsFactories(void) {
    D_00586238 = &D_004E17A0;
    D_00586230 = "GuiEndGameAwards";
    FreeList_Push(&D_00586230);
    D_00586248 = &D_004E1790;
    D_00586240 = &D_004C2460;
    FreeList_Push(&D_00586240);
}
