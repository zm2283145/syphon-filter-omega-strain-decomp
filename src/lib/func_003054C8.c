typedef struct { int type; int f4; int f8; unsigned char bC, bD, bE, bF; int pad[6]; } UpnpEnt;
typedef struct { char pad[0x180]; int h180; UpnpEnt *ent; int count; int f18C; int f190; } UpnpObj;
typedef struct { unsigned int magic; int n; int pad; } UpnpMsg3;
extern int RtUdp_SendToPeerEndpoint(UpnpObj *o, int peer, unsigned char type, void *data, unsigned short len);

int func_003054C8(UpnpObj *o, int n, int base)
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

