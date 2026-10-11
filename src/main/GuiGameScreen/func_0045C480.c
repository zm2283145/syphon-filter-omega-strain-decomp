#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int WeaponDb_Get(int, int);                         
int func_001437E0(int);                             
int func_00143B60(int, int);                          
int func_00143D20(int, int);                        
int func_00175FF0(char * , int);                       
extern char * D_004FFC0C;
extern int D_004FFD30;

void func_0045C480(char * arg0) {
    int temp_a1;
    int temp_s2;
    int temp_a1_2;
    char * temp_s1;
    int temp_v0;

    temp_a1 = F_(arg0, 0x90, int);
    if (temp_a1 != -1) {
        temp_a1_2 = temp_a1 * 4;
        temp_s2 = *(int *)((char *)F_(arg0, 0x78, int) + temp_a1_2);
        temp_s1 = (char *)(F_(D_004FFC0C, 0x30, int));
        if (temp_s2 != -2) {
            if ((func_00143D20(temp_s2, temp_a1_2) & 0xFF) < 6) {
                temp_v0 = WeaponDb_Get(D_004FFD30, temp_s2);
                if ((temp_v0 != 0) && (temp_v0 != func_001437E0(F_(temp_s1, 0x3524, int)))) {
                    func_00175FF0(D_004FFC0C, temp_s2);
                }
            }
        } else {
            func_00143B60(F_(temp_s1, 0x3524, int), temp_a1_2);
        }
    }
}
