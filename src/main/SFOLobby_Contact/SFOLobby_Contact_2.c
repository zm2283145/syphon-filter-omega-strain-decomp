/*
 * main/SFOLobby_Contact: 2 files, 0044DB60-0044DD20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0044DB60 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "SFOLobby.h"
extern "C" {
extern char D_004C0ED0; /* "SFOLobby_Contact.cc" */
extern char D_004C0EC0; /* "1" (message id) */
int Lobby_GetTime(...);
void SFOLobby_RequestBuddyList(SFOLobby* self, int a);
int func_00450A90(LobbyArray* list, int id, int a);
int SFOLobby_RequestAccountInfo(SFOLobby* self, int id);
int SFOLobby_SetError(SFOLobby* self, int code, char* file, int line);
void* memset(void* d, int c, unsigned int n);
void String_Copy(char* d, char* s);
char* strncpy(char* d, const char* s, unsigned int n);
int func_0046A5F0(void* req, void* cb);
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
    if (func_00450A90(&self->pool150, id, 0)) return true;
    return func_00450A90(&self->buddyList, id, 0) != 0;
}

/* Adds account `id` as a buddy (func_0046A5F0, MediusAddBuddy-style request with
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
    self->requestResult = func_0046A5F0(&req, func_004466B0);
    if (self->requestResult) {
        SFOLobby_SetError(self, 1, &D_004C0ED0, 0x104);
        return 0;
    }
    SFOLobby_SetError(self, 0, &D_004C0ED0, 0x126);
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_0044DB60 */

/* merge_units: begin func_0044DD20 */
#pragma push /* merge_units */
extern void func_00452FC0(SFOLobby*, int);
extern void LobbyArray_Free(LobbyArray*);

/* Leaves the CONTACTS state (6; state 10 is left unchanged), releasing the
 * caller-supplied lists set up by SFOLobby_EnterContactsState. */
void SFOLobby_LeaveContactsState(SFOLobby* s)
{
    int st = s->state;
    if (st == SFOLOBBY_STATE_IDLE) return;
    if (st == SFOLOBBY_STATE_CONTACTS || st == SFOLOBBY_STATE_10) {
        if (st != SFOLOBBY_STATE_10) s->state = SFOLOBBY_STATE_IDLE;
        func_00452FC0(s, 0);
        if (s->outList23EC) LobbyArray_Free(s->outList23EC);
        s->outList23EC = 0;
        if (s->outBuddyList) LobbyArray_Free(s->outBuddyList);
        s->outBuddyList = 0;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0044DD20 */
