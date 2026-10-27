#include "types.h"
extern void AbstractWidgetClassRep_AddClassRep(void*);
extern char D_004C2460;
extern char D_004E1790;
extern char D_004E17A0;
extern void* D_00586230;
extern void* D_00586238;
extern void* D_00586240;
extern void* D_00586248;
void StaticInit_GuiEndGameAwards(void) {
    D_00586238 = &D_004E17A0;
    D_00586230 = "GuiEndGameAwards";
    AbstractWidgetClassRep_AddClassRep(&D_00586230);
    D_00586248 = &D_004E1790;
    D_00586240 = &D_004C2460;
    AbstractWidgetClassRep_AddClassRep(&D_00586240);
}
