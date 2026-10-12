#include "types.h"
int cGOBJ_GetScriptTypeKeyPtr();
int Script_RegisterNative();
int Script_RegisterType();
int Script_cDamageMsg_Type();
int Script_cDamageMsg_Where();
int Script_cDamageMsg_Attacker();
int Script_cDamageMsg_Damage();
int ScriptType_cDamageMsg_Init();
extern char D_00493888;
extern void* g_MsgLibDamageRequestKey;
extern int D_00571700;
extern int D_00571708;
extern int D_00571710;
extern int D_00571718;
extern int D_00571720;
extern int D_00571728;
extern char D_00583918;
extern char D_00583920;
void func_004D6E30(void) {
    g_MsgLibDamageRequestKey = "MSGLIB_DAMAGE_REQUEST";
    D_00571700 = Script_RegisterType("cDamageMsg", ScriptType_cDamageMsg_Init, 1, 0);
    D_00571708 = D_00571700;
    D_00571710 = Script_RegisterNative(D_00571700, Script_cDamageMsg_Damage, &D_00493888, "Damage", 1, &D_00571700);
    D_00571718 = Script_RegisterNative(D_00571700, Script_cDamageMsg_Attacker, cGOBJ_GetScriptTypeKeyPtr(), "Attacker", 1, &D_00571700);
    D_00571720 = Script_RegisterNative(D_00571700, Script_cDamageMsg_Where, &D_00583920, "Where", 1, &D_00571700);
    D_00571728 = Script_RegisterNative(D_00571700, Script_cDamageMsg_Type, &D_00583918, "Type", 1, &D_00571700);
}
