#include "types.h"
int rt_time_platform_timer_getcount(void) {
    int c;
    asm { mfc0 c, $9
     sync.p }
    return c;
}