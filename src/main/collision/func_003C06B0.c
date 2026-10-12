#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
int Alloc_Lock(int);                                    
int Alloc_Unlock(int);                                  
int Mem_Alloc(int, int, int *, int);                      
int func_001361D0(int *);                           
int func_00219DF0(int );                            
int func_0025DBC0(int , int);                       
extern unsigned char D_00533880;
extern int D_00533888;
extern int D_00542D00;

void func_003C06B0(int arg0) {
    int sp3C;
    int temp_s1;

    if (D_00542D00 == NULL) {
        if (D_00533880 != 0) {
            Alloc_Lock(9);
        }
        D_00533888 += 1;
        temp_s1 = Mem_Alloc(0, 0x10, ((int*)"collision.cc"), 0x686);
        if (D_00533880 != 0) {
            Alloc_Unlock(9);
        }
        D_00533888 -= 1;
        if (temp_s1 != NULL) {
            sp3C = arg0;
            func_00219DF0(temp_s1);
            func_0025DBC0(temp_s1, func_001361D0(&sp3C));
            F_(temp_s1, 0xC, signed char) = 1;
        }
        D_00542D00 = temp_s1;
    }
}
