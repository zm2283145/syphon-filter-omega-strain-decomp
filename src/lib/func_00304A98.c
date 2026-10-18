/* func_00304A98: medius peer-connection message handler (kinds 0x70 connect/NAT records, 4, 8, 12);
 * sibling of func_00303D98 (lib/medius). */
typedef struct {
    int type;
    int f4;
    int f8;
    unsigned char bC, bD, bE, bF;
    unsigned char b10;
    unsigned char b11;
    char pad12[0x24 - 0x12];
    void *x24;
} UpnpEnt4A98;
typedef struct {
    char pad[0x180];
    int h180;
    UpnpEnt4A98 *ent;
    int count;
    char pad18C[0x1A4 - 0x18C];
    void (*fn1A4)(int idx, int v);
    char pad1A8[0x1B4 - 0x1A8];
    void (*fn1B4)(int idx, unsigned char v);
} UpnpObj4A98;
typedef struct {
    int x0;
    union { signed char name1[16]; int idx4; unsigned char u4; };
    signed char name2[16];
    unsigned short port1;
    unsigned short port2;
    int peer;
    unsigned char b2C;
    unsigned char b2D;
    char pad2E[2];
    char x30[1];
} UpnpMsg4A98;
typedef struct {
    char ip[16];
    unsigned short port;
    int peer;
} UpnpAddr4A98;
typedef struct { char d[64]; } UpnpBuf4A98;

extern int func_00304578(UpnpObj4A98 *o, int *type, int *idx);
extern void *memset(void *d, int c, unsigned int n);
extern char *strncpy(char *d, const char *s, unsigned int n);
extern void func_002F9000(int a, int b, int c, int d);
extern void func_002F9460(int a, int b);
extern int func_002F7D68(int a);
extern void *func_002F7ED8(int a, int b);
extern int func_003079E0(int h, int a, int b);
extern void func_002F84A0(int a);
extern void func_002F84D0(int a, int b, void *c);
extern void func_002F9728(UpnpBuf4A98 *b);
extern int func_002F8C50(int a, int b, UpnpBuf4A98 *c);
extern int func_003055E8(UpnpObj4A98 *o, UpnpMsg4A98 *m, UpnpEnt4A98 *e);
extern int func_003076E0(int h, UpnpAddr4A98 *a, int *out);
extern int func_003083E8(int h, UpnpAddr4A98 *a, int *out);
extern void func_00305268(UpnpObj4A98 *o, int a, int b);

int func_00304A98(UpnpObj4A98 *o, int idx, UpnpMsg4A98 *m, int kind)
{
    UpnpAddr4A98 addr;
    UpnpBuf4A98 buf;
    int ret;

    if (kind == 0x70) {
        UpnpEnt4A98 *e;
        int type;
        int peer;
        int r;

        type = 0;
        peer = -2;
        if (m->peer < 0 || m->peer >= o->count)
            return 14;
        e = &o->ent[m->peer];
        if ((ret = func_00304578(o, &type, &peer)) != 0)
            return ret;
        if (!type || type == 5) {
            int pp = m->peer;
            if (m->b2C && pp) {
                UpnpEnt4A98 *e0 = o->ent;
                *e = *e0;
                memset(e0, 0, sizeof(UpnpEnt4A98));
                e0->f4 = -1;
                e0->f8 = -1;
                func_002F9000(-1, 0, -1, m->peer);
                func_002F9460(-1, 0);
                e->x24 = func_002F7ED8(func_002F7D68(-1), m->peer);
                func_003079E0(o->h180, e->f4, m->peer);
                func_003079E0(o->h180, e->f8, m->peer);
                return 0;
            }
            if (type == 0 && m->b2D) {
                func_002F84A0(-1);
                e->type = 5;
                return 0;
            }
            func_002F84D0(-1, pp, m->x30);
            e->x24 = func_002F7ED8(func_002F7D68(-1), m->peer);
            func_002F9728(&buf);
            func_002F8C50(-1, m->peer, &buf);
            if (func_003055E8(o, m, e) != 0)
                return 0;
            if (m->name1[0] && m->port1) {
                strncpy(addr.ip, (char *)m->name1, 16);
                addr.port = m->port1;
                addr.peer = m->peer;
                if (type == 0)
                    r = func_003076E0(o->h180, &addr, &e->f4);
                else
                    r = func_003083E8(o->h180, &addr, &e->f4);
                if (r != 21) {
                    if (r != 0)
                        return 7;
                    e->type = 2;
                }
            }
            if (!m->name2[0] || !m->port2)
                return 0;
            strncpy(addr.ip, (char *)m->name2, 16);
            addr.port = m->port2;
            addr.peer = m->peer;
            if (type == 0)
                r = func_003076E0(o->h180, &addr, &e->f8);
            else
                r = func_003083E8(o->h180, &addr, &e->f8);
        } else {
            if (type != 6)
                goto out0;
            func_002F84D0(-1, m->peer, m->x30);
            e->x24 = func_002F7ED8(func_002F7D68(-1), m->peer);
            func_002F9728(&buf);
            func_002F8C50(-1, m->peer, &buf);
            addr.peer = m->peer;
            if (func_003055E8(o, m, e) != 0)
                return 0;
            if (m->name1[0] && m->port1) {
                strncpy(addr.ip, (char *)m->name1, 16);
                addr.port = m->port1;
                r = func_003083E8(o->h180, &addr, &e->f4);
                if (r != 21) {
                    if (r != 0)
                        return 7;
                    e->type = 2;
                }
            }
            if (!m->name2[0] || !m->port2)
                return 0;
            strncpy(addr.ip, (char *)m->name2, 16);
            addr.port = m->port2;
            r = func_003083E8(o->h180, &addr, &e->f8);
        }
        if (r != 21) {
            if (r != 0)
                return 7;
            e->type = 2;
        }
        return 0;
    } else if (kind == 4) {
        int type;
        int peer;

        type = 0;
        peer = -2;
        if ((ret = func_00304578(o, &type, &peer)) != 0)
            return ret;
        if ((unsigned int)(type - 6) < 2) {
            o->fn1A4(idx, 0);
            return 0;
        }
        o->ent[idx].b11 = 1;
    } else if (kind == 8) {
        o->ent[idx].b10 = m->u4;
        o->fn1B4(idx, m->u4);
        return 0;
    } else if (kind == 12) {
        int k = m->idx4;
        if (o->ent[k].f4 != -1) {
            func_00305268(o, o->ent[k].f4, 16);
            return 0;
        }
        if (o->ent[k].f8 != -1)
            func_00305268(o, o->ent[k].f8, 16);
    }
out0:
    return 0;
}
