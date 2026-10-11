#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
int __destroy_array(int , int *, int, int);               
int func_00255F10(int);                               
int func_003E8EB0(int);                               
int operator_delete(int );                          
extern int func_00251290;

int func_00252FB0(int arg0, long long arg1) {
    int temp_a0;
    int temp_a0_2;

    if (arg0 != NULL) {
        func_00255F10(F_(arg0, 0x0, int));
        func_003E8EB0(F_(arg0, 0x9C, int));
        func_003E8EB0(F_(arg0, 0xA0, int));
        func_003E8EB0(F_(arg0, 0xA4, int));
        func_003E8EB0(F_(arg0, 0xA8, int));
        func_003E8EB0(F_(arg0, 0xAC, int));
        temp_a0 = F_(arg0, 0xB0, int);
        if (temp_a0 != 0) {
            func_003E8EB0(temp_a0);
        }
        temp_a0_2 = F_(arg0, 0xB4, int);
        if (temp_a0_2 != 0) {
            func_003E8EB0(temp_a0_2);
        }
        __destroy_array(arg0 + 4, &func_00251290, 0x1C, 5);
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
