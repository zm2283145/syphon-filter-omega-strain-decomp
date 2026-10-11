#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
extern unsigned char D_005721C0;
extern unsigned char D_005721C8;
extern unsigned char D_005723C8;
extern unsigned char D_005724B0;

void func_00429C00(int *arg0) {
    int var_v1;

    if (D_005723C8 == 0) {
        D_005723C8 = 1;
    }
    if (*arg0 == 0) {
        var_v1 = D_005721C8 ? D_005721C0 : 1;
        if (var_v1 != 0) {
            D_005724B0 = 0xA;
        } else if (D_005724B0 == 9) {
            D_005724B0 = 0xA;
        } else {
            D_005724B0 = 9;
        }
    } else {
        D_005724B0 = 0xB;
    }
    D_005723C8 = 0;
}
