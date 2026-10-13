#include "SFOLobby.h"
typedef struct {
    char messageId[0x15];
    char sessionKey[0x13];
    int accountId;
} R44D9;
extern void SFOLobby_CallUpdateHook(SFOLobby*, int, int);
extern void* memset(void*, int, int);
extern void String_Copy(char*, char*);
extern char* strncpy(char*, const char*, int);
extern int Lobby_GetTime(void);
extern int func_0046A550(R44D9*, void*);
extern void func_004466F0();
extern void SFOLobby_SetError(SFOLobby*, int, char*, int);
extern int SFOLobby_Poll(SFOLobby*, int, int, int);
extern char D_004C0ED0[]; /* "SFOLobby_Contact.cc" */
extern char D_004C0EC0[]; /* "1" (message id) */
extern int D_00497890;    /* request timeout */

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
