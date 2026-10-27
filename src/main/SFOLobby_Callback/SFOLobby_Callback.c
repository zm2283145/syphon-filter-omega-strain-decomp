/*
 * main/SFOLobby_Callback: SFOLobby_Callback.cc (32 files, 00446560-004475E0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"
void *memcpy();
void *memset(void *, int, int);
int strcmp(const void *, const void *);
int strlen(const char *);
char *strncpy(void *, const void *, int);

/* merge_units: begin func_00446560 */
#pragma push /* merge_units */
#include "SFOLobby.h"

/* Reply to a pending inbox entry of type 1 (SFOLobby_MessageAck): accepted or denied. */
typedef struct {
    char messageId[0x18];
    int statusCode;                 /* MediusRequestAccepted or MediusRequestDenied */
    char sessionKey[0x14];
    int requestId;                  /* entry->id */
    int f34;
} Msg_00446560;
typedef struct { char pad[8]; int id; } Arg_00446560;
extern int MediusBuddyAddConfirmation(Msg_00446560* m);

int SFOLobby_ContactConfirmation(SFOLobby* self, Arg_00446560* arg, int ok)
{
    Msg_00446560 m;
    memset(&m, 0, sizeof(m));
    Libc_Strcpy(m.messageId, "1");
    strncpy(m.sessionKey, self->sessionKey, 0x11);
    m.requestId = arg->id;
    m.f34 = 1;
    m.statusCode = ok ? MediusRequestAccepted : MediusRequestDenied;
    if (MediusBuddyAddConfirmation(&m)) {
        SFOLobby_SetError(self, 1, "SFOLobby_Callback.cc", 2084);
        return 0;
    }
    SFOLobby_SetError(self, 0, "SFOLobby_Callback.cc", 2088);
    return 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00446560(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00446560 */

/* merge_units: begin func_00446640 */
#pragma push /* merge_units */
typedef struct { char pad[0x18]; int kind; char name[1]; } Request;
typedef struct { int type; int pad; int kind; char name[0xA0]; } Record;
extern SFOLobby* D_00585E60;
extern int SFOLobbyList_Append(LobbyArray* list, Record* rec);
/* Reply callback: queues a type-1 inbox entry built from the message. */
void SFOLobby_Callback_BuddyConfirmationRequest(void* a0, void* a1, void* a2, Request* req)
{
    Record rec;
    if (SFOLobby_IgnoreCallbacks(a0, a1, a2) == 0) {
        memset(&rec, 0, sizeof(rec));
        rec.type = 1;
        rec.kind = req->kind;
        Libc_Strcpy(rec.name, req->name);
        SFOLobbyList_Append(&D_00585E60->inbox, &rec);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00446640(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00446640 */

/* merge_units: begin func_004466B0 */
#pragma push /* merge_units */
/* Reply callback: flags gotReply230. */
void func_004466B0(void)
{
    if (!SFOLobby_IgnoreCallbacks())
        D_00585E60->gotReply230 = 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004466B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004466B0 */

/* merge_units: begin func_004466F0 */
#pragma push /* merge_units */
/* Reply callback: flags gotReply238 and records whether the status was MediusSuccess. */
void SFOLobby_Callback_RemoveFromBuddyList(void* a, void* b, void* c, LobbyReply* d)
{
    if (!SFOLobby_IgnoreCallbacks(a, b, c, d)) {
        D_00585E60->gotReply238 = 1;
        D_00585E60->reply238Ok = d->statusCode == MediusSuccess;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004466F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004466F0 */

/* merge_units: begin func_00446740 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#pragma mpwc_relax on
#if 0 /* merge_units */
int SFOLobbyList_Append(LobbyArray * , int *);
#endif /* merge_units */
#define SFOLobbyList_Append(a0, a1) (SFOLobbyList_Append((a0), (void *)(a1))) /* merge_units */


/* Reply callback: flags gotReply22C when the end-of-list byte (+0x44) is set and
 * queues a type-1 inbox entry for every successful record. */
void SFOLobby_Callback_GetBuddyInvitations(int d0, int d1, int d2, char * arg3) {
    struct { int f20[2]; int f28; int f2C[41]; } sl;

    if (SFOLobby_IgnoreCallbacks() == 0) {
        if (F_(arg3, 0x44, signed char) != 0) {
            D_00585E60->gotReply22C = 1;
        }
        if (F_(arg3, 0x18, int) == 0) {
            memset(sl.f20, 0, 0xAC);
            sl.f20[0] = 1;
            sl.f28 = F_(arg3, 0x1C, int);
            Libc_Strcpy(sl.f2C, arg3 + 0x20);
            SFOLobbyList_Append(&D_00585E60->inbox, sl.f20);
        }
    }
}
#undef SFOLobbyList_Append /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00446740(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00446740 */

/* merge_units: begin func_004467D0 */
#pragma push /* merge_units */
typedef struct { char pad[0x18]; int statusCode; char accountName[0x2C]; LobbyPlayerInfo info; } S67D0;
extern int atoi(S67D0* s);
extern void SFOLobby_RefreshAgentData(SFOLobby* h, int r, void* p, int q, int t);
/* Reply callback: on success caches the player's info in accountCache. */
void SFOLobby_Callback_GetPlayerInfo_ForBuddyList(int a, int b, int c, S67D0* s) {
    if (SFOLobby_IgnoreCallbacks(a, b, c, s) == 0 && s->statusCode == 0) {
        int r = atoi(s);
        SFOLobby_RefreshAgentData(D_00585E60, r, s->accountName, s->info.ip, (int)&s->info);
    }
}
/* merge_units: generate this block's code before the language mode changes */
static inline void merge_flush_func_004467D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004467D0 */

/* merge_units: begin func_00446830 */
#pragma push /* merge_units */
#pragma cplusplus on
#define NULL 0
extern "C" {
char *SFOLobby_FindGameData(SFOLobby *, int, int *);
void SFOLobbyList_CopyListFrom(LobbyArray *, LobbyArray *);
void SFOLobbyList_SetUpdateFlag(LobbyArray *, int);
#if 0 /* merge_units */
int SFOLobbyList_Append(LobbyArray *, void *);
#endif /* merge_units */
#define SFOLobbyList_Append(a0, a1) (SFOLobbyList_Append((a0), (Record *)(a1))) /* merge_units */

extern char D_004C0CC8[]; /* "" */
}
typedef struct {
    signed char a, b;
} Pair446830;
/* One buddy-list reply record (same layout as LobbyBuddyReply). */
typedef struct {
    char messageId[0x15];
    int statusCode;
    int accountId;
    Pair446830 accountName[0x10];
    int w[0x23];                    /* w[0] playerStatus, w[2] gameWorldId */
    signed char endOfList;
} Msg446830;
/* LobbyArray element of buddyList (0x50 bytes). */
typedef struct {
    int accountId;
    char name[0x20];
    int f24;                        /* 1 in a game, 2 in a chat world, 3 otherwise */
    int f28;
    char *f2C;
    int f30;
    int f34;
    int f38;
    int f3C;
    int f40;
    int f44;
    int gameWorldId;
    int f4C;
} Buddy446830;
/* Buddy-list reply callback: appends one buddy per record (looking up the game the
 * buddy is in), and on the last record publishes the list to pool150/outBuddyList. */
extern "C" void SFOLobby_Callback_GetBuddyList(int d0, int d1, int d2, Msg446830 *msg)
{
    Buddy446830 req;
    LobbyArray *list;
    char *e;
    if (SFOLobby_IgnoreCallbacks() == 0) {
        list = &D_00585E60->buddyList;
        if (list != NULL) {
            if (msg->statusCode == MediusSuccess) {
                memset(&req, 0, 0x50);
                req.accountId = msg->accountId;
                Libc_Strcpy(req.name, (char *)msg->accountName);
                req.f30 = 0;
                req.f34 = -1;
                req.f38 = -1;
                req.f3C = -1;
                req.f40 = -1;
                req.f44 = 5;
                req.f28 = 2;
                req.f24 = 3;
                req.f2C = D_004C0CC8;
                switch (msg->w[0]) {
                case MediusPlayerDisconnected:
                case MediusPlayerInAuthWorld:
                    break;
                case MediusPlayerInChatWorld:
                    req.f24 = 2;
                    break;
                case MediusPlayerInGameWorld:
                    req.f24 = 1;
                    req.gameWorldId = msg->w[2];
                    e = SFOLobby_FindGameData(D_00585E60, req.gameWorldId, &req.f24);
                    if (e != NULL) {
                        req.f30 = F_(e, 0x24, int);
                        req.f34 = F_(e, 0x4, int);
                        req.f38 = F_(e, 0x8, int);
                        req.f3C = F_(e, 0x1C, int);
                        req.f40 = F_(e, 0x10, int);
                        req.f44 = F_(e, 0x18, int);
                    }
                    break;
                }
                SFOLobbyList_Append(list, &req);
            }
            if (msg->endOfList != 0) {
                SFOLobbyList_SetBusy(list, 0);
                if (list->count > 0)
                    SFOLobbyList_SetUpdateFlag(list, 1);
                if (D_00585E60->outBuddyList != NULL)
                    SFOLobbyList_CopyListFrom(D_00585E60->outBuddyList, list);
                SFOLobbyList_CopyListFrom(&D_00585E60->pool150, list);
            }
            *(Msg446830 *)&D_00585E60->buddyListReply = *msg;
        }
    }
}
#undef SFOLobbyList_Append /* merge_units */
/* merge_units: generate this block's code before the language mode changes */
static inline void merge_flush_func_00446830(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00446830 */

/* merge_units: begin func_00446AE0 */
#pragma push /* merge_units */
extern int SFOLobby_RefreshGameData(SFOLobby* self, int a, int b, int c, int d, void* e);/* Reply callback: on success forwards the record's fields to SFOLobby_RefreshGameData. */
void SFOLobby_Callback_RefreshGameInfo(int a0, int a1, int a2, char* m) {
    if (SFOLobby_IgnoreCallbacks() == 0 && F_(m, 0x18, int) == 0) {
        SFOLobby_RefreshGameData(D_00585E60, F_(m, 0x3C, int), F_(m, 0x30, int), F_(m, 0x24, int), F_(m, 0x184, int), m + 0x34);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00446AE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00446AE0 */

/* merge_units: begin func_00446B40 */
#pragma push /* merge_units */
typedef struct { char c[21]; } S21;
typedef struct { char c[256]; } S256;
typedef struct { char c[64]; } S64;
int SFOLobby_RefreshGameData();
typedef struct { S21 name; int a18, a1C, a20, a24, a28, a2C, a30; S256 s; S64 t; int b174, b178, b17C, b180, b184, b188; } R46B;
/* Reply callback: flags gotReply20C, forwards a successful record to SFOLobby_RefreshGameData
 * and keeps a copy in reply1D08. */
void func_00446B40(int d0, int d1, int d2, R46B *src) {
    if (SFOLobby_IgnoreCallbacks() == 0) {
        R46B *d;
        D_00585E60->gotReply20C = 1;
        if (src->a18 == 0) {
            SFOLobby_RefreshGameData(D_00585E60, *(int *)((char *)src + 0x3C), src->a30, src->a24, src->b184, &src->s);
        }
        d = (R46B *)D_00585E60->reply1D08;
        d->name = src->name;
        d->a18 = src->a18;
        d->a1C = src->a1C;
        d->a20 = src->a20;
        d->a24 = src->a24;
        d->a28 = src->a28;
        d->a2C = src->a2C;
        d->a30 = src->a30;
        d->s = src->s;
        d->t = src->t;
        d->b174 = src->b174;
        d->b178 = src->b178;
        d->b17C = src->b17C;
        d->b180 = src->b180;
        d->b184 = src->b184;
        d->b188 = src->b188;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00446B40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00446B40 */

/* merge_units: begin func_00446CA0 */
#pragma push /* merge_units */
#pragma cplusplus on
/* C++: Metrowerks keeps the call (no tail jump) in C++, as in retail; the
   per-function file (src/lib/SFOLobby_Callback) matched these bytes with GCC */
extern "C" int SFOLobby_Callback_SetGameListFilter(void) {
    int tmp0;

    tmp0 = SFOLobby_IgnoreCallbacks();
    return tmp0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00446CA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00446CA0 */

/* merge_units: begin func_00446CC0 */
#pragma push /* merge_units */
/* Reply callback: flags gotReply208 (awaited by SFOLobby_UpdateStats). */
void SFOLobby_Callback_UpdateStats(void)
{
    if (!SFOLobby_IgnoreCallbacks())
        D_00585E60->gotReply208 = 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00446CC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00446CC0 */

/* merge_units: begin func_00446D00 */
#pragma push /* merge_units */
/* Reply to the own-IP request (SFOLobby_GetMyIP). */
typedef struct LobbyMyIpReply {
    char messageId[0x15];
    char ip[0x2C - 0x15];           /* 0x15 */
    int statusCode;                 /* 0x2C */
} LobbyMyIpReply;

/* Own-IP reply callback: flags gotMyIp and stores the address on success. */
void SFOLobby_Callback_GetMyIP(int a0, int a1, int a2, LobbyMyIpReply* info) {
    if (SFOLobby_IgnoreCallbacks() == 0) {
        D_00585E60->gotMyIp = 1;
        if (info->statusCode == MediusSuccess) {
            Libc_Strcpy(D_00585E60->myIp, info->ip);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00446D00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00446D00 */

/* merge_units: begin func_00446D60 */
#pragma push /* merge_units */
/* Reply callback: flags gotReply1D0 and keeps the 0x5C-byte reply in replyFD8. */
void SFOLobby_Callback_TextFilter(void* a0, void* a1, void* a2, void* data)
{
    if (SFOLobby_IgnoreCallbacks(a0, a1, a2) == 0) {
        D_00585E60->gotReply1D0 = 1;
        memcpy(D_00585E60->replyFD8, data, 0x5C);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00446D60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00446D60 */

/* merge_units: begin func_00446DB0 */
#pragma push /* merge_units */
/* Account-info reply callback (request SFOLobby_GetAgentDetails): flags gotAccountInfo and
 * keeps the reply. */
void SFOLobby_Callback_GetPlayerInfo(int a, int b, int c, void* data) {
    if (!SFOLobby_IgnoreCallbacks(a, b, c, data)) {
        D_00585E60->gotAccountInfo = 1;
        memcpy(&D_00585E60->accountInfoReply, data, 0x148);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00446DB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00446DB0 */

/* merge_units: begin func_00446E00 */
#pragma push /* merge_units */
/* Account-id-by-name reply callback (request SFOLobby_GetAgentID): flags gotAccountId
 * and keeps the reply. */
void SFOLobby_Callback_AccountGetID(void* a0, int a1, int a2, void* src) {
    if (SFOLobby_IgnoreCallbacks(a0, a1, a2, (int)src) == 0) {
        D_00585E60->gotAccountId = 1;
        memcpy(&D_00585E60->accountIdReply, src, 0x20);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00446E00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00446E00 */

/* merge_units: begin func_00446E50 */
#pragma push /* merge_units */
/* Reply callback: flags gotReply1B0 and keeps the 0x1C-byte reply in reply400. */
void SFOLobby_Callback_PickLocation(int a, int b, int c, void* src)
{
    if (!SFOLobby_IgnoreCallbacks(a, b, c)) {
        D_00585E60->gotReply1B0 = 1;
        memcpy(D_00585E60->reply400, src, 0x1C);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00446E50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00446E50 */

/* merge_units: begin func_00446EA0 */
#pragma push /* merge_units */
#pragma mpwc_relax on
#if 0 /* merge_units */
int SFOLobbyList_Append(LobbyArray *, int *);
#endif /* merge_units */
#define SFOLobbyList_Append(a0, a1) (SFOLobbyList_Append((a0), (void *)(a1))) /* merge_units */

/* Reply callback: flags gotReply1AC, appends {id, name} to lobbyList when the
 * record's +0x5C field is 0, and keeps the reply in reply39C. */
void SFOLobby_Callback_GetLocations(int d0, int d1, int d2, char * arg3) {
    struct { int f20; int f24[19]; } sl;
    int temp_v0;
    if (SFOLobby_IgnoreCallbacks() == 0) {
        D_00585E60->gotReply1AC = 1;
        temp_v0 = F_(arg3, 0x5C, int);
        if ((temp_v0 != 1) && (temp_v0 == 0)) {
            sl.f20 = F_(arg3, 0x18, int);
            Libc_Strcpy(sl.f24, arg3 + 0x1C);
            SFOLobbyList_Append(D_00585E60->lobbyList, &sl.f20);
        }
        memcpy(D_00585E60->reply39C, arg3, 0x64);
    }
}
#undef SFOLobbyList_Append /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00446EA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00446EA0 */

/* merge_units: begin func_00446F30 */
#pragma push /* merge_units */
/* Reply callback: flags gotReply200 and keeps the 0x64-byte reply in reply1BCC. */
void SFOLobby_Callback_ChannelInfo(int a, int b, int c, int msg) {
    if (!SFOLobby_IgnoreCallbacks(a, b, c, msg)) {
        D_00585E60->gotReply200 = 1;
        memcpy(D_00585E60->reply1BCC, msg, 100);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00446F30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00446F30 */

/* merge_units: begin func_00446F80 */
#pragma push /* merge_units */
/* Reply callback: flags gotReply1F8 and keeps the 0x20-byte reply in reply1B1C. */
void SFOLobby_Callback_CreateChannel(int a, int b, int c, const char* name)
{
    if (!SFOLobby_IgnoreCallbacks(a, b, c)) {
        D_00585E60->gotReply1F8 = 1;
        memcpy(D_00585E60->reply1B1C, name, 0x20);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00446F80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00446F80 */

/* merge_units: begin func_00446FD0 */
#pragma push /* merge_units */
/* Reply callback: flags gotReply1C0 and keeps the 0xB8-byte reply in reply9B0. */
void SFOLobby_Callback_JoinChannel(void* a, void* b, void* c, void* src) { if (!SFOLobby_IgnoreCallbacks(a, b, c, src)) { D_00585E60->gotReply1C0 = 1; memcpy(D_00585E60->reply9B0, src, 0xB8); } }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00446FD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00446FD0 */

/* merge_units: begin func_00447020 */
#pragma push /* merge_units */
/* Reply callback: flags gotReply1FC and keeps the 0x90-byte reply in reply1B3C. */
void SFOLobby_Callback_FindChannel(int a, int b, int c, void* src)
{
    if (SFOLobby_IgnoreCallbacks(a, b, c) == 0) {
        D_00585E60->gotReply1FC = 1;
        memcpy(D_00585E60->reply1B3C, src, 0x90);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00447020(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00447020 */

/* merge_units: begin func_00447070 */
#pragma push /* merge_units */
#pragma mpwc_relax on
#if 0 /* merge_units */
int SFOLobbyList_Append(LobbyArray *, char *);
#endif /* merge_units */
#define SFOLobbyList_Append(a0, a1) (SFOLobbyList_Append((a0), (void *)(a1))) /* merge_units */

/* Reply callback (second callback of SFOLobby_UniverseInformationRequest): flags gotReply1A0, appends a
 * LobbyUniverseEntry to universeList on success and keeps the 0x230-byte reply in reply18EC. */
void SFOLobby_Callback_UniverseStatusList(int d0, int d1, int d2, char * arg3) {
    struct { int f20[32]; int fA0[32]; int f120; int f124[64]; int f224; int f228; int f22C; } sl;
    int temp_v0;
    if (SFOLobby_IgnoreCallbacks() == 0) {
        D_00585E60->gotReply1A0 = 1;
        temp_v0 = F_(arg3, 0x18, int);
        if ((temp_v0 != 1) && (temp_v0 == 0)) {
            Libc_Strcpy(sl.f20, arg3 + 0x1C);
            Libc_Strcpy(sl.fA0, arg3 + 0x9C);
            Libc_Strcpy(sl.f124, arg3 + 0x120);
            sl.f120 = F_(arg3, 0x11C, int);
            sl.f224 = F_(arg3, 0x220, int);
            sl.f228 = F_(arg3, 0x224, int);
            sl.f22C = F_(arg3, 0x228, int);
            SFOLobbyList_Append(D_00585E60->universeList, sl.f20);
        }
        memcpy(D_00585E60->reply18EC, arg3, 0x230);
    }
}
#undef SFOLobbyList_Append /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00447070(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00447070 */

/* merge_units: begin func_00447130 */
#pragma push /* merge_units */
#pragma mpwc_relax on
#if 0 /* merge_units */
int SFOLobbyList_Append(LobbyArray *, char *);
#endif /* merge_units */
#define SFOLobbyList_Append(a0, a1) (SFOLobbyList_Append((a0), (void *)(a1))) /* merge_units */

/* Reply callback (first callback of SFOLobby_UniverseInformationRequest): flags gotReply19C, appends the
 * record's string to outList2404 on success and keeps the reply in reply17CC. */
void SFOLobby_Callback_UniverseNews(int d0, int d1, int d2, char * arg3) {
    int sp20[64];
    if (SFOLobby_IgnoreCallbacks() == 0) {
        D_00585E60->gotReply19C = 1;
        if (F_(arg3, 0x18, int) == 0) {
            Libc_Strcpy(sp20, arg3 + 0x1C);
            SFOLobbyList_Append(D_00585E60->outList2404, sp20);
        }
        memcpy(D_00585E60->reply17CC, arg3, 0x120);
    }
}
#undef SFOLobbyList_Append /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00447130(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00447130 */

/* merge_units: begin func_004471B0 */
#pragma push /* merge_units */
/* Reply callback (request SFOLobby_SessionBeginRequest): flags gotReply1A4 and keeps the 0x30-byte
 * reply in reply350. */
void SFOLobby_Callback_SessionBegin(void* a0, void* a1, void* a2, void* data)
{
    if (SFOLobby_IgnoreCallbacks(a0, a1, a2) == 0) {
        D_00585E60->gotReply1A4 = 1;
        memcpy(&D_00585E60->reply350, data, 0x30);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004471B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004471B0 */

/* merge_units: begin func_00447200 */
#pragma push /* merge_units */
#pragma cplusplus on
/* C++: Metrowerks keeps the call (no tail jump) in C++, as in retail; the
   per-function file (src/lib/SFOLobby_Callback) matched these bytes with GCC */
extern "C" int SFOLobby_Callback_ReassignGameMediusWorldID(void) {
    int tmp0;

    tmp0 = SFOLobby_IgnoreCallbacks();
    return tmp0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00447200(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00447200 */

/* merge_units: begin func_00447220 */
#pragma push /* merge_units */
/* Connect callback (SFOLobby_MediusConnectMUIS/SFOLobby_MediusConnectMAS/SFOLobby_MediusConnectMLS): flags gotConnect
 * and stores the connection handle when it is valid. */
void SFOLobby_Callback_MediusConnect(int handle) {
    if (SFOLobby_IgnoreCallbacks() == 0) {
        D_00585E60->gotConnect = 1;
        if (handle > 0) {
            D_00585E60->connHandle = handle;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00447220(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00447220 */

/* merge_units: begin func_00447270 */
#pragma push /* merge_units */
/* Reply callback: flags gotReply198 and keeps the reply in reply314. */
void SFOLobby_Callback_AccountRegistration(int a, int b, int c, void* data) {
    if (!SFOLobby_IgnoreCallbacks(a, b, c, data)) {
        D_00585E60->gotReply198 = 1;
        memcpy(&D_00585E60->reply314, data, 0x20);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00447270(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00447270 */

/* merge_units: begin func_004472C0 */
#pragma push /* merge_units */
typedef struct { int x; char s[0x3EC]; } E4472C0;
char D_004C0CD0[] = "{SFOLOBBY_SETTINGS}"; /* defined here: the unit's data (0x004C0CD0) */
extern int Libc_Strncmp(const char* a, const char* b, int n);
extern void SFOLobby_ParseConfigFile(SFOLobby* g, char* s, int n, int f);
#if 0 /* merge_units */
extern int SFOLobbyList_Append(LobbyArray* a, E4472C0* e);
#endif /* merge_units */
#define SFOLobbyList_Append(a0, a1) (SFOLobbyList_Append((a0), (void *)(a1))) /* merge_units */

#pragma opt_propagation off
/* Reply callback: flags gotReply1BC. A text record starting with
 * "{SFOLOBBY_SETTINGS}" is handed (without the prefix) to SFOLobby_ParseConfigFile; any other
 * record goes to outList2400. On error the end-of-list byte (+0x408) is forced. */
void SFOLobby_OnSettings(int d0, int d1, int d2, char* msg)
{
    if (SFOLobby_IgnoreCallbacks() == 0) {
        D_00585E60->gotReply1BC = 1;
        if (F_(msg, 0x18, int) != 0) {
            F_(msg, 0x408, char) = 1;
        } else {
            E4472C0 e;
            char* pfx;
            int n;
            e.x = F_(msg, 0x1C, int);
            Libc_Strcpy(e.s, msg + 0x20);
            pfx = D_004C0CD0;
            n = strlen(pfx);
            if (Libc_Strncmp(e.s, pfx, n) == 0) {
                SFOLobby_ParseConfigFile((SFOLobby*)D_00585E60, e.s + n, strlen(e.s) - n, 1);
            } else {
                SFOLobbyList_Append(D_00585E60->outList2400, &e);
            }
        }
        memcpy(D_00585E60->reply5A4, msg, 0x40C);
    }
}
#undef SFOLobbyList_Append /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004472C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004472C0 */

/* merge_units: begin func_004473C0 */
#pragma push /* merge_units */
#pragma mpwc_relax on
#if 0 /* merge_units */
int SFOLobbyList_Append(LobbyArray *, char * );
#endif /* merge_units */
#define SFOLobbyList_Append(a0, a1) (SFOLobbyList_Append((a0), (void *)(a1))) /* merge_units */

/* Reply callback: flags gotReply1B8 and files the record under outUsageList when
 * its first string is "USAGE", else under outList23FC. */
void SFOLobby_Callback_GetPolicy(int d0, int d1, int d2, char * arg3) {
    if (SFOLobby_IgnoreCallbacks() == 0) {
        D_00585E60->gotReply1B8 = 1;
        if (F_(arg3, 0x18, int) != 0) {
            F_(arg3, 0x11C, signed char) = 1;
        } else if (strcmp(arg3, "USAGE") == 0) {
            SFOLobbyList_Append(D_00585E60->outUsageList, arg3 + 0x1C);
        } else {
            SFOLobbyList_Append(D_00585E60->outList23FC, arg3 + 0x1C);
        }
        memcpy(D_00585E60->reply484, arg3, 0x120);
    }
}
#undef SFOLobbyList_Append /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004473C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004473C0 */

/* merge_units: begin func_00447470 */
#pragma push /* merge_units */
/* Reply callback (request SFOLobby_SessionEndRequest): flags gotReply1A8 and keeps the reply. */
void SFOLobby_Callback_SessionEnd(void* a0, int a1, int a2, void* src) {
    if (SFOLobby_IgnoreCallbacks(a0, a1, a2, (int)src) == 0) {
        D_00585E60->gotReply1A8 = 1;
        memcpy(&D_00585E60->reply380, src, 0x1C);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00447470(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00447470 */

/* merge_units: begin func_004474C0 */
#pragma push /* merge_units */
extern char D_004C0CB0; /* "SFOLobby_Callback.cc" */
/* Reply callback: flags gotReply190 and reports server-side failures as error 1. */
void SFOLobby_Callback_AccountLogout(int d0, int d1, int d2, LobbyReply *src) {
    if (SFOLobby_IgnoreCallbacks() == 0) {
        int e;
        D_00585E60->gotReply190 = 1;
        e = src->statusCode;
        switch (e) {
        case MediusSuccess:
            break;
        case MediusPlayerNotPrivileged:
            SFOLobby_SetError(D_00585E60, 1, &D_004C0CB0, 0x351);
            break;
        case MediusDMEError:
            SFOLobby_SetError(D_00585E60, 1, &D_004C0CB0, 0x35C);
            break;
        case MediusDBError:
            SFOLobby_SetError(D_00585E60, 1, &D_004C0CB0, 0x367);
            break;
        case MediusWMError:
            SFOLobby_SetError(D_00585E60, 1, &D_004C0CB0, 0x372);
            break;
        default:
            if (e < 0) SFOLobby_SetError(D_00585E60, 1, &D_004C0CB0, 0x379);
            break;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004474C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004474C0 */

/* merge_units: begin func_004475E0 */
#pragma push /* merge_units */
/* Login reply callback: flags gotLogin, maps the Medius status to a lobby error
 * (0x3A bad password, 0x3B unknown account, 0x3C already logged in, else 1),
 * stores the account id and keeps the reply. */
void SFOLobby_Callback_AccountLogin(int d0, int d1, int d2, LobbyLoginReply *src) {
    if (SFOLobby_IgnoreCallbacks() == 0) {
        D_00585E60->gotLogin = 1;
        switch (src->statusCode) {
        case MediusSuccess:
            break;
        case MediusInvalidPassword:
            SFOLobby_SetError(D_00585E60, 0x3A, &D_004C0CB0, 0x2D0);
            break;
        case MediusAccountNotFound:
            SFOLobby_SetError(D_00585E60, 0x3B, &D_004C0CB0, 0x2E0);
            break;
        case MediusPlayerNotPrivileged:
            SFOLobby_SetError(D_00585E60, 1, &D_004C0CB0, 0x2EB);
            break;
        case MediusAccountLoggedIn:
            SFOLobby_SetError(D_00585E60, 0x3C, &D_004C0CB0, 0x2F6);
            break;
        case MediusDMEError:
            SFOLobby_SetError(D_00585E60, 1, &D_004C0CB0, 0x301);
            break;
        case MediusDBError:
            SFOLobby_SetError(D_00585E60, 1, &D_004C0CB0, 0x30C);
            break;
        case MediusWMError:
            SFOLobby_SetError(D_00585E60, 1, &D_004C0CB0, 0x317);
            break;
        }
        D_00585E60->accountId = src->accountId;
        memcpy(&D_00585E60->loginReply, src, 0xC4);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004475E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004475E0 */
