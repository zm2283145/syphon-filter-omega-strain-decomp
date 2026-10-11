#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma inline_depth(10)
extern "C" {
#include "net_local_id.h"
}
#include "tank_obj_init.h"
typedef struct { int a; } Id_4100;
extern "C" {
extern char D_004A93D0[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void IdMgr_Allocate(Id_4100* out, int kind);
void cGOBJ_ctor(void* p, Id_4100* id, int a, int* b);
}
extern "C" TankObj* Global_CreateTank(int arg)
{
    TankObj* p;
{ AllocGuard g; p = (TankObj*)Mem_Alloc(0, 0x78, D_004A93D0, 0x2F2); }
    if (p) {
Id_4100 id; int z[1];
        z[0] = 0;
        IdMgr_Allocate(&id, 0xF9);
        cGOBJ_ctor(p, &id, 0, z);
        TankObj_Init(p, arg);
    }
    return p;
}