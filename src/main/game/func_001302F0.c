#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
char * Archive_Open(int, char *, int, int);                 
int func_0036D2A0();                  
int func_003F9530();                       
int sprintf();                           
extern int D_00489BE0;

int func_001302F0(int arg0) {
    int sp50[32];
    int sp30[8];
    char * temp_v0;

    if (D_00489BE0 != -1) {
        return D_00489BE0;
    }
    sprintf(sp50, "ZMEDIA\\ZMOVIES.HOG");
    temp_v0 = (char *)(Archive_Open(arg0 + 0x3C, sp50, 1, 0));
    if (F_(temp_v0, 0x14C, unsigned char) != 0) {
        D_00489BE0 = 0;
loop_5:
        sprintf(sp30, "DEMO%2.2d.PSS", D_00489BE0 + 1);
        if (func_0036D2A0(temp_v0, sp30, 1) != -1) {
            D_00489BE0 += 1;
            goto loop_5;
        }
    }
    func_003F9530(arg0 + 0x3C, temp_v0);
    D_00489BE0 += 1;
    return D_00489BE0;
}
