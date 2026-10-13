/*
 * main/SFOLobby_Lobby: 4 files, 00451370-004516E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin SFOLobby_LookupAccountId */
#pragma push /* merge_units */
#include "SFOLobby.h"
/* self as char* is needed for matching (an SFOLobby* parameter changes codegen). */
#define SELF ((SFOLobby*)o)
extern unsigned int strlen(const char*);
extern int strcmp(const char*, const char*);
extern char* strncpy(char*, const char*, int);
extern void* memset(void*, int, int);
extern char* String_Copy(char*, const char*);
extern void SFOLobby_SetError(char*, int, char*, int);
extern int* LobbyArray_At(char*, int);
extern int func_0046B140(void*, void*);
extern void func_00446E00(void);  /* reply callback, fills accountIdReply */
extern int Lobby_GetTime(void);
extern void SFOLobby_CallUpdateHook(char*, int, int);
extern int SFOLobby_Poll(char*, int, int, int);
extern char D_004C0F68[];           /* "1" */
extern char D_004C0F70[];           /* "SFOLobby_Lobby.cc" */
extern int D_00497890;              /* reply timeout */
static inline int* Find(char* o, char* name) {
    int n = SELF->accountCache.count;
    int i;
    for (i = 0; i < n; i++) {
        int* e = LobbyArray_At(o + 0xFC /* &accountCache */, i);
        if (strcmp(name, (char*)(e + 1)) == 0) return e;
    }
    return 0;
}

typedef struct {
    char messageId[0x15];
    char sessionKey[0x11];
    char accountName[0x20];
} Req;

/* Account id for an account name: from the account cache, else by asking the
 * server (fills accountIdReply). -1 on error. */
int SFOLobby_LookupAccountId(char* o, char* name) {
    int st;
    int i;
    int n;
    int* e;
    int h;
    Req r;

    st = SELF->state;
    if (st != 5 && st != 6 && st != 7) {
        SFOLobby_SetError(o, 0x23, D_004C0F70, 0x101);
        return -1;
    }
    if (name == 0 || *name == 0 || strlen(name) > 0x1F) {
        SFOLobby_SetError(o, 0x22, D_004C0F70, 0x108);
        return -1;
    }
    e = Find(o, name);
    if (e != 0) {
        return *e;
    }
    memset(&r, 0, sizeof(r));
    String_Copy(r.messageId, D_004C0F68);
    strncpy(r.sessionKey, SELF->sessionKey, 0x11);
    strncpy(r.accountName, name, 0x1F);
    SELF->requestResult = func_0046B140(&r, func_00446E00);
    if (*(int*)(o + 0x248 + 4) /* requestResult */ != 0) {
        SFOLobby_SetError(o, 1, D_004C0F70, 0x11B);
        return -1;
    }
    h = Lobby_GetTime();
    SELF->gotAccountId = 0;
    while (*(int*)(o + 0x1C0 + 4) /* gotAccountId */ == 0) {
        SFOLobby_CallUpdateHook(o, 0, 0);
        if (SFOLobby_Poll(o, h, D_00497890, 0) == 0) {
            SFOLobby_SetError(o, 2, D_004C0F70, 0x129);
            return -1;
        }
    }
    if (SELF->accountIdReply.statusCode != 0) {
        SFOLobby_SetError(o, 0x1D, D_004C0F70, 0x130);
        return -1;
    }
    SFOLobby_SetError(o, 0, D_004C0F70, 0x135);
    return SELF->accountIdReply.accountId;
}
#pragma pop /* merge_units */
/* merge_units: end SFOLobby_LookupAccountId */

/* merge_units: begin func_004515F0 */
#pragma push /* merge_units */
/* Sets the lobby mode (which list func_004516E0 refreshes). */
void func_004515F0(SFOLobby* o, int value) {
    if (value != o->mode) o->mode = value;
}
#pragma pop /* merge_units */
/* merge_units: end func_004515F0 */

