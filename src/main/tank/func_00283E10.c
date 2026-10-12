#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma inline_depth(10)
extern "C" {
#include "net_local_id.h"
}
#include "tank_obj_init_vt.h"
extern "C" {
void cTank_dtor();
void Object_HandleMessage();
void func_0012ECE0();
void Object_GetAttachedOrSelf();
void func_0015C090();
void func_0012ED00();
void func_003CE810();
void func_003CE7D0();
void func_0012ED30();
void func_0012ED40();
void func_0012ED50();
void cTank_v0B();
void cTank_v0C();
void func_003CEA00();
void func_003CE9F0();
void func_003CE9E0();
void cTank_v10();
void Actor_BasePreLogic();
void Actor_BaseWorldUpdate();
void Actor_VirtualNop();
void func_003CE9D0();
void Object_Activate();
void Object_Deactivate();
void Node_SetFlag2C();
void Node_ClearFlag2C();
void Node_GetFlag2C();
void func_0015BFB0();
void func_0015BFC0();
void func_0015BFD0();
void func_00148870();
void func_0015BFF0();
void func_0015BFE0();
void func_0013EE60();
void func_0015C000();
void Object_AttachTransform();
void func_003CDE00();
void func_003CDDC0();
void func_003CDD80();
void func_003CDD40();
void func_003CDC20();
void func_003CDBE0();
void func_003CDA60();
void func_003CD920();
void func_003CD7A0();
void func_0015C010();
void func_00153860();
void func_0014D340();
void func_0015C020();
void func_00140E90();
void func_0015C030();
void func_0015C040();
void func_0015C050();
void func_003CD520();
void func_003CD4A0();
void func_003CD420();
void func_003CD260();
void func_003CD1C0();
void func_003CD110();
void func_003CD090();
void func_003CCFF0();
void func_0013E060();
void func_0015C080();
void Actor_ApplyContactDamage();
void func_0015C0A0();
void func_00141850();
void Controller_DeathNotice();
void* const D_004DCF90[68] = {
    0, 0, (void*)cTank_dtor, (void*)Object_HandleMessage, (void*)func_0012ECE0, (void*)Object_GetAttachedOrSelf, (void*)func_0015C090, (void*)func_0012ED00, (void*)func_003CE810, (void*)func_003CE7D0, (void*)func_0012ED30, (void*)func_0012ED40, (void*)func_0012ED50, (void*)cTank_v0B, (void*)cTank_v0C, (void*)func_003CEA00, (void*)func_003CE9F0, (void*)func_003CE9E0, (void*)cTank_v10, (void*)Actor_BasePreLogic, (void*)Actor_BaseWorldUpdate, (void*)Actor_VirtualNop, (void*)func_003CE9D0, (void*)Object_Activate, (void*)Object_Deactivate, (void*)Node_SetFlag2C, (void*)Node_ClearFlag2C, (void*)Node_GetFlag2C, (void*)func_0015BFB0, (void*)func_0015BFC0, (void*)func_0015BFD0, (void*)func_00148870, (void*)func_0015BFF0, (void*)func_0015BFE0, (void*)func_0013EE60, (void*)func_0015C000, (void*)Object_AttachTransform, (void*)func_003CDE00, (void*)func_003CDDC0, (void*)func_003CDD80, (void*)func_003CDD40, (void*)func_003CDC20, (void*)func_003CDBE0, (void*)func_003CDA60, (void*)func_003CD920, (void*)func_003CD7A0, (void*)func_0015C010, (void*)func_00153860, (void*)func_0014D340, (void*)func_0015C020, (void*)func_00140E90, (void*)func_0015C030, (void*)func_0015C040, (void*)func_0015C050, (void*)func_003CD520, (void*)func_003CD4A0, (void*)func_003CD420, (void*)func_003CD260, (void*)func_003CD1C0, (void*)func_003CD110, (void*)func_003CD090, (void*)func_003CCFF0, (void*)func_0013E060, (void*)func_0015C080, (void*)Actor_ApplyContactDamage, (void*)func_0015C0A0, (void*)func_00141850, (void*)Controller_DeathNotice
};
}
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