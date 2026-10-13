#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int SignalSema(int, int, int);
int WaitSema(int);

typedef struct { int f0; char p4[4]; int f8; int fC; int f10; int f14; int f18; char p1C[36]; int f40; } PS0_003F53B0;
#pragma push

void func_003F53B0(PS0_003F53B0 *arg0, int *arg1, int *arg2, int *arg3, char * arg4) {
    int *temp_s0;
int temp_a1;
int temp_a0;
int temp_a2;
int temp_hi;
int temp_v1;

    temp_s0 = arg4;
    WaitSema(arg0->f40);
    temp_a1 = arg0->f10;
    temp_a2 = arg0->f14;
    temp_a0 = arg0->f18;
    temp_hi = (arg0->fC + temp_a1) << 0xB; temp_hi = (temp_hi + temp_a2) % temp_a0;
    temp_v1 = (((arg0->f8 - 2) - temp_a1) << 0xB) - temp_a2;
    if ((temp_a0 - temp_hi) >= temp_v1) {
        *arg1 = arg0->f0 + temp_hi;
        *arg2 = temp_v1;
        *arg3 = 0;
        *temp_s0 = 0;
    } else {
        *arg1 = arg0->f0 + temp_hi;
        *arg2 = arg0->f18 - temp_hi;
        *arg3 = arg0->f0;
        *temp_s0 = temp_v1 - (arg0->f18 - temp_hi);
    }
    SignalSema(arg0->f40, temp_hi, temp_a2);
}
#pragma pop
