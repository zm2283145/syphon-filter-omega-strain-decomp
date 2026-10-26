#define F(p,T,o) (*(T *)((char *)(p) + (o)))
typedef struct { int type; unsigned int slot; unsigned int id; int x0C; } MsgDB8E8;
typedef struct { char x0[6]; unsigned short base; unsigned short cnt; unsigned short first; unsigned short num; } RangeDB8E8;
extern unsigned int D_0048C450;
extern int D_0048C464;
extern int D_0048C47C;
extern signed char D_0058C178[];
extern void (*D_0058DF8C)(MsgDB8E8 *);
extern int NetGetClientInfo(unsigned int, unsigned int, void **);
extern int NetIGetSessionMasterClientIndex(int *, unsigned int);
extern int NetFindNextSessionMaster(unsigned int, unsigned int, int *);
extern int NetIGetClient(RangeDB8E8 **, unsigned int, unsigned int);
extern void NetIGetObject(void **, int);
extern void RemoteObjectUpdate(int, int, int);
extern int NetFreeRemoteObject(unsigned int);
extern void NetIGetDataStream(unsigned char **, int);
extern void DmeFree(unsigned char *);
extern void NetFreeClient(unsigned int, unsigned int);
void NetClientLeaves(unsigned int slot, unsigned int id)
{
    MsgDB8E8 msg;
    void *q;
    int cur;
    int x18;
    RangeDB8E8 *r;
    void *e;
    unsigned char *b;
    int i;
    x18 = 0x100;
    q = 0;
    if (slot >= 4) return;
    if (id >= 0x100) return;
    if (slot != D_0048C450) return;
    if (NetGetClientInfo(slot, id, &q) != 0) return;
    if (q == 0) return;
    F(q, int, 0x14) = 2;
    F(q, int, 0x18) = 0;
    F(q, int, 0x1C) = 0;
    NetIGetSessionMasterClientIndex(&cur, slot);
    x18 = cur;
    if (id == cur) {
        if (NetFindNextSessionMaster(slot, id, &x18) != 0) return;
        if (x18 == 0x100) return;
    }
    NetIGetClient(&r, slot, id);
    if (r == 0) return;
    if (D_0058DF8C) {
        msg.type = 1;
        msg.slot = slot;
        msg.id = id;
        msg.x0C = D_0048C47C;
        D_0058DF8C(&msg);
    }
    for (i = 0; i < D_0048C464; i++) {
        if (D_0058C178[i] == 2) {
            NetIGetObject(&e, i);
            if (e != 0) {
                if (F(e, unsigned int, 8) == id) {
                    if (F(e, unsigned char, 2) == 3 || F(e, unsigned char, 2) == 4) {
                        NetIGetSessionMasterClientIndex((int *)((char *)e + 8), slot);
                        if (F(e, unsigned int, 4) == id) {
                            F(e, int, 4) = -1;
                            RemoteObjectUpdate(F(e, int, 4), i, -2);
                        }
                    } else {
                        NetFreeRemoteObject(i);
                        D_0058C178[i] = 0;
                    }
                } else if (F(e, unsigned int, 4) == id) {
                    F(e, int, 4) = -1;
                    RemoteObjectUpdate(F(e, int, 4), i, -2);
                }
            }
        }
    }
    for (i = r->base; i < r->base + r->cnt; i++) {
        if (D_0058C178[i] == 1) D_0058C178[i] = 0;
    }
    if (r->first < 0x800) {
        for (i = 0; i < r->num; i++) {
            NetIGetDataStream(&b, i + r->first);
            if (b != 0) {
                if (b[0] == 2 && b[2] != 0) {
                    DmeFree(b + 0x10);
                }
                b[0] = 0;
            }
        }
    }
    NetFreeClient(slot, id);
}
