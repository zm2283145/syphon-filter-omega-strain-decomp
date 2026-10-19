#include "types.h"
typedef struct { int a; int b; } Desc00211540;
typedef struct { int a; char b; } Proto00211540;
extern int func_002E9A10(void* reg);
extern int Event_UnpackHeader(Desc00211540* d);
extern int func_002E9A98(Desc00211540* d, void* field, int size, int count);
extern int NetMsg_RegisterType(void* type, int version, void* factory);
extern char D_004F54C0[];
extern void func_002115E0(void);
unsigned char func_00211540(void* reg)
{
    Proto00211540 p;
    Desc00211540 d;
    unsigned char ok = 0;
    if (func_002E9A10(reg) == 0 && Event_UnpackHeader(&d) != 0 &&
        func_002E9A98(&d, &p.a, 4, 1) == 0 &&
        func_002E9A98(&d, &p.b, 1, 1) == 0 &&
        NetMsg_RegisterType(D_004F54C0, 2, func_002115E0) == 0)
        ok = 1;
    return ok;
}