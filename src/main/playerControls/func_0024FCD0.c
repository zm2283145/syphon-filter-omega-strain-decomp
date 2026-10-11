#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
extern char D_0049F790;

int func_0024FCD0(char * arg0) {
    int var_v0;

    var_v0 = F_((&D_0049F790 + (F_(arg0, 0x310, unsigned char) * 0x50)), 0x4C, unsigned char) != 0;
    if (var_v0 != 0) {
        var_v0 = F_((&D_0049F790 + (F_(arg0, 0x311, unsigned char) * 0x50)), 0x4C, unsigned char) != 0;
    }
    return var_v0;
}
