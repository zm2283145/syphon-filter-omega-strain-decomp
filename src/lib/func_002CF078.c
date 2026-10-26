typedef struct { char pad[0x1C]; int f1C; char f20[0x10]; int f30; int f34; } Msg_F078;
typedef struct { int f0; void* f4; char f8[0x18]; } Ctx_F078;
extern short D_0048C414;
extern int D_0048C3D8;
extern int D_0048C3DC;
extern int D_0048C384;
extern int iTerminateString_void(void *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
int __attribute__((weak, section(".dtors_drop"))) MGCLGetServerType(void) { return 0; }
extern int MGCLGetServerPort(void);
extern int NetSetDefaultResolveAddrParams(void *);
extern void MGCLGetNATServiceAddress(void *);
extern void MGCLResolveAddrCallback(void);
extern void MGCLSetProcessingState(int);
extern void MGCLSetQueuedRequest(int, void *);
extern int NetResolveAddr(void *, void *);
extern void NetGetMyIpAddress(void *);
int MGCLAuthenticationSend(Msg_F078 *a, int b)
{
    Ctx_F078 s;
    char t[0x10];
    iTerminateString_void(a, 0x15);
    if (D_0048C414 != 1) return -0xC;
    D_0048C3DC = b;
    if (MGCLGetServerType() == 1 || MGCLGetServerType() == 2) {
        if (NetSetDefaultResolveAddrParams(&s)) return -5;
        MGCLGetNATServiceAddress(s.f8);
        s.f4 = MGCLResolveAddrCallback;
        MGCLSetProcessingState(4);
        MGCLSetQueuedRequest(0, a);
        if (NetResolveAddr(&s, t) == 0) return 0;
        MGCLSetProcessingState(0);
        return -5;
    }
    if (MGCLGetServerType() != 0 && MGCLGetServerType() != 4) return -0xD;
    a->f1C = 1;
    NetGetMyIpAddress(a->f20);
    a->f30 = MGCLGetServerPort();
    a->f34 = 0;
    return Net_SendLocked(0x40, D_0048C3D8, 0xFFFF, 3, D_0048C384, 0x4C, a) ? -5 : 0;
}

