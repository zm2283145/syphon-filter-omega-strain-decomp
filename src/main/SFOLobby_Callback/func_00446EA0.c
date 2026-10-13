#include "SFOLobby.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#pragma mpwc_relax on
int String_Copy();
int LobbyArray_Append(LobbyArray *, int *);
int SFOLobby_NoInstance();
int memcpy(char * , char * , int);
extern SFOLobby * D_00585E60;
/* Reply callback: flags gotReply1AC, appends {id, name} to lobbyList when the
 * record's +0x5C field is 0, and keeps the reply in reply39C. */
void func_00446EA0(int d0, int d1, int d2, char * arg3) {
    struct { int f20; int f24[19]; } sl;
    int temp_v0;
    if (SFOLobby_NoInstance() == 0) {
        D_00585E60->gotReply1AC = 1;
        temp_v0 = F_(arg3, 0x5C, int);
        if ((temp_v0 != 1) && (temp_v0 == 0)) {
            sl.f20 = F_(arg3, 0x18, int);
            String_Copy(sl.f24, arg3 + 0x1C);
            LobbyArray_Append(D_00585E60->lobbyList, &sl.f20);
        }
        memcpy(D_00585E60->reply39C, arg3, 0x64);
    }
}
