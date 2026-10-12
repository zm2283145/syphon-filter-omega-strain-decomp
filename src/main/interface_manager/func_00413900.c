#pragma cplusplus on
#include "types.h"

struct Str413900 { int a; int b; int c; };
struct Arc413900 { char pad[0x14C]; unsigned char ready; };
struct Self413900 { char pad[0x1E0]; int h1E0; int p1E4; Arc413900* arc; };

extern "C" {
int func_004134B0(Self413900* self, Str413900* out, int name, int flags);
char* func_001692D0(Str413900* s);
Arc413900* Archive_Open(int h, char* name, int a, int b);
void func_00138B70(Str413900* s, int flags);
}

#pragma push
#pragma opt_propagation off
extern "C" void func_00413900(Self413900* self, int name)
{
    bool ok = false;
    if (self->p1E4 && self->h1E0) {
        Str413900 s;
        Str413900* ps = &s;
        ps->a = 0; ps->b = 0; ps->c = 0;
        if (func_004134B0(self, ps, name, 0)) {
            self->arc = Archive_Open(self->h1E0, func_001692D0(&s), 1, 0);
            if (self->arc->ready) ok = true;
        }
        func_00138B70(&s, 0);
    }
    if (!ok) self->arc = 0;
}
#pragma pop
