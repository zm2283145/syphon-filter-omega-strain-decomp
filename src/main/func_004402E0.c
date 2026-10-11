#include "types.h"
extern int func_002E9A10(void);
extern int func_003C9C30(void* p);
extern int func_002E9A98(void* a, void* b, int c, int d);
extern int NetMsg_RegisterType(void* t, int id, void* fn);
extern int D_00583998;
extern int func_00440370();
unsigned char func_004402E0(void) {
    int a[2];
    int buf[2];
    int busy;
    unsigned char r = 0;
    busy = func_002E9A10();
    if (!busy && func_003C9C30(buf) && !busy && func_002E9A98(buf, a, 4, 1) == 0 && NetMsg_RegisterType(&D_00583998, 2, func_00440370) == 0) {
        r = 1;
    }
    return r;
}





