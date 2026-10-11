#include "types.h"
typedef struct { char pad[0x50]; float cone; } Ang2D40;
typedef struct { char pad[0x6C]; Ang2D40* angles; } Tank2D40;
typedef union { int i; Tank2D40* p; } Arg2D40;
int Script_cTank_SetFiringCone(Arg2D40* args) {
    float deg[1];
    Ang2D40* a;
    float d;
    *(int*)deg = args[1].i;
    a = args[0].p->angles;
    d = deg[0];
    if (a) {
        a->cone = 0.017453292f * d;
    }
    return 0;
}