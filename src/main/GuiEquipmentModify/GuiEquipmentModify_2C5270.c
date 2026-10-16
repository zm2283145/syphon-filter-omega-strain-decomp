#include "types.h"
typedef struct {
    unsigned char a, b, c;
    int d;
    int e;
    int f;
    int g;
    int h;
} Cfg5270;
extern int func_002E9A10(void);
extern int func_003C9C30(void* f);
extern int func_002E9A98(void* f, void* buf, int size, int count);
extern int NetMsg_RegisterType(void* t, int id, void* fn);
extern char D_0051EE40[];
extern void func_002C50E0(void);
unsigned char func_002C5270(void)
{
    struct { long long file; Cfg5270 cfg; } L;
    unsigned char ok = 0;
    if (func_002E9A10() == 0 && func_003C9C30(&L.file) &&
        func_002E9A98(&L.file, &L.cfg.a, 1, 1) == 0 &&
        func_002E9A98(&L.file, &L.cfg.e, 4, 1) == 0 &&
        func_002E9A98(&L.file, &L.cfg.f, 4, 1) == 0 &&
        func_002E9A98(&L.file, &L.cfg.h, 4, 1) == 0 &&
        func_002E9A98(&L.file, &L.cfg.g, 4, 1) == 0 &&
        func_002E9A98(&L.file, &L.cfg.b, 1, 1) == 0 &&
        func_002E9A98(&L.file, &L.cfg.c, 1, 1) == 0 &&
        func_002E9A98(&L.file, &L.cfg.d, 4, 1) == 0 &&
        NetMsg_RegisterType(D_0051EE40, 2, func_002C50E0) == 0)
        ok = 1;
    return ok;
}