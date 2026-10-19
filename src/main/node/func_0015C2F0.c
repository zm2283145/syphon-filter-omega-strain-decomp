#include "types.h"
extern void Actor_ApplyContactDamage();
extern void Actor_BaseLogicUpdate();
extern void Actor_BasePreLogic();
extern void Actor_BaseWorldUpdate();
extern void Actor_VirtualNop();
extern void Controller_DeathNotice();
extern void Node_ClearFlag2C();
extern void Node_GetFlag2C();
extern void Node_SetFlag2C();
extern void Object_Activate();
extern void Object_AttachTransform();
extern void Object_GetAttachedOrSelf();
extern void cNode_v0B();
extern void cNode_v0C();
extern void cNode_v0E();
extern void cNode_v0F();
extern void cNode_v34();
extern void cNode_v35();
extern void cNode_v36();
extern void cNode_v37();
extern void cNode_v38();
extern void cNode_v39();
extern void cNode_v3B();
extern void GObj_GetID();
extern void func_0012ED00();
extern void func_0012ED30();
extern void func_0012ED40();
extern void func_0012ED50();
extern void func_0013E060();
extern void func_0013EE60();
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
extern void cNode_v3A();
extern void cNode_v2B();
extern void cNode_v2A();
extern void cNode_v29();
extern void cNode_v28();
extern void cNode_v27();
extern void cNode_v26();
extern void cNode_v25();
extern void cNode_v24();
extern void Player_GetActiveWeapon();
extern void Object_Deactivate();
extern void cNode_v07();
extern void cNode_v06();
extern void cNode_v14();
extern void cNode_v0D();
extern void Object_HandleMessage();
extern void * const cNode_vtable[];
extern void func_0015CA10(void* p);
extern void func_0015CA20(void* p, int flag);
extern void cGOBJ_dtor(void* self, int flag);
extern void operator_delete(void* p);
typedef struct { void* vt; } S_C2F0;
#pragma opt_common_subs off
S_C2F0* cNode_dtor(S_C2F0* self, short flag)
{
    if (self) {
        void* m;
        self->vt = ((char*)cNode_vtable);
        func_0015CA10((char*)self + 0x68);
        m = (char*)self + 0x68;
        if (m) {
            if (m) {
                if (m)
                    func_0015CA20(m, 0);
            }
        }
        cGOBJ_dtor(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
#pragma opt_common_subs reset
void * const cNode_vtable[68] = { (void*)0x0, (void*)0x0, (void*)cNode_dtor, (void*)Object_HandleMessage, (void*)GObj_GetID, (void*)Object_GetAttachedOrSelf, (void*)func_0015C090, (void*)func_0012ED00, (void*)cNode_v06, (void*)cNode_v07, (void*)func_0012ED30, (void*)func_0012ED40, (void*)func_0012ED50, (void*)cNode_v0B, (void*)cNode_v0C, (void*)cNode_v0D, (void*)cNode_v0E, (void*)cNode_v0F, (void*)Actor_BaseLogicUpdate, (void*)Actor_BasePreLogic, (void*)Actor_BaseWorldUpdate, (void*)Actor_VirtualNop, (void*)cNode_v14, (void*)Object_Activate, (void*)Object_Deactivate, (void*)Node_SetFlag2C, (void*)Node_ClearFlag2C, (void*)Node_GetFlag2C, (void*)func_0015BFB0, (void*)func_0015BFC0, (void*)func_0015BFD0, (void*)func_00148870, (void*)func_0015BFF0, (void*)func_0015BFE0, (void*)func_0013EE60, (void*)func_0015C000, (void*)Object_AttachTransform, (void*)Player_GetActiveWeapon, (void*)cNode_v24, (void*)cNode_v25, (void*)cNode_v26, (void*)cNode_v27, (void*)cNode_v28, (void*)cNode_v29, (void*)cNode_v2A, (void*)cNode_v2B, (void*)func_0015C010, (void*)func_00153860, (void*)Object_GetEye, (void*)func_0015C020, (void*)func_00140E90, (void*)func_0015C030, (void*)func_0015C040, (void*)func_0015C050, (void*)cNode_v34, (void*)cNode_v35, (void*)cNode_v36, (void*)cNode_v37, (void*)cNode_v38, (void*)cNode_v39, (void*)cNode_v3A, (void*)cNode_v3B, (void*)func_0013E060, (void*)func_0015C080, (void*)Actor_ApplyContactDamage, (void*)func_0015C0A0, (void*)GObj_GetLifeState, (void*)Controller_DeathNotice };
