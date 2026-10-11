#include "types.h"
typedef struct { char pad[0x50]; float angle; } Ang5360;
typedef struct { char pad[0x6C]; Ang5360* angles; } AngOwner5360;
void func_00285360(AngOwner5360* self, float deg) {
    Ang5360* a = self->angles;
    if (a) {
        a->angle = 0.017453292f * deg;
    }
}