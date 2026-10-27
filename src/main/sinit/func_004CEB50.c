#include "types.h"
extern char D_004A65E8[];
extern char D_004A65F8[];
extern char D_004A6608[];
extern char D_004A6618[];
extern char D_004A6628[];
extern char D_004A6638[];
extern char D_004A6648[];
extern char D_004A6658[];
extern char D_004A6668[];
extern char D_0048AC60[];
extern char D_0048AC68[];
extern char D_0048AC70[];
extern char D_00493878[];
extern char D_00493880[];
extern char D_00493888[];
extern char D_00493890[];
extern char* D_004F77A8;
extern char D_004F77B0[];
extern char g_TargetVisMgr[];
extern char* g_LosCheckService;
extern signed char D_004EA0C8;
extern int D_004F78E8;
extern int D_004F78F0;
extern int D_004F78F8;
extern int D_004F7900;
extern int D_004F7908;
extern int D_004F7910;
extern int D_004F7918;
extern int D_004F7920;
extern int D_004F7928;
extern char TargSettings_SOBJ_init[];
extern char Script_SetRadarBlip[];
extern char Script_SetRadarBlip_2[];
extern char Script_ClearRadarBlip[];
extern char Script_SetWaypoint[];
extern char cTargetManager_dtor[];
extern int __register_global_object();
extern int cGOBJ_SOBJ_getClassId();
extern int cScriptBase_registerFunc_intPintPint_intP_charP_int_etc();
extern int cScriptBase_addClass();
extern int cScriptBase_registerGlobalVar();
extern int* TargSettings_SOBJ_getClassId();
extern int cTargetManager_ctor();
void StaticInit_targetManager(void)
{
    D_004F77A8 = D_004A65E8;
    cTargetManager_ctor(g_TargetVisMgr);
    __register_global_object(g_TargetVisMgr, cTargetManager_dtor, D_004F77B0);
    D_004F78E8 = cScriptBase_addClass(D_004A65F8, TargSettings_SOBJ_init, 0, 0);
    D_004F78F0 = *TargSettings_SOBJ_getClassId();
    D_004F78F8 = cScriptBase_registerGlobalVar(D_004A6608, (int)D_0048AC60, TargSettings_SOBJ_getClassId());
    D_004F7900 = cScriptBase_registerGlobalVar(D_004A6618, (int)D_0048AC68, D_00493888);
    D_004F7908 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_SetRadarBlip, D_00493880, D_004A6628, 1, cGOBJ_SOBJ_getClassId());
    D_004F7910 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_SetRadarBlip_2, D_00493880, D_004A6628, 2, cGOBJ_SOBJ_getClassId(), D_00493890);
    D_004F7918 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_ClearRadarBlip, D_00493880, D_004A6638, 1, cGOBJ_SOBJ_getClassId());
    D_004F7920 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_SetWaypoint, D_00493880, D_004A6648, 1, cGOBJ_SOBJ_getClassId());
    D_004F7928 = cScriptBase_registerGlobalVar(D_004A6658, (int)D_0048AC70, D_00493878);
    if (!D_004EA0C8) {
        g_LosCheckService = D_004A6668;
        D_004EA0C8 = 1;
    }
}
