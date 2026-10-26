#include "types.h"

extern int rt_list_buf_get_data_ptr(int);
extern int rt_list_buf_get_data_size(int);

int rt_udp_get_packet_data(int a0, int a1, int a2) {
    int s0, s1, s2, v0;
    int cond;

    v0 = 0 + 1;
    s0 = a1;
    s1 = a0;
    s2 = a2;
    cond = s0 == 0;
    if (cond) goto L0030919C;
    cond = s2 == 0;
    *(int*)(char*)s0 = 0;
    if (cond) goto L0030919C;
    cond = s1 == 0;
    *(int*)(char*)s2 = 0;
    if (cond) goto L0030919C;
    v0 = rt_list_buf_get_data_size(a0);
    v0 = (unsigned int)v0 < (unsigned int)25;
    cond = v0 != 0;
    a0 = s1;
    if (cond) goto L00309190;
    v0 = rt_list_buf_get_data_ptr(a0);
    a0 = s1;
    v0 = v0 + 24;
    *(int*)(char*)s0 = v0;
    v0 = rt_list_buf_get_data_size(a0);
    v0 = v0 + -28;
    *(int*)(char*)s2 = v0;
    goto L00309198;
L00309190:;
    *(int*)(char*)s0 = 0;
    *(int*)(char*)s2 = 0;
L00309198:;
    v0 = 0;
L0030919C:;
    goto ret;
ret:
    return v0;
}
