/*
 * main/SFOLobby_Main: 9 files, 00452A70-004534A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00452A70 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad0[0x244]; char flag; char pad245[3]; int* table; } Lobby_452A70;
typedef struct { char pad0[0x18]; int busy; char pad1C[0x44 - 0x1C]; int val; char name[0x8C - 0x48]; char kind; } Msg_452A70;
extern Lobby_452A70* D_00585E60;
extern int D_00585F90;
extern int SFOLobby_NoInstance(int a, int b, int c, Msg_452A70* s);
extern void String_Copy(char* d, char* s);
extern char* strrchr(char* s, int c);
extern int atoi(char* s);
void func_00452A70(int a, int b, int c, Msg_452A70* s) {
    char buf[0x40];
    char* p;
    int n;
    if (SFOLobby_NoInstance(a, b, c, s) || !D_00585E60->table) return;
    if (s->busy == 0) {
        String_Copy(buf, s->name);
        *strrchr(buf, ':') = 0;
        p = strrchr(buf, '_');
        if (p) {
            n = atoi(p + 1);
            if (n < D_00585F90) {
                D_00585E60->table[n] = s->val;
            }
        }
    }
    if (s->kind == 1) {
        D_00585E60->flag = 1;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00452A70 */

/* merge_units: begin func_00452B40 */
#pragma push /* merge_units */
typedef struct {
    char p0[0x1B38]; int f1B38; char p1B3C[0x1B80 - 0x1B3C]; int f1B80;
    char p1B84[0x1EB4 - 0x1B84]; int f1EB4; char f1EB8[0x40];
    char p1EF8[0x2564 - 0x1EF8];
    unsigned char err;
    char pad2565[3];
    char* errFile;
    int errLine;
} S452B40;
extern char D_004C0FA8[];
extern char D_004C0FB0[];
extern void String_Copy(char*, char*);
extern void func_00454010(void*);
extern int SFOLobby_FindChannel(S452B40*, char*);
extern int SFOLobby_CreateChannel(S452B40*, char*, char*);
extern int SFOLobby_JoinChannel(S452B40*, int, void*);
extern int SFOLobby_HandleOverflowJoinChannel(S452B40*, int);

static inline void SetErr_452B40(S452B40* self, unsigned char code, char* file, int line)
{
    if (self->err != 5) {
        self->err = code;
        self->errFile = file;
        self->errLine = line;
    }
}

