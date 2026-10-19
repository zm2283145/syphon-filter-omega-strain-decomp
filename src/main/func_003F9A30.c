#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


extern "C" {
int Mem_Free(...);                     
int func_0036D5D0(...);                         
extern char D_0049AE60;
extern unsigned char g_ProfileLockEnabled;
}
extern "C" void func_003F9A30(void ***arg0, int *arg1, void ***arg2) {
    void **temp_s0;

    temp_s0 = *arg2;
    *arg2 = (void **)(F_(temp_s0, 0x4, int));
    F_(F_(temp_s0, 0x0, int), 0x4, int) = (int)(F_(temp_s0, 0x4, int));
    *(int *)F_(temp_s0, 0x4, int) = F_(temp_s0, 0x0, int);
    func_0036D5D0((char *)temp_s0 + 8, -1);
    if (temp_s0 != NULL) {
        {
            AllocGuard g;
        Mem_Free(0, temp_s0, &D_0049AE60, 0x64);
        }
    }
    *arg1 -= 1;
    *arg0 = *arg2;
}
