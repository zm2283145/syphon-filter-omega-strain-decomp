#pragma cplusplus on
#include "types.h"

struct Str4133B0 { int a; int b; int c; };
struct List4133B0 { int pad0; int count; Str4133B0* data; };
struct Self4133B0 { char pad[0x1E0]; int h1E0; int p1E4; int arc; List4133B0* list; };

extern "C" {
int func_004134B0(Self4133B0* self, Str4133B0* out, int name, unsigned char* isPak);
char* String_CStr(Str4133B0* s);
int func_003F9850(int h, char* name, int arc);
int Archive_Open(int h, char* name, int a, int b);
void func_00413FB0(List4133B0* list, Str4133B0* pos, int n, Str4133B0* value);
void func_00138B70(Str4133B0* s, int flags);
}

#pragma push
#pragma opt_propagation off
extern "C" int func_004133B0(Self4133B0* self, int* out, int name)
{
    if (!self->list) return 0;
    {
        unsigned char inPak;
        Str4133B0 s;
        Str4133B0* ps = &s;
        ps->a = 0; ps->b = 0; ps->c = 0;
        if (func_004134B0(self, ps, name, &inPak)) {
            if (inPak) {
                *out = func_003F9850(self->h1E0, String_CStr(&s), self->arc);
            } else {
                *out = Archive_Open(self->h1E0, String_CStr(&s), 0, 0);
            }
            func_00413FB0(self->list, &self->list->data[self->list->count], 1, &s);
            func_00138B70(&s, 0);
            return 1;
        }
        func_00138B70(&s, 0);
        return 0;
    }
}
#pragma pop
