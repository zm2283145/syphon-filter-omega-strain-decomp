/*
 * main/SFOLobby_Contact: SFOLobby_Contact.cc (6 files, 0044D860-0044DDC0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* library prototypes shared by the blocks below (C linkage) */
void *memset(void *, int, int);
int sprintf(void *, const void *, ...);
char *strncpy(void *, const void *, int);

/* merge_units: begin func_0044D860 */
#pragma push /* merge_units */
#include "SFOLobby.h"
extern void String_Copy(char*, char*);
extern int Lobby_GetTime(void);
extern int SFOLobby_SetError(SFOLobby*, int, char*, int);
extern void SFOLobby_CallUpdateHook(SFOLobby*, int, int);
extern int SFOLobby_Poll(SFOLobby*, int, int, int);
extern int MediusGetBuddyList_ExtraInfo(void*, void*);
extern void LobbyArray_Clear(LobbyArray*);
extern void LobbyArray_SetRefreshing(LobbyArray*, int);
extern int D_00497890;     /* request timeout */
extern char D_004C0EC0[];  /* "1" (message id) */
extern char D_004C0ED0[];  /* "SFOLobby_Contact.cc" */
extern char SFOLobby_Callback_GetBuddyList[];

/* Requests the buddy list (MediusGetBuddyList_ExtraInfo, reply callback SFOLobby_Callback_GetBuddyList refills
 * buddyList); with `wait` set, blocks until the last record arrives. */
