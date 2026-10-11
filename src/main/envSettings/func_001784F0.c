#pragma cplusplus on
#include "types.h"
extern "C" void operator_delete(void* p);
extern "C" void cGOBJ_dtor(void* self, int flag);
class VDel { public: int a; virtual ~VDel(); };
extern "C" char D_004D9E00[];
typedef struct { void* vt; char pad[0x9C]; VDel* xA0; } S_84F0;
extern "C" S_84F0* cEnvSettings_dtor(S_84F0* self, short flag)
{
    if (self) {
        self->vt = D_004D9E00;
        if (self->xA0)
            delete self->xA0;
        cGOBJ_dtor(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}