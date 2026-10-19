/*
 * main/SFOLobby_Games: SFOLobby_Games.cc (7 files, 0044E060-0044E960)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* library prototypes shared by the blocks below (C linkage) */
void *memset(void *, int, int);
int sprintf(void *, const void *, ...);
char *strncpy(void *, const void *, int);

/* merge_units: begin func_0044E060 */
#pragma push /* merge_units */
#include "SFOLobby.h"
extern void String_Copy(char*, char*);
extern int Lobby_GetTime(void);
extern void SFOLobby_SetError(SFOLobby*, int, char*, int);
extern void SFOLobby_CallUpdateHook(SFOLobby*, int, int);
extern int SFOLobby_Poll(SFOLobby*, int, int, int);
extern void func_0046A0E8(void*, void*);
extern int D_00497890;    /* request timeout */
extern char D_004C0EF0[]; /* "1" (message id) */
extern char D_004C0F00[]; /* "SFOLobby_Games.cc" */
extern char func_00446B40[];
static inline int NonZero44E060(int v) { return v != 0; }
#pragma push
#pragma opt_common_subs off
#pragma bool off
/* Sends request func_0046A0E8 for `arg` and waits for its reply (callback
 * func_00446B40 -> reply1D08); returns the reply, or 0 on failure. */
