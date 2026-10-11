#include "types.h"
extern int func_002E9A10(void* reg);
extern int func_003C9C30(void* desc);
extern int func_003FF2C0(void);
extern int func_002E9A98(void* desc, void* field, int size, int count);
extern int func_002E9F08(void* t, void* fn);
extern int D_0055A218;
extern void func_003E4240(void);
unsigned char func_003E5060(void* reg)
{
    struct { long long file; char padC[4]; int fC; int f10; char f14[16]; char f24[12]; } L;
    unsigned char ok = 0;
    if (func_002E9A10(reg) == 0 && func_003FF2C0() != 0
        && func_002E9A98(&L.file, &L.fC, 4, 1) == 0
        && func_002E9A98(&L.file, &L.f10, 4, 1) == 0
        && func_002E9A98(&L.file, L.f14, 16, 1) == 0
        && func_002E9A98(&L.file, L.f24, 12, 1) == 0
        && func_002E9F08(&D_0055A218, func_003E4240) == 0)
        ok = 1;
    return ok;
}
