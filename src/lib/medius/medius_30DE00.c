typedef struct { int sock; int x4; char pad[0x1C]; unsigned short port; char pad2[0x32]; void *ctx; } UpnpDE00;
extern int rt_memory_allocate_init_zero(void *pp, unsigned long size);
extern void rt_memory_free(void *pp);
extern int rt_comm_get_local_ip(int *p);
int rt_upnp_create(UpnpDE00 **out, int sock, unsigned short port)
{
    UpnpDE00 *u = 0;
    if (out == 0) return 2;
    *out = 0;
    if (sock == 0) return 2;
    if (rt_memory_allocate_init_zero(&u, 0x64) != 0) return 3;
    if (rt_memory_allocate_init_zero(&u->ctx, 0x2E70) != 0) {
        rt_memory_free(&u);
        return 3;
    }
    if (rt_comm_get_local_ip(&u->x4) != 0) {
        rt_memory_free(&u->ctx);
        rt_memory_free(&u);
        return 5;
    }
    u->port = port;
    u->sock = sock;
    *out = u;
    return 0;
}
