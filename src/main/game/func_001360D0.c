#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
int Alloc_Lock(int);                                    
int Alloc_Unlock(int);                                  
int Mem_Alloc(int, int, int *, int);                      
int func_001361C0(int , int);                       
int func_001361D0(int *);                           
int func_001361E0(int );                            
int func_00139920(int , int);                       
extern int D_004EA0C0;
extern unsigned char D_00533880;
extern int D_00533888;

void func_001360D0(int arg0) {
    int sp3C;
    int temp_s1;

    if (D_004EA0C0 == NULL) {
        if (D_00533880 != 0) {
            Alloc_Lock(9);
        }
        D_00533888 += 1;
        temp_s1 = Mem_Alloc(0, 0x10, ((int*)"collision.hh"), 0xAE6);
        if (D_00533880 != 0) {
            Alloc_Unlock(9);
        }
        D_00533888 -= 1;
        if (temp_s1 != NULL) {
            sp3C = arg0;
            func_001361E0(temp_s1);
            func_001361C0(temp_s1, func_001361D0(&sp3C));
            F_(temp_s1, 0xC, signed char) = 1;
        }
        D_004EA0C0 = temp_s1;
        return;
    }
    func_00139920(D_004EA0C0, arg0);
}