int SFOLobby_RequestBuddyList(SFOLobby* s, int wait)
{
    char messageId[0x15];

    memset(&s->buddyListReply, 0, 0xD0);
    s->buddyListReply.accountId = -1;
    memset(messageId, 0, sizeof(messageId));
    String_Copy(messageId, D_004C0EC0);
    s->requestResult = MediusGetBuddyList_ExtraInfo(messageId, SFOLobby_Callback_GetBuddyList);
    if (s->requestResult != 0) {
        return 0;
    }
    LobbyArray_Clear(&s->buddyList);
    LobbyArray_SetRefreshing(&s->buddyList, 1);
    if (wait) {
        while (s->buddyListReply.endOfList != 1) {
            SFOLobby_CallUpdateHook(s, 0, 0);
            if (s->requestResult != 0) {
                SFOLobby_SetError(s, 1, D_004C0ED0, 0x1A7);
                s->busy = 0;
                return 0;
            }
            if (SFOLobby_Poll(s, s->waitStart, D_00497890, 0) == 0) {
                SFOLobby_SetError(s, 2, D_004C0ED0, 0x1AF);
                s->busy = 0;
                return 0;
            }
        }
    }
    s->buddyListTime = Lobby_GetTime();
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_0044D860 */

/* merge_units: begin func_0044D9C0 */
#pragma push /* merge_units */
typedef struct {
    char messageId[0x15];
    char sessionKey[0x13];
    int accountId;
} R44D9;
extern int MediusRemoveFromBuddyList(R44D9*, void*);
extern void SFOLobby_Callback_RemoveFromBuddyList();

/* Sends a buddy request for `accountId` (MediusRemoveFromBuddyList, probably MediusRemoveBuddy)
 * and waits for its status reply (SFOLobby_Callback_RemoveFromBuddyList -> reply238Ok). */
int func_0044D9C0(SFOLobby* o, int accountId) {
    R44D9 rec;
    if (accountId < 0) {
        SFOLobby_SetError(o, 0x29, D_004C0ED0, 0x14C);
        return 1;
    }
    memset(&rec, 0, 0x2C);
    String_Copy(rec.messageId, D_004C0EC0);
    strncpy(rec.sessionKey, o->sessionKey, 0x11);
    rec.accountId = accountId;
    o->requestResult = MediusRemoveFromBuddyList(&rec, SFOLobby_Callback_RemoveFromBuddyList);
    if (o->requestResult) {
        SFOLobby_SetError(o, 1, D_004C0ED0, 0x15A);
        return 0;
    }
    accountId = Lobby_GetTime();
    o->gotReply238 = 0;
    o->busy = 1;
    while (o->gotReply238 == 0) {
        SFOLobby_CallUpdateHook(o, 0, 0);
        if (!SFOLobby_Poll(o, accountId, D_00497890, 0)) {
            o->busy = 0;
            SFOLobby_SetError(o, 2, D_004C0ED0, 0x16A);
            return 0;
        }
    }
    o->busy = 0;
    o->buddyListTime = 0;
    if (!o->reply238Ok) {
        SFOLobby_SetError(o, 0x29, D_004C0ED0, 0x175);
        return 0;
    }
    SFOLobby_SetError(o, 0, D_004C0ED0, 0x17B);
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_0044D9C0 */

/* merge_units: begin func_0044DB60 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
#if 0 /* merge_units */
extern char D_004C0ED0; /* "SFOLobby_Contact.cc" */
#endif /* merge_units */
#define D_004C0ED0 (*(char*)&D_004C0ED0) /* merge_units */

#if 0 /* merge_units */
extern char D_004C0EC0; /* "1" (message id) */
#endif /* merge_units */
#define D_004C0EC0 (*(char*)&D_004C0EC0) /* merge_units */

#if 0 /* merge_units */
int SFOLobby_RequestBuddyList(SFOLobby* self, int a);
#endif /* merge_units */
#define SFOLobby_RequestBuddyList(a0, a1) (SFOLobby_RequestBuddyList((a0), (a1))) /* merge_units */

int SFOLobby_FindAgent(LobbyArray* list, int id, int a);
int SFOLobby_RequestAccountInfo(SFOLobby* self, int id);
#if 0 /* merge_units */
int SFOLobby_SetError(SFOLobby* self, int code, char* file, int line);
#endif /* merge_units */
#define SFOLobby_SetError(a0, a1, a2, a3) (SFOLobby_SetError((a0), (a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
void String_Copy(char* d, char* s);
#endif /* merge_units */
#define String_Copy(a0, a1) (String_Copy((a0), (a1))) /* merge_units */

int MediusBuddyGetPermission(void* req, void* cb);
void func_004466B0(void);
}

struct Req_44DB60 {
    char messageId[0x15];
    char sessionKey[0x13];
    int accountId;
    int addType;
};

static inline bool Has_44DB60(SFOLobby* self, int id)
{
    if (SFOLobby_FindAgent(&self->pool150, id, 0)) return true;
    return SFOLobby_FindAgent(&self->buddyList, id, 0) != 0;
}

/* Adds account `id` as a buddy (MediusBuddyGetPermission, MediusAddBuddy-style request with
 * add type 1) after checking it is not ourselves or already a buddy, and after
 * fetching its account info (SFOLobby_RequestAccountInfo). */
extern "C" int SFOLobby_AddBuddy(SFOLobby* self, int id)
{
    Req_44DB60 req;
    bool found;

    if (id < 0) {
        SFOLobby_SetError(self, 0x1D, &D_004C0ED0, 0xD0);
        return 0;
    }
    if (id == self->accountId) {
        SFOLobby_SetError(self, 0x25, &D_004C0ED0, 0xD6);
        return 0;
    }
    Lobby_GetTime();
    SFOLobby_RequestBuddyList(self, 1);
    self->buddyListTime = Lobby_GetTime();
    found = Has_44DB60(self, id);
    if (found) {
        SFOLobby_SetError(self, 0x1E, &D_004C0ED0, 0xDD);
        return 0;
    }
    if (!SFOLobby_RequestAccountInfo(self, id)) {
        SFOLobby_SetError(self, 1, &D_004C0ED0, 0xE5);
        return 0;
    }
    memset(&req, 0, sizeof(req));
    String_Copy(req.messageId, &D_004C0EC0);
    strncpy(req.sessionKey, self->sessionKey, 0x11);
    req.addType = 1;
    req.accountId = id;
    self->requestResult = MediusBuddyGetPermission(&req, func_004466B0);
    if (self->requestResult) {
        SFOLobby_SetError(self, 1, &D_004C0ED0, 0x104);
        return 0;
    }
    SFOLobby_SetError(self, 0, &D_004C0ED0, 0x126);
    return 1;
}
#undef D_004C0ED0 /* merge_units */
#undef D_004C0EC0 /* merge_units */
#undef SFOLobby_RequestBuddyList /* merge_units */
#undef SFOLobby_SetError /* merge_units */
#undef String_Copy /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044DB60 */

/* merge_units: begin func_0044DD20 */
#pragma push /* merge_units */
extern void SFOLobby_SetCallback(); /* (SFOLobby *, int); SFOLobby_EnterContactsState passes only the first argument */
extern void LobbyArray_Free(LobbyArray*);

/* Leaves the CONTACTS state (6; state 10 is left unchanged), releasing the
 * caller-supplied lists set up by SFOLobby_EnterContactsState. */
void SFOLobby_LeaveContactsState(SFOLobby* s)
{
    int st = s->state;
    if (st == SFOLOBBY_STATE_IDLE) return;
    if (st == SFOLOBBY_STATE_CONTACTS || st == SFOLOBBY_STATE_10) {
        if (st != SFOLOBBY_STATE_10) s->state = SFOLOBBY_STATE_IDLE;
        SFOLobby_SetCallback(s, 0);
        if (s->outList23EC) LobbyArray_Free(s->outList23EC);
        s->outList23EC = 0;
        if (s->outBuddyList) LobbyArray_Free(s->outBuddyList);
        s->outBuddyList = 0;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0044DD20 */

/* merge_units: begin func_0044DDC0 */
#pragma push /* merge_units */
#pragma opt_propagation off
#pragma cplusplus on
extern "C" {
extern int D_004977B8;  /* buddy list refresh interval */
extern int D_004977D0;  /* buddy info refresh interval */
extern char D_004C0EE8; /* "%d" */
int Lobby_GetTime(void);
#if 0 /* merge_units */
int SFOLobby_RequestBuddyList(SFOLobby* self, int a);
#endif /* merge_units */
#define SFOLobby_RequestBuddyList(a0, a1) (SFOLobby_RequestBuddyList((a0), (a1))) /* merge_units */

void SFOLobby_CellUpdateClanInvitations(SFOLobby* self);
void func_00451B30(SFOLobby* self);
void SFOLobby_PingIntel(SFOLobby* self, LobbyArray* list);
void SFOLobby_CollectGameInfo(SFOLobby* self, LobbyArray* list);
int LobbyArray_GetRefreshing(LobbyArray* list);
LobbyBuddyEntry* LobbyArray_At(LobbyArray* list, int i);
void SFOLobby_CellUpdateMemberList(SFOLobby* self, int a);
int MediusGetPlayerInfo(void* req, void* cb);
void SFOLobby_Callback_GetPlayerInfo_ForBuddyList(void);
}

struct Req_44DDC0 {
    char messageId[0x15];
    char sessionKey[0x13];
    int accountId;
};

/* Per-frame update of the CONTACTS state (6): periodically re-requests the buddy
 * list, and every D_004977D0 ms asks for fresh info (MediusGetPlayerInfo, callback
 * SFOLobby_Callback_GetPlayerInfo_ForBuddyList) on each buddy that is online. */
extern "C" void SFOLobby_UpdateContacts(SFOLobby* me)
{
    SFOLobby* self;
    int now;
    int last;
    LobbyArray* list;
    int d;
    Req_44DDC0 req;
    int i;
    LobbyBuddyEntry* item;
    self = me;
    if (self->state == SFOLOBBY_STATE_CONTACTS && !self->inUpdateHook) {
        last = self->buddyListTime;
        d = Lobby_GetTime() - last;
        if (!last || d > D_004977B8) {
            SFOLobby_RequestBuddyList(self, 0);
            self->buddyListTime = Lobby_GetTime();
        }
        SFOLobby_CellUpdateClanInvitations(self);
        func_00451B30(self);
        SFOLobby_PingIntel(self, &self->buddyList);
        SFOLobby_CollectGameInfo(self, &self->buddyList);
        now = Lobby_GetTime();
        list = &self->buddyList;
        if (now - self->buddyInfoTime > D_004977D0 && !(unsigned char)LobbyArray_GetRefreshing(list)) {
            self->buddyInfoTime = now;
            i = 0;
            if (0 < list->count) {
                do {
                item = LobbyArray_At(list, i);
                if (item->location != 3) {
                    memset(&req, 0, sizeof(req));
                    sprintf(req.messageId, &D_004C0EE8, item->accountId);
                    strncpy(req.sessionKey, self->sessionKey, 0x11);
                    req.accountId = item->accountId;
                    MediusGetPlayerInfo(&req, SFOLobby_Callback_GetPlayerInfo_ForBuddyList);
                }
                    i++;
                } while (i < list->count);
            }
        }
        SFOLobby_CellUpdateMemberList(self, 0);
    }
}
#undef SFOLobby_RequestBuddyList /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044DDC0 */

/* merge_units: begin func_0044DF80 */
#pragma push /* merge_units */
extern void SFOLobby_SetCallback();
extern void LobbyArray_Init(LobbyArray*, int, int, int);
#if 0 /* merge_units */
extern int SFOLobby_RequestBuddyList(SFOLobby*, int);
#endif /* merge_units */
#define SFOLobby_RequestBuddyList(a0, a1) (SFOLobby_RequestBuddyList((a0), (a1))) /* merge_units */

#pragma push
/* Enters the CONTACTS state (6) from IDLE/initial with the caller-supplied
 * output lists, then requests the buddy list. */
int SFOLobby_EnterContactsState(SFOLobby* s, int unused, LobbyArray* list23EC, LobbyArray* buddies)
{
    if (s->state != SFOLOBBY_STATE_IDLE && s->state != SFOLOBBY_STATE_0) {
        SFOLobby_SetError(s, 1, D_004C0ED0, 0x21);
        return 0;
    }
    s->state = SFOLOBBY_STATE_CONTACTS;
    SFOLobby_SetCallback(s);
    s->outList23EC = list23EC;
    s->outBuddyList = buddies;
    LobbyArray_Init(s->outList23EC, s->unk1EA4, 0, 0x68);
    LobbyArray_Init(s->outBuddyList, 0x40, 0x20, sizeof(LobbyBuddyEntry));
    s->buddyListTime = 0;
    s->buddyInfoTime = 0;
    SFOLobby_RequestBuddyList(s, 0);
    SFOLobby_SetError(s, 0, D_004C0ED0, 0x3C);
    return 1;
}
#pragma pop
#undef SFOLobby_RequestBuddyList /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044DF80 */
