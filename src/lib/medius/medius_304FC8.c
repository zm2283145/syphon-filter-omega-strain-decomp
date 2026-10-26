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

int rt_p2p_complete_connection(UpnpObj *o)
{
    UpnpMsg m;
    int i;
    int r;    int state = 0;
    int host = -2;
    int conn = 0;
    int pending = 0;
    for (i = 0; i < o->count; i++) {
        switch (o->ent[i].type) {
        case 0: break;
        case 1: case 2: pending++; break;
        case 3: case 4: conn++; break;
        case 5: state = 5; host = i; break;
        case 6: case 7: break;
        }
    }
    if (state == 5 && pending == 0 && conn != 0) {
        o->ent[host].type = 6;
        o->cb198(host, conn + 1, 0);
        for (i = 0; i < o->count; i++) {
        if (o->ent[i].type - 3 < 2u) {
            m.magic = 0xEFF0CDAB;
            if ((r = RtUdp_SendToPeerEndpoint(o, i, 7, &m, 4)) != 0) return r;
            if (o->ent[i].b11) { o->ent[i].b11 = 0; o->cb1A4(i, 0); }
        }
    }
    }
    return 0;
}

