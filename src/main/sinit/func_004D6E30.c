#include "types.h"
int cGOBJ_SOBJ_getClassId();
int cScriptBase_registerFunc_int_intPintPint_intP_charP_etc();
int cScriptBase_addClass();
int Script_cDamageMsg_Type();
int Script_cDamageMsg_Where();
int Script_cDamageMsg_Attacker();
int Script_cDamageMsg_Damage();
int cDamageMsg_SOBJ_init();
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
void StaticInit_DamageMsg(void) {
    g_MsgLibDamageRequestKey = "MSGLIB_DAMAGE_REQUEST";
    D_00571700 = cScriptBase_addClass("cDamageMsg", cDamageMsg_SOBJ_init, 1, 0);
    D_00571708 = D_00571700;
    D_00571710 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(D_00571700, Script_cDamageMsg_Damage, &D_00493888, "Damage", 1, &D_00571700);
    D_00571718 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(D_00571700, Script_cDamageMsg_Attacker, cGOBJ_SOBJ_getClassId(), "Attacker", 1, &D_00571700);
    D_00571720 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(D_00571700, Script_cDamageMsg_Where, &D_00583920, "Where", 1, &D_00571700);
    D_00571728 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(D_00571700, Script_cDamageMsg_Type, &D_00583918, "Type", 1, &D_00571700);
}
