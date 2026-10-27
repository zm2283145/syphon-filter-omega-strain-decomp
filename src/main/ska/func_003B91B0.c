#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


extern "C" {
/*fc*/
int *cMemMan_Allocate(...);                     
int Libc_Abort(...);                                  
int Libc_Fprintf(...);                          
unsigned int _cdeque_deleter_common_int_max_size(...);                                
extern char * D_00489738;
extern char D_0049AE50;
extern unsigned char g_ProfileLockEnabled;
}
extern "C" void _cdeque_deleter_int_1_init(char * arg0, unsigned int arg1, int *arg2) {
    int *temp_s0;
    int *var_a0;
    unsigned int var_s2;

    var_s2 = arg1;
    if (var_s2 != 0) {
        if (_cdeque_deleter_common_int_max_size() < var_s2) {
            Libc_Fprintf(F_(D_00489738, 0xC, int), "cdeque::construction length error");
            Libc_Abort();
        }
        {
            AllocGuard g;
        temp_s0 = (int *)((cMemMan_Allocate(0, (var_s2 + 1) * 4, &D_0049AE50, 0x5C)));
        }
        F_(arg0, 0xC, int) = (int)(temp_s0);
        F_(arg0, 0x0, int) = (int) (var_s2 + 1);
        F_(arg0, 0x4, int) = var_s2;
        var_a0 = (int *)((F_(arg0, 0xC, int)));
        if (var_s2 != 0) {
            do {
                var_s2 -= 1;
                *var_a0 = *arg2;
                var_a0 += 1;
            } while (var_s2 != 0);
        }
    }
}
