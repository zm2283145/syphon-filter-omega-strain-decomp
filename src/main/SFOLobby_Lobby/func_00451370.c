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



