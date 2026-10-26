/*
 * main/SFOLobby_Config: SFOLobby_Config.cc (9 files, 0044B7A0-0044C440)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"
void *memcpy();
void *memset(void *, int, int);
int sprintf(void *, const void *, ...);
int strlen(const char *);

/* merge_units: begin func_0044B7A0 */
#pragma push /* merge_units */
#include "SFOLobby.h"
extern char D_004C0D58[]; /* DNAS start message */
extern char D_004C0D70[]; /* "SFOLobby_Config.cc" */
extern char D_004C0D88[]; /* DNAS done message */
extern unsigned char D_00585E68;
void SFOLobby_DumpMemInfo(char*);
int SFOLibInit_RequestOverlay(int);
int GetThreadId(void);
int ChangeThreadPriority(int, int);
int func_1E68080(int, char*, unsigned short, int, unsigned char, char*, int*);
void DecodeKey_XorB3(char*, int);

/* DNAS authentication: switches the network mode (SFOLibInit_RequestOverlay(2)), runs the DNAS
 * check with dnasArg/dnasData at a raised thread priority, and on success decodes
 * the returned password. On failure asks the update hook (event 3) whether to
 * continue anyway. */
int SFOLobby_DnasAuth(SFOLobby* self)
{
    int old;
    int r;

    self->dnasResult = 0;
    SFOLobby_DumpMemInfo(D_004C0D58);
    SFOLobby_CallUpdateHook(self, 2, 2);
    if (SFOLibInit_RequestOverlay(2) == 0) {
        SFOLobby_SetError(self, 5, D_004C0D70, 0x27A);
        return 0;
    }
    old = ChangeThreadPriority(GetThreadId(), 0x7F);
    if (old < 0)
        old = 2;
    memset(self->password, 0, 0x20);
    self->passwordLen = 0;
    self->dnasResult = func_1E68080(self->dnasArg, self->dnasData, self->dnasDataLen, 0, D_00585E68, self->password, &self->passwordLen);
    if (self->dnasResult != 0) {
        SFOLobby_SetError(self, 6, D_004C0D70, 0x289);
        ChangeThreadPriority(GetThreadId(), old);
        if (SFOLibInit_RequestOverlay(1) == 0) {
            SFOLobby_SetError(self, 5, D_004C0D70, 0x28E);
            return 0;
        }
        r = 0;
        SFOLobby_CallUpdateHook(self, 3, (int)&r);
        return r == 1;
    }
    ChangeThreadPriority(GetThreadId(), old);
    if (SFOLibInit_RequestOverlay(1) == 0) {
        SFOLobby_SetError(self, 5, D_004C0D70, 0x29B);
        return 0;
    }
    SFOLobby_DumpMemInfo(D_004C0D88);
    DecodeKey_XorB3(self->password, 0);
    return 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0044B7A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0044B7A0 */

/* merge_units: begin func_0044B970 */
#pragma push /* merge_units */
#include "types.h"

extern char* strchr(const char*, int);
extern void Libc_Strupr(char*);
extern void sceCdInit(int);
extern void sceSifExitCmd(void);
extern int func_00169920(void);
extern void LoadExecPS2_2(char*, int, char**);
void SFOLobby_LaunchNetGui(char* name, char* arg) {
    char buf[0x100];
    char* argv[2];
    int argc;
    unsigned char has;
    if (D_00585E68) sprintf(buf, "cdrom0:\\%s;1", name);
    else sprintf(buf, "host0:%s", name);
    Libc_Strupr(strchr(buf, ':'));
    sceCdInit(5);
    sceSifExitCmd();
    argv[0] = buf;
    argv[1] = arg;
    has = arg && strlen(arg);
    argc = has + 1;
    if (D_00585E68) {
        if (func_00169920()) LoadExecPS2_2("cdrom0:\\NETGUI\\NTGUI2CN.ELF;1", argc, argv);
        else LoadExecPS2_2("cdrom0:\\NETGUI\\NTGUI2CP.ELF;1", argc, argv);
    } else {
        if (func_00169920()) LoadExecPS2_2("host0:NETGUI/NTGUI2HN.ELF", argc, argv);
        else LoadExecPS2_2("host0:NETGUI/NTGUI2HP.ELF", argc, argv);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0044B970(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0044B970 */

/* merge_units: begin func_0044BAB0 */
#pragma push /* merge_units */
int SFOLobby_NetUp(); /* defined below with (SFOLobby *, int); this block passes a NetCfg_44BAB0 * */
int SFOLobby_NetDown(SFOLobby* a); /* gsynth: defined below */
typedef struct { int w[0x1340 / 4]; } __attribute__((aligned(16))) NetCfg_44BAB0;
/* netConfigList entry (0x13C0 bytes, see SFOLobby_ListNetConfigs) */
typedef struct {
    char hdr[0x80];
    NetCfg_44BAB0 cfg;
} NetProfile_44BAB0;

extern NetCfg_44BAB0 D_005849C0;
extern int D_00585CCC;
extern char D_004C0E40[]; /* "Dummy universe name" */
extern char D_004C0E60[]; /* "Dummy description" */
extern void FlushCache(int);
extern int SFOLibInit_RequestNetworkIRX(int);
extern int SFOLobby_ResolveHost(SFOLobby*, char*, char*);
#if 0 /* merge_units */
extern int SFOLobby_DnasAuth(SFOLobby*);
#endif /* merge_units */
#define SFOLobby_DnasAuth(a0) (SFOLobby_DnasAuth((a0))) /* merge_units */

extern int SFOLobby_ConnectDir(SFOLobby*);
extern int SFOLobby_UniverseInformationRequest(SFOLobby*);
#define LobbyArray_At(a0, a1) ((NetProfile_44BAB0 *)LobbyArray_At((a0), (a1))) /* merge_units */
extern void LobbyArray_Append(LobbyArray*, LobbyUniverseEntry*);
extern int SFOLobby_ShutdownMedius(SFOLobby*, int);
extern int SFOLobby_InitializeMediusBare(SFOLobby*);
#if 0 /* merge_units */
#endif /* merge_units */

#if 0 /* merge_units */
int SFOLobby_NetDown(SFOLobby*);
#endif /* merge_units */
#define SFOLobby_NetDown(a0) (SFOLobby_NetDown((a0))) /* merge_units */


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
    FlushCache(0);
    QuadCopy_44BAB0(&D_005849C0, &prof->cfg, sizeof(NetCfg_44BAB0) / 16);
    FlushCache(0);
    if (D_00585CCC == 3) {
        if (SFOLibInit_RequestNetworkIRX(D_00585CCC) == 0) {
            SFOLobby_SetError(self, 0xE, D_004C0D70, 0x1D0);
            return 0;
        }
    } else if (D_00585CCC == 1) {
        if (SFOLibInit_RequestNetworkIRX(D_00585CCC) == 0) {
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
    if (SFOLobby_InitializeMediusBare(self) == 0) {
        SFOLobby_NetDown(self);
        return 0;
    }
    if (self->useDnas != 0 && SFOLobby_DnasAuth(self) == 0) {
        SFOLobby_ShutdownMedius(self, 1);
        SFOLobby_NetDown(self);
        return 0;
    }
    if (self->directAuth != 0) {
        if (SFOLobby_ResolveHost(self, self->authHostName, self->authServer) == 0) {
            SFOLobby_ShutdownMedius(self, 1);
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
            SFOLobby_ShutdownMedius(self, 1);
            SFOLobby_NetDown(self);
            return 0;
        }
        if (SFOLobby_ConnectDir(self) == 0) {
            SFOLobby_ShutdownMedius(self, 1);
            SFOLobby_NetDown(self);
            return 0;
        }
        if (SFOLobby_UniverseInformationRequest(self) == 0) {
            SFOLobby_ShutdownMedius(self, 1);
            SFOLobby_NetDown(self);
            return 0;
        }
        self->connHandle = -1;
    }
    SFOLobby_SetError(self, 0, D_004C0D70, 0x233);
    return 1;
}
#undef LobbyArray_At /* merge_units */
#undef SFOLobby_DnasAuth /* merge_units */
#undef SFOLobby_NetDown /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0044BAB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0044BAB0 */

/* merge_units: begin func_0044BDE0 */
#pragma push /* merge_units */
void FlushCache(int);
int ezNetCtlSetProperties(int);
int ezNetCtlGetStatus(void*);
int ezNetCtlUpInterface(void);
int SFOLibInit_RequestCancel(int);
extern int D_00585D00;    /* time the network was last brought down (SFOLobby_NetDown) */
extern char D_00585D40[]; /* ezNetCtl status buffer */
extern int D_00585D4C;    /* ezNetCtl state: 3 = up, 5 = down */

/* Applies the network configuration, waits at least 2.5 s after the last
 * shutdown, starts the network and waits (60 s timeout) for it to come up. */
int SFOLobby_NetUp(SFOLobby* self, int props)
{
    int r;
    int now;

    FlushCache(0);
    r = ezNetCtlSetProperties(props);
    FlushCache(0);
    if (r < 0) {
        SFOLobby_SetError(self, 7, D_004C0D70, 0x14A);
        return 0;
    }
    now = Lobby_GetTime();
    if (now < D_00585D00)
        D_00585D00 = now;
    while (now < D_00585D00 + 0x9C4) {
        SFOLobby_CallUpdateHook(self, 0, 0);
        now = Lobby_GetTime();
    }
    D_00585D00 = 0;
    self->waitStart = now;
    if (ezNetCtlUpInterface() < 0) {
        SFOLobby_SetError(self, 0x20, D_004C0D70, 0x163);
        return 0;
    }
    for (;;) {
        SFOLobby_CallUpdateHook(self, 1, 0);
        if (!!SFOLibInit_RequestCancel(0)) {
            SFOLobby_SetError(self, 0x3E, D_004C0D70, 0x16D);
            return 0;
        }
        if (ezNetCtlGetStatus(D_00585D40) >= 0) {
            switch (D_00585D4C) {
            case 1:
                break;
            case 3:
                return 1;
            case 2:
                break;
            case 5:
                SFOLobby_SetError(self, 0x21, D_004C0D70, 0x187);
                return 0;
            }
            if (now - self->waitStart > 60000) {
                SFOLobby_SetError(self, 2, D_004C0D70, 0x190);
                return 0;
            }
            now = Lobby_GetTime();
        } else
            return 1;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0044BDE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0044BDE0 */

/* merge_units: begin func_0044BFF0 */
#pragma push /* merge_units */
extern int ezNetCtlDownInterface(SFOLobby *);

extern int ezNetCtlGetStatus(void *);

/* Stops the network and waits (60 s timeout) until it reports down. */
int SFOLobby_NetDown(SFOLobby *a) {
    int t;
    if (ezNetCtlDownInterface(a) < 0) {
        SFOLobby_SetError(a, 0x20, D_004C0D70, 0x11A);
        return 0;
    }
    a->waitStart = t = Lobby_GetTime();
    D_00585D00 = t;
    for (;;) {
        SFOLobby_CallUpdateHook(a, 0, 0);
        if (ezNetCtlGetStatus(D_00585D40) < 0 || D_00585D4C == 5) {
            break;
        }
        if (t - a->waitStart > 60000) {
            SFOLobby_SetError(a, 2, D_004C0D70, 0x134);
            return 0;
        }
        t = Lobby_GetTime();
    }
    return 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0044BFF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0044BFF0 */

/* merge_units: begin func_0044C0E0 */
#pragma push /* merge_units */
typedef struct {
    int type;
    int status;
    char a[32];
    char b[32];
    char c[32];
} CombEnt;
typedef struct {
    int count;
    int sel;
    int ids[10];
    CombEnt ent[10];
} CombList;
typedef struct {
    unsigned char isDefault;
    int dev;
    int id;
    int type;
    int status;
    char a[32];
    char b[32];
    char c[32];
    char pad74[0xC];
    char prop[0x1340];
} NetCfgInfo;
typedef struct {
    char pad[0x23D8];
    struct { int pad; int count; }* list;
} NetCfg;
extern char* D_00497720[];
extern CombList D_00584580;
#if 0 /* merge_units */
extern char D_005849C0[];
#endif /* merge_units */
#define D_005849C0 ((char*)&D_005849C0) /* merge_units */


int ezNetCnfGetCombinationList(char*, int, CombList*);
int ezNetCnfGetProperties(char*, char*, void*);

#if 0 /* merge_units */
void LobbyArray_Append(void*, NetCfgInfo*);
#endif /* merge_units */
#define LobbyArray_Append(a0, a1) (LobbyArray_Append((void *)(a0), (void *)(a1))) /* merge_units */


int SFOLobby_ListNetConfigs(NetCfg* self, int which)
{
    int dev;
    int n;
    int i;
    NetCfgInfo info;

    SFOLobby_CallUpdateHook(self, 2, 1);
    LobbyArray_Clear(self->list);
    for (dev = 0; dev < 2; dev++) {
        if (which >= 0 && which != dev) continue;
        FlushCache(0);
        n = ezNetCnfGetCombinationList(D_00497720[dev], 1, &D_00584580);
        FlushCache(0);
        if (n <= 0) {
            switch (n) {
            case 0:
                SFOLobby_SetError(self, 0x2F, D_004C0D70, 0xC2);
                break;
            case -15:
                SFOLobby_SetError(self, 0x30, D_004C0D70, 0xC6);
                break;
            default:
                SFOLobby_SetError(self, 0x2F, D_004C0D70, 0xCB);
                break;
            }
            return 0;
        }
        for (i = 0; i < D_00584580.count; i++) {
            memset(&info, 0, sizeof(info));
            info.isDefault = D_00584580.sel == i + 1;
            info.dev = dev;
            info.id = D_00584580.ids[i];
            info.type = D_00584580.ent[i].type;
            info.status = D_00584580.ent[i].status;
            memcpy(info.a, D_00584580.ent[i].a, 32);
            memcpy(info.b, D_00584580.ent[i].b, 32);
            memcpy(info.c, D_00584580.ent[i].c, 32);
            if (info.type >= 0) {
                FlushCache(0);
                if (ezNetCnfGetProperties(D_00497720[info.dev], info.a, D_005849C0) == 0) {
                    FlushCache(0);
                    memcpy(info.prop, D_005849C0, sizeof(info.prop));
                    LobbyArray_Append(self->list, &info);
                }
            }
        }
        if (self->list->count == 0) {
            SFOLobby_SetError(self, 0x2F, D_004C0D70, 0x10A);
            return 0;
        }
    }
    return 1;
}
#undef D_005849C0 /* merge_units */
#undef LobbyArray_Append /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0044C0E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0044C0E0 */

/* merge_units: begin func_0044C3C0 */
#pragma push /* merge_units */
extern int LobbyArray_Free(LobbyArray* p);

/* Leaves the NETWORK state (1) for IDLE (9), releasing netConfigList. */
void SFOLobby_LeaveNetworkState(SFOLobby* self)
{
    if (self->state != SFOLOBBY_STATE_IDLE && self->state == SFOLOBBY_STATE_NETWORK) {
        self->state = SFOLOBBY_STATE_IDLE;
        if (self->netConfigList) {
            LobbyArray_Free(self->netConfigList);
        }
        self->netConfigList = 0;
        SFOLobby_SetCallback(self, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0044C3C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0044C3C0 */

/* merge_units: begin func_0044C420 */
#pragma push /* merge_units */
/* Reads byte +0x2409 when state +0x255C is 3 (result unused). */
typedef struct { char pad00[0x2409]; volatile unsigned char flag; char pad[0x255C - 0x240A]; int state; } Obj_00445E60;
void SFOLobby_ConfigScreenIntel(Obj_00445E60 *obj) {
    if (obj->state == 1) obj->flag;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0044C420(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0044C420 */

/* merge_units: begin func_0044C440 */
#pragma push /* merge_units */
#pragma mpwc_relax on
int Iop_LoadEzNetModules(int);
#if 0 /* merge_units */
int SFOLobby_NetDown(SFOLobby *);
#endif /* merge_units */
#define SFOLobby_NetDown(a0) (SFOLobby_NetDown((a0))) /* merge_units */

#if 0 /* merge_units */
int SFOLobby_ListNetConfigs(SFOLobby *, int);
#endif /* merge_units */
#define SFOLobby_ListNetConfigs(a0, a1) (SFOLobby_ListNetConfigs((void *)(a0), (a1))) /* merge_units */

int SFOLobby_DisconnectAuthServer(SFOLobby *);
#if 0 /* merge_units */
int LobbyArray_Free(LobbyArray *);
#endif /* merge_units */
#define LobbyArray_Free(a0) (LobbyArray_Free((a0))) /* merge_units */

int LobbyArray_Init(LobbyArray *, int, int, int);
int SFOLobby_ShutdownMedius(SFOLobby *, int);
#if 0 /* merge_units */
extern char D_004C0D70; /* "SFOLobby_Config.cc" */
#endif /* merge_units */
#define D_004C0D70 (*(char*)&D_004C0D70) /* merge_units */


/* Enters the NETWORK state (1) from IDLE/initial: shuts down any previous network
 * session, loads the network modules and sets up the caller-supplied lists, then
 * enumerates the network configurations (SFOLobby_ListNetConfigs). */
int SFOLobby_EnterNetworkState(SFOLobby *self, int arg1, LobbyArray *netConfigs, LobbyArray *list2404, char *universes) {
    LobbyArray *a;

    if ((self->state != SFOLOBBY_STATE_IDLE) && (self->state != SFOLOBBY_STATE_0)) {
        return 0;
    }
    self->state = SFOLOBBY_STATE_NETWORK;
    SFOLobby_SetCallback(self);
    self->unk2578 = 0;
    if (self->unk1EA8 > 0) {
        if (self->connHandle > 0) {
            SFOLobby_DisconnectAuthServer(self);
        }
        SFOLobby_ShutdownMedius(self, 1);
        SFOLobby_NetDown(self);
        Iop_LoadEzNetModules(0);
        a = self->outList2404;
        if (a != 0) {
            LobbyArray_Free(a);
        }
        self->outList2404 = 0;
        a = self->universeList;
        if (a != 0) {
            LobbyArray_Free(a);
        }
        self->universeList = 0;
    }
    if (Iop_LoadEzNetModules(1) == 0) {
        SFOLobby_SetError(self, 0x2E, &D_004C0D70, 0x44);
        return 0;
    }
    self->outList2404 = list2404;
    LobbyArray_Init(self->outList2404, 0x10, 0x10, 0x100);
    self->universeList = (LobbyArray *) universes;
    LobbyArray_Init(self->universeList, 0x10, 0x10, sizeof(LobbyUniverseEntry));
    self->netConfigList = netConfigs;
    LobbyArray_Init(self->netConfigList, 0x10, 0x10, 0x13C0);
    if (SFOLobby_ListNetConfigs(self, 0) == 0) {
        a = self->outList2404;
        if (a != 0) {
            LobbyArray_Free(a);
        }
        self->outList2404 = 0;
        a = self->universeList;
        if (a != 0) {
            LobbyArray_Free(a);
        }
        self->universeList = 0;
        a = self->netConfigList;
        if (a != 0) {
            LobbyArray_Free(a);
        }
        self->netConfigList = 0;
        return 0;
    }
    return 1;
}
#undef SFOLobby_NetDown /* merge_units */
#undef SFOLobby_ListNetConfigs /* merge_units */
#undef LobbyArray_Free /* merge_units */
#undef D_004C0D70 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0044C440(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0044C440 */
