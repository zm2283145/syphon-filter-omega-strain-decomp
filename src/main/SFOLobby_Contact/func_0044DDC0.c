#pragma opt_propagation off
#pragma cplusplus on
#include "SFOLobby.h"
extern "C" {
extern int D_004977B8;  /* buddy list refresh interval */
extern int D_004977D0;  /* buddy info refresh interval */
extern char D_004C0EE8; /* "%d" */
int Lobby_GetTime(void);
void SFOLobby_RequestBuddyList(SFOLobby* self, int a);
void func_004498C0(SFOLobby* self);
void func_00451B30(SFOLobby* self);
void func_00453FA0(SFOLobby* self, LobbyArray* list);
void func_0044EBD0(SFOLobby* self, LobbyArray* list);
int LobbyArray_GetRefreshing(LobbyArray* list);
LobbyBuddyEntry* LobbyArray_At(LobbyArray* list, int i);
void func_00449800(SFOLobby* self, int a);
void* memset(void* d, int c, unsigned int n);
int sprintf(char* d, const char* f, ...);
char* strncpy(char* d, const char* s, unsigned int n);
int func_0046A048(void* req, void* cb);
void func_004467D0(void);
}

struct Req_44DDC0 {
    char messageId[0x15];
    char sessionKey[0x13];
    int accountId;
};

/* Per-frame update of the CONTACTS state (6): periodically re-requests the buddy
 * list, and every D_004977D0 ms asks for fresh info (func_0046A048, callback
 * func_004467D0) on each buddy that is online. */
extern "C" void SFOLobby_UpdateContacts(SFOLobby* me)
{
    SFOLobby* self;
    int now;
    int last;
    LobbyArray* list;
    int d;
    Req_44DDC0 req;
    int i;
    LobbyBuddyEntry* item;
    self = me;
    if (self->state == SFOLOBBY_STATE_CONTACTS && !self->inUpdateHook) {
        last = self->buddyListTime;
        d = Lobby_GetTime() - last;
        if (!last || d > D_004977B8) {
            SFOLobby_RequestBuddyList(self, 0);
            self->buddyListTime = Lobby_GetTime();
        }
        func_004498C0(self);
        func_00451B30(self);
        func_00453FA0(self, &self->buddyList);
        func_0044EBD0(self, &self->buddyList);
        now = Lobby_GetTime();
        list = &self->buddyList;
        if (now - self->buddyInfoTime > D_004977D0 && !(unsigned char)LobbyArray_GetRefreshing(list)) {
            self->buddyInfoTime = now;
            i = 0;
            if (0 < list->count) {
                do {
                item = LobbyArray_At(list, i);
                if (item->location != 3) {
                    memset(&req, 0, sizeof(req));
                    sprintf(req.messageId, &D_004C0EE8, item->accountId);
                    strncpy(req.sessionKey, self->sessionKey, 0x11);
                    req.accountId = item->accountId;
                    func_0046A048(&req, func_004467D0);
                }
                    i++;
                } while (i < list->count);
            }
        }
        func_00449800(self, 0);
    }
}
