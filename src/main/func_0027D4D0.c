#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_00134E00(char * , int);                         
int func_0017EB50(char * , int);                         
int func_0017EC70(char * , int);                         
int func_0017ED20(char * , int);                         
int func_0017EDD0(char * , int);                         
int func_0017EE80(char * , int);                         
int func_0017EEE0(char * , int);                         
int func_0017EF30(char * , int);                         
int func_0017F080(char **, int);                           
int operator_delete(char **);                            
extern char D_004DA580;
extern void Actor_ApplyContactDamage();
extern void Controller_DeathNotice();
extern void Node_ClearFlag2C();
extern void Node_GetFlag2C();
extern void Node_SetFlag2C();
extern void Object_Activate();
extern void Object_AttachTransform();
extern void Object_GetAttachedOrSelf();
extern void PlayerCamera_PreUpdate();
extern void PlayerCamera_Update();
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
extern void func_0017A1A0();
extern void func_0017A1B0();
extern void func_00180780();
extern void func_00180790();
extern void func_00180B50();
extern void PlayerCamera_v13();
extern void PlayerCamera_v11();
extern void GObj_GetWorldMatrix();
extern void cNode_v3A();
extern void cGOBJ_v39();
extern void Node_GetComponentMatrix();
extern void PathObj_GetPosition();
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
extern void Player_GetActiveWeapon();
extern void Object_Deactivate();
extern void cNode_v07();
extern void cNode_v06();
extern void cNode_v14();
extern void cNode_v0D();
extern void Object_HandleMessage();
extern void * const D_004DCDE0[];

char **PlayerCamera_dtor(char **arg0, long long arg1) {
    if (arg0 != NULL) {
        *arg0 = &(*(char*)D_004DCDE0);
        if (arg0 != NULL) {
            *arg0 = &D_004DA580;
            func_00134E00((char *)arg0 + 0xC70, -1);
            func_0017EB50((char *)arg0 + 0xB20, -1);
            func_0017EC70((char *)arg0 + 0xA90, -1);
            func_0017ED20((char *)arg0 + 0x9D0, -1);
            func_0017ED20((char *)arg0 + 0x910, -1);
            func_0017ED20((char *)arg0 + 0x850, -1);
            func_0017EDD0((char *)arg0 + 0x780, -1);
            func_0017ED20((char *)arg0 + 0x6C0, -1);
            func_0017ED20((char *)arg0 + 0x600, -1);
            func_0017EDD0((char *)arg0 + 0x530, -1);
            func_0017EDD0((char *)arg0 + 0x460, -1);
            func_0017ED20((char *)arg0 + 0x3A0, -1);
            func_0017ED20((char *)arg0 + 0x2E0, -1);
            func_0017EDD0((char *)arg0 + 0x210, -1);
            func_0017EEE0((char *)arg0 + 0x1C0, -1);
            func_0017EE80((char *)arg0 + 0x170, -1);
            func_0017EEE0((char *)arg0 + 0x130, -1);
            func_0017EF30((char *)arg0 + 0x70, -1);
            func_0017F080(arg0, 0);
        }
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
void * const D_004DCDE0[68] = { (void*)0x0, (void*)0x0, (void*)PlayerCamera_dtor, (void*)Object_HandleMessage, (void*)GObj_GetID, (void*)Object_GetAttachedOrSelf, (void*)func_0015C090, (void*)func_0012ED00, (void*)cNode_v06, (void*)cNode_v07, (void*)func_0012ED30, (void*)func_0012ED40, (void*)func_0012ED50, (void*)func_0017A1A0, (void*)func_0017A1B0, (void*)cNode_v0D, (void*)func_00180780, (void*)func_00180790, (void*)PlayerCamera_PreUpdate, (void*)PlayerCamera_v11, (void*)PlayerCamera_Update, (void*)PlayerCamera_v13, (void*)cNode_v14, (void*)Object_Activate, (void*)Object_Deactivate, (void*)Node_SetFlag2C, (void*)Node_ClearFlag2C, (void*)Node_GetFlag2C, (void*)func_0015BFB0, (void*)func_0015BFC0, (void*)func_0015BFD0, (void*)func_00148870, (void*)func_0015BFF0, (void*)func_0015BFE0, (void*)func_0013EE60, (void*)func_0015C000, (void*)Object_AttachTransform, (void*)Player_GetActiveWeapon, (void*)func_00180B50, (void*)cNode_v25, (void*)cNode_v26, (void*)cNode_v27, (void*)cNode_v28, (void*)cNode_v29, (void*)cNode_v2A, (void*)cNode_v2B, (void*)func_0015C010, (void*)func_00153860, (void*)Object_GetEye, (void*)func_0015C020, (void*)func_00140E90, (void*)func_0015C030, (void*)func_0015C040, (void*)func_0015C050, (void*)Node_GetWorldMatrix, (void*)cGOBJ_v35, (void*)Node_GetLightRefPoint, (void*)PathObj_GetPosition, (void*)Node_GetComponentMatrix, (void*)cGOBJ_v39, (void*)cNode_v3A, (void*)GObj_GetWorldMatrix, (void*)func_0013E060, (void*)func_0015C080, (void*)Actor_ApplyContactDamage, (void*)func_0015C0A0, (void*)GObj_GetLifeState, (void*)Controller_DeathNotice };
