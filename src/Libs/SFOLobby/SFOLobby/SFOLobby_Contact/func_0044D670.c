#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int SFOLobby_GetMillisecs();                                
int SFOLobby_RequestBuddyList(char * , int);                         
int SFOLobby_FindAgent(char * , int, int);                    

int SFOLobby_ContactListContainsAgent(char * arg0, int arg1, int arg2) {
    if (arg2 != 0) {
        SFOLobby_GetMillisecs();
        SFOLobby_RequestBuddyList(arg0, 1);
        F_(arg0, 0x257C, int) = SFOLobby_GetMillisecs();
    }
    if (SFOLobby_FindAgent(arg0 + 0x150, arg1, 0) != 0) {
        return 1;
    }
    return SFOLobby_FindAgent(arg0 + 0xE0, arg1, 0) != 0;
}
