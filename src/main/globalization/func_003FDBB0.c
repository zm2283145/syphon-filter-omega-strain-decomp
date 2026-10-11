#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int Alloc_Unlock(int);                                  
int Mem_Free(int, int, char *, int);                         
int PtrVector_Resize(char *, int, int *);                
int func_003FEEE0(int, int);                            
extern char D_004BE440;
extern unsigned char D_00533880;
extern int D_00533888;
extern int D_0055CA50;
extern char D_0055CA70;
extern int D_0055CA80;
extern int D_0055D460;
extern int D_0055D468;

void func_003FDBB0(void) {
    int sp2C;
    int temp_s0;

    temp_s0 = D_0055CA50;
    if (temp_s0 != 0) {
        if (D_00533880 != 0) {
            Alloc_Lock(9);
        }
        D_00533888 += 1;
        if ((temp_s0 != 0) && (temp_s0 != 0) && (temp_s0 != 0)) {
            func_003FEEE0(temp_s0, 0);
        }
        Mem_Free(0, temp_s0, &D_004BE440, 0x9B);
        if (D_00533880 != 0) {
            Alloc_Unlock(9);
        }
        D_0055CA50 = 0;
        D_00533888 -= 1;
    }
    sp2C = 0;
    PtrVector_Resize(&D_0055CA70, D_0055CA80, &sp2C);
    D_0055D460 = D_0055D468;
}
