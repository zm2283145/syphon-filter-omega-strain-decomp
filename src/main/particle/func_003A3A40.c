#pragma cplusplus on
#include "types.h"
#pragma opt_propagation off
#pragma opt_common_subs off

extern "C" {
int func_0012AC20(char*, char**);
float SoftFloat_DoubleToFloat(int);
char* strchr(const char*, int);
long func_0012B1F0(char*, char**, int);
}

struct V4_3A3A40 {
    float x, y, z, w;
    V4_3A3A40& operator=(const V4_3A3A40& o)
    {
        __int128 t;
        __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));

struct Obj3A3A40 {
    char pad0[0x18];
    float f18, f1C, f20, f24, f28, f2C, f30, f34;
    char pad38[0x4C - 0x38];
    float f4C;
    char pad50[0x64 - 0x50];
    unsigned char b64;
    char pad65[0x15C - 0x65];
    float f15C;
    char pad160[0x16C - 0x160];
    float f16C;
    char pad170[0x8F4 - 0x170];
    int i8F4;
    char pad8F8[0x910 - 0x8F8];
    V4_3A3A40 v910, v920, v930, v940;
    char pad950[0x974 - 0x950];
    float f974, f978;
    char pad97C[0x980 - 0x97C];
    float f980, f984, f988, f98C;
    V4_3A3A40 v990;
    float f9A0, f9A4, f9A8, f9AC;
    char pad9B0[0xA20 - 0x9B0];
    float fA20, fA24, fA28, fA2C, fA30, fA34, fA38;
    int iA3C;
    float fA40, fA44, fA48, fA4C, fA50, fA54, fA58, fA5C, fA60, fA64, fA68, fA6C;
};

struct Mk3A3A40 : V4_3A3A40 {
    Mk3A3A40(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
};

#define RD() SoftFloat_DoubleToFloat(func_0012AC20(s, &s))
#define NL() s = strchr(s, '\n') + 1

extern "C" void func_003A3A40(Obj3A3A40* self, char* str)
{
    char* s = str;
    self->fA20 = RD();
    self->fA24 = RD();
    self->fA28 = RD();
    NL();
    self->fA2C = RD();
    self->fA30 = RD();
    NL();
    self->fA34 = RD();
    self->fA38 = RD();
    self->iA3C = func_0012B1F0(s, &s, 10);
    NL();
    self->fA40 = RD();
    self->fA44 = RD();
    self->fA48 = RD();
    self->fA4C = 1.0f;
    NL();
    self->fA50 = RD();
    self->fA54 = RD();
    self->fA58 = RD();
    self->fA5C = 1.0f;
    NL();
    self->fA60 = RD();
    self->fA64 = RD();
    self->fA68 = RD();
    self->fA6C = 1.0f;
    NL();
    self->f980 = RD();
    self->f988 = RD();
    self->f9A0 = RD();
    self->f9A8 = RD();
    NL();
    self->f984 = RD();
    self->f98C = RD();
    self->f9A4 = RD();
    self->f9AC = RD();
    NL();
    self->v990 = Mk3A3A40(self->f988, self->f98C, self->f9A0, self->f9A4);
    self->i8F4 = func_0012B1F0(s, &s, 10);
    if (self->i8F4 != 0) self->iA3C = -1;
    self->f974 = self->f4C;
    self->f978 = (unsigned int)self->b64;
    {
    void* d0 = &self->v910; /* dead on purpose */
    void* d1 = &self->v920; /* dead on purpose */
    void* d2 = &self->v930; /* dead on purpose */
    void* d3 = &self->v940; /* dead on purpose */
    self->v910 = Mk3A3A40(self->fA34, self->fA38, self->f2C, self->f18);
    self->v920 = Mk3A3A40(self->f30, self->f34, self->f1C, self->f24);
    self->v930 = Mk3A3A40(self->f15C, self->f16C, self->f20, self->f28);
    self->v940 = Mk3A3A40(self->fA30, self->fA28, self->fA2C, 0.0f);
    }
}
