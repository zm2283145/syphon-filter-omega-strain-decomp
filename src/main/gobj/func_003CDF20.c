#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC003CDF20 { virtual int v0(...); };
extern "C" {
int Mem_Free(...);                     
extern char D_004BD228;
extern unsigned char D_00533880;
}
#pragma push
#pragma opt_common_subs off
extern "C" void func_003CDF20(char * arg0) {
    void **temp_s1;

    temp_s1 = (void **)(F_(arg0, 0x50, int));
    if (temp_s1 != NULL) {
        if (F_(arg0, 0x48, unsigned char) != 0) {
            {
                AllocGuard g;
            ((VC003CDF20 *)(temp_s1))->v0(-1);
            Mem_Free(0, temp_s1, &D_004BD228, 0x174);
            }
            F_(arg0, 0x48, unsigned char) = 0U;
        }
        F_(arg0, 0x50, int) = NULL;
    }
}
#pragma pop
