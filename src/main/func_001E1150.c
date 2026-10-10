#include "types.h"

typedef struct { char pad[0xC]; unsigned char flag; } Obj1E;

extern void func_001E1300(Obj1E* self);
extern void func_001E12E0(Obj1E* self, int* value);

/* Initializes the object, sets its flag and assigns the given value; returns self. */
Obj1E* func_001E1150(Obj1E* self, int value)
{
    func_001E1300(self);
    self->flag = 1;
    func_001E12E0(self, &value);
    return self;
}
