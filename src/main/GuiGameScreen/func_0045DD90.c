#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_002B1970(int );                            
int func_004147A0();                                
int func_00414B30(int, int );                       
int func_0041E0F0(int , int, int, int, int);                 
int func_0045DE40(int );                            

#pragma opt_common_subs off
void func_0045DD90(int arg0, int arg1) {
    int temp_v1;
    int temp_v1_2;

    temp_v1 = F_(arg0, 0x4C, int);
    if (temp_v1 != NULL) {
        if (arg1 != 0) {
            F_(temp_v1, 0x14, unsigned short) = (unsigned short) (F_(temp_v1, 0x14, unsigned short) | 2);
        } else {
            F_(temp_v1, 0x14, unsigned short) = (unsigned short) (F_(temp_v1, 0x14, unsigned short) & 0xFFFD);
        }
        if (arg1 != 0) {
            func_002B1970(F_(arg0, 0x4C, int));
            temp_v1_2 = F_(arg0, 0x4C, int);
            F_(temp_v1_2, 0x14, unsigned short) = (unsigned short) (F_(temp_v1_2, 0x14, unsigned short) | 0x80);
            func_00414B30(func_004147A0(), F_(arg0, 0x4C, int));
            func_0041E0F0(F_(arg0, 0x4C, int), func_004147A0(), 0x10, 2, 0);
            return;
        }
        func_0045DE40(arg0);
    }
}
