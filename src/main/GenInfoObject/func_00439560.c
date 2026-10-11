#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int Alloc_Unlock(int);                                  
int Mem_Free(int, int, char *, int);                         
int func_002EB650(void **, int);                    
extern int D_00497578;
extern char D_004BFD60;
extern unsigned char D_00533880;
extern int D_00533888;
extern unsigned char D_005723C8;
extern signed char D_00583880;
extern int D_00583888;

void func_00439560(int d0, int arg1) {
    char * sp38[2];
    int temp_s1;

    if (D_005723C8 == 0) {
        D_005723C8 = 1;
    }
    if (func_002EB650((void **)sp38, arg1) == 0) {
        temp_s1 = D_00583888;
        if (temp_s1 != 0) {
            if (D_00533880 != 0) {
                Alloc_Lock(9);
            }
            D_00533888 += 1;
            Mem_Free(0, temp_s1, &D_004BFD60, 0x234);
            if (D_00533880 != 0) {
                Alloc_Unlock(9);
            }
            D_00533888 -= 1;
        }
        D_00583888 = F_(sp38[0], 0x1C, int);
        D_00583880 = 1;
        D_00497578 = arg1;
    }
    D_005723C8 = 0;
}
