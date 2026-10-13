typedef struct { int f0; int f4; int f8; int state; char pad[0x2023]; unsigned char wide; unsigned char retried; } UpCtxD8B0;
typedef struct {
    char pad[0x26];
    unsigned short port26;
    char host[0x10];
    unsigned short port38;
    char pad2[0x1E];
    UpCtxD8B0 *ctx;
} UpnpD8B0;

extern char *strncpy(char *, const char *, unsigned int);
extern int func_0030E148(UpnpD8B0 *u, void *cb);
extern int func_0030E330(UpnpD8B0 *u, int arg, void *cb);
extern int UPnP_GetStatusInfo(UpnpD8B0 *u, int arg, void *cb);
extern int UPnP_GetExternalIPAddress(UpnpD8B0 *u, int arg, void *cb);
extern int UPnP_GetPortMappingNumberOfEntries(UpnpD8B0 *u, int arg, void *cb);
extern int UPnP_AddPortMapping(UpnpD8B0 *u, int arg, unsigned short port, void *cb);
extern int func_0030EA40(UpnpD8B0 *u, char *host, unsigned short port, void *cb);
extern void func_0030DB68();
extern void func_0030DBD8();
extern void func_0030DC30();
extern void func_0030DC98();
extern void func_0030DCF0();
extern void func_0030DD48();
extern void func_0030DDA0();

int func_0030D8B0(UpnpD8B0 *u)
{
    int r = 0;
    char host[16];
    unsigned short port;

    switch (u->ctx->state) {
    case 0: case 1: break;
    case 2:
        r = func_0030E148(u, func_0030DB68);
        if (r == 0) u->ctx->state = 1; else u->ctx->state = 8;
        break;
    case 3:
        if (!u->ctx->wide) r = func_0030E330(u, 0x1000, func_0030DBD8); else r = func_0030E330(u, 0x800, func_0030DBD8);
        if (r == 0) u->ctx->state = 1; else u->ctx->state = 8;
        break;
    case 4:
        if (!u->ctx->wide) r = UPnP_GetStatusInfo(u, 0x1000, func_0030DC30); else r = UPnP_GetStatusInfo(u, 0x800, func_0030DC30);
        if (r == 0) u->ctx->state = 1; else u->ctx->state = 8;
        break;
    case 5:
        if (!u->ctx->wide) r = UPnP_GetExternalIPAddress(u, 0x1000, func_0030DC98); else r = UPnP_GetExternalIPAddress(u, 0x800, func_0030DC98);
        if (r == 0) u->ctx->state = 1; else u->ctx->state = 8;
        break;
    case 6:
        if (!u->ctx->wide) r = UPnP_GetPortMappingNumberOfEntries(u, 0x1000, func_0030DCF0); else r = UPnP_GetPortMappingNumberOfEntries(u, 0x800, func_0030DCF0);
        if (r == 0) u->ctx->state = 1; else u->ctx->state = 8;
        break;
    case 7:
        if (!u->ctx->wide) r = UPnP_AddPortMapping(u, 0x1000, u->port26, func_0030DD48); else r = UPnP_AddPortMapping(u, 0x800, u->port26, func_0030DD48);
        if (r == 0) u->ctx->state = 1;
        else {
            UpCtxD8B0 *c = u->ctx;
            if (c->retried == 0) {
                c->state = 6; c->retried = 1;
            } else {
                c->state = 8;
            }
        }
        break;
    case 8:
        port = u->port38;
        strncpy(host, u->host, 16);
        r = func_0030EA40(u, host, port, func_0030DDA0);
        if (r == 0) u->ctx->state = 1;
        else if (u->ctx != 0) u->ctx->state = 0;
        break;
    }
    return r;
}


