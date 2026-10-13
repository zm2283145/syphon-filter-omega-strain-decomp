#include "SFOLobby.h"
extern SFOLobby* D_00585E60;
extern int SFOLobby_NoInstance(void* a0, void* a1, void* a2);
extern void* memcpy(void* dst, const void* src, int n);
/* Reply callback: flags gotReply1D0 and keeps the 0x5C-byte reply in replyFD8. */
void func_00446D60(void* a0, void* a1, void* a2, void* data)
{
    if (SFOLobby_NoInstance(a0, a1, a2) == 0) {
        D_00585E60->gotReply1D0 = 1;
        memcpy(D_00585E60->replyFD8, data, 0x5C);
    }
}
