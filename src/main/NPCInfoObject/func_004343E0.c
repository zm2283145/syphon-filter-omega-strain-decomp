#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_004355D0();                                  
char * func_004361C0(int *, int);                      

int func_004343E0(int d0, int arg1) {
    int sp1C;
    unsigned char temp_v0;
    char * temp_v0_2;

    sp1C = arg1;
    func_004355D0();
    temp_v0_2 = func_004361C0(&sp1C, 0);
    if (temp_v0_2 != NULL) {
        temp_v0 = F_(temp_v0_2, 0x4, unsigned char);
        if (temp_v0 != 0xFF) {
            return temp_v0;
        }
    }
    return -1;
}
