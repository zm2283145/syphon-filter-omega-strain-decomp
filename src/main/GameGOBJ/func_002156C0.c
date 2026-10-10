#include "types.h"
typedef struct { char pad[0x10C]; int count; int* locks; } Lift56C0;
void Lift_SetFloorLock(Lift56C0* p, int floor, unsigned char lock) {
    if (floor >= 0 && floor < p->count) {
        p->locks[floor] = lock;
    }
}