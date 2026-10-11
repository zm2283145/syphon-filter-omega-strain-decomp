#include "types.h"
extern int func_002E9A10(void);
extern int func_003C9C30(void* p);
extern int func_002E9A98(void* a, void* b, int c, int d);
extern int NetMsg_RegisterType(void* t, int id, void* fn);
extern int D_0052ACF0;
extern int func_00324000();
unsigned char func_003240C0(void) {
    int ok[2];
    int buf[2];
    unsigned char r = 0;
    if (func_002E9A10() == 0 && func_003C9C30(buf) != 0 && func_002E9A98(buf, ok, 4, 1) == 0 &&
        NetMsg_RegisterType(&D_0052ACF0, 2, func_00324000) == 0) {
        r = 1;
    }
    return r;
}
