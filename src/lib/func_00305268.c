typedef struct { int type; int f4; int f8; unsigned char bC, bD, bE, bF; int pad[6]; } UpnpEnt;
typedef struct {
    char pad[0x180];
    int h180;
    UpnpEnt *ent;
    int count;
    int f18C;
    int f190;
    unsigned char b194, b195, b196, b197;
    void (*cb198)(int idx, int n, int x);
    int f19C;
    void (*cb1A0)(int a); /* one arg: retail's slot a1 is a reorg target-thread copy */
    void (*cb1A4)(int idx, int x);
} UpnpObj;

extern int rt_p2p_get_peer_by_connection(UpnpObj *o, int peer, int *idx);
extern int rt_udp_disconnect(int h, int ep);
extern int rt_p2p_get_my_peer_status(UpnpObj *o, int *st, int *a);
extern void rt_p2p_disconnect(UpnpObj *o);
extern int rt_p2p_determine_new_host(UpnpObj *o, int *out);
extern int rt_p2p_send_broadcast_disconnect(UpnpObj *o, long n, int base);
extern void *memset(void *, int, unsigned int);

int rt_p2p_generic_disconnect(UpnpObj *o, int peer)
{
    int idx;
    int st;
    int a;
    int c;
    UpnpEnt *e;
    int r;

    idx = -2;
    a = -2;
    c = -2;
    st = 0;
    if (rt_p2p_get_peer_by_connection(o, peer, &idx) != 0 || idx == -2) {
        rt_udp_disconnect(o->h180, peer);
        r = rt_p2p_get_my_peer_status(o, &st, &a);
        if (r != 0) return r;
        if (st == 5 || st == 0) {
            rt_p2p_disconnect(o);
            if (o->cb198) o->cb198(-2, 0, 6);
            return 6;
        }
        return r;
    }
    e = &o->ent[idx];
    r = rt_p2p_get_my_peer_status(o, &st, &a);
    if (r != 0) return r;
    if (st == 5 || st == 0) {
fail:
        rt_p2p_disconnect(o);
        if (o->cb198) o->cb198(-2, 0, 6);
        return 6;
    }
    if (e->f4 != -1) rt_udp_disconnect(o->h180, e->f4);
    if (e->f8 != -1) rt_udp_disconnect(o->h180, e->f8);
    o->cb1A4(idx, 1);
    if (e->type == 4) rt_p2p_determine_new_host(o, &c);
    memset(e, 0, 0x28);
    e->f4 = -1;
    e->f8 = -1;
    if (c != -2) o->cb1A0(c);
    rt_p2p_send_broadcast_disconnect(o, a, idx);
    return 0;
}

