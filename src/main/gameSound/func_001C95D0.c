#pragma cplusplus on
#include "types.h"
struct E1C95D0 { int type; char pad4[0xC]; char name[0x34]; unsigned char active; char pad45[0x1B0 - 0x45]; };
struct S1C95D0 { char pad[0x50]; E1C95D0 slots[50]; };
extern "C" int String_CompareNoCase(const char* a, const char* b);
static inline bool B1C95D0_eq(unsigned char a, int b) { return a == b; }
extern "C" bool func_001C95D0(S1C95D0* s, const char* name)
{
    int i;
    for (i = 0; i < 50; i++) {
        E1C95D0* e = &s->slots[i];
        if (e->type == 4 && String_CompareNoCase(e->name, name) == 0)
            return !B1C95D0_eq(e->active, 0);
    }
    return false;
}