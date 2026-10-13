#include "SFOLobby.h"
extern SFOLobby* D_00585E60;
extern int SFOLobby_NoInstance(void*, void*, void*, void*);
extern void memcpy(void*, void*, int);
/* Reply callback: flags gotReply1C0 and keeps the 0xB8-byte reply in reply9B0. */
void func_00446FD0(void* a, void* b, void* c, void* src) { if (!SFOLobby_NoInstance(a, b, c, src)) { D_00585E60->gotReply1C0 = 1; memcpy(D_00585E60->reply9B0, src, 0xB8); } }
