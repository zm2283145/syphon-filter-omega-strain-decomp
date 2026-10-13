#include "SFOLobby.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#pragma mpwc_relax on
int String_Copy(char *, char * );
int LobbyArray_Append(LobbyArray * , int *);
int SFOLobby_NoInstance();
int memset(int *, int, int);
extern SFOLobby * D_00585E60;

/* Reply callback: flags gotReply22C when the end-of-list byte (+0x44) is set and
 * queues a type-1 inbox entry for every successful record. */
void func_00446740(int d0, int d1, int d2, char * arg3) {
    struct { int f20[2]; int f28; int f2C[41]; } sl;

    if (SFOLobby_NoInstance() == 0) {
        if (F_(arg3, 0x44, signed char) != 0) {
            D_00585E60->gotReply22C = 1;
        }
        if (F_(arg3, 0x18, int) == 0) {
            memset(sl.f20, 0, 0xAC);
            sl.f20[0] = 1;
            sl.f28 = F_(arg3, 0x1C, int);
            String_Copy(sl.f2C, arg3 + 0x20);
            LobbyArray_Append(&D_00585E60->inbox, sl.f20);
        }
    }
}
