#include "types.h"
#include "vc_copy.h"
#include "v4_asm_copy.h"
typedef struct { char pad[0x10]; __int128 q10; __int128 q20; __int128 q30; __int128 q40; __int128 q50; } P_9600;
void cPointMass_ClearPhysics(P_9600* p) {
    __int128* d; __int128* s; __int128 t; __int128* z;
    V4StoreZero(&p->q50);
    V4StoreZero(&p->q40);
    d = &p->q20; s = &p->q10; z = &p->q30;
    t = V4Load(s); V4Store(d, t);
    VZeroF(z);
}