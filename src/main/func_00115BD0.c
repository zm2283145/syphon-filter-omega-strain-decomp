#include "types.h"

extern int func_0010D5C0(void);
extern void func_00115C10(void);
extern void func_0010D5D0(void);

/* Dispatches on func_0010D5C0() == 0x2000000. */
void func_00115BD0(void) {
    if (func_0010D5C0() == 0x2000000) {
        func_00115C10();
    } else {
        func_0010D5D0();
    }
}
