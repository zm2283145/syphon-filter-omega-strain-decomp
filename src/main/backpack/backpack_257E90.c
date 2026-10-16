/*
 * main/backpack: range (3 files, 00257E90-00258330)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_00257E90 */
#pragma push /* merge_units */
typedef struct Backpack{void*vt;char pad[0x2F8];void*actor;}Backpack;
extern char D_004DC350[];extern void*D_004FFBD0;
void Hotbox_RemoveObjectBox(void*,void*);void Object_Unregister(void*);void Object_DeleteLater(void*,float);void cGOBJ_dtor(Backpack*,int);void operator_delete(void*);
Backpack*cBackpack_dtor(Backpack*self,int flags){
 if(self){self->vt=D_004DC350;if(self->actor){Hotbox_RemoveObjectBox(D_004FFBD0,self->actor);Object_Unregister(self->actor);Object_DeleteLater(self->actor,0.1f);self->actor=0;}
 cGOBJ_dtor(self,0);if((short)flags>0)operator_delete(self);}
 return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00257E90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00257E90 */

/* merge_units: begin func_00257F30 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
extern "C" void Backpack_Reset(void* self, int preserve); /* gsynth: defined below */
#pragma pop
#pragma cplusplus on
#pragma push
#pragma inline_depth(12)
#pragma opt_propagation off
struct V4 {float x,y,z,w;};
struct Transform {VPAD2(a) VPAD1(b) virtual void set(V4*);};
struct Link {char pad[0x94];int id;};
struct Backpack_00257F30 {
 VPAD16(a) VPAD4(b) VPAD1(c) virtual void active(int); VPAD8(d) VPAD4(e) virtual void attach(void*,int);
 char p4[8];int id;char p10[0x40];Transform* transform;char p54[0xC];unsigned char ready;char p61[0x283];int count,a2e8,a2ec;unsigned char dropped;char p2f1[7];int x2f8;Link* link;int x300,x304,x308,x30c;float timer;int x314;
};
struct Reader {int version;int a,b;char* cur;};
struct Weapon {char p0[0x70];int unit;char p74[0x7C];unsigned char kind;};
extern "C" {
extern char D_004F7F68[],D_004DC350[],D_0055C9F0[];
extern int D_004FFD30;
#if 0 /* merge_units */
extern int D_004FFBD0;
#endif /* merge_units */
#define D_004FFBD0 (*(int*)&D_004FFBD0) /* merge_units */

void cGOBJ_ctor(Backpack_00257F30*,int*,int,void*);
#if 0 /* merge_units */
void Backpack_Reset(Backpack_00257F30*,int);
#endif /* merge_units */
#define Backpack_Reset(a0, a1) (Backpack_Reset((void *)(a0), (a1))) /* merge_units */

Weapon* WeaponDb_Get(int,int);
void Backpack_AddWeapon(Backpack_00257F30*,int,int,int,int);
void Object_Register(Backpack_00257F30*);
Link* Hotbox_CreateRuntime(int,Backpack_00257F30*,int,int);
int IdMgr_FindCollision(int,int);
void ZoneMgr_Associate(int,Backpack_00257F30*,int,int);
}
static inline int Read(Reader* r) {int v=*(int*)r->cur;r->cur+=4;return v;}
static inline void ReadFloat(Reader* r,float* out) {*out=*(float*)r->cur;r->cur+=4;}
static inline void Ensure(Backpack_00257F30* obj) {if(!obj->link){obj->active(1);Object_Register(obj);if(!obj->link){obj->link=Hotbox_CreateRuntime(D_004FFBD0,obj,0,1);obj->link->id=obj->id;}}}
extern "C" Backpack_00257F30* cBackpack_ctor(Backpack_00257F30* obj0,Reader* r0) {
 int flag; int weapon;int slot;int n;int amount;Weapon* w;int j;Backpack_00257F30* obj=obj0;Reader* r=r0;
 int id=-1;
 V4 pos;
 cGOBJ_ctor(obj,&id,0,D_004F7F68);
 *(void**)obj=D_004DC350;obj->x304=-2;obj->x300=0;
 Backpack_Reset(obj,0);obj->attach(D_0055C9F0,0);
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
    j=0;if(0<n){do {Backpack_AddWeapon(obj,weapon,(amount-1)*w->unit,w->unit,flag);j++;}while(j<n);}
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
#undef D_004FFBD0 /* merge_units */
#undef Backpack_Reset /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00257F30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00257F30 */

/* merge_units: begin func_00258330 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_propagation off
#pragma opt_strength_reduction off
#pragma opt_unroll_loops off
#define F(p,o,t) (*(t*)((char*)(p)+(o)))
struct WeaponInfo{int a,b;int flags;int c;};
struct Tables{char pad[0x3524];WeaponInfo*weapons;};
struct World{char pad[0x30];Tables*tables;};
extern "C" World*D_004FFC0C;
struct Id{volatile int value;Id(int v):value(v){}}; static inline const Id* Identity(const Id*p){return p;} static inline void Assign(Id*d,const Id*s){d->value=s->value;}
extern "C" void Backpack_Reset(void*self,int preserve){
 WeaponInfo*weapons=D_004FFC0C->tables->weapons;int i=0;char*p=(char*)self;
 do{int flags=weapons[F(p,0x64,unsigned char)].flags;if(!preserve||flags>-1){F(p,0x130,int)=0;F(p,0x134,unsigned char)=0;}i++;p+=0xD4;}while(i<3);
 if(!preserve){F(self,0x2FC,int)=0;F(self,0x30C,int)=2;}
 F(self,0x2E0,int)=3;F(self,0x2E4,int)=0;F(self,0x2F2,unsigned char)=0;F(self,0x300,int)=0;
 Assign(&F(self,0x304,Id),Identity(&Id(-1)));
 F(self,0x2F1,unsigned char)=0;F(self,0x2F3,unsigned char)=0;F(self,0x314,int)=0xBF800000;F(self,0x308,int)=0;F(self,0x2F4,unsigned char)=0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00258330(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00258330 */
