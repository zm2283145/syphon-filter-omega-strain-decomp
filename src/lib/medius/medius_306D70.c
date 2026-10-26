#include "types.h"

extern int iWakeupThread(int);

int rt_time_alarm_func(int a0, int a1, int a2) {
    return iWakeupThread(a2);
}
