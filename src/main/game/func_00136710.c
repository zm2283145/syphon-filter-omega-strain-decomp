#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
extern "C" {
#include "net_local_id.h"
int cAgentData_ctor(...);
int cMemMan_Allocate(...);
int cScriptInterpreter_CallFunction(...);
int cWeaponDB_LoadOnce(...);
int cMemCard_Init(...);
extern char D_0049A890;
extern unsigned char D_004E9FF0;
extern char D_00555070;
extern char g_MemCard;
}

extern "C" void cGameSystem_InitAgentData(char * arg0) {
    int var_s1;
    int var_a2;
    int var_s3;
    char * var_s0;

    if (D_004E9FF0 == 0) {
        D_004E9FF0 = 1;
        cWeaponDB_LoadOnce(F_(arg0, 0x1E0, int));
        cMemCard_Init(&g_MemCard);
        cScriptInterpreter_CallFunction(&D_00555070, "awards::init", 0);
        var_s1 = 0;
        var_s0 = arg0;
        do {
            {
                AllocGuard g;
            var_s3 = cMemMan_Allocate(0, 0xB78, &D_0049A890, 0x186);
            }
            if (var_s3 != 0) {
                var_s3 = cAgentData_ctor(var_s3);
            }
            var_s1 += 1;
            F_(var_s0, 0x1C8, int) = var_s3;
            var_s0 += 4;
        } while (var_s1 < 4);
    }
    var_a2 = g_IsMultiplayer ? NetLocalId() : 0;
    { int cur = F_(arg0, 0x1D8, int); if (var_a2 != cur) { int* pa = (int*)(arg0 + 0x1C8) + cur; int* pb = (int*)(arg0 + 0x1C8) + var_a2; int t = *pa; *pa = *pb; *pb = t; *(int*)(arg0 + 0x1D8) = var_a2; } }
}