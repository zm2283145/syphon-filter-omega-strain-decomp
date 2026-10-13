/* 0x004053B0 ManUtils_LoadSKL (mw38). Quad copies use lq/sq GCC asm; operator= decl order
   reproduces the dead duplicate addiu pair. Empty asm barrier (no code) keeps axis on the stack. */
#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
struct V { float x, y, z, w; };
struct M;
extern "C" void func_001D3E20(M*);
extern "C" void Mtx_MakeAxisRotation(M*, float, float, float, float);
struct M {
    union { float m[4][4]; __int128 q[4]; };
    M() {}
    M& operator=(const M& o) { void* xx = (void*)&o; xx = this; __int128 t0; __int128 t1; M* d = this; const M* s = &o; asm volatile("lq %0,0(%2)\n\tlq %1,16(%2)\n\tsq %0,0(%3)\n\tlq %0,32(%2)\n\tsq %1,16(%3)\n\tlq %1,48(%2)\n\tsq %0,32(%3)\n\tsq %1,48(%3)" : "=&r"(t0), "=&r"(t1) : "r"(s), "r"(d) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct File {
    int x0;
    char name[0x9C];
};
extern "C" {
void func_0036E5D0(File* f);
void func_0036E140(File* f, const char* path, int a, int b);
int func_0036DEF0(File* f);
void func_0036DEC0(File* f);
void func_0036E220(File* f, int flags);
}
struct Man {
    char pad0[0x160];
    M m160;
    char pad1A0[0x40];
    float m1E0[3][4];
};
extern "C" {
int sprintf(char*, const char*, ...);
void Appearance_LoadPartSortTable(Man*, const char*);
void func_004029B0(Man*, const char*, void*, M*);
void Mtx_Multiply(M*, M*);
M* Mtx_Copy(M* d, const M* s);
M* Matrix_TransposeInPlace(M* m);
int FileMan_GetSize(File*);
char* FileMan_ReadData(File*);
void Appearance_PackText(void*, char*, int);
extern const char D_004BE860[];
extern const char D_004BE880[];
extern const char D_004BE8A0[];
extern const char D_004BE8C0[];
extern const char D_004BE8E0[];
extern const char D_004BE770[];
extern char D_00493A60;
extern char D_0055D510[];
extern char D_0055D950[];
}
static inline void RotMul(M* a, const V& ax, float ang) { M rot; func_001D3E20(&rot); Mtx_MakeAxisRotation(&rot, ax.x, ax.y, ax.z, ang); Mtx_Multiply(a, &rot); }
static inline M* TransCopy(M* d, const M* s) { M tmp; return Mtx_Copy(d, Matrix_TransposeInPlace(Mtx_Copy(&tmp, s))); }
#pragma push
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_unroll_loops off
extern "C" void ManUtils_LoadSKL(Man* self)
{
    M a;
    V axis;
    M b;
    int i, j;
    Appearance_LoadPartSortTable(self, D_004BE860);
    func_004029B0(self, D_004BE880, (char*)self + 0x120, &a);
    axis.x = 0.0f;
    axis.y = 0.0f;
    axis.z = 1.0f;
    axis.w = 0.0f;
    asm volatile("" : : "r"(&axis) : "memory"); /* barrier: no code */
    RotMul(&a, axis, 3.1415927f);
    {
        M* d = &self->m160;
        __int128 t0, t1;
        M* s = &a;
        asm volatile("lq %0,0(%2)\n\tlq %1,16(%2)\n\tsq %0,0(%3)\n\tlq %0,32(%2)\n\tsq %1,16(%3)\n\tlq %1,48(%2)\n\tsq %0,32(%3)\n\tsq %1,48(%3)" : "=&r"(t0), "=&r"(t1) : "r"(s), "r"(d) : "memory");
    }
    func_004029B0(self, D_004BE8A0, (char*)self + 0x1A0, &a);
    TransCopy(&b, &a);
    a = b;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            self->m1E0[i][j] = a.m[i][j];
        }
    }
    D_00493A60 = 0;
    {
        File f;
        func_0036E5D0(&f);
        func_0036E140(&f, D_004BE8C0, 0, 0);
        if ((unsigned char)func_0036DEF0(&f)) {
            char buf[0x80];
            sprintf(buf, D_004BE770, f.name);
            func_0036E220(&f, -1);
            goto next1;
        }
        int size = FileMan_GetSize(&f);
        Appearance_PackText(D_0055D510, FileMan_ReadData(&f), size);
        func_0036DEC0(&f);
        func_0036E220(&f, -1);
    }
next1:;
    {
        File f;
        func_0036E5D0(&f);
        func_0036E140(&f, D_004BE8E0, 0, 0);
        if ((unsigned char)func_0036DEF0(&f)) {
            char buf[0x80];
            sprintf(buf, D_004BE770, f.name);
            func_0036E220(&f, -1);
            return;
        }
        int size = FileMan_GetSize(&f);
        Appearance_PackText(D_0055D950, FileMan_ReadData(&f), size);
        func_0036DEC0(&f);
        func_0036E220(&f, -1);
    }
}
#pragma pop
