/*
 * main/SFOLobby_Config: 5 files, 0044BDE0-0044C420
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0044BDE0 */
#pragma push /* merge_units */
#include "SFOLobby.h"

void func_0010D3E0(int);
int ezNetCtlSetProperties(int);
int ezNetCtlGetStatus(void*);
void SFOLobby_SetError(SFOLobby*, int, char*, int);
void SFOLobby_CallUpdateHook(SFOLobby*, int, int);
int Lobby_GetTime(void);
int func_00353130(void);
int func_003A6650(int);
extern char D_004C0D70[]; /* "SFOLobby_Config.cc" */
extern int D_00585D00;    /* time the network was last brought down (SFOLobby_NetDown) */
extern char D_00585D40[]; /* ezNetCtl status buffer */
extern int D_00585D4C;    /* ezNetCtl state: 3 = up, 5 = down */

/* Applies the network configuration, waits at least 2.5 s after the last
 * shutdown, starts the network and waits (60 s timeout) for it to come up. */
int SFOLobby_NetUp(SFOLobby* self, int props)
{
    int r;
    int now;

    func_0010D3E0(0);
    r = ezNetCtlSetProperties(props);
    func_0010D3E0(0);
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
    if (func_00353130() < 0) {
        SFOLobby_SetError(self, 0x20, D_004C0D70, 0x163);
        return 0;
    }
    for (;;) {
        SFOLobby_CallUpdateHook(self, 1, 0);
        if (!!func_003A6650(0)) {
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
#pragma pop /* merge_units */
/* merge_units: end func_0044BDE0 */

/* merge_units: begin func_0044BFF0 */
#pragma push /* merge_units */
extern int func_003531B8(SFOLobby *);
#if 0 /* merge_units */
extern void SFOLobby_SetError(SFOLobby *, int, const char *, int);
#endif /* merge_units */
#define SFOLobby_SetError(a0, a1, a2, a3) (SFOLobby_SetError((a0), (a1), (char *)(a2), (a3))) /* merge_units */

extern int Lobby_GetTime(void);
extern void SFOLobby_CallUpdateHook(SFOLobby *, int, int);
extern int ezNetCtlGetStatus(void *);

/* Stops the network and waits (60 s timeout) until it reports down. */
int SFOLobby_NetDown(SFOLobby *a) {
    int t;
    if (func_003531B8(a) < 0) {
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
#undef SFOLobby_SetError /* merge_units */
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
extern char D_005849C0[];
#if 0 /* merge_units */
void SFOLobby_CallUpdateHook(NetCfg*, int, int);
#endif /* merge_units */
#define SFOLobby_CallUpdateHook(a0, a1, a2) (SFOLobby_CallUpdateHook((SFOLobby *)(a0), (a1), (a2))) /* merge_units */

void LobbyArray_Clear(void*);
int ezNetCnfGetCombinationList(char*, int, CombList*);
int ezNetCnfGetProperties(char*, char*, void*);
#if 0 /* merge_units */
void SFOLobby_SetError(NetCfg*, int, char*, int);
#endif /* merge_units */
#define SFOLobby_SetError(a0, a1, a2, a3) (SFOLobby_SetError((SFOLobby *)(a0), (a1), (a2), (a3))) /* merge_units */

void LobbyArray_Append(void*, NetCfgInfo*);
void* memset(void*, int, unsigned int);
void* memcpy(void*, const void*, unsigned int);

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
        func_0010D3E0(0);
        n = ezNetCnfGetCombinationList(D_00497720[dev], 1, &D_00584580);
        func_0010D3E0(0);
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
                func_0010D3E0(0);
                if (ezNetCnfGetProperties(D_00497720[info.dev], info.a, D_005849C0) == 0) {
                    func_0010D3E0(0);
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
#undef SFOLobby_CallUpdateHook /* merge_units */
#undef SFOLobby_SetError /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044C0E0 */

/* merge_units: begin func_0044C3C0 */
#pragma push /* merge_units */
extern void LobbyArray_Free(LobbyArray* p);
extern void func_00452FC0(SFOLobby* self, int a);

/* Leaves the NETWORK state (1) for IDLE (9), releasing netConfigList. */
void SFOLobby_LeaveNetworkState(SFOLobby* self)
{
    if (self->state != SFOLOBBY_STATE_IDLE && self->state == SFOLOBBY_STATE_NETWORK) {
        self->state = SFOLOBBY_STATE_IDLE;
        if (self->netConfigList) {
            LobbyArray_Free(self->netConfigList);
        }
        self->netConfigList = 0;
        func_00452FC0(self, 0);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0044C3C0 */

/* merge_units: begin func_0044C420 */
#pragma push /* merge_units */
#include "types.h"

/* Reads byte +0x2409 when state +0x255C is 3 (result unused). */
typedef struct { char pad00[0x2409]; volatile unsigned char flag; char pad[0x255C - 0x240A]; int state; } Obj_00445E60;
void func_0044C420(Obj_00445E60 *obj) {
    if (obj->state == 1) obj->flag;
}
#pragma pop /* merge_units */
/* merge_units: end func_0044C420 */
