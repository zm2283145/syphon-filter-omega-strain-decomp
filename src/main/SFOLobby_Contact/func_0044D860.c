#include "SFOLobby.h"
extern void String_Copy(char*, char*);
extern int Lobby_GetTime(void);
extern void SFOLobby_SetError(SFOLobby*, int, char*, int);
extern void SFOLobby_CallUpdateHook(SFOLobby*, int, int);
extern int SFOLobby_Poll(SFOLobby*, int, int, int);
extern int func_0046C170(void*, void*);
extern void LobbyArray_Clear(LobbyArray*);
extern void LobbyArray_SetRefreshing(LobbyArray*, int);
extern void* memset(void*, int, int);
extern int D_00497890;     /* request timeout */
extern char D_004C0EC0[];  /* "1" (message id) */
extern char D_004C0ED0[];  /* "SFOLobby_Contact.cc" */
extern char func_00446830[];

/* Requests the buddy list (func_0046C170, reply callback func_00446830 refills
 * buddyList); with `wait` set, blocks until the last record arrives. */
int SFOLobby_RequestBuddyList(SFOLobby* s, int wait)
{
    char messageId[0x15];

    memset(&s->buddyListReply, 0, 0xD0);
    s->buddyListReply.accountId = -1;
    memset(messageId, 0, sizeof(messageId));
    String_Copy(messageId, D_004C0EC0);
    s->requestResult = func_0046C170(messageId, func_00446830);
    if (s->requestResult != 0) {
        return 0;
    }
    LobbyArray_Clear(&s->buddyList);
    LobbyArray_SetRefreshing(&s->buddyList, 1);
    if (wait) {
        while (s->buddyListReply.endOfList != 1) {
            SFOLobby_CallUpdateHook(s, 0, 0);
            if (s->requestResult != 0) {
                SFOLobby_SetError(s, 1, D_004C0ED0, 0x1A7);
                s->busy = 0;
                return 0;
            }
            if (SFOLobby_Poll(s, s->waitStart, D_00497890, 0) == 0) {
                SFOLobby_SetError(s, 2, D_004C0ED0, 0x1AF);
                s->busy = 0;
                return 0;
            }
        }
    }
    s->buddyListTime = Lobby_GetTime();
    return 1;
}
