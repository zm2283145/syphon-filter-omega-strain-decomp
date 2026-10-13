#pragma cplusplus on
#include "SFOLobby.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
extern "C" {
int String_Copy(char *, char *);
char *func_0044F0C0(SFOLobby *, int, int *);
void LobbyArray_SetRefreshing(LobbyArray *, int);
void LobbyArray_Copy(LobbyArray *, LobbyArray *);
void LobbyArray_SetDirty(LobbyArray *, int);
int LobbyArray_Append(LobbyArray *, void *);
int SFOLobby_NoInstance();
void *memset(void *, int, int);
extern char D_004C0CC8[]; /* "" */
extern SFOLobby *D_00585E60;
}
typedef struct {
    signed char a, b;
} Pair446830;
/* One buddy-list reply record (same layout as LobbyBuddyReply). */
typedef struct {
    char messageId[0x15];
    int statusCode;
    int accountId;
    Pair446830 accountName[0x10];
    int w[0x23];                    /* w[0] playerStatus, w[2] gameWorldId */
    signed char endOfList;
} Msg446830;
/* LobbyArray element of buddyList (0x50 bytes). */
typedef struct {
    int accountId;
    char name[0x20];
    int f24;                        /* 1 in a game, 2 in a chat world, 3 otherwise */
    int f28;
    char *f2C;
    int f30;
    int f34;
    int f38;
    int f3C;
    int f40;
    int f44;
    int gameWorldId;
    int f4C;
} Buddy446830;
/* Buddy-list reply callback: appends one buddy per record (looking up the game the
 * buddy is in), and on the last record publishes the list to pool150/outBuddyList. */
extern "C" void func_00446830(int d0, int d1, int d2, Msg446830 *msg)
{
    Buddy446830 req;
    LobbyArray *list;
    char *e;
    if (SFOLobby_NoInstance() == 0) {
        list = &D_00585E60->buddyList;
        if (list != NULL) {
            if (msg->statusCode == MediusSuccess) {
                memset(&req, 0, 0x50);
                req.accountId = msg->accountId;
                String_Copy(req.name, (char *)msg->accountName);
                req.f30 = 0;
                req.f34 = -1;
                req.f38 = -1;
                req.f3C = -1;
                req.f40 = -1;
                req.f44 = 5;
                req.f28 = 2;
                req.f24 = 3;
                req.f2C = D_004C0CC8;
                switch (msg->w[0]) {
                case MediusPlayerDisconnected:
                case MediusPlayerInAuthWorld:
                    break;
                case MediusPlayerInChatWorld:
                    req.f24 = 2;
                    break;
                case MediusPlayerInGameWorld:
                    req.f24 = 1;
                    req.gameWorldId = msg->w[2];
                    e = func_0044F0C0(D_00585E60, req.gameWorldId, &req.f24);
                    if (e != NULL) {
                        req.f30 = F_(e, 0x24, int);
                        req.f34 = F_(e, 0x4, int);
                        req.f38 = F_(e, 0x8, int);
                        req.f3C = F_(e, 0x1C, int);
                        req.f40 = F_(e, 0x10, int);
                        req.f44 = F_(e, 0x18, int);
                    }
                    break;
                }
                LobbyArray_Append(list, &req);
            }
            if (msg->endOfList != 0) {
                LobbyArray_SetRefreshing(list, 0);
                if (list->count > 0)
                    LobbyArray_SetDirty(list, 1);
                if (D_00585E60->outBuddyList != NULL)
                    LobbyArray_Copy(D_00585E60->outBuddyList, list);
                LobbyArray_Copy(&D_00585E60->pool150, list);
            }
            *(Msg446830 *)&D_00585E60->buddyListReply = *msg;
        }
    }
}
