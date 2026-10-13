#include "SFOLobby.h"
typedef struct { char pad[0x18]; int statusCode; char accountName[0x2C]; LobbyPlayerInfo info; } S67D0;
extern SFOLobby* D_00585E60;
extern int SFOLobby_NoInstance(int a, int b, int c, S67D0* s);
extern int func_00121BC8(S67D0* s);
extern void SFOLobby_CacheAccount(SFOLobby* h, int r, void* p, int q, int t);
/* Reply callback: on success caches the player's info in accountCache. */
void func_004467D0(int a, int b, int c, S67D0* s) {
    if (SFOLobby_NoInstance(a, b, c, s) == 0 && s->statusCode == 0) {
        int r = func_00121BC8(s);
        SFOLobby_CacheAccount(D_00585E60, r, s->accountName, s->info.ip, (int)&s->info);
    }
}