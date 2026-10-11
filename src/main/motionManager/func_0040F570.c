#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Mem_Free(int, int, char *, int);                         
int func_0012F530(char *, int);                            
int func_00136DA0(char *);                               
int func_0040F5E0(int, int);                            
extern char D_004BEDD0;
extern int D_00571CD0;

void func_0040F570(void) {
    int sp2C;
    int temp_s0;

    temp_s0 = D_00571CD0;
    if (temp_s0 != 0) {
        func_00136DA0(&sp2C);
        func_0040F5E0(temp_s0, -1);
        Mem_Free(0, temp_s0, &D_004BEDD0, 0x2B);
        func_0012F530(&sp2C, -1);
        D_00571CD0 = 0;
    }
}
