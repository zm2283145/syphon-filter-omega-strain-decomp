#include "types.h"

extern void func_0010D010(int code);

/* Never returns: repeatedly calls func_0010D010(5) (halt/exit loop). */
void func_003F7F80(void) {
    for (;;) {
        func_0010D010(5);
    }
}
