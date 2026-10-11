#include "types.h"
typedef struct { unsigned char b0; char pad[3]; int f4; int f8; char fC; } Slot49;
typedef struct { char pad[0x13C]; void* p13C; Slot49* p140; } Owner49;
typedef struct { char pad[0x3584]; Slot49* p3584; } Ctx49;
void func_00249460(Owner49* self, Ctx49* ctx) {
    if (!self->p140) self->p140 = ctx->p3584;
    if (self->p140) self->p140->b0 = 0;
}