#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


extern "C" {
int Mem_Free(...);                      
int cSfxScheduler_ClearItemList(...);                            
int cSfxScheduler_dtor(...);                         
extern int D_004BE020;
extern "C" void Effect_Draw();
extern "C" void Effect_Update();
extern void * const D_004E0760[];
extern unsigned char g_ProfileLockEnabled;
}
extern "C" int SpecFx_dtor(int arg0, long long arg1) {
    if (arg0 != NULL) {
        F_(arg0, 0x14, int) = (int)(&(*(int*)D_004E0760));
        cSfxScheduler_ClearItemList(arg0, arg0);
        cSfxScheduler_dtor(arg0, 0);
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            {
                AllocGuard g;
            Mem_Free(0, arg0, &D_004BE020, 0xE9);
            }
        }
    }
    return arg0;
}
void * const D_004E0760[8] = { (void*)0x0, (void*)0x0, (void*)SpecFx_dtor, (void*)Effect_Update, (void*)Effect_Draw, (void*)0x0, (void*)0x0, (void*)0x0 };
