#include "types.h"
int Script_SetLocation();
int cGOBJ_SOBJ_getClassId();
int cScriptBase_registerFunc_intPintPint_intP_charP_int_etc();
int AbstractWidgetClassRep_AddClassRep();
extern char D_00493880;
extern char D_00493898;
extern char D_004DDEC0;
extern void* D_00506608;
extern void* D_00506610;
extern int D_00506618;
void StaticInit_GuiQuickChat(void) {
    D_00506610 = &D_004DDEC0;
    D_00506608 = "GuiQuickChat";
    AbstractWidgetClassRep_AddClassRep(&D_00506608);
    D_00506618 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_SetLocation, &D_00493880, "SetLocation", 2, cGOBJ_SOBJ_getClassId(), &D_00493898);
}
