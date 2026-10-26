#include "types.h"

extern int rt_time_platform_get_date_time(int);

int rt_time_get_date_time(int a0) {
    return rt_time_platform_get_date_time(a0);
}
