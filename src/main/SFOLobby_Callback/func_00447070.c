#include "SFOLobby.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#pragma mpwc_relax on
int String_Copy(char *, char * );
int LobbyArray_Append(LobbyArray *, char *);
int SFOLobby_NoInstance();
int memcpy(char * , char * , int);
extern SFOLobby * D_00585E60;
/* Reply callback (second callback of func_0044CD20): flags gotReply1A0, appends a
 * LobbyUniverseEntry to universeList on success and keeps the 0x230-byte reply in reply18EC. */
void func_00447070(int d0, int d1, int d2, char * arg3) {
    struct { int f20[32]; int fA0[32]; int f120; int f124[64]; int f224; int f228; int f22C; } sl;
    int temp_v0;
    if (SFOLobby_NoInstance() == 0) {
        D_00585E60->gotReply1A0 = 1;
        temp_v0 = F_(arg3, 0x18, int);
        if ((temp_v0 != 1) && (temp_v0 == 0)) {
            String_Copy(sl.f20, arg3 + 0x1C);
            String_Copy(sl.fA0, arg3 + 0x9C);
            String_Copy(sl.f124, arg3 + 0x120);
            sl.f120 = F_(arg3, 0x11C, int);
            sl.f224 = F_(arg3, 0x220, int);
            sl.f228 = F_(arg3, 0x224, int);
            sl.f22C = F_(arg3, 0x228, int);
            LobbyArray_Append(D_00585E60->universeList, sl.f20);
        }
        memcpy(D_00585E60->reply18EC, arg3, 0x230);
    }
}
