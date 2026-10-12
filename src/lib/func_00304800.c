typedef struct { int type; int f4; int f8; unsigned char bC, bD, bE, bF; int pad[6]; } UpnpEnt;
typedef struct {
    char pad[0x180];
    int h180;
    UpnpEnt *ent;
    int count;
    int size;
    void *buf;
    unsigned char b194;
    char pad195[0x13];
    void (*cb1A8)(int peer, void *data, unsigned short len);
    void (*cb1AC)(void *addr, unsigned short port, void *data, unsigned short len);
} UpnpObj;
extern void *memcpy(void *, const void *, unsigned int);
extern int RtUdp_Read(int h, int ep, void *buf, int size, int *len);
extern int func_00304A98(UpnpObj *o, int peer, void *data, int len);
extern int func_00307598(int h, int ep, void *addr, unsigned short *port);

int RtUdp_DrainReceive(UpnpObj *o)
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
                if (RtUdp_Read(o->h180, o->ent[i].f4, o->buf, o->size, &len) == 0 && len != 0) {
                    memcpy(&magic, o->buf, 4);
                    if (magic != (int)0xEFF0CDAB) {
                        o->cb1A8(i, o->buf, len);
                    } else {
                        rv = func_00304A98(o, i, o->buf, len);
                        if (rv != 0)
                            return rv;
                    }
                    got = 1;
                }
            }
            if (o->ent[i].f8 != -1) {
                magic = 0;
                if (RtUdp_Read(o->h180, o->ent[i].f8, o->buf, o->size, &len) == 0 && len != 0) {
                    memcpy(&magic, o->buf, 4);
                    if (magic != (int)0xEFF0CDAB) {
                        o->cb1A8(i, o->buf, len);
                    } else {
                        rv = func_00304A98(o, i, o->buf, len);
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
        if (func_00307598(o->h180, -2, addr, &port) != 0)
            return 7;
        if (RtUdp_Read(o->h180, -2, o->buf, o->size, &len) == 0 && len != 0)
            o->cb1AC(addr, port, o->buf, len);
        else
            o->b194 = 0;
    }
    return 0;
}