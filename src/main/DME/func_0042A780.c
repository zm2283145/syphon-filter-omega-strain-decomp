#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int func_002EBCE0(char *);                               
int Gui_GetScreenStack();                             
int func_0041E0F0(int, int, int, int, int);                    
int func_0042ACD0();                                
extern signed char D_005721E0;
extern signed char D_005721F0;
extern signed char D_005723B0;
extern signed char D_00572468;
extern int D_00572470;
extern int D_00572478;
extern signed char D_005724B0;

extern char D_004BF9B8;
void func_0042A780(void) {
    int sp2C;
    int temp_a0;
    int temp_s0;

    D_005723B0 = 0;
    D_005721E0 = 0;
    D_005724B0 = 5;
    D_005721F0 = 0;
    if (func_0042ACD0() == 0) {
        func_002EBCE0(&sp2C);
        return;
    }
    temp_a0 = D_00572470 + 1;
    D_00572470 = temp_a0;
    if (temp_a0 < D_00572478) {
        D_00572468 = 1;
        return;
    }
    if (Gui_GetScreenStack(temp_a0) != 0) {
        temp_s0 = Gui_GetScreenStack();
        func_0041E0F0(temp_s0, Gui_GetScreenStack(), 0x1E, 0, (int)&D_004BF9B8);
    }
    D_00572470 = 0;
    D_00572478 = 0;
}

