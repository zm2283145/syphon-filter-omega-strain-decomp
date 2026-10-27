#include "types.h"
extern char SpecFxTable[];
extern char tLoadRec_ctor[];
extern char Script_FogMyanmar[], Script_SmokeToronto3[], Script_RainTokyo[], Script_RainLorelei[];
extern char Script_SnowBelarus2[], Script_AtmosphericEffect[], Script_AtmosphericEffect_2[];
extern char Script_Wind[], Script_Shatter[], Script_SpawnParticle[], Script_SpawnLight[];
extern char D_00493880[], D_00493888[], D_00493890[];
extern char D_004A6C38[], D_004A6C58[], D_004A6C68[], D_004A6C78[];
extern char D_0048AD90[];
extern int D_004F7B98, D_004F7BA0, D_004F7BA8, D_004F7BB0, D_004F7BB8, D_004F7BC0, D_004F7BC8;
extern int D_004F7BD0, D_004F7BD8, D_004F7BE0, D_004F7BF8, D_004F7C10, D_004F7C18, D_004F7C20;
extern char* D_004F7BE8;
extern char* D_004F7C00;
extern char D_004F7BF0[], D_004F7C08[];
extern char cNetSpawnParticleMsg_NetReceive[], cNetSpawnLightMsg_NetReceive[];
extern signed char D_004EA0C8;
extern char* g_LosCheckService;
extern int __construct_array();
extern int cScriptBase_registerFunc_intPintPint_intP_charP_int_etc();
extern int cGOBJ_SOBJ_getClassId();
extern int cScriptBase_registerEnum();
extern int cNetMsg_RegisterMsg();
void StaticInit_SpecFxDefs(void)
{
    __construct_array(SpecFxTable, tLoadRec_ctor, 0, 8, 0x29);
    D_004F7B98 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_FogMyanmar, D_00493880, D_004A6C38, 0);
    D_004F7BA0 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_SmokeToronto3, D_00493880, "SmokeToronto3", 0);
    D_004F7BA8 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_RainTokyo, D_00493880, D_004A6C68, 0);
    D_004F7BB0 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_RainLorelei, D_00493880, D_004A6C78, 0);
    D_004F7BB8 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_SnowBelarus2, D_00493880, D_004A6C58, 0);
    D_004F7BC0 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_AtmosphericEffect, D_00493880, "AtmosphericEffect", 5, &D_004F7BE0, D_00493890, D_00493890, D_00493890, D_00493890);
    D_004F7BC8 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_AtmosphericEffect_2, D_00493880, "AtmosphericEffect", 6, &D_004F7BE0, D_00493890, D_00493890, D_00493890, D_00493890, D_00493888);
    D_004F7BD0 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_Wind, D_00493880, "Wind", 5, D_00493890, D_00493890, D_00493890, D_00493890, D_00493890);
    D_004F7BD8 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_Shatter, D_00493880, "Shatter", 2, cGOBJ_SOBJ_getClassId(), cGOBJ_SOBJ_getClassId());
    D_004F7BE0 = cScriptBase_registerEnum("eEffectName", D_0048AD90, 0xC);
    D_004F7BE8 = "cNetSpawnParticleMsg";
    D_004F7BF8 = cNetMsg_RegisterMsg(cNetSpawnParticleMsg_NetReceive, D_004F7BF0, "cNetSpawnParticleMsg");
    D_004F7C00 = "cNetSpawnLightMsg";
    D_004F7C10 = cNetMsg_RegisterMsg(cNetSpawnLightMsg_NetReceive, D_004F7C08, "cNetSpawnLightMsg");
    D_004F7C18 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_SpawnParticle, D_00493880, "SpawnParticle", 2, &D_004F7BE0, cGOBJ_SOBJ_getClassId());
    D_004F7C20 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_SpawnLight, D_00493880, "SpawnLight", 3, cGOBJ_SOBJ_getClassId(), D_00493890, D_00493890);
    if (!D_004EA0C8) {
        g_LosCheckService = "LOS Manager";
        D_004EA0C8 = 1;
    }
}
