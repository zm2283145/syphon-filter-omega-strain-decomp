#include "types.h"
#pragma cplusplus on
struct E26BC20 { unsigned char b0; int i4; float f8; int iC; float f10; int i14; unsigned char b18; };
struct C26BC20 { char pad[0x1C0]; };
extern int D_004FF020;
extern unsigned char D_004FF028;
extern E26BC20 D_004FEED0[2][6];
extern C26BC20 D_0055A300[2];
extern "C" void func_00369920(void* p, int f, int n);
extern "C" void func_0026BC20(float dt) {
    int k;
    D_004FF020++;
    for (k = 0; k < 2; k++) {
        unsigned char flag = 0;
        int sum = 0;
        if (D_004FF028) {
            int j;
            for (j = 0; j < 6; j++) {
                E26BC20* e = &D_004FEED0[k][j];
                if (e->b18) {
                    e->f10 += dt;
                    if (D_004FF020 % e->iC == 0) {
                        flag = (flag | e->b0) != 0;
                        sum += e->i4;
                    }
                    if (!(e->f8 < 0.0f) && e->f10 > e->f8) {
                        e->b18 = 0;
                    }
                }
            }
        }
        func_00369920((char*)&D_0055A300[k] + 0x40, flag, sum);
    }
}