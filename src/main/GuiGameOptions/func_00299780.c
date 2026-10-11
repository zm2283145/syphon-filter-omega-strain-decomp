#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
int func_00414790();                                
int func_004147A0();                                
int func_00414AC0(int, int , int);                  
int func_00418A80(int, int *, int *);                   
int func_00456160();                                  
extern int D_004AA750;
extern int D_004AA760;

void func_00299780(int arg0) {
    int temp_s0;

    if (F_(arg0, 0x400, unsigned char) != 0) {
        func_00456160();
        return;
    }
    temp_s0 = func_00418A80(func_00414790(), &D_004AA750, &D_004AA760);
    func_00414AC0(func_004147A0(), arg0, temp_s0);
}
