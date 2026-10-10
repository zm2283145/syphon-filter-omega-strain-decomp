#include "types.h"
typedef struct { int pad0; int size; char pad8[0x40]; long unk48; } Obj;
/* Resets the object's 64-bit field at +0x48 and sets size 0x2000. */
int func_0010D918(int unused, Obj* o)
{
    o->unk48 = 0;
    o->size = 0x2000;
    return 0;
}
