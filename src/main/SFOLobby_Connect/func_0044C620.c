#include "SFOLobby.h"
extern void String_Copy(char*, char*);
extern int Lobby_GetTime(void);
extern void SFOLobby_SetError(SFOLobby*, int, char*, int);
extern void SFOLobby_CallUpdateHook(SFOLobby*, int, int);
extern int SFOLobby_Poll(SFOLobby*, int, int, int);
extern int func_0046AF60(void*, void*);
extern void* memset(void*, int, int);
extern int strlen(const char*);
extern int D_00497890;              /* reply timeout */
extern char D_004C0E78[];           /* "1" */
extern char D_004C0E80[];           /* "SFOLobby_Connect.cc" */
extern char func_00446D00[];
#pragma push
#pragma opt_common_subs off
/* Asks the server for the own IP address; the reply callback func_00446D00 stores
 * it in myIp and sets gotMyIp. */
int SFOLobby_RequestMyIp(SFOLobby* s)
{
    struct { char messageId[0x15]; char sessionKey[0x11]; } req;
    memset(&req, 0, sizeof(req));
    String_Copy(req.messageId, D_004C0E78);
    String_Copy(req.sessionKey, s->sessionKey);
    memset(s->myIp, 0, 0x14);
    s->requestResult = func_0046AF60(&req, func_00446D00);
    if (s->requestResult != 0) return 0;
    s->gotMyIp = 0;
    s->waitStart = Lobby_GetTime();
    while (s->gotMyIp == 0) {
        SFOLobby_CallUpdateHook(s, 0, 0);
        if (SFOLobby_Poll(s, s->waitStart, D_00497890, 0) == 0) {
            SFOLobby_SetError(s, 2, D_004C0E80, 0x38A);
            break;
        }
    }
    if (strlen(s->myIp) == 0) {
        SFOLobby_SetError(s, 1, D_004C0E80, 0x392);
        return 0;
    }
    return 1;
}
#pragma pop
