#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Lobby_GetTime();                                
int SFOLobby_RequestBuddyList(char * , int);                         
int func_00450A90(char * , int, int);                    

int func_0044D670(char * arg0, int arg1, int arg2) {
    if (arg2 != 0) {
        Lobby_GetTime();
        SFOLobby_RequestBuddyList(arg0, 1);
        F_(arg0, 0x257C, int) = Lobby_GetTime();
    }
    if (func_00450A90(arg0 + 0x150, arg1, 0) != 0) {
        return 1;
    }
    return func_00450A90(arg0 + 0xE0, arg1, 0) != 0;
}
