#include "types.h"

typedef struct { int unk0; int unk4; char pad[4]; unsigned char unkC; char pad2[0x1F]; } NetInit;

extern int D_004F5480;
extern int NetRegisterObjectStart(void);
extern int cPathedGOBJ_RegisterPathedGobj(NetInit* init);
extern int NetRegisterStructure(int* handle, const char* name, int n);
extern void NetRegisterRemoteObjectCallback(int handle, void (*a)(), void (*b)(), void (*c)());
extern void cPathedGOBJ_PathedGobjCreationCallback();
extern void cPathedGOBJ_PathedGobjUpdateCallback();
extern void func_002128A0();

/* Initializes the network service, opens the named handle and registers its callbacks. */
void NetPathedGobj_NetRegister(void)
{
    NetInit init;
    int handle;
    init.unk0 = 0;
    init.unk4 = 0;
    init.unkC = 0;
    if (NetRegisterObjectStart())
        return;
    if (!cPathedGOBJ_RegisterPathedGobj(&init))
        return;
    if (NetRegisterStructure(&handle, "NetPathedGobj", 0x20))
        return;
    D_004F5480 = handle;
    NetRegisterRemoteObjectCallback(handle, cPathedGOBJ_PathedGobjCreationCallback, cPathedGOBJ_PathedGobjUpdateCallback, func_002128A0);
}
