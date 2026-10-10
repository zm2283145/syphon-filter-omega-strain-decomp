#include "types.h"

extern void func_0036CAC0(void* target, int id, int value, int flag);

typedef struct { unsigned int flags; char pad[0x80]; short id; char pad2[0x12]; void* target; } Obj;

/* If flag bit 1 is set, forwards *value to the target and returns true. */
unsigned char func_0036D950(Obj* self, int* value)
{
    unsigned char result = 0;
    if (self->flags & 2) {
        func_0036CAC0(self->target, self->id, *value, 1);
        result = 1;
    }
    return result;
}
