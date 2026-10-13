#pragma cplusplus on
#pragma opt_propagation off
#pragma opt_strength_reduction off
#pragma opt_unroll_loops off
#pragma opt_rotateloops off
#pragma opt_loop_invariants off
#pragma opt_common_subs off
#include "canonical_key_copy.h"
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
extern unsigned char D_00533880;
extern int D_00533888;
void Alloc_Lock(int id);
void Alloc_Unlock(int id);
extern char D_004BE7F0[];
extern char D_004BE830[];
extern int D_00539248;
extern int D_00571300;
void Mem_Free(int pool, void* p, char* file, int line);
void String_Copy(char* d, char* s);
void func_00128F58(char* d, char* s);
void func_0036E5D0(MC_File* f);
void func_0036E220(void* f, int del);
void func_0036E140(MC_File* f, char* name, int a, int b);
void* func_003EBA50(void);
void func_003EAA60(void* m, MC_File* f, int a);
void func_003813A0(int lib, int h, int keep);
void operator_delete(void* p);
MC_State* func_00404FD0(MC_State* s, short del);
}
/* Mesh/texture cache destructor: releases cached LOD meshes and textures, frees buffers. */
MC_State* func_00404FD0(MC_State* s, short del)
{
    MC_File fm;
    char name[32];
    unsigned int i;
    int j;
    void* p;
    if (s) {
        func_0036E5D0(&fm);
        for (i = s->meshLoaded; i < s->meshCount; i++) {
            String_Copy(name, s->names[i]);
            func_00128F58(name, D_004BE830);
            for (j = 1; j > 0; j--) {
                MC_Lod* l = (MC_Lod*)((char*)s->lods + i * 32 + j * 16);
                int h = l->h;
                if (h != l[-1].h && h != 0) {
                    name[14] = j + '0';
                    func_0036E140(&fm, name, 0, 0);
                    func_003EAA60(func_003EBA50(), &fm, 1);
                }
            }
            if (s->lods[i][0].h) {
                name[14] = '0';
                func_0036E140(&fm, name, 0, 0);
                func_003EAA60(func_003EBA50(), &fm, 1);
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
                    func_003813A0(D_00539248, b, 0);
            }
            {
                /* loading the library first orders lui before the index add */
                int lib = D_00539248;
                func_003813A0(lib, s->tex[i].a, 0);
            }
        }
        s->texCount = 0;
        s->texD0 = 0;
        p = s->bufD4;
        if (p) {
            if (D_00533880) Alloc_Lock(9);
            D_00533888++;
            Mem_Free(0, p, D_004BE7F0, 0x52C);
            if (D_00533880) Alloc_Unlock(9);
            D_00533888--;
            p = s->bufD8;
            if (D_00533880) Alloc_Lock(9);
            D_00533888++;
            Mem_Free(0, p, D_004BE7F0, 0x52D);
            if (D_00533880) Alloc_Unlock(9);
            D_00533888--;
            s->bufD4 = 0;
            s->bufD8 = 0;
        }
        if (s->hasE8) {
            p = s->bufE8;
            if (D_00533880) Alloc_Lock(9);
            D_00533888++;
            Mem_Free(0, p, D_004BE7F0, 0x532);
            if (D_00533880) Alloc_Unlock(9);
            D_00533888--;
        }
        s->bufE8 = 0;
        s->hasE8 = 0;
        D_00571300 = 1;
        func_0036E220(&fm, -1);
        func_0036E220((char*)s + 0x134AC, -1);
        func_0036E220((char*)s + 0x13410, -1);
        if (del > 0)
            operator_delete(s);
    }
    return s;
}

