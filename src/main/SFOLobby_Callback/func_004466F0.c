#include "SFOLobby.h"
extern SFOLobby* D_00585E60;
extern int SFOLobby_NoInstance(void* a, void* b, void* c, LobbyReply* d);
/* Reply callback: flags gotReply238 and records whether the status was MediusSuccess. */
void func_004466F0(void* a, void* b, void* c, LobbyReply* d)
{
    if (!SFOLobby_NoInstance(a, b, c, d)) {
        D_00585E60->gotReply238 = 1;
        D_00585E60->reply238Ok = d->statusCode == MediusSuccess;
    }
}
