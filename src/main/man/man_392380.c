#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
/* lq/sq quad copies and retail's hand-written quad memclear as asm; the unused xx locals keep retail's dead addius.
   The member arrays' empty ctor loops are explicit do/while walks (placement-new of Arr added a null check);
   each loop starts from the previous end pointer so retail's register reuse is kept. */
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V& operator=(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct Box { V mn; V mx; Box() : mn(3.4028235e38f, 3.4028235e38f, 3.4028235e38f, 1.0f), mx(-3.4028235e38f, -3.4028235e38f, -3.4028235e38f, 1.0f) {} };
struct E40 { char p[0x40]; E40() {} };
struct E50 { char p[0x50]; E50() {} };
static inline __int128 Hi(long long v) { __int128 r; asm { pcpyld r, v, zero } return r; }
static inline void QZero(void* d0, int n0) { int n = n0; void* d = d0;
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
struct Arr {
    E40 a480[0x69];
    char pad1EC0[0x2460 - 0x1EC0];
    E50 a2460[10];
    V a2780[2];
    V a27A0[2];
    E40 a27C0[0x10];
};
struct Man {
    Box box;
    char name[0x460];
    Arr arr;
    char pad2BC0[0x1B];
    unsigned char x2BDB;
    unsigned char x2BDC;
    char pad2BDD[0xF];
    short x2BEC;
    char pad2BEE[0x16];
    int x2C04;
    char pad2C08[6];
    signed char x2C0E;
    signed char x2C0F;
    char pad2C10[0x160];
    int x2D70;
    int x2D74;
    char pad2D78[0x1C];
    short x2D94;
    char pad2D96[2];
    short x2D98;
};
extern "C" {
extern __int128 D_00493A70;
extern __int128 D_00493A80;
extern __int128 D_00493A90;
extern __int128 D_00493AA0;
extern char D_004BC428[];
void String_Copy(char* d, const char* s);
}
#pragma push
#pragma opt_unroll_loops off
extern "C" Man* ManModel_ClearAttachPoints(Man* self)
{
    self->box.mn.x = 3.4028235e38f; self->box.mn.y = 3.4028235e38f; self->box.mn.z = 3.4028235e38f; self->box.mn.w = 1.0f;
    self->box.mx.x = -3.4028235e38f; self->box.mx.y = -3.4028235e38f; self->box.mx.z = -3.4028235e38f; self->box.mx.w = 1.0f;
    { E40* p = self->arr.a480; do { p++; } while (p != self->arr.a480 + 0x69); }
    { E50* p = self->arr.a2460; E50* pe = (E50*)self->arr.a2780; do { p++; } while (p != pe);
      V* p3 = (V*)pe; V* pe3 = self->arr.a27A0; do { p3++; } while (p3 != pe3);
      V* p4 = pe3; V* pe4 = (V*)self->arr.a27C0; do { p4++; } while (p4 != pe4);
      E40* p5 = (E40*)pe4; E40* pe5 = self->arr.a27C0 + 0x10; do { p5++; } while (p5 != pe5); }
    self->x2D74 = -2;
    self->x2D70 = 0;
    {
        int keep = self->x2C04;
        QZero(self, 0x2DF);
        self->x2C04 = keep;
    }
    self->x2D94 = -1;
    self->x2D98 = 300;
    self->x2BEC = 0x80;
    self->x2C0E = -1;
    self->x2C0F = -1;
    self->x2BDB = 1;
    self->x2BDC = 1;
    String_Copy(self->name, D_004BC428);
    D_00493A70 = 0x300000000000000000000000000000;
    D_00493A80 = 0x310000000000000000000000000000;
    D_00493A90 = 0x320000000000000000000000000000;
    D_00493AA0 = 0x330000000000000000000000000000;
    self->box.mn = V(-3.5f, -3.5f, -0.5f, 1.0f);
    self->box.mx = V(3.5f, 3.5f, 7.0f, 1.0f);
    return self;
}
#pragma pop







