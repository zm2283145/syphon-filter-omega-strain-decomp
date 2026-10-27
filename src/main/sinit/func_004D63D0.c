#include "types.h"
extern char D_00493910[], D_00493880[], D_00493878[], D_00493890[], D_00493898[];
extern char D_00493938, D_00493940;
extern char D_0055A180[];
extern int D_0055A188, D_0055A190, D_0055A198, D_0055A1A0, D_0055A1A8, D_0055A1B0;
extern int D_0055A1B8, D_0055A1C0, D_0055A1C8, D_0055A1D0;
extern char* g_CasEventMsgClass;
extern int g_NoneWord;
extern char Script_PerformAction[], Script_PerformAction_2[], Script_PerformAction_3[];
extern char Script_PerformAction_WithObject[], Script_PerformAction_WithObject_2[];
extern char Script_PerformAction_WithObject_3[], Script_PerformAction_WithObject_4[];
extern char Script_StopPerformingAction[];
extern int cScriptBase_registerEnum();
extern int cScriptBase_registerGlobalVar();
extern int cScriptBase_registerFunc_intPintPint_intP_charP_int_etc();
extern int cGOBJ_SOBJ_getClassId();
extern int cSystem_SOBJ_getClassId();

void StaticInit_character(void)
{
    *(int*)D_0055A180 = cScriptBase_registerEnum("nCAS::eAction", D_00493910, 3);
    D_0055A188 = cScriptBase_registerGlobalVar("PerformActionOnceThrough", (int)&D_00493938, D_00493890);
    D_0055A190 = cScriptBase_registerGlobalVar("PerformActionForever", (int)&D_00493940, D_00493890);
    D_0055A198 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_PerformAction, D_00493880, "PerformAction", 2, cSystem_SOBJ_getClassId(), D_0055A180);
    D_0055A1A0 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_PerformAction_2, D_00493880, "PerformAction", 3, cSystem_SOBJ_getClassId(), D_0055A180, D_00493898);
    D_0055A1A8 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_PerformAction_3, D_00493880, "PerformAction", 4, cSystem_SOBJ_getClassId(), D_0055A180, D_00493898, D_00493890);
    D_0055A1B0 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_PerformAction_WithObject, D_00493880, "PerformAction_WithObject", 3, cSystem_SOBJ_getClassId(), D_0055A180, cGOBJ_SOBJ_getClassId());
    D_0055A1B8 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_PerformAction_WithObject_2, D_00493880, "PerformAction_WithObject", 4, cSystem_SOBJ_getClassId(), D_0055A180, cGOBJ_SOBJ_getClassId(), D_00493898);
    D_0055A1C0 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_PerformAction_WithObject_3, D_00493880, "PerformAction_WithObject", 5, cSystem_SOBJ_getClassId(), D_0055A180, cGOBJ_SOBJ_getClassId(), D_00493898, D_00493890);
    D_0055A1C8 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_PerformAction_WithObject_4, D_00493880, "PerformAction_WithObject", 6, cSystem_SOBJ_getClassId(), D_0055A180, cGOBJ_SOBJ_getClassId(), D_00493898, D_00493890, D_00493878);
    D_0055A1D0 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_StopPerformingAction, D_00493880, "StopPerformingAction", 1, cSystem_SOBJ_getClassId());
    g_CasEventMsgClass = "MSGGAME_CAS_EVENT";
    g_NoneWord = -1;
}
