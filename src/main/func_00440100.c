#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_0042D300(int *);                             
extern unsigned char D_005721D0;
extern unsigned char D_005723C8;

int func_00440100(int d0, int d1, int d2, char * arg3) {
    int sp18[2];

    if (D_005723C8 == 0) {
        D_005723C8 = 1;
    }
    if (D_005721D0 != 0) {
        sp18[0] = F_(arg3, 0x8, int);
        func_0042D300(sp18);
    }
    D_005723C8 = 0;
    return 0xC;
}
