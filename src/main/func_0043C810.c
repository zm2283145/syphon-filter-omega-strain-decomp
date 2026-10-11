#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int String_CtorCStr_13B480(char *, char *);                 
int func_00138B70(char *, int);                            
int func_0013D680(char * , char *);                       
int func_003813A0(int, int, int);                       
extern char D_004C0018;
extern int D_00539248;

#pragma push
#pragma opt_common_subs off
void func_0043C810(char * arg0) {
    struct { int f20[4]; } sl;
    int temp_a1;

    temp_a1 = F_(arg0, 0x48, int);
    if (temp_a1 != -1) {
        func_003813A0(D_00539248, temp_a1, 0);
        F_(arg0, 0x48, int) = -1;
    }
    F_(arg0, 0x4C, int) = 0;
    String_CtorCStr_13B480(sl.f20, &D_004C0018);
    func_0013D680(arg0 + 0x50, sl.f20);
    func_00138B70(sl.f20, 0);
}
#pragma pop
