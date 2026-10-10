#include "types.h"
typedef struct { char pad[0x3C]; int range; } WeapEntD4;
typedef struct { int a; int b; int id; int c; } SlotD4;
typedef struct { SlotD4 slots[8]; char pad[4]; unsigned char cur; } LosD4;
extern void* D_004FFD30;
extern WeapEntD4* WeaponDb_Get(void* db, int id);
float func_0013FAF0(LosD4* p)
{
    float r = 0.0f;
    unsigned char i = p->cur;
    if (i != 6) {
        SlotD4* s = p->slots + i; int id = s->id;
        if (id != -1) {
            r = WeaponDb_Get(D_004FFD30, id)->range;
        }
    }
    return r;
}