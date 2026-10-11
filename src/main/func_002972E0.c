#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int Agent_GetSelected();                      
signed char func_00332860();                      
extern char D_004FFB50;

void func_002972E0(int arg0) {
    int temp_s1;
    int var_s0;
    signed char temp_v0;
    char * temp_v1;

    temp_s1 = Agent_GetSelected(&D_004FFB50, -1);
    var_s0 = 0;
    do {
        temp_v0 = func_00332860(temp_s1, var_s0 + 1, -1);
        temp_v1 = (char *)(arg0 + var_s0);
        var_s0 += 1;
        F_(temp_v1, 0xF8, signed char) = temp_v0;
    } while (var_s0 <= 0x11);
}
