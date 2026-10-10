#include "types.h"
typedef struct { int h0; int h4; unsigned char b8; int iC; int i10; char name[16]; } F6ObjNet;
extern int func_002E9A10(void);
extern int func_003C9C30(F6ObjNet*);
extern int func_002E9A98(F6ObjNet*, void*, int, int);
extern int NetMsg_RegisterType(void*, int, void*);
extern char D_0051F0B8[];
extern void ObjectiveNet_OnReceive(void);
unsigned char ObjectiveNet_Setup(void)
{
    F6ObjNet s;
    int err;
    unsigned char ok = 0;
    err = func_002E9A10();
    if (err == 0 && func_003C9C30(&s) && err == 0
        && func_002E9A98(&s, &s.iC, 4, 1) == 0
        && func_002E9A98(&s, &s.b8, 1, 1) == 0
        && func_002E9A98(&s, &s.i10, 4, 1) == 0
        && func_002E9A98(&s, s.name, 1, 16) == 0
        && NetMsg_RegisterType(D_0051F0B8, 2, ObjectiveNet_OnReceive) == 0) {
        ok = 1;
    }
    return ok;
}