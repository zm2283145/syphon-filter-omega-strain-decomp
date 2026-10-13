#include "SFOLobby.h"
extern SFOLobby* D_00585E60;
extern int SFOLobby_NoInstance(void* a0, void* a1, void* a2);
extern void* memcpy(void* dst, const void* src, int n);
/* Reply callback (request func_0044CBE0): flags gotReply1A4 and keeps the 0x30-byte
 * reply in reply350. */
void func_004471B0(void* a0, void* a1, void* a2, void* data)
{
    if (SFOLobby_NoInstance(a0, a1, a2) == 0) {
        D_00585E60->gotReply1A4 = 1;
        memcpy(&D_00585E60->reply350, data, 0x30);
    }
}
