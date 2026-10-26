/*
 * lib/medius: 3 files, 00305420-003055E8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00305420 */
typedef struct { int state; char pad[0x24]; } Slot5420;
typedef struct { char pad[0x184]; Slot5420 *slots; int count; } Owner5420;
int rt_p2p_determine_new_host(Owner5420 *o, int *out)
{
    int i;
    if (out == 0) return 2;
    *out = -2;
    for (i = 0; i < o->count; i++) {
        if (o->slots[i].state == 3) {
            *out = i;
            o->slots[i].state = 4;
            break;
        }
        if (o->slots[i].state == 6) {
            *out = i;
            o->slots[i].state = 7;
            break;
        }
    }
    return 0;
}
/* merge_units: end func_00305420 */

/* merge_units: begin func_003054C8 */
typedef struct { int type; int f4; int f8; unsigned char bC, bD, bE, bF; int pad[6]; } UpnpEnt;
typedef struct { char pad[0x180]; int h180; UpnpEnt *ent; int count; int f18C; int f190; } UpnpObj;
typedef struct { unsigned int magic; int n; int pad; } UpnpMsg3;
extern int RtUdp_SendToPeerEndpoint(UpnpObj *o, int peer, unsigned char type, void *data, unsigned short len);

int rt_p2p_send_broadcast_disconnect(UpnpObj *o, int n, int base)
{
    UpnpMsg3 m;
    int i;
    int found;
    m.magic = 0xEFF0CDAB;
    i = 0;
    found = 0;
    m.n = base;
    if (n) {
        if (base < n) i = n - 1;
    } else i = o->count - 1;
    for (; base < i; i--) {
        if (o->ent[i].type == 3) found = 1;
        if (o->ent[i].type == 4) found = 1;
    }
    if (!found) {
        for (i = 0; i < o->count; i++) {
            if (o->ent[i].type - 3 < 2u) {
                RtUdp_SendToPeerEndpoint(o, i, 7, &m, 12);
            }
        }
    }
    return 0;
}
/* merge_units: end func_003054C8 */

/* merge_units: begin func_003055E8 */
typedef struct { int h; int a; int b; } UpnpSlot;
typedef struct { UpnpSlot slot[32]; int h180; } UpnpObj_003055E8;
typedef struct { int f0; char a[16]; char b[16]; unsigned short pa; unsigned short pb; int f28; } PeerInfo;
typedef struct { int type; int f4; int f8; char pad[6]; char name[16]; unsigned short port; } PeerOut;
extern int rt_udp_get_address(int h, int ep, char *addr, unsigned short *port);
extern int rt_udp_set_peer_id(int h, int ep, int val);
extern void KM_CreateRandomRCKey(void *buf);
extern int KM_AddSymmetricKey(int a, int peer, void *buf);
extern int rt_udp_accept(int h, int ep);
extern int String_CompareN(const char *a, const char *b, int n);
extern char *strncpy(char *d, const char *s, unsigned int n);

int rt_p2p_find_backlog_connection(UpnpObj_003055E8 *o, PeerInfo *in, PeerOut *out)
{
    char addr[16];
    unsigned short port;
    unsigned int i;
    if (o == 0) return 0;
    if (in == 0) return 0;
    i = 0;
    do {
        if (o->slot[i].h == -1) continue;
        if (rt_udp_get_address(o->h180, o->slot[i].h, addr, &port) != 0) break;
        if (String_CompareN(addr, in->a, 16) == 0 && port == in->pa && port != 0) {
            char buf[64];
            rt_udp_set_peer_id(o->h180, o->slot[i].h, in->f28);
            KM_CreateRandomRCKey(buf);
            KM_AddSymmetricKey(-1, in->f28, buf);
            rt_udp_accept(o->h180, o->slot[i].h);
            strncpy(out->name, in->b, 16);
            out->port = in->pb;
            out->f4 = o->slot[i].h;
            out->type = 2;
            o->slot[i].h = -1;
            return 1;
        }
        if (String_CompareN(addr, in->b, 16) == 0 && port == in->pb && port != 0) {
            char buf[64];
            rt_udp_set_peer_id(o->h180, o->slot[i].h, in->f28);
            KM_CreateRandomRCKey(buf);
            KM_AddSymmetricKey(-1, in->f28, buf);
            rt_udp_accept(o->h180, o->slot[i].h);
            strncpy(out->name, in->a, 16);
            out->port = in->pa;
            out->f8 = o->slot[i].h;
            out->type = 2;
            o->slot[i].h = -1;
            return 1;
        }
    } while (++i < 32);
    return 0;
}
/* merge_units: end func_003055E8 */
