/*
 * lib/medius: 6 files, 003043E8-00304800
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003043E8 */
typedef struct { int type; int f4; int f8; int pad[7]; } UpnpEnt;
typedef struct { char pad[0x180]; int h180; UpnpEnt *ent; int count; int f18C; int f190; } UpnpObj;
typedef struct { char pad[0x40]; char a40[16]; char a50[16]; unsigned short p60; unsigned short p62; } UpnpAddr;
extern int rt_p2p_get_peer_address(UpnpObj *o, int peer, int mode, char *addr, unsigned short *port);
extern int Libc_Strncmp(const char *, const char *, unsigned int);

int rt_p2p_get_peer_by_address(UpnpObj *o, UpnpAddr *a, int *out)
{
    char addr[16];
    unsigned short port;
    int i;
    int match;
    if (out == 0) return 2;
    *out = -2;
    if (o == 0) return 2;
    if (a == 0) return 2;    for (i = 0; i < o->count; i++) {
        match = 0;
        rt_p2p_get_peer_address(o, i, 0, addr, &port);
        Libc_Strncmp(addr, a->a40, 16);
        rt_p2p_get_peer_address(o, i, 1, addr, &port);
        if (Libc_Strncmp(addr, a->a50, 16) == 0) match = (port == a->p62);
        if (match) { *out = i; break; }
    }
    return 0;
}
/* merge_units: end func_003043E8 */

/* merge_units: begin func_00304508 */
int rt_p2p_get_peer_by_connection(UpnpObj *o, int key, int *out)
{
    int i;
    if (out == 0) return 2;
    *out = -2;
    if (o == 0) return 2;    for (i = 0; i < o->count; i++) {
        if (key == o->ent[i].f4) { *out = i; break; }
        if (key == o->ent[i].f8) { *out = i; break; }
    }
    return 0;
}
/* merge_units: end func_00304508 */

/* merge_units: begin func_00304578 */
int rt_p2p_get_my_peer_status(UpnpObj *o, int *type, int *idx)
{
    int i;
    int t;
    if (type == 0) return 2;
    *type = 0;
    if (idx == 0) return 2;
    *idx = -2;
    if (o == 0) return 2;

    for (i = 0; i < o->count; i++) {
        if (o->ent[i].type == 6) { *type = o->ent[i].type; *idx = i; break; }
        if (o->ent[i].type == 7 || o->ent[i].type == 5) { *type = o->ent[i].type; *idx = i; break; }
    }
    return 0;
}
/* merge_units: end func_00304578 */

/* merge_units: begin func_00304618 */
extern void *memset(void *, int, unsigned int);

int rt_p2p_find_free_peer_index(UpnpObj *o, int *out)
{
    int i;
    if (out == 0) return 2;
    *out = -2;    for (i = 0; i < o->count; i++) {
        if (o->ent[i].type == 0) {
            *out = i;
            memset(&o->ent[i], 0, sizeof(UpnpEnt));
            o->ent[i].f8 = o->ent[i].f4 = -1;
            break;
        }
    }
    return 0;
}
/* merge_units: end func_00304618 */

/* merge_units: begin func_003046C8 */
typedef struct { int magic; char a4[0x10]; char a14[0x10]; unsigned short p24; unsigned short p26; int peer; unsigned char b2C; char pad[3]; char b30[0x40]; } UpnpRec;
extern int rt_p2p_get_my_peer_status(UpnpObj *o, int *type, int *idx);
extern int rt_p2p_get_my_address(UpnpObj *o, int mode, void *a, void *b);
#if 0 /* merge_units */
extern int rt_p2p_get_peer_address(UpnpObj *o, int peer, int mode, void *a, void *b);
#endif /* merge_units */
#define rt_p2p_get_peer_address(a0, a1, a2, a3, a4) (rt_p2p_get_peer_address((a0), (a1), (a2), (char *)(a3), (unsigned short *)(a4))) /* merge_units */

