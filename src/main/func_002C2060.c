#include "types.h"

typedef struct Obj2C20 {
    char pad00[0xC];
    unsigned char flag; /* 0x0C */
} Obj2C20;

extern void func_00290B90(Obj2C20* self, int* src, unsigned char flag);
extern void func_001396D0(Obj2C20* self, int value);

/* Constructor: base init, copies *src and stores the flag byte. */
Obj2C20* func_002C2060(Obj2C20* self, int* src, unsigned char flag) {
    func_00290B90(self, src, flag);
    func_001396D0(self, *src);
    self->flag = flag;
    return self;
}
