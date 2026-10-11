#include "types.h"
extern int func_002E9A10(void);
extern int func_003C9C30(void* f);
extern int func_002E9A98(void* f, void* buf, int size, int count);
extern int NetMsg_RegisterType(void* t, int id, void* fn);
extern char D_0051F090[];
extern void func_002D2650(void);
unsigned char func_002D2850(void)
{
    struct { long long file; unsigned char a; int b; int c; int d; } L;
    unsigned char ok = 0;
    if (func_002E9A10() == 0 && func_003C9C30(&L.file) &&
        func_002E9A98(&L.file, &L.a, 1, 1) == 0 &&
        func_002E9A98(&L.file, &L.b, 4, 1) == 0 &&
        func_002E9A98(&L.file, &L.c, 4, 1) == 0 &&
        func_002E9A98(&L.file, &L.d, 4, 1) == 0 &&
        NetMsg_RegisterType(D_0051F090, 2, func_002D2650) == 0)
        ok = 1;
    return ok;
}