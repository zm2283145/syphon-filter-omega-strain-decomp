#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
extern "C" {
#include "net_local_id.h"
int AgentData_Construct(...);
int Mem_Alloc(...);
int ScriptMgr_CallFunction(...);
int WeaponDb_Load(...);
int func_0040E4C0(...);
extern char D_0049A890;
extern unsigned char D_004E9FF0;
extern char D_00555070;
extern char g_MemCard;
}

extern "C" void Awards_Init(char * arg0) {
    int var_s1;
    int var_a2;
    int var_s3;
    char * var_s0;

    if (D_004E9FF0 == 0) {
        D_004E9FF0 = 1;
        WeaponDb_Load(F_(arg0, 0x1E0, int));
        func_0040E4C0(&g_MemCard);
        ScriptMgr_CallFunction(&D_00555070, "awards::init", 0);
        var_s1 = 0;
        var_s0 = arg0;
        do {
            {
                AllocGuard g;
            var_s3 = Mem_Alloc(0, 0xB78, &D_0049A890, 0x186);
            }
            if (var_s3 != 0) {
                var_s3 = AgentData_Construct(var_s3);
            }
            var_s1 += 1;
            F_(var_s0, 0x1C8, int) = var_s3;
            var_s0 += 4;
        } while (var_s1 < 4);
    }
    var_a2 = g_IsMultiplayer ? NetLocalId() : 0;
    { int cur = F_(arg0, 0x1D8, int); if (var_a2 != cur) { int* pa = (int*)(arg0 + 0x1C8) + cur; int* pb = (int*)(arg0 + 0x1C8) + var_a2; int t = *pa; *pa = *pb; *pb = t; *(int*)(arg0 + 0x1D8) = var_a2; } }
}