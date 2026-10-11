#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int Alloc_Unlock(int);                                  
char * Mem_Alloc(int, int, char *, int);                      
int func_00436DD0(char *, char *, void **);                 
extern char D_004BFCA0;
extern unsigned char D_00533880;
extern int D_00533888;
extern char D_00582B50;

#pragma push
#pragma opt_common_subs off
void func_00434BE0(int d0, char * arg1, signed char arg2) {
    struct { char pad40[8]; char * f48; signed char f4C[4]; int f50[4]; } sl;
    char * temp_s0;

    if (D_00533880 != 0) {
        Alloc_Lock(9);
    }
    D_00533888 += 1;
    temp_s0 = Mem_Alloc(0, 0x14, &D_004BFCA0, 0x300);
    if (D_00533880 != 0) {
        Alloc_Unlock(9);
    }
    D_00533888 -= 1;
    if (temp_s0 != NULL) {
        F_(temp_s0, 0x4, unsigned char) = F_(arg1, 0x4, unsigned char);
        F_(temp_s0, 0x0, int) = F_(arg1, 0x0, int);
        F_(temp_s0, 0x5, unsigned char) = F_(arg1, 0x5, unsigned char);
        F_(temp_s0, 0x6, unsigned char) = F_(arg1, 0x6, unsigned char);
        F_(temp_s0, 0xA, unsigned char) = F_(arg1, 0xA, unsigned char);
        F_(temp_s0, 0x7, unsigned char) = F_(arg1, 0x7, unsigned char);
        F_(temp_s0, 0xB, unsigned char) = F_(arg1, 0xB, unsigned char);
        F_(temp_s0, 0x8, unsigned char) = F_(arg1, 0x8, unsigned char);
        F_(temp_s0, 0xC, unsigned char) = F_(arg1, 0xC, unsigned char);
        F_(temp_s0, 0x9, unsigned char) = F_(arg1, 0x9, unsigned char);
        F_(temp_s0, 0xD, unsigned char) = F_(arg1, 0xD, unsigned char);
        F_(temp_s0, 0x10, int) = F_(arg1, 0x10, int);
    }
    sl.f48 = temp_s0;
    sl.f4C[0] = arg2;
    func_00436DD0(sl.f50, &D_00582B50, &sl.f48);
}
#pragma pop
