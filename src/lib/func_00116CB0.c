#include "types.h"

extern int D_00487850; /* negative when the device is unavailable */

/* SDK (EE-GCC): returns the low 2 bits of hardware register 0x10001010, or 0x80008001 on error. */
int func_00116CB0(void) {
    if (D_00487850 >= 0) {
        return *(volatile int*)0x10001010 & 3;
    }
    return 0x80008001;
}
