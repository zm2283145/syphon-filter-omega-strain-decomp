#pragma cplusplus on
#include "types.h"

struct Info9EF10 {
    char pad[0x8F4];
    int busy;                   /* 0x8F4 */
};

class Obj9EF10 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Info9EF10* GetInfo();   /* vtable +0x14 */
    char pad04[0x60 - 0x04];
    float delay;                /* 0x60 */
    float last;                 /* 0x64 */
    char pad68[0x74 - 0x68];
    int owner;                  /* 0x74 */
    char pad78[0x16C - 0x78];
    unsigned char ready;        /* 0x16C */
};

extern "C" unsigned char func_0039EF10(Obj9EF10* self, float now)
{
    unsigned char r;
    if (self->owner == 0) r = self->ready;
    else r = !(self->GetInfo()->busy != 0) && now - self->last > self->delay;
    return r;
}


