/*
 * main/SFOLobby_Lobby: SFOLobby_Lobby.cc (21 files, 0044FA70-00451370)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"
void *memcpy();
void *memset(void *, int, int);
int sprintf(void *, const void *, ...);
int strcmp(const void *, const void *);
int strlen(const char *);
char *strncpy(void *, const void *, int);

/* merge_units: begin func_0044FA70 */
#pragma push /* merge_units */
#include "SFOLobby.h"
void SFOLobby_CacheAccount(SFOLobby* s, int id, char* name, int ip, unsigned char* data); /* gsynth: defined below */
#pragma cplusplus on
extern "C" {
int Libc_Sscanf(char *, char *, ...);
void LobbyArray_Copy(LobbyArray *, LobbyArray *);
int LobbyArray_Append(LobbyArray *, void *);
#define LobbyArray_At(a0, a1) ((char *)LobbyArray_At((a0), (a1))) /* merge_units */
int LobbyArray_RemoveAt(LobbyArray *, int);
#if 0 /* merge_units */
void SFOLobby_CacheAccount(SFOLobby *, int, char *, int, LobbyPlayerInfo *);
#endif /* merge_units */
#define SFOLobby_CacheAccount(a0, a1, a2, a3, a4) (SFOLobby_CacheAccount((a0), (a1), (a2), (a3), (unsigned char *)(a4))) /* merge_units */

#define strlen(a0) ((unsigned int)strlen((a0))) /* merge_units */
extern char D_004C0F38[];
extern char D_004C0F50[];
extern SFOLobby *D_00585E60;
extern int D_00497938;
}

static inline bool IsNul(char c) { return !c; }

static inline void Grow(SFOLobby *lobby, int n)
{
    if (n != -1) {
        LobbyBuddyEntry tmp;
        memset(&tmp, 0, 0x50);
        while (lobby->listA8.count < n)
            LobbyArray_Append(&lobby->listA8, &tmp);
    }
}


typedef struct {
    int id;
    int f4;
    unsigned char f8;
    int fC;
    int f10;
} Game;

