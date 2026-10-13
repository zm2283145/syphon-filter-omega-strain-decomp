#pragma cplusplus on
#include "types.h"

extern "C" void Appearance_RegistryKey(char* dst, int n, char* src);

struct V4_D530 {
 float x, y, z, w;
 V4_D530() {}
 V4_D530(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
} __attribute__((aligned(16)));
static inline void QCopy_D530(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }

struct Id_D530 { int a; unsigned short b; };

struct Obj_D530 {
    char name[0x120];
    __int128 q120[2];
    __int128 q140[0x18];
    char pad2C0[0x3E0 - 0x2C0];
    V4_D530 mn;
    V4_D530 mx;
    int x400;
    int x404;
    unsigned short x408;
    short idx;
    unsigned char x40C;
    unsigned char x40D;
    unsigned char x40E;
    unsigned char x40F;
    signed char x410[5];
    unsigned char x415;
    signed char x416;
    signed char x417;
    unsigned char x418;
    unsigned char x419;
    char pad41A[2];
    int x41C;
};



static inline void QZero_D530(void* d0, int n0) { int n = n0; void* d = d0;
    asm {
        .set noreorder
    lp:
        nop
        addi n, n, -1
        sq $zero, 0(d)
        bgtz n, lp
        addiu d, d, 0x10
        .set reorder
    }
}

/* Retail evaluates (mn, mx, &z) before the second copy: the tail is an inline taking all three. */
static inline void FinJ_D530(V4_D530* a, V4_D530* pv0, V4_D530* b)
{
    V4_D530 t2(-3.4028235e38f, -3.4028235e38f, -3.4028235e38f, 1.0f);
    QCopy_D530(pv0, &t2);
    b->x = 0.0f; b->y = 0.0f; b->z = 0.0f; b->w = 0.0f;
    __asm__ volatile("lqc2 vf1, 0x0(%0); lqc2 vf2, 0x0(%1); lqc2 vf3, 0x0(%2); vmini.xyz vf1, vf1, vf3; vmax.xyz vf2, vf2, vf3; sqc2 vf1, 0x0(%0); sqc2 vf2, 0x0(%1)" : : "r"(a), "r"(pv0), "r"(b) : "memory");
}

extern "C" void func_0038D530(Obj_D530* self, char* name, int idx, Id_D530* id,
                              int a, int b, int c, int d)
{
    Appearance_RegistryKey(self->name, 0x1F, name);
    self->x400 = 0;
    self->x40D = c;
    self->x40E = d;
    self->x404 = 0;
    if (id) {
        self->x404 = id->a;
        self->x408 = id->b;
    }
    self->idx = idx;
    self->x40C = 0;
    self->x40F = 0;
    self->x410[0] = -1;
    self->x410[1] = -1;
    self->x410[2] = -1;
    self->x410[3] = -1;
    self->x410[4] = -1;
    self->x417 = -1;
    self->x415 = 0;
    self->x416 = -1;
    self->x41C = 0;
    self->x418 = b;
    self->x419 = a;
    V4_D530 z;
    V4_D530 t1(3.4028235e38f, 3.4028235e38f, 3.4028235e38f, 1.0f);
    QCopy_D530(&self->mn, &t1);
    void* xx = &self->mx;
    FinJ_D530(&self->mn, &self->mx, &z);
    QZero_D530(self->q140, 0x18);
    QZero_D530(self->q120, 2);
    ((float*)self->q140)[-1] = 1.0f;
}
