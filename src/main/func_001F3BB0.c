#include "types.h"

typedef struct Obj3 {
    int base;
    int unk4;
    int unk8;
} Obj3;

extern void func_001F3BF0(Obj3* self, int arg);

/* Constructor: base init with 0, then clears the two following words. */
Obj3* func_001F3BB0(Obj3* self) {
    func_001F3BF0(self, 0);
    self->unk4 = 0;
    self->unk8 = 0;
    return self;
}
