typedef struct { int h; int a; int b; } RtUdpSlot;
typedef struct { int type; int f4; int f8; int pad[7]; } RtUdpPeer;
typedef struct { RtUdpSlot slot[32]; void *h180; RtUdpPeer *ent; } RtUdpObj;
extern int rt_p2p_get_my_peer_status(RtUdpObj *o, int *type, int *peer);
extern int rt_p2p_find_free_peer_index(RtUdpObj *o, int *idx);
extern void rt_udp_deny(void *h, int key);
extern void rt_udp_accept(void *h, int key);
extern void rt_udp_set_peer_id(void *h, int key, int idx, int x);
extern void KM_CreateRandomRCKey(void *buf);
extern void KM_AddSymmetricKey(int a, int idx, void *buf);
extern int rt_time_elapsed(int *t, unsigned int *out);
extern void rt_time_start(int *t);

void rt_p2p_handle_connect_event(RtUdpObj *o, int key)
{
    char buf[0x40];
    int type;
    int peer;
    int idx;
    unsigned int el;
    unsigned int i;
    unsigned int fr;
    RtUdpSlot *s;

    type = 0;
    peer = -2;
    idx = -2;
    if (rt_p2p_get_my_peer_status(o, &type, &peer) == 0) {
        if (type == 7) {
            if (rt_p2p_find_free_peer_index(o, &idx) == 0) {
                if (idx != -2) {
                    /* pinned copy: retail shares one -1 register for the store and the 4th arg */
                    register int m1 asm("$7") = -1;
                    o->ent[idx].type = 2;
                    o->ent[idx].f4 = key;
                    o->ent[idx].f8 = m1;
                    rt_udp_set_peer_id(o->h180, key, idx, m1);
                    KM_CreateRandomRCKey(buf);
                    KM_AddSymmetricKey(-1, idx, buf);
                    rt_udp_accept(o->h180, key);
                } else {
                    rt_udp_deny(o->h180, key);
                }
            }
        } else {
            fr = 32;
            for (i = 0; i < 32; i++) {
                if (o->slot[i].h == key) {
                    rt_time_elapsed(&o->slot[i].a, &el);
                    if (el <= 30000)
                        return;
                    rt_udp_deny(o->h180, key);
                    o->slot[i].h = -1;
                    return;
                }
                if (o->slot[i].h == -1 && fr == 32)
                    fr = i;
            }
            if (fr != 32) {
                o->slot[fr].h = key;
                rt_time_start(&o->slot[fr].a);
            } else {
                rt_udp_deny(o->h180, key);
            }
        }
    }
}





