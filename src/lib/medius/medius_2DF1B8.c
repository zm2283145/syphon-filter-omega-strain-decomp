extern int RtMsgToDmeConnectionIndex(int);
extern int NetGetConnInfo(unsigned int, int **);
extern int RemoteClientConnects(unsigned int, unsigned short, int, unsigned short);
extern int RemoteClientDisconnectEvent(unsigned int, unsigned short);
extern unsigned short D_0058C0B0;
extern unsigned short D_0058D178;

typedef struct {
    char pad[0x440];
    int cnt;
} S_002DF1B8;

void RemoteClientEvent(unsigned short a0, unsigned short a1, int a2, unsigned char a3)
{
    S_002DF1B8 *p = 0;
    unsigned int idx = RtMsgToDmeConnectionIndex(a0);
    if (idx < 4 && a2 != 0 && NetGetConnInfo(idx, (int **)&p) == 0 && p != 0) {
        if (a3) {
            unsigned short v;
            p->cnt++;
            if (D_0058D178 == 0)
                v = D_0058C0B0;
            else
                v = D_0058D178;
            RemoteClientConnects(idx, a1, a2, v);
        } else {
            RemoteClientDisconnectEvent(idx, a1);
        }
    }
}
