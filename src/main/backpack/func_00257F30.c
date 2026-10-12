#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#pragma push
#pragma inline_depth(12)
#pragma opt_propagation off
struct V4 {float x,y,z,w;};
struct Transform {VPAD2(a) VPAD1(b) virtual void set(V4*);};
struct Link {char pad[0x94];int id;};
struct Backpack {
 VPAD16(a) VPAD4(b) VPAD1(c) virtual void active(int); VPAD8(d) VPAD4(e) virtual void attach(void*,int);
 char p4[8];int id;char p10[0x40];Transform* transform;char p54[0xC];unsigned char ready;char p61[0x283];int count,a2e8,a2ec;unsigned char dropped;char p2f1[7];int x2f8;Link* link;int x300,x304,x308,x30c;float timer;int x314;
};
struct Reader {int version;int a,b;char* cur;};
struct Weapon {char p0[0x70];int unit;char p74[0x7C];unsigned char kind;};
extern "C" {
extern char D_004F7F68[],D_004DC350[],D_0055C9F0[];
extern int D_004FFD30,D_004FFBD0;
void cGOBJ_ctor(Backpack*,int*,int,void*);
void func_00258330(Backpack*,int);
Weapon* WeaponDb_Get(int,int);
void func_00255AF0(Backpack*,int,int,int,int);
void Object_Register(Backpack*);
Link* Hotbox_CreateRuntime(int,Backpack*,int,int);
int IdMgr_FindCollision(int,int);
void ZoneMgr_Associate(int,Backpack*,int,int);
}
static inline int Read(Reader* r) {int v=*(int*)r->cur;r->cur+=4;return v;}
static inline void ReadFloat(Reader* r,float* out) {*out=*(float*)r->cur;r->cur+=4;}
static inline void Ensure(Backpack* obj) {if(!obj->link){obj->active(1);Object_Register(obj);if(!obj->link){obj->link=Hotbox_CreateRuntime(D_004FFBD0,obj,0,1);obj->link->id=obj->id;}}}
extern "C" Backpack* cBackpack_ctor(Backpack* obj0,Reader* r0) {
 int flag; int weapon;int slot;int n;int amount;Weapon* w;int j;Backpack* obj=obj0;Reader* r=r0;
 int id=-1;
 V4 pos;
 cGOBJ_ctor(obj,&id,0,D_004F7F68);
 *(void**)obj=D_004DC350;obj->x304=-2;obj->x300=0;
 func_00258330(obj,0);obj->attach(D_0055C9F0,0);
 int hi=Read(r);int lo=Read(r);obj->id=lo|(hi<<16);
 ReadFloat(r,&pos.x);ReadFloat(r,&pos.y);ReadFloat(r,&pos.z);pos.w=1.0f;
 obj->transform->set(&pos);
 slot=0;do {
  weapon=Read(r);n=Read(r);amount=Read(r);
  if(r->version>=0x39) {flag=*(unsigned char*)r->cur;r->cur++;
   int remainder;char* ptr=r->cur;remainder=(int)((unsigned long long)(unsigned int)ptr&3);
   if(remainder)r->cur=ptr+(4-(int)remainder);
  }
  if(weapon>=0) {
   w=WeaponDb_Get(D_004FFD30,weapon);
   if(amount>0 || !w->unit) {
    if(w->kind==1 || w->kind==7) {amount*=n;n=1;}
    j=0;if(0<n){do {func_00255AF0(obj,weapon,(amount-1)*w->unit,w->unit,flag);j++;}while(j<n);}
   }
  }
 slot++;}while(slot<3);
 int item=Read(r);int copies=Read(r);
 if(copies>0 && item) {if(obj->count++==0){obj->a2e8=item;obj->a2ec=item;}Ensure(obj);}
 int region=Read(r);int child=Read(r);
 if(child!=-1 && region!=-1){int found=IdMgr_FindCollision(region,child);if(found)ZoneMgr_Associate(found,obj,1,0);else obj->active(1);}
 obj->x2f8=0;obj->dropped=0;obj->ready=1;Ensure(obj);
 obj->x30c=0;obj->timer=0;
 return obj;
}
#pragma pop
