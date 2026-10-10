#include "types.h"
#pragma cplusplus on
#include "alloc_guard.h"
class Xf_f4 {
public:
    virtual void Destroy(int flags);
};
struct Obj_f4 { char pad[0x48]; unsigned char owns; char pad49[7]; Xf_f4* xf; };
extern "C" {
extern char D_004BD228[];
void Mem_Free(int, void*, char*, int);
}
extern "C" void Object_ShareTransform(Obj_f4* self, Xf_f4* xf)
{
    Xf_f4* old = self->xf;
    if (old) {
        if (self->owns) {
            {
                AllocGuard g;
                old->Destroy(-1);
                Mem_Free(0, old, D_004BD228, 0x174);
            }
            self->owns = 0;
        }
        self->xf = 0;
    }
    self->xf = xf;
}
