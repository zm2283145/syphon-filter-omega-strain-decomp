/*
 * main/SFOLobby_Contact: 2 files, 0044D860-0044D9C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin SFOLobby_RequestBuddyList */
#pragma push /* merge_units */
#include "SFOLobby.h"
extern void String_Copy(char*, char*);
extern int Lobby_GetTime(void);
extern void SFOLobby_SetError(SFOLobby*, int, char*, int);
extern void SFOLobby_CallUpdateHook(SFOLobby*, int, int);
extern int SFOLobby_Poll(SFOLobby*, int, int, int);
extern int func_0046C170(void*, void*);
extern void LobbyArray_Clear(LobbyArray*);
extern void LobbyArray_SetRefreshing(LobbyArray*, int);
extern void* memset(void*, int, int);
extern int D_00497890;     /* request timeout */
extern char D_004C0EC0[];  /* "1" (message id) */
extern char D_004C0ED0[];  /* "SFOLobby_Contact.cc" */
extern char func_00446830[];

/* Requests the buddy list (func_0046C170, reply callback func_00446830 refills
 * buddyList); with `wait` set, blocks until the last record arrives. */
int SFOLobby_RequestBuddyList(SFOLobby* s, int wait)
{
    char messageId[0x15];

    memset(&s->buddyListReply, 0, 0xD0);
    s->buddyListReply.accountId = -1;
    memset(messageId, 0, sizeof(messageId));
    String_Copy(messageId, D_004C0EC0);
    s->requestResult = func_0046C170(messageId, func_00446830);
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
/* merge_units: end SFOLobby_RequestBuddyList */

/* merge_units: begin func_0044D9C0 */
#pragma push /* merge_units */
typedef struct {
    char messageId[0x15];
    char sessionKey[0x13];
    int accountId;
} R44D9;
extern char* strncpy(char*, const char*, int);
extern int func_0046A550(R44D9*, void*);
extern void func_004466F0();

/* Sends a buddy request for `accountId` (func_0046A550, probably MediusRemoveBuddy)
 * and waits for its status reply (func_004466F0 -> reply238Ok). */
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
    o->requestResult = func_0046A550(&rec, func_004466F0);
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
