#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
typedef struct { char p0[316]; int f13C; } PS0_002493C0;
typedef struct { char p0[13604]; int f3524; char p3528[92]; int f3584; } PS1_002493C0;
void func_002493C0(PS0_002493C0 *arg0, PS1_002493C0 *arg1) {
    int var_v1_2;
    unsigned char temp_a0;
    char * temp_a1;
    char * temp_a2;
    char * var_v1;

    if (arg0->f13C == NULL) {
        var_v1 = (char *)(arg1->f3584);
        if (var_v1 != NULL) {
            var_v1 += 0x1C;
        }
        arg0->f13C = (int)(var_v1);
    }
    temp_a2 = (char *)(arg0->f13C);
    if (temp_a2 != NULL) {
        temp_a1 = (char *)(arg1->f3524);
        temp_a0 = F_(temp_a1, 0x84, unsigned char);
        var_v1_2 = (temp_a0 != 6) ? F_(((char *)(temp_a0 * 0x10) + (int)(temp_a1)), 0x8, int) : -1;
        F_(temp_a2, 0x6, short) = (short) var_v1_2;
    }
}

