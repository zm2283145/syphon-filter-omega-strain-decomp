#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "frontend.h"
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int cMemMan_Allocate(...);                        
int GetMachine(...);                                  
int cFrontendSystem_LoadSkeletons(...);                               
int CCI_Screen_ScreenInit(...);                       
int cMotionManager_InitStatics(...);                                  
extern unsigned char g_ProfileLockEnabled;
extern int D_00543790;
extern int D_00543794;
}
#pragma push
#pragma push
#pragma opt_propagation off
/* Second construction stage (called by gameFrontEnd after cFrontendSystem_ctor):
 * loads the front-end skeletons and allocates the character set. */
extern "C" void cFrontendSystem_Init(FrontEndScene* self) {
    int characters;

    cFrontendSystem_LoadSkeletons(self, self->archives);
    cMotionManager_InitStatics();
    D_00543790 = 0;
    D_00543794 = 0;
    GetMachine();
    {
        AllocGuard g;
    characters = cMemMan_Allocate(0, 0x18, ((int*)"frontend.cc"), 0x76);
    }
    /* barrier: empty arm keeps the label (and its padding nop) before the store */
    if (characters == 0) asm { .set reorder } 
    self->characters = (void*)characters;
    CCI_Screen_ScreenInit(self->characters, self->archives);
}
#pragma pop
#pragma pop
