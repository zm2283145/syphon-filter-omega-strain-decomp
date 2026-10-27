/*
 * lib/medius: 2 files, 00305170-00305230
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00305170 */
typedef struct { int type; int f4; int f8; unsigned char bC, bD, bE, bF; int pad[6]; } UpnpEnt;
typedef struct { char pad[0x180]; int h180; UpnpEnt *ent; int count; int f18C; int f190; } UpnpObj;
extern int rt_udp_send(int h, int ep, unsigned char type, void *data, unsigned short len);

int rt_p2p_isend(UpnpObj *o, int peer, unsigned char type, void *data, unsigned short len)
{
    int ep;
    if (peer < 0 || peer >= o->count) return 8;    if (o->ent[peer].f4 != -1 && o->ent[peer].bC) {
        if (rt_udp_send(o->h180, o->ent[peer].f4, type, data, len) != 0) return 7;
    } else if (o->ent[peer].f8 != -1 && o->ent[peer].bD) {
        if (rt_udp_send(o->h180, o->ent[peer].f8, type, data, len) != 0) return 7;
    } else return 6;
    return 0;
}
/* merge_units: end func_00305170 */

/* merge_units: begin func_00305230 */
typedef struct { char pad[0x195]; unsigned char b195; } UpnpObj_230;
typedef struct { unsigned int magic; unsigned char b; } UpnpPkt_230;
#if 0 /* merge_units */
extern int rt_p2p_isend(UpnpObj_230 *o, int peer, int type, void *data, int len);
#endif /* merge_units */
#define rt_p2p_isend(a0, a1, a2, a3, a4) (rt_p2p_isend((UpnpObj *)(a0), (a1), (unsigned char)(a2), (a3), (unsigned short)(a4))) /* merge_units */

int rt_p2p_send_my_broadcast_flag(UpnpObj_230 *o, int peer)
{
    UpnpPkt_230 pkt;
    pkt.magic = 0xEFF0CDAB;
    pkt.b = o->b195;
    return rt_p2p_isend(o, peer, 7, &pkt, 8);
}
#undef rt_p2p_isend /* merge_units */
/* merge_units: end func_00305230 */
