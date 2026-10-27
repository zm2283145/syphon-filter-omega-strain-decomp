#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int SFOLobbyList_GetSlot(int arg0, int arg1) {
    int temp_v1;

    temp_v1 = F_(arg0, 0x14, int);
    if (temp_v1 == 0) {
        return 0;
    }
    if ((arg1 < 0) || (arg1 >= F_(arg0, 0x4, int))) {
        return 0;
    }
    return temp_v1 + (arg1 * F_(arg0, 0x10, int));
}
