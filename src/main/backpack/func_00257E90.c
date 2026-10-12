#include "types.h"
typedef struct Backpack{void*vt;char pad[0x2F8];void*actor;}Backpack;
extern char D_004DC350[];extern void*D_004FFBD0;
void func_00170DB0(void*,void*);void Object_Unregister(void*);void func_003CB230(void*,float);void cGOBJ_dtor(Backpack*,int);void operator_delete(void*);
Backpack*cBackpack_dtor(Backpack*self,int flags){
 if(self){self->vt=D_004DC350;if(self->actor){func_00170DB0(D_004FFBD0,self->actor);Object_Unregister(self->actor);func_003CB230(self->actor,0.1f);self->actor=0;}
 cGOBJ_dtor(self,0);if((short)flags>0)operator_delete(self);}
 return self;
}
