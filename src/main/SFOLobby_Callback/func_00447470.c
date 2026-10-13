#include "SFOLobby.h"
extern SFOLobby* D_00585E60;
extern int SFOLobby_NoInstance(void*, int, int, int);
extern void memcpy(void*, void*, int);
/* Reply callback (request func_0044CA90): flags gotReply1A8 and keeps the reply. */
void func_00447470(void* a0, int a1, int a2, void* src) {
    if (SFOLobby_NoInstance(a0, a1, a2, (int)src) == 0) {
        D_00585E60->gotReply1A8 = 1;
        memcpy(&D_00585E60->reply380, src, 0x1C);
    }
}
