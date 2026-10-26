typedef struct { int f0; char pad4[0x18]; char f1C[0x18]; char f34[0x5C]; } RtPeer;
typedef struct {
    int f0; RtPeer *peers; int f8; char q[0x20]; int npeers; int f30; int f34; int f38; int f3C; int f40;
    short f44; unsigned short port; int f48; int f4C; int f50;
} RtUdp;
extern void rt_udp_destroy_shared_channel_data(RtUdp *r);
extern int rt_list_buf_destroy(void *q);
extern void rt_memory_free(void *pp);
int rt_udp_destroy(RtUdp *arg)
{
    RtUdp *r = 0;
    unsigned int i = 0;
    if (arg == 0) return 2;
    r = arg;
    if (r->f0 != 0) rt_udp_destroy_shared_channel_data(r);
    if (r->peers != 0) {
        for (i = 0; i < r->npeers; i++) {
            if (r->peers[i].f0 != 0) {
                rt_list_buf_destroy(r->peers[i].f1C);
                rt_list_buf_destroy(r->peers[i].f34);
                r->peers[i].f0 = 0;
            }
        }
        rt_memory_free(&r->peers);
    }
    rt_list_buf_destroy(r->q);
    rt_memory_free(&r);
    return 0;
}

