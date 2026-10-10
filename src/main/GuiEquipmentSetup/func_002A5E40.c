#include "types.h"

typedef struct Obj39 {
    int unk0;
    float f[5];
    char sub18[0x18];
    char sub30[8];
    unsigned char flag;
} Obj39;

extern void func_001BED80(void*, void*);
extern float func_001BED70(void*);
extern void func_001BED50(void*, void*, float);

/* Assignment: copies five floats, the sub-object at +0x18, derived data at +0x30 and the flag. */
Obj39* func_002A5E40(Obj39* self, Obj39* other) {
    self->f[0] = other->f[0];
    self->f[1] = other->f[1];
    self->f[2] = other->f[2];
    self->f[3] = other->f[3];
    self->f[4] = other->f[4];
    func_001BED80(self->sub18, other->sub18);
    func_001BED50(self->sub30, self->sub18, func_001BED70(other->sub30));
    self->flag = other->flag;
    return self;
}
