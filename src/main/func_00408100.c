#include "types.h"
extern int func_002E9A10(void* reg);
extern int func_003C9C30(void* desc);

extern int func_002E9A98(void* desc, void* field, int size, int count);
extern int NetMsg_RegisterType(void* t, int id, void* fn);
extern int D_005716F8;
extern void func_004081E0(void);
unsigned char func_00408100(void* reg)
{
    struct { long long file; char f8; char padC[3]; int fC; short f10; short f12; short f14; } L;
    unsigned char ok = 0;
    if (func_002E9A10(reg) == 0 && func_003C9C30(&L.file) != 0
        && func_002E9A98(&L.file, &L.f8, 1, 1) == 0
        && func_002E9A98(&L.file, &L.fC, 4, 1) == 0
        && func_002E9A98(&L.file, &L.f10, 2, 1) == 0
        && func_002E9A98(&L.file, &L.f14, 2, 1) == 0
        && func_002E9A98(&L.file, &L.f12, 2, 1) == 0
        && NetMsg_RegisterType(&D_005716F8, 2, func_004081E0) == 0)
        ok = 1;
    return ok;
}
