#include "types.h"

typedef struct { char pad[0x23D8]; void* pending; char pad2[0x255C - 0x23DC]; int state; } Obj;
extern void func_0044F6B0(void* p);
extern void func_00452FC0(Obj* self, int a);

/* Moves from state 1 to state 9, releasing the pending object. */
void func_0044C3C0(Obj* self)
{
    if (self->state != 9 && self->state == 1) {
        self->state = 9;
        if (self->pending) {
            func_0044F6B0(self->pending);
        }
        self->pending = 0;
        func_00452FC0(self, 0);
    }
}
