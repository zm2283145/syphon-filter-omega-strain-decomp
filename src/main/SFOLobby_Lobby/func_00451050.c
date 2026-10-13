#pragma cplusplus on
#include "SFOLobby.h"
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
