#define F(p,T,o) (*(T *)((char *)(p) + (o)))
typedef struct { unsigned char b0, b1, b2, b3; int f4; int f8; int fC; } M2DCA70;
extern int D_00598420;
extern int NetGetConnInfo(unsigned int, void **);
extern int NetGetClientInfo(unsigned int, unsigned int, void **);
extern unsigned char NetClientIndexToClientIndexPacket(unsigned int);
extern int NetGetMyPersistantObjectCount(int *);
extern void NetSendDmeMessage(int, unsigned int, int, int, int, M2DCA70 *);
void SendMyClientStatus(unsigned int slot, int who)
{
    M2DCA70 m;
    void *p = 0;
    void *q = 0;
    unsigned int id, i;
    if (slot >= 4) return;
    if (NetGetConnInfo(slot, &p) != 0) return;
    if (p == 0) return;
    id = F(p, unsigned int, 0x400);
    if (id >= 0x100) return;
    if (NetGetClientInfo(slot, id, &q) != 0) return;
    if (q == 0) return;
    m.b1 = NetClientIndexToClientIndexPacket(id);
    m.b0 = F(q, unsigned char, 0x14);
    m.b2 = F(q, unsigned char, 0x18);
    m.b3 = F(q, unsigned char, 0x1C);
    m.f8 = F(q, int, 0x24);
    m.fC = F(p, int, 0x448);
    if (NetGetMyPersistantObjectCount(&m.f4) != 0) return;
    if (who == -1) {
        for (i = 0; i < 0x100; i++) {
            if (NetGetClientInfo(slot, i, &q) != 0) return;
            if (q == 0) continue;
            if (F(q, unsigned char, 0x28) != 1) continue;
            if (i == id) continue;
            NetSendDmeMessage(0x50, slot, i, D_00598420, 0x10, &m);
        }
        return;
    }
    NetSendDmeMessage(0x50, slot, who, D_00598420, 0x10, &m);
}