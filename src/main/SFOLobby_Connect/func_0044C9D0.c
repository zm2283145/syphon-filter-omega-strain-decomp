#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_00451B00(char * , int, char *, int);                 
int func_00468CD0();                                
extern char D_004C0E80;

typedef struct { char p0[384]; int f180; int f184; char p188[196]; int f24C; } PS0_0044C9D0;
int func_0044C9D0(PS0_0044C9D0 *arg0) {
    arg0->f24C = func_00468CD0();
    if (arg0->f24C != 0) {
        func_00451B00(arg0, 0x2B, &D_004C0E80, 0x2A0);
        return 0;
    }
    arg0->f180 = -1;
    arg0->f184 = 0;
    return 1;
}
