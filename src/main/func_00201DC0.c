#include "types.h"

typedef struct { int unk0; int unk4; int unk8; } Obj;
extern void func_00201E00(Obj* self, int a, int b);

/* Constructor: base init then clears +4/+8. */
Obj* func_00201DC0(Obj* self, int a)
{
    func_00201E00(self, a, 0);
    self->unk4 = 0;
    self->unk8 = 0;
    return self;
}
