#include "types.h"
extern char D_004DAD90[];
extern char D_004DA330[];
extern void std_vector_deleter_cVector_dtor(void* p, int f);
extern void operator_delete(void* p);
typedef struct { void* vt; } V_EF30;
V_EF30* cGameCameraCollisionRoutine_dtor(V_EF30* self, short flag)
{
    if (self) {
        void* m;
        self->vt = D_004DAD90;
        m = (char*)self + 0x30;
        if (m) {
            if (m) {
                if (m)
                    std_vector_deleter_cVector_dtor(m, 0);
            }
        }
        if (self)
            self->vt = D_004DA330;
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}