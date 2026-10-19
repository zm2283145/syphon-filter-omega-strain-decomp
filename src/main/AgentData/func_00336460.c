#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int Mem_Free(int, int, char *, int);                         
int __destroy_array(char * , char *, int, int);               
int func_002887C0(char * , int);                         
int func_00336610(char * , int);                         
int func_0033A330(char * , int);                         
int operator_delete(char * );                          
extern unsigned char g_ProfileLockEnabled;
extern char func_003365A0;
}
extern "C" char * func_00336460(char * arg0, long long arg1) {
    int temp_s2;
    char * temp_a0;
    char * temp_a0_2;
    char * temp_a0_3;

    if (arg0 != NULL) {
        temp_s2 = F_(arg0, 0x9A4, int);
        {
            AllocGuard g;
        Mem_Free(0, temp_s2, "AgentData.cc", 0xE0);
        }
        temp_a0 = arg0 + 0xB58;
        if (temp_a0 != NULL) {
            func_002887C0(temp_a0, -1);
        }
        temp_a0_2 = arg0 + 0xAF8;
        if (temp_a0_2 != NULL) {
            func_00336610(temp_a0_2, -1);
        }
        __destroy_array(arg0 + 0xAA8, &func_003365A0, 0x10, 5);
        temp_a0_3 = arg0 + 0xC4;
        if ((temp_a0_3 != NULL) && (temp_a0_3 != NULL) && (temp_a0_3 != NULL)) {
            func_0033A330(temp_a0_3, 0);
        }
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
