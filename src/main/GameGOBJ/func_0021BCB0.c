#pragma cplusplus on

#include "types.h"

extern "C" {
void func_0036E220(void* member, int flags);
void cGOBJ_dtor(void* self, int flags);
void operator_delete(void* allocation);
extern char D_004DAF30[];
}

struct SoundGobj0021BCB0 {
    void* vtable;
    char base[0x5C];
    char payload[0x48];
    char memberA[0x9C];
    char memberB[4];
};

extern "C" SoundGobj0021BCB0* cSoundGOBJ_dtor(SoundGobj0021BCB0* self, short deleteFlag)
{
    if (self) {
        self->vtable = D_004DAF30;
        if (self->payload) {
            func_0036E220(self->memberB, -1);
            func_0036E220(self->memberA, -1);
        }
        cGOBJ_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}