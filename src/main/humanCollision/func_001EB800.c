#include "types.h"

typedef struct { char pad[0xC]; char flag; } Obj1EB;
extern void func_001EB850(Obj1EB* self);
extern void func_001EF530(Obj1EB* self, int value);

/* Constructs the object: base init, sets the value from *src and stores the flag byte; returns self. */
Obj1EB* func_001EB800(Obj1EB* self, int* src, char flag)
{
    func_001EB850(self);
    func_001EF530(self, *src);
    self->flag = flag;
    return self;
}
