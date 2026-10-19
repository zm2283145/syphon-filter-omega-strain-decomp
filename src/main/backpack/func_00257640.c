#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "vslot_pad.h"
#include "vu0_ops.h"
extern "C" {
extern int D_00494178;
extern int D_005721A8;
extern bool D_005721C0;
extern bool g_IsMultiplayer;
int NetGame_InitLocalSlot(int*,int);
int func_002EBBA0(int,int*);
}
#pragma push
#pragma inline_depth(12)
#pragma opt_common_subs off
#pragma opt_propagation off
static inline int LocalId() { int r=0;int a=D_005721A8;if(g_IsMultiplayer) { if(D_00494178==-1)NetGame_InitLocalSlot(&D_00494178,a);r=D_00494178; }else { /* Keep the default-id branch. */ asm { .set reorder } }return r; }
static inline int KnownLocal(bool online) { int r=0;int a=D_005721A8;if(online) { if(D_00494178==-1)NetGame_InitLocalSlot(&D_00494178,a);r=D_00494178; }else { /* Keep the default-id branch. */ asm { .set reorder } }return r; }
static inline bool Hosting() {bool r;if(g_IsMultiplayer)r=D_005721C0;else {r=1; /* Preserve the offline branch. */ asm { .set reorder }}return r;}
static inline int OwnerId() {int id;if(Hosting())id=LocalId();else{int tmp;func_002EBBA0(D_005721A8,&tmp);id=tmp;}return id;}
struct Mat { __int128 q[4]; Mat() {} };
struct Backpack {
 VPAD32(a) VPAD2(b) virtual void attach(void*,int);
 char pad4[8];int id,netid;unsigned char active;char pad15[0x1A];unsigned char flag2f;char pad30[0x30];unsigned char flag60;char pad61[0x28F];unsigned char dropped;char pad2f1[0xF];int x300,x304,owner,x30c;float timer;int x314;
};
extern "C" {
extern int g_BackpackList;
extern float D_004F7F70;
extern char D_004A7B50[];
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
extern "C" void cBackpack_dtor();
extern "C" void cBackpack_v01();
extern "C" void cBackpack_v0B();
extern "C" void cBackpack_v0C();
extern "C" void cBackpack_v10();
extern "C" void cBackpack_v14();
extern "C" void cBackpack_v20();
extern "C" void cBackpack_v28();
extern "C" void GObj_GetID();
extern "C" void func_0012ED00();
extern "C" void func_0012ED30();
extern "C" void func_0012ED40();
extern "C" void func_0012ED50();
extern "C" void func_0013E060();
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
void * const D_004DC350[68] = { (void*)0x0, (void*)0x0, (void*)cBackpack_dtor, (void*)cBackpack_v01, (void*)GObj_GetID, (void*)Object_GetAttachedOrSelf, (void*)func_0015C090, (void*)func_0012ED00, (void*)cNode_v06, (void*)cNode_v07, (void*)func_0012ED30, (void*)func_0012ED40, (void*)func_0012ED50, (void*)cBackpack_v0B, (void*)cBackpack_v0C, (void*)cNode_v0D, (void*)func_003CE9F0, (void*)func_003CE9E0, (void*)cBackpack_v10, (void*)Actor_BasePreLogic, (void*)Actor_BaseWorldUpdate, (void*)Actor_VirtualNop, (void*)cBackpack_v14, (void*)Object_Activate, (void*)Object_Deactivate, (void*)Node_SetFlag2C, (void*)Node_ClearFlag2C, (void*)Node_GetFlag2C, (void*)func_0015BFB0, (void*)func_0015BFC0, (void*)func_0015BFD0, (void*)func_00148870, (void*)func_0015BFF0, (void*)func_0015BFE0, (void*)cBackpack_v20, (void*)func_0015C000, (void*)Object_AttachTransform, (void*)Player_GetActiveWeapon, (void*)cNode_v24, (void*)cNode_v25, (void*)cNode_v26, (void*)cNode_v27, (void*)cBackpack_v28, (void*)cNode_v29, (void*)cNode_v2A, (void*)cNode_v2B, (void*)func_0015C010, (void*)func_00153860, (void*)Object_GetEye, (void*)func_0015C020, (void*)func_00140E90, (void*)func_0015C030, (void*)func_0015C040, (void*)func_0015C050, (void*)Node_GetWorldMatrix, (void*)cGOBJ_v35, (void*)Node_GetLightRefPoint, (void*)PathObj_GetPosition, (void*)Node_GetComponentMatrix, (void*)cGOBJ_v39, (void*)cNode_v3A, (void*)GObj_GetWorldMatrix, (void*)func_0013E060, (void*)func_0015C080, (void*)Actor_ApplyContactDamage, (void*)func_0015C0A0, (void*)GObj_GetLifeState, (void*)Controller_DeathNotice };
extern char g_IdentityMatrix[];
void* Mem_Alloc(int,int,char*,int);
void Backpack_CheckCap();
void IdMgr_Allocate(int*,int);
void cGOBJ_ctor(void*,int*,int,int*);
void Backpack_Reset(Backpack*,int);
void Backpack_AppendToList(int,Backpack**);
Mat Actor_GetBackpackDropMatrix(void*);
void Backpack_Place(Backpack*,Mat*,int);
void Backpack_SetOwner(Backpack*,void*);
void NetMap_BindReceiver(int,int,Backpack*);
}
static inline void* AllocBack() { AllocGuard g;return Mem_Alloc(0,0x318,D_004A7B50,0x157); }
static inline void ConstructBack(Backpack* obj,int* id) {
 int localId; int z=0;
 if(id) { /* Keep the selected-id branch and its delay slot. */ asm { .set reorder } } else {
  int tmp;
  IdMgr_Allocate(&tmp,0xF5);
  tmp|=(LocalId()+1)<<24;
  localId=tmp;id=&localId;
 }
 cGOBJ_ctor(obj,id,3,&z);
 *(void**)obj=((char*)D_004DC350);
 obj->x304=-2;obj->x300=0;obj->flag2f=1;
 Backpack_Reset(obj,0);
 obj->attach(g_IdentityMatrix,0);
 obj->dropped=1;obj->flag60=0;obj->timer=D_004F7F70;
}

static inline void Bind(Backpack* obj) {
 obj->netid=obj->id;
 if(!Hosting()) obj->active=0;
 int id=obj->netid;
 int owner=OwnerId();NetMap_BindReceiver(id,owner,obj);
}
extern "C" Backpack* Backpack_Construct(void* actor,int carry,int* id) {
 Backpack* result=0;
 int registry=g_BackpackList;
 Backpack_CheckCap();
 Backpack* obj=(Backpack*)AllocBack();
 if(obj) ConstructBack(obj,id);
 result=obj;Backpack_AppendToList(registry,&result);
 if(actor) {Mat m=Actor_GetBackpackDropMatrix(actor);Backpack_Place(result,&m,1);}
 else {Mat m;VU0_UnitMatrix(&m);Backpack_Place(result,&m,1);}
 if(carry) { /* Preserve the carry branch before clearing the owner. */ asm { .set reorder } } else actor=0;
 Backpack_SetOwner(result,actor);
 { bool online=g_IsMultiplayer;if(online) {result->owner=KnownLocal(online);Bind(result);} }
 return result;
}
#pragma pop

