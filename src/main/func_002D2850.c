#include "types.h"
extern int func_002E9A10(void);
extern int Event_UnpackHeader(void* f);
extern int func_002E9A98(void* f, void* buf, int size, int count);
extern int NetMsg_RegisterType(void* t, int id, void* fn);
extern char D_0051F090[];
extern void cNetLabelMsg_NetReceive(void);
unsigned char cNetLabelMsg_NetRegister(void)
{
    struct { long long file; unsigned char a; int b; int c; int d; } L;
    unsigned char ok = 0;
    if (func_002E9A10() == 0 && Event_UnpackHeader(&L.file) &&
        func_002E9A98(&L.file, &L.a, 1, 1) == 0 &&
        func_002E9A98(&L.file, &L.b, 4, 1) == 0 &&
        func_002E9A98(&L.file, &L.c, 4, 1) == 0 &&
        func_002E9A98(&L.file, &L.d, 4, 1) == 0 &&
        NetMsg_RegisterType(D_0051F090, 2, cNetLabelMsg_NetReceive) == 0)
        ok = 1;
    return ok;
}