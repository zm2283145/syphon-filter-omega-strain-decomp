#pragma cplusplus on
#include "types.h"
#pragma opt_propagation off
#pragma opt_common_subs off

extern "C" {
int func_0012AC20(char*, char**);
float func_0011C928(int);
char* strchr(const char*, int);
long func_0012B1F0(char*, char**, int);
}

struct V4_3A3F80 {
    float x, y, z, w;
    V4_3A3F80& operator=(const V4_3A3F80& o)
    {
        __int128 t;
        __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory");
        { void* xx = this; } /* dead on purpose: retail recomputes &v[k] after each copy */
        return *this;
    }
} __attribute__((aligned(16)));

struct Obj3A3F80 {
    char pad0[0x18];
    float f18, f1C, f20, f24, f28, f2C, f30, f34;
    char pad38[0x15C - 0x38];
    float f15C;
    char pad160[0x16C - 0x160];
    float f16C;
    char pad170[0x8F4 - 0x170];
    int i8F4;
    char pad8F8[0x900 - 0x8F8];
    V4_3A3F80 v[9];
    float f990, f994, f998, f99C, f9A0, f9A4, f9A8, f9AC;
    float f9B0, f9B4, f9B8, f9BC, f9C0, f9C4;
    int i9C8;
    unsigned char b9CC;
};

struct Mk3A3F80 : V4_3A3F80 {
    Mk3A3F80(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
};

extern "C" void func_003A3F80(Obj3A3F80* self, char* str, float ver)
{
    char* s = str;
    self->f990 = func_0011C928(func_0012AC20(s, &s));
    self->f994 = func_0011C928(func_0012AC20(s, &s));
    s = strchr(s, '\n') + 1;
    self->f9A0 = func_0011C928(func_0012AC20(s, &s));
    self->f9A4 = func_0011C928(func_0012AC20(s, &s));
    s = strchr(s, '\n') + 1;
    self->f998 = func_0011C928(func_0012AC20(s, &s));
    self->f99C = func_0011C928(func_0012AC20(s, &s));
    s = strchr(s, '\n') + 1;
    self->f9A8 = func_0011C928(func_0012AC20(s, &s));
    self->f9AC = func_0011C928(func_0012AC20(s, &s));
    self->f9AC = self->f9AC / self->f9A8;
    s = strchr(s, '\n') + 1;
    self->f9B0 = func_0011C928(func_0012AC20(s, &s));
    self->f9B4 = 0.0f;
    s = strchr(s, '\n') + 1;
    self->f9B8 = func_0011C928(func_0012AC20(s, &s));
    self->f9BC = func_0011C928(func_0012AC20(s, &s));
    s = strchr(s, '\n') + 1;
    if (ver >= 1.5f) {
        self->f9C0 = func_0011C928(func_0012AC20(s, &s));
        self->f9C4 = func_0011C928(func_0012AC20(s, &s));
        s = strchr(s, '\n') + 1;
        self->i8F4 = func_0012B1F0(s, &s, 10);
        s = strchr(s, '\n') + 1;
    } else {
        self->f9C0 = 0.0f;
        self->f9C4 = 0.0f;
        self->i8F4 = 0;
    }
    if (ver >= 2.0f) {
        self->i9C8 = func_0012B1F0(s, &s, 10);
        if (self->i9C8 == 0) self->i9C8 = 1;
        self->b9CC = func_0012B1F0(s, &s, 10) != 0;
        s = strchr(s, '\n') + 1;
    } else {
        self->i9C8 = 1;
        self->b9CC = 0;
    }
    {
    V4_3A3F80* d0 = &self->v[0];
    *d0 = Mk3A3F80(self->f990, self->f998, self->f9B8, self->f9B0);
    }
    {
    self->v[1] = Mk3A3F80(self->f994, self->f99C, self->f9BC, self->f9B4);
    self->v[2] = Mk3A3F80(0.0f, self->f9A0, self->f9C0, self->f9C4);
    self->v[3] = Mk3A3F80(0.0f, self->f9A4, self->f2C, self->f18);
    self->v[4] = Mk3A3F80(self->f30, self->f34, self->f1C, self->f24);
    self->v[5] = Mk3A3F80(self->f15C, self->f16C, self->f20, self->f28);
    }
}
