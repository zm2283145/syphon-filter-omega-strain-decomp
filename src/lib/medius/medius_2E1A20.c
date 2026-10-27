/*
 * lib/medius: 2 files, 002E1A20-002E1BA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002E1A20 */
typedef struct { char pad[0x400]; int self; } S;
typedef struct { char pad[0x14]; int f14; int f18; int f1C; } P;
extern unsigned int D_00598418;
extern int D_0048C450;
extern char D_0048C454;
extern char D_0048C440;
extern int D_0058DF88;
extern int D_0048C478;
extern int D_0058DF8C;
extern int D_0048C47C;
extern int D_0048C488;
extern int D_0048C48C;
extern int D_0048C464;
extern int NetGetConnInfo(unsigned int, S **);
extern int NetISetMyClientReceiveBroadcast(unsigned int, int);
extern unsigned char NetClientIndexToClientIndexPacket(unsigned int);
extern int NetISendMessage(char, int, int, unsigned int, unsigned int, int, void *);
extern int NetFreeAllDataStreams(void);
extern int NetIFreeAllObjects(void);
extern void NetFreeClients(unsigned int);
extern int NetGetClientInfo(unsigned int, unsigned int, P **);
extern void SendMyClientStatus(unsigned int, int);
extern int NetSetSessionMasterClientIndex(unsigned int, int);

int NetILeave(unsigned int id)
{
    S *s;
    unsigned char b[1];
    P *p;
    int ret;
    int i;

    s = 0;
    p = 0;
    if (id >= 4) return 0x17;
    ret = NetGetConnInfo(id, &s);
    if (ret != 0) return ret;
    if (s == 0) return ret;
    NetISetMyClientReceiveBroadcast(id, 0);
    b[0] = NetClientIndexToClientIndexPacket(s->self);
    NetISendMessage(0x50, id, -1, 0, D_00598418, 1, b);
    NetFreeAllDataStreams();
    NetIFreeAllObjects();
    NetFreeClients(id);
    D_0048C450 = 4;
    D_0048C454 = 0;
    D_0048C440 = 0;
    ret = NetGetClientInfo(id, s->self, &p);
    if (ret != 0) return ret;
    if (p == 0) return ret;
    p->f14 = 2;
    p->f18 = 0;
    p->f1C = 0;
    SendMyClientStatus(id, -1);
    for (i = 0; i < 4; i++) {
        if (NetGetConnInfo(i, &s) == 0 && s != 0) NetSetSessionMasterClientIndex(i, 0x100);
    }
    D_0048C464 = 0;
    D_0058DF88 = 0;
    D_0048C478 = 0;
    D_0058DF8C = 0;
    D_0048C47C = 0;
    D_0048C488 = 0;
    D_0048C48C = 0;
    return 0;
}
/* merge_units: end func_002E1A20 */

/* merge_units: begin func_002E1BA0 */
typedef struct { int a, b, c; int used; char pad[0xC]; } SE1BA0;
extern SE1BA0 D_0058D188[];
int FindFreePingSlot(void)
{
    int i;
    for (i = 0; i < 0x7F; i++)
        if (D_0058D188[i].used == 0) return i;
    return 0x7F;
}
/* merge_units: end func_002E1BA0 */
