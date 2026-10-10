#include "types.h"

typedef struct { char pad[0xC]; unsigned char flag; } Obj0C;
extern void func_00290B90(Obj0C* self, int* src, unsigned char flag);
extern void func_001396D0(Obj0C* self, int value);

/* Initializes self from src, sets the value *src and stores flag at +0xC; returns self. */
Obj0C* func_00344EC0(Obj0C* self, int* src, unsigned char flag)
{
    func_00290B90(self, src, flag);
    func_001396D0(self, *src);
    self->flag = flag;
    return self;
}
