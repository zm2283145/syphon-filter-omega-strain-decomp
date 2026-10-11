#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
int Alloc_Lock(int);                                    
int Alloc_Unlock(int);                                  
int Mem_Alloc(int, int, int *, int);                      
int func_001361D0(int *);                           
int func_00257450(int , int);                       
int func_00257460(int );                            
extern int D_004A7B50;
extern int D_004F7F30;
extern unsigned char D_00533880;
extern int D_00533888;

void func_00257380(void) {
    int sp2C;
    int temp_s0;

    if (D_00533880 != 0) {
        Alloc_Lock(9);
    }
    D_00533888 += 1;
    temp_s0 = Mem_Alloc(0, 0x10, &D_004A7B50, 0x17D);
    if (D_00533880 != 0) {
        Alloc_Unlock(9);
    }
    D_00533888 -= 1;
    if (temp_s0 != NULL) {
        sp2C = 0x14;
        func_00257460(temp_s0);
        func_00257450(temp_s0, func_001361D0(&sp2C));
        F_(temp_s0, 0xC, signed char) = 1;
    }
    D_004F7F30 = temp_s0;
}
