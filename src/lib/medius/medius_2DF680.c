/*
 * lib/medius: 7 files, 002DF680-002DFAE8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002DF680 */
extern unsigned int strlen(const char *);
extern unsigned char D_0048C4AC;
extern char D_0058DF80[];
extern int D_0058D17C;
extern int NetIEnableUDP(void);
extern int NetIIpStringToBinary(char *, char *);
int NetIAssignLocalServer(char *name, int b)
{
    int r;
    if (name == 0) return 0x17;
    if (strlen(name) == 0) return 0x17;
    if (b == 0) return 0x17;
    if (D_0048C4AC == 0) {
        r = NetIEnableUDP();
        if (r) return r;
    }
    NetIIpStringToBinary(D_0058DF80, name);
    D_0058D17C = b;
    return 0;
}
/* merge_units: end func_002DF680 */

/* merge_units: begin func_002DF708 */
typedef struct {
    unsigned short port; short pad;
    int a; int b; int c; int d; int e; int f;
    void *g;
    void *f0; void *f1; void *f2; void *f3; void *f4; void *f5;
} Cfg;
extern unsigned char D_0048C4B5;
extern unsigned short D_0058C0B0;
extern int D_0048C49C;
extern int D_0048C4A0;
extern int D_0048C460;
extern int D_0048C4B0;
extern char D_00522760[];
extern void p2p_disconnect_cb(void);
extern void p2p_host_change_cb(void);
extern void p2p_peer_update_cb(void);
extern void p2p_incoming_data_cb(void);
extern void p2p_unconnected_data_cb(void);
extern void p2p_broadcast_update_cb(void);
extern int rt_p2p_create(Cfg *, int *);
extern int rt_p2p_destroy(int);
int NetIEnableUDP(void)
{
    Cfg c;
    if (D_0048C4AC == 0) {
    c.port = D_0058C0B0;
    c.a = 8;
    c.b = 0x200;
    c.c = D_0048C49C;
    c.d = D_0048C4A0;
    c.e = 0x1E;
    c.f = D_0048C460;
    c.f0 = p2p_disconnect_cb;
    c.f1 = p2p_host_change_cb;
    c.f2 = p2p_peer_update_cb;
    c.f3 = p2p_incoming_data_cb;
    c.f4 = p2p_unconnected_data_cb;
    c.f5 = p2p_broadcast_update_cb;
    if (D_0048C4B5) c.g = D_00522760; else c.g = 0;
    if (rt_p2p_create(&c, &D_0048C4B0)) {
        rt_p2p_destroy(D_0048C4B0);
        D_0048C4B0 = 0;
        return 0x25;
    }
    D_0048C4AC = 1;
    }
    return 0;
}
/* merge_units: end func_002DF708 */

/* merge_units: begin func_002DF828 */
extern int D_0058DF84;
extern int D_0058D180;
extern int D_0059841C;
extern int rt_msg_client_get_broadcast_ip(char *);
extern int NetMapMsgClientError(int, int);
extern int Libc_Strncmp(char *, char *, int);
extern int NetISendMessageByUDPToIP(int, char *, int, int, int, int *);
int NetIRequestServersOnSubnet(int a)
{
    char buf[16];
    char buf2[16];
    int x;
    int r;
    if (D_0048C4AC == 0) {
        r = NetIEnableUDP();
        if (r) return r;
    }
    r = NetMapMsgClientError(rt_msg_client_get_broadcast_ip(buf), 0x18);
    if (r) return r;
    D_0058DF84 = a;
    x = D_0058D180;
    if (Libc_Strncmp(buf, "0.0.0.0", 0x10) == 0) return 0x23;
    NetIIpStringToBinary(buf2, buf);
    return NetISendMessageByUDPToIP(0, buf2, 0, D_0059841C, 4, &x);
}
/* merge_units: end func_002DF828 */

/* merge_units: begin func_002DF8E8 */
extern signed char D_0058C178[];
extern void NetFreeRemoteObject(int);
int NetIFreeAllObjects(void)
{
    int i;
    for (i = 0; i < 0x1000; i++) {
        if (D_0058C178[i] == 2) NetFreeRemoteObject(i);
        D_0058C178[i] = 0;
    }
    return 0;
}
/* merge_units: end func_002DF8E8 */

