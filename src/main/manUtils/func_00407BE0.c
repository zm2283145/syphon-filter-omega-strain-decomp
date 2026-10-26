#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int Mem_Free(int, int, char *, int);                         
extern char D_004BE7F0;
extern unsigned char g_ProfileLockEnabled;
extern int D_0055D4F8;
extern int D_0055D4FC;
extern int D_0055D500;
}
extern "C" void SKLHog_DeleteIdentities(void) {
    int temp_s0;
    int temp_s0_2;

    if (D_0055D500 != 0) {
        temp_s0 = D_0055D4F8;
        {
            AllocGuard g;
        Mem_Free(0, temp_s0, &D_004BE7F0, 0xB0);
        }
        temp_s0_2 = D_0055D4FC;
        {
            AllocGuard g;
        Mem_Free(0, temp_s0_2, &D_004BE7F0, 0xB1);
        }
        D_0055D500 = 0;
    }
}
