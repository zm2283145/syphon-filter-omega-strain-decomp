#include "SFOLobby.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#pragma mpwc_relax on
int LobbyArray_Append(LobbyArray *, char * );
int SFOLobby_NoInstance();
int memcpy(char * , char * , int);
int strcmp(char * , char *);
extern SFOLobby * D_00585E60;
/* Reply callback: flags gotReply1B8 and files the record under outUsageList when
 * its first string is "USAGE", else under outList23FC. */
void func_004473C0(int d0, int d1, int d2, char * arg3) {
    if (SFOLobby_NoInstance() == 0) {
        D_00585E60->gotReply1B8 = 1;
        if (F_(arg3, 0x18, int) != 0) {
            F_(arg3, 0x11C, signed char) = 1;
        } else if (strcmp(arg3, "USAGE") == 0) {
            LobbyArray_Append(D_00585E60->outUsageList, arg3 + 0x1C);
        } else {
            LobbyArray_Append(D_00585E60->outList23FC, arg3 + 0x1C);
        }
        memcpy(D_00585E60->reply484, arg3, 0x120);
    }
}
