#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC003B4F10 { virtual int v0(...); };
extern "C" {
int Alloc_Lock(...);                                    
int EnableIntc(...);                                  
void **cMemMan_Allocate(...);                     
int cMemMan_Deallocate(...);                     
int cSkaAnimationSet_AddNode(...);          
void **cSkaAnim_ctor_cSkaAnimDataR(...);               
extern int D_004BCD60;
extern char D_004BCD70;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
}
extern "C" void cSkaAnimationSet_CreateNode_cString16NR_cSkaAnimDataR(int *arg0, int arg1, int arg2, int arg3) {
    int sp6C;
    void **var_s0;

    if (g_ProfileLockEnabled != 0) {
        Alloc_Lock(9);
    }
    g_ProfileLockDepth += 1;
    var_s0 = cMemMan_Allocate(0, 0x50, &D_004BCD70, 0x216);
    if (g_ProfileLockEnabled != 0) {
        EnableIntc(9);
    }
    g_ProfileLockDepth -= 1;
    if (var_s0 != NULL) {
        var_s0 = cSkaAnim_ctor_cSkaAnimDataR(var_s0, arg3);
    }
    cSkaAnimationSet_AddNode(&sp6C, arg1, arg2, var_s0);
    if (sp6C == D_004BCD60) {
        if (g_ProfileLockEnabled != 0) {
            Alloc_Lock(9);
        }
        g_ProfileLockDepth += 1;
        ((VC003B4F10 *)(var_s0))->v0(-1);
        cMemMan_Deallocate(0, var_s0, &D_004BCD70, 0x21C);
        if (g_ProfileLockEnabled != 0) {
            EnableIntc(9);
        }
        g_ProfileLockDepth -= 1;
    }
    *arg0 = sp6C;
}
