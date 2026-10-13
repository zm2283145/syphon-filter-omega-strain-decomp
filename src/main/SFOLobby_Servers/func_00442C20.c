#include "SFOLobby.h"

typedef struct {
    int type;
    int id;
    char data[0x38];
} NetCfg442C20;

extern char D_00583A00[];
extern char D_004C05D0[]; /* "SFOLobby_Servers.cc" */
void* memset(void*, int, unsigned int);
char* strncpy(char*, const char*, unsigned int);
int sceLibnetInitialize(void*, int, int, int);
int func_0034B868(void*, void*);
int func_0034AA50(void*, void*, int, void*, char*, int, int);
int func_0034AB38(void*, void*, char*, int, void*);
void SFOLobby_SetError(SFOLobby*, int, char*, int);
void func_0034B7E8(void*);

/* Resolves `hostName` with sceLibnet (DNS lookup) and stores the address
 * string (max 31 chars) in `out`. */
int SFOLobby_ResolveHost(SFOLobby* self, char* hostName, char* out) {
    NetCfg442C20 cfg;
    char buf[0x5C0];

    memset(&cfg, 0, sizeof(cfg));
    cfg.type = 1;
    cfg.id = -1;
    if (sceLibnetInitialize(self->libnetCtx, 0x800, 0x2000, 0x20) != 0) {
        return 0;
    }
    if (func_0034B868(self->libnetCtx, D_00583A00) < 0) {
        return 0;
    }
    if (func_0034AA50(self->libnetCtx, D_00583A00, 0, cfg.data, hostName, 0, 0) < 0) {
        SFOLobby_SetError(self, 0x2D, D_004C05D0, 0xB3);
        func_0034B7E8(self->libnetCtx);
        return 0;
    }
    if (func_0034AB38(self->libnetCtx, D_00583A00, buf, 0x80, cfg.data) < 0) {
        SFOLobby_SetError(self, 0x2D, D_004C05D0, 0xC0);
        func_0034B7E8(self->libnetCtx);
        return 0;
    }
    strncpy(out, buf, 0x1F);
    out[0x1F] = 0;
    func_0034B7E8(self->libnetCtx);
    return 1;
}
