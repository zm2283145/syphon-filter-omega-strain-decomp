#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int Alloc_Unlock(int);                                  
char * Mem_Alloc(int, int, char *, int);                    
int func_003D7E90();                                  
int func_003D8C30(int, void **);                      
int memcpy(char * , char *, int);                         
int sprintf(char *, char *, char * );                        
int strlen(char *);                                    
extern char D_00499C71;
extern char D_004BD3B0;
extern char D_004BD3C8;
extern unsigned char D_00533880;
extern int D_00533888;
extern int D_00554F18;

#pragma push
#pragma opt_propagation off
int func_003D8A30(char * arg0, int arg1, int arg2) {
    int temp_v1;
    char * temp_s2;
    int sp60[67];
    char * temp_s1;
    char * var_s0;
    char * sp16C;
    int var_v0;
    int temp_s0;

    var_s0 = arg0;
    if ((*arg0 == 0x67) && ((&D_00499C71)[var_s0[1]] & 1)) {
        var_s0 += 1;
    }
    func_003D7E90();
    sprintf(sp60, &D_004BD3C8, var_s0);
    if (D_00533880 != 0) {
        Alloc_Lock(9);
    }
    D_00533888 += 1;
    temp_s2 = Mem_Alloc(0, 0x20, &D_004BD3B0, 0x89);
    if (D_00533880 != 0) {
        Alloc_Unlock(9);
    }
    D_00533888 -= 1;
    if (temp_s2 != NULL) {
        temp_v1 = strlen((char*)sp60) + 1; temp_s0 = (temp_v1 + 0x1F) / 32 * 32;
        if (D_00533880 != 0) {
            Alloc_Lock(9);
        }
        D_00533888 += 1;
        temp_s1 = Mem_Alloc(0, temp_s0, &D_004BD3B0, 0x130);
        if (D_00533880 != 0) {
            Alloc_Unlock(9);
        }
        D_00533888 -= 1;
        memcpy(temp_s1, sp60, temp_s0);
        F_(temp_s2, 0x0, int) = (int)(temp_s1);
        F_(temp_s2, 0x4, int) = arg2;
        F_(temp_s2, 0x8, signed char) = (signed char) (arg1 != 0);
        F_(temp_s2, 0xC, int) = arg1;
        F_(temp_s2, 0x10, int) = 0;
        F_(temp_s2, 0x14, int) = 0;
        F_(temp_s2, 0x18, signed char) = 0;
        F_(temp_s2, 0x19, signed char) = 0;
    }
    sp16C = temp_s2;
    func_003D8C30(D_00554F18, &sp16C);
    return 0;
}
#pragma pop
