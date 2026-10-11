#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int Alloc_Unlock(int);                                  
int *Mem_Alloc(int, int, char *, int);                       
int ScriptStr_AppendTracking(char * , int **);         
int Str_Duplicate(int);                               
extern char D_004BD4C0;
extern unsigned char D_00533880;
extern int D_00533888;

int ScriptStr_CopyTracked(char * arg0, int arg1) {
    int temp_s0;
    int *sp4C;
    int *temp_s2;

    if (D_00533880 != 0) {
        Alloc_Lock(9);
    }
    D_00533888 += 1;
    temp_s2 = Mem_Alloc(0, 0xC, &D_004BD4C0, 0x66E);
    if (D_00533880 != 0) {
        Alloc_Unlock(9);
    }
    D_00533888 -= 1;
    if (temp_s2 != NULL) {
        temp_s0 = F_(arg0, 0x4E7C, int);
        F_(temp_s2, 0x0, int) = Str_Duplicate(arg1);
        F_(temp_s2, 0x4, int) = 0;
        F_(temp_s2, 0x8, int) = temp_s0;
    }
    sp4C = temp_s2;
    ScriptStr_AppendTracking(arg0 + 0x18, &sp4C);
    return *sp4C;
}
