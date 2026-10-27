#include "types.h"
extern int D_0049CE18;
extern int D_004EE908, D_004EE910, D_004EE918, D_004EE920, D_004EE928;
extern char* D_004EE930;
extern char D_004EE938;
extern int D_004EE940, D_004EE948, D_004EE950, D_004EE958;
extern char D_00493880;
extern signed char D_004EA0C8;
extern char* g_LosCheckService;
extern int cScriptBase_addClass(char*, void*, int, int);
extern int cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(int, void*, void*, char*, int, int*);
extern int cNetMsg_RegisterMsg(void*, void*, char*);
extern void* cGOBJ_SOBJ_getClassId(void);
extern void cGameCamera_SOBJ_init();
extern void cHumanSeenMsg_NetReceive();
extern void cHumanSeenMsg_SOBJ_init();
extern void Script_cGameCamera_PushCurrent();
extern void Script_cGameCamera_PopCurrent();
extern void Script_cGameCamera_RemoveCamera();
extern void Script_cHumanSeenMsg_Who();
void StaticInit_gameCamera(void) {
    char* s;
    D_0049CE18 = 0x3F2B851F;
    D_004EE908 = cScriptBase_addClass("cGameCamera", cGameCamera_SOBJ_init, 0, 1);
    D_004EE910 = D_004EE908;
    D_004EE918 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(D_004EE908, Script_cGameCamera_PushCurrent, &D_00493880, "PushCurrent", 1, &D_004EE908);
    D_004EE920 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(D_004EE908, Script_cGameCamera_PopCurrent, &D_00493880, "PopCurrent", 1, &D_004EE908);
    D_004EE928 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(D_004EE908, Script_cGameCamera_RemoveCamera, &D_00493880, "RemoveCamera", 1, &D_004EE908);
    s = "cHumanSeenMsg";
    D_004EE930 = s;
    D_004EE940 = cNetMsg_RegisterMsg(cHumanSeenMsg_NetReceive, &D_004EE938, s);
    D_004EE948 = cScriptBase_addClass("cHumanSeenMsg", cHumanSeenMsg_SOBJ_init, 1, 0);
    D_004EE950 = D_004EE948;
    D_004EE958 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(D_004EE948, Script_cHumanSeenMsg_Who, cGOBJ_SOBJ_getClassId(), "Who", 1, &D_004EE948);
    if (!D_004EA0C8) {
        g_LosCheckService = "LOS Manager";
        D_004EA0C8 = 1;
    }
}
