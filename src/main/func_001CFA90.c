#include "types.h"
typedef struct { char pad[0xE4]; float a; char pad2[0x1B4 - 0xE8]; float b; } CFA90_t;
int func_001CFA90(CFA90_t* p) {
    return p->a == 0.0f && p->b == 0.0f;
}