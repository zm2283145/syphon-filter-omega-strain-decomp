#include "types.h"

typedef struct { int unk0; int unk4; int unk8; } Obj;
extern void func_001F3140(Obj* self, int a);

/* Constructor: base init then clears +4/+8. */
Obj* func_001F3100(Obj* self)
{
    func_001F3140(self, 0);
    self->unk4 = 0;
    self->unk8 = 0;
    return self;
}
