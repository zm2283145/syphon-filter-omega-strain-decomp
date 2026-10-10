#include "types.h"

typedef struct Obj3 {
    int base;
    int unk4;
    int unk8;
} Obj3;

extern void func_0020BC20(Obj3* self, int arg, int flags);

/* Constructor: base init with (arg, 0), then clears the two following words. */
Obj3* func_0020BBE0(Obj3* self, int arg) {
    func_0020BC20(self, arg, 0);
    self->unk4 = 0;
    self->unk8 = 0;
    return self;
}
