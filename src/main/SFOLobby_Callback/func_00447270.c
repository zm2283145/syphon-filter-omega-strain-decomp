#include "SFOLobby.h"
extern SFOLobby* D_00585E60;
extern int SFOLobby_NoInstance(int a, int b, int c, void* data);
extern void memcpy(void* dst, void* src, int size);
/* Reply callback: flags gotReply198 and keeps the reply in reply314. */
void func_00447270(int a, int b, int c, void* data) {
    if (!SFOLobby_NoInstance(a, b, c, data)) {
        D_00585E60->gotReply198 = 1;
        memcpy(&D_00585E60->reply314, data, 0x20);
    }
}
