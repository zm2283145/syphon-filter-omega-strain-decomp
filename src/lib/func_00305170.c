typedef struct { int type; int f4; int f8; unsigned char bC, bD, bE, bF; int pad[6]; } UpnpEnt;
typedef struct { char pad[0x180]; int h180; UpnpEnt *ent; int count; int f18C; int f190; } UpnpObj;
extern int RtUdp_QueueSend(int h, int ep, unsigned char type, void *data, unsigned short len);

int RtUdp_SendToPeerEndpoint(UpnpObj *o, int peer, unsigned char type, void *data, unsigned short len)
{
    int ep;
    if (peer < 0 || peer >= o->count) return 8;    if (o->ent[peer].f4 != -1 && o->ent[peer].bC) {
        if (RtUdp_QueueSend(o->h180, o->ent[peer].f4, type, data, len) != 0) return 7;
    } else if (o->ent[peer].f8 != -1 && o->ent[peer].bD) {
        if (RtUdp_QueueSend(o->h180, o->ent[peer].f8, type, data, len) != 0) return 7;
    } else return 6;
    return 0;
}
