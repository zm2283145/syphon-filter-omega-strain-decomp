#include "types.h"
typedef struct { char p0[0x14C]; unsigned char ready; } Y36DEF0;
typedef struct { unsigned int flags; char p4[0x80]; short h84; char p86[0x12]; Y36DEF0* y; } X36DEF0;
extern short Hog_FindFileNoCase(Y36DEF0* y, void* p, int z);
extern int func_0036D680(X36DEF0* x);
/* Polls the stream state: 1 idle, 2 not ready, 3 failed open, 0 opened, 5 nothing to do. */
int func_0036DEF0(X36DEF0* x)
{
    if (x->flags == 0) return 1;
    if (x->flags & 2) {
        int r;
        if (!x->y->ready) r = 2;
        else {
            x->h84 = Hog_FindFileNoCase(x->y, (char*)x + 4, 0);
            if (x->h84 == -1) r = 3;
            else r = 0;
        }
        return r;
    }
    if (x->flags & 1) { int r = func_0036D680(x); return r; }
    return 5;
}
