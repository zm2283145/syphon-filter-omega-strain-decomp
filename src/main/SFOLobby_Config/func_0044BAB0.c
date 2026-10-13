#include "SFOLobby.h"

typedef struct { int w[0x1340 / 4]; } __attribute__((aligned(16))) NetCfg_44BAB0;
/* netConfigList entry (0x13C0 bytes, see SFOLobby_ListNetConfigs) */
typedef struct {
    char hdr[0x80];
    NetCfg_44BAB0 cfg;
} NetProfile_44BAB0;

extern NetCfg_44BAB0 D_005849C0;
extern int D_00585CCC;
extern char D_004C0D70[]; /* "SFOLobby_Config.cc" */
extern char D_004C0E40[]; /* "Dummy universe name" */
extern char D_004C0E60[]; /* "Dummy description" */
extern void String_Copy(char* d, const char* s);
extern void func_0010D3E0(int);
extern int func_003A6700(int);
extern int SFOLobby_ResolveHost(SFOLobby*, char*, char*);
extern int SFOLobby_DnasAuth(SFOLobby*);
extern int SFOLobby_ConnectDir(SFOLobby*);
extern int func_0044CD20(SFOLobby*);
extern NetProfile_44BAB0* LobbyArray_At(LobbyArray*, int);
extern void LobbyArray_Append(LobbyArray*, LobbyUniverseEntry*);
extern void SFOLobby_SetError(SFOLobby*, int, char*, int);
extern void func_00452C70(SFOLobby*, int);
extern int func_00452CD0(SFOLobby*);
extern void SFOLobby_CallUpdateHook(SFOLobby*, int, int);
extern void* memset(void*, int, unsigned int);
int SFOLobby_NetUp(SFOLobby*, NetCfg_44BAB0*);
void SFOLobby_NetDown(SFOLobby*);

/* hand-written quad copy loop (retail uses addi) */
static inline void QuadCopy_44BAB0(void* d0, const void* s0, int n0) {
    int n = n0;
    __int128 t;
    const void* src = s0;
    void* dst = d0;
    asm {
        .set noreorder
    loop:
        lq t, 0(src)
        addiu dst, dst, 0x10
        addi n, n, -1
        addiu src, src, 0x10
        bgtz n, loop
        sq t, -0x10(dst)
        .set reorder
    }
}

/* Brings the network up with network configuration `id` (netConfigList index),
 * optionally runs DNAS (useDnas), then either resolves the auth server directly
 * (directAuth: one dummy universe entry) or resolves and queries the directory
 * server for the universe list. */
int SFOLobby_StartNetwork(SFOLobby* self, int id, unsigned char useDnas) {
    NetProfile_44BAB0* prof;
    LobbyUniverseEntry ent;

    SFOLobby_CallUpdateHook(self, 2, 1);
    self->useDnas = useDnas;
    self->passwordLen = 0;
    prof = LobbyArray_At(self->netConfigList, id);
    if (prof == 0) {
        SFOLobby_SetError(self, 0x34, D_004C0D70, 0x1B8);
        return 0;
    }
    func_0010D3E0(0);
    QuadCopy_44BAB0(&D_005849C0, &prof->cfg, sizeof(NetCfg_44BAB0) / 16);
    func_0010D3E0(0);
    if (D_00585CCC == 3) {
        if (func_003A6700(D_00585CCC) == 0) {
            SFOLobby_SetError(self, 0xE, D_004C0D70, 0x1D0);
            return 0;
        }
    } else if (D_00585CCC == 1) {
        if (func_003A6700(D_00585CCC) == 0) {
            SFOLobby_SetError(self, 0xE, D_004C0D70, 0x1D9);
            return 0;
        }
    } else if (D_00585CCC == 2) {
        SFOLobby_SetError(self, 4, D_004C0D70, 0x1E1);
        return 0;
    } else {
        SFOLobby_SetError(self, 4, D_004C0D70, 0x1E7);
        return 0;
    }
    if (SFOLobby_NetUp(self, &D_005849C0) == 0) {
        SFOLobby_NetDown(self);
        return 0;
    }
    if (func_00452CD0(self) == 0) {
        SFOLobby_NetDown(self);
        return 0;
    }
    if (self->useDnas != 0 && SFOLobby_DnasAuth(self) == 0) {
        func_00452C70(self, 1);
        SFOLobby_NetDown(self);
        return 0;
    }
    if (self->directAuth != 0) {
        if (SFOLobby_ResolveHost(self, self->authHostName, self->authServer) == 0) {
            func_00452C70(self, 1);
            SFOLobby_NetDown(self);
            return 0;
        }
        memset(&ent, 0, sizeof(ent));
        String_Copy(ent.name, D_004C0E40);
        String_Copy(ent.hostName, self->authHostName);
        String_Copy(ent.description, D_004C0E60);
        LobbyArray_Append(self->universeList, &ent);
    } else {
        if (SFOLobby_ResolveHost(self, self->dirHostName, self->dirServer) == 0) {
            func_00452C70(self, 1);
            SFOLobby_NetDown(self);
            return 0;
        }
        if (SFOLobby_ConnectDir(self) == 0) {
            func_00452C70(self, 1);
            SFOLobby_NetDown(self);
            return 0;
        }
        if (func_0044CD20(self) == 0) {
            func_00452C70(self, 1);
            SFOLobby_NetDown(self);
            return 0;
        }
        self->connHandle = -1;
    }
    SFOLobby_SetError(self, 0, D_004C0D70, 0x233);
    return 1;
}
