#pragma cplusplus on
#include "types.h"
struct E3339E0 { int name; int idx; int pad[4]; };
struct A3339E0 { char pad[0x84]; int bits[8]; };
extern "C" {
extern char D_005329F0[];
extern int D_005329F4;
E3339E0** func_003305C0(void* v);
const char* func_003FDAE0(int name);
int func_00333890(A3339E0* self, const char* a, const char* b, char wild);
}
static inline bool Neq3339E0(E3339E0* a, E3339E0* b) { return !(a == b); }
static inline bool Done3339E0(A3339E0* self, int idx)
{
    int r;
    if (idx > -1) r = ((self->bits[idx / 32] >> (idx & 31)) & 1) != 0;
    else { r = 0; asm { .set reorder } }
    return r;
}
extern "C" int cAgentData_AreObjectivesComplete(A3339E0* self, const char* pattern)
{
    E3339E0* first = *func_003305C0(D_005329F0);
    E3339E0* last = *func_003305C0(D_005329F0) + D_005329F4;
    for (; Neq3339E0(first, last); first++) {
        if (func_00333890(self, pattern, func_003FDAE0(first->name), '*')) {
            if (!Done3339E0(self, first->idx)) return 0;
        }
    }
    return 1;
}
