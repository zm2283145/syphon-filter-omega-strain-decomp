typedef struct { int type; int f4; int f8; unsigned char bC, bD, bE, bF; unsigned char b10, b11, b12, b13; int pad[5]; } UpnpEnt;
typedef struct {
    char pad[0x180]; int h180; UpnpEnt *ent; int count; int f18C; int f190;
    unsigned char b194, b195, b196, b197;
    void (*cb198)(int idx, unsigned short n, int x);
    int f19C; int f1A0;
    void (*cb1A4)(int idx, int x);
} UpnpObj;
typedef struct { unsigned int magic; } UpnpMsg;
extern int RtUdp_SendToPeerEndpoint(UpnpObj *o, int peer, unsigned char type, void *data, unsigned short len);

int RtUdp_SendToPeers(UpnpObj *o, int peer, unsigned char type, void *data, unsigned short len)
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
