/*
 * main/SFOLobby_Account: 10 files, 004452D0-004452F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin SFOLobby_Account_4452D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies just before SFOLobby_Account.cc (starts 0x004452F0).
 */

#include "types.h"

extern int D_004976D8;

int func_004452D0(void) {
    return D_004976D8;
}

void func_004452E0(int value) {
    D_004976D8 = value;
}
#pragma pop /* merge_units */
/* merge_units: end SFOLobby_Account_4452D0 */

/* merge_units: begin func_004452F0 */
#pragma push /* merge_units */
extern char D_004C0B50[], D_004C0B60[];
extern int D_00497890;
extern void func_004474C0(void);
extern int func_00469318(void*, void*);
typedef struct {
    char a[0x15];
    char b[0x11];
} Msg_4452F0;
int SFOLobby_AccountLogout(char* s)
{
    Msg_4452F0 m;
    SFOLobby_CallUpdateHook(s, 2, 1);
    memset(&m, 0, sizeof(m));
    String_Copy(m.a, D_004C0B50);
    String_Copy(m.b, s + 0x2418);
    *(int*)(s + 0x190) = 0;
    *(int*)(s + 0x2410) = Lobby_GetTime();
    *(int*)(s + 0x24C) = func_00469318(&m, func_004474C0);
    if (*(int*)(s + 0x24C)) {
        SFOLobby_SetError(s, 9, D_004C0B60, 0x2F9);
        return 0;
    }
    while (*(int*)(s + 0x190) == 0) {
        SFOLobby_CallUpdateHook(s, 0, 0);
        if (*(int*)(s + 0x24C)) {
            SFOLobby_SetError(s, 9, D_004C0B60, 0x303);
            return 0;
        }
        if (!SFOLobby_Poll(s, *(int*)(s + 0x2410), D_00497890, 0)) {
            SFOLobby_SetError(s, 2, D_004C0B60, 0x30A);
            return 0;
        }
    }
    return *(int*)(s + 0x34C) == 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_004452F0 */

/* merge_units: begin func_00445420 */
#pragma push /* merge_units */
extern void SFOLobby_OnAccountLogin(void);
extern int func_00469260(void*, void*);
typedef struct {
    char a[0x15];
    char b[0x11];
    char c[0x20];
    char d[0x20];
} Msg_445420;
int SFOLobby_AccountLogin(char* s)
{
    Msg_445420 m;
    SFOLobby_CallUpdateHook(s, 2, 1);
    memset(&m, 0, sizeof(m));
    String_Copy(m.a, D_004C0B50);
    String_Copy(m.b, s + 0x2418);
    String_Copy(m.c, s + 0x243D);
    String_Copy(m.d, s + 0x245D);
    *(int*)(s + 0x18C) = 0;
    *(int*)(s + 0x2410) = Lobby_GetTime();
    *(int*)(s + 0x24C) = func_00469260(&m, SFOLobby_OnAccountLogin);
    if (*(int*)(s + 0x24C)) {
        SFOLobby_SetError(s, 10, D_004C0B60, 0x2B0);
        return 0;
    }
    while (*(int*)(s + 0x18C) == 0) {
        SFOLobby_CallUpdateHook(s, 0, 0);
        if (*(int*)(s + 0x24C)) {
            SFOLobby_SetError(s, 10, D_004C0B60, 0x2BA);
            return 0;
        }
        if (!SFOLobby_Poll(s, *(int*)(s + 0x2410), D_00497890, 0)) {
            SFOLobby_SetError(s, 2, D_004C0B60, 0x2C1);
            return 0;
        }
    }
    return *(int*)(s + 0x268) == 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00445420 */

/* merge_units: begin func_00445570 */
#pragma push /* merge_units */
extern int func_00476998(void);
extern void SFOLobby_OnSettings(void);
extern int func_0046AB38(void*, void*);
typedef struct {
    char a[0x15];
    char b[0x11];
    int t;
} Msg_445570;
int SFOLobby_RequestSettings(char* s)
{
    Msg_445570 m;
    SFOLobby_CallUpdateHook(s, 2, 6);
    memset(&m, 0, sizeof(m));
    memset(s + 0x5A4, 0, 0x40C);
    String_Copy(m.a, D_004C0B50);
    String_Copy(m.b, s + 0x2418);
    m.t = func_00476998();
    *(int*)(s + 0x1BC) = 0;
    *(int*)(s + 0x2410) = Lobby_GetTime();
    *(int*)(s + 0x24C) = func_0046AB38(&m, SFOLobby_OnSettings);
    while (*(signed char*)(s + 0x9AC) != 1) {
        SFOLobby_CallUpdateHook(s, 0, 0);
        if (*(int*)(s + 0x24C) != 0) {
            SFOLobby_SetError(s, 0x29, D_004C0B60, 0x273);
            return 0;
        }
        if (!SFOLobby_Poll(s, *(int*)(s + 0x2410), D_00497890, 0)) {
            SFOLobby_SetError(s, 2, D_004C0B60, 0x27A);
            return 0;
        }
    }
    SFOLobby_SetError(s, 0, D_004C0B60, 0x27E);
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_00445570 */

/* merge_units: begin func_004456C0 */
#pragma push /* merge_units */
typedef struct { char pad[0x1B8]; int f1b8; char pad2[0x90]; int f24c; char pad3[0x234]; char f484[0x11C]; signed char c5a0; char pad4[0x1E6F]; int f2410; char p2414[4]; char f2418[0x20]; } O445;
int SFOLobby_GetPolicy(O445* o, int mode); /* gsynth: defined below */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


#if 0 /* merge_units */
extern int SFOLobby_GetPolicy(void* self, int enable);
#endif /* merge_units */
#define SFOLobby_GetPolicy(a0, a1) (SFOLobby_GetPolicy((O445 *)(a0), (a1))) /* merge_units */



/* SFOLobby_GetPolicy(self, 1). */
int SFOLobby_GetPrivacyPolicy(void* self) {
    return SFOLobby_GetPolicy(self, 1);
}

/* SFOLobby_GetPolicy(self, 0). */
int SFOLobby_GetUsagePolicy(void* self) {
    return SFOLobby_GetPolicy(self, 0);
}
#undef SFOLobby_GetPolicy /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004456C0 */

/* merge_units: begin func_004456E0 */
#pragma push /* merge_units */
typedef struct { char name[0x15]; char id[0x13]; int mode; } R445;

extern int func_0046A8F8(R445*, void*);
extern void SFOLobby_OnGetPolicy();
extern char D_004C0B60[];
int SFOLobby_GetPolicy(O445* o, int mode) {
    R445 rec;
    char* s;
    SFOLobby_CallUpdateHook(o, 2, 5);
    memset(&rec, 0, 0x2C);
    memset(o->f484, 0, 0x120);
    if (mode == 0) s = "USAGE";
    else s = "PRIVACY";
    String_Copy(rec.name, s);
    String_Copy(rec.id, o->f2418);
    rec.mode = mode;
    o->f1b8 = 0;
    o->f2410 = Lobby_GetTime();
    o->f24c = func_0046A8F8(&rec, SFOLobby_OnGetPolicy);
    while (o->c5a0 != 1) {
        SFOLobby_CallUpdateHook(o, 0, 0);
        if (o->f24c != 0) {
            SFOLobby_SetError(o, 0x15, D_004C0B60, 0x22C);
            return 0;
        }
        if (!SFOLobby_Poll(o, o->f2410, D_00497890, 0)) {
            SFOLobby_SetError(o, 2, D_004C0B60, 0x233);
            return 0;
        }
    }
    SFOLobby_SetError(o, 0, D_004C0B60, 0x237);
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_004456E0 */

/* merge_units: begin func_00445850 */
#pragma push /* merge_units */
extern void func_00447470(void);
extern int func_004690A0(void*, void*);
extern int SFOLobby_DisconnectLobbyServer(void*);
extern void func_004537D0(void*);
typedef struct {
    char a[0x15];
    char b[0x11];
} Msg_445850;
int func_00445850(char* s)
{
    Msg_445850 m;
    SFOLobby_CallUpdateHook(s, 2, 1);
    if (*(int*)(s + 0x1A4) == 1) {
        memset(&m, 0, sizeof(m));
        String_Copy(m.a, D_004C0B50);
        String_Copy(m.b, s + 0x2418);
        *(int*)(s + 0x2410) = Lobby_GetTime();
        *(int*)(s + 0x24C) = func_004690A0(&m, func_00447470);
        if (*(int*)(s + 0x24C) != 0) {
            SFOLobby_SetError(s, 9, D_004C0B60, 0x1E8);
            return 0;
        }
        while (*(int*)(s + 0x1A8) == 0) {
            SFOLobby_CallUpdateHook(s, 0, 0);
            if (!SFOLobby_Poll(s, *(int*)(s + 0x2410), D_00497890, 0)) {
                SFOLobby_SetError(s, 2, D_004C0B60, 0x1F2);
                return 0;
            }
        }
        if (*(int*)(s + 0x398) != 0) {
            SFOLobby_SetError(s, 9, D_004C0B60, 0x1FE);
            return 0;
        }
    }
    if (!SFOLobby_DisconnectLobbyServer(s)) return 0;
    func_004537D0(s);
    SFOLobby_SetError(s, 0, D_004C0B60, 0x208);
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_00445850 */

/* merge_units: begin func_004459D0 */
#pragma push /* merge_units */
#include "SFOLobby_Account_types.h"

#if 0 /* merge_units */
extern int SFOLobby_AccountLogin(LobbyAccount* self);
#endif /* merge_units */
#define SFOLobby_AccountLogin(a0) (SFOLobby_AccountLogin((char *)(a0))) /* merge_units */


#if 0 /* merge_units */
extern int SFOLobby_AccountLogout(LobbyAccount* self);
#endif /* merge_units */
#define SFOLobby_AccountLogout(a0) (SFOLobby_AccountLogout((char *)(a0))) /* merge_units */



/* Submit the two account fields, then clear their first bytes after use. */
unsigned char func_004459D0(LobbyAccount* self, const char* first, const char* second)
{
    unsigned char result;
    strncpy(self->first, first, 32);
    strncpy(self->second, second, 32);
    result = SFOLobby_AccountLogin(self);
    if (result)
        SFOLobby_AccountLogout(self);
    self->first[0] = 0;
    self->second[0] = 0;
    return result;
}
#undef SFOLobby_AccountLogin /* merge_units */
#undef SFOLobby_AccountLogout /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004459D0 */

/* merge_units: begin func_00445A40 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern int SFOLobby_AccountLogin(char*);
#endif /* merge_units */
#define SFOLobby_AccountLogin(a0) (SFOLobby_AccountLogin((a0))) /* merge_units */


#if 0 /* merge_units */
extern int SFOLobby_AccountLogout(char*);
#endif /* merge_units */
#define SFOLobby_AccountLogout(a0) (SFOLobby_AccountLogout((a0))) /* merge_units */


extern int SFOLobby_DisconnectAuthServer(void*);
extern int SFOLobby_ConnectLobby(void*);
int func_00445A40(char* s, const char* a, const char* b)
{
    strncpy(s + 0x243D, a, 0x20);
    strncpy(s + 0x245D, b, 0x20);
    if (!SFOLobby_AccountLogin(s)) {
        if (*(int*)(s + 0x268) == -0x3DF) {
            SFOLobby_AccountLogout(s);
            SFOLobby_SetError(s, 1, D_004C0B60, 0x187);
            return 0;
        } else if (*(int*)(s + 0x268) == -0x3E5) {
            if (SFOLobby_AccountLogout(s)) {
                if (!SFOLobby_AccountLogin(s)) return 0;
            } else {
                SFOLobby_SetError(s, 1, D_004C0B60, 0x194);
                return 0;
            }
        } else {
            return 0;
        }
    }
    if (!SFOLobby_DisconnectAuthServer(s)) return 0;
    if (!SFOLobby_ConnectLobby(s)) return 0;
    SFOLobby_SetError(s, 0, D_004C0B60, 0x1AB);
    return 1;
}
#undef SFOLobby_AccountLogin /* merge_units */
#undef SFOLobby_AccountLogout /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00445A40 */

/* merge_units: begin func_00445B90 */
#pragma push /* merge_units */
typedef struct { char p0[0x198]; int done; char p19C[0xB0]; int f24C; char p250[0xDC]; int f32C; char p330[0x20E0]; int f2410; char p2414[4]; char name[0x14C]; } S445B90;
extern int SFOLobby_CheckText(S445B90*, char*, int);
extern int func_00469458(void*, void*);
extern char D_004C0B50[];
extern char func_00447270[];
int SFOLobby_CreateAccount(S445B90* s, char* arg1, char* arg2)
{
    struct { char f40[0x15]; char f55[0x13]; int f68; char f6C[0x20]; char f8C[0x20]; } req;

    SFOLobby_CallUpdateHook(s, 2, 1);
    if (SFOLobby_CheckText(s, arg1, 0) == 0) {
        SFOLobby_SetError(s, 3, D_004C0B60, 0xD5);
        return 0;
    }
    if (SFOLobby_CheckText(s, arg2, 0) == 0) {
        SFOLobby_SetError(s, 3, D_004C0B60, 0xDA);
        return 0;
    }
    memset(&req, 0, sizeof(req));
    String_Copy(req.f40, D_004C0B50);
    String_Copy(req.f55, s->name);
    req.f68 = 1;
    strncpy(req.f6C, arg1, 0x20);
    strncpy(req.f8C, arg2, 0x20);
    s->done = 0;
    s->f2410 = Lobby_GetTime();
    s->f24C = func_00469458(&req, func_00447270);
    while (s->done == 0) {
        SFOLobby_CallUpdateHook(s, 0, 0);
        if (s->f24C != 0) {
            SFOLobby_SetError(s, 0xB, D_004C0B60, 0xF5);
            return 0;
        }
        if (SFOLobby_Poll(s, s->f2410, D_00497890, 0) == 0) {
            SFOLobby_SetError(s, 2, D_004C0B60, 0xFC);
            return 0;
        }
    }
    if (s->f32C != 0) {
        if (s->f32C == -0x3E7) {
            SFOLobby_SetError(s, 0x3D, D_004C0B60, 0x105);
        } else {
            SFOLobby_SetError(s, 0xB, D_004C0B60, 0x109);
        }
        return 0;
    }
    SFOLobby_SetError(s, 0, D_004C0B60, 0x10E);
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_00445B90 */