extern int KM_GetLocalPublicKey(int, void *);
extern int KM_GetPublicKey(int, int, void *);
int rt_p2p_fill_new_peer_struct(UpnpObj *o, int peer, UpnpRec *r)
{
    int type;
    int idx;
    int ret;
    idx = -2;
    type = 0;
    if (r == 0) return 2;
    if ((ret = rt_p2p_get_my_peer_status(o, &type, &idx)) != 0) return ret;
    memset(r, 0, 0x70);
    r->magic = 0xEFF0CDAB;
    r->peer = peer;    if (peer == idx) {
        r->b2C = 1;
        if ((ret = rt_p2p_get_my_address(o, 0, r->a4, &r->p24)) != 0) return ret;
        ret = rt_p2p_get_my_address(o, 1, r->a14, &r->p26);
        KM_GetLocalPublicKey(-1, r->b30);
        if (ret == 0) goto ok;
        return ret;
    }
    if ((ret = rt_p2p_get_peer_address(o, peer, 0, r->a4, &r->p24)) != 0) return ret;
    ret = rt_p2p_get_peer_address(o, peer, 1, r->a14, &r->p26);
    KM_GetPublicKey(-1, peer, r->b30);
    if (ret != 0) return ret;
ok:
    return 0;
}
#undef rt_p2p_get_peer_address /* merge_units */
/* merge_units: end func_003046C8 */

/* merge_units: begin func_00304800 */
typedef struct { int type; int f4; int f8; unsigned char bC, bD, bE, bF; int pad[6]; } UpnpEnt_00304800;
typedef struct {
    char pad[0x180];
    int h180;
    UpnpEnt_00304800 *ent;
    int count;
    int size;
    void *buf;
    unsigned char b194;
    char pad195[0x13];
    void (*cb1A8)(int peer, void *data, unsigned short len);
    void (*cb1AC)(void *addr, unsigned short port, void *data, unsigned short len);
} UpnpObj_00304800;
extern void *memcpy(void *, const void *, unsigned int);
extern int rt_udp_recv(int h, int ep, void *buf, int size, int *len);
extern int rt_p2p_process_internal_message(UpnpObj_00304800 *o, int peer, void *data, int len);
extern int rt_udp_get_address(int h, int ep, void *addr, unsigned short *port);

int rt_p2p_receive_messages(UpnpObj_00304800 *o)
{
    char addr[16];
    unsigned short port;
    int len;
    int magic;
    int i;
    int got;
    int rv;

    for (i = 0; i < o->count; i++) {
        while (o->ent[i].bF != 0) {
            got = 0;
            if (o->ent[i].f4 != -1) {
                magic = 0;
                if (rt_udp_recv(o->h180, o->ent[i].f4, o->buf, o->size, &len) == 0 && len != 0) {
                    memcpy(&magic, o->buf, 4);
                    if (magic != (int)0xEFF0CDAB) {
                        o->cb1A8(i, o->buf, len);
                    } else {
                        rv = rt_p2p_process_internal_message(o, i, o->buf, len);
                        if (rv != 0)
                            return rv;
                    }
                    got = 1;
                }
            }
            if (o->ent[i].f8 != -1) {
                magic = 0;
                if (rt_udp_recv(o->h180, o->ent[i].f8, o->buf, o->size, &len) == 0 && len != 0) {
                    memcpy(&magic, o->buf, 4);
                    if (magic != (int)0xEFF0CDAB) {
                        o->cb1A8(i, o->buf, len);
                    } else {
                        rv = rt_p2p_process_internal_message(o, i, o->buf, len);
                        if (rv != 0)
                            return rv;
                    }
                    got = 1;
                }
            }
            if (!got)
                o->ent[i].bF = 0;
        }
    }
    while (o->b194 != 0) {
        if (rt_udp_get_address(o->h180, -2, addr, &port) != 0)
            return 7;
        if (rt_udp_recv(o->h180, -2, o->buf, o->size, &len) == 0 && len != 0)
            o->cb1AC(addr, port, o->buf, len);
        else
            o->b194 = 0;
    }
    return 0;
}
/* merge_units: end func_00304800 */
