#include "types.h"
typedef struct { int x0; int x4; int x8; unsigned char xC; } Req16E170;
unsigned char NpcAi_RequestMode(Req16E170* p, int v, int pri) {
    unsigned char r = 0;
    if (pri >= p->x8) {
        p->x4 = v;
        p->xC = 1;
        r = 1;
        p->x8 = pri;
    }
    return r;
}
