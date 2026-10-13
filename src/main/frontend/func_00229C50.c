#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "frontend.h"
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int Mem_Alloc(...);                        
int func_001698C0(...);                                  
int FrontEndScene_LoadSkeletons(...);                               
int func_0022A040(...);                       
int MotionManager_Init(...);                                  
extern unsigned char D_00533880;
extern int D_00543790;
extern int D_00543794;
}
#pragma push
#pragma push
#pragma opt_propagation off
/* Second construction stage (called by gameFrontEnd after FrontEndScene_ctor):
 * loads the front-end skeletons and allocates the character set. */
extern "C" void FrontEndScene_Init(FrontEndScene* self) {
    int characters;

    FrontEndScene_LoadSkeletons(self, self->archives);
    MotionManager_Init();
    D_00543790 = 0;
    D_00543794 = 0;
    func_001698C0();
    {
        AllocGuard g;
    characters = Mem_Alloc(0, 0x18, ((int*)"frontend.cc"), 0x76);
    }
    /* barrier: empty arm keeps the label (and its padding nop) before the store */
    if (characters == 0) asm { .set reorder } 
    self->characters = (void*)characters;
    func_0022A040(self->characters, self->archives);
}
#pragma pop
#pragma pop
