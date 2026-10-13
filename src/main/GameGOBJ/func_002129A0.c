#include "types.h"
typedef struct { int priority; int count; int flags; unsigned char attr; } Prm_002129A0;
typedef struct { char pad0[0x8]; int x8; char padC[2]; short xE; short x10; char pad12[2]; int x14; int x18; } Rec_002129A0;
extern int D_004F5488;
extern int func_002E9BE8(int* out, int off, int size, int count, int type, Prm_002129A0* prm);
unsigned char func_002129A0(Rec_002129A0* r)
{
    Prm_002129A0 prm;
    int db;
    unsigned char ok;
    int e;
    prm.priority = 500;
    ok = 0;
    prm.count = 1;
    prm.attr = 0x40;
    prm.flags = 0;
    if (func_002E9BE8(&db, (char*)&r->x14 - (char*)r, 4, 4, 1, &prm) == 0 &&
        func_002E9BE8(&db, (char*)&r->x18 - (char*)r, 4, 4, 1, &prm) == 0 &&
        func_002E9BE8(&db, (char*)&r->xE - (char*)r, 2, 3, 1, &prm) == 0 &&
        (e = func_002E9BE8(&db, (char*)&r->x10 - (char*)r, 2, 3, 1, &prm)) == 0) {
        if (!e) {
            e = func_002E9BE8(&db, (char*)&r->x8 - (char*)r, 4, 4, 1, &prm);
            D_004F5488 = db;
            if (!e)
                ok = 1;
        }
    }
    return ok;
}

