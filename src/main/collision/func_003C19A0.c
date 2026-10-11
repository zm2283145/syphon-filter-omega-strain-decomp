#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_00181E80(int, int *);                             
int func_00182260(int, int *);                             

void func_003C19A0(int arg0) {
    int sp1C;
    int sp18;

    if (F_(arg0, 0x4, int) > 0) {
        sp1C = F_(arg0, 0x8, int);
        func_00182260(arg0, &sp1C);
        return;
    }
    sp18 = F_(arg0, 0x10, int);
    func_00181E80(arg0, &sp18);
}
