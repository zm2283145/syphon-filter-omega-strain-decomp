#include "types.h"
int rt_msg_client_calc_connect_aux_udp_msg_size(short* p) {
    if (p == 0) return 2;
    *p = 29;
    return 0;
}
