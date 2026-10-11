#include "types.h"
extern int func_002E9A10(void);
extern int func_003C9C30(void* p);
extern int func_002E9A98(void* a, void* b, int c, int d);
extern int func_002E9F08(void* t, void* fn);
extern int D_0055D4A0;
extern int func_003FF5D0();
unsigned char func_003FF4F0(void) {
    int ok[2];
    int buf[2];
    unsigned char r = 0;
    if (func_002E9A10() == 0 && func_003C9C30(buf) != 0 && func_002E9A98(buf, ok, 4, 1) == 0 &&
        func_002E9F08(&D_0055D4A0, func_003FF5D0) == 0) {
        r = 1;
    }
    return r;
}
