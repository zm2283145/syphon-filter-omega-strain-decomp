#include "types.h"
typedef struct { char pad[0xB4]; float fB4; } S17D070;
int func_0017D070(S17D070* s) {
    return !(s->fB4 == 0.0f);
}
