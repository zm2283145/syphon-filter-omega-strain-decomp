#include "types.h"
typedef struct EnumMember3E0 { int value; char* name; int unk8; } EnumMember3E0;
typedef struct Enum3E0 { char pad00[0x8]; int count; EnumMember3E0* members; } Enum3E0;
typedef struct Vec3E0 { int pad0; int count; Enum3E0** data; } Vec3E0;
extern Vec3E0* D_00554F30;
#pragma opt_strength_reduction off
char* func_003E0040(void* script, int id, int value)
{
    Enum3E0* e;
    int i;
    int n;
    if (id < 10) return "ERROR: invalid enum Id";
    i = id - 10;
    e = D_00554F30->data[i];
    n = e->count;
    i = 0;
    if (i < n) do {
        if (value == e->members[i].value) return (*(EnumMember3E0* volatile*)&e->members)[i].name;
        i++;
    } while (i < n);
    return "ERROR: invalid value";
}
