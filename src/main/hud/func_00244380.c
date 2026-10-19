#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


extern "C" {
char **Mem_Alloc(...);                        
int IeElement_Release(...);                            
int HudTracker_Kill(...);                              
int HudTracker_Attach(...);                      
int HudTracker_Construct(...);                   
char * IeElement_Create(...);                           
extern char D_004A7210;
extern "C" void Actor_ApplyContactDamage();
extern "C" void Actor_BasePreLogic();
extern "C" void Actor_BaseWorldUpdate();
extern "C" void Actor_VirtualNop();
extern "C" void Controller_DeathNotice();
extern "C" void Node_ClearFlag2C();
extern "C" void Node_GetFlag2C();
extern "C" void Node_SetFlag2C();
extern "C" void Object_Activate();
extern "C" void Object_AttachTransform();
extern "C" void Object_GetAttachedOrSelf();
extern "C" void cGOBJ_v0B();
extern "C" void cGOBJ_v0C();
extern "C" void GObj_GetID();
extern "C" void func_0012ED00();
extern "C" void func_0012ED30();
extern "C" void func_0012ED40();
extern "C" void func_0012ED50();
extern "C" void func_0013E060();
extern "C" void func_0013EE60();
extern "C" void func_00140E90();
extern "C" void GObj_GetLifeState();
extern "C" void func_00148870();
extern "C" void Object_GetEye();
extern "C" void func_00153860();
extern "C" void func_0015BFB0();
extern "C" void func_0015BFC0();
extern "C" void func_0015BFD0();
extern "C" void func_0015BFE0();
extern "C" void func_0015BFF0();
extern "C" void func_0015C000();
extern "C" void func_0015C010();
extern "C" void func_0015C020();
extern "C" void func_0015C030();
extern "C" void func_0015C040();
extern "C" void func_0015C050();
extern "C" void func_0015C080();
extern "C" void func_0015C090();
extern "C" void func_0015C0A0();
extern "C" void HudBlip_Draw();
extern "C" void GObj_GetWorldMatrix();
extern "C" void cNode_v3A();
extern "C" void cGOBJ_v39();
extern "C" void Node_GetComponentMatrix();
extern "C" void PathObj_GetPosition();
extern "C" void Node_GetLightRefPoint();
extern "C" void cGOBJ_v35();
extern "C" void Node_GetWorldMatrix();
extern "C" void cNode_v2B();
extern "C" void cNode_v2A();
extern "C" void cNode_v29();
extern "C" void cNode_v28();
extern "C" void cNode_v27();
extern "C" void cNode_v26();
extern "C" void cNode_v25();
extern "C" void cNode_v24();
extern "C" void Player_GetActiveWeapon();
extern "C" void Object_Deactivate();
extern "C" void cNode_v07();
extern "C" void cNode_v06();
extern "C" void func_003CE9E0();
extern "C" void func_003CE9F0();
extern "C" void cNode_v0D();
extern "C" void Object_HandleMessage();
extern "C" void HudLockTracker_Draw();
extern "C" void HudTracker_Update();
extern "C" void HudTracker_Delete();
void * const D_004E0480[72] = { (void*)0x0, (void*)0x0, (void*)HudTracker_Delete, (void*)Object_HandleMessage, (void*)GObj_GetID, (void*)Object_GetAttachedOrSelf, (void*)func_0015C090, (void*)func_0012ED00, (void*)cNode_v06, (void*)cNode_v07, (void*)func_0012ED30, (void*)func_0012ED40, (void*)func_0012ED50, (void*)cGOBJ_v0B, (void*)cGOBJ_v0C, (void*)cNode_v0D, (void*)func_003CE9F0, (void*)func_003CE9E0, (void*)HudTracker_Update, (void*)Actor_BasePreLogic, (void*)Actor_BaseWorldUpdate, (void*)Actor_VirtualNop, (void*)HudBlip_Draw, (void*)Object_Activate, (void*)Object_Deactivate, (void*)Node_SetFlag2C, (void*)Node_ClearFlag2C, (void*)Node_GetFlag2C, (void*)func_0015BFB0, (void*)func_0015BFC0, (void*)func_0015BFD0, (void*)func_00148870, (void*)func_0015BFF0, (void*)func_0015BFE0, (void*)func_0013EE60, (void*)func_0015C000, (void*)Object_AttachTransform, (void*)Player_GetActiveWeapon, (void*)cNode_v24, (void*)cNode_v25, (void*)cNode_v26, (void*)cNode_v27, (void*)cNode_v28, (void*)cNode_v29, (void*)cNode_v2A, (void*)cNode_v2B, (void*)func_0015C010, (void*)func_00153860, (void*)Object_GetEye, (void*)func_0015C020, (void*)func_00140E90, (void*)func_0015C030, (void*)func_0015C040, (void*)func_0015C050, (void*)Node_GetWorldMatrix, (void*)cGOBJ_v35, (void*)Node_GetLightRefPoint, (void*)PathObj_GetPosition, (void*)Node_GetComponentMatrix, (void*)cGOBJ_v39, (void*)cNode_v3A, (void*)GObj_GetWorldMatrix, (void*)func_0013E060, (void*)func_0015C080, (void*)Actor_ApplyContactDamage, (void*)func_0015C0A0, (void*)GObj_GetLifeState, (void*)Controller_DeathNotice, (void*)HudLockTracker_Draw, (void*)0x0, (void*)0x0, (void*)0x0 };
extern unsigned char g_ProfileLockEnabled;
typedef struct { char p0[92]; int f5C; int f60; int f64; int f68; } PS0_00244380;
}
extern "C" void Hud_ShowTargetLock(PS0_00244380 *arg0, int arg1, int arg2) {
    char **temp_a0;
    char **temp_s0;
    char **temp_s0_2;
    int var_s0;
    char * temp_v1;

    if (arg2 == -1) {
        var_s0 = arg0->f5C;
    } else {
        var_s0 = arg0->f60;
    }
    temp_v1 = (char *)(arg0->f68);
    if (temp_v1 == NULL) {
        arg0->f68 = (int)(IeElement_Create(var_s0));
        {
            AllocGuard g;
        temp_s0 = Mem_Alloc(0, 0x90, &D_004A7210, 0x3A1);
        }
        if (temp_s0 != NULL) {
            HudTracker_Construct(temp_s0, arg0->f68, arg1);
            *temp_s0 = &(*(char*)D_004E0480);
        }
        arg0->f64 = (int)(temp_s0);
    } else if (F_(temp_v1, 0x70, int) != var_s0) {
        temp_a0 = (char **)(arg0->f64);
        if (temp_a0 != NULL) {
            HudTracker_Kill(temp_a0);
        } else {
            IeElement_Release(temp_v1);
        }
        arg0->f68 = (int)(IeElement_Create(var_s0));
        {
            AllocGuard g;
        temp_s0_2 = Mem_Alloc(0, 0x90, &D_004A7210, 0x3AD);
        }
        if (temp_s0_2 != NULL) {
            HudTracker_Construct(temp_s0_2, arg0->f68, arg1);
            *temp_s0_2 = &(*(char*)D_004E0480);
        }
        arg0->f64 = (int)(temp_s0_2);
    }
    HudTracker_Attach(arg0->f64, arg1, arg2);
}
