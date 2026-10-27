#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
void SFOLobbyList_ClearAndCompactList(int);
int SFOLobby_SetCallback(char*, int);

#pragma opt_common_subs off
void SFOLobby_ServerScreenExit(char* arg0) {
    int s = F_(arg0, 0x255C, int);
    int p;
    if (s == 9) return;
    if (s != 2 && s != 0) return;
    F_(arg0, 0x255C, int) = 9;
    p = F_(arg0, 0x2404, int);
    if (p != 0) SFOLobbyList_ClearAndCompactList(p);
    F_(arg0, 0x2404, int) = 0;
    p = F_(arg0, 0x23DC, int);
    if (p != 0) SFOLobbyList_ClearAndCompactList(p);
    F_(arg0, 0x23DC, int) = 0;
    p = F_(arg0, 0x23E0, int);
    if (p != 0) SFOLobbyList_ClearAndCompactList(p);
    F_(arg0, 0x23E0, int) = 0;
    SFOLobby_SetCallback(arg0, 0);
}
