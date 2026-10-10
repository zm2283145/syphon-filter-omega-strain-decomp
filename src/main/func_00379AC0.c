#include "types.h"

typedef struct { char pad[0x10]; char blockA[0x40]; char blockB[0xB4]; unsigned char useA; } Obj104;
extern void func_00374DF0(Obj104* o);

/* Updates the object, then returns block +0x10 when the flag at +0x104 is set, else block +0x50. */
void* func_00379AC0(Obj104* o)
{
    func_00374DF0(o);
    if (o->useA)
        return o->blockA;
    return o->blockB;
}
