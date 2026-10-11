#pragma cplusplus on
#include "types.h"
extern "C" { void operator_delete(void* p); void cMessage_dtor(void* m, int f); extern char D_004DA930[]; }
struct M_1ADBE0 { void* vt; };
struct O_1ADBE0 { char pad[0x5C]; M_1ADBE0 msg; };
static inline void MDtor_1ADBE0(M_1ADBE0* m) { if (m) { m->vt = D_004DA930; cMessage_dtor(m, 0); } }
extern "C" void* func_001ADBE0(O_1ADBE0* self, short deleteFlag)
{
    if (self) {
        MDtor_1ADBE0(&self->msg);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}