extern "C" void func_0044FA70(int d0, int d1, int d2, char *arg3)
{
    int idx;
    int key;
    int third;
    int n1;
    int n2;
    int n3;
    int n4;
    LobbyArray *list;
    Game *g;
    LobbyBuddyEntry *e;
    int slot;
    SFOLobby *lobby;
    bool ok;
    int i;
    char *p;

    if (D_00585E60 != 0) {
        list = &D_00585E60->listA8;
        if (list != 0) {
            if (Libc_Sscanf(arg3, D_004C0F38, &idx, &key, &third) != 3)
                return;
            idx--;
            if (idx >= D_00585E60->array00.count)
                return;
            g = (Game *)LobbyArray_At(&D_00585E60->array00, idx);
            if (g == 0)
                return;
            if (key != g->id || g->f8 == 0)
                return;
            if (*(int *)(arg3 + 0x18) == 0) {
                slot = g->f10 + idx * D_00497938;
                lobby = D_00585E60;
                Grow(lobby, slot + 1);
                e = (LobbyBuddyEntry *)LobbyArray_At(list, slot);
                memset(e, 0, 0x50);
                g->f10++;
                if (g->f10 > D_00497938)
                    return;
                n4 = n3 = n2 = n1 = 0;
                char name[0x40] = {0};
                char buf[0x40];
                ok = true;
                String_Copy(buf, arg3 + 0x20);
                i = 0;
                p = buf;
                while (!IsNul(*p) && *p != 9 && i < 0x40) {
                    if (*p == ' ')
                        *p = -1;
                    p++;
                    i++;
                }
                if (Libc_Sscanf(buf, D_004C0F50, name, &n1, &n2, &n3, &n4) != 5)
                    ok = false;
                if (name[0] != 0) {
                    p = name;
                    do {
                        if (*(unsigned char *)p == 0xFF)
                            *p = ' ';
                        p++;
                    } while (*p != 0);
                }
                if (strlen(name) > 0x1F)
                    ok = false;
                if (n1 < 1 || n1 > 4)
                    ok = false;
                if (n2 < 0 || n2 >= D_00585E60->array54.count)
                    ok = false;
                if (n3 < 0 || (unsigned int)n3 >= 6)
                    ok = false;
                if (ok) {
                    SFOLobby_CacheAccount(D_00585E60, n4, name, 0, 0);
                    {
                        SFOLobby *lb;
                        int wid;
                        int acc;
                        int j;
                        acc = n4;
                        lb = D_00585E60;
                        wid = *(int *)(arg3 + 0x1C);
                        for (j = 0; j < lb->listA8.count; j++) {
                            LobbyBuddyEntry *r = (LobbyBuddyEntry *)LobbyArray_At(&lb->listA8, j);
                            if (r->gameWorldId == wid || r->accountId == acc)
                                memset(r, 0, 0x50);
                        }
                    }
                    String_Copy(e->name, name);
                    e->f30 = *(int *)(arg3 + 0x60);
                    e->f34 = *(int *)(arg3 + 0x68);
                    e->f38 = n1;
                    e->gameWorldId = *(int *)(arg3 + 0x1C);
                    e->accountId = n4;
                    e->f40 = n2;
                    e->f44 = n3;
                    e->location = 0;
                    e->f4C = key;
                }
            }
            if (*(signed char *)(arg3 + 0x6C) != 0) {
                if (g->f10 != D_00497938) {
                    slot = g->f10 + D_00497938 * idx;
                    if (g->f10 != 0) {
                        lobby = D_00585E60;
                        Grow(lobby, slot);
                        if (slot != -1) {
                            if (slot == 0)
                                LobbyArray_Clear(&lobby->listA8);
                            else
                                while (lobby->listA8.count > slot)
                                    LobbyArray_RemoveAt(&lobby->listA8, lobby->listA8.count - 1);
                        }
                    } else {
                        lobby = D_00585E60;
                        if (slot != -1) {
                            if (slot == 0)
                                LobbyArray_Clear(&lobby->listA8);
                            else
                                while (lobby->listA8.count > slot)
                                    LobbyArray_RemoveAt(&lobby->listA8, lobby->listA8.count - 1);
                        }
                    }
                    for (; idx < (*(SFOLobby *volatile *)&D_00585E60)->array00.count; idx++) {
                        Game *o = (Game *)LobbyArray_At(&D_00585E60->array00, idx);
                        if (o->f10 == 0) {
                            o->id = 0;
                            o->f4 = 0;
                            o->f8 = 0;
                            o->fC = 0;
                            o->f10 = 0;
                            o->fC = Lobby_GetTime();
                        }
                    }
                }
                g->f8 = 0;
                g->fC = Lobby_GetTime();
                LobbyArray_SetRefreshing(list, 0);
                if (D_00585E60->outList23F0 != 0)
                    LobbyArray_Copy(D_00585E60->outList23F0, list);
            }
        }
    }
}
#undef LobbyArray_At /* merge_units */
#undef strlen /* merge_units */
#undef SFOLobby_CacheAccount /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0044FA70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0044FA70 */

/* merge_units: begin func_00450060 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
#define LobbyArray_At(a0, a1) ((char *)LobbyArray_At((a0), (a1))) /* merge_units */

int func_00476998(void);
int func_00469DC8(void *, void *);
#if 0 /* merge_units */
void func_0044FA70(int, int, int, char *);
#endif /* merge_units */
#define func_0044FA70(a0, a1, a2, a3) (func_0044FA70((a0), (a1), (a2), (a3))) /* merge_units */

extern int D_004978A8;
extern int D_004978C0;
extern int D_004978D8;
extern int D_00585FA8;
}

