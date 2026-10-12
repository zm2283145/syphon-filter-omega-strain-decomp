#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
char * WeaponDb_Get(int);
int WeaponInv_RemoveSlot(char * , int, int, int, int);
int WeaponInv_SlotOfItem(int);
extern int D_0049D010;
extern int D_004FFD30;

void func_00176060(char * arg0, int arg1) {
    int temp_a2;
    int temp_v0;
    int var_a1;
    char * temp_a0;
    char * temp_s1;

    temp_s1 = (char *)(F_(arg0, 0x30, int));
    if ((temp_s1 != NULL) && (F_(temp_s1, 0x4C, int) == D_0049D010) && (F_(WeaponDb_Get(D_004FFD30), 0x13C, int) != 0)) {
        temp_v0 = WeaponInv_SlotOfItem(arg1);
        temp_a0 = (char *)(F_(temp_s1, 0x3524, int));
        temp_a2 = temp_v0 & 0xFF;
        var_a1 = temp_v0;
        if (arg1 == F_((char *)(temp_a2 * 0x10) + (int)temp_a0, 0x8, int)) {
            if ((temp_a2 == 0) && (arg1 == F_(temp_a0, 0x18, int))) {
                var_a1 = 1;
            }
            WeaponInv_RemoveSlot(temp_a0, var_a1, 1, 0, 0);
        }
    }
}
