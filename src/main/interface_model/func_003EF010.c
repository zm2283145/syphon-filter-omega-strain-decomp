#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int Alloc_Unlock(int);                                  
int Mem_Alloc();                        
int IeElement_Construct(int, int );                     
int IeNode_SetShown(int, int, int);                              
int IeNode_LinkElement(int , int *);                     
extern int D_004BE030;
extern unsigned char D_00533880;
extern int D_00533888;

int IeElement_Create(int arg0) {
    int sp3C;
    int var_s1;

    IeNode_SetShown(arg0, 1, 1);
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
        var_s1 = IeElement_Construct(var_s1, arg0);
    }
    sp3C = var_s1;
    IeNode_LinkElement(arg0 + 0x8C, &sp3C);
    return F_(F_(arg0, 0x90, int), 0x8, int);
}
