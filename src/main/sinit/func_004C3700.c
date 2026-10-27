#include "types.h"
typedef struct { int a, b, c; } Str_4C3700;
typedef struct { char pad[0xC]; void* c; void* d; void* e; } Obj_4C3700;
extern char D_004EA030[], D_004EA020[];
extern char DarknessDecreaser, NpcDarknessDecreaser, D_00489BC0;
extern char D_00493888[], D_00493880[], D_00493878[], D_00493890[], D_004938A0[];
extern char confunc_RELOADSYS[], cConsCommand_dtor[], cNetAgentUpdateMsg_NetReceive[];
extern char Script_SetScrollDelay[], Script_RequestLevelEnd[], Script_AddTremor[];
extern char Script_StartGlobalTimer[], Script_StartGlobalTimer_2[], Script_IsMultiplayer[];
extern char Script_ResetStats[], Script_ResetLevel[];
extern int D_004EA008, D_004EA010, D_004EA018, D_004EA058, D_004EA060, D_004EA068;
extern int D_004EA070, D_004EA078, D_004EA080, D_004EA088, D_004EA090, D_004EA0A8;
extern char* D_004EA098;
extern char* g_LosCheckService;
extern char D_004EA0A0[];
extern signed char D_004EA0C8;
extern int cScriptBase_registerGlobalVar();
extern int cScriptBase_registerFunc_intPintPint_intP_charP_int_etc();
extern int cGOBJ_SOBJ_getClassId();
extern int cNetMsg_RegisterMsg();
extern void std_basic_string_char_char_traits_char_ctor_charP(Str_4C3700* s, const char* c);
extern void std_basic_string_char_char_traits_char_ctor_basicstringR(void* o, Str_4C3700* s);
extern void* cKeyedAutoRegisterObject_cString_cConsCommand_GetNonConstRegistry(void);
extern void cKeyedRegistry_cString_cConsCommand_Register(void* a, void* b, void* c);
extern void String_Dtor(void* s, int f);
extern void __register_global_object(void* obj, void* dtor, void* link);

void StaticInit_game(void)
{
    D_004EA008 = cScriptBase_registerGlobalVar("DarknessDecreaser", (int)&DarknessDecreaser, D_00493888);
    D_004EA010 = cScriptBase_registerGlobalVar("NpcDarknessDecreaser", (int)&NpcDarknessDecreaser, D_00493888);
    D_004EA018 = cScriptBase_registerGlobalVar("SendStatsTime", (int)&D_00489BC0, D_00493888);
    {
        Str_4C3700 tmp;
        Obj_4C3700* o = (Obj_4C3700*)D_004EA030;
        std_basic_string_char_char_traits_char_ctor_charP(&tmp, "RELOADSYS");
        std_basic_string_char_char_traits_char_ctor_basicstringR(o, &tmp);
        cKeyedRegistry_cString_cConsCommand_Register(cKeyedAutoRegisterObject_cString_cConsCommand_GetNonConstRegistry(), D_004EA030, D_004EA030);
        String_Dtor(&tmp, 0);
        o->c = "RELOADSYS";
        o->d = "The system you want to reload as a parameter.";
        o->e = confunc_RELOADSYS;
        __register_global_object(o, cConsCommand_dtor, D_004EA020);
    }
    D_004EA058 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_SetScrollDelay, D_00493880, "SetScrollDelay", 1, D_00493890);
    D_004EA060 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_RequestLevelEnd, D_00493880, "RequestLevelEnd", 0);
    D_004EA068 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_AddTremor, D_00493880, "AddTremor", 4, cGOBJ_SOBJ_getClassId(), D_00493890, D_00493890, D_00493890);
    D_004EA070 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_StartGlobalTimer, D_00493880, "StartGlobalTimer", 1, D_00493890);
    D_004EA078 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_StartGlobalTimer_2, D_00493880, "StartGlobalTimer", 2, D_00493890, D_004938A0);
    D_004EA080 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_IsMultiplayer, D_00493878, "IsMultiplayer", 0);
    D_004EA088 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_ResetStats, D_00493880, "ResetStats", 0);
    D_004EA090 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_ResetLevel, D_00493880, "ResetLevel", 0);
    D_004EA098 = "cNetAgentUpdateMsg";
    D_004EA0A8 = cNetMsg_RegisterMsg(cNetAgentUpdateMsg_NetReceive, D_004EA0A0, "cNetAgentUpdateMsg");
    if (!D_004EA0C8) {
        g_LosCheckService = "LOS Manager";
        D_004EA0C8 = 1;
    }
}

