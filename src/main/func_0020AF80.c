#include "types.h"

typedef struct { int unk0; int unk4; int unk8; } Obj;
extern void func_0020AFC0(Obj* self, int a, int b);

/* Constructor: base init then clears +4/+8. */
#pragma optimization_level 1
Obj* func_0020AF80(Obj* self, int a)
{
    func_0020AFC0(self, a, 0);
    self->unk4 = 0;
    self->unk8 = 0;
    return self;
}
#pragma optimization_level reset
