#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
/*fc*/
int Loc_LookupText();                            
int func_004147A0();                                
int func_00414B30();                       
int func_0041E0F0();                 
int func_00421290();                 
int func_0045BF80();                                  
extern char D_004C21E0;

typedef struct { char p0[224]; int fE0; char pE4[4]; int fE8; char pEC[4]; int fF0; char pF4[28]; signed char f110; } PS0_0045C030;
void cPlayer_LaunchChooseMenu(PS0_0045C030 *arg0, char *arg1) {
    char * temp_v1;

    temp_v1 = (char *)(arg0->fE0);
    if (temp_v1 != NULL) {
        if (F_(arg0->fE8, 0x94, int) != 0) {
            F_(temp_v1, 0x14, unsigned short) = (unsigned short) (F_(temp_v1, 0x14, unsigned short) | 2);
            func_00414B30(func_004147A0(), arg0->fE8);
            func_00421290(arg0->fE8, Loc_LookupText(&D_004C21E0), -1, 0);
            arg0->fF0 = (int)(arg1);
            arg0->f110 = 0;
            func_0041E0F0(arg0->fE0, func_004147A0(), 0x10, 2, 0);
            return;
        }
        func_0045BF80();
    }
}
