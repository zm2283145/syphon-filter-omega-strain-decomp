#include "types.h"

typedef struct { char pad[0x20]; int x20; } P_1A9210;
typedef struct { char pad[0x3210]; int flags; char pad2[0x3310 - 0x3214]; P_1A9210* p; } O_1A9210;
static inline int NZ_1A9210(int x) { return x != 0; }
static inline unsigned char Idle_1A9210(O_1A9210* o)
{
    unsigned char r = 1;
    P_1A9210* p = o->p;
    if (!(NZ_1A9210((int)p) ^ 1) && p->x20) r = 0;
    return r;
}
static inline unsigned char A_1A9210(O_1A9210* o)
{
    unsigned char r = 0;
    if (Idle_1A9210(o) && (NZ_1A9210((o->flags >> 4) & 1) ^ 1)) r = 1;
    return r;
}
unsigned char func_001A9210(O_1A9210* o)
{
    unsigned char r = 0;
    if (A_1A9210(o) && (NZ_1A9210((o->flags >> 5) & 1) ^ 1)) r = 1;
    return r;
}
