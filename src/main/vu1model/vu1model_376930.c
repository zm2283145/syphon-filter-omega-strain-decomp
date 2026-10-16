/*
 * main/vu1model: range (3 files, 00376930-00376FF0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_00376930 */
#pragma push /* merge_units */
#pragma cplusplus on
struct E376930 { int x0; void* p; int x8; int xC; };
struct S376930 { char pad[0xC]; E376930* arr; int count; };
extern "C" {
extern void* D_0053924C;
void func_003D2630(void* mgr, void* p);
void func_003D1F00(void* p, int f);
}
static inline void Del376930(void* o)
{
    AllocGuard g;
    func_003D1F00(o, -1);
    Mem_Free(0, o, "vu1model.cc", 0x2AA);
}
static inline void Rel376930(void* p, int line)
{
    AllocGuard g;
    Mem_Free(0, p, "vu1model.cc", line);
}
extern "C" void func_00376930(S376930* s)
{
    if (s->arr) {
        int i;
        for (i = 0; i < s->count; i++) {
            if (s->arr[i].p) {
                func_003D2630(D_0053924C, s->arr[i].p);
                Del376930(s->arr[i].p);
                s->arr[i].p = 0;
            }
        }
        Rel376930(s->arr, 0x2AE);
        s->arr = 0;
        s->count = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00376930(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00376930 */

/* merge_units: begin func_00376AD0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
void *Mem_Alloc(int, int, char *, int);
void *UvScrollAnim_Construct(void *, void *, void *, void *, int);
void *Material_Animate(void *, void *, void *, void *, int);
void MaterialAnim_Register(int, void *);
extern char D_004BC170;


#if 0 /* merge_units */
extern int D_0053924C;
#endif /* merge_units */
#define D_0053924C (*(int*)&D_0053924C) /* merge_units */

}

typedef struct FxEnt {
    int f0;
    void *f4;
    char *f8;
    char *fC;
} FxEnt;

typedef struct FxItem {
    int f0;
    char *f4;
    char pad8[0x18];
} FxItem;

typedef struct FxGroup {
    int f0;
    int f4;
    FxItem *f8;
    int fC;
} FxGroup;

typedef struct FxMat {
    int f0;
    int f4;
    char f8[0x30];
    int f38[8];
    int f58;
} FxMat;

typedef struct FxData {
    char pad0[0x10];
    int f10;
    char pad14[0x50 - 0x14];
    FxMat *f50;
    FxGroup *f54;
    char pad58[4];
    int f5C;
} FxData;

typedef struct FxSub {
    char pad0[0x48];
    char f48[0x68];
    char fB0[0x28];
} FxSub;

typedef struct FxSubs {
    int a;
    int b;
    FxSub e[1];
} FxSubs;

typedef struct FxModel {
    int f0;
    FxData *f4;
    short *f8;
    FxEnt *fC;
    int f10;
    int f14;
} FxModel;

static inline void *FxAlloc(int size, int line)
{
    void *p;
    {
        AllocGuard g;
        p = Mem_Alloc(0, size, &D_004BC170, line);
    }
    return p;
}

extern "C" void Model_SetupMaterialFx(FxModel *m)
{
    int n;
    int i;
    int k;

    m->fC = (FxEnt *)FxAlloc(m->f10 * 16, 0x242);
    for (k = 0; k < m->f10; k++) {
        m->fC[k].f4 = 0;
    }
    n = 0;
    for (i = 0; i < m->f4->f10; i++) {
        FxGroup *g = &m->f4->f54[i];
        FxMat *mat = &m->f4->f50[g->fC];
        char *s = g->f8->f4;
        if (mat->f4 & 2) {
            void *p = FxAlloc(0x1C, 0x256);
            if (p) {
                p = UvScrollAnim_Construct(p, mat->f8, s + 0x10, s + 0x90, m->f8[mat->f38[0]]);
            }
            m->fC[n].f4 = p;
            MaterialAnim_Register(D_0053924C, m->fC[n].f4);
        } else if (mat->f4 & 4) {
            void *p = FxAlloc(0x34, 0x25C);
            if (p) {
                p = Material_Animate(p, mat->f8, s + 0x10, s + 0x90, m->f8[mat->f38[0]]);
            }
            m->fC[n].f4 = p;
            MaterialAnim_Register(D_0053924C, m->fC[n].f4);
        }
        if (mat->f58 == 1) {
            char *t = g->f8->f4;
            *(int *)(t + 0x10) = mat->f4;
            *(int *)(t + 0x90) = mat->f4;
            m->fC[n].f0 = m->f8[mat->f38[0]];
            m->fC[n].f8 = t + 0x50;
            m->fC[n].fC = t + 0xD0;
            n++;
        } else {
            int kk;
            for (kk = 0; kk < g->f4; kk++) {
                char *t = g->f8[kk].f4;
                char *se = t + 0x100;
                int idx = n++;
                int j;
                *(int *)(t + 0x10) = mat->f4;
                *(int *)(t + 0x90) = mat->f4;
                m->fC[idx].f0 = m->f8[mat->f38[0]];
                m->fC[idx].f8 = t + 0x50;
                m->fC[idx].fC = t + 0xD0;
                for (se += 8, j = 1; j < mat->f58; j++, se += sizeof(FxSub)) {
                    m->fC[n].f0 = m->f8[mat->f38[j]];
                    m->fC[n].f8 = ((FxSub *)se)->f48;
                    m->fC[n].fC = ((FxSub *)se)->fB0;
                    n++;
                }
            }
        }
    }
    if (m->f14 <= 0x300) {
        int off = 0x70000000 - m->f4->f5C;
        FxEnt *e = m->fC;
        for (k = m->f10; k > 0; k--) {
            e->f8 += off;
            e->fC += off;
            e++;
        }
    }
}
#undef D_0053924C /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00376AD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00376AD0 */

/* merge_units: begin func_00376FF0 */
#pragma push /* merge_units */
typedef struct { int pad0; int value; int pad8; int padC; } E376FF0;
typedef struct { char pad[0xC]; E376FF0* ents; int count; } S376FF0;
int func_00376FF0(S376FF0* o, int* out, int max)
{
    int n = 0;
    int i;
    for (i = 0; i < o->count; i++) {
        int v = o->ents[i].value;
        if (v) {
            if (n >= max) break;
            *out = v; n++; out++;
        }
    }
    return n;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00376FF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00376FF0 */
