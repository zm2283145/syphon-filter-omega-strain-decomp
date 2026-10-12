#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "vslot_pad.h"
#include "vu0_ops.h"
extern "C" {
extern int D_00494178,D_005721A8;
extern bool D_005721C0,D_005721C8;
int func_002EBAF8(int*,int);
int func_002EBBA0(int,int*);
}
#pragma push
#pragma inline_depth(12)
#pragma opt_common_subs off
#pragma opt_propagation off
static inline int LocalId() { int r=0;int a=D_005721A8;if(D_005721C8) { if(D_00494178==-1)func_002EBAF8(&D_00494178,a);r=D_00494178; }else { /* Keep the default-id branch. */ asm { .set reorder } }return r; }
static inline int KnownLocal(bool online) { int r=0;int a=D_005721A8;if(online) { if(D_00494178==-1)func_002EBAF8(&D_00494178,a);r=D_00494178; }else { /* Keep the default-id branch. */ asm { .set reorder } }return r; }
static inline bool Hosting() {bool r;if(D_005721C8)r=D_005721C0;else {r=1; /* Preserve the offline branch. */ asm { .set reorder }}return r;}
static inline int OwnerId() {int id;if(Hosting())id=LocalId();else{int tmp;func_002EBBA0(D_005721A8,&tmp);id=tmp;}return id;}
struct Mat { __int128 q[4]; Mat() {} };
struct Backpack {
 VPAD32(a) VPAD2(b) virtual void attach(void*,int);
 char pad4[8];int id,netid;unsigned char active;char pad15[0x1A];unsigned char flag2f;char pad30[0x30];unsigned char flag60;char pad61[0x28F];unsigned char dropped;char pad2f1[0xF];int x300,x304,owner,x30c;float timer;int x314;
};
extern "C" {
extern int D_004F7F30; extern float D_004F7F70;
extern char D_004A7B50[],D_004DC350[],D_0055C9F0[];
void* Mem_Alloc(int,int,char*,int);
void func_00257A40();
void IdMgr_Allocate(int*,int);
void cGOBJ_ctor(void*,int*,int,int*);
void func_00258330(Backpack*,int);
void func_00257620(int,Backpack**);
Mat func_001A32A0(void*);
void func_002561D0(Backpack*,Mat*,int);
void func_002566B0(Backpack*,void*);
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
 *(void**)obj=D_004DC350;
 obj->x304=-2;obj->x300=0;obj->flag2f=1;
 func_00258330(obj,0);
 obj->attach(D_0055C9F0,0);
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
 int registry=D_004F7F30;
 func_00257A40();
 Backpack* obj=(Backpack*)AllocBack();
 if(obj) ConstructBack(obj,id);
 result=obj;func_00257620(registry,&result);
 if(actor) {Mat m=func_001A32A0(actor);func_002561D0(result,&m,1);}
 else {Mat m;VU0_UnitMatrix(&m);func_002561D0(result,&m,1);}
 if(carry) { /* Preserve the carry branch before clearing the owner. */ asm { .set reorder } } else actor=0;
 func_002566B0(result,actor);
 { bool online=D_005721C8;if(online) {result->owner=KnownLocal(online);Bind(result);} }
 return result;
}
#pragma pop

