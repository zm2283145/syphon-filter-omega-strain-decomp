#include "types.h"
typedef struct { int h0; int h4; unsigned char b8; int iC; int i10; char name[1]; } F6ObjNet;
extern int func_002E9A10(void);
extern int func_003C9C30(F6ObjNet*);
extern int func_002E9A98(F6ObjNet*, void*, int, int);
extern int NetMsg_RegisterType(void*, int, void*);
extern char D_0051F0A0[];
extern void func_002D7190(void);
unsigned char func_002D7020(void)
{
    F6ObjNet s;
    int err;
    unsigned char ok = 0;
    err = func_002E9A10();
    if (err == 0 && func_003C9C30(&s) && err == 0
        && func_002E9A98(&s, &s.b8, 1, 1) == 0 && func_002E9A98(&s, &s.iC, 4, 1) == 0 && func_002E9A98(&s, &s.i10, 4, 1) == 0 && func_002E9A98(&s, s.name, 4, 1) == 0
        && NetMsg_RegisterType(D_0051F0A0, 2, func_002D7190) == 0) {
        ok = 1;
    }
    return ok;
}