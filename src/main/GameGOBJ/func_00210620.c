#define LOCALID_(X) { int ld_a = D_005721A8; /* read before the flag test: retail loads it ahead of the branch */ if (D_005721C8) { if (D_00494178 == -1) NetGame_InitLocalSlot(&D_00494178, ld_a); X = D_00494178; } else X = 0; }
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Lift_SeekFloor(int, int, int, int);                     
int Object_LookupById(int *, int);                  
int func_002EB650(void **);                         
int NetGame_InitLocalSlot(int *, int);                        
extern int D_00494178;
extern int D_005721A8;
extern unsigned char D_005721C8;
extern unsigned char D_005723C8;

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void func_00210620(void) {
    struct { char pad[4]; int f14; char* f18; } sl;
    int temp_v0;
    int var_a1;
    char* o;

    if (D_005723C8 == 0) {
        D_005723C8 = 1;
    }
    if (func_002EB650(&sl.f18) == 0) {
        LOCALID_(var_a1)
        o = sl.f18;
        if (F_(o, 0x4, int) == var_a1) {
            sl.f14 = *F_(o, 0x1C, int*);
            temp_v0 = Object_LookupById(&sl.f14, var_a1);
            if (temp_v0 != 0) {
                { int k = 1; Lift_SeekFloor(temp_v0, -1, k, k); }
            }
        }
    }
    D_005723C8 = 0;
}

#pragma pop
