#include "types.h"
typedef struct { int a, b, c; } Str_4C3700;
typedef struct { char pad[0xC]; void* c; void* d; void* e; } Obj_4C3700;
extern char D_004EA030[], D_004EA020[];
extern char DarknessDecreaser, NpcDarknessDecreaser, D_00489BC0;
extern char D_00493888[], D_00493880[], D_00493878[], D_00493890[], D_004938A0[];
extern char func_00130770[], func_0013BF60[], func_0012F0D0[];
extern char Script_SetScrollDelay[], Script_RequestLevelEnd[], Script_AddTremor[];
extern char Script_StartGlobalTimer[], Script_StartGlobalTimer_2[], Script_IsMultiplayer[];
extern char Script_ResetStats[], Script_ResetLevel[];
extern int D_004EA008, D_004EA010, D_004EA018, D_004EA058, D_004EA060, D_004EA068;
extern int D_004EA070, D_004EA078, D_004EA080, D_004EA088, D_004EA090, D_004EA0A8;
extern char* D_004EA098;
extern char* D_004EA0B0;
extern char D_004EA0A0[];
extern signed char D_004EA0C8;
extern int Script_RegisterVariable();
extern int Script_RegisterNative_2();
extern int cGOBJ_GetScriptTypeKeyPtr();
extern int func_002824D0();
extern void String_CtorCStr_13B480(Str_4C3700* s, const char* c);
extern void func_0013BCB0(void* o, Str_4C3700* s);
extern void* func_0013BE20(void);
extern void func_0013BD40(void* a, void* b, void* c);
extern void func_00138B70(void* s, int f);
extern void __register_global_object(void* obj, void* dtor, void* link);

void func_004C3700(void)
{
    D_004EA008 = Script_RegisterVariable("DarknessDecreaser", (int)&DarknessDecreaser, D_00493888);
    D_004EA010 = Script_RegisterVariable("NpcDarknessDecreaser", (int)&NpcDarknessDecreaser, D_00493888);
    D_004EA018 = Script_RegisterVariable("SendStatsTime", (int)&D_00489BC0, D_00493888);
    {
        Str_4C3700 tmp;
        Obj_4C3700* o = (Obj_4C3700*)D_004EA030;
        String_CtorCStr_13B480(&tmp, "RELOADSYS");
        func_0013BCB0(o, &tmp);
        func_0013BD40(func_0013BE20(), D_004EA030, D_004EA030);
        func_00138B70(&tmp, 0);
        o->c = "RELOADSYS";
        o->d = "The system you want to reload as a parameter.";
        o->e = func_00130770;
        __register_global_object(o, func_0013BF60, D_004EA020);
    }
    D_004EA058 = Script_RegisterNative_2(Script_SetScrollDelay, D_00493880, "SetScrollDelay", 1, D_00493890);
    D_004EA060 = Script_RegisterNative_2(Script_RequestLevelEnd, D_00493880, "RequestLevelEnd", 0);
    D_004EA068 = Script_RegisterNative_2(Script_AddTremor, D_00493880, "AddTremor", 4, cGOBJ_GetScriptTypeKeyPtr(), D_00493890, D_00493890, D_00493890);
    D_004EA070 = Script_RegisterNative_2(Script_StartGlobalTimer, D_00493880, "StartGlobalTimer", 1, D_00493890);
    D_004EA078 = Script_RegisterNative_2(Script_StartGlobalTimer_2, D_00493880, "StartGlobalTimer", 2, D_00493890, D_004938A0);
    D_004EA080 = Script_RegisterNative_2(Script_IsMultiplayer, D_00493878, "IsMultiplayer", 0);
    D_004EA088 = Script_RegisterNative_2(Script_ResetStats, D_00493880, "ResetStats", 0);
    D_004EA090 = Script_RegisterNative_2(Script_ResetLevel, D_00493880, "ResetLevel", 0);
    D_004EA098 = "cNetAgentUpdateMsg";
    D_004EA0A8 = func_002824D0(func_0012F0D0, D_004EA0A0, "cNetAgentUpdateMsg");
    if (!D_004EA0C8) {
        D_004EA0B0 = "LOS Manager";
        D_004EA0C8 = 1;
    }
}

