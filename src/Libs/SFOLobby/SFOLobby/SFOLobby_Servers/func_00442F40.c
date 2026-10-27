#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int SFOLobbyList_AllocList(int, int, int, int);                      
int SFOLobby_SetCallback();                                  

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
int SFOLobby_ServerScreenStart(char * arg0, int d1, int arg2) {
    if (F_(arg0, 0x255C, int) != 9) {
        return 0;
    }
    F_(arg0, 0x255C, int) = 2;
    SFOLobby_SetCallback();
    F_(arg0, 0x23E0, int) = arg2;
    { int w = 0x20; SFOLobbyList_AllocList(F_(arg0, 0x23E0, int), w, w, 0x44); }
    return 1;
}

#pragma pop
