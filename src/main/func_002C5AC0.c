#include "types.h"
typedef struct { char d[0x2E0]; } Save5AC0;
extern void func_001584B0(void* buf);
extern int func_002E9A10(void);
extern int func_003C9C30(void* f);
extern int func_002E9A98(void* f, void* buf, int size, int count);
extern int NetMsg_RegisterType(void* t, int id, void* fn);
extern char D_0051EE50[];
extern void func_002C5B80(void);
unsigned char func_002C5AC0(void)
{
    struct { long long file; long long version; Save5AC0 buf; } L;
    int err;
    unsigned char ok;
    Save5AC0* p;
    ok = 0;
    p = &L.buf;
    func_001584B0(p);
    err = func_002E9A10();
    if (err == 0 && func_003C9C30(&L.file) && err == 0 &&
        func_002E9A98(&L.file, &L.version, 4, 1) == 0 &&
        func_002E9A98(&L.file, p, 0x2E0, 1) == 0 &&
        NetMsg_RegisterType(D_0051EE50, 2, func_002C5B80) == 0)
        ok = 1;
    return ok;
}