#include "types.h"
typedef struct CxBurstActor { char pad0[0xC]; int serial; char pad10[0x3524-0x10]; void* weapons; } CxBurstActor;
typedef struct CxBurstNpc { char pad0[0x30]; CxBurstActor* actor; char pad34[0xA4-0x34]; int burst; int shots; } CxBurstNpc;
extern int func_001B16C0(CxBurstActor*);
extern int Random_Next(void);
extern int WeaponInv_GetClipSize(void*,int);
void func_0014FC60(CxBurstNpc* self) {
    CxBurstActor* actor=self->actor;
    if(func_001B16C0(actor)) {
        void* weapons=actor->weapons;
        self->burst=(self->actor->serial&7)+3;
        if(Random_Next()&1)self->burst++;
        if(self->burst>WeaponInv_GetClipSize(weapons,6)) {
            int n=WeaponInv_GetClipSize(weapons,6)/2;
            if(n<=0)n=1;
            self->burst=n;
        }
    } else self->burst=0;
    self->shots=0;
}
