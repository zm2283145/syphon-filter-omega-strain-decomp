/*
 * main/collision: range (3 files, 003C17A0-003C18A0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vc_copy.h"
#include "v4_asm_copy.h"

/* merge_units: begin func_003C17A0 */
#pragma push /* merge_units */
typedef struct { float x; int pad[3]; __int128 q; } S003C1880;
S003C1880* cSphere_opAssign(S003C1880* arg0, S003C1880* arg1); /* gsynth: defined below */typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 min; V4 max; } Box_18A0;
typedef struct { float r; int pad[3]; V4 c; } Sphere_18A0;
void cBox_BoundingSphere(Sphere_18A0* out, Box_18A0* b); /* gsynth: defined below */typedef struct { int pad[7]; int f1C; } ColData_f3;
typedef struct { ColData_f3* data; unsigned char loaded; char pad[11]; int f10; } ColHolder_f3;
typedef struct { int w[11]; } ColTmp_f3;
extern int cFileMan_Open(void* f);
extern void cFileMan_Read_charPP_int(void* f, int* out, int z);
extern void cFileMan_Close(void* f);
extern void cCollisionModel_Data_FixUpPointers(ColData_f3* d);
extern void* cCollisionModel_Data_BoundingBox(ColData_f3* d);
#if 0 /* merge_units */
extern void cBox_BoundingSphere(ColTmp_f3* t, void* p);
#endif /* merge_units */
#define cBox_BoundingSphere(a0, a1) (cBox_BoundingSphere((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void cSphere_opAssign(int* dst, ColTmp_f3* t);
#endif /* merge_units */
#define cSphere_opAssign(a0, a1) ((void)cSphere_opAssign((void *)(a0), (void *)(a1))) /* merge_units */

int cCollisionModelMaster_Load(ColHolder_f3* c, void* file)
{
    int buf[1];
    ColTmp_f3 tmp;
    if (c->data == 0) {
        buf[0] = 0;
        if ((unsigned char)cFileMan_Open(file)) {
            c->loaded = 1;
            return 0;
        }
        cFileMan_Read_charPP_int(file, buf, 0);
        cFileMan_Close(file);
        c->data = (ColData_f3*)buf[0];
        cCollisionModel_Data_FixUpPointers(c->data);
        cBox_BoundingSphere(&tmp, cCollisionModel_Data_BoundingBox(c->data));
        cSphere_opAssign(&c->f10, &tmp);
        {
            unsigned char b = 1;
            if (c->data != 0 && c->data->f1C != 0) b = 0;
            c->loaded = b;
        }
        return 1;
    }
    return 0;
}
#undef cBox_BoundingSphere /* merge_units */
#undef cSphere_opAssign /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C17A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C17A0 */

/* merge_units: begin func_003C1880 */
#pragma push /* merge_units */
#pragma push
#pragma opt_propagation off
S003C1880 *cSphere_opAssign(S003C1880 *arg0, S003C1880 *arg1) {
    S003C1880 *s = arg1;
    arg0->x = s->x;
    {
        __int128 *src = &s->q;
        __int128 *dst = &arg0->q;
        { typedef char uf_chk_[sizeof(*dst) == 16 ? 1 : -1]; VCopyF(&(*dst), &(*src)); }
    }
    return arg0;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C1880(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C1880 */

/* merge_units: begin func_003C18A0 */
#pragma push /* merge_units */
#pragma push
#pragma peephole off
#pragma opt_common_subs off
void cBox_BoundingSphere(Sphere_18A0* out, Box_18A0* b)
{
    V4 lenV;
    V4 cc;
    V4 sub;
    V4 ret;
    V4 mulV;
    V4 add;
    V4 mulT;
    float h;
    float len;
    { V4* d = &add; V4* mx = &b->max; asm { lqc2 vf1, 0x0(b); lqc2 vf2, 0x0(mx); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(d) } }
    { void* xx = &mulV; }
    { __int128 tt; V4* s; V4* p; __int128 t1; V4* q; V4* d; asm { paddub tt, zero, zero } s = &add; p = &mulV; q = &mulT; d = &mulV; t1 = *(__int128*)s; *(__int128*)d = t1; h = 0.5f; asm { .set noreorder; lqc2 vf1, 0x0(p); mfc1 tt, h; qmtc2.ni tt, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(q); .set reorder } ret = *q; }
    { void* xx = &cc; } { V4* d3 = &cc; V4* s3 = &ret; *d3 = *s3; }
    { V4* d = &sub; V4* mx = &b->max; asm { lqc2 vf1, 0x0(mx); lqc2 vf2, 0x0(b); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(d) } }
    { V4* s4 = &sub; V4* d4 = &lenV; void* xx = &lenV; __int128 t4; len = 0.0f; t4 = *(__int128*)s4; *(__int128*)d4 = t4; { V4* v = &lenV; __asm__ volatile("lqc2 vf1, 0x0(%1); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vsqrt Q, vf3w; vwaitq; vaddq.x vf4, vf0, Q; qmfc2.ni %0, vf4" : "=r"(len) : "r"(v) : "memory"); } }
    { void* xx = &out->c; } out->r = 0.5f * len; out->c = cc;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C18A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C18A0 */
