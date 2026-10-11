#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int String_CtorCStr_13B480(char *, int);                 
int func_00138B70(char *, int);                            
int func_003CBF70(int, char *, int);                     
extern char D_004BEE50;

int func_00412C40(int arg0) {
    int var_s4;
    int var_s3;
    int temp_s2;
    int sp60[4];
    char *var_s1;

    var_s4 = 0;
    var_s3 = 0;
    var_s1 = &D_004BEE50;
loop_1:
    String_CtorCStr_13B480(sp60, F_(var_s1, 0x0, int));
    temp_s2 = ~func_003CBF70(arg0, sp60, 0) != 0;
    func_00138B70(sp60, 0);
    if (temp_s2 != 0) {
        var_s4 = F_(var_s1, 0x4, int);
    } else {
        var_s3 += 1;
        var_s1 += 8;
        if (var_s3 < 8) {
            goto loop_1;
        }
    }
    return var_s4;
}
