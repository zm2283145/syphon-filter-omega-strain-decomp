typedef __int128 Q128;
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int func_002EC580(int *);                             

int func_00453F30(int arg0) {
    struct { int size; int st[4]; int pad[3]; } s;
    if ((arg0 < 0) || (arg0 >= 4)) {
        return 0;
    }
    s.size = 0x18;
    func_002EC580(&s);
    return s.st[arg0] == 2;
}
