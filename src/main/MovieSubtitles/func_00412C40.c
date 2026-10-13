#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int String_CtorCStr_13B480(char *, int);                 
int String_Dtor(char *, int);                            
int func_003CBF70(int, char *, int);                     
extern char D_004BEDF8[];
extern char D_004BEE08[];
extern char D_004BEE10[];
extern char D_004BEE18[];
extern char D_004BEE20[];
extern char D_004BEE28[];
extern char D_004BEE30[];
extern char D_004BEE40[];
static void * const dat_004BEE50[16] = { (void*)D_004BEDF8, (void*)0x0, (void*)D_004BEE08, (void*)0x1, (void*)D_004BEE10, (void*)0x2, (void*)D_004BEE18, (void*)0x3, (void*)D_004BEE20, (void*)0x4, (void*)D_004BEE28, (void*)0x5, (void*)D_004BEE30, (void*)0x6, (void*)D_004BEE40, (void*)0x7 };

int func_00412C40(int arg0) {
    int var_s4;
    int var_s3;
    int temp_s2;
    int sp60[4];
    char *var_s1;

    var_s4 = 0;
    var_s3 = 0;
    var_s1 = &(*(char*)dat_004BEE50);
loop_1:
    String_CtorCStr_13B480(sp60, F_(var_s1, 0x0, int));
    temp_s2 = ~func_003CBF70(arg0, sp60, 0) != 0;
    String_Dtor(sp60, 0);
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
