#include "types.h"
int cNetMsg_RegisterMsg();
int cGOBJ_SOBJ_getClassId();
int cScriptBase_registerFunc_intPintPint_intP_charP_int_etc();
int Script_ActivateBodyToss_2();
int Script_ActivateBodyToss();
int func_004768E0();
extern char D_00493878;
extern char D_00493880;
extern void* D_00588038;
extern char D_00588040;
extern int D_00588048;
extern int D_00588050;
extern int D_00588058;
void StaticInit_RegisterActivateBodyToss(void) {
    D_00588038 = "cActivateBodyTossMsg";
    D_00588048 = cNetMsg_RegisterMsg(func_004768E0, &D_00588040, "cActivateBodyTossMsg");
    D_00588050 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_ActivateBodyToss, &D_00493880, "ActivateBodyToss", 1, cGOBJ_SOBJ_getClassId());
    D_00588058 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_ActivateBodyToss_2, &D_00493880, "ActivateBodyToss", 2, cGOBJ_SOBJ_getClassId(), &D_00493878);
}
