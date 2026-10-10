#include "types.h"

typedef struct Body {
    char part0[0xD0];
    float fD0;
    char padD4[0xC];
    char partE0[0x10];
    char partF0[0x10];
    float f100;
    char pad104[0xC];
    char part110[0x40];
    char part150[0x10];
    int i160;
    int i164;
} Body;

typedef struct Obj178 {
    int id;
    char pad[0xC];
    Body body;
} Obj178;

extern void func_003B6C20(void*, void*);
extern void func_00132800(void*, void*);
extern void Vec4_Assign(void*, void*);
extern void func_003B6BC0(void*, void*);

/* Assignment operator: copies each member. */
Obj178* func_003B6B20(Obj178* self, Obj178* other) {
    Body* d;
    self->id = other->id;
    d = &self->body;
    func_003B6C20(d->part0, other->body.part0);
    d->fD0 = other->body.fD0;
    func_00132800(d->partE0, other->body.partE0);
    Vec4_Assign(d->partF0, other->body.partF0);
    d->f100 = other->body.f100;
    func_003B6BC0(d->part110, other->body.part110);
    func_00132800(d->part150, other->body.part150);
    d->i160 = other->body.i160;
    d->i164 = other->body.i164;
    return self;
}
