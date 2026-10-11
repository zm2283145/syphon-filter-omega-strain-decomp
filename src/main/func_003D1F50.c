#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int func_00379740(int, int);                        
int func_003797D0(char *);                             
int func_003D20F0(char *, int);                        
int func_003D2110(char *, int);                          
int func_003D2120(char *);                               
int func_003D2140(int);                             
int func_003D2150(char * );                          
void **func_003D2160(char *);                          
int func_003D2170(char *, char *);                        
int func_003D2180(char *, int);                          
int strcmp(int, int);                                 
extern char D_005381F0;
extern char * D_00539248;

#pragma push
#pragma opt_common_subs off
void Global_SetTexture(int arg0, int arg1, unsigned int arg2) {
    char * var_s0;
    int sp7C;
    int sp78;
    char * temp_s3;
    int sp74;
    char * temp_a0;
    int sp70;
    int temp_s2;

    var_s0 = NULL;
    func_003D2180(&sp78, arg0);
    func_003D2170(&sp7C, &sp78);
    func_003D2110(&sp70, arg0);
    if (func_003D20F0(&sp7C, func_003D2170(&sp74, &sp70)) != 0) {
loop_2:
        temp_s3 = *func_003D2160(&sp7C);
        temp_s2 = func_003797D0(&D_005381F0);
        if (strcmp(func_003D2140(func_00379740(temp_s2, func_003D2150(temp_s3))), arg1) == 0) {
            var_s0 = temp_s3;
        } else {
            func_003D2120(&sp7C);
            func_003D2110(&sp70, arg0);
            if (func_003D20F0(&sp7C, func_003D2170(&sp74, &sp70)) == 0) {

            } else {
                goto loop_2;
            }
        }
    }
    if ((var_s0 != NULL) && (arg2 < F_(var_s0, 0x14, unsigned int))) {
        temp_a0 = (char *)(*(int *)((char *)F_(D_00539248, 0x8, int) + (F_(var_s0, 0x0, int) * 4)));
        if ((arg2 != F_(temp_a0, 0x4C, int)) && (arg2 < F_(F_(temp_a0, 0x44, char *), 0x22, unsigned short))) {
            F_(temp_a0, 0x60, signed char) = 0;
            F_(temp_a0, 0x61, signed char) = 0;
            F_(temp_a0, 0x4C, int) = arg2;
        }
        F_(var_s0, 0x28, int) = arg2;
    }
}
#pragma pop

