#pragma cplusplus on

#include "types.h"

extern "C" {
extern char D_004DAEB0[];
extern char D_004D9DE0[];
void operator_delete(void* allocation);
}

struct Obj0021B830 {
    int pad[2];
    void* vtable;
};

extern "C" Obj0021B830* BlastEvent_Destruct(Obj0021B830* self, short deleteFlag)
{
    if (self) {
        self->vtable = D_004DAEB0;
        if (self)
            self->vtable = D_004D9DE0;
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}