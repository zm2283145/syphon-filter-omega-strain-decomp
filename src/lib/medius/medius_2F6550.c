#include "types.h"

extern int rt_comm_platform_display_state(float);

int rt_comm_display_state(float f12) {
    return rt_comm_platform_display_state(f12);
}
