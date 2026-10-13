#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#pragma opt_common_subs off
void LobbyArray_Clear(int arg0) {
    if (F_(arg0, 0x14, int) != 0) {
        if (F_(arg0, 0x4, int) != 0) {
            F_(arg0, 0x18, signed char) = 1;
        }
        F_(arg0, 0x4, int) = 0;
    }
}
