#include "types.h"
typedef struct { int a; int id; int b; int count; } S141240;
typedef struct { char pad[0xF0]; unsigned char kind; } W141240;
extern void* D_004FFD30;
extern W141240* WeaponDb_Get(void*, int);
extern int WeaponInv_IsReadyToFire(void*, int);
int Weapon_CanAttack(char* self) {
    unsigned char i = *(unsigned char*)(self + 0x84);
    S141240* s;
    if (i != 6) {
        s = (S141240*)(self + (i << 4) + 4);
        switch (WeaponDb_Get(D_004FFD30, s->id)->kind) {
        case 0: case 8: case 9:
            return WeaponInv_IsReadyToFire(self, 0);
        case 1: case 7:
            return s->count > 0;
        case 3: case 4: case 5: case 10:
            return 1;
        }
    }
    return 0;
}