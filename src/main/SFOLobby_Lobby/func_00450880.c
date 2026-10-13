#include "SFOLobby.h"
extern LobbyAccountEntry* LobbyArray_At(LobbyArray*, int);
extern void LobbyArray_Append(LobbyArray*, LobbyAccountEntry*);
extern int Lobby_GetTime(void);
extern void String_Copy(char*, char*);
extern void* memcpy(void*, const void*, int);
extern void* memset(void*, int, int);
static inline LobbyAccountEntry* Find450880(LobbyArray* list, int id)
{
    int n = list->count;
    int i;
    LobbyAccountEntry* e;
    for (i = 0; i < n; i++) {
        e = LobbyArray_At(list, i);
        if (id == e->accountId)
            return e;
    }
    return 0;
}
/* Adds or updates the accountCache entry for an account. data is only taken when
 * its first byte is 0xB. */
void SFOLobby_CacheAccount(SFOLobby* s, int id, char* name, int ip, unsigned char* data)
{
    LobbyAccountEntry tmp;
    LobbyAccountEntry* e = Find450880(&s->accountCache, id);
    if (data && *data != 0xB)
        data = 0;
    if (e) {
        if (e->ip != ip) {
            e->f28 = 0;
            e->f2C = 0;
            e->f30 = 0;
        }
        if (data) {
            e->hasInfo = 1;
            e->infoTime = Lobby_GetTime();
            memcpy(&e->info, data, sizeof(e->info));
        }
    } else {
        memset(&tmp, 0, sizeof(tmp));
        tmp.accountId = id;
        String_Copy(tmp.name, name);
        tmp.ip = ip;
        if (data) {
            tmp.hasInfo = 1;
            tmp.infoTime = Lobby_GetTime();
            memcpy(&tmp.info, data, sizeof(tmp.info));
        }
        LobbyArray_Append(&s->accountCache, &tmp);
    }
}
