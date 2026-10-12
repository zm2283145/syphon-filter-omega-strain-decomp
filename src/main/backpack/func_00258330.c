#pragma cplusplus on

#include "types.h"
#pragma opt_propagation off
#pragma opt_strength_reduction off
#pragma opt_unroll_loops off
#define F(p,o,t) (*(t*)((char*)(p)+(o)))
struct WeaponInfo{int a,b;int flags;int c;};
struct Tables{char pad[0x3524];WeaponInfo*weapons;};
struct World{char pad[0x30];Tables*tables;};
extern "C" World*D_004FFC0C;
struct Id{volatile int value;Id(int v):value(v){}}; static inline const Id* Identity(const Id*p){return p;} static inline void Assign(Id*d,const Id*s){d->value=s->value;}
extern "C" void func_00258330(void*self,int preserve){
 WeaponInfo*weapons=D_004FFC0C->tables->weapons;int i=0;char*p=(char*)self;
 do{int flags=weapons[F(p,0x64,unsigned char)].flags;if(!preserve||flags>-1){F(p,0x130,int)=0;F(p,0x134,unsigned char)=0;}i++;p+=0xD4;}while(i<3);
 if(!preserve){F(self,0x2FC,int)=0;F(self,0x30C,int)=2;}
 F(self,0x2E0,int)=3;F(self,0x2E4,int)=0;F(self,0x2F2,unsigned char)=0;F(self,0x300,int)=0;
 Assign(&F(self,0x304,Id),Identity(&Id(-1)));
 F(self,0x2F1,unsigned char)=0;F(self,0x2F3,unsigned char)=0;F(self,0x314,int)=0xBF800000;F(self,0x308,int)=0;F(self,0x2F4,unsigned char)=0;
}
