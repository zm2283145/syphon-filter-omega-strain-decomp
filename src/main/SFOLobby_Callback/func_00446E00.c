#include "SFOLobby.h"
extern SFOLobby* D_00585E60;
extern int SFOLobby_NoInstance(void*, int, int, int);
extern void memcpy(void*, void*, int);
/* Account-id-by-name reply callback (request SFOLobby_LookupAccountId): flags gotAccountId
 * and keeps the reply. */
void func_00446E00(void* a0, int a1, int a2, void* src) {
    if (SFOLobby_NoInstance(a0, a1, a2, (int)src) == 0) {
        D_00585E60->gotAccountId = 1;
        memcpy(&D_00585E60->accountIdReply, src, 0x20);
    }
}
