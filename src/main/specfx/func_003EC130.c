#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC003EC130 { char vpad[4]; virtual int v0(...); };
extern "C" {
int func_00138DA0(...);              
extern int D_0055C090;
typedef struct { int f0; char p4[4]; int f8; } PS0_003EC130;
}
extern "C" void func_003EC130(int d0, PS0_003EC130 *arg1) {
    int sp3C;
    char * sp38;
    char * temp_a0;
    char * temp_s1;

    if (arg1->f0 > 0) {
        do {
            temp_s1 = (char *)(F_(arg1->f8, 0x8, int));
            temp_a0 = (char *)(F_(temp_s1, 0x0, int));
            if (temp_a0 != NULL) {
                ((VC003EC130 *)(temp_a0))->v0(1);
            }
            F_(temp_s1, 0x0, int) = NULL;
            F_(temp_s1, 0xC, signed char) = 0;
            D_0055C090 -= 1;
            sp38 = (char *)(arg1->f8);
            func_00138DA0(&sp3C, arg1, &sp38);
        } while (arg1->f0 > 0);
    }
}
