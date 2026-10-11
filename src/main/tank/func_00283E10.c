#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma inline_depth(10)
extern "C" {
#include "net_local_id.h"
}
#include "tank_obj_init.h"
typedef struct { char pad[0x24]; TankObj* obj; char id[4]; } Spawner_3E10;
extern "C" {
extern char D_004A93D0[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void Script_ReadU32(void* p);
void cGOBJ_ctor(void* p, void* id, int a, int* b);
void func_002842F0(TankObj* o);
}
extern "C" void func_00283E10(Spawner_3E10* s, int arg)
{
    TankObj* p;
    Script_ReadU32(s->id);
    {
        AllocGuard g;
        p = (TankObj*)Mem_Alloc(0, 0x78, D_004A93D0, 0x305);
    }
    if (p) {
        int z[1];
        z[0] = 0;
        cGOBJ_ctor(p, s->id, 0, z);
        TankObj_Init(p, arg);
    }
    s->obj = p;
    func_002842F0(s->obj);
}