#include "types.h"
typedef struct { char pad[0x60]; float x60; } NpcB1;
int cNPC_v51(NpcB1* n) {
    float f = n->x60;
    int r;
    if (f >= 0.0005f) {
        if (f < 0.25f) r = 1;
        else if (f > 0.75f) r = 3;
        else r = 2;
    } else r = 0;
    return r;
}