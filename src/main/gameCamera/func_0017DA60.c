#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int Vec4_Add(char *, char *, char *);                          
int func_0017DBF0(int);                             
int func_0017DC00(float, char *, int);                     
int func_0017DC30(int);                             
int func_0017DC40(char * , int);                       

void Curve_Sample(char *arg0, char * arg1, float farg0) {
    int sp90[4];
    int sp80[4];
    int sp70[4];
    float temp_f22;
    float temp_f21;
    int sp60[4];
    int sp50[4];
    float var_f20;
    float temp_f23;
    int sp40[4];

    if (F_(arg1, 0x40, float) != 0.0f) {
        var_f20 = farg0 * F_(arg1, 0x44, float);
    } else {
        var_f20 = 1.0f;
    }
    temp_f22 = var_f20 * var_f20;
    temp_f21 = temp_f22 * var_f20;
    temp_f23 = 3.0f * temp_f22;
    func_0017DC00(1.0f + ((2.0f * temp_f21) - temp_f23), sp70, func_0017DC30(func_0017DC40(arg1, 0)));
    func_0017DC00((-2.0f * temp_f21) + temp_f23, sp60, func_0017DC30(func_0017DC40(arg1, 1)));
    Vec4_Add(sp80, sp70, sp60);
    func_0017DC00(var_f20 + (temp_f21 - (2.0f * temp_f22)), sp50, func_0017DBF0(func_0017DC40(arg1, 0)));
    Vec4_Add(sp90, sp80, sp50);
    func_0017DC00(temp_f21 - temp_f22, sp40, func_0017DBF0(func_0017DC40(arg1, 1)));
    Vec4_Add(arg0, sp90, sp40);
}
