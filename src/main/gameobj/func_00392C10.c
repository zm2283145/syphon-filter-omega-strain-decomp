#include "types.h"
typedef struct { char pad[0x2EC0]; } F8Actor_pad;
typedef struct {
    void* vt;
    char pad4[0x5C];
    char x60[0x2E50 - 0x60];
    char x2E50[4];
    char x2E54[0x14];
    char x2E68[0x2EC0 - 0x2E68];
    char x2EC0[0x10];
    char x2ED0[0xF0];
    char x2FC0[4];
} F8Actor_392;
extern void Actor_ApplyContactDamage();
extern void Actor_BasePreLogic();
extern void Actor_VirtualNop();
extern void Actor_WorldUpdate();
extern void Controller_DeathNotice();
extern void Node_ClearFlag2C();
extern void Node_GetFlag2C();
extern void Node_SetFlag2C();
extern void Object_AttachTransform();
extern void Object_GetAttachedOrSelf();
extern void Skel_Bind();
extern void cGOBJ_v0B();
extern void cGOBJ_v0C();
extern void GObj_GetID();
extern void func_0012ED00();
extern void func_0012ED30();
extern void func_0012ED40();
extern void func_0012ED50();
extern void Actor_GetPosition();
extern void func_0013E060();
extern void func_00140E90();
extern void GObj_GetLifeState();
extern void func_00148870();
extern void Object_GetEye();
extern void func_00153860();
extern void func_0015BFB0();
extern void func_0015BFC0();
extern void func_0015BFD0();
extern void func_0015BFE0();
extern void func_0015BFF0();
extern void func_0015C000();
extern void func_0015C010();
extern void func_0015C020();
extern void func_0015C030();
extern void func_0015C040();
extern void func_0015C050();
extern void func_0015C080();
extern void func_0015C090();
extern void func_0015C0A0();
extern void func_001E8C90();
extern void func_003925C0();
extern void Actor_v07();
extern void Actor_Deactivate();
extern void Actor_v06();
extern void ActorModel_Activate();
extern void ActorModel_Draw();
extern void Actor_LogicUpdate();
extern void func_00392BF0();
extern void GObj_GetWorldMatrix();
extern void cNode_v3A();
extern void cGOBJ_v39();
extern void Node_GetComponentMatrix();
extern void Node_GetLightRefPoint();
extern void cGOBJ_v35();
extern void Node_GetWorldMatrix();
extern void cNode_v2B();
extern void cNode_v2A();
extern void cNode_v29();
extern void cNode_v28();
extern void cNode_v27();
extern void cNode_v26();
extern void cNode_v25();
extern void cNode_v24();
extern void Player_GetActiveWeapon();
extern void cNode_v0D();
extern void Object_HandleMessage();
extern void * const D_004DF740[];
extern void func_00393690(void* p);
extern void func_003931F0(void* p);
extern void func_00393000(void* p, int f);
extern void func_00392D10(void* p, int f);
extern void func_003960F0(void* p, int f);
extern void func_00396000(void* p, int f);
extern void func_00392260(void* p, int f);
extern void cGOBJ_dtor(void* p, int f);
extern void operator_delete(void* p);
static inline void F8L3a(void* p) { if (p) func_003960F0(p, 0); }
static inline void F8L2a(void* p) { if (p) F8L3a(p); }
static inline void F8L1a(void* p) { if (p) F8L2a(p); }
static inline void F8L3b(void* p) { if (p) func_00396000(p, 0); }
static inline void F8L2b(void* p) { if (p) F8L3b(p); }
static inline void F8L1b(void* p) { if (p) F8L2b(p); }
F8Actor_392* Actor_Destroy(F8Actor_392* a, short del)
{
    if (a) {
        a->vt = ((char*)D_004DF740);
        if (a->x2EC0) {
            func_00393690(a->x2EC0);
            func_003931F0(a->x2EC0);
            func_00393000(a->x2FC0, -1);
            func_00392D10(a->x2ED0, -1);
        }
        if (a->x2E50) {
            F8L1a(a->x2E68);
            F8L1b(a->x2E54);
        }
        func_00392260(a->x60, -1);
        cGOBJ_dtor(a, 0);
        if (del > 0)
            operator_delete(a);
    }
    return a;
}
void * const D_004DF740[72] = { (void*)0x0, (void*)0x0, (void*)Actor_Destroy, (void*)Object_HandleMessage, (void*)GObj_GetID, (void*)Object_GetAttachedOrSelf, (void*)func_0015C090, (void*)func_0012ED00, (void*)Actor_v06, (void*)Actor_v07, (void*)func_0012ED30, (void*)func_0012ED40, (void*)func_0012ED50, (void*)cGOBJ_v0B, (void*)cGOBJ_v0C, (void*)cNode_v0D, (void*)func_00392BF0, (void*)Skel_Bind, (void*)Actor_LogicUpdate, (void*)Actor_BasePreLogic, (void*)Actor_WorldUpdate, (void*)Actor_VirtualNop, (void*)ActorModel_Draw, (void*)ActorModel_Activate, (void*)Actor_Deactivate, (void*)Node_SetFlag2C, (void*)Node_ClearFlag2C, (void*)Node_GetFlag2C, (void*)func_0015BFB0, (void*)func_0015BFC0, (void*)func_0015BFD0, (void*)func_00148870, (void*)func_0015BFF0, (void*)func_0015BFE0, (void*)func_001E8C90, (void*)func_0015C000, (void*)Object_AttachTransform, (void*)Player_GetActiveWeapon, (void*)cNode_v24, (void*)cNode_v25, (void*)cNode_v26, (void*)cNode_v27, (void*)cNode_v28, (void*)cNode_v29, (void*)cNode_v2A, (void*)cNode_v2B, (void*)func_0015C010, (void*)func_00153860, (void*)Object_GetEye, (void*)func_0015C020, (void*)func_00140E90, (void*)func_0015C030, (void*)func_0015C040, (void*)func_0015C050, (void*)Node_GetWorldMatrix, (void*)cGOBJ_v35, (void*)Node_GetLightRefPoint, (void*)Actor_GetPosition, (void*)Node_GetComponentMatrix, (void*)cGOBJ_v39, (void*)cNode_v3A, (void*)GObj_GetWorldMatrix, (void*)func_0013E060, (void*)func_0015C080, (void*)Actor_ApplyContactDamage, (void*)func_0015C0A0, (void*)GObj_GetLifeState, (void*)Controller_DeathNotice, (void*)func_003925C0, (void*)0x0, (void*)0x0, (void*)0x0 };
