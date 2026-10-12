#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_0042B1A0(int);                               
int func_0042EB20();                                  
int func_004355D0(char *);                               
int func_00436BA0(char *, int);                            
int func_00436C00(char *);                               
int func_00438770(int);                                 
int func_0043AA30(char *);                               
int func_0043B190(char *);                               
static unsigned int dat_00493A18[2] = { 0x1, 0x0 };
extern int D_0055C7B8;
extern signed char D_005724D0;

void func_003FBEC0(void) {
    int sp1C;
    int sp18;

    D_005724D0 = 1;
    if ((*(unsigned char*)dat_00493A18) != 0) {
        (*(unsigned char*)dat_00493A18) = 0;
    }
    func_00436C00(&sp1C);
    func_004355D0(&sp1C);
    func_0043B190(&sp18);
    func_0043AA30(&sp18);
    D_0055C7B8 = func_0042B1A0(0) + 0x64;
    func_0042EB20();
    func_00438770(0);
    func_00436BA0(&sp1C, -1);
}
