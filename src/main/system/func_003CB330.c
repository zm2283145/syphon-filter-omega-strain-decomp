#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
/*fc*/
int Mem_Free(...);                         
int operator_delete(...);                          
extern char D_004BD1A8;
extern char D_004BD1E8;
extern char D_004DFDE0;
extern unsigned char D_00533880;
}
extern "C" char * Receiver_Destruct(char * arg0, long long arg1) {
    char *temp_s0;
    char *temp_s3;

    if (arg0 != NULL) {
        F_(arg0, 0x0, int) = (int)(&D_004DFDE0);
        F_(arg0, 0x4, int) = 0;
        F_(arg0, 0xC, int) = 0xF0FFFFF0;
        temp_s0 = (char *)(F_(arg0, 0x18, int));
        if (temp_s0 != NULL) {
            {
                AllocGuard g;
            if (temp_s0 != NULL) {
                temp_s3 = *(char **)temp_s0;
                if (temp_s3 != NULL) {
                    {
                        AllocGuard g;
                    Mem_Free(0, temp_s3, &D_004BD1E8, 0x34);
                    }
                }
            }
            Mem_Free(0, temp_s0, &D_004BD1A8, 0x54);
            }
        }
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
