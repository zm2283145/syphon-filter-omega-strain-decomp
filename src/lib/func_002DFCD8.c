typedef struct {
    char pad0[0x400];
    int x400;
    char pad404[0x34];
    int x438;
    int pad43C;
    int x440;
    int x444;
    int pad448;
    int x44C;
} Ctx;

typedef struct {
    char name[0x10];
    unsigned short x10;
    short pad12;
    int x14;
    int x18;
    int x1C;
    char pad20[8];
    char x28;
} Ent;

typedef struct {
    int port;
    int state;
    int arg;
    int err;
    int user;
} Info;

extern unsigned int RtMsgToDmeConnectionIndex(unsigned short);
extern int NetGetConnInfo(unsigned int port, Ctx **ctx);
extern int NetIsValidClientIndex(int slot);
extern int NetCreateClientInfo(unsigned int port, int slot, Ent **ent);
extern int NetStreamMediaIsEnabledOnConnection(unsigned int port);
extern int NetStreamMediaSetClientIndex(unsigned int port, int slot);
extern void NetStreamMediaDisableOnConnection(unsigned int port);
extern int MapMsgClientFailureReason(int *out, unsigned int v);
extern int Libc_Strncmp(const char *, const char *, int);
extern void rt_msg_client_get_connection_ip(unsigned short, char *);
extern char *strncpy(char *, const char *, unsigned int);
extern void NetISetMyClientReceiveBroadcast(unsigned int, int);
extern void *memset(void *, int, unsigned int);
extern void (*D_0048C468)(Info *);
extern int D_0048C46C;
extern char D_00588074[];
extern unsigned short D_0058C0B0;

void MsgClientConnectCallback(unsigned short a0, unsigned char flag, unsigned short slot, unsigned short n, int arg)
{
    Info info;
    Ctx *ctx = 0;
    Ent *ent = 0;
    int result = 0;
    unsigned int port;
    int one;
    int err;
    int valid;

    port = RtMsgToDmeConnectionIndex(a0);
    if (port >= 4) return;
    one = NetIsValidClientIndex(slot);
    if (one != 1) return;
    if (NetGetConnInfo(port, &ctx) != 0) return;
    if (ctx == 0) return;
    if (NetCreateClientInfo(port, slot, &ent) != 0) return;
    if (ent == 0) return;
    if (flag == one) {
        valid = (int)port < 4;
        if (valid && slot < ctx->x444) {
            if (NetStreamMediaIsEnabledOnConnection(port) == one) {
                if (NetStreamMediaSetClientIndex(port, slot) != 0) return;
            }
            if (ctx == 0) return;
            ctx->x438 = one;
            ctx->x440 = n - 1;
            result = 0;
            err = 0;
            ctx->x400 = slot;
            ent->x14 = 2;
            ent->x18 = 0;
            ent->x1C = 0;
            if (Libc_Strncmp(D_00588074, D_00588074 + 0x18, 0x10) == 0) {
                rt_msg_client_get_connection_ip(a0, D_00588074);
            }
            strncpy(ent->name, D_00588074, 0x10);
            ent->x10 = D_0058C0B0;
            ent->x28 = one;
            if (ctx->x44C == 4) {
                NetISetMyClientReceiveBroadcast(port, 1);
            }
        } else {
            if (NetStreamMediaIsEnabledOnConnection(port) == 1) {
                NetStreamMediaDisableOnConnection(port);
            }
            if (valid && ctx) {
                ctx->x438 = 3;
                ctx->x400 = 0x100;
            }
            result = 1;
            err = slot >= ctx->x444 ? 0x1C : 3;
        }
    } else {
        if (NetStreamMediaIsEnabledOnConnection(port) == one) {
            NetStreamMediaDisableOnConnection(port);
        }
        if ((int)port < 4 && ctx) ctx->x438 = 3;
        err = 3;
        if (MapMsgClientFailureReason(&result, arg) != 0) result = 1;
    }
    if (D_0048C468 != 0) {
        memset(&info, 0, sizeof(info));
        info.port = port;
        if ((int)port < 4 && ctx) info.state = ctx->x438; else info.state = 3;
        info.arg = result;
        info.err = err;
        info.user = D_0048C46C;
        D_0048C468(&info);
        D_0048C468 = 0;
        D_0048C46C = 0;
    }
}

