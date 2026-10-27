/*
 * Libs/SFOLib/Source/xlib: 5 files, 00379E20-0037A1E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00379E20 */
#pragma push /* merge_units */
#pragma push
#pragma optimization_level 1
#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 r[4]; } M4_9E20;
typedef struct { char p[0x1B8]; float nearz; } O_9E20;
/* VU0 clip test against the VU0-memory near plane: hand-scheduled block emitted as written */
int XLib_GetOutCode(O_9E20* o, M4_9E20* m, V4* v) {
    int r; float* vm; float n; float z;
    asm {
        .set noreorder
        lqc2 vf5, 0x0(v)
        lqc2 vf1, 0x0(m)
        lqc2 vf2, 0x10(m)
        lqc2 vf3, 0x20(m)
        lqc2 vf4, 0x30(m)
        vmulax.xyzw ACC, vf1, vf5x
        vmadday.xyzw ACC, vf2, vf5y
        vmaddaz.xyzw ACC, vf3, vf5z
        vmaddw.xyzw vf6, vf4, vf5w
        vnop
        vnop
        vnop
        .word 0x4BC631FF
        vsqi.xyzw vf6, (vi0++)
        vnop
        vnop
        vnop
        cfc2.ni r, vi18
    }
    r &= 0x3F;
    vm = (float*)0x11004000;
    z = o->nearz; n = vm[2]; if (!(n < z)) r |= 0x40;
    return r;
}
#pragma pop
static inline void merge_flush_func_00379E20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00379E20 */

/* merge_units: begin func_00379EA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)

/* Returns true if point p, transformed by the renderer's camera matrix
 * (0xF00), lies inside the clip volume (|x|,|y|,|z| <= |w|). */

/* 16-byte quad copy (lq/sq have no C equivalent). */
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }

struct V {
    float x, y, z, w;
    V() {}
    /* The unused xx keeps retail's dead address addiu. */
    V(const V& o) { void* xx = this; Q16(this, &o); }
} __attribute__((aligned(16)));
struct M { V r[4]; };
struct R { char pad[0xF00]; M m; };

extern "C" {
void XLib_UpdateCompMat(R*);
bool XLib_Inside(R* r, V* p);
}

static inline V Xform(M* m, const V& v)
{
    V t = v;
    V* pp = &t;
    asm {
        lqc2 vf8, 0x0(pp)
        lqc2 vf4, 0x0(m)
        lqc2 vf5, 0x10(m)
        lqc2 vf6, 0x20(m)
        lqc2 vf7, 0x30(m)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        sqc2 vf12, 0x0(pp)
    }
    return *pp;
}

bool XLib_Inside(R* r, V* p)
{
    XLib_UpdateCompMat(r);
    V c = Xform(&r->m, *p);
    float aw = 0.0f;
    float cw = c.w;
    asm { abs.s aw, cw } /* fabs: same asm idiom as src/main/cSkaParams_HasJustArrivedAtTarget.c */
    return c.x <= aw && c.x >= -aw && c.y <= aw && c.y >= -aw && c.z <= aw && c.z >= -aw;
}
static inline void merge_flush_func_00379EA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00379EA0 */

/* merge_units: begin func_00379FE0 */
#pragma push /* merge_units */
typedef struct { char pad[0xD0]; unsigned char ready; } R_79FE0;
void FlushCache(int a);
static inline void Kick_79FE0(void* tag, int qwc)
{
    while (*(volatile int*)0x1000A000 & 0x100) {
    }
    *(volatile int*)0x1000A020 = qwc;
    *(volatile int*)0x1000E010 = 4;
    if (((unsigned int)tag & 0x70000000) == 0x70000000) {
        *(volatile unsigned int*)0x1000A010 = (unsigned int)tag | 0x80000000;
    } else {
        *(volatile unsigned int*)0x1000A010 = (unsigned int)tag;
        FlushCache(0);
    }
    asm volatile ("sync");
    *(volatile int*)0x1000A000 = 0x181;
    while (*(volatile int*)0x1000A000 & 0x100) {
    }
}
void XLib_ClearVram(R_79FE0* self, unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    unsigned long* p = (unsigned long*)0x70000000;
    *p++ = 0x8009 | ((unsigned long)0x10000000 << 32);
    *p++ = 0xE;
    *p++ = 1;
    *p++ = 0x1A;
    *p++ = 0x100000;
    *p++ = 0x4C;
    *p++ = 0;
    *p++ = 0x18;
    *p++ = 0x04000000 | ((unsigned long)0x04000000 << 32);
    *p++ = 0x40;
    *p++ = 0;
    *p++ = 0x47;
    *p++ = 6;
    *p++ = 0;
    *p++ = (unsigned long)r | ((unsigned long)g << 8) | ((unsigned long)b << 16) | ((unsigned long)a << 24) | ((unsigned long)0x3F800000 << 32);
    *p++ = 1;
    *p++ = 0;
    *p++ = 4;
    *p++ = 0x40004000;
    *p++ = 4;
    Kick_79FE0((void*)0x70000000, 0xA);
    self->ready = 1;
}
static inline void merge_flush_func_00379FE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00379FE0 */

/* merge_units: begin func_0037A1C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

extern void XLib_ClearActiveBuffer(Obj37A1C0* self, int a1, int a2, int a3, int a4, int a5);

/* Forwards to XLib_ClearActiveBuffer with the object's unk1C/unk20 pair. */
void XLib_ClearScreen_tIRGBAR_bool_uint(Obj37A1C0* self, int a1, int a2, int a3) {
    XLib_ClearActiveBuffer(self, self->unk1C, self->unk20, a1, a2, a3);
}
static inline void merge_flush_func_0037A1C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0037A1C0 */

/* merge_units: begin func_0037A1E0 */
#pragma push /* merge_units */
#pragma opt_propagation off
typedef unsigned long long u64_t;
typedef struct { u64_t lo, hi; } GsQ;
typedef struct {
    char pad0[0x1C];
    int w;
    int h;
    char pad24[0x2C - 0x24];
    int psm;
    char pad30[0xD0 - 0x30];
    unsigned char ready;
    char padD1[0x12C - 0xD1];
    unsigned int tbp[5];
    int cur;
} R1E0;
extern char D_00537F80[];
extern u64_t* cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_int_etc(void* q, int a, int b, int c, int d, int e);

void XLib_ClearZBuffer(R1E0* o)
{
    unsigned int tbp = o->tbp[o->cur];
    GsQ* q = (GsQ*)cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_int_etc(D_00537F80, 1, 1, 8, 0, 1);
    q->lo = 0x11000000ULL | ((u64_t)0x50000008 << 32);
    q->hi = 0x8007ULL | ((u64_t)0x10000000 << 32);
    q++;
    q->lo = 0xE;
    q->hi = 1; q++; q->lo = 0x1A;
    q->hi = (u64_t)tbp | ((u64_t)(o->w >> 6) << 16) | ((u64_t)o->psm << 24); q++; q->lo = 0x4C;
    q->hi = 0x32001; q++; q->lo = 0x47;
    q->hi = 6; q++; q->lo = 0;
    q->hi = 0; q++; q->lo = 1;
    q->hi = ((0x800 - (o->w >> 1)) << 4) | ((u64_t)((0x800 - (o->h >> 1)) << 4) << 16); q++; q->lo = 5;
    q->hi = (((o->w >> 1) + 0x800) << 4) | ((u64_t)(((o->h >> 1) + 0x800) << 4) << 16); q++; q->lo = 5;
    o->ready = 1;
}
static inline void merge_flush_func_0037A1E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0037A1E0 */
