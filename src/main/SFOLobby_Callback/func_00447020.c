#include "SFOLobby.h"
extern SFOLobby* D_00585E60;
extern int SFOLobby_NoInstance(int a, int b, int c);
extern void* memcpy(void* dst, const void* src, unsigned int n);
/* Reply callback: flags gotReply1FC and keeps the 0x90-byte reply in reply1B3C. */
void func_00447020(int a, int b, int c, void* src)
{
    if (SFOLobby_NoInstance(a, b, c) == 0) {
        D_00585E60->gotReply1FC = 1;
        memcpy(D_00585E60->reply1B3C, src, 0x90);
    }
}
