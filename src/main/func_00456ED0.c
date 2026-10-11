#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int Service_Lookup(int *, int *);                       
int func_001C96D0(int, int);                            
int func_003F9E30(int, int);                            
int func_0041EFA0(int);                               
extern int D_004F2CC0;
extern int D_004FFB50;
extern int D_004FFC2C;
extern unsigned char D_005721C8;

void func_00456ED0(int arg0) {
    if (D_005721C8 == 0) {
        func_001C96D0(Service_Lookup(&D_004FFB50, &D_004F2CC0), 1);
    }
    func_003F9E30(D_004FFC2C + 0x100, 0);
    func_0041EFA0(arg0);
}
