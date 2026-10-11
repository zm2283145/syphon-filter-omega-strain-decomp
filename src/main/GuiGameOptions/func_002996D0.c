#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int func_0029AA50(int, int);                                 
int func_002C9510(int);                               
int func_002C9860(int, int);                            
int func_002CAC80(int, int);                          
int func_0045A3A0(int , int);                         
extern float D_004C1FC8;
extern int D_004FFC04;
extern int D_005383C0;

void func_002996D0(int arg0, int arg1) {
    F_(arg0, 0x78, int) = 0;
    F_(arg0, 0xD8, int) = 0;
    func_0029AA50(arg0, 0x800);
    func_002C9860(D_004FFC04, 1);
    func_0045A3A0(arg0 + 0xB8, 0x800);
    func_002C9510(D_004FFC04);
    D_005383C0 = (int) (F_(arg0, 0xD4, float) * D_004C1FC8) & 0xFF;
    if (arg1 != 0) {
        func_002CAC80(D_004FFC04, F_(arg0, 0x48, int));
    }
}
