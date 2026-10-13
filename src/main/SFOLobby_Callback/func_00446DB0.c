#include "SFOLobby.h"
extern SFOLobby* D_00585E60;
extern int SFOLobby_NoInstance(int a, int b, int c, void* data);
extern void memcpy(void* dst, void* src, int size);
/* Account-info reply callback (request SFOLobby_RequestAccountInfo): flags gotAccountInfo and
 * keeps the reply. */
void func_00446DB0(int a, int b, int c, void* data) {
    if (!SFOLobby_NoInstance(a, b, c, data)) {
        D_00585E60->gotAccountInfo = 1;
        memcpy(&D_00585E60->accountInfoReply, data, 0x148);
    }
}
