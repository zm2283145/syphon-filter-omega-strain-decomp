#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int func_0036D380(int, int);
int func_0036DE50(char * arg0) {
    int f = F_(arg0, 0x0, int);
    if (f & 2) {
        return func_0036D380(F_(arg0, 0x98, int), F_(arg0, 0x84, short));
    }
    if (f & 1) {
        return (F_(F_(arg0, 0x98, int), 0x2C, int) / 0x800) * 0x800 + 0x800;
    }
    return 0;
}