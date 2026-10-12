#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int Alloc_Unlock(int);                                  
int Mem_Free(int, int, char *, int);                         
int func_0012F530(char *, int);                            
int func_00136DA0(char *);                               
int func_00408FB0(int, int);                            
int func_0040A210(int, int);                            
extern unsigned char D_00533880;
extern int D_00533888;

typedef struct { int f0; int f4; unsigned char f8; } PS0_00408EA0;
void func_00408EA0(PS0_00408EA0 *arg0) {
    int sp38[2];
    int temp_s1;
    int temp_s1_2;

    if (arg0->f8 != 0) {
        temp_s1 = arg0->f0;
        func_00136DA0(sp38);
        func_00408FB0(temp_s1, -1);
        Mem_Free(0, temp_s1, "materialProperties.cc", 0x75);
        func_0012F530(sp38, -1);
        arg0->f0 = 0;
        temp_s1_2 = arg0->f4;
        if (D_00533880 != 0) {
            Alloc_Lock(9);
        }
        D_00533888 += 1;
        if ((temp_s1_2 != 0) && (temp_s1_2 != 0) && (temp_s1_2 != 0)) {
            func_0040A210(temp_s1_2, 0);
        }
        Mem_Free(0, temp_s1_2, "materialProperties.cc", 0x78);
        if (D_00533880 != 0) {
            Alloc_Unlock(9);
        }
        D_00533888 -= 1;
        arg0->f4 = 0;
        arg0->f8 = 0U;
    }
}
