#include "types.h"
typedef struct { unsigned int flags; char pad[0x94]; char* a98; } S36D8E0;
extern int func_00369160(char* p);
int func_0036D8E0(S36D8E0* o)
{
    int r = 1;
    if (o->flags & 4) {
        if (o->flags & 2) r = func_00369160(o->a98 + 0x80);
        else if (o->flags & 1) r = func_00369160(o->a98);
        else r = 1;
    }
    return r;
}
