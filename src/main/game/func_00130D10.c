#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int Alloc_Lock(int);                                    
int Alloc_Unlock(int);                                  
int *Mem_Alloc(int, int, char *, int);                     
int String_Copy(int *, int);                          
int func_00130F20(int, int **);                       
int strlen(int);                                    
extern char D_0049A890;
extern unsigned char D_00533880;
extern int D_00533888;

void func_00130D10(int arg0, int arg1, int arg2, int arg3) {
    int temp_s4;
    int *var_s4;
    int *sp6C;
    int *temp_s3_2;
    int *temp_s2;
    int temp_s3;

    temp_s3 = strlen(arg2) + 1;
    if (D_00533880 != 0) {
        Alloc_Lock(9);
    }
    D_00533888 += 1;
    temp_s3_2 = (char *)(Mem_Alloc(0, temp_s3, &D_0049A890, 0x92C));
    if (D_00533880 != 0) {
        Alloc_Unlock(9);
    }
    var_s4 = NULL;
    D_00533888 -= 1;
    String_Copy(temp_s3_2, arg2);
    if (arg3 != 0) {
        temp_s4 = strlen(arg3) + 1;
        if (D_00533880 != 0) {
            Alloc_Lock(9);
        }
        D_00533888 += 1;
        var_s4 = (char *)(Mem_Alloc(0, temp_s4, &D_0049A890, 0x933));
        if (D_00533880 != 0) {
            Alloc_Unlock(9);
        }
        D_00533888 -= 1;
        String_Copy(var_s4, arg3);
    }
    if (D_00533880 != 0) {
        Alloc_Lock(9);
    }
    D_00533888 += 1;
    temp_s2 = (char *)(Mem_Alloc(0, 0xC, &D_0049A890, 0x937));
    if (D_00533880 != 0) {
        Alloc_Unlock(9);
    }
    sp6C = temp_s2;
    D_00533888 -= 1;
    *temp_s2 = arg1;
    F_(sp6C, 0x4, int) = (int)(temp_s3_2);
    F_(sp6C, 0x8, int) = (int)(var_s4);
    func_00130F20(arg0 + 0x2C, &sp6C);
}
