#include "types.h"
typedef struct { int a; char name[0x40]; } Proto0022E5E0;
extern int func_002E9A10(void* reg);
extern int func_003C9C30(void* d);
extern int func_002E9A98(void* d, void* field, int size, int count);
extern int NetMsg_RegisterType(void* type, int version, void* factory);
extern char D_004F7948[];
extern void func_0022E710(void);
unsigned char func_0022E5E0(void* reg)
{
    struct { long long file; Proto0022E5E0 p; } L;
    unsigned char ok = 0;
    if (func_002E9A10(reg) == 0 && func_003C9C30(&L.file) != 0 &&
        func_002E9A98(&L.file, &L.p.a, 4, 1) == 0 &&
        func_002E9A98(&L.file, L.p.name, 0x40, 0x40) == 0 &&
        NetMsg_RegisterType(D_004F7948, 2, func_0022E710) == 0)
        ok = 1;
    return ok;
}