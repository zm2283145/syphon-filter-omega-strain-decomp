#include "types.h"
typedef struct { int max; int ver; int flags; unsigned char mode; } Prm23D0;
typedef struct { unsigned char a; char pad[3]; int b[1]; int c[1]; unsigned char d; char pad2[3]; int e; int f; int g; } Rec23D0;
extern int func_002E9BE8(int* db, int offset, int size, int count, int type, Prm23D0* prm);
unsigned char func_002D23D0(int unused, Rec23D0* r, Prm23D0* prm)
{
    int db;
    unsigned char ok = 0;
    prm->max = 0xFA;
    if (func_002E9BE8(&db, (char*)r->b - (char*)r, 4, 5, 1, prm) == 0 &&
        func_002E9BE8(&db, (char*)r->c - (char*)r, 4, 5, 1, prm) == 0 &&
        func_002E9BE8(&db, (char*)&r->d - (char*)r, 1, 0, 1, prm) == 0 &&
        func_002E9BE8(&db, (char*)&r->a - (char*)r, 1, 1, 1, prm) == 0 &&
        func_002E9BE8(&db, (char*)&r->e - (char*)r, 4, 6, 1, prm) == 0 &&
        func_002E9BE8(&db, (char*)&r->f - (char*)r, 4, 6, 1, prm) == 0 &&
        func_002E9BE8(&db, (char*)&r->g - (char*)r, 4, 6, 1, prm) == 0)
        ok = 1;
    return ok;
}