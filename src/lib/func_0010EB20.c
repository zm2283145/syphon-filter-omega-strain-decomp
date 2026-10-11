#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int func_0010EA30();                                 

void func_0010EB20(int arg0) {
    if (arg0 == 0xA) {
        func_0010EA30(0xD);
        func_0010EA30(0xA);
        return;
    }
    func_0010EA30();
}
