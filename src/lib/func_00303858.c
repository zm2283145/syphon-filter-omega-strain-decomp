typedef struct { unsigned int state; char pad[0x24]; } Ent3858;
typedef struct { char pad[0x184]; Ent3858 *ents; int count; char pad2[9]; unsigned char v; } Obj3858;
typedef struct { int magic; unsigned char v; } Msg3858;
extern int RtUdp_SendToPeerEndpoint(Obj3858 *o, int idx, unsigned char flag, void *data, unsigned short len);
int func_00303858(Obj3858 *o, unsigned char v)
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
