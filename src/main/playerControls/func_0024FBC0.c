#include "types.h"
typedef struct { unsigned char active; unsigned char passive; char pad[0x9E]; } D6EdgeReq;
typedef struct { char pad[0x3E0]; D6EdgeReq req[1]; } D6EdgeOwner;
void EdgeRequest_Latch(D6EdgeOwner* o, signed char idx, unsigned char passive)
{
    D6EdgeReq* e = (D6EdgeReq*)((char*)o + 0x3E0) + idx;
    if (e->active) {
        e->passive = e->passive && passive;
    } else {
        e->passive = passive;
    }
    e->active = 1;
}