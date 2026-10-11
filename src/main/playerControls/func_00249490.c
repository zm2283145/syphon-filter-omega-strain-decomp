#include "types.h"
typedef struct { float x, y, z; } Vec49;
typedef struct { unsigned char b0; char pad[15]; Vec49 v; } Slot49c;
typedef struct { char pad[0x140]; Slot49c* p140; } Owner49c;
typedef struct { char pad[0x3584]; Slot49c* p3584; } Ctx49c;
void func_00249490(Owner49c* self, Ctx49c* ctx, Vec49* v) {
    if (!self->p140) self->p140 = ctx->p3584;
    if (self->p140) {
        Slot49c* s = self->p140;
        s->b0 = 1;
        s->v.x = v->x;
        s->v.y = v->y;
        s->v.z = v->z;
    }
}