#include "types.h"
extern char D_00489C10, MaxNpcAmmoPct, D_00489C20, g_DoKnifeDmg;
extern char D_00489D00[];
extern char D_00493890[], D_00493880[], D_00493888[], D_00493878[];
extern char Script_ReloadWeapons[], ScriptType_cOutOfAmmoMsg_Init[], Script_cOutOfAmmoMsg_Weapon[];
extern int D_004EA128, D_004EA130, D_004EA138, D_004EA148, D_004EA158, D_004EA160, D_004EA168;
extern int D_004EA170, D_004EA178;
extern char* g_OutOfAmmoMsgClass;
extern char* g_LosCheckService;
extern signed char D_004EA0C8;
extern int cScriptBase_registerGlobalVar();
extern int cScriptBase_registerFunc_intPintPint_intP_charP_int_etc();
extern int cScriptBase_registerFunc_int_intPintPint_intP_charP_etc();
extern int cScriptBase_addClass();
extern int cScriptBase_registerEnum();
extern int* func_001450C0(void);

void StaticInit_weapon(void)
{
    D_004EA128 = cScriptBase_registerGlobalVar("dmgAdjust", (int)&D_00489C10, D_00493890);
    D_004EA130 = cScriptBase_registerGlobalVar("MinNpcAmmoPct", (int)&MaxNpcAmmoPct, D_00493890);
    D_004EA138 = cScriptBase_registerGlobalVar("MaxNpcAmmoPct", (int)&D_00489C20, D_00493890);
    D_004EA148 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_ReloadWeapons, D_00493880, "ReloadWeapons", 0);
    g_OutOfAmmoMsgClass = "Out Of Ammo";
    D_004EA158 = cScriptBase_addClass("cOutOfAmmoMsg", ScriptType_cOutOfAmmoMsg_Init, 1, 0);
    D_004EA160 = *func_001450C0();
    D_004EA168 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(*func_001450C0(), Script_cOutOfAmmoMsg_Weapon, D_00493888, "Weapon", 1, func_001450C0());
    D_004EA170 = cScriptBase_registerEnum("cWeapon::eWpnSlot", D_00489D00, 8);
    D_004EA178 = cScriptBase_registerGlobalVar("doKnifeDmg", (int)&g_DoKnifeDmg, D_00493878);
    if (!D_004EA0C8) {
        g_LosCheckService = "LOS Manager";
        D_004EA0C8 = 1;
    }
}
