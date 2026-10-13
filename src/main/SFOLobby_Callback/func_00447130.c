#include "SFOLobby.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#pragma mpwc_relax on
int String_Copy(char *, char * );
int LobbyArray_Append(LobbyArray *, char *);
int SFOLobby_NoInstance();
int memcpy(char * , char * , int);
extern SFOLobby * D_00585E60;
/* Reply callback (first callback of func_0044CD20): flags gotReply19C, appends the
 * record's string to outList2404 on success and keeps the reply in reply17CC. */
void func_00447130(int d0, int d1, int d2, char * arg3) {
    int sp20[64];
    if (SFOLobby_NoInstance() == 0) {
        D_00585E60->gotReply19C = 1;
        if (F_(arg3, 0x18, int) == 0) {
            String_Copy(sp20, arg3 + 0x1C);
            LobbyArray_Append(D_00585E60->outList2404, sp20);
        }
        memcpy(D_00585E60->reply17CC, arg3, 0x120);
    }
}
