#pragma peephole off
#include "types.h"
typedef struct { int a0; int id; int x; int y; } E3D60;
typedef struct { int pad; E3D60 e[2]; } S3D60;
void cWeapon_EqualizeDualWieldAmmo(char* self)
{
    E3D60* b = (E3D60*)(self + 0x14);
    E3D60* a = (E3D60*)(self + 0x4);
    if (*(int*)(self + 0x18) != -1 && a->id != -1) {
        int y = (b->y + a->y + 1) / 2;
        int x = (b->x + a->x + 1) / 2;
        a->x = x;
        b->x = x;
        a->y = y;
        b->y = y;
    }
}