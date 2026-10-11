#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class C_185970 { public: VPAD32(a) virtual unsigned char Mode(); char pad4[0x40]; void* t44; void* t48; char pad4C[0x1E0 - 0x4C]; void* t1E0; void* t1E4; };
struct R_185970 { char pad[0x10]; char* target; };
struct O_185970 { char pad[0x58]; C_185970* ctl; char pad5C[0x3584 - 0x5C]; char* target; };
extern "C" void func_00185970(O_185970* o, R_185970* r)
{
    if (r->target) {
        o->target = r->target;
        if (o->ctl->Mode() == 2) {
            o->ctl->t1E0 = r->target;
            { char* x = r->target; if (x) x += 0x1C; o->ctl->t1E4 = x; }
        } else {
            o->ctl->t44 = r->target;
            { char* x = r->target; if (x) x += 0x1C; o->ctl->t48 = x; }
        }
    }
}
