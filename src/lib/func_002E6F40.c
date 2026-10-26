typedef struct { int code; int val; } Msg;
typedef struct { int x0; unsigned short x4; unsigned short x6; } Arg;
extern unsigned char D_0048C454[];
extern int D_0048C478[];
extern int D_0058DF90;
extern void (*D_0058DF88)(Msg *);
extern int D_0058806C;
extern int NetGetConnInfo(unsigned int, char **);
extern void NetIGetClient(char **, unsigned int, unsigned int);
extern int NetILeave(unsigned int);
extern int NetGetClientInfo(unsigned int, unsigned int, char **);
extern void SendMyClientStatus(unsigned int, int);
extern void NetSetSessionMasterClientIndex(unsigned int, unsigned int);
extern void NetResetTime(int);
extern int NetISendMyClientUpdate(unsigned int, int);
extern int MyClientJoins(unsigned int, unsigned int);
extern void NetISetMyClientReceiveBroadcast(unsigned int, int);

int AcceptClientPacketHandler(unsigned int a, int b, unsigned int c, Arg *d)
{
    char *q = 0;
    char *p = 0;
    char *r = 0;
    unsigned int n;
    Msg m;

    if (d == 0) return -1;
    if (a >= 4) return -1;
    if (c >= 0x100) return -1;
    if (D_0048C454[0] == 1) return 8;
    if (NetGetConnInfo(a, &p)) return -1;
    if (p == 0) return -1;
    n = *(unsigned int *)(p + 0x400);
    if (n >= 0x100) return -1;
    NetIGetClient(&q, a, n);
    if (q == 0) return -1;
    if (D_0058DF90 == 1) {
        NetILeave(a);
        if (D_0058DF88) {
            m.code = 7;
            m.val = D_0048C478[0];
            D_0058DF88(&m);
            D_0058DF88 = 0;
            D_0048C478[0] = 0;
        }
        return 8;
    }
    if (NetGetClientInfo(a, n, &r) || r == 0) return -1;
    *(int *)(r + 0x14) = 4;
    SendMyClientStatus(a, -1);
    NetSetSessionMasterClientIndex(a, c);
    D_0048C454[0] = 1;
    NetResetTime(d->x0);
    *(int *)q = D_0058806C;
    *(unsigned short *)(q + 6) = d->x4;
    *(unsigned short *)(q + 0xA) = d->x6;
    NetISendMyClientUpdate(a, -1);
    MyClientJoins(a, n);
    NetISetMyClientReceiveBroadcast(a, 1);
    return 8;
}