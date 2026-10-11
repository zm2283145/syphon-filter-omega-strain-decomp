#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_00138DA0(char *, int, char *);                     
int func_0015AF40(char *, int *);                        
int func_003D2110(char *, int);                          
int func_003D2180(char *, int);                          
int func_003D2710(int *, char *);                        
int func_003D2720(char *, char *);                        
int func_003D2740(char *);                               
int *func_003D2760(char *);                            
int func_003D2770(char *, char *);                          
int func_003D2780(char *);                               

void func_003D2630(int arg0, int arg1) {
    int sp4C;
    int sp48;
    int sp44;
    int sp40;
    int sp3C;
    int sp38;
    int sp34;

    func_003D2780(&sp3C);
    func_003D2180(&sp38, arg0);
    func_003D2770(&sp3C, &sp38);
    func_003D2110(&sp34, arg0);
    while (func_003D2720(&sp3C, &sp34) != 0) {
        { int v = *func_003D2760(&sp3C); if (v == arg1) break; }
        func_003D2740(&sp3C);
        func_003D2110(&sp34, arg0);
    }
    func_003D2710(&sp4C, &sp3C);
    sp48 = sp4C;
    func_0015AF40(&sp40, &sp48);
    func_00138DA0(&sp44, arg0, &sp40);
}
