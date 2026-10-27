/*
 * main/manUtils: range (2 files, 00404FD0-004053B0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "canonical_key_copy.h"
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"
int cMemMan_Deallocate();
int sprintf(void *, const void *, ...);

/* merge_units: begin func_00404FD0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_propagation off
#pragma opt_strength_reduction off
#pragma opt_unroll_loops off
#pragma opt_rotateloops off
#pragma opt_loop_invariants off
#pragma opt_common_subs off
typedef struct { int f0; int f4; int h; int fC; } MC_Lod;
typedef struct { short a; short b; } MC_Tex;
typedef struct { __int128 x[11]; } MC_File;
typedef struct {
    char pad0[0xC0];
    unsigned int meshCount;
    int meshC4;
    unsigned int meshLoaded;
    unsigned int texCount;
    int texD0;
    void* bufD4;
    void* bufD8;
    char padDC[0xE4 - 0xDC];
    int hasE8;
    void* bufE8;
    char padEC[0x1410 - 0xEC];
    MC_Tex tex[0x600];
    char names[0x300][16];
    MC_Lod lods[0x300][2];
    char pad1[0x13410 - 0xBC10];
    MC_File sub0;
} MC_State;
extern "C" {
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
void Alloc_Lock(int id);
void EnableIntc(int id);
extern char D_004BE7F0[];
extern char D_004BE830[];
extern int g_TextureMgr;
extern int D_00571300;
void Libc_Strcat(char* d, char* s);
void cFileMan_ctor_void(MC_File* f);
void cFileMan_dtor(void* f, int del);
void cFileMan_EncodeFilename_charP_cFileIOP_bool(MC_File* f, char* name, int a, int b);
void* GetFileStreamMan(void);
void cFileStreamMan_StreamRequestFlush_cFileManR_eStreamMode(void* m, MC_File* f, int a);
void cTexMan_RemoveTexture(int lib, int h, int keep);
void operator_delete(void* p);
MC_State* Monster_dtor(MC_State* s, short del);
}
/* Mesh/texture cache destructor: releases cached LOD meshes and textures, frees buffers. */
MC_State* Monster_dtor(MC_State* s, short del)
{
    MC_File fm;
    char name[32];
    unsigned int i;
    int j;
    void* p;
    if (s) {
        cFileMan_ctor_void(&fm);
        for (i = s->meshLoaded; i < s->meshCount; i++) {
            Libc_Strcpy(name, s->names[i]);
            Libc_Strcat(name, D_004BE830);
            for (j = 1; j > 0; j--) {
                MC_Lod* l = (MC_Lod*)((char*)s->lods + i * 32 + j * 16);
                int h = l->h;
                if (h != l[-1].h && h != 0) {
                    name[14] = j + '0';
                    cFileMan_EncodeFilename_charP_cFileIOP_bool(&fm, name, 0, 0);
                    cFileStreamMan_StreamRequestFlush_cFileManR_eStreamMode(GetFileStreamMan(), &fm, 1);
                }
            }
            if (s->lods[i][0].h) {
                name[14] = '0';
                cFileMan_EncodeFilename_charP_cFileIOP_bool(&fm, name, 0, 0);
                cFileStreamMan_StreamRequestFlush_cFileManR_eStreamMode(GetFileStreamMan(), &fm, 1);
            }
        }
        ckc_qzero(s->names, 0x300);
        ckc_qzero(s->lods, 0x600);
        s->meshCount = 0;
        s->meshC4 = 0;
        s->meshLoaded = 0;
        for (i = 0; i < s->texCount; i++) {
            {
                MC_Tex* t = (MC_Tex*)((char*)s->tex + i * 4);
                int b = t->b;
                if (b != t->a)
                    cTexMan_RemoveTexture(g_TextureMgr, b, 0);
            }
            {
                /* loading the library first orders lui before the index add */
                int lib = g_TextureMgr;
                cTexMan_RemoveTexture(lib, s->tex[i].a, 0);
            }
        }
        s->texCount = 0;
        s->texD0 = 0;
        p = s->bufD4;
        if (p) {
            if (g_ProfileLockEnabled) Alloc_Lock(9);
            g_ProfileLockDepth++;
            cMemMan_Deallocate(0, p, D_004BE7F0, 0x52C);
            if (g_ProfileLockEnabled) EnableIntc(9);
            g_ProfileLockDepth--;
            p = s->bufD8;
            if (g_ProfileLockEnabled) Alloc_Lock(9);
            g_ProfileLockDepth++;
            cMemMan_Deallocate(0, p, D_004BE7F0, 0x52D);
            if (g_ProfileLockEnabled) EnableIntc(9);
            g_ProfileLockDepth--;
            s->bufD4 = 0;
            s->bufD8 = 0;
        }
        if (s->hasE8) {
            p = s->bufE8;
            if (g_ProfileLockEnabled) Alloc_Lock(9);
            g_ProfileLockDepth++;
            cMemMan_Deallocate(0, p, D_004BE7F0, 0x532);
            if (g_ProfileLockEnabled) EnableIntc(9);
            g_ProfileLockDepth--;
        }
        s->bufE8 = 0;
        s->hasE8 = 0;
        D_00571300 = 1;
        cFileMan_dtor(&fm, -1);
        cFileMan_dtor((char*)s + 0x134AC, -1);
        cFileMan_dtor((char*)s + 0x13410, -1);
        if (del > 0)
            operator_delete(s);
    }
    return s;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00404FD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00404FD0 */

/* merge_units: begin func_004053B0 */
#pragma push /* merge_units */
/* 0x004053B0 Monster_MonsterInit (mw38). Quad copies use lq/sq GCC asm; operator= decl order
   reproduces the dead duplicate addiu pair. Empty asm barrier (no code) keeps axis on the stack. */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
struct V { float x, y, z, w; };
struct M;
extern "C" void cMatrix_ctor_void(M*);
extern "C" void cMatrix_SetWithAxisAngle(M*, float, float, float, float);
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
#if 0 /* merge_units */
void cFileMan_ctor_void(File* f);
#endif /* merge_units */
#define cFileMan_ctor_void(a0) (cFileMan_ctor_void((MC_File *)(a0))) /* merge_units */

#if 0 /* merge_units */
void cFileMan_EncodeFilename_charP_cFileIOP_bool(File* f, const char* path, int a, int b);
#endif /* merge_units */
#define cFileMan_EncodeFilename_charP_cFileIOP_bool(a0, a1, a2, a3) (cFileMan_EncodeFilename_charP_cFileIOP_bool((MC_File *)(a0), (char *)(a1), (a2), (a3))) /* merge_units */

int cFileMan_Open(File* f);
void cFileMan_Close(File* f);
#if 0 /* merge_units */
void cFileMan_dtor(File* f, int flags);
#endif /* merge_units */
#define cFileMan_dtor(a0, a1) (cFileMan_dtor((void *)(a0), (a1))) /* merge_units */

}
struct Man {
    char pad0[0x160];
    M m160;
    char pad1A0[0x40];
    float m1E0[3][4];
};
extern "C" {
void Monster_ReadSortTable(Man*, const char*);
void Monster_LoadLights(Man*, const char*, void*, M*);
void cMatrix_Rotate(M*, M*);
M* cMatrix_ctor_cMatrixR(M* d, const M* s);
M* cMatrix_Transpose(M* m);
int cFileMan_GetSize(File*);
char* cFileMan_Read_void(File*);
void SKL_ConvertSKL(void*, char*, int);
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
static inline void RotMul(M* a, const V& ax, float ang) { M rot; cMatrix_ctor_void(&rot); cMatrix_SetWithAxisAngle(&rot, ax.x, ax.y, ax.z, ang); cMatrix_Rotate(a, &rot); }
static inline M* TransCopy(M* d, const M* s) { M tmp; return cMatrix_ctor_cMatrixR(d, cMatrix_Transpose(cMatrix_ctor_cMatrixR(&tmp, s))); }
#pragma push
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_unroll_loops off
extern "C" void Monster_MonsterInit(Man* self)
{
    M a;
    V axis;
    M b;
    int i, j;
    Monster_ReadSortTable(self, D_004BE860);
    Monster_LoadLights(self, D_004BE880, (char*)self + 0x120, &a);
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
    Monster_LoadLights(self, D_004BE8A0, (char*)self + 0x1A0, &a);
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
        cFileMan_ctor_void(&f);
        cFileMan_EncodeFilename_charP_cFileIOP_bool(&f, D_004BE8C0, 0, 0);
        if ((unsigned char)cFileMan_Open(&f)) {
            char buf[0x80];
            sprintf(buf, D_004BE770, f.name);
            cFileMan_dtor(&f, -1);
            goto next1;
        }
        int size = cFileMan_GetSize(&f);
        SKL_ConvertSKL(D_0055D510, cFileMan_Read_void(&f), size);
        cFileMan_Close(&f);
        cFileMan_dtor(&f, -1);
    }
next1:;
    {
        File f;
        cFileMan_ctor_void(&f);
        cFileMan_EncodeFilename_charP_cFileIOP_bool(&f, D_004BE8E0, 0, 0);
        if ((unsigned char)cFileMan_Open(&f)) {
            char buf[0x80];
            sprintf(buf, D_004BE770, f.name);
            cFileMan_dtor(&f, -1);
            return;
        }
        int size = cFileMan_GetSize(&f);
        SKL_ConvertSKL(D_0055D950, cFileMan_Read_void(&f), size);
        cFileMan_Close(&f);
        cFileMan_dtor(&f, -1);
    }
}
#pragma pop
#undef cFileMan_ctor_void /* merge_units */
#undef cFileMan_EncodeFilename_charP_cFileIOP_bool /* merge_units */
#undef cFileMan_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004053B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004053B0 */
