#include "types.h"

typedef struct Pending {
    char pad[0xD4];
    int arg;
    unsigned char pending;
} Pending;

extern void cGameSystem_RemoveCamera(Pending*, int);

/* If the pending flag is set, clears it and calls cGameSystem_RemoveCamera(self, arg). */
void cGameSystem_PopWeaponCam(Pending* p) {
    if (p->pending) {
        p->pending = 0;
        cGameSystem_RemoveCamera(p, p->arg);
    }
}
