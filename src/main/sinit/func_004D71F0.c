#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
extern int D_004BF3C0;
extern int D_004BF3C4;
extern int D_004BF3C8;
extern int D_004BF3CC;
extern char D_004E0BE0;
extern char **D_00572118;
extern char *D_00572120;
extern char **D_00572124;
extern char *D_00572128;

void StaticInit_GuiWidgetFactory(void) {
    D_004BF3C0 = 0x3F800000;
    D_00572128 = &D_004E0BE0;
    D_00572120 = "GuiWidget";
    D_004BF3C4 = 0x3F800000;
    D_004BF3C8 = 0x3F800000;
    D_004BF3CC = 0x3F800000;
    D_00572124 = D_00572118;
    D_00572118 = &D_00572120;
}
