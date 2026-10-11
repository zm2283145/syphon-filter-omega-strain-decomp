#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int *Ptr_IdentityCast(char * );                      
int func_001A6D00(char *, char *);                        
int func_001A6D20(char *);                               
void **func_001A7790(char *);                          
int func_001A77A0(char *, char *);                          
int func_001A77C0(char *, char *);                          
char *func_001A77D0(char *);                             
int func_003931E0(char *);                               
int func_003932F0(int);                               

void func_003931F0(char *arg0) {
    int sp2C;
    int sp28;
    int sp24;
    int sp20;

    func_001A77C0(&sp2C, func_001A77D0(arg0 + 0x100));
    func_001A77A0(&sp28, func_001A77D0(arg0 + 0x100));
    if (func_001A6D00(&sp2C, &sp28) != 0) {
        do {
            func_003932F0(*Ptr_IdentityCast(*func_001A7790(&sp2C)));
            func_001A6D20(&sp2C);
        } while (func_001A6D00(&sp2C, &sp28) != 0);
    }
    func_001A77C0(&sp24, arg0 + 0x108);
    func_001A77A0(&sp20, arg0 + 0x108);
    if (func_001A6D00(&sp24, &sp20) != 0) {
        do {
            F_((*func_001A7790(&sp24)), 0x4, int) = 0;
            func_001A6D20(&sp24);
        } while (func_001A6D00(&sp24, &sp20) != 0);
    }
    func_003931E0(arg0 + 0x108);
}
