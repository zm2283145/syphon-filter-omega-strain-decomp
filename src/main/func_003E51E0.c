#include "types.h"
extern int func_002E9A10(void* reg);
extern int func_003FF2C0(void);
extern int func_002E9A98(void* desc, void* field, int size, int count);
extern int func_002E9F08(void* type, void* factory);
extern int D_0055A208;
extern void func_003E49B0(void);
unsigned char func_003E51E0(void* reg)
{
    struct { long long file; int pad; char a[16]; int b; int c; char d; } L;
    unsigned char ok = 0;
    if (func_002E9A10(reg) == 0 && func_003FF2C0() != 0
        && func_002E9A98(&L.file, L.a, 0x10, 1) == 0
        && func_002E9A98(&L.file, &L.b, 4, 1) == 0
        && func_002E9A98(&L.file, &L.c, 4, 1) == 0
        && func_002E9A98(&L.file, &L.d, 1, 1) == 0
        && func_002E9F08(&D_0055A208, func_003E49B0) == 0)
        ok = 1;
    return ok;
}