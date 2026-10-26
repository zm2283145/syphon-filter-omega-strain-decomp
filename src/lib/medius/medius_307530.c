typedef struct { char pad[0x46]; unsigned short h46; } ScfSock_530;
extern int rt_comm_get_local_ip(void *a);
int rt_udp_get_local_address(ScfSock_530 *o, void *a, unsigned short *out)
{
    int ret = 2;
    if (o == 0) return ret;
    ret = 1;
    if (a == 0) return ret;
    if (out == 0) return ret;
    if (rt_comm_get_local_ip(a) != 0) return 0x10;
    *out = o->h46;
    return 0;
}