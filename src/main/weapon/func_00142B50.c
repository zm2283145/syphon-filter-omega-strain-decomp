#include "types.h"
typedef struct { char pad[0x64]; int rate; } Weap_2B50;
typedef struct { int pad0; int pad4; int id; int padC; } Slot_2B50;
typedef struct { Slot_2B50 slots[8]; char pad[4]; unsigned char cur; } S_2B50;
extern void* D_004FFD30;
extern float D_00489C10;
Weap_2B50* WeaponDb_Get(void* db, int id);
int func_00142B50(S_2B50* self)
{
    unsigned char i = self->cur;
    int r = 0;
    if (i != 6)
        { float f = WeaponDb_Get(D_004FFD30, self->slots[i].id)->rate; r = (int)(f * D_00489C10); }
    return r;
}