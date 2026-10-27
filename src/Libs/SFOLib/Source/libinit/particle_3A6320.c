/*
 * main/particle: 2 files, 003A6320-003A6390
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003A6320 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"

/* Deleting destructor: own cleanup, then the base destructor. */
extern "C" void operator_delete(void* allocation);
extern "C" void cSkeletonDataBank_Clear(void* self);
extern "C" void* std_list_cSkeletonDataBankEntryPtr_dtor(void* self, short deleteFlag);

extern "C" void* cSkeletonDataBank_dtor(void* self, short deleteFlag)
{
    if (self) {
        cSkeletonDataBank_Clear(self);
        if (self)
            std_list_cSkeletonDataBankEntryPtr_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003A6320 */

/* merge_units: begin func_003A6390 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int CreateSema(char *);
int CreateThread(char *);
int StartThread(int, int);
int GetThreadId();
int sceSifSearchModuleByName(char *);
int sceCdPOffCallback(char *, int);
extern int D_004934C8;
extern int D_004934D0;
extern int D_004934D8;
extern char D_0053BBC0;
extern char func_003A6450;
extern char SFOPowerOffThread;

void SFOPreparePowerOff(void) {
    struct { int f10; int f14; int f18[3]; int f24[3]; int f30; char * f34; char * f38; int f3C; int f40; int f44[7]; } sl;

    if (sceSifSearchModuleByName("dev9") >= 0) {
        sl.f14 = 1;
        sl.f18[0] = 0;
        sl.f24[0] = 0;
        D_004934D8 = CreateSema(&sl.f10);
        D_004934C8 = GetThreadId();
        sl.f40 = 0;
        sl.f3C = 0x2000;
        sl.f34 = &SFOPowerOffThread;
        sl.f38 = &D_0053BBC0;
        sl.f44[0] = 1;
        D_004934D0 = CreateThread(&sl.f30);
        StartThread(D_004934D0, D_004934D8);
        sceCdPOffCallback(&func_003A6450, D_004934D8);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003A6390 */
