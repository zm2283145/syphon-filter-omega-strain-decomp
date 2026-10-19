#include "types.h"

extern int GetMemorySize(void);
extern void func_00115C10(void);
extern void func_0010D5D0(void);

/* Dispatches on GetMemorySize() == 0x2000000. */
void func_00115BD0(void) {
    if (GetMemorySize() == 0x2000000) {
        func_00115C10();
    } else {
        func_0010D5D0();
    }
}
