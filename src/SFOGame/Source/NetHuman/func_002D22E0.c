#include "types.h"
typedef struct { int max; int ver; int flags; unsigned char mode; } Prm22E0;
typedef struct { char pad[0x1C]; short a[2]; unsigned char b; unsigned char c; short d[2]; } Rec22E0;
extern int NetObjectField(int* db, int offset, int size, int count, int type, Prm22E0* prm);
unsigned char cAimWeapon_InitNet(int unused, Rec22E0* r, Prm22E0* prm)
{
    int db;
    unsigned char ok = 0;
    if (NetObjectField(&db, (char*)&r->c - (char*)r, 1, 1, 1, prm) == 0 &&
        NetObjectField(&db, (char*)r->a - (char*)r, 2, 3, 1, prm) == 0 &&
        NetObjectField(&db, (char*)&r->b - (char*)r, 1, 1, 1, prm) == 0) {
        prm->mode = 0x40;
        if (NetObjectField(&db, (char*)r->d - (char*)r, 2, 2, 1, prm) == 0)
            ok = 1;
    }
    prm->mode = 0;
    return ok;
}