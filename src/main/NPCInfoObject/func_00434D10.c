#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int Alloc_Unlock(int);                                  
char * Mem_Alloc(int, int, char *, int);                      
int func_00434BB0(char *, void **);                      
extern char D_004BFCA0;
extern unsigned char D_00533880;
extern int D_00533888;
extern char D_00582B10;

void func_00434D10(int d0, char * arg1) {
    char * sp3C;
    char * temp_s0;

    if (D_00533880 != 0) {
        Alloc_Lock(9);
    }
    D_00533888 += 1;
    temp_s0 = Mem_Alloc(0, 0x14, &D_004BFCA0, 0x2F4);
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
    sp3C = temp_s0;
    func_00434BB0(&D_00582B10, &sp3C);
}
