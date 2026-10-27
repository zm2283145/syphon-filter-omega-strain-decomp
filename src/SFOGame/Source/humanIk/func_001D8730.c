#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int EnableIntc(int);                                  
int cMemMan_Deallocate(int, int, char *, int);                         
int cTimerDisable_dtor(char *, int);                            
int cTimerDisable_ctor(char *);                               
int cDrawAndHolsterWeapon_ActionManager_cWeaponSlotTransitionTable_dtor(int, int);                            
extern int D_004F2D80;
extern int D_004F2D88;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;

void cDrawAndHolsterWeapon_ActionManager_UnInitStatics(void) {
    int sp28[2];
    int temp_s0;
    int temp_s0_2;

    temp_s0 = D_004F2D80;
    if (temp_s0 != 0) {
        if (g_ProfileLockEnabled != 0) {
            Alloc_Lock(9);
        }
        g_ProfileLockDepth += 1;
        cMemMan_Deallocate(0, temp_s0, "humanIk.cc", 0x27E);
        if (g_ProfileLockEnabled != 0) {
            EnableIntc(9);
        }
        D_004F2D80 = 0;
        g_ProfileLockDepth -= 1;
    }
    temp_s0_2 = D_004F2D88;
    if (temp_s0_2 != 0) {
        cTimerDisable_ctor(sp28);
        cDrawAndHolsterWeapon_ActionManager_cWeaponSlotTransitionTable_dtor(temp_s0_2, -1);
        cMemMan_Deallocate(0, temp_s0_2, "humanIk.cc", 0x283);
        cTimerDisable_dtor(sp28, -1);
        D_004F2D88 = 0;
    }
}
