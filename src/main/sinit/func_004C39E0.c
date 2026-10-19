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
extern int Script_RegisterVariable();
extern int Script_RegisterNative_2();
extern int Script_RegisterNative();
extern int Script_RegisterType();
extern int ScriptEnum_Register();
extern int* func_001450C0(void);

void func_004C39E0(void)
{
    D_004EA128 = Script_RegisterVariable("dmgAdjust", (int)&D_00489C10, D_00493890);
    D_004EA130 = Script_RegisterVariable("MinNpcAmmoPct", (int)&MaxNpcAmmoPct, D_00493890);
    D_004EA138 = Script_RegisterVariable("MaxNpcAmmoPct", (int)&D_00489C20, D_00493890);
    D_004EA148 = Script_RegisterNative_2(Script_ReloadWeapons, D_00493880, "ReloadWeapons", 0);
    g_OutOfAmmoMsgClass = "Out Of Ammo";
    D_004EA158 = Script_RegisterType("cOutOfAmmoMsg", ScriptType_cOutOfAmmoMsg_Init, 1, 0);
    D_004EA160 = *func_001450C0();
    D_004EA168 = Script_RegisterNative(*func_001450C0(), Script_cOutOfAmmoMsg_Weapon, D_00493888, "Weapon", 1, func_001450C0());
    D_004EA170 = ScriptEnum_Register("cWeapon::eWpnSlot", D_00489D00, 8);
    D_004EA178 = Script_RegisterVariable("doKnifeDmg", (int)&g_DoKnifeDmg, D_00493878);
    if (!D_004EA0C8) {
        g_LosCheckService = "LOS Manager";
        D_004EA0C8 = 1;
    }
}