typedef struct {
    char messageId[0x15];
    char sessionKey[0x11];
    char pad26[2];
    int ver;
    short page;
    short pageSize;
    char pad30[0];
} ReqGames;

typedef struct {
    LobbyArray array00;
    char pad1C[0xA8 - 0x1C];
    LobbyArray listA8;
    char padC4[0x170 - 0xC4];
    int reqCounter;
    int rangeStart;
    int rangeEnd;
    char pad17C[0x24C - 0x17C];
    int requestResult;
    char pad250[0x2418 - 0x250];
    char sessionKey[0x11];
} L60;

extern "C" void func_00450060(L60 *self)
{
    int now;
    int count;
    int sent;
    int i;
    int hi;
    int hi2;
    int lo;
    int lo2;
    int n;
    int start;
    int half;
    int end;
    int k;
    int kend;
    unsigned char found;
    Game *g;

    now = Lobby_GetTime();
    count = self->array00.count;
    sent = 0;
    for (i = 0; i < count; i++) {
        Game *gg = (Game *)LobbyArray_At(&self->array00, i);
        if (gg->f8 != 0) {
            if (gg->fC + D_004978A8 < now) {
                int id = gg->f4;
                int a = i * D_00497938;
                int b = a + D_00497938;
                if (a < self->listA8.count) {
                    if (self->listA8.count < b)
                        b = self->listA8.count;
                    while (a < b) {
                        LobbyBuddyEntry *e = (LobbyBuddyEntry *)LobbyArray_At(&self->listA8, a++);
                        if (e->f4C == id)
                            memset(e, 0, 0x50);
                    }
                }
                gg->id = 0;
                gg->f4 = 0;
                gg->f8 = 0;
                gg->fC = 0;
                gg->f10 = 0;
            } else {
                sent++;
            }
        }
    }
    if (sent >= D_00585FA8)
        return;
    for (i = count - 1; i >= 0; i--) {
        g = (Game *)LobbyArray_At(&self->array00, i);
        if (g->f10 != 0 || g->f8 != 0 || g->fC + D_004978C0 >= now)
            break;
        LobbyArray_RemoveAt(&self->array00, i);
    }
    n = count * D_00497938;
    if (n != -1) {
        if (n == 0)
            LobbyArray_Clear(&self->listA8);
        else
            while (self->listA8.count > n)
                LobbyArray_RemoveAt(&self->listA8, self->listA8.count - 1);
    }
    n = self->array00.count;
    half = D_00497938 / 2;
    start = self->rangeStart - half;
    end = self->rangeEnd + half;
    if (start < 0)
        start = 0;
    if (end < start)
        end = start;
    lo = (start - (D_00497938 - 1)) / D_00497938;
    hi = (end + (D_00497938 - 1)) / D_00497938;
    lo2 = (self->rangeStart - (D_00497938 - 1)) / D_00497938;
    hi2 = (self->rangeEnd + (D_00497938 - 1)) / D_00497938;
    if (lo > n)
        lo = n;
    else if (lo < 0)
        lo = 0;
    if (lo2 > n)
        lo2 = n;
    else if (lo2 < 0)
        lo2 = 0;
    if (lo <= hi) do {
        if (lo >= n + (D_00585FA8 - sent))
            return;
        found = 0;
        if (lo == n) {
            Game tmp;
            tmp.id = 0;
            tmp.f4 = 0;
            tmp.f8 = 0;
            tmp.fC = 0;
            tmp.f10 = 0;
            LobbyArray_Append(&self->array00, &tmp);
            n++;
            found = 1;
        } else {
            g = (Game *)LobbyArray_At(&self->array00, lo);
            if (g->f8 == 0) {
                if (g->fC + D_004978C0 < now) {
                    found = 1;
                } else if (lo >= lo2 && lo <= hi2 && g->fC + D_004978D8 < now) {
                    int a = lo * D_00497938;
                    int b = a + D_00497938;
                    if (a < self->listA8.count) {
                        if (self->listA8.count < b)
                            b = self->listA8.count;
                        while (a < b) {
                            LobbyBuddyEntry *e = (LobbyBuddyEntry *)LobbyArray_At(&self->listA8, a++);
                            if (e->name[0] == 0) {
                                found = 1;
                                break;
                            }
                        }
                    }
                }
            }
        }
        if (found) {
            ReqGames req;
            g = (Game *)LobbyArray_At(&self->array00, lo);
            g->fC = now;
            g->f8 = 1;
            g->f4 = g->id;
            g->id = self->reqCounter++;
            g->f10 = 0;
            memset(&req, 0, 0x30);
            sprintf(req.messageId, D_004C0F38, lo + 1, g->id, g->f4);
            String_Copy(req.sessionKey, self->sessionKey);
            req.ver = func_00476998();
            req.page = lo + 1;
            req.pageSize = D_00497938;
            self->requestResult = func_00469DC8(&req, (void *)func_0044FA70);
            if (self->requestResult != 0)
                g->f8 = 0;
            sent++;
        }
        if (sent >= D_00585FA8)
            return;
    } while (++lo <= hi);
}
#undef LobbyArray_At /* merge_units */
#undef func_0044FA70 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00450060(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00450060 */

