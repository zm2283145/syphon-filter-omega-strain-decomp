/* rt_p2p_process_internal_message: medius peer-connection message handler (kinds 0x70 connect/NAT records, 4, 8, 12);
 * sibling of rt_p2p_handle_connected_event (lib/medius). */
typedef struct {
    int type;
    int f4;
    int f8;
    unsigned char bC, bD, bE, bF;
    unsigned char b10;
    unsigned char b11;
    char pad12[0x24 - 0x12];
    void *x24;
} UpnpEnt4A98;
typedef struct {
    char pad[0x180];
    int h180;
    UpnpEnt4A98 *ent;
    int count;
    char pad18C[0x1A4 - 0x18C];
    void (*fn1A4)(int idx, int v);
    char pad1A8[0x1B4 - 0x1A8];
    void (*fn1B4)(int idx, unsigned char v);
} UpnpObj4A98;
typedef struct {
    int x0;
    union { signed char name1[16]; int idx4; unsigned char u4; };
    signed char name2[16];
    unsigned short port1;
    unsigned short port2;
    int peer;
    unsigned char b2C;
    unsigned char b2D;
    char pad2E[2];
    char x30[1];
} UpnpMsg4A98;
typedef struct {
    char ip[16];
    unsigned short port;
    int peer;
} UpnpAddr4A98;
typedef struct { char d[64]; } UpnpBuf4A98;

extern int rt_p2p_get_my_peer_status(UpnpObj4A98 *o, int *type, int *idx);
extern void *memset(void *d, int c, unsigned int n);
extern char *strncpy(char *d, const char *s, unsigned int n);
extern void KM_CopyKeys(int a, int b, int c, int d);
extern void KM_DeleteKeys(int a, int b);
extern int GetKeyMaster(int a);
extern void *GetKeyChain(int a, int b);
extern int rt_udp_set_peer_id(int h, int a, int b);
extern void KM_SetLocalClientID(int a);
extern void KM_SetPublicKey(int a, int b, void *c);
extern void KM_CreateRandomRCKey(UpnpBuf4A98 *b);
extern int KM_AddSymmetricKey(int a, int b, UpnpBuf4A98 *c);
extern int rt_p2p_find_backlog_connection(UpnpObj4A98 *o, UpnpMsg4A98 *m, UpnpEnt4A98 *e);
extern int rt_udp_connect(int h, UpnpAddr4A98 *a, int *out);
extern int rt_udp_pre_accept(int h, UpnpAddr4A98 *a, int *out);
extern void rt_p2p_generic_disconnect(UpnpObj4A98 *o, int a, int b);

int rt_p2p_process_internal_message(UpnpObj4A98 *o, int idx, UpnpMsg4A98 *m, int kind)
{
    UpnpAddr4A98 addr;
    UpnpBuf4A98 buf;
    int ret;

    if (kind == 0x70) {
        UpnpEnt4A98 *e;
        int type;
        int peer;
        int r;

        type = 0;
        peer = -2;
        if (m->peer < 0 || m->peer >= o->count)
            return 14;
        e = &o->ent[m->peer];
        if ((ret = rt_p2p_get_my_peer_status(o, &type, &peer)) != 0)
            return ret;
        if (!type || type == 5) {
            int pp = m->peer;
            if (m->b2C && pp) {
                UpnpEnt4A98 *e0 = o->ent;
                *e = *e0;
                memset(e0, 0, sizeof(UpnpEnt4A98));
                e0->f4 = -1;
                e0->f8 = -1;
                KM_CopyKeys(-1, 0, -1, m->peer);
                KM_DeleteKeys(-1, 0);
                e->x24 = GetKeyChain(GetKeyMaster(-1), m->peer);
                rt_udp_set_peer_id(o->h180, e->f4, m->peer);
                rt_udp_set_peer_id(o->h180, e->f8, m->peer);
                return 0;
            }
            if (type == 0 && m->b2D) {
                KM_SetLocalClientID(-1);
                e->type = 5;
                return 0;
            }
            KM_SetPublicKey(-1, pp, m->x30);
            e->x24 = GetKeyChain(GetKeyMaster(-1), m->peer);
            KM_CreateRandomRCKey(&buf);
            KM_AddSymmetricKey(-1, m->peer, &buf);
            if (rt_p2p_find_backlog_connection(o, m, e) != 0)
                return 0;
            if (m->name1[0] && m->port1) {
                strncpy(addr.ip, (char *)m->name1, 16);
                addr.port = m->port1;
                addr.peer = m->peer;
                if (type == 0)
                    r = rt_udp_connect(o->h180, &addr, &e->f4);
                else
                    r = rt_udp_pre_accept(o->h180, &addr, &e->f4);
                if (r != 21) {
                    if (r != 0)
                        return 7;
                    e->type = 2;
                }
            }
            if (!m->name2[0] || !m->port2)
                return 0;
            strncpy(addr.ip, (char *)m->name2, 16);
            addr.port = m->port2;
            addr.peer = m->peer;
            if (type == 0)
                r = rt_udp_connect(o->h180, &addr, &e->f8);
            else
                r = rt_udp_pre_accept(o->h180, &addr, &e->f8);
        } else {
            if (type != 6)
                goto out0;
            KM_SetPublicKey(-1, m->peer, m->x30);
            e->x24 = GetKeyChain(GetKeyMaster(-1), m->peer);
            KM_CreateRandomRCKey(&buf);
            KM_AddSymmetricKey(-1, m->peer, &buf);
            addr.peer = m->peer;
            if (rt_p2p_find_backlog_connection(o, m, e) != 0)
                return 0;
            if (m->name1[0] && m->port1) {
                strncpy(addr.ip, (char *)m->name1, 16);
                addr.port = m->port1;
                r = rt_udp_pre_accept(o->h180, &addr, &e->f4);
                if (r != 21) {
                    if (r != 0)
                        return 7;
                    e->type = 2;
                }
            }
            if (!m->name2[0] || !m->port2)
                return 0;
            strncpy(addr.ip, (char *)m->name2, 16);
            addr.port = m->port2;
            r = rt_udp_pre_accept(o->h180, &addr, &e->f8);
        }
        if (r != 21) {
            if (r != 0)
                return 7;
            e->type = 2;
        }
        return 0;
    } else if (kind == 4) {
        int type;
        int peer;

        type = 0;
        peer = -2;
        if ((ret = rt_p2p_get_my_peer_status(o, &type, &peer)) != 0)
            return ret;
        if ((unsigned int)(type - 6) < 2) {
            o->fn1A4(idx, 0);
            return 0;
        }
        o->ent[idx].b11 = 1;
    } else if (kind == 8) {
        o->ent[idx].b10 = m->u4;
        o->fn1B4(idx, m->u4);
        return 0;
    } else if (kind == 12) {
        int k = m->idx4;
        if (o->ent[k].f4 != -1) {
            rt_p2p_generic_disconnect(o, o->ent[k].f4, 16);
            return 0;
        }
        if (o->ent[k].f8 != -1)
            rt_p2p_generic_disconnect(o, o->ent[k].f8, 16);
    }
out0:
    return 0;
}
