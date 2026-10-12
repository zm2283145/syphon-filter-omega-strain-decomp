#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
int Loc_LookupText(int *, int );                    
int func_0041BEB0(int, int, int);                       

#pragma opt_common_subs off
void func_002999B0(int arg0) {
    int *var_a0;
    int temp_a1;
    int temp_a1_2;

    if (F_(arg0, 0x400, unsigned char) != 0) {
        temp_a1 = F_(arg0, 0x80, int);
        if (temp_a1 != NULL) {
            if (F_(arg0, 0xB4, int) != 3) {
                F_(temp_a1, 0x14, unsigned short) = (unsigned short) (F_(temp_a1, 0x14, unsigned short) | 2);
            } else {
                F_(temp_a1, 0x14, unsigned short) = (unsigned short) (F_(temp_a1, 0x14, unsigned short) & 0xFFFD);
            }
        }
        temp_a1_2 = F_(arg0, 0x84, int);
        if (temp_a1_2 != NULL) {
            if (F_(arg0, 0xB4, int) == 3) {
                F_(temp_a1_2, 0x14, unsigned short) = (unsigned short) (F_(temp_a1_2, 0x14, unsigned short) | 2);
            } else {
                F_(temp_a1_2, 0x14, unsigned short) = (unsigned short) (F_(temp_a1_2, 0x14, unsigned short) & 0xFFFD);
            }
        }
        if (F_(arg0, 0x88, int) != 0) {
            if (F_(arg0, 0xB4, int) == 3) {
                var_a0 = ((int*)"ToKick");
            } else {
                var_a0 = ((int*)"ToSave");
            }
            func_0041BEB0(F_(arg0, 0x88, int), Loc_LookupText(var_a0, temp_a1_2), 0);
        }
    }
}
