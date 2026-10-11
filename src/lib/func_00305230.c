typedef struct { char pad[0x195]; unsigned char b195; } UpnpObj_230;
typedef struct { unsigned int magic; unsigned char b; } UpnpPkt_230;
extern int RtUdp_SendToPeerEndpoint(UpnpObj_230 *o, int peer, int type, void *data, int len);
int func_00305230(UpnpObj_230 *o, int peer)
{
    UpnpPkt_230 pkt;
    pkt.magic = 0xEFF0CDAB;
    pkt.b = o->b195;
    return RtUdp_SendToPeerEndpoint(o, peer, 7, &pkt, 8);
}