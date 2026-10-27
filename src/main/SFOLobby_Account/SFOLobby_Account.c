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

int SFOMGCL_Get_MediusWorldID(void) {
    return D_004976D8;
}

void SFOMGCL_Set_MediusWorldID(int value) {
    D_004976D8 = value;
}
#pragma pop /* merge_units */
/* merge_units: end SFOLobby_Account_4452D0 */

/* merge_units: begin func_004452F0 */
#pragma push /* merge_units */
extern char D_004C0B50[], D_004C0B60[];
extern int D_00497890;
extern void SFOLobby_Callback_AccountLogout(void);
extern int MediusAccountLogout(void*, void*);
typedef struct {
    char a[0x15];
    char b[0x11];
} Msg_4452F0;
int SFOLobby_AccountLogoutRequest(char* s)
{
    Msg_4452F0 m;
    SFOLobby_GuiCallback(s, 2, 1);
    memset(&m, 0, sizeof(m));
    Libc_Strcpy(m.a, D_004C0B50);
    Libc_Strcpy(m.b, s + 0x2418);
    *(int*)(s + 0x190) = 0;
    *(int*)(s + 0x2410) = SFOLobby_GetMillisecs();
    *(int*)(s + 0x24C) = MediusAccountLogout(&m, SFOLobby_Callback_AccountLogout);
    if (*(int*)(s + 0x24C)) {
        SFOLobby_SetError(s, 9, D_004C0B60, 0x2F9);
        return 0;
    }
    while (*(int*)(s + 0x190) == 0) {
        SFOLobby_GuiCallback(s, 0, 0);
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
extern void SFOLobby_Callback_AccountLogin(void);
extern int MediusAccountLogin(void*, void*);
typedef struct {
    char a[0x15];
    char b[0x11];
    char c[0x20];
    char d[0x20];
} Msg_445420;
int SFOLobby_AccountLoginRequest(char* s)
{
    Msg_445420 m;
    SFOLobby_GuiCallback(s, 2, 1);
    memset(&m, 0, sizeof(m));
    Libc_Strcpy(m.a, D_004C0B50);
    Libc_Strcpy(m.b, s + 0x2418);
    Libc_Strcpy(m.c, s + 0x243D);
    Libc_Strcpy(m.d, s + 0x245D);
    *(int*)(s + 0x18C) = 0;
    *(int*)(s + 0x2410) = SFOLobby_GetMillisecs();
    *(int*)(s + 0x24C) = MediusAccountLogin(&m, SFOLobby_Callback_AccountLogin);
    if (*(int*)(s + 0x24C)) {
        SFOLobby_SetError(s, 10, D_004C0B60, 0x2B0);
        return 0;
    }
    while (*(int*)(s + 0x18C) == 0) {
        SFOLobby_GuiCallback(s, 0, 0);
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
extern int KM_GetSoftwareID(void);
extern void SFOLobby_OnSettings(void);
extern int MediusGetAnnouncements(void*, void*);
typedef struct {
    char a[0x15];
    char b[0x11];
    int t;
} Msg_445570;
int SFOLobby_GetAnnouncements(char* s)
{
    Msg_445570 m;
    SFOLobby_GuiCallback(s, 2, 6);
    memset(&m, 0, sizeof(m));
    memset(s + 0x5A4, 0, 0x40C);
    Libc_Strcpy(m.a, D_004C0B50);
    Libc_Strcpy(m.b, s + 0x2418);
    m.t = KM_GetSoftwareID();
    *(int*)(s + 0x1BC) = 0;
    *(int*)(s + 0x2410) = SFOLobby_GetMillisecs();
    *(int*)(s + 0x24C) = MediusGetAnnouncements(&m, SFOLobby_OnSettings);
    while (*(signed char*)(s + 0x9AC) != 1) {
        SFOLobby_GuiCallback(s, 0, 0);
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

extern int MediusGetPolicy(R445*, void*);
extern void SFOLobby_Callback_GetPolicy();
extern char D_004C0B60[];
int SFOLobby_GetPolicy(O445* o, int mode) {
    R445 rec;
    char* s;
    SFOLobby_GuiCallback(o, 2, 5);
    memset(&rec, 0, 0x2C);
    memset(o->f484, 0, 0x120);
    if (mode == 0) s = "USAGE";
    else s = "PRIVACY";
    Libc_Strcpy(rec.name, s);
    Libc_Strcpy(rec.id, o->f2418);
    rec.mode = mode;
    o->f1b8 = 0;
    o->f2410 = SFOLobby_GetMillisecs();
    o->f24c = MediusGetPolicy(&rec, SFOLobby_Callback_GetPolicy);
    while (o->c5a0 != 1) {
        SFOLobby_GuiCallback(o, 0, 0);
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
extern void SFOLobby_Callback_SessionEnd(void);
extern int MediusSessionEnd(void*, void*);
extern int SFOLobby_MediusDisconnectMLS(void*);
extern void SFOLobby_ResetConnectionFlags(void*);
typedef struct {
    char a[0x15];
    char b[0x11];
} Msg_445850;
int SFOLobby_AccountLogOut(char* s)
{
    Msg_445850 m;
    SFOLobby_GuiCallback(s, 2, 1);
    if (*(int*)(s + 0x1A4) == 1) {
        memset(&m, 0, sizeof(m));
        Libc_Strcpy(m.a, D_004C0B50);
        Libc_Strcpy(m.b, s + 0x2418);
        *(int*)(s + 0x2410) = SFOLobby_GetMillisecs();
        *(int*)(s + 0x24C) = MediusSessionEnd(&m, SFOLobby_Callback_SessionEnd);
        if (*(int*)(s + 0x24C) != 0) {
            SFOLobby_SetError(s, 9, D_004C0B60, 0x1E8);
            return 0;
        }
        while (*(int*)(s + 0x1A8) == 0) {
            SFOLobby_GuiCallback(s, 0, 0);
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
    if (!SFOLobby_MediusDisconnectMLS(s)) return 0;
    SFOLobby_ResetConnectionFlags(s);
    SFOLobby_SetError(s, 0, D_004C0B60, 0x208);
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_00445850 */

/* merge_units: begin func_004459D0 */
#pragma push /* merge_units */
#include "SFOLobby_Account_types.h"

#if 0 /* merge_units */
extern int SFOLobby_AccountLoginRequest(LobbyAccount* self);
#endif /* merge_units */
#define SFOLobby_AccountLoginRequest(a0) (SFOLobby_AccountLoginRequest((char *)(a0))) /* merge_units */


#if 0 /* merge_units */
extern int SFOLobby_AccountLogoutRequest(LobbyAccount* self);
#endif /* merge_units */
#define SFOLobby_AccountLogoutRequest(a0) (SFOLobby_AccountLogoutRequest((char *)(a0))) /* merge_units */



/* Submit the two account fields, then clear their first bytes after use. */
unsigned char func_004459D0(LobbyAccount* self, const char* first, const char* second)
{
    unsigned char result;
    strncpy(self->first, first, 32);
    strncpy(self->second, second, 32);
    result = SFOLobby_AccountLoginRequest(self);
    if (result)
        SFOLobby_AccountLogoutRequest(self);
    self->first[0] = 0;
    self->second[0] = 0;
    return result;
}
#undef SFOLobby_AccountLoginRequest /* merge_units */
#undef SFOLobby_AccountLogoutRequest /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004459D0 */

/* merge_units: begin func_00445A40 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern int SFOLobby_AccountLoginRequest(char*);
#endif /* merge_units */
#define SFOLobby_AccountLoginRequest(a0) (SFOLobby_AccountLoginRequest((a0))) /* merge_units */


#if 0 /* merge_units */
extern int SFOLobby_AccountLogoutRequest(char*);
#endif /* merge_units */
#define SFOLobby_AccountLogoutRequest(a0) (SFOLobby_AccountLogoutRequest((a0))) /* merge_units */


extern int SFOLobby_MediusDisconnectMAS(void*);
extern int SFOLobby_MediusConnectMLS(void*);
int func_00445A40(char* s, const char* a, const char* b)
{
    strncpy(s + 0x243D, a, 0x20);
    strncpy(s + 0x245D, b, 0x20);
    if (!SFOLobby_AccountLoginRequest(s)) {
        if (*(int*)(s + 0x268) == -0x3DF) {
            SFOLobby_AccountLogoutRequest(s);
            SFOLobby_SetError(s, 1, D_004C0B60, 0x187);
            return 0;
        } else if (*(int*)(s + 0x268) == -0x3E5) {
            if (SFOLobby_AccountLogoutRequest(s)) {
                if (!SFOLobby_AccountLoginRequest(s)) return 0;
            } else {
                SFOLobby_SetError(s, 1, D_004C0B60, 0x194);
                return 0;
            }
        } else {
            return 0;
        }
    }
    if (!SFOLobby_MediusDisconnectMAS(s)) return 0;
    if (!SFOLobby_MediusConnectMLS(s)) return 0;
    SFOLobby_SetError(s, 0, D_004C0B60, 0x1AB);
    return 1;
}
#undef SFOLobby_AccountLoginRequest /* merge_units */
#undef SFOLobby_AccountLogoutRequest /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00445A40 */

/* merge_units: begin func_00445B90 */
#pragma push /* merge_units */
typedef struct { char p0[0x198]; int done; char p19C[0xB0]; int f24C; char p250[0xDC]; int f32C; char p330[0x20E0]; int f2410; char p2414[4]; char name[0x14C]; } S445B90;
extern int SFOLobby_ServerTextFilter(S445B90*, char*, int);
extern int MediusAccountRegistration(void*, void*);
extern char D_004C0B50[];
extern char SFOLobby_Callback_AccountRegistration[];
int SFOLobby_AccountCreate(S445B90* s, char* arg1, char* arg2)
{
    struct { char f40[0x15]; char f55[0x13]; int f68; char f6C[0x20]; char f8C[0x20]; } req;

    SFOLobby_GuiCallback(s, 2, 1);
    if (SFOLobby_ServerTextFilter(s, arg1, 0) == 0) {
        SFOLobby_SetError(s, 3, D_004C0B60, 0xD5);
        return 0;
    }
    if (SFOLobby_ServerTextFilter(s, arg2, 0) == 0) {
        SFOLobby_SetError(s, 3, D_004C0B60, 0xDA);
        return 0;
    }
    memset(&req, 0, sizeof(req));
    Libc_Strcpy(req.f40, D_004C0B50);
    Libc_Strcpy(req.f55, s->name);
    req.f68 = 1;
    strncpy(req.f6C, arg1, 0x20);
    strncpy(req.f8C, arg2, 0x20);
    s->done = 0;
    s->f2410 = SFOLobby_GetMillisecs();
    s->f24C = MediusAccountRegistration(&req, SFOLobby_Callback_AccountRegistration);
    while (s->done == 0) {
        SFOLobby_GuiCallback(s, 0, 0);
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
