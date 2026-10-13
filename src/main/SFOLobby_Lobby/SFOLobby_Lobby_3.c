/*
 * main/SFOLobby_Lobby: 5 files, 00450EF0-00451200
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00450EF0 */
#pragma push /* merge_units */
#include "SFOLobby.h"
extern int LobbyArray_At(LobbyArray*);
/* Element of array38 (0 when empty). */
int func_00450EF0(SFOLobby* p) {
    /* .set reorder barrier keeps the empty then-arm */
    if (p->array38.count == 0) { asm { .set reorder } return 0; }
    return LobbyArray_At(&p->array38);
}
#pragma pop /* merge_units */
/* merge_units: end func_00450EF0 */

/* merge_units: begin func_00450F30 */
#pragma push /* merge_units */
#pragma mpwc_relax on
/* inbox element (0xAC bytes). */
typedef struct {
    int type;                       /* 0 game invite, 1 other request */
    int f4;
    int id;
} InboxEntry_450F30;
int func_00446560(SFOLobby * , InboxEntry_450F30 * , int);
int func_00449360(SFOLobby * , int, int, char *);
#if 0 /* merge_units */
InboxEntry_450F30 * LobbyArray_At(LobbyArray * );
#endif /* merge_units */
#define LobbyArray_At(a0) ((InboxEntry_450F30 *)LobbyArray_At((a0))) /* merge_units */

int LobbyArray_RemoveAt(LobbyArray * , int);
/* Answers inbox entry index (accept when accept != 0) and removes it. */
int func_00450F30(SFOLobby * self, int index, int accept) {
    int type;
    InboxEntry_450F30 * e;
    if (index < self->inbox.count) {
        e = LobbyArray_At(&self->inbox);
        type = e->type;
        switch (type) {
        case 0:
            if (accept != 0) {
                func_00449360(self, e->id, 1, "Accept");
            } else {
                func_00449360(self, e->id, 2, "Decline");
            }
            break;
        case 1:
            func_00446560(self, e, accept);
            break;
        }
        LobbyArray_RemoveAt(&self->inbox, index);
    }
    return 1;
}
#undef LobbyArray_At /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00450F30 */

/* merge_units: begin func_00451010 */
#pragma push /* merge_units */
/* Element of inbox (0 when empty). */
int func_00451010(SFOLobby* p) {
    /* .set reorder barrier keeps the empty then-arm */
    if (p->inbox.count == 0) { asm { .set reorder } return 0; }
    return LobbyArray_At(&p->inbox);
}
#pragma pop /* merge_units */
/* merge_units: end func_00451010 */

/* merge_units: begin func_00451050 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
void* memset(void*, int, unsigned int);
int strlen(const char*);
char* strncpy(char*, const char*, int);
int sprintf(char*, const char*, ...);
void String_Copy(char*, const char*);
int func_00469990(void*, void*);
int func_0046A378(void*);
void func_00447BB0(void);
void SFOLobby_SetError(SFOLobby*, int, char*, int);
extern char D_004C0F68[];           /* "1" */
extern char D_004C0F70[];           /* "SFOLobby_Lobby.cc" */
extern char D_004C0F98[];           /* "%d" */
}
struct ConnReq_451050 {
    char messageId[0x15];
    char sessionKey[0x13];
    int port;
    char name[0x40];
};
struct JoinReq_451050 {
    char messageId[0x15];
    char sessionKey[0x13];
    int flag;
    int id;
    char name[0x40];
};
/* Sends a request named name (reply callback func_00447BB0, message id = id);
 * when id is not the own account also sends the follow-up (func_0046A378).
 * Requires outList23EC. */
extern "C" int func_00451050(SFOLobby* self, char* name, int id) {
    ConnReq_451050 req;
    JoinReq_451050 join;
    if (self->outList23EC == 0) {
        SFOLobby_SetError(self, 0x24, D_004C0F70, 0x187);
        return 0;
    }
    if (!name || !strlen(name)) return 0;
    strlen(name);
    memset(&req, 0, sizeof(req));
    req.port = 1;
    sprintf(req.messageId, D_004C0F98, id);
    strncpy(req.sessionKey, self->sessionKey, 0x11);
    strncpy(req.name, name, 0x40);
    self->requestResult = func_00469990(&req, (void*)func_00447BB0);
    if (self->requestResult != 0) {
        SFOLobby_SetError(self, 1, D_004C0F70, 0x19E);
        return 0;
    }
    if (id != self->accountId) {
        memset(&join, 0, sizeof(join));
        String_Copy(join.messageId, D_004C0F68);
        strncpy(join.sessionKey, self->sessionKey, 0x11);
        strncpy(join.name, name, 0x40);
        { enum { OFF, ON } e = id == 0 ? OFF : ON; join.flag = e; }
        join.id = id;
        self->requestResult = func_0046A378(&join);
        if (self->requestResult != 0) {
            SFOLobby_SetError(self, 1, D_004C0F70, 0x1B1);
            return 0;
        }
    }
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_00451050 */

/* merge_units: begin func_00451200 */
#pragma push /* merge_units */
extern int D_00497890;              /* reply timeout */
extern char func_00446DB0[];
extern int Lobby_GetTime(void);
#if 0 /* merge_units */
extern void String_Copy(char*, char*);
#endif /* merge_units */
#define String_Copy(a0, a1) (String_Copy((a0), (const char *)(a1))) /* merge_units */

extern char* strncpy(char*, const char*, int);
extern int func_0046A048(void*, void*);
extern void SFOLobby_SetError(SFOLobby*, int, char*, int);
extern void SFOLobby_CallUpdateHook(SFOLobby*, int, int);
extern int SFOLobby_Poll(SFOLobby*, int, int, int);
extern void SFOLobby_CacheAccount(SFOLobby*, int, char*, int, int);
#if 0 /* merge_units */
extern void* memset(void*, int, int);
#endif /* merge_units */
#define memset(a0, a1, a2) (memset((a0), (a1), (unsigned int)(a2))) /* merge_units */

/* Asks the server for an account's info (reply callback func_00446DB0 fills
 * accountInfoReply), waits for it and stores it in the account cache. */
int SFOLobby_RequestAccountInfo(SFOLobby* s, int id)
{
    struct { char messageId[0x15]; char sessionKey[0x13]; int accountId; } req;
    int t;
    if (id < 0) {
        SFOLobby_SetError(s, 0x1D, D_004C0F70, 0x14C);
        return 0;
    }
    memset(&req, 0, sizeof(req));
    String_Copy(req.messageId, D_004C0F68);
    strncpy(req.sessionKey, s->sessionKey, 0x11);
    req.accountId = id;
    s->requestResult = func_0046A048(&req, func_00446DB0);
    if (s->requestResult != 0) {
        SFOLobby_SetError(s, 1, D_004C0F70, 0x15A);
        return 0;
    }
    t = Lobby_GetTime();
    s->gotAccountInfo = 0;
    while (s->gotAccountInfo == 0) {
        SFOLobby_CallUpdateHook(s, 0, 0);
        if (SFOLobby_Poll(s, t, D_00497890, 0) == 0) {
            SFOLobby_SetError(s, 2, D_004C0F70, 0x168);
            return 0;
        }
    }
    SFOLobby_CacheAccount(s, id, s->accountInfoReply.accountName, s->accountInfoReply.info.ip,
                  (int)&s->accountInfoReply.info);
    return 1;
}
#undef String_Copy /* merge_units */
#undef memset /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00451200 */
