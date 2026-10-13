#include "types.h"
extern int D_0048A030;
extern int D_004EE4C8;
extern int D_004EE4F8;
int iWakeupThread(int);

int func_001667C0(int cause) {
    D_004EE4C8 += 1;
    if (D_0048A030 != -1) {
        if (D_004EE4F8 == 0) {
            iWakeupThread(D_0048A030);
        } else {
            D_004EE4F8 -= 1;
        }
    }
    /* ExitHandler(): sync + ei cannot be expressed in C */
    asm { sync }
    asm { ei }
    return -1;
}
