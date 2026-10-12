#include "types.h"
/* Loads the saved settings block field by field, then registers the net message type. */
extern int func_002E9A10(void);
extern int func_003C9C30(void* f);
extern int func_002E9A98(void* f, void* buf, int size, int count);
extern int NetMsg_RegisterType(void* t, int id, void* fn);
extern char D_0051F060[];
extern void func_002D11D0(void);
unsigned char func_002D0FE0(void)
{
    struct { long long file; int a, b, c; float d[3]; float e[3]; int f, g; } L;
    int err; unsigned char ok = 0; err = func_002E9A10();
    if (err == 0 && func_003C9C30(&L.file) && err == 0 &&
        func_002E9A98(&L.file, &L.a, 4, 1) == 0 &&
        func_002E9A98(&L.file, &L.b, 4, 1) == 0 &&
        func_002E9A98(&L.file, &L.c, 4, 1) == 0 &&
        func_002E9A98(&L.file, L.d, 12, 3) == 0 &&
        func_002E9A98(&L.file, L.e, 12, 3) == 0 &&
        func_002E9A98(&L.file, &L.f, 4, 1) == 0 &&
        func_002E9A98(&L.file, &L.g, 4, 1) == 0 &&
        NetMsg_RegisterType(D_0051F060, 2, func_002D11D0) == 0)
        ok = 1;
    return ok;
}
