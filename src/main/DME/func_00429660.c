#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int Alloc_Unlock(int);                                  
char * Mem_Alloc(int, int, char *, int);                      
int func_00429770(char *, void **);                      
int strncpy(char * , int, int);                          
extern char D_004BF9B0;
extern unsigned char D_00533880;
extern int D_00533888;
extern unsigned char D_005723C8;
extern char D_005724A0;

#pragma push
#pragma opt_common_subs off
void func_00429660(int arg0, int arg1) {
    struct { char pad40[8]; char * f48[2]; } sl;
    char * temp_s0;

    if (D_005723C8 == 0) {
        D_005723C8 = 1;
    }
    if (D_00533880 != 0) {
        Alloc_Lock(9);
    }
    D_00533888 += 1;
    temp_s0 = Mem_Alloc(0, 0x14, &D_004BF9B0, 0x72F);
    if (D_00533880 != 0) {
        Alloc_Unlock(9);
    }
    D_00533888 -= 1;
    if (temp_s0 != NULL) {
        F_(temp_s0, 0x10, int) = 0xE4A;
    }
    sl.f48[0] = temp_s0;
    strncpy(temp_s0, arg0, 0x10);
    F_(sl.f48[0], 0x10, int) = arg1;
    func_00429770(&D_005724A0, sl.f48);
    D_005723C8 = 0;
}
#pragma pop