char* SFOLobby_GetGameInfo(SFOLobby* s, int arg)
{
    struct { char messageId[0x15]; char sessionKey[0x13]; int arg; } req;
    int t0;

    s->gotReply20C = 0;
    memset(&req, 0, sizeof(req));
    String_Copy(req.messageId, D_004C0EF0);
    String_Copy(req.sessionKey, s->sessionKey);
    req.arg = arg;
    func_0046A0E8(&req, func_00446B40);
    t0 = Lobby_GetTime();
    s->busy = 1;
    while (NonZero44E060(s->gotReply20C) ^ 1) {
        SFOLobby_CallUpdateHook(s, 0, 0);
        if (s->requestResult != 0) {
            s->busy = 0;
            return 0;
        }
        if (SFOLobby_Poll(s, t0, D_00497890, 0) == 0) {
            SFOLobby_SetError(s, 2, D_004C0F00, 0x2FE);
            s->busy = 0;
            return 0;
        }
    }
    s->busy = 0;
    return ((LobbyReply*)s->reply1D08)->statusCode == 0 ? s->reply1D08 : 0;
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_0044E060 */

/* merge_units: begin func_0044E1A0 */
#pragma push /* merge_units */
/* Looks like a Medius game-list filter: field, comparison operator, value. */
typedef struct {
    char messageId[0x15];
    char sessionKey[0x13];
    int field;
    int compare;
    int value;
} Request;
#if 0 /* merge_units */
extern char* String_Copy(char* dst, const char* src);
#endif /* merge_units */
#define String_Copy(a0, a1) (String_Copy((a0), (void *)(a1))) /* merge_units */

extern void func_0046AC78(Request* req, void (*cb)(void));
extern void func_00446CA0(void);

/* Submits two filter requests: field 4 compared (2) against `value`, and
 * field 7 compared (2) against 1. */
void func_0044E1A0(SFOLobby* self, int value)
{
    Request a; /* this order under cwps2-3.0b38 (b, a under 3.0.3) */
    Request b;
    memset(&a, 0, sizeof(Request));
    sprintf(a.messageId, "%d", 4);
    String_Copy(a.sessionKey, self->sessionKey);
    a.field = 4;
    a.compare = 2;
    a.value = value;
    func_0046AC78(&a, func_00446CA0);
    memset(&b, 0, sizeof(Request));
    sprintf(b.messageId, "%d", 7);
    String_Copy(b.sessionKey, self->sessionKey);
    b.field = 7;
    b.compare = 2;
    b.value = 1;
    func_0046AC78(&b, func_00446CA0);
}
#undef String_Copy /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044E1A0 */

/* merge_units: begin func_0044E280 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int SFOLobby_NoInstance();
extern SFOLobby * D_00585E60;

typedef struct { char c[21]; } SCc21;
typedef struct { int c[39]; } SCi39;
/* Reply callback: flags gotReply210 and copies the 0xBC-byte reply into reply1C30. */
void func_0044E280(int d0, int d1, int d2, signed char *arg3) {
    signed char *temp_a3;
    int *var_a2_2;
    int *var_a1_2;
    signed char *var_a1;
    signed char *var_a2;
    int var_a0;
    int var_a0_2;

    if (SFOLobby_NoInstance() == 0) {
        var_a0 = 0x15;
        var_a2 = arg3;
        D_00585E60->gotReply210 = 1;
        temp_a3 = (signed char *)D_00585E60->reply1C30;
        var_a1 = temp_a3;
        *(SCc21 *)(temp_a3) = *(SCc21 *)(arg3);
        var_a2_2 = arg3 + 0x20;
        var_a1_2 = temp_a3 + 0x20;
        var_a0_2 = 0x27;
        F_(temp_a3, 0x18, int) = F_(arg3, 0x18, int);
        F_(temp_a3, 0x1C, int) = F_(arg3, 0x1C, int);
        *(SCi39 *)(temp_a3 + 0x20) = *(SCi39 *)(arg3 + 0x20);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0044E280 */

/* merge_units: begin func_0044E330 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_004446E0(int);

int func_0044E330(void) {
    return func_004446E0(1);
}
#pragma pop /* merge_units */
/* merge_units: end func_0044E330 */

/* merge_units: begin func_0044E340 */
#pragma push /* merge_units */
#pragma mpwc_relax on
int Net_ParseIPv4(char * );
int func_00444040(int);
int func_00444050(int);
int func_00444060();
int func_00444070(int);
int SFOLobby_UpdateClientState(SFOLobby * , int);
int func_004505E0(SFOLobby * , char *);
int func_00452F30(SFOLobby * , int, char *);
extern char D_00585E90;          /* own LobbyPlayerInfo (0xFC bytes); the fields below live inside it */
extern int D_00585F78;           /* .wE8 */
extern int D_00585F7C;           /* .wEC */
extern int D_00585F80;           /* .wF0 */
extern int D_00585F84;           /* .ip */
extern signed char D_00585F88;   /* .bF8 */
extern signed char D_00585F89;   /* .bF9 */

#pragma opt_common_subs off
/* Leaves state 10 for IDLE (9) and republishes our own player info with our
 * IP address (func_004505E0). */
void func_0044E340(SFOLobby * arg0) {
    if (arg0->state == SFOLOBBY_STATE_10) {
        arg0->state = SFOLOBBY_STATE_IDLE;
    }
    func_00452F30(arg0, 3, &D_00585E90);
    D_00585F78 = arg0->unk2484;
    D_00585F84 = Net_ParseIPv4(arg0->myIp);
    D_00585F88 = 5;
    D_00585F7C = 0;
    D_00585F89 = 0;
    D_00585F80 = 0;
    func_004505E0(arg0, &D_00585E90);
    SFOLobby_UpdateClientState(arg0, 2);
    SFOLobby_UpdateClientState(arg0, 1);
    if ((func_00444060() != 0) && (func_00444070(1) == 0)) {
        func_00444050(0);
        func_00444040(0);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0044E340 */

/* merge_units: begin func_0044E430 */
#pragma push /* merge_units */
#pragma mpwc_relax on

extern int Net_ParseIPv4(char*);
extern void Net_StartSessionSingleTry(void*);
#if 0 /* merge_units */
extern char* SFOLobby_GetGameInfo(SFOLobby*, int);
#endif /* merge_units */
#define SFOLobby_GetGameInfo(a0, a1) (SFOLobby_GetGameInfo((a0), (a1))) /* merge_units */

extern int func_00452F30(SFOLobby*, int, char*);
extern int func_004505E0(SFOLobby*, char*);
extern int func_00469C10(char*, void*);
extern void func_004452E0(int);
extern void func_00453F90(SFOLobby*, int);
extern int func_0044A0D0(SFOLobby*, int, int);
extern int func_0044D670(SFOLobby*, int, int);

typedef struct LobbyGame {
    int id;         /* 0x00 */
    char pad4[8];
    int worldId;    /* 0x0C */
    int f10;        /* 0x10 */
    char pad14[4];
    int type;       /* 0x18 */
    char pad1C[8];
    int status;     /* 0x24 */
    char pad28[4];
} LobbyGame;

extern void* LobbyArray_At(LobbyArray*, int);
extern LobbyAccountEntry* func_00450A00(SFOLobby*, int);
extern int D_005721A8;
extern int D_00584520;
void func_0044E280(); /* gsynth: address taken */
#define func_0044E280 ((char *)func_0044E280) /* merge_units */

typedef struct {
    char messageId[0x15];
    char sessionKey[0x13];
    int id;             /* 0x28 */
    char pad2C[0x50 - 0x2C];
    int f50;            /* 0x50 */
    char pad54[0xC4 - 0x54];
} JoinReq;

/* Finds the pool118 game entry with the given id (0 = none). */
static inline LobbyGame* FindGame(SFOLobby* s, int id) {
    if (id == 0) return NULL;
    {
        int n = s->pool118.count;
        int j;
        LobbyGame* e;
        for (j = 0; j < n; j++) {
            e = (LobbyGame*)LobbyArray_At(&s->pool118, j);
            if (id == e->id) {
                return e;
            }
        }
        return NULL;
    }
}

/* Joins game id: refreshes it (SFOLobby_GetGameInfo), checks its status and the
 * host's account state, publishes our player info, sends the join request
 * (reply callback func_0044E280) and waits for gotReply210, then starts the
 * session from the reply and enters state 10. Returns 1 on success. */
int SFOLobby_JoinGame(SFOLobby* s, int id) {
    JoinReq req;
    int wid;
    int type;
    int t0;
    int t1;
    LobbyAccountEntry* acc;
    LobbyGame* g;

    if (id == 0) {
        SFOLobby_SetError(s, 0x33, D_004C0F00, 0x198);
        return 0;
    }
    SFOLobby_GetGameInfo(s, id);
    g = FindGame(s, id);
    if (g == NULL) {
        SFOLobby_SetError(s, 0x33, D_004C0F00, 0x1A1);
        return 0;
    }
    if (g->status != 1) {
        if (g->status == 3) {
            SFOLobby_SetError(s, 0x39, D_004C0F00, 0x1A9);
        } else {
            SFOLobby_SetError(s, 0x38, D_004C0F00, 0x1AB);
        }
        return 0;
    }
    type = g->type;
    if (type == 3 || type == 4) {
        t0 = Lobby_GetTime();
        wid = g->worldId;
        acc = func_00450A00(s, wid);
        while (acc->f34 == 3) {
            func_00453F90(s, wid);
            SFOLobby_CallUpdateHook(s, 0, 0);
            if (SFOLobby_Poll(s, t0, D_00497890, 0) == 0) {
                SFOLobby_SetError(s, 2, D_004C0F00, 0x1BF);
                break;
            }
        }
        if (acc->f34 == 3 || acc->f34 == 4) {
            SFOLobby_SetError(s, 0x35, D_004C0F00, 0x1C5);
            return 0;
        }
        if (type == 3 && (unsigned)acc->f34 < 2) {
            SFOLobby_SetError(s, 0x35, D_004C0F00, 0x1CA);
            return 0;
        }
        if (type == 4 && acc->f34 == 0) {
            SFOLobby_SetError(s, 0x35, D_004C0F00, 0x1CF);
            return 0;
        }
    }
    if (type == 2 && func_0044A0D0(s, g->worldId, 1) == 0) {
        SFOLobby_SetError(s, 0x36, D_004C0F00, 0x1E3);
        return 0;
    }
    if (type == 1 && func_0044D670(s, g->worldId, 1) == 0) {
        SFOLobby_SetError(s, 0x37, D_004C0F00, 0x1EB);
        return 0;
    }
    func_00452F30(s, 2, &D_00585E90);
    D_00585F78 = s->unk2484;
    D_00585F84 = Net_ParseIPv4(s->myIp);
    D_00585F7C = g->worldId;
    D_00585F89 = g->f10;
    D_00585F88 = g->type;
    D_00585F80 = id;
    if (func_004505E0(s, &D_00585E90) == 0) {
        SFOLobby_SetError(s, 1, D_004C0F00, 0x200);
        return 0;
    }
    memset(&req, 0, sizeof(req));
    String_Copy(req.messageId, D_004C0EF0);
    strncpy(req.sessionKey, s->sessionKey, 0x11);
    req.id = id;
    req.f50 = 2;
    s->requestResult = func_00469C10((char*)&req, func_0044E280);
    if (s->requestResult != 0) {
        SFOLobby_SetError(s, 1, D_004C0F00, 0x21D);
        return 0;
    }
    t1 = Lobby_GetTime();
    s->gotReply210 = 0;
    s->busy = 1;
    while (s->gotReply210 == 0) {
        SFOLobby_CallUpdateHook(s, 0, 0);
        if (SFOLobby_Poll(s, t1, D_00497890, 0) == 0) {
            SFOLobby_SetError(s, 2, D_004C0F00, 0x22C);
            s->busy = 0;
            return 0;
        }
    }
    s->busy = 0;
    if (((LobbyReply*)s->reply1C30)->statusCode != 0) {
        SFOLobby_SetError(s, 0x38, D_004C0F00, 0x234);
        return 0;
    }
    Net_StartSessionSingleTry(s->reply1C30 + 0x20);
    D_00584520 = D_005721A8;
    func_004452E0(req.id);
    s->state = 10;
    SFOLobby_SetError(s, 0, D_004C0F00, 0x248);
    return 1;
}
#undef func_0044E280 /* merge_units */
#undef SFOLobby_GetGameInfo /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044E430 */

/* merge_units: begin func_0044E960 */
#pragma push /* merge_units */
extern int func_00476998(void);
extern int func_004441D0(char*, char*, int, int);
#if 0 /* merge_units */
extern void SFOLobby_SetError(char*, int, char*, int);
#endif /* merge_units */
#define SFOLobby_SetError(a0, a1, a2, a3) (SFOLobby_SetError((void *)(a0), (a1), (a2), (a3))) /* merge_units */

extern void Net_StartSession(int);
extern int func_00444460(char*, char*, char*, int, int, int, int, int, int, int, int, int, int);
#if 0 /* merge_units */
extern int func_00452F30(char*, int, char*);
#endif /* merge_units */
#define func_00452F30(a0, a1, a2) (func_00452F30((void *)(a0), (a1), (a2))) /* merge_units */

extern int func_004452D0(void);
#if 0 /* merge_units */
extern int func_004505E0(char*, char*);
#endif /* merge_units */
#define func_004505E0(a0, a1) (func_004505E0((void *)(a0), (a1))) /* merge_units */

extern int func_00444050(int);
extern void func_00444020(int);
extern char D_004C0F18[];
extern char D_004C0F20[];
extern char D_004C0F30[];
extern int D_00494180;
extern int D_00585E70;
extern int D_00585E74;
extern int D_00585E78;
extern int D_00585E7C;
extern int D_00585E80;
extern int D_00585E84;
#if 0 /* merge_units */
extern char D_00585E90[];
#endif /* merge_units */
#define D_00585E90 ((char*)&D_00585E90) /* merge_units */

#if 0 /* merge_units */
extern char D_00585F88;
#endif /* merge_units */
#define D_00585F88 (*(char*)&D_00585F88) /* merge_units */

#if 0 /* merge_units */
extern char D_00585F89;
#endif /* merge_units */
#define D_00585F89 (*(char*)&D_00585F89) /* merge_units */


#pragma opt_common_subs off
int SFOLobby_CreateGame(char* self, int a1, int a2, int a3)
{
    char buf[0x48];
    char id[8];
    sprintf(id, D_004C0F18, (unsigned int)F_(self, 0x207C, int));
    if (func_004441D0(self + 0x1FFC, id, F_(self, 0x1EAC, int), func_00476998())) {
        SFOLobby_SetError(self, 0x31, D_004C0F00, 0xF2);
        return 0;
    }
    F_(self, 0x26A0, char) = 0;
    D_00494180 = a2;
    Net_StartSession(0);
    D_00584520 = D_005721A8;
    sprintf(buf, D_004C0F20, self + 0x243D, a2, a1, a3, F_(self, 0x2480, int));
    if (!func_00444460(buf, (char*)&D_00585E70, D_004C0F30, F_(self, 0x1EA8, int), a2, 1, a1, 0, 0, 0, 0, 0, 2)) {
        SFOLobby_SetError(self, 0x32, D_004C0F00, 0x152);
        return 0;
    }
    func_00452F30(self, 1, D_00585E90);
    D_00585F78 = F_(self, 0x2484, int);
    D_00585F84 = Net_ParseIPv4(self + 0x2429);
    D_00585F7C = F_(self, 0x2480, int);
    D_00585F89 = a1;
    D_00585F80 = func_004452D0();
    D_00585F88 = a3;
    memset(&D_00585E70, 0, 0x18);
    D_00585E70 = F_(self, 0x2480, int);
    D_00585E78 = func_004452D0();
    D_00585E74 = a1;
    D_00585E7C = a3;
    D_00585E80 = 0;
    D_00585E84 = Net_ParseIPv4(self + 0x2429);
    if (!func_004505E0(self, D_00585E90)) {
        SFOLobby_SetError(self, 1, D_004C0F00, 0x176);
        return 0;
    }
    func_00444050(1);
    func_00444020(1);
    F_(self, 0x255C, int) = 10;
    SFOLobby_SetError(self, 0, D_004C0F00, 0x17F);
    return 1;
}
#undef SFOLobby_SetError /* merge_units */
#undef func_00452F30 /* merge_units */
#undef func_004505E0 /* merge_units */
#undef D_00585E90 /* merge_units */
#undef D_00585F88 /* merge_units */
#undef D_00585F89 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044E960 */
