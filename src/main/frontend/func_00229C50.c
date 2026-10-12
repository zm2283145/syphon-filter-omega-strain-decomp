#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int Mem_Alloc(...);                        
int func_001698C0(...);                                  
int func_00229B90(...);                               
int func_0022A040(...);                       
int func_0040F650(...);                                  
extern unsigned char D_00533880;
extern int D_00543790;
extern int D_00543794;
}
#pragma push
#pragma push
#pragma opt_propagation off
extern "C" void func_00229C50(int arg0) {
    int temp_s1;

    func_00229B90(arg0, arg0 + 0x2C);
    func_0040F650();
    D_00543790 = 0;
    D_00543794 = 0;
    func_001698C0();
    {
        AllocGuard g;
    temp_s1 = Mem_Alloc(0, 0x18, ((int*)"frontend.cc"), 0x76);
    }
    /* barrier: empty arm keeps the label (and its padding nop) before the store */
    if (temp_s1 == 0) asm { .set reorder } 
    F_(arg0, 0x38, int) = temp_s1;
    func_0022A040(F_(arg0, 0x38, int), arg0 + 0x2C);
}
#pragma pop
#pragma pop
