#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Agent_GetSelected(char *, int, int, signed char);               
int func_00332A10(int, int, int, int);                    
extern char D_004ACB30;
extern char D_004FFB50;
extern signed char D_004FFBA0;
extern signed char D_004FFBA1;
extern char * D_004FFC04;
extern signed char D_005064A8;
extern int D_005064B0;
extern int D_005064B8;

void func_002A0DC0(void) {
    int temp_s0;
    signed char temp_a3;

    temp_a3 = D_004FFBA0;
    D_004FFBA1 = temp_a3;
    D_004FFBA0 = 3;
    F_(D_004FFC04, 0x35, signed char) = 1;
    F_(D_004FFC04, 0x33, signed char) = 1;
    temp_s0 = F_(D_004FFC04, 0x248, int);
    if (temp_s0 != -1) {
        func_00332A10(Agent_GetSelected(&D_004FFB50, -1, 3, temp_a3), F_(&D_004ACB30, (temp_s0 * 4), int) + 1, 6, 1);
    }
    D_005064A8 = 0;
    D_005064B0 = 0;
    D_005064B8 = 0;
}
