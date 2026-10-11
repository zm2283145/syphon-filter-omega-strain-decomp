#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


extern "C" {
char * Mem_Alloc(...);                      
int Mem_Free(...);                      
extern char D_004A93D0;
extern unsigned char D_00533880;
}
typedef struct { char p0[100]; int f64; } PS0_00285C00;
extern "C" void func_00285C00(PS0_00285C00 *arg0, int arg1, char * arg2) {
    char * temp_s0;
    char * temp_s0_2;

    temp_s0 = (char *)(arg0->f64);
    if (temp_s0 != NULL) {
        {
            AllocGuard g;
        Mem_Free(0, temp_s0, &D_004A93D0, 0x1F1);
        }
    }
    {
        AllocGuard g;
    temp_s0_2 = Mem_Alloc(0, 0x2C, &D_004A93D0, 0x1F3);
    }
    if (temp_s0_2 != NULL) {
        F_(temp_s0_2, 0x4, int) = (int)(arg2);
        F_(temp_s0_2, 0x0, int) = arg1;
        F_(temp_s0_2, 0x24, float) = F_(F_(temp_s0_2, 0x4, char *), 0x144, float);
        F_(temp_s0_2, 0x28, signed char) = 0;
    }
    arg0->f64 = (int)(temp_s0_2);
}
