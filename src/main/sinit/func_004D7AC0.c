#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int FreeList_Push(char **);                              
extern char D_004C1AD8;
extern char D_004C1B00;
extern char D_004C1B68;
extern char D_004C1B90;
extern char D_004C1BB0;
extern char D_004E14F0;
extern char D_004E1500;
extern char D_004E1510;
extern char D_004E1520;
extern char D_004E1530;
extern char D_004E1540;
extern char *D_00586010;
extern char *D_00586018;
extern char *D_00586020;
extern char *D_00586028;
extern char *D_00586030;
extern char *D_00586038;
extern char *D_00586080;
extern char *D_00586088;
extern char *D_00586090;
extern char *D_00586098;
extern char *D_005860A0;
extern char *D_005860A8;

void StaticInit_GuiStartMenuFactories(void) {
    D_00586018 = &D_004E1540;
    D_00586010 = &D_004C1B00;
    FreeList_Push(&D_00586010);
    D_00586028 = &D_004E1530;
    D_00586020 = &D_004C1AD8;
    FreeList_Push(&D_00586020);
    D_00586038 = &D_004E1520;
    D_00586030 = &D_004C1B90;
    FreeList_Push(&D_00586030);
    D_00586088 = &D_004E1510;
    D_00586080 = "GuiWeaponStats";
    FreeList_Push(&D_00586080);
    D_00586098 = &D_004E1500;
    D_00586090 = &D_004C1BB0;
    FreeList_Push(&D_00586090);
    D_005860A8 = &D_004E14F0;
    D_005860A0 = &D_004C1B68;
    FreeList_Push(&D_005860A0);
}
