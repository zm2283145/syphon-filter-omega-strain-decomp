/*
 * main/SFOLobby_Lobby: 7 files, 00450880-00450EC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin SFOLobby_CacheAccount */
#pragma push /* merge_units */
#include "SFOLobby.h"
extern LobbyAccountEntry* LobbyArray_At(LobbyArray*, int);
extern void LobbyArray_Append(LobbyArray*, LobbyAccountEntry*);
extern int Lobby_GetTime(void);
extern void String_Copy(char*, char*);
extern void* memcpy(void*, const void*, int);
extern void* memset(void*, int, int);
static inline LobbyAccountEntry* Find450880(LobbyArray* list, int id)
{
    int n = list->count;
    int i;
    LobbyAccountEntry* e;
    for (i = 0; i < n; i++) {
        e = LobbyArray_At(list, i);
        if (id == e->accountId)
            return e;
    }
    return 0;
}
/* Adds or updates the accountCache entry for an account. data is only taken when
 * its first byte is 0xB. */
void SFOLobby_CacheAccount(SFOLobby* s, int id, char* name, int ip, unsigned char* data)
{
    LobbyAccountEntry tmp;
    LobbyAccountEntry* e = Find450880(&s->accountCache, id);
    if (data && *data != 0xB)
        data = 0;
    if (e) {
        if (e->ip != ip) {
            e->f28 = 0;
            e->f2C = 0;
            e->f30 = 0;
        }
        if (data) {
            e->hasInfo = 1;
            e->infoTime = Lobby_GetTime();
            memcpy(&e->info, data, sizeof(e->info));
        }
    } else {
        memset(&tmp, 0, sizeof(tmp));
        tmp.accountId = id;
        String_Copy(tmp.name, name);
        tmp.ip = ip;
        if (data) {
            tmp.hasInfo = 1;
            tmp.infoTime = Lobby_GetTime();
            memcpy(&tmp.info, data, sizeof(tmp.info));
        }
        LobbyArray_Append(&s->accountCache, &tmp);
    }
}
#pragma pop /* merge_units */
/* merge_units: end SFOLobby_CacheAccount */

/* merge_units: begin func_00450A00 */
#pragma push /* merge_units */
#define NULL 0
#pragma mpwc_relax on
#if 0 /* merge_units */
int *LobbyArray_At(LobbyArray * , int);
#endif /* merge_units */
#define LobbyArray_At(a0, a1) ((int *)LobbyArray_At((a0), (a1))) /* merge_units */

/* Finds the accountCache entry for an account id. */
int *func_00450A00(SFOLobby * self, int id) {
    int *e;
    int n;
    int i;
    n = self->accountCache.count;
    for (i = 0; i < n; i++) {
        e = LobbyArray_At(&self->accountCache, i);
        if (id == *e) {
            return e;
        }
    }
    return NULL;
}
#undef LobbyArray_At /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00450A00 */

/* merge_units: begin func_00450A90 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern int* LobbyArray_At(LobbyArray* t, int i);
#endif /* merge_units */
#define LobbyArray_At(a0, a1) ((int *)LobbyArray_At((a0), (a1))) /* merge_units */

/* Finds the element of t whose first word equals id. */
int* func_00450A90(LobbyArray* t, int id) {
    int n;
    int i;
    if (!t || !(n = t->count)) return 0;
    for (i = 0; i < n; i++) {
        int* e = LobbyArray_At(t, i);
        if (id == *e) return e;
    }
    return 0;
}
#undef LobbyArray_At /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00450A90 */

/* merge_units: begin func_00450B30 */
#pragma push /* merge_units */
extern int D_00585FA8;
extern int D_004977A0;              /* refresh interval */
extern int D_00497938;
extern char D_004C0F68[];           /* "1" */
extern char func_00447790[];
extern void func_00450060(SFOLobby*);
extern int func_00476998(void);
extern int func_00469DC8(void*, void*);
extern void LobbyArray_Clear(LobbyArray*);
extern void LobbyArray_SetRefreshing(LobbyArray*, int);
extern void LobbyArray_SetDirty(LobbyArray*, int);
static inline int Off450B30(SFOLobby* self)
{
    return D_00585FA8 != 0 && !self->unk17C;
}
/* Re-requests listA8 (reply callback func_00447790) once the refresh interval has
 * passed, and marks it dirty when it has entries. */
