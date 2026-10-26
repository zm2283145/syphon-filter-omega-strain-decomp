#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int SFOLobbyList_CompactList();                                  

#pragma opt_common_subs off
void LobbyArray_Free(int arg0) {
    int temp_v1;

    temp_v1 = F_(arg0, 0x14, int);
    if (temp_v1 != 0) {
        if (temp_v1 != 0) {
            if (F_(arg0, 0x4, int) != 0) {
                F_(arg0, 0x18, signed char) = 1;
            }
            F_(arg0, 0x4, int) = 0;
        }
        SFOLobbyList_CompactList();
    }
}
