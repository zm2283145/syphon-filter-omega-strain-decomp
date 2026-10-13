#include "SFOLobby.h"
extern SFOLobby* D_00585E60;
extern int SFOLobby_NoInstance(int a, int b, int c);
extern void memcpy(void* dst, void* src, int size);
/* Reply callback: flags gotReply1B0 and keeps the 0x1C-byte reply in reply400. */
void func_00446E50(int a, int b, int c, void* src)
{
    if (!SFOLobby_NoInstance(a, b, c)) {
        D_00585E60->gotReply1B0 = 1;
        memcpy(D_00585E60->reply400, src, 0x1C);
    }
}
