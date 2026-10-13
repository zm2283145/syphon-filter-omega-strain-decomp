#include "SFOLobby.h"
extern SFOLobby* D_00585E60;
extern int SFOLobby_NoInstance(int a, int b, int c);
extern void memcpy(char* dst, const char* src, int n);
/* Reply callback: flags gotReply1F8 and keeps the 0x20-byte reply in reply1B1C. */
void func_00446F80(int a, int b, int c, const char* name)
{
    if (!SFOLobby_NoInstance(a, b, c)) {
        D_00585E60->gotReply1F8 = 1;
        memcpy(D_00585E60->reply1B1C, name, 0x20);
    }
}
