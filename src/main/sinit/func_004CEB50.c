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
extern char ScriptType_TargSettings_Init[];
extern char Script_SetRadarBlip[];
extern char Script_SetRadarBlip_2[];
extern char Script_ClearRadarBlip[];
extern char Script_SetWaypoint[];
extern char TargetVisMgr_dtor[];
extern int __register_global_object();
extern int cGOBJ_GetScriptTypeKeyPtr();
extern int Script_RegisterNative_2();
extern int Script_RegisterType();
extern int Script_RegisterVariable();
extern int* func_0022C640();
extern int TargetVisMgr_ctor();
void StaticInit_RegisterTargetManager(void)
{
    D_004F77A8 = D_004A65E8;
    TargetVisMgr_ctor(g_TargetVisMgr);
    __register_global_object(g_TargetVisMgr, TargetVisMgr_dtor, D_004F77B0);
    D_004F78E8 = Script_RegisterType(D_004A65F8, ScriptType_TargSettings_Init, 0, 0);
    D_004F78F0 = *func_0022C640();
    D_004F78F8 = Script_RegisterVariable(D_004A6608, (int)D_0048AC60, func_0022C640());
    D_004F7900 = Script_RegisterVariable(D_004A6618, (int)D_0048AC68, D_00493888);
    D_004F7908 = Script_RegisterNative_2(Script_SetRadarBlip, D_00493880, D_004A6628, 1, cGOBJ_GetScriptTypeKeyPtr());
    D_004F7910 = Script_RegisterNative_2(Script_SetRadarBlip_2, D_00493880, D_004A6628, 2, cGOBJ_GetScriptTypeKeyPtr(), D_00493890);
    D_004F7918 = Script_RegisterNative_2(Script_ClearRadarBlip, D_00493880, D_004A6638, 1, cGOBJ_GetScriptTypeKeyPtr());
    D_004F7920 = Script_RegisterNative_2(Script_SetWaypoint, D_00493880, D_004A6648, 1, cGOBJ_GetScriptTypeKeyPtr());
    D_004F7928 = Script_RegisterVariable(D_004A6658, (int)D_0048AC70, D_00493878);
    if (!D_004EA0C8) {
        g_LosCheckService = D_004A6668;
        D_004EA0C8 = 1;
    }
}
