#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
/*fc*/
int Mem_Free(...);                         
int cGOBJ_dtor(...);                            
int operator_delete(...);                          
extern char D_004A6698;
extern char D_004DB8F0;
extern unsigned char D_00533880;
}
extern "C" char * cCheckpoint_dtor(char * arg0, long long arg1) {
    int temp_s2;

    if (arg0 != NULL) {
        F_(arg0, 0x0, int) = (int)(&D_004DB8F0);
        temp_s2 = F_(arg0, 0x70, int);
        if (temp_s2 != 0) {
            {
                AllocGuard g;
            Mem_Free(0, temp_s2, &D_004A6698, 0x38);
            }
        }
        cGOBJ_dtor(arg0, 0);
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
