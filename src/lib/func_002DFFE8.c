typedef struct {
    int idx;
    int f4;
    int f8;
    int fC;
    int f10;
} DisconnectMsg;

typedef struct {
    char pad[0x438];
    int f438;
} ConnInfo;

extern void (*D_0048C470)(DisconnectMsg *);
extern int D_0048C474;
extern unsigned int RtMsgToDmeConnectionIndex(unsigned short);
extern int NetGetConnInfo(unsigned int, ConnInfo **);
extern void *memset(void *, int, unsigned int);

void MsgClientDisconnectCallback(unsigned short h)
{
    DisconnectMsg m;
    ConnInfo *info;
    unsigned int idx;
    int f438, cb, one;

    info = 0;
    one = 1;
    idx = RtMsgToDmeConnectionIndex(h);
    if (idx >= 4) return;
    if (NetGetConnInfo(idx, &info)) return;
    if (info == 0) return;
    if (D_0048C470 == 0) return;
    memset(&m, 0, sizeof(m));
    f438 = info->f438;
    cb = D_0048C474;
    m.idx = idx;
    m.f4 = f438;
    m.f8 = one;
    m.fC = 0;
    m.f10 = cb;
    D_0048C470(&m);
}