int SFOLobby_JoinMissionChannel(S452B40* s, char* name)
{
    char pass[0x100];
    char info[0x60];

    String_Copy(pass, D_004C0FA8);
    func_00454010(info);
    if (!SFOLobby_FindChannel(s, name)) {
        if (!SFOLobby_CreateChannel(s, name, pass)) {
            SetErr_452B40(s, 0x17, D_004C0FB0, 0x457);
            return 0;
        }
        if (!SFOLobby_JoinChannel(s, s->f1B38, info)) {
            SetErr_452B40(s, 0x16, D_004C0FB0, 0x45C);
            return 0;
        }
        s->f1EB4 = s->f1B38;
        String_Copy(s->f1EB8, name);
    } else if (!SFOLobby_HandleOverflowJoinChannel(s, s->f1B80)) {
        return 0;
    }
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_00452B40 */

/* merge_units: begin func_00452C70 */
#pragma push /* merge_units */
#include "SFOLobby_Main_types.h"

extern void SFOLobby_DisconnectAuthServer(void);
extern void MediusCloseBare(void);
extern void NetClose(void);

/* Run the requested cleanup operations and clear the lobby's pending field. */
int SFOLobby_ShutdownMedius(LobbyMain* self, int notify)
{
    if (self->unk180 > 0)
        SFOLobby_DisconnectAuthServer();
    if (notify) {
        MediusCloseBare();
        NetClose();
    }
    self->unk1EA8 = 0;
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_00452C70 */

/* merge_units: begin func_00452CD0 */
#pragma push /* merge_units */
typedef struct {
    int f0;
    int f4;
    void* f8;
    int fC;
    int f10;
    void* f14;
    int f18;
} Req1C;

typedef struct {
    int w[6];
} Res18;

typedef struct {
    char a[0x40];
    char b[0x40];
} Buf80;

typedef struct {
    void* f0;
    void* f4;
    void* f8;
    void* fC;
    int f10;
} Cb14;

typedef struct {
    char pad0[0x24C];
    int f24C;
    char pad250[0x1EA8 - 0x250];
    int f1EA8;
    char pad1EAC[0x1F3C - 0x1EAC];
    char buf1F3C[0x40];
    char pad1F7C[0x23D6 - 0x1F7C];
    unsigned char b23D6;
    char pad23D7[0x2409 - 0x23D7];
    unsigned char b2409;
    char pad240A[0x2550 - 0x240A];
    void (*cb2550)(int, int);
    char pad2554[0x2564 - 0x2554];
    unsigned char b2564;
    void* p2568;
    int f256C;
} Net;

extern void* memset(void*, int, unsigned int);
extern void cDME_Init_PreLobby(void);
extern void cDME_Init_PostLobby(void);
extern void NetSetDefaultInitializeParams(Req1C*);
extern void NetInitialize(Req1C*, Res18*);
extern void KM_GenerateRSAKeyPair(void*, void*);
extern int KM_GetSoftwareID(void);
extern void srand(int);
extern int Random_Next(void);
extern int MediusInitializeBare(Cb14*, int*);
extern void KM_GetMediusPublicKey(void*);
extern void SFOLobby_Callback_SystemMessage(void);
extern void SFOLobby_Callback_LobbyChat(void);
extern void SFOLobby_Callback_BuddyConfirmationRequest(void);
extern void SFOLobby_Callback_MediusErrorMessage(void);
extern void SFOLobby_Callback_ReassignGameMediusWorldID(void);
extern int D_00572538;
extern double SoftFloat_IntToDouble(int);
extern double SoftFloat_FloatToDouble(float);
extern double SoftFloat_DoubleMultiply(double, double);
extern double SoftFloat_DoubleSub(double, double);
extern int SoftFloat_DoubleToInt(double);

int SFOLobby_InitializeMediusBare(Net* s)
{
    Req1C req;
    Res18 res;
    Buf80 buf;
    Cb14 cb;
    int h;
    int x;

    cDME_Init_PreLobby();
    memset(&req, 0, sizeof(req));
    memset(&res, 0, sizeof(res));
    NetSetDefaultInitializeParams(&req);
    memset(&buf, 0, sizeof(buf));
    s->b2409 = 1;
    if (s->cb2550 != 0) {
        s->cb2550(0, 0);
    }
    s->b2409 = 0;
    if (!s->b23D6) {
        KM_GenerateRSAKeyPair(buf.a, buf.b);
    }
    req.f4 = KM_GetSoftwareID();
    req.f8 = s->b23D6 ? 0 : &buf;
    x = D_00572538;
    srand(SoftFloat_DoubleToInt(SoftFloat_DoubleSub(SoftFloat_IntToDouble(x), SoftFloat_DoubleMultiply(0.0625, SoftFloat_FloatToDouble((float)x)))));
    req.fC = Random_Next() % 1000 + 6000;
    req.f14 = SFOLobby_Callback_SystemMessage;
    req.f10 = 1;
    req.f18 = 0;
    NetInitialize(&req, &res);
    cDME_Init_PostLobby();
    memset(&cb, 0, sizeof(cb));
    memset(&h, 0, sizeof(h));
    cb.f0 = SFOLobby_Callback_LobbyChat;
    cb.f4 = SFOLobby_Callback_BuddyConfirmationRequest;
    cb.f8 = SFOLobby_Callback_MediusErrorMessage;
    cb.fC = SFOLobby_Callback_ReassignGameMediusWorldID;
    cb.f10 = 30000;
    s->f24C = MediusInitializeBare(&cb, &h);
    if (s->f24C == -0x13) {
        s->f24C = 0;
    }
    if (s->f24C != 0) {
        if (s->b2564 != 5) {
            s->b2564 = 0x10;
            s->p2568 = D_004C0FB0;
            s->f256C = 0x3AF;
        }
        return 0;
    }
    memset(s->buf1F3C, 0, sizeof(s->buf1F3C));
    if (!s->b23D6) {
        KM_GetMediusPublicKey(s->buf1F3C);
    }
    s->f1EA8 = KM_GetSoftwareID();
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_00452CD0 */

/* merge_units: begin func_00452F30 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


/* Invokes the registered callback, if any, with (a0, a1). */
void SFOLobby_StatsCallback(LobbyMain* self, int a0, int a1) {
    LobbyMainCallback cb = self->callback;
    if (cb != 0) {
        cb(a0, a1);
    }
}

/* Registers the callback used by SFOLobby_StatsCallback. */
void SFOLobby_SetStatsCallback(LobbyMain* self, LobbyMainCallback cb) {
    self->callback = cb;
}
#pragma pop /* merge_units */
/* merge_units: end func_00452F30 */

/* merge_units: begin func_00452F70 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
#pragma push
#pragma opt_common_subs off
void SFOLobby_CallUpdateHook(char * arg0, int arg1, int arg2) {
    int (*temp_v1)(int, int);

    F_(arg0, 0x2409, signed char) = 1;
    temp_v1 = (int (*)(int, int))(F_(arg0, 0x2550, int));
    if (temp_v1 != NULL) {
        temp_v1(arg1, arg2);
    }
    F_(arg0, 0x2409, signed char) = 0;
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_00452F70 */

/* merge_units: begin func_00452FC0 */
#pragma push /* merge_units */
void SFOLobby_SetCallback(LobbyMain* self, int value) {
    self->unk2550 = value;
}

/* True when the state byte equals 5. */
int SFOLobby_IsFatalError(LobbyMain* self) {
    return self->state == 5;
}

int SFOLobby_GetDnasResult(LobbyMain* self) {
    return self->unk2570;
}
#pragma pop /* merge_units */
/* merge_units: end func_00452FC0 */

/* merge_units: begin func_00452FF0 */
#pragma push /* merge_units */
typedef struct { char pad[0x2564]; signed char code; char pad2[3]; char* file; int line; } E452;
extern int sprintf(char*, const char*, ...);
signed char SFOLobby_FormatError(E452* e, char* buf) {
    signed char r = e->code;
    if (buf) {
        char* s;
        unsigned char c = *(volatile unsigned char*)&e->code;
        switch (c) {
    case 0: s = "ERROR_NONE"; break;
    case 1: s = "ERROR_GENERAL"; break;
    case 2: s = "ERROR_TIMEOUT"; break;
    case 3: s = "ERROR_VULGARITY"; break;
    case 4: s = "ERROR_CONFIGSELECT"; break;
    case 5: s = "ERROR_CATASTROPHIC"; break;
    case 6: s = "ERROR_DNAS_FAILED"; break;
    case 7: s = "ERROR_HARDWARE_NOT_SUPPORTED"; break;
    case 8: s = "ERROR_UPDATE_PASSWORD_FAILED"; break;
    case 9: s = "ERROR_LOGOUT_FAILED"; break;
    case 10: s = "ERROR_LOGIN_FAILED"; break;
    case 11: s = "ERROR_ACCOUNT_CREATE_FAILED"; break;
    case 12: s = "ERROR_CONNECTION_FAILED"; break;
    case 13: s = "ERROR_UPDATECLIENTSTATE_FAILED"; break;
    case 14: s = "ERROR_MODULE_LOAD_FAILED"; break;
    case 15: s = "ERROR_MEDIUS_NOT_INITIALIZED"; break;
    case 16: s = "ERROR_MEDIUS_INITIALIZATION_FAILED"; break;
    case 17: s = "ERROR_BEGIN_SESSION_FAILED"; break;
    case 18: s = "ERROR_END_SESSION_FAILED"; break;
    case 19: s = "ERROR_GET_SESSION_KEY_FAILED"; break;
    case 20: s = "ERROR_AUTHENTICATION_FAILED"; break;
    case 21: s = "ERROR_GET_POLICY_FAILED"; break;
    case 22: s = "ERROR_JOIN_CHANNEL_FAILED"; break;
    case 23: s = "ERROR_CREATE_CHANNEL_FAILED"; break;
    case 24: s = "ERROR_FIND_CHANNEL_FAILED"; break;
    case 25: s = "ERROR_FILTER_FAILED"; break;
    case 26: s = "ERROR_NAME_TAKEN"; break;
    case 27: s = "ERROR_NAME_TOO_LONG"; break;
    case 28: s = "ERROR_ALREADY_LEADER"; break;
    case 29: s = "ERROR_AGENT_NONEXISTENT"; break;
    case 30: s = "ERROR_AGENT_ALREADY_BELONGS"; break;
    case 31: s = "ERROR_NOT_LEADER"; break;
    case 32: s = "ERROR_INTERFACE_NOT_STARTED"; break;
    case 33: s = "ERROR_INTERFACE_CONNECTION_FAILED"; break;
    case 34: s = "ERROR_INVALID_NAME"; break;
    case 35: s = "ERROR_SCREEN_NOT_ALLOWED"; break;
    case 36: s = "ERROR_NO_CHAT_LINES"; break;
    case 38: s = "ERROR_CONTACTINVITE_OFFLINE"; break;
    case 39: s = "ERROR_CONTACTINVITE_NONLOBBY"; break;
    case 40: s = "ERROR_CONTACTINVITE_DECLINED"; break;
    case 37: s = "ERROR_CANTINVITESELF"; break;
    case 41: s = "ERROR_GENERAL_IGNORABLE"; break;
    case 42: s = "ERROR_AGENTLIST_FULL"; break;
    case 43: s = "ERROR_MLSDISCONNECTFAILED"; break;
    case 44: s = "ERROR_MASDISCONNECTFAILED"; break;
    case 45: s = "ERROR_DNSLOOKUP_FAILED"; break;
    case 46: s = "ERROR_REQUESTEZNET_FAILED"; break;
    case 47: s = "ERROR_CONFIGGETLIST_FAILED"; break;
    case 48: s = "ERROR_CONFIGGETLIST_INVALID_MEMCARD"; break;
    case 49: s = "ERROR_SFOMGCL_STARTUP_FAILED"; break;
    case 50: s = "ERROR_CREATE_GAME_FAILED"; break;
    case 51: s = "ERROR_GAME_NOTFOUND"; break;
    case 52: s = "ERROR_EMPTY_LIST_SLOT"; break;
    case 53: s = "ERROR_JOINGAME_FILTER_PING"; break;
    case 54: s = "ERROR_JOINGAME_FILTER_CELL"; break;
    case 55: s = "ERROR_JOINGAME_FILTER_CONTACT"; break;
    case 56: s = "ERROR_JOINGAME_GENERAL"; break;
    case 57: s = "ERROR_JOINGAME_CLOSED"; break;
    case 58: s = "ERROR_INCORRECTPASSWORD"; break;
    case 59: s = "ERROR_ACCOUNT_NOT_FOUND"; break;
    case 60: s = "ERROR_ACCOUNT_LOGGEDIN"; break;
    case 61: s = "ERROR_ACCOUNT_ALREADY_EXISTS"; break;
    case 62: s = "ERROR_USER_CANCEL"; break;
    case 63: s = "ERROR_CELL_FULL_BUT_REVOKABLE"; break;
        default: s = "ERROR_UNKNOWN"; break;
        }
        sprintf(buf, "Error: %d - %s, File: %s, Line: %d", c, s, e->file, e->line);
    }
    if ((unsigned char)e->code != 5) {
        e->code = 0;
        e->file = D_004C0FB0;
        e->line = 0x2EA;
    }
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end func_00452FF0 */

/* merge_units: begin func_004534A0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
int NetGetNetUpdateErrors(int *);
int Lobby_GetTime(void);
int MediusUpdate(void);
int MediusUpdateUniverseInformation(void);
int MediusUpdateBare(void);
extern int D_00497928;
extern unsigned char g_IsMultiplayer;
extern char D_005723B8;
extern unsigned char D_00585FC0;
}

typedef struct {
    char pad0[0x180];
    int port;               /* 0x180 */
    char pad184[0x2564 - 0x184];
    unsigned char state;    /* 0x2564 */
    char pad2565[3];
    char* stateName;        /* 0x2568 */
    int stateLine;          /* 0x256C */
    char pad2570[0x255C - 0x2570 + 0x20];
} Dummy4534A0;

typedef struct {
    char pad0[0x180];
    int port;               /* 0x180 */
    char pad184[0x255C - 0x184];
    int mode;               /* 0x255C */
    char pad2560[4];
    unsigned char state;    /* 0x2564 */
    char pad2565[3];
    char* stateName;        /* 0x2568 */
    int stateLine;          /* 0x256C */
    char pad2570[8];
    int now;                /* 0x2578 */
    char pad257C[0x2660 - 0x257C];
    int deadline;           /* 0x2660 */
} Conn4534A0;

inline bool Port_IsReady(int arg0) {
    struct { int size; int st[4]; int pad[3]; } s;
    if ((arg0 < 0) || (arg0 >= 4)) {
        return false;
    }
    s.size = 0x18;
    NetGetNetUpdateErrors((int*)&s);
    if (s.st[arg0] == 2)
        return true;
    return false;
}

extern "C" int SFOLobby_Poll(Conn4534A0* self, int start, int timeout, int flag) {
    int now;
    int ok;
    bool fallback;
    if (self->mode == 0) {
        self->now = 0;
        return 0;
    }
    if (D_00585FC0 != 0) {
        return 1;
    }
    D_00585FC0 = 1;
    now = Lobby_GetTime();
    fallback = false;
    self->now = now;
    if (flag != 0) {
        ok = MediusUpdateUniverseInformation();
    } else if (self->mode == 0xA && g_IsMultiplayer != 0) {
        ok = MediusUpdateBare();
    } else {
        fallback = true;
        ok = MediusUpdate();
    }
    if (self->deadline == 0) {
        self->deadline = now + D_00497928;
    }
    if (ok != 0) {
        if (!Port_IsReady(self->port) || self->deadline <= now) {
            if (fallback) {
                D_005723B8 = 1;
            }
            if (self->state != 5) {
                self->state = 5;
                self->stateName = D_004C0FB0;
                self->stateLine = 0x26C;
            }
            D_00585FC0 = 0;
            return 0;
        }
    } else {
        self->deadline = now + D_00497928;
    }
    if (start != 0 && timeout > 0 && timeout < now - start) {
        D_00585FC0 = 0;
        return 0;
    }
    D_00585FC0 = 0;
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_004534A0 */
