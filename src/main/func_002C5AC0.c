#include "types.h"
typedef struct { char d[0x2E0]; } Save5AC0;
extern void func_001584B0(void* buf);
extern int func_002E9A10(void);
extern int Event_UnpackHeader(void* f);
extern int func_002E9A98(void* f, void* buf, int size, int count);
extern int NetMsg_RegisterType(void* t, int id, void* fn);
extern char D_0051EE50[];
extern void cNetCopyMsg_NetReceive(void);
unsigned char cNetCopyMsg_NetRegister(void)
{
    struct { long long file; long long version; Save5AC0 buf; } L;
    int err;
    unsigned char ok;
    Save5AC0* p;
    ok = 0;
    p = &L.buf;
    func_001584B0(p);
    err = func_002E9A10();
    if (err == 0 && Event_UnpackHeader(&L.file) && err == 0 &&
        func_002E9A98(&L.file, &L.version, 4, 1) == 0 &&
        func_002E9A98(&L.file, p, 0x2E0, 1) == 0 &&
        NetMsg_RegisterType(D_0051EE50, 2, cNetCopyMsg_NetReceive) == 0)
        ok = 1;
    return ok;
}