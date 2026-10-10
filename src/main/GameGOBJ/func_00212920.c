#include "types.h"

typedef struct { int unk0; int unk4; char pad[4]; unsigned char unkC; char pad2[0x1F]; } NetInit;

extern char D_004A45A8[];
extern int D_004F5480;
extern int func_002E9B60(void);
extern int func_002129A0(NetInit* init);
extern int func_002E9CD0(int* handle, const char* name, int n);
extern void func_002E9D88(int handle, void (*a)(), void (*b)(), void (*c)());
extern void func_00212700();
extern void func_00212540();
extern void func_002128A0();

/* Initializes the network service, opens the named handle and registers its callbacks. */
void func_00212920(void)
{
    NetInit init;
    int handle;
    init.unk0 = 0;
    init.unk4 = 0;
    init.unkC = 0;
    if (func_002E9B60())
        return;
    if (!func_002129A0(&init))
        return;
    if (func_002E9CD0(&handle, D_004A45A8, 0x20))
        return;
    D_004F5480 = handle;
    func_002E9D88(handle, func_00212700, func_00212540, func_002128A0);
}
