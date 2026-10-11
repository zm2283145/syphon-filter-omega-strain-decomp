#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int Alloc_Unlock(int);                                  
int Mem_Alloc();                        
int func_003E9000(int, int );                     
int func_003EEBE0(int, int, int);                              
int func_003EF0F0(int , int *);                     
extern int D_004BE030;
extern unsigned char D_00533880;
extern int D_00533888;

int func_003EF010(int arg0) {
    int sp3C;
    int var_s1;

    func_003EEBE0(arg0, 1, 1);
    if (D_00533880 != 0) {
        Alloc_Lock(9);
    }
    D_00533888 += 1;
    var_s1 = Mem_Alloc(0, 0x80, &D_004BE030, 0x207);
    if (D_00533880 != 0) {
        Alloc_Unlock(9);
    }
    D_00533888 -= 1;
    if (var_s1 != 0) {
        var_s1 = func_003E9000(var_s1, arg0);
    }
    sp3C = var_s1;
    func_003EF0F0(arg0 + 0x8C, &sp3C);
    return F_(F_(arg0, 0x90, int), 0x8, int);
}
