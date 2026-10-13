#include "SFOLobby.h"
extern void String_Copy(char*, char*);
extern int Lobby_GetTime(void);
extern void SFOLobby_SetError(SFOLobby*, int, char*, int);
extern void SFOLobby_CallUpdateHook(SFOLobby*, int, int);
extern int SFOLobby_Poll(SFOLobby*, int, int, int);
extern int func_0046BFF0(void*, void*, void*);
extern void* memset(void*, int, int);
extern int D_00497890;              /* reply timeout */
extern char D_004C0E78[];           /* "1" */
extern char D_004C0E80[];           /* "SFOLobby_Connect.cc" */
extern char func_00447130[];
extern char func_00447070[];
/* Two-part list request (callbacks func_00447130 -> reply17CC and
 * func_00447070 -> reply18EC); waits until both lists report their end. */
int func_0044CD20(SFOLobby* s)
{
    struct { char messageId[0x18]; int f18; int f1C; int f20; } req;
    memset(&req, 0, sizeof(req));
    memset(s->reply17CC, 0, 0x120);
    memset(s->reply18EC, 0, 0x230);
    String_Copy(req.messageId, D_004C0E78);
    req.f18 = 3;
    req.f1C = 2;
    req.f20 = s->unk26A4;
    s->requestResult = func_0046BFF0(&req, func_00447130, func_00447070);
    if (s->requestResult != 0) {
        return 0;
    }
    s->gotReply19C = 0;
    s->gotReply1A0 = 0;
    s->waitStart = Lobby_GetTime();
    do {
        SFOLobby_CallUpdateHook(s, 0, 0);
        if (SFOLobby_Poll(s, s->waitStart, D_00497890, 1) == 0) {
            SFOLobby_SetError(s, 2, D_004C0E80, 0x1E6);
            return 0;
        }
    } while (!s->gotReply19C || !s->gotReply1A0 || s->reply17CCEnd != 1 || s->reply18ECEnd != 1);
    return 1;
}
