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
extern "C" void Skel_FreeAll(void* self);
extern "C" void* func_003A62A0(void* self, short deleteFlag);

extern "C" void* func_003A6320(void* self, short deleteFlag)
{
    if (self) {
        Skel_FreeAll(self);
        if (self)
            func_003A62A0(self, 0);
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
int func_0010D050();
int sceSifSearchModuleByName(char *);
int func_00118870(char *, int);
extern int D_004934C8;
extern int D_004934D0;
extern int D_004934D8;
extern char D_0053BBC0;
extern char func_003A6450;
extern char func_003A6460;

void func_003A6390(void) {
    struct { int f10; int f14; int f18[3]; int f24[3]; int f30; char * f34; char * f38; int f3C; int f40; int f44[7]; } sl;

    if (sceSifSearchModuleByName("dev9") >= 0) {
        sl.f14 = 1;
        sl.f18[0] = 0;
        sl.f24[0] = 0;
        D_004934D8 = CreateSema(&sl.f10);
        D_004934C8 = func_0010D050();
        sl.f40 = 0;
        sl.f3C = 0x2000;
        sl.f34 = &func_003A6460;
        sl.f38 = &D_0053BBC0;
        sl.f44[0] = 1;
        D_004934D0 = CreateThread(&sl.f30);
        StartThread(D_004934D0, D_004934D8);
        func_00118870(&func_003A6450, D_004934D8);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003A6390 */
