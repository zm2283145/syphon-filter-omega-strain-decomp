/*
 * lib/medius: 2 files, 00303D98-00304140
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00303D98 */
typedef struct { int type; int f4; int f8; unsigned char bC, bD, bE, bF; int pad[6]; } UpnpEnt;
typedef struct { char pad[0x180]; int h180; UpnpEnt *ent; int count; int f18C; int f190; } UpnpObj;
typedef struct { int magic; char a4[0x10]; char a14[0x10]; unsigned short p24; unsigned short p26; int peer; unsigned char b2C; unsigned char b2D; char pad[2]; char b30[0x40]; } UpnpRec;
extern int rt_p2p_get_my_peer_status(UpnpObj *o, int *type, int *idx);
extern int rt_p2p_get_peer_by_connection(UpnpObj *o, int key, int *out);
extern int rt_p2p_fill_new_peer_struct(UpnpObj *o, int peer, UpnpRec *r);
extern int RtUdp_SendToPeerEndpoint(UpnpObj *o, int peer, unsigned char type, void *data, unsigned short len);
extern int rt_p2p_send_my_broadcast_flag(UpnpObj *o, int idx);
extern void rt_udp_disconnect(int h, int key);

void rt_p2p_handle_connected_event(UpnpObj *o, int key)
{
    UpnpRec rec;
    int type;
    int peer;
    int idx;
    int i;
    int ret;

    type = 0;
    peer = -2;
    idx = -2;
    if (rt_p2p_get_my_peer_status(o, &type, &peer) != 0)
        return;
    if (rt_p2p_get_peer_by_connection(o, key, &idx) != 0 || idx == -2) {
        rt_udp_disconnect(o->h180, key);
        return;
    }
    if (type == 7) {
        if (o->ent[idx].type == 2) {
            o->ent[idx].type = 3;
            if (o->ent[idx].f4 == key)
                o->ent[idx].bC = 1;
            else if (o->ent[idx].f8 == key)
                o->ent[idx].bD = 1;
            if (peer != 0) {
                if ((ret = rt_p2p_fill_new_peer_struct(o, peer, &rec)) != 0)
                    return;
                if ((ret = RtUdp_SendToPeerEndpoint(o, idx, 7, &rec, 0x70)) != 0)
                    return;
            }
            for (i = 0; i < o->count; i++) {
                if (o->ent[i].type == 3 && i != idx) {
                    rt_p2p_fill_new_peer_struct(o, i, &rec);
                    if ((ret = RtUdp_SendToPeerEndpoint(o, idx, 7, &rec, 0x70)) != 0)
                        return;
                }
            }
            if ((ret = rt_p2p_fill_new_peer_struct(o, idx, &rec)) != 0)
                return;
            rec.b2D = 1;
            if ((ret = RtUdp_SendToPeerEndpoint(o, idx, 7, &rec, 0x70)) != 0)
                return;
            if ((ret = rt_p2p_fill_new_peer_struct(o, idx, &rec)) != 0)
                return;
            for (i = 0; i < o->count; i++) {
                if (o->ent[i].type == 3 && i != idx) {
                    if ((ret = RtUdp_SendToPeerEndpoint(o, i, 7, &rec, 0x70)) != 0)
                        return;
                }
            }
            ret = rt_p2p_send_my_broadcast_flag(o, idx);
        } else {
            if (o->ent[idx].f4 == key)
                o->ent[idx].bC = 1;
            else if (o->ent[idx].f8 == key)
                o->ent[idx].bD = 1;
        }
    } else {
        if (o->ent[idx].type == 2) {
            o->ent[idx].type = 3;
            if (o->ent[idx].f4 == key)
                o->ent[idx].bC = 1;
            else if (o->ent[idx].f8 == key)
                o->ent[idx].bD = 1;
            rt_p2p_send_my_broadcast_flag(o, idx);
        } else if (o->ent[idx].type == 1) {
            o->ent[idx].type = 4;
            if (o->ent[idx].f4 == key)
                o->ent[idx].bC = 1;
            else if (o->ent[idx].f8 == key)
                o->ent[idx].bD = 1;
            ret = rt_p2p_send_my_broadcast_flag(o, idx);
        } else {
            if (o->ent[idx].f4 == key)
                o->ent[idx].bC = 1;
            else if (o->ent[idx].f8 == key)
                o->ent[idx].bD = 1;
        }
    }
}
/* merge_units: end func_00303D98 */

/* merge_units: begin func_00304140 */
typedef struct { char pad[0x180]; int h180; UpnpEnt *ent; int count; int f18C; int f190; unsigned char b194; char pad2[0x1B]; void (*cb)(void *buf, int len, int code); } UpnpObj_00304140;
#if 0 /* merge_units */
extern int rt_p2p_get_peer_by_connection(UpnpObj_00304140 *o, int key, int *out);
#endif /* merge_units */
#define rt_p2p_get_peer_by_connection(a0, a1, a2) (rt_p2p_get_peer_by_connection((UpnpObj *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern int rt_udp_disconnect(int h, int key);
#endif /* merge_units */
#define rt_udp_disconnect(a0, a1) ((int)rt_udp_disconnect((a0), (a1))) /* merge_units */

#define UPNP_MARK_FLAG(name, field, ON_ALL) void name(UpnpObj_00304140 *o, int key) { int idx; if (key == -2) { ON_ALL; return; } idx = -2; if (rt_p2p_get_peer_by_connection(o, key, &idx) != 0 || idx == -2) { rt_udp_disconnect(o->h180, key); return; } o->ent[idx].field = 1; }
extern int rt_udp_get_resolved_address(int h, void *buf, unsigned short *len);
void rt_p2p_handle_resolve_event(UpnpObj_00304140 *o, int unused, int flag)
{
    char buf[16];
    unsigned short len = 0;
    if (flag == 0) {
        if (rt_udp_get_resolved_address(o->h180, buf, &len) == 0) o->cb(buf, len, 0);
    } else {
        o->cb(buf, 0, 5);
    }
}
#undef rt_p2p_get_peer_by_connection /* merge_units */
#undef rt_udp_disconnect /* merge_units */
/* merge_units: end func_00304140 */
