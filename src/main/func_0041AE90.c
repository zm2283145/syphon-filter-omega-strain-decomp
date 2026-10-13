#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
typedef __int128 Q128;
#pragma mpwc_relax on
int String_PushBack(char *, int);                          
int String_Reserve(char *);                              
int String_Dtor(char *, int);                            
int String_CStr(char *);                             
int func_003D08B0(int, int);                          

void func_0041AE90(int arg0, int arg1) {
    Q128 sp40[1];
    int var_s0;

    if (arg0 != 0) {
        { int *sp_ = (int *)sp40; sp_[0] = 0; sp_[1] = 0; sp_[2] = 0; String_Reserve((char *)sp_); }
        for (var_s0 = 0; var_s0 < arg1; var_s0++) {
                String_PushBack(&sp40, 0x23);
        }
        func_003D08B0(arg0, String_CStr(&sp40));
        String_Dtor(&sp40, 0);
    }
}

