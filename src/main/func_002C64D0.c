#include "types.h"
extern int func_002E9A10(void);
extern int func_003C9C30(void* f);
extern int func_002E9A98(void* f, void* buf, int size, int count);
extern int NetMsg_RegisterType(void* t, int id, void* fn);
extern char D_0051EE60[];
extern void func_002C6370(void);
unsigned char func_002C64D0(void)
{
    struct { long long file; int v[7]; } L;
    unsigned char ok = 0;
    if (func_002E9A10() == 0 && func_003C9C30(&L.file) &&
        func_002E9A98(&L.file, &L.v[0], 4, 1) == 0 &&
        func_002E9A98(&L.file, &L.v[1], 4, 1) == 0 &&
        func_002E9A98(&L.file, &L.v[2], 4, 1) == 0 &&
        func_002E9A98(&L.file, &L.v[3], 4, 1) == 0 &&
        func_002E9A98(&L.file, &L.v[4], 4, 1) == 0 &&
        func_002E9A98(&L.file, &L.v[5], 4, 1) == 0 &&
        func_002E9A98(&L.file, &L.v[6], 4, 1) == 0 &&
        NetMsg_RegisterType(D_0051EE60, 2, func_002C6370) == 0)
        ok = 1;
    return ok;
}