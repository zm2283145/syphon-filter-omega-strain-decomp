#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int Mem_Free(int, int, char *, int);                         
extern char D_004BFCA0;
extern unsigned char D_00533880;
extern unsigned char D_00582780;
extern int D_005827F0;
extern int D_005827F8;
extern int D_00582800;
extern int D_00582808;
extern int D_00582810;
}
extern "C" void func_00433760(void) {
    int temp_s0;
    int temp_s0_2;
    int temp_s0_3;
    int temp_s0_4;
    int temp_s0_5;

    if (D_00582780 == 0) {
        temp_s0 = D_005827F0;
        if (temp_s0 != 0) {
            {
                AllocGuard g;
            Mem_Free(0, temp_s0, &D_004BFCA0, 0x5AA);
            }
        }
        temp_s0_2 = D_005827F8;
        if (temp_s0_2 != 0) {
            {
                AllocGuard g;
            Mem_Free(0, temp_s0_2, &D_004BFCA0, 0x5AD);
            }
        }
        temp_s0_3 = D_00582800;
        if (temp_s0_3 != 0) {
            {
                AllocGuard g;
            Mem_Free(0, temp_s0_3, &D_004BFCA0, 0x5B0);
            }
        }
        temp_s0_4 = D_00582808;
        if (temp_s0_4 != 0) {
            {
                AllocGuard g;
            Mem_Free(0, temp_s0_4, &D_004BFCA0, 0x5B3);
            }
        }
        temp_s0_5 = D_00582810;
        if (temp_s0_5 != 0) {
            {
                AllocGuard g;
            Mem_Free(0, temp_s0_5, &D_004BFCA0, 0x5B6);
            }
        }
        D_005827F0 = 0;
        D_005827F8 = 0;
        D_00582800 = 0;
        D_00582808 = 0;
        D_00582810 = 0;
    }
}
