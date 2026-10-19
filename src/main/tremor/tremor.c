/*
 * main/tremor: 3 files, 002726F0-002727B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002726F0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { char pad[0x10]; float f10; } Src_D640;
typedef struct {
    char pad[0x1C]; float f1C; float f20; float f24; float f28; float f2C; Src_D640* p30; float f34;
} Ch_D640;

void CameraShake_Apply(Ch_D640* c, float x, float d) {
    float s;
    *(float*)((char*)c + 0x10) = x;
    if (d >= 0.0f) {
        s = d * c->f2C;
        c->f1C = c->f1C * s;
        c->f24 = c->f24 * s;
        c->f28 = d;
        c->f2C = d != 0.0f ? 1.0f / d : 0.0f;
        c->f34 = c->p30->f10;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_002726F0 */

/* merge_units: begin func_00272770 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Word* func_00272770(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_00272780(Iter* out, Tree* t) {
    out->p = &t->header;
}

void func_00272790(int a0, int a1) {
    *(int*)((char*)a0) = *(int*)(char*)a1;
}

Word* func_002727A0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
#pragma pop /* merge_units */
/* merge_units: end func_00272770 */

/* merge_units: begin func_002727B0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
static inline void QC(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
extern "C" {
int Alloc_Lock(int);
int Alloc_Unlock(int);
void* Mem_Alloc(int, int, char*, int);
int TremorList_Push(void*, void*);
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern char D_004A8EF0[];
}
struct Obj { char pad[0xC]; int id; };
static inline const int& GetId(Obj* o) { int tmp; if (o) return o->id; tmp = -1; return tmp; }
static inline int GetId2(Obj* o) { const int* p; int tmp; if (o) p = &o->id; else { tmp = -1; p = &tmp; } return *p; }
struct Flash {
    float a; float zero; float c; float d; float b; char pad14[0xC];
    V4 col; int f30; int f34;
};
extern "C" void VisionFx_RequestFlash(void* list, V4* col, float a, float b, float c, float d)
{
    Flash* f;
    Flash* q;
    Obj* const o = 0;
    if (g_ProfileLockEnabled != 0) {
        Alloc_Lock(9);
    }
    g_ProfileLockDepth += 1;
    f = (Flash*)Mem_Alloc(0, 0x40, D_004A8EF0, 0x59);
    if (g_ProfileLockEnabled != 0) {
        Alloc_Unlock(9);
    }
    g_ProfileLockDepth -= 1;
    if (f != 0) {
        f->f34 = -2;
        f->f30 = 0;
        f->a = a;
        f->b = b;
        QC(&f->col, col);
        f->c = c;
        f->d = d;
        f->zero = 0.0f;
        f->f30 = 0;
{ int tmp[2]; const int* p; if (o) p = &o->id; else { tmp[1] = -1; p = &tmp[1]; } f->f34 = *p; }
    }
    q = f;
    TremorList_Push(list, &q);
}
#pragma pop /* merge_units */
/* merge_units: end func_002727B0 */
