#include "types.h"
typedef struct { char pad[0x9C4]; float v; } F17A610_t;
int Camera_IsBoomActive(F17A610_t* p) {
    return !(0.0f == p->v);
}