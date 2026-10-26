#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
void LobbyArray_Free(int);
int SFOLobby_SetCallback(char*, int);

#pragma opt_common_subs off
void SFOLobby_AccountScreenExit(char* arg0) {
    int s = F_(arg0, 0x255C, int);
    int p;
    if (s == 9) return;
    if (s != 3 && s != 0) return;
    F_(arg0, 0x255C, int) = 9;
    p = F_(arg0, 0x23F8, int);
    if (p != 0) LobbyArray_Free(p);
    F_(arg0, 0x23F8, int) = 0;
    p = F_(arg0, 0x23FC, int);
    if (p != 0) LobbyArray_Free(p);
    F_(arg0, 0x23FC, int) = 0;
    p = F_(arg0, 0x2400, int);
    if (p != 0) LobbyArray_Free(p);
    F_(arg0, 0x2400, int) = 0;
    SFOLobby_SetCallback(arg0, 0);
}
