#include "types.h"
typedef struct { char pad[0xB4]; float fB4; } A1_S;
int func_0017D510(A1_S* o) {
    return !(o->fB4 == 0.0f);
}