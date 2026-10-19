#include "types.h"
extern int D_0049CE18;
extern int D_004EE908, D_004EE910, D_004EE918, D_004EE920, D_004EE928;
extern char* D_004EE930;
extern char D_004EE938;
extern int D_004EE940, D_004EE948, D_004EE950, D_004EE958;
extern char D_00493880;
extern signed char D_004EA0C8;
extern char* g_LosCheckService;
extern int Script_RegisterType(char*, void*, int, int);
extern int Script_RegisterNative(int, void*, void*, char*, int, int*);
extern int NetMsgTable_Add(void*, void*, char*);
extern void* cGOBJ_GetScriptTypeKeyPtr(void);
extern void ScriptType_cGameCamera_Init();
extern void cHumanSeenMsg_NetReceive();
extern void ScriptType_cHumanSeenMsg_Init();
extern void Script_cGameCamera_PushCurrent();
extern void Script_cGameCamera_PopCurrent();
extern void Script_cGameCamera_RemoveCamera();
extern void Script_cHumanSeenMsg_Who();
void StaticInit_RegisterGameCamera(void) {
    char* s;
    D_0049CE18 = 0x3F2B851F;
    D_004EE908 = Script_RegisterType("cGameCamera", ScriptType_cGameCamera_Init, 0, 1);
    D_004EE910 = D_004EE908;
    D_004EE918 = Script_RegisterNative(D_004EE908, Script_cGameCamera_PushCurrent, &D_00493880, "PushCurrent", 1, &D_004EE908);
    D_004EE920 = Script_RegisterNative(D_004EE908, Script_cGameCamera_PopCurrent, &D_00493880, "PopCurrent", 1, &D_004EE908);
    D_004EE928 = Script_RegisterNative(D_004EE908, Script_cGameCamera_RemoveCamera, &D_00493880, "RemoveCamera", 1, &D_004EE908);
    s = "cHumanSeenMsg";
    D_004EE930 = s;
    D_004EE940 = NetMsgTable_Add(cHumanSeenMsg_NetReceive, &D_004EE938, s);
    D_004EE948 = Script_RegisterType("cHumanSeenMsg", ScriptType_cHumanSeenMsg_Init, 1, 0);
    D_004EE950 = D_004EE948;
    D_004EE958 = Script_RegisterNative(D_004EE948, Script_cHumanSeenMsg_Who, cGOBJ_GetScriptTypeKeyPtr(), "Who", 1, &D_004EE948);
    if (!D_004EA0C8) {
        g_LosCheckService = "LOS Manager";
        D_004EA0C8 = 1;
    }
}
