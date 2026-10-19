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
void GObj_GetID();
void Object_GetAttachedOrSelf();
void func_0015C090();
void func_0012ED00();
void cNode_v06();
void cNode_v07();
void func_0012ED30();
void func_0012ED40();
void func_0012ED50();
void cTank_v0B();
void cTank_v0C();
void cNode_v0D();
void func_003CE9F0();
void func_003CE9E0();
void cTank_v10();
void Actor_BasePreLogic();
void Actor_BaseWorldUpdate();
void Actor_VirtualNop();
void cNode_v14();
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
void Player_GetActiveWeapon();
void cNode_v24();
void cNode_v25();
void cNode_v26();
void cNode_v27();
void cNode_v28();
void cNode_v29();
void cNode_v2A();
void cNode_v2B();
void func_0015C010();
void func_00153860();
void Object_GetEye();
void func_0015C020();
void func_00140E90();
void func_0015C030();
void func_0015C040();
void func_0015C050();
void Node_GetWorldMatrix();
void cGOBJ_v35();
void Node_GetLightRefPoint();
void PathObj_GetPosition();
void Node_GetComponentMatrix();
void cGOBJ_v39();
void cNode_v3A();
void GObj_GetWorldMatrix();
void func_0013E060();
void func_0015C080();
void Actor_ApplyContactDamage();
void func_0015C0A0();
void GObj_GetLifeState();
void Controller_DeathNotice();
void* const cTank_vtable[68] = {
    0, 0, (void*)cTank_dtor, (void*)Object_HandleMessage, (void*)GObj_GetID, (void*)Object_GetAttachedOrSelf, (void*)func_0015C090, (void*)func_0012ED00, (void*)cNode_v06, (void*)cNode_v07, (void*)func_0012ED30, (void*)func_0012ED40, (void*)func_0012ED50, (void*)cTank_v0B, (void*)cTank_v0C, (void*)cNode_v0D, (void*)func_003CE9F0, (void*)func_003CE9E0, (void*)cTank_v10, (void*)Actor_BasePreLogic, (void*)Actor_BaseWorldUpdate, (void*)Actor_VirtualNop, (void*)cNode_v14, (void*)Object_Activate, (void*)Object_Deactivate, (void*)Node_SetFlag2C, (void*)Node_ClearFlag2C, (void*)Node_GetFlag2C, (void*)func_0015BFB0, (void*)func_0015BFC0, (void*)func_0015BFD0, (void*)func_00148870, (void*)func_0015BFF0, (void*)func_0015BFE0, (void*)func_0013EE60, (void*)func_0015C000, (void*)Object_AttachTransform, (void*)Player_GetActiveWeapon, (void*)cNode_v24, (void*)cNode_v25, (void*)cNode_v26, (void*)cNode_v27, (void*)cNode_v28, (void*)cNode_v29, (void*)cNode_v2A, (void*)cNode_v2B, (void*)func_0015C010, (void*)func_00153860, (void*)Object_GetEye, (void*)func_0015C020, (void*)func_00140E90, (void*)func_0015C030, (void*)func_0015C040, (void*)func_0015C050, (void*)Node_GetWorldMatrix, (void*)cGOBJ_v35, (void*)Node_GetLightRefPoint, (void*)PathObj_GetPosition, (void*)Node_GetComponentMatrix, (void*)cGOBJ_v39, (void*)cNode_v3A, (void*)GObj_GetWorldMatrix, (void*)func_0013E060, (void*)func_0015C080, (void*)Actor_ApplyContactDamage, (void*)func_0015C0A0, (void*)GObj_GetLifeState, (void*)Controller_DeathNotice
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
extern "C" void cNetCreateTankMsg_Apply(Spawner_3E10* s, int arg)
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