/* merge_units: begin func_00451610 */
#pragma push /* merge_units */
extern void func_00452FC0(SFOLobby* self, int x);
extern void LobbyArray_Free(LobbyArray* p);
/* Shuts the lobby down from states 0, 5 and 10 (state becomes 9 unless it was 10)
 * and frees the caller lists and the lobby arrays. */
void func_00451610(SFOLobby* self)
{
    if (self->state == SFOLOBBY_STATE_IDLE) return;
    if (self->state == 5 || self->state == 0 || self->state == 10) {
        if (self->state != 10) {
            self->state = SFOLOBBY_STATE_IDLE;
        }
        func_00452FC0(self, 0);
        if (self->outList23EC) {
            LobbyArray_Free(self->outList23EC);
        }
        self->outList23EC = 0;
        if (self->outList23F4) {
            LobbyArray_Free(self->outList23F4);
        }
        self->outList23F4 = 0;
        if (self->outList23F0) {
            LobbyArray_Free(self->outList23F0);
        }
        self->outList23F0 = 0;
        LobbyArray_Free(&self->list8C);
        LobbyArray_Free(&self->listA8);
        LobbyArray_Free(&self->array00);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00451610 */

/* merge_units: begin func_004516E0 */
#pragma push /* merge_units */
typedef struct { char messageId[0x18]; int id; } Req_4516E0;
#if 0 /* merge_units */
extern void* memset(void*, int, unsigned int);
#endif /* merge_units */
#define memset(a0, a1, a2) (memset((a0), (a1), (int)(a2))) /* merge_units */

#if 0 /* merge_units */
extern void String_Copy(char*, const char*);
#endif /* merge_units */
#define String_Copy(a0, a1) ((void)String_Copy((a0), (a1))) /* merge_units */

extern int func_0046C290(Req_4516E0* a, void* b);
extern void func_00447A30(void);
extern void LobbyArray_Clear(LobbyArray*);
extern void LobbyArray_SetRefreshing(LobbyArray*, int);
extern void LobbyArray_SetDirty(LobbyArray*, int);
extern void func_00450B30(SFOLobby*);
extern void func_00453FA0(SFOLobby*, void*);
extern void func_004498C0(SFOLobby*);
extern void func_0044D700(SFOLobby*, int);
extern void func_00449800(SFOLobby*, int);
extern void func_00451B30(SFOLobby*);
extern int D_00497788;              /* list8C refresh interval */
/* Re-requests list8C (reply callback func_00447A30) once the interval has passed. */
static inline void Tick_4516E0(SFOLobby* self) {
    if (Lobby_GetTime() - self->list8CTime > D_00497788) {
        Req_4516E0 r;
        memset(&r, 0, sizeof(r));
        String_Copy(r.messageId, D_004C0F68);
        r.id = self->list8CId;
        self->requestResult = func_0046C290(&r, func_00447A30);
        if (self->requestResult != 0)
            return;
        self->list8CTime = Lobby_GetTime();
        LobbyArray_Clear(&self->list8C);
        LobbyArray_SetRefreshing(&self->list8C, 1);
    }
    if (*(unsigned char*)&self->list8C.dirty && self->list8C.count > 0)
        LobbyArray_SetDirty(&self->list8C, 0);
}
/* Per-frame lobby update while in state 5: refreshes the lists for the current
 * mode, then runs the other periodic updates. */
void func_004516E0(SFOLobby* self) {
    if (self->state == 5 && !self->inUpdateHook) {
    switch (self->mode) {
    case 0:
        Tick_4516E0(self);
        func_00450B30(self);
        func_00453FA0(self, &self->list8C);
        break;
    case 1:
        Tick_4516E0(self);
        func_00450B30(self);
        func_00453FA0(self, &self->listA8);
        break;
    }
    func_004498C0(self);
    func_0044D700(self, 0);
    func_00449800(self, 0);
    func_00451B30(self);
    }
}
#undef memset /* merge_units */
#undef String_Copy /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004516E0 */
