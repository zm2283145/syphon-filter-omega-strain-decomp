#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_00443E70();                                
int func_0044D860(char * , int);                       
extern int D_004977B8;

typedef struct { char p0[9596]; int f257C; } PS0_0044D700;
void func_0044D700(PS0_0044D700 *arg0, int arg1) {
    int temp_a0;
    int temp_s0;

    temp_s0 = arg0->f257C;
    temp_a0 = func_00443E70() - temp_s0;
    if ((arg1 == 0) && (temp_s0 != 0)) {
        if (D_004977B8 < temp_a0) {
            goto block_4;
        }
    } else {
block_4:
        func_0044D860(arg0, arg1);
        arg0->f257C = func_00443E70();
    }
}
