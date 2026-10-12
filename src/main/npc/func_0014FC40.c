#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct CxNpcThunk { VPAD32(a) VPAD8(b) VPAD4(c) VPAD1(d)
virtual void Target(int,int);
};
extern "C" { static inline void CxNpcThunk_Call(CxNpcThunk* self,int arg) { self->Target(arg,100); } }
#pragma cplusplus off
void cNPC_v43(struct CxNpcThunk* self,int arg) { CxNpcThunk_Call(self,arg); }
