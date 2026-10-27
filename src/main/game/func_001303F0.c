#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
/*fc*/
char * cMemMan_Allocate(...);                      
int strncpy(...);                            
extern char D_0049A890;
extern unsigned char g_ProfileLockEnabled;
}
typedef struct { char p0[172]; int fAC; } PS0_001303F0;
#pragma push
#pragma opt_common_subs off
extern "C" void cGameSystem_QueueMovie(PS0_001303F0 *arg0, int arg1) {
    char * temp_a0;
    char * temp_s0;
    int var_a1;
    int temp_v1;
    char * var_a0;

    if (arg0->fAC == NULL) {
        {
            AllocGuard g;
        temp_s0 = (char *)(cMemMan_Allocate(0, 0x808, &D_0049A890, 0x9FD));
        }
        if (temp_s0 != NULL) {
            var_a1 = 0;
            var_a0 = temp_s0;
            do {
                F_(var_a0, 0x0, signed char) = 0;
                F_(var_a0, 0x80, signed char) = 0;
                var_a1 += 8;
                F_(var_a0, 0x100, signed char) = 0;
                F_(var_a0, 0x180, signed char) = 0;
                F_(var_a0, 0x200, signed char) = 0;
                F_(var_a0, 0x280, signed char) = 0;
                F_(var_a0, 0x300, signed char) = 0;
                F_(var_a0, 0x380, signed char) = 0;
                var_a0 += 0x400;
            } while (var_a1 < 0x10);
            F_(temp_s0, 0x804, int) = 0;
            F_(temp_s0, 0x800, int) = 0;
        }
        arg0->fAC = (int)(temp_s0);
    }
    temp_a0 = (char *)(arg0->fAC);
    temp_v1 = F_(temp_a0, 0x804, int);
    if (temp_v1 < 0x10) {
        F_(temp_a0, 0x804, int) = (int) (temp_v1 + 1);
        strncpy(temp_a0 + (temp_v1 << 7), arg1, 0x80);
    }
}
#pragma pop
