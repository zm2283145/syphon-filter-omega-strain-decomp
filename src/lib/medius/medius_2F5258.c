#include "types.h"

extern int iWakeupThread(int);

int delay_wakeup(int a0, int a1, int a2) {
    return iWakeupThread(a2);
}
