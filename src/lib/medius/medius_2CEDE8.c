typedef struct { char d[0x30]; } B30_EDE8;
typedef struct { char d[0x40]; } B40_EDE8;
typedef struct {
    char pad0[0x18];
    int f18;
    B30_EDE8 a;
    char pad4c[4];
    B40_EDE8 b;
} Src_EDE8;
typedef struct {
    int f0;
    B30_EDE8 a;
    B40_EDE8 b;
    char pad74[0xC];
} Req_EDE8;
extern int (*D_0048C3EC)(int, int, int, Src_EDE8 *);
extern void NetSetDefaultIncomingClientParams(Req_EDE8 *);
extern void NetIncomingClient(Req_EDE8 *, int *);
int GlobalMediusTypeServerJoinGameCallback(int a0, int a1, int a2, Src_EDE8 *s)
{
    Req_EDE8 req;
    int out[4];
    int r = 0;
    if (D_0048C3EC != 0) r = D_0048C3EC(a0, a1, a2, s);
    if (r == 0 && s->f18 == 2) {
        NetSetDefaultIncomingClientParams(&req);
        req.a = s->a;
        req.b = s->b;
        NetIncomingClient(&req, out);
    }
    return 0xB4;
}

