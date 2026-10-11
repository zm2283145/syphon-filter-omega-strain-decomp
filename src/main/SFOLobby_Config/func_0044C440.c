#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int func_003A6680(int);                               
int func_0044BFF0(char * );                            
int func_0044C0E0(char * , int);                       
int func_0044CA30(char * );                            
int func_0044F6B0(int);                               
int func_0044F880(int, int, int, int);                      
int func_00451B00(char * , int, char *, int);                 
int func_00452C70(char * , int);                         
int func_00452FC0(char * );                            
extern char D_004C0D70;

typedef struct { char p0[384]; int f180; char p184[7460]; int f1EA8; char p1EAC[1324]; int f23D8; int f23DC; char p23E0[36]; int f2404; char p2408[340]; int f255C; char p2560[24]; int f2578; } PS0_0044C440;
int func_0044C440(PS0_0044C440 *arg0, int arg1, int arg2, int arg3, char * arg4) {
    int temp_a0;
    int temp_a0_2;
    int temp_a0_3;
    int temp_a0_4;
    int temp_a0_5;
    int temp_v1;

    temp_v1 = arg0->f255C;
    if ((temp_v1 != 9) && (temp_v1 != 0)) {
        return 0;
    }
    arg0->f255C = 1;
    func_00452FC0(arg0);
    arg0->f2578 = 0;
    if (arg0->f1EA8 > 0) {
        if (arg0->f180 > 0) {
            func_0044CA30(arg0);
        }
        func_00452C70(arg0, 1);
        func_0044BFF0(arg0);
        func_003A6680(0);
        temp_a0 = arg0->f2404;
        if (temp_a0 != 0) {
            func_0044F6B0(temp_a0);
        }
        arg0->f2404 = 0;
        temp_a0_2 = arg0->f23DC;
        if (temp_a0_2 != 0) {
            func_0044F6B0(temp_a0_2);
        }
        arg0->f23DC = 0;
    }
    if (func_003A6680(1) == 0) {
        func_00451B00(arg0, 0x2E, &D_004C0D70, 0x44);
        return 0;
    }
    arg0->f2404 = arg3;
    func_0044F880(arg0->f2404, 0x10, 0x10, 0x100);
    arg0->f23DC = (int) arg4;
    func_0044F880(arg0->f23DC, 0x10, 0x10, 0x210);
    arg0->f23D8 = arg2;
    func_0044F880(arg0->f23D8, 0x10, 0x10, 0x13C0);
    if (func_0044C0E0(arg0, 0) == 0) {
        temp_a0_3 = arg0->f2404;
        if (temp_a0_3 != 0) {
            func_0044F6B0(temp_a0_3);
        }
        arg0->f2404 = 0;
        temp_a0_4 = arg0->f23DC;
        if (temp_a0_4 != 0) {
            func_0044F6B0(temp_a0_4);
        }
        arg0->f23DC = 0;
        temp_a0_5 = arg0->f23D8;
        if (temp_a0_5 != 0) {
            func_0044F6B0(temp_a0_5);
        }
        arg0->f23D8 = 0;
        return 0;
    }
    return 1;
}
