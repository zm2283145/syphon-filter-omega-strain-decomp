typedef struct { int sock; int x4; char pad[0x1C]; unsigned short port; char pad2[0x32]; void *ctx; } UpnpDE00;
extern int Net_AllocZeroed(void *pp, unsigned long size);
extern void func_002FB3C0(void *pp);
extern int func_002F63E8(int *p);
int func_0030DE00(UpnpDE00 **out, int sock, unsigned short port)
{
    UpnpDE00 *u = 0;
    if (out == 0) return 2;
    *out = 0;
    if (sock == 0) return 2;
    if (Net_AllocZeroed(&u, 0x64) != 0) return 3;
    if (Net_AllocZeroed(&u->ctx, 0x2E70) != 0) {
        func_002FB3C0(&u);
        return 3;
    }
    if (func_002F63E8(&u->x4) != 0) {
        func_002FB3C0(&u->ctx);
        func_002FB3C0(&u);
        return 5;
    }
    u->port = port;
    u->sock = sock;
    *out = u;
    return 0;
}
