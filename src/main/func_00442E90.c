#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
void LobbyArray_Free(int);
int func_00452FC0(char*, int);

#pragma opt_common_subs off
void func_00442E90(char* arg0) {
    int s = F_(arg0, 0x255C, int);
    int p;
    if (s == 9) return;
    if (s != 2 && s != 0) return;
    F_(arg0, 0x255C, int) = 9;
    p = F_(arg0, 0x2404, int);
    if (p != 0) LobbyArray_Free(p);
    F_(arg0, 0x2404, int) = 0;
    p = F_(arg0, 0x23DC, int);
    if (p != 0) LobbyArray_Free(p);
    F_(arg0, 0x23DC, int) = 0;
    p = F_(arg0, 0x23E0, int);
    if (p != 0) LobbyArray_Free(p);
    F_(arg0, 0x23E0, int) = 0;
    func_00452FC0(arg0, 0);
}
