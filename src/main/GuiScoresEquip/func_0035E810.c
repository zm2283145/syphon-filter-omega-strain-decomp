#include "types.h"

typedef struct { char data[0x18]; } Part18;
typedef struct { char data[8]; } Part8;
typedef struct { int unk0; float f[5]; Part18 a; Part8 b; unsigned char flag; } Obj35E;

extern void func_001BED80(Part18* dst, Part18* src);
extern float func_001BED70(Part8* p);
extern void func_001BED50(Part8* dst, Part18* ref, float value);

/* Copies src into self (floats, sub-objects and flag); returns self. */
Obj35E* func_0035E810(Obj35E* self, Obj35E* src)
{
    self->f[0] = src->f[0];
    self->f[1] = src->f[1];
    self->f[2] = src->f[2];
    self->f[3] = src->f[3];
    self->f[4] = src->f[4];
    func_001BED80(&self->a, &src->a);
    func_001BED50(&self->b, &self->a, func_001BED70(&src->b));
    self->flag = src->flag;
    return self;
}
