#include "SFOLobby.h"
extern int SFOLobby_NoInstance();
extern void func_0044EDC0(SFOLobby* self, int a, int b, int c, int d, void* e);
extern SFOLobby* D_00585E60;
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
/* Reply callback: on success forwards the record's fields to func_0044EDC0. */
void func_00446AE0(int a0, int a1, int a2, char* m) {
    if (SFOLobby_NoInstance() == 0 && F_(m, 0x18, int) == 0) {
        func_0044EDC0(D_00585E60, F_(m, 0x3C, int), F_(m, 0x30, int), F_(m, 0x24, int), F_(m, 0x184, int), m + 0x34);
    }
}
