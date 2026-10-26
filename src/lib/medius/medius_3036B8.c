/*
 * lib/medius: 3 files, 003036B8-00303858
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003036B8 */
typedef struct { int type; int f4; int f8; int pad[7]; } UpnpEnt;
typedef struct { char pad[0x180]; int h180; UpnpEnt *ent; int count; int f18C; int f190; } UpnpObj;

extern int RtUdp_UpdateTransport(int h);
extern int RtUdp_DrainReceive(UpnpObj *o);
extern int rt_p2p_complete_connection(UpnpObj *o);
int rt_p2p_update(UpnpObj *o)
{
    int ret = 2;
    if (o == 0) return ret;
    if (RtUdp_UpdateTransport(o->h180) != 0) return 7;
    ret = RtUdp_DrainReceive(o);
    if (ret != 0) return ret;
    ret = rt_p2p_complete_connection(o);
    __asm__ __volatile__("");
    return ret;
}
/* merge_units: end func_003036B8 */

/* merge_units: begin func_00303710 */
typedef struct { int type; int f4; int f8; unsigned char bC, bD, bE, bF; unsigned char b10, b11, b12, b13; int pad[5]; } UpnpEnt_00303710;
typedef struct {
    char pad[0x180]; int h180; UpnpEnt_00303710 *ent; int count; int f18C; int f190;
    unsigned char b194, b195, b196, b197;
    void (*cb198)(int idx, unsigned short n, int x);
    int f19C; int f1A0;
    void (*cb1A4)(int idx, int x);
} UpnpObj_00303710;
typedef struct { unsigned int magic; } UpnpMsg;
extern int RtUdp_SendToPeerEndpoint(UpnpObj_00303710 *o, int peer, unsigned char type, void *data, unsigned short len);

int RtUdp_SendToPeers(UpnpObj_00303710 *o, int peer, unsigned char type, void *data, unsigned short len)
{
    int rv = 2;
    int ret = 0;
    int i;
    if (o != 0 && data != 0 && len != 0) {
        if (peer == -1) {
            for (i = 0; i < o->count; i++) {
                if (o->ent[i].b10) {
                    if (o->ent[i].type - 3 < 2u) ret = RtUdp_SendToPeerEndpoint(o, i, type, data, len);
                    if (ret != 0 && ret != 6) break;
                }
            }
        } else {
            if (o->ent[peer].type - 3 < 2u) ret = RtUdp_SendToPeerEndpoint(o, peer, type, data, len);
        }
        rv = ret;
    }
    return rv;
}
/* merge_units: end func_00303710 */

/* merge_units: begin func_00303858 */
typedef struct { unsigned int state; char pad[0x24]; } Ent3858;
typedef struct { char pad[0x184]; Ent3858 *ents; int count; char pad2[9]; unsigned char v; } Obj3858;
typedef struct { int magic; unsigned char v; } Msg3858;
#if 0 /* merge_units */
extern int RtUdp_SendToPeerEndpoint(Obj3858 *o, int idx, unsigned char flag, void *data, unsigned short len);
#endif /* merge_units */
#define RtUdp_SendToPeerEndpoint(a0, a1, a2, a3, a4) (RtUdp_SendToPeerEndpoint((UpnpObj_00303710 *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */

int rt_p2p_receive_broadcasts(Obj3858 *o, unsigned char v)
{
    Msg3858 m;
    int r = 0;
    int i;
    m.magic = 0xEFF0CDAB;
    m.v = v;
    if (o == 0) return 2;
    o->v = v;
    for (i = 0; i < o->count; i++) {
        if (o->ents[i].state - 3 < 2) r = RtUdp_SendToPeerEndpoint(o, i, 7, &m, 8);
        if (r != 0 && r != 6) return r;
    }
    return 0;
}
#undef RtUdp_SendToPeerEndpoint /* merge_units */
/* merge_units: end func_00303858 */
