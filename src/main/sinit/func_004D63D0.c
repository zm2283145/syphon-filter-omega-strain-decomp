#include "types.h"
extern char D_00493910[], D_00493880[], D_00493878[], D_00493890[], D_00493898[];
extern char D_00493938, D_00493940;
extern char D_0055A180[];
extern int D_0055A188, D_0055A190, D_0055A198, D_0055A1A0, D_0055A1A8, D_0055A1B0;
extern int D_0055A1B8, D_0055A1C0, D_0055A1C8, D_0055A1D0;
extern char* D_0055A1D8;
extern int D_004BDD00;
extern char Script_PerformAction[], Script_PerformAction_2[], Script_PerformAction_3[];
extern char Script_PerformAction_WithObject[], Script_PerformAction_WithObject_2[];
extern char Script_PerformAction_WithObject_3[], Script_PerformAction_WithObject_4[];
extern char Script_StopPerformingAction[];
extern int ScriptEnum_Register();
extern int Script_RegisterVariable();
extern int Script_RegisterNative_2();
extern int cGOBJ_GetScriptTypeKeyPtr();
extern int cSystem_GetScriptTypeKeyPtr();

void func_004D63D0(void)
{
    *(int*)D_0055A180 = ScriptEnum_Register("nCAS::eAction", D_00493910, 3);
    D_0055A188 = Script_RegisterVariable("PerformActionOnceThrough", (int)&D_00493938, D_00493890);
    D_0055A190 = Script_RegisterVariable("PerformActionForever", (int)&D_00493940, D_00493890);
    D_0055A198 = Script_RegisterNative_2(Script_PerformAction, D_00493880, "PerformAction", 2, cSystem_GetScriptTypeKeyPtr(), D_0055A180);
    D_0055A1A0 = Script_RegisterNative_2(Script_PerformAction_2, D_00493880, "PerformAction", 3, cSystem_GetScriptTypeKeyPtr(), D_0055A180, D_00493898);
    D_0055A1A8 = Script_RegisterNative_2(Script_PerformAction_3, D_00493880, "PerformAction", 4, cSystem_GetScriptTypeKeyPtr(), D_0055A180, D_00493898, D_00493890);
    D_0055A1B0 = Script_RegisterNative_2(Script_PerformAction_WithObject, D_00493880, "PerformAction_WithObject", 3, cSystem_GetScriptTypeKeyPtr(), D_0055A180, cGOBJ_GetScriptTypeKeyPtr());
    D_0055A1B8 = Script_RegisterNative_2(Script_PerformAction_WithObject_2, D_00493880, "PerformAction_WithObject", 4, cSystem_GetScriptTypeKeyPtr(), D_0055A180, cGOBJ_GetScriptTypeKeyPtr(), D_00493898);
    D_0055A1C0 = Script_RegisterNative_2(Script_PerformAction_WithObject_3, D_00493880, "PerformAction_WithObject", 5, cSystem_GetScriptTypeKeyPtr(), D_0055A180, cGOBJ_GetScriptTypeKeyPtr(), D_00493898, D_00493890);
    D_0055A1C8 = Script_RegisterNative_2(Script_PerformAction_WithObject_4, D_00493880, "PerformAction_WithObject", 6, cSystem_GetScriptTypeKeyPtr(), D_0055A180, cGOBJ_GetScriptTypeKeyPtr(), D_00493898, D_00493890, D_00493878);
    D_0055A1D0 = Script_RegisterNative_2(Script_StopPerformingAction, D_00493880, "StopPerformingAction", 1, cSystem_GetScriptTypeKeyPtr());
    D_0055A1D8 = "MSGGAME_CAS_EVENT";
    D_004BDD00 = -1;
}
