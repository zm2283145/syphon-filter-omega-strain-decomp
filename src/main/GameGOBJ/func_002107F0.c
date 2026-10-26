#include "types.h"
typedef struct { int a; int b; int c; signed char d; } Desc_2107F0;
extern int NetRegisterObjectStart(void);
extern int NetObjectField(void* out, int a, int b, int c, int d, Desc_2107F0* desc);
extern int NetRegisterStructure(int* h, void* name, int n);
extern void NetRegisterRemoteObjectCallback(int h, void* a, void* b, void* c);
extern int D_0048AAE8;
extern void func_002106F0();
extern void func_00210620();
extern void func_00210780();
void tGimmeTheElevatorMenu_NetRegister(void)
{
    int out[1];
    Desc_2107F0 desc;
    desc.a = 1000;
    desc.b = 1;
    desc.d = 0x40;
    desc.c = 0;
    if (NetRegisterObjectStart() == 0 && NetObjectField(out, 0, 4, 5, 1, &desc) == 0 &&
        NetRegisterStructure(&D_0048AAE8, "tGimmeTheElevatorMenu", 8) == 0)
        NetRegisterRemoteObjectCallback(D_0048AAE8, func_002106F0, func_00210620, func_00210780);
}