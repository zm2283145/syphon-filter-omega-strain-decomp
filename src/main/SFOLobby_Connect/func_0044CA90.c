#include "SFOLobby.h"
extern void String_Copy(char*, char*);
extern int Lobby_GetTime(void);
extern void SFOLobby_SetError(SFOLobby*, int, char*, int);
extern void SFOLobby_CallUpdateHook(SFOLobby*, int, int);
extern int SFOLobby_Poll(SFOLobby*, int, int, int);
extern int func_004690A0(void*, void*);
extern void* memset(void*, int, int);
extern int D_00497890;              /* reply timeout */
extern char D_004C0E78[];           /* "1" */
extern char D_004C0E80[];           /* "SFOLobby_Connect.cc" */
extern char func_00447470[];
#pragma push
#pragma opt_common_subs off
#pragma opt_loop_invariants off
/* Request answered into reply380 (callback func_00447470); fails on a negative status. */
int func_0044CA90(SFOLobby* s)
{
    struct { char messageId[0x15]; char sessionKey[0x11]; } req;
    memset(&req, 0, sizeof(req));
    memset(&s->reply380, 0, 0x1C);
    String_Copy(req.messageId, D_004C0E78);
    String_Copy(req.sessionKey, s->sessionKey);
    s->requestResult = func_004690A0(&req, func_00447470);
    if (s->requestResult != 0) {
        SFOLobby_SetError(s, 0x12, D_004C0E80, 0x25F);
        return 0;
    }
    s->gotReply1A8 = 0;
    s->gotReply1A4 = 0;
    s->waitStart = Lobby_GetTime();
    while (s->gotReply1A8 == 0) {
        SFOLobby_CallUpdateHook(s, 0, 0);
        if (SFOLobby_Poll(s, s->waitStart, D_00497890, 0) == 0) {
            SFOLobby_SetError(s, 2, D_004C0E80, 0x26C);
            return 0;
        }
    }
    if (s->reply380.statusCode < 0) {
        SFOLobby_SetError(s, 0x12, D_004C0E80, 0x274);
        return 0;
    }
    return 1;
}
#pragma pop
