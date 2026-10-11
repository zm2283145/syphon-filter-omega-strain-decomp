#include "types.h"
extern int func_002E9A10(void);
extern int func_003C9C30(void* p);
extern int NetMsg_RegisterType(void* t, int id, void* fn);
extern int D_00582738;
extern int func_00431850();
unsigned char func_00431890(void) {
    int buf[4];
    unsigned char r = 0;
    if (func_002E9A10() == 0 && func_003C9C30(buf + 2) != 0 &&
        NetMsg_RegisterType(&D_00582738, 2, func_00431850) == 0) {
        r = 1;
    }
    return r;
}