#include "types.h"
typedef struct { int a; int b; int c; int d; } E3870;
typedef struct { char pad[0x10]; int base; int pad14; int id; int extra; int pad20; char pad2[0x84-0x24]; char cur; } S3870;
int WeaponInv_GetClip(S3870* self, char slot)
{
    int r;
    if ((unsigned char)slot == 6)
        slot = self->cur;
    if ((unsigned char)slot != 6) {
        r = *(int*)((char*)self + (unsigned char)slot * 16 + 0xC);
        if ((unsigned char)slot == 0 && self->id != -1)
            r += self->extra;
        return r;
    }
    return 0;
}