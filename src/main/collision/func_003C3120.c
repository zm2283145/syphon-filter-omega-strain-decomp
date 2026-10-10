#include "types.h"

typedef struct Obj3C3 {
    char pad[0xC];
    char flag;
} Obj3C3;

extern void func_003C3170(Obj3C3* self, int* src, int flag);
extern void func_001396D0(Obj3C3* self, int value);

/* Constructor: base init, applies *src, then stores the flag byte at +0xC. */
Obj3C3* func_003C3120(Obj3C3* self, int* src, int flag) {
    func_003C3170(self, src, flag);
    func_001396D0(self, *src);
    self->flag = flag;
    return self;
}
