#include "SFOLobby.h"
#define NULL 0
#pragma mpwc_relax on
extern void String_Copy(char*, char*);
extern char* strncpy(char*, const char*, int);
extern void* memset(void*, int, int);
extern int Lobby_GetTime(void);
extern void SFOLobby_SetError(SFOLobby*, int, char*, int);
extern void SFOLobby_CallUpdateHook(SFOLobby*, int, int);
extern int SFOLobby_Poll(SFOLobby*, int, int, int);
extern int Net_ParseIPv4(char*);
extern void Net_StartSessionSingleTry(void*);
extern char* func_0044E060(SFOLobby*, int);
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

extern int D_00497890;
extern char D_004C0EF0[];
extern char D_004C0F00[];
extern int D_005721A8;
extern int D_00584520;
extern char D_00585E90;
extern int D_00585F78;
extern int D_00585F7C;
extern int D_00585F80;
extern int D_00585F84;
extern signed char D_00585F88;
extern signed char D_00585F89;
extern char func_0044E280[];

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

/* Joins game id: refreshes it (func_0044E060), checks its status and the
 * host's account state, publishes our player info, sends the join request
 * (reply callback func_0044E280) and waits for gotReply210, then starts the
 * session from the reply and enters state 10. Returns 1 on success. */
int func_0044E430(SFOLobby* s, int id) {
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
    func_0044E060(s, id);
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