void func_00450B30(SFOLobby* s)
{
    struct { char messageId[0x15]; char sessionKey[0x13]; int f28; short f2C; short f2E; } req;
    int dt;
    if (Off450B30(s)) {
        func_00450060(s);
        return;
    }
    dt = Lobby_GetTime() - s->listA8Time;
    if (D_004977A0 < dt) {
        memset(&req, 0, sizeof(req));
        String_Copy(req.messageId, D_004C0F68);
        String_Copy(req.sessionKey, s->sessionKey);
        req.f28 = func_00476998();
        req.f2C = 1;
        req.f2E = D_00497938;
        s->requestResult = func_00469DC8(&req, func_00447790);
        if (s->requestResult != 0) return;
        s->listA8Time = Lobby_GetTime();
        LobbyArray_Clear(&s->listA8);
        LobbyArray_SetRefreshing(&s->listA8, 1);
    }
    if (*(unsigned char*)&s->listA8.dirty && s->listA8.count > 0)
        LobbyArray_SetDirty(&s->listA8, 1);
}
#pragma pop /* merge_units */
/* merge_units: end func_00450B30 */

/* merge_units: begin func_00450C60 */
#pragma push /* merge_units */
#pragma mpwc_relax on
int func_00450CF0();
int SFOLobby_RequestAccountInfo(SFOLobby *, int);
#if 0 /* merge_units */
void *memcpy(void *, void *, int);
#endif /* merge_units */
#define memcpy(a0, a1, a2) (memcpy((a0), (const void *)(a1), (a2))) /* merge_units */

/* Gets the player info for an account: from the cache when fresh, else by asking
 * the server (SFOLobby_RequestAccountInfo). */
int func_00450C60(SFOLobby *self, int id, LobbyPlayerInfo *out) {
    if (func_00450CF0() != 0) {
        return 1;
    }
    if (SFOLobby_RequestAccountInfo(self, id) == 0) {
        return 0;
    }
    memcpy(out, &self->accountInfoReply.info, 0xFC);
    return 1;
}
#undef memcpy /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00450C60 */

/* merge_units: begin func_00450CF0 */
#pragma push /* merge_units */
#pragma mpwc_relax on
#if 0 /* merge_units */
int Lobby_GetTime();
#endif /* merge_units */
#define Lobby_GetTime() (Lobby_GetTime()) /* merge_units */

LobbyAccountEntry *LobbyArray_At(LobbyArray * , int);
#if 0 /* merge_units */
int memset(LobbyPlayerInfo * , int, int);
#endif /* merge_units */
#define memset(a0, a1, a2) ((int)memset((void *)(a0), (a1), (a2))) /* merge_units */

extern int D_00497848;              /* cached info lifetime */
typedef struct { LobbyStatPair x[0x60]; } Pairs_0CF0;
static inline LobbyAccountEntry* Find_0CF0(SFOLobby* self, int id) {
    int n = self->accountCache.count;
    int i;
    for (i = 0; i < n; i++) {
        LobbyAccountEntry* e = LobbyArray_At(&self->accountCache, i);
        if (id == e->accountId) return e;
    }
    return NULL;
}
/* Copies the cached player info of an account into out when it is still fresh;
 * otherwise clears out and returns 0. */
int func_00450CF0(SFOLobby * self, int id, LobbyPlayerInfo * out) {
    LobbyStatPair *src;
    LobbyStatPair *dst;
    int n;
    LobbyAccountEntry *e;
    e = Find_0CF0(self, id);
    if ((e != NULL) && (e->hasInfo != 0) && ((Lobby_GetTime() - e->infoTime) < D_00497848)) {
        src = e->info.pairs;
        dst = out->pairs;
        n = 0x60;
        out->b0 = e->info.b0;
        out->b1 = e->info.b1;
        out->b2 = e->info.b2;
        out->b3 = e->info.b3;
        out->h4 = e->info.h4;
        out->h6 = e->info.h6;
        out->h8 = e->info.h8;
        out->hA = e->info.hA;
        out->hC = e->info.hC;
        out->hE = e->info.hE;
        out->w10 = e->info.w10;
        out->w14 = e->info.w14;
        out->w18 = e->info.w18;
        out->w1C = e->info.w1C;
        out->w20 = e->info.w20;
        out->w24 = e->info.w24;
        *(Pairs_0CF0*)dst = *(Pairs_0CF0*)src;
        out->wE8 = e->info.wE8;
        out->wEC = e->info.wEC;
        out->wF0 = e->info.wF0;
        out->ip = e->info.ip;
        out->bF8 = e->info.bF8;
        out->bF9 = e->info.bF9;
        return 1;
    }
    memset(out, 0, 0xFC);
    return 0;
}
#undef Lobby_GetTime /* merge_units */
#undef memset /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00450CF0 */

/* merge_units: begin func_00450EC0 */
#pragma push /* merge_units */
extern void LobbyArray_RemoveAt(LobbyArray* list, int index);
/* Removes element index of array38 when it is within range. */
void func_00450EC0(SFOLobby* self, int index) {
    if (index < self->array38.count) {
        LobbyArray_RemoveAt(&self->array38, index);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00450EC0 */
