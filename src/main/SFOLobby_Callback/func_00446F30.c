#include "SFOLobby.h"
extern SFOLobby* D_00585E60;
extern int SFOLobby_NoInstance(int a, int b, int c, int d);
extern void memcpy(void* dst, int src, int len);
/* Reply callback: flags gotReply200 and keeps the 0x64-byte reply in reply1BCC. */
void func_00446F30(int a, int b, int c, int msg) {
    if (!SFOLobby_NoInstance(a, b, c, msg)) {
        D_00585E60->gotReply200 = 1;
        memcpy(D_00585E60->reply1BCC, msg, 100);
    }
}
