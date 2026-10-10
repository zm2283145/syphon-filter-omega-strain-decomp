#include "types.h"

typedef struct { float x, y, z, w; } Vec4f;
typedef struct { char pad[0x90]; void* target; char pad2[0xC]; Vec4f color; } Obj;
extern void func_003D0810(void* target, Vec4f* color);

/* Stores a colour and pushes it to the attached target. */
void func_00425DB0(Obj* self, Vec4f* color)
{
    self->color.x = color->x;
    self->color.y = color->y;
    self->color.z = color->z;
    self->color.w = color->w;
    if (self->target) {
        func_003D0810(self->target, &self->color);
    }
}
