typedef struct { int type; int f4; int f8; unsigned char bC, bD, bE, bF; int pad[6]; } UpnpEnt;
typedef struct { char pad[0x180]; int h180; UpnpEnt *ent; int count; int f18C; int f190; } UpnpObj;
typedef struct { int magic; char a4[0x10]; char a14[0x10]; unsigned short p24; unsigned short p26; int peer; unsigned char b2C; unsigned char b2D; char pad[2]; char b30[0x40]; } UpnpRec;
extern int func_00304578(UpnpObj *o, int *type, int *idx);
extern int func_00304508(UpnpObj *o, int key, int *out);
extern int func_003046C8(UpnpObj *o, int peer, UpnpRec *r);
extern int RtUdp_SendToPeerEndpoint(UpnpObj *o, int peer, unsigned char type, void *data, unsigned short len);
extern int func_00305230(UpnpObj *o, int idx);
extern void func_00307928(int h, int key);

void func_00303D98(UpnpObj *o, int key)
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
    if (func_00304578(o, &type, &peer) != 0)
        return;
    if (func_00304508(o, key, &idx) != 0 || idx == -2) {
        func_00307928(o->h180, key);
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
                if ((ret = func_003046C8(o, peer, &rec)) != 0)
                    return;
                if ((ret = RtUdp_SendToPeerEndpoint(o, idx, 7, &rec, 0x70)) != 0)
                    return;
            }
            for (i = 0; i < o->count; i++) {
                if (o->ent[i].type == 3 && i != idx) {
                    func_003046C8(o, i, &rec);
                    if ((ret = RtUdp_SendToPeerEndpoint(o, idx, 7, &rec, 0x70)) != 0)
                        return;
                }
            }
            if ((ret = func_003046C8(o, idx, &rec)) != 0)
                return;
            rec.b2D = 1;
            if ((ret = RtUdp_SendToPeerEndpoint(o, idx, 7, &rec, 0x70)) != 0)
                return;
            if ((ret = func_003046C8(o, idx, &rec)) != 0)
                return;
            for (i = 0; i < o->count; i++) {
                if (o->ent[i].type == 3 && i != idx) {
                    if ((ret = RtUdp_SendToPeerEndpoint(o, i, 7, &rec, 0x70)) != 0)
                        return;
                }
            }
            ret = func_00305230(o, idx);
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
            func_00305230(o, idx);
        } else if (o->ent[idx].type == 1) {
            o->ent[idx].type = 4;
            if (o->ent[idx].f4 == key)
                o->ent[idx].bC = 1;
            else if (o->ent[idx].f8 == key)
                o->ent[idx].bD = 1;
            ret = func_00305230(o, idx);
        } else {
            if (o->ent[idx].f4 == key)
                o->ent[idx].bC = 1;
            else if (o->ent[idx].f8 == key)
                o->ent[idx].bD = 1;
        }
    }
}