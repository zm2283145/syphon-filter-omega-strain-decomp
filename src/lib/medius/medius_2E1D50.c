typedef struct { int a; unsigned short id; short p; int type; void (*cb)(); int time; int x; int y; } E;
typedef struct { int f0; unsigned char slot; unsigned char f5; char pad[2]; } M;
extern E D_0058D188[];
extern int D_0048C450;
extern int D_0058806C;
extern int D_005983DC;
extern int NetSendMessage(int, int, int, int, int, int, void *);
extern int FindFreePingSlot(void);
extern int NetGetClientInfo(unsigned int, unsigned int, void **);
extern int NetIGetLocalTime(int *);
extern void NetIIpStringToBinary(void *, void *);
extern void TimeBasePingCallback();

void SendTimebaseCorrection(unsigned int id)
{
    M m;
    void *p = 0;
    char s;

    if (id >= 0x100) return;
    m.f5 = 1;
    m.slot = FindFreePingSlot();
    if ((char)m.slot == 0x7F) return;
    m.f0 = D_0058806C;
    NetSendMessage(-0x80, D_0048C450, id, 0, D_005983DC, 8, &m);
    if (NetGetClientInfo(D_0048C450, id, &p) != 0) return;
    if (p == 0) return;
    NetIGetLocalTime(&D_0058D188[m.slot].time);
    NetIIpStringToBinary(&D_0058D188[m.slot], p);
    D_0058D188[m.slot].id = *(unsigned short *)((char *)p + 0x10);
    D_0058D188[m.slot].cb = TimeBasePingCallback;
    D_0058D188[m.slot].type = 1;
    D_0058D188[m.slot].x = D_0048C450;
    D_0058D188[m.slot].y = id;
}