/* merge_units: begin func_002DF958 */
extern unsigned short D_0058D178;
extern char D_005880A0[];
extern unsigned int RtMsgToDmeConnectionIndex(unsigned short);
extern int NetGetMyWorldID(void);
extern void ParseMessageList(int, int, int, int, unsigned short);
void IncomingMessageFunc(unsigned short a, unsigned short b, int c, unsigned short d)
{
    unsigned int h = RtMsgToDmeConnectionIndex(a);
    if (h >= 4) return;
    if (c == 0) return;
    if (d == 0) return;
    D_005880A0[0] = 0;
    D_0058D178 = 0;
    ParseMessageList(NetGetMyWorldID(), h, b, c, d);
}
/* merge_units: end func_002DF958 */

/* merge_units: begin func_002DFA08 */
int MapMsgClientFailureReason(int* out, unsigned int v)
{
    if (out == 0)
        return 0x17;
    switch (v) {
    case 0: *out = 0; break;
    case 2: *out = 2; break;
    case 3: *out = 3; break;
    case 4: *out = 4; break;
    case 5: *out = 5; break;
    case 6: *out = 6; break;
    case 7: *out = 7; break;
    case 8: *out = 8; break;
    case 9: *out = 9; break;
    case 1: *out = 1; break;
    default: return 0x17;
    }
    return 0;
}
/* merge_units: end func_002DFA08 */

/* merge_units: begin func_002DFAE8 */
typedef struct {
    char pad0[0x400];
    int x400;
    char pad404[0x34];
    int x438;
    int pad43C;
    int x440;
} Ctx2DFAE8;

typedef struct {
    char pad0[0x14];
    int x14;
    int x18;
    int x1C;
    char pad20[8];
    char x28;
} Ent2DFAE8;

typedef struct {
    int port;
    int state;
    int arg;
    int err;
    int user;
} Info2DFAE8;

extern int NetGetConnInfo(unsigned int port, Ctx2DFAE8** ctx);
extern int NetIsValidClientIndex(int slot);
extern int NetCreateClientInfo(unsigned int port, int slot, Ent2DFAE8** ent);
extern void KM_SetLocalClientID(int a, int b, int c, int d);
extern int NetStreamMediaIsEnabledOnConnection(unsigned int port);
extern int NetStreamMediaSetClientIndex(unsigned int port, int slot, Ent2DFAE8* ent);
extern void NetStreamMediaDisableOnConnection(unsigned int port);
extern int rt_p2p_get_my_address(int h, int a, Ent2DFAE8* ent, void* p);
extern void* memset(void* d, int c, unsigned int n);
extern void (*D_0048C468)(Info2DFAE8* info);
extern int D_0048C46C;

void MyClientConnectsPeerToPeer(unsigned int port, int slot, unsigned char flag, unsigned short n, int arg)
{
    Info2DFAE8 info;
    Ctx2DFAE8* ctx = 0;
    Ent2DFAE8* ent = 0;
    int err;

    if (port >= 4) return;
    if (NetGetConnInfo(port, &ctx) != 0) return;
    if (ctx == 0) return;
    if (ctx->x438 == 1) return;
    if (flag) {
        register int m asm("$6");
        register int k asm("$7");
        if (NetIsValidClientIndex(slot) != 1) return;
        err = NetCreateClientInfo(port, slot, &ent);
        if (err != 0) return;
        if (ent == 0) return;
        m = n - 1;
        k = 2;
        ctx->x438 = 1;
        ctx->x400 = slot;
        ctx->x440 = m;
        ent->x14 = k;
        ent->x18 = 0;
        ent->x1C = 0;
        ent->x28 = 1;
        KM_SetLocalClientID(-1, slot, m, k);
        if (NetStreamMediaIsEnabledOnConnection(port) == 1) {
            err = NetStreamMediaSetClientIndex(port, slot, ent);
            if (err != 0) return;
        }
        if (rt_p2p_get_my_address(D_0048C4B0, 1, ent, (char*)ent + 0x10) != 0) return;
    } else {
        err = 3;
        ctx->x400 = 0x100;
        ctx->x438 = 3;
        if (NetStreamMediaIsEnabledOnConnection(port) == 1) {
            NetStreamMediaDisableOnConnection(port);
        }
    }
    if (D_0048C468 != 0) {
        memset(&info, 0, sizeof(info));
        info.state = ctx->x438;
        info.port = port;
        info.arg = arg;
        info.err = err;
        info.user = D_0048C46C;
        D_0048C468(&info);
        D_0048C468 = 0;
        D_0048C46C = 0;
    }
}
/* merge_units: end func_002DFAE8 */
