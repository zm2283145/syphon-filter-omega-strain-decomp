#include "types.h"
extern int func_002E9A10(void);
extern int func_003C9C30(void* p);
extern int func_002E9A98(void* a, void* b, int c, int d);
extern int NetMsg_RegisterType(void* t, int id, void* fn);
extern int D_004F80B0;
extern int func_0025E220();
unsigned char func_0025E330(void) {
    int buf[2];
    int b[1];
    int a[1];
    int busy;
    unsigned char r = 0;
    busy = func_002E9A10();
    if (!busy && func_003C9C30(buf) && !busy && func_002E9A98(buf, a, 4, 1) == 0 &&
        func_002E9A98(buf, b, 4, 1) == 0 && NetMsg_RegisterType(&D_004F80B0, 2, func_0025E220) == 0) {
        r = 1;
    }
    return r;
}