/* merge_units: begin func_00450590 */
#pragma push /* merge_units */
/* Store an ordered range with a nonnegative lower bound. */
void func_00450590(SFOLobby* lobby, int start, int end)
{
    if (start < 0)
        start = 0;
    if (end < start)
        end = start;
    lobby->rangeStart = start;
    lobby->rangeEnd = end;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00450590(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00450590 */

/* merge_units: begin func_004505C0 */
#pragma push /* merge_units */
/* True when no lobby instance exists; every reply callback checks this first. */
int SFOLobby_NoInstance(void)
{
    return D_00585E60 == 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004505C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004505C0 */

/* merge_units: begin func_004505E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_loop_invariants off
#pragma opt_common_subs off
typedef struct {
    char messageId[0x15];
    char sessionKey[0x11];
    char info[0xFC];                /* LobbyPlayerInfo (unaligned here) */
    char pad[4];
} Req4505;
/* merge_units: SFOLobby.h is first included by a C block, so LobbyPlayerInfo is
   a C struct here; the original (a C++ file) copied it member by member, so the
   copy below goes through a C++ twin of the same layout. */
typedef struct { signed char a; signed char b; } merge_LobbyStatPair_cpp;
typedef struct {
    unsigned char b0, b1, b2, b3;
    unsigned short h4, h6, h8, hA, hC, hE;
    int w10, w14, w18, w1C, w20, w24;
    merge_LobbyStatPair_cpp pairs[0x60];
    int wE8;
    int wEC;
    int wF0;
    int ip;
    unsigned char bF8, bF9;
} merge_LobbyPlayerInfo_cpp;
extern "C" {
int func_004695C8(void*, void*);
void func_00446CC0(void);
int Net_ParseIPv4(char*);
#if 0 /* merge_units */
void SFOLobby_CacheAccount(SFOLobby*, int, char*, int, LobbyPlayerInfo*);
#endif /* merge_units */
#define SFOLobby_CacheAccount(a0, a1, a2, a3, a4) (SFOLobby_CacheAccount((a0), (a1), (a2), (a3), (unsigned char *)(a4))) /* merge_units */

extern int D_00497890;              /* reply timeout */
extern char D_004C0F68[];           /* "1" */
extern char D_004C0F70[];           /* "SFOLobby_Lobby.cc" */
extern LobbyPlayerInfo D_00585E90;  /* own player info */
}
/* Uploads the own player info (reply callback func_00446CC0), waits for the reply,
 * then keeps a copy in D_00585E90 and in the account cache. */
extern "C" int func_004505E0(SFOLobby* self, LobbyPlayerInfo* info)
{
    Req4505 req;
    int t;
    self->unk2590 = Lobby_GetTime();
    memset(&req, 0, sizeof(req));
    String_Copy(req.messageId, D_004C0F68);
    strncpy(req.sessionKey, self->sessionKey, 0x11);
    memcpy(&req.info, info, 0xFC);
    self->requestResult = func_004695C8(&req, (void*)func_00446CC0);
    if (self->requestResult != 0) {
        SFOLobby_SetError(self, 1, D_004C0F70, 0x428);
        return 0;
    }
    t = Lobby_GetTime();
    self->gotAccountInfo = 0;
    while (self->gotReply208 == 0) {
        SFOLobby_CallUpdateHook(self, 0, 0);
        if (!SFOLobby_Poll(self, t, D_00497890, 0)) {
            SFOLobby_SetError(self, 2, D_004C0F70, 0x436);
            return 0;
        }
    }
    *(merge_LobbyPlayerInfo_cpp *)&D_00585E90 = *(merge_LobbyPlayerInfo_cpp *)info;
    SFOLobby_CacheAccount(self, self->accountId, self->accountName, Net_ParseIPv4(self->myIp), &D_00585E90);
    return 1;
}
#undef SFOLobby_CacheAccount /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004505E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004505E0 */

/* merge_units: begin func_00450880 */
#pragma push /* merge_units */
#define LobbyArray_At(a0, a1) ((LobbyAccountEntry *)LobbyArray_At((a0), (a1))) /* merge_units */
#if 0 /* merge_units */
extern int LobbyArray_Append(LobbyArray*, LobbyAccountEntry*);
#endif /* merge_units */
#define LobbyArray_Append(a0, a1) (LobbyArray_Append((a0), (void *)(a1))) /* merge_units */

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
#undef LobbyArray_At /* merge_units */
#undef LobbyArray_Append /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00450880(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00450880 */

/* merge_units: begin func_00450A00 */
#pragma push /* merge_units */
#define NULL 0
#pragma mpwc_relax on
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00450A00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00450A00 */

/* merge_units: begin func_00450A90 */
#pragma push /* merge_units */
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00450A90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00450A90 */

/* merge_units: begin func_00450B30 */
#pragma push /* merge_units */
extern int D_004977A0;              /* refresh interval */
extern char func_00447790[];
#if 0 /* merge_units */
extern void func_00450060(SFOLobby*);
#endif /* merge_units */
#define func_00450060(a0) (func_00450060((void *)(a0))) /* merge_units */

extern int func_00476998(void);
extern int func_00469DC8(void*, void*);
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
#undef func_00450060 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00450B30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00450B30 */

/* merge_units: begin func_00450C60 */
#pragma push /* merge_units */
int func_00450CF0(SFOLobby* self, int id, LobbyPlayerInfo* out); /* gsynth: defined below */
int SFOLobby_RequestAccountInfo(SFOLobby* s, int id); /* gsynth: defined below */
#pragma mpwc_relax on
int func_00450CF0();
#if 0 /* merge_units */
int SFOLobby_RequestAccountInfo(SFOLobby *, int);
#endif /* merge_units */
#define SFOLobby_RequestAccountInfo(a0, a1) (SFOLobby_RequestAccountInfo((a0), (a1))) /* merge_units */


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
#undef SFOLobby_RequestAccountInfo /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00450C60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00450C60 */

/* merge_units: begin func_00450CF0 */
#pragma push /* merge_units */
#pragma mpwc_relax on

#define LobbyArray_At(a0, a1) ((LobbyAccountEntry *)LobbyArray_At((a0), (a1))) /* merge_units */

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
#undef LobbyArray_At /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00450CF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00450CF0 */

/* merge_units: begin func_00450EC0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern int LobbyArray_RemoveAt(LobbyArray* list, int index);
#endif /* merge_units */
#define LobbyArray_RemoveAt(a0, a1) (LobbyArray_RemoveAt((a0), (a1))) /* merge_units */

/* Removes element index of array38 when it is within range. */
void func_00450EC0(SFOLobby* self, int index) {
    if (index < self->array38.count) {
        LobbyArray_RemoveAt(&self->array38, index);
    }
}
#undef LobbyArray_RemoveAt /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00450EC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00450EC0 */

/* merge_units: begin func_00450EF0 */
#pragma push /* merge_units */
#define LobbyArray_At(a0) ((int)LobbyArray_At((a0))) /* merge_units */
/* Element of array38 (0 when empty). */
int func_00450EF0(SFOLobby* p) {
    /* .set reorder barrier keeps the empty then-arm */
    if (p->array38.count == 0) { asm { .set reorder } return 0; }
    return LobbyArray_At(&p->array38);
}
#undef LobbyArray_At /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00450EF0(void) {}
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
#define LobbyArray_At(a0) ((InboxEntry_450F30 *)LobbyArray_At((a0))) /* merge_units */

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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00450F30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00450F30 */

/* merge_units: begin func_00451010 */
#pragma push /* merge_units */
/* Element of inbox (0 when empty). */
int func_00451010(SFOLobby* p) {
    /* .set reorder barrier keeps the empty then-arm */
    if (p->inbox.count == 0) { asm { .set reorder } return 0; }
    return (int)LobbyArray_At(&p->inbox);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00451010(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00451010 */

/* merge_units: begin func_00451050 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
int func_00469990(void*, void*);
int func_0046A378(void*);
void func_00447BB0(void);
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00451050(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00451050 */

/* merge_units: begin func_00451200 */
#pragma push /* merge_units */
extern char func_00446DB0[];

extern int func_0046A048(void*, void*);
#if 0 /* merge_units */
extern void SFOLobby_CacheAccount(SFOLobby*, int, char*, int, int);
#endif /* merge_units */
#define SFOLobby_CacheAccount(a0, a1, a2, a3, a4) (SFOLobby_CacheAccount((a0), (a1), (a2), (a3), (void *)(a4))) /* merge_units */


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
#undef SFOLobby_CacheAccount /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00451200(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00451200 */

/* merge_units: begin func_00451370 */
#pragma push /* merge_units */
/* self as char* is needed for matching (an SFOLobby* parameter changes codegen). */
#define SELF ((SFOLobby*)o)
#define strlen(a0) ((unsigned int)strlen((a0))) /* merge_units */
#define LobbyArray_At(a0, a1) ((int *)LobbyArray_At((a0), (a1))) /* merge_units */
extern int func_0046B140(void*, void*);
extern void func_00446E00(void);  /* reply callback, fills accountIdReply */
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
#undef LobbyArray_At /* merge_units */
#undef strlen /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00451370(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00451370 */

/* merge_units: begin func_004515F0 */
#pragma push /* merge_units */
/* Sets the lobby mode (which list func_004516E0 refreshes). */
void func_004515F0(SFOLobby* o, int value) {
    if (value != o->mode) o->mode = value;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004515F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004515F0 */

/* merge_units: begin func_00451610 */
#pragma push /* merge_units */
extern void LobbyArray_Free(LobbyArray* p);
/* Shuts the lobby down from states 0, 5 and 10 (state becomes 9 unless it was 10)
 * and frees the caller lists and the lobby arrays. */
void SFOLobby_LeaveRoom(SFOLobby* self)
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00451610(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00451610 */

/* merge_units: begin func_004516E0 */
#pragma push /* merge_units */
typedef struct { char messageId[0x18]; int id; } Req_4516E0;


extern int func_0046C290(Req_4516E0* a, void* b);
extern void func_00447A30(void);
#if 0 /* merge_units */
extern void func_00450B30(SFOLobby*);
#endif /* merge_units */
#define func_00450B30(a0) (func_00450B30((a0))) /* merge_units */

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
#undef func_00450B30 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004516E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004516E0 */
