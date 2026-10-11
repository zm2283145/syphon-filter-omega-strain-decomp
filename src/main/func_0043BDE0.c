#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int func_0041DF00(char * , int, int, int);                 
int func_0041EFA0();                                  

void func_0043BDE0(char * arg0) {
    float r;
    int temp_t1;
    int temp_t0;

    func_0041EFA0();
    if (F_(arg0, 0x48, unsigned char) != 0) {
        temp_t1 = F_(arg0, 0x5C, int);
        temp_t0 = F_(arg0, 0x4C, int);
        r = (float) (F_(arg0, 0x58, int) - temp_t1) / (float) (F_(arg0, 0x60, int) - temp_t1);
        func_0041DF00(arg0, 0xA, temp_t0 + (int) (r * (float) (F_(arg0, 0x50, int) - temp_t0)), 0);
    }
}

