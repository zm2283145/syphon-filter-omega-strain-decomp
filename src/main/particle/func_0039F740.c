#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
/*fc*/
int cMemMan_Deallocate(...);                         
int cTexMan_RemoveTexture(...);                       
int operator_delete(...);                          
extern char D_004BC5D0;
extern char D_004DFAD8;
extern "C" void cParticleShatter_Render();
extern "C" void cParticleShatter_NextFrame();
extern "C" void cParticleShatter_Done();
extern "C" void cParticleBase_GetRenderMatrix();
extern "C" void cParticleShatter_Definition();
extern void * const D_004DFB10[];
extern char D_004DFB50;
extern unsigned char g_ProfileLockEnabled;
extern int g_TextureMgr;
}
#pragma opt_common_subs off
extern "C" char * cParticleShatter_dtor(char * arg0, long long arg1) {
    int temp_a1;
    int temp_s2;

    if (arg0 != NULL) {
        F_(arg0, 0x0, int) = (int)(&(*(char*)D_004DFB10));
        temp_a1 = F_(arg0, 0x170, int);
        if (temp_a1 >= 0) {
            cTexMan_RemoveTexture(g_TextureMgr, temp_a1, 1);
        }
        temp_s2 = F_(arg0, 0x124, int);
        if (temp_s2 != 0) {
            {
                AllocGuard g;
            cMemMan_Deallocate(0, temp_s2, &D_004BC5D0, 0x99B);
            }
            F_(arg0, 0x124, int) = 0;
        }
        if (arg0 != NULL) {
            F_(arg0, 0x0, int) = (int)(&D_004DFB50);
            if (arg0 != NULL) {
                F_(arg0, 0x0, int) = (int)(&D_004DFAD8);
            }
        }
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
void * const D_004DFB10[8] = { (void*)0x0, (void*)0x0, (void*)cParticleShatter_dtor, (void*)cParticleShatter_Render, (void*)cParticleShatter_NextFrame, (void*)cParticleShatter_Definition, (void*)cParticleShatter_Done, (void*)cParticleBase_GetRenderMatrix };
