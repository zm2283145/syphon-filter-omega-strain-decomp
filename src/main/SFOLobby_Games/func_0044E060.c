#include "SFOLobby.h"
extern void String_Copy(char*, char*);
extern int Lobby_GetTime(void);
extern void SFOLobby_SetError(SFOLobby*, int, char*, int);
extern void SFOLobby_CallUpdateHook(SFOLobby*, int, int);
extern int SFOLobby_Poll(SFOLobby*, int, int, int);
extern void func_0046A0E8(void*, void*);
extern void* memset(void*, int, int);
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
char* func_0044E060(SFOLobby* s, int arg)
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
