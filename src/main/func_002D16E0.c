#include "types.h"
extern int func_002E9A10(void);
extern int Event_UnpackHeader(void* f);
extern int func_002E9A98(void* f, void* buf, int size, int count);
extern int NetMsg_RegisterType(void* t, int id, void* fn);
extern char D_0051F070[];
extern void func_002D1810(void);
unsigned char func_002D16E0(void)
{
    struct { long long file; int a; int b; } L;
    int err;
    unsigned char ok;
    ok = 0;
    err = func_002E9A10();
    if (err == 0 && Event_UnpackHeader(&L.file) && err == 0 &&
        func_002E9A98(&L.file, &L.a, 4, 1) == 0 &&
        func_002E9A98(&L.file, &L.b, 4, 1) == 0 &&
        NetMsg_RegisterType(D_0051F070, 2, func_002D1810) == 0)
        ok = 1;
    return ok;
}