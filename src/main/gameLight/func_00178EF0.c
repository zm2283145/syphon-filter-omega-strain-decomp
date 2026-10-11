#pragma cplusplus on
#include "types.h"
extern "C" void operator_delete(void* p);
extern "C" void cGOBJ_dtor(void* self, int flag);
class VDel { public: int a; virtual ~VDel(); };
extern "C" char D_004D9F50[];
extern "C" char D_004DA1D0[];
typedef struct { void* vt; char pad[0x5C]; VDel* x60; } S_00178EF0;
extern "C" S_00178EF0* cGameSceneLight_dtor(S_00178EF0* self, short flag)
{
    if (self) {
        self->vt = D_004D9F50;
        if (self) {
            self->vt = D_004DA1D0;
            if (self->x60) {
                delete self->x60;
                self->x60 = 0;
            }
            cGOBJ_dtor(self, 0);
        }
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}