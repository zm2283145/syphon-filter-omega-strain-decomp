typedef struct { char pad[0xB8]; int fB8; } P;
typedef struct { int f0; void (*f4)(void); char f8[0x18]; } S;
extern short D_00497CC0;
extern int D_00497CC4;
int D_00497D34 = 0;
extern int D_00598564;
extern int Medius_TerminateString(void *, int);
extern int NetSetDefaultResolveAddrParams(S *);
extern void MediusGetNatServiceAddress(void *);
extern void MediusResolveAddrCallback(void);
extern int MediusSetProcessingState(int);
extern int MediusSetQueuedRequest(int, P *);
extern int NetResolveAddr(S *, int *);
extern int Net_SendLocked(int, int, int, int, int, int, P *);
int MediusCreateGameOnSelf(P *p, int b)
{
    S s;
    int x[4];
    Medius_TerminateString(p, 0x15);
    Medius_TerminateString((char *)p + 0x15, 0x11);
    Medius_TerminateString((char *)p + 0x40, 0x40);
    Medius_TerminateString((char *)p + 0x80, 0x20);
    if (D_00497CC0 != 1) return -0xF;
    if (D_00497CC4 < 0) return -0x10;
    D_00497D34 = b;
    if (p->fB8 == 2) {
        if (NetSetDefaultResolveAddrParams(&s)) return -2;
        MediusGetNatServiceAddress(s.f8);
        s.f4 = MediusResolveAddrCallback;
        MediusSetProcessingState(3);
        MediusSetQueuedRequest(0x12, p);
        if (NetResolveAddr(&s, x) == 0) return 0;
        MediusSetProcessingState(0);
        return -2;
    }
    if (Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598564, 0xEC, p)) return -5;
    return 0;
}

