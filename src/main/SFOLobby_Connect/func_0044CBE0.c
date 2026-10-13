#include "SFOLobby.h"
extern void String_Copy(char*, char*);
extern int Lobby_GetTime(void);
extern void SFOLobby_SetError(SFOLobby*, int, char*, int);
extern void SFOLobby_CallUpdateHook(SFOLobby*, int, int);
extern int SFOLobby_Poll(SFOLobby*, int, int, int);
extern int func_00469000(void*, void*);
extern void* memset(void*, int, int);
extern int D_00497890;              /* reply timeout */
extern char D_004C0E78[];           /* "1" */
extern char D_004C0E80[];           /* "SFOLobby_Connect.cc" */
extern char func_004471B0[];
#pragma push
#pragma opt_common_subs off
/* Request answered into reply350 (callback func_004471B0); fails unless MediusSuccess. */
int func_0044CBE0(SFOLobby* s)
{
    struct { char messageId[0x18]; int flag; } req;
    memset(&req, 0, sizeof(req));
    memset(&s->reply350, 0, 0x30);
    String_Copy(req.messageId, D_004C0E78);
    req.flag = 1;
    s->requestResult = func_00469000(&req, func_004471B0);
    if (s->requestResult != 0) {
        SFOLobby_SetError(s, 0x11, D_004C0E80, 0x222);
        return 0;
    }
    s->gotReply1A4 = 0;
    s->waitStart = Lobby_GetTime();
    while (s->gotReply1A4 == 0) {
        SFOLobby_CallUpdateHook(s, 0, 0);
        if (SFOLobby_Poll(s, s->waitStart, D_00497890, 0) == 0) {
            SFOLobby_SetError(s, 2, D_004C0E80, 0x22E);
            return 0;
        }
    }
    if (s->reply350.statusCode != 0) {
        SFOLobby_SetError(s, 0x11, D_004C0E80, 0x236);
        return 0;
    }
    return 1;
}
#pragma pop
