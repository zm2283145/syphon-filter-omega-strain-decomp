/*
 * main/skybox: range (2 files, 003BCB90-003BCC70)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
char *strncpy(void *, const void *, int);

/* merge_units: begin func_003BCB90 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V4 {
    float x, y, z, w;
    V4 operator*(float s) const {
        V4 r; V4* q = &r; int t; const V4* v = this;
        asm {
            .set noreorder
            lqc2 vf1, 0x0(v)
            mfc1 t, s
            qmtc2.ni t, vf2
            vmulx.xyzw vf1, vf1, vf2x
            sqc2 vf1, 0x0(q)
            .set reorder
        }
        return *q;
    }
    V4& operator=(const V4& a) { __int128* d = (__int128*)this; const __int128* s = (const __int128*)&a; *d = *s; return *this; }
    V4& operator+=(const V4& a) {
        V4* d = this; const V4* p = &a;
        asm {
            lqc2 vf1, 0x0(d)
            lqc2 vf2, 0x0(p)
            vadd.xyzw vf1, vf1, vf2
            sqc2 vf1, 0x0(d)
        }
        return *this;
    }
} __attribute__((aligned(16)));
struct Sky_BCB90 {
    char p0[0x1B0];
    V4 vel;
    V4 acc;
    char p1d0[0x10];
    V4 dir;
    V4 base;
    float ang;
    float angVel;
    float angMax;
    unsigned int flags;
};
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_dead_assignments off
extern "C" void func_003BCB90(Sky_BCB90* o) {
    o->ang = o->ang + o->angVel;
    if (!(o->flags & 8)) {
        o->vel += o->acc;
    }
    if (o->flags & 4) {
        { float a = o->ang; float m = o->angMax; if (a > m) o->ang = -m; }
        { float a; float m = o->angMax; a = o->ang; if (a < -m) o->ang = m; }
    }
    {
        V4* d; /* dead store: retail keeps the unused &dir addiu */
        o->dir = o->base * o->ang;
        d = &o->dir;
    }
    o->dir.w = 1.0f;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BCB90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003BCB90 */

/* merge_units: begin func_003BCC70 */
#pragma push /* merge_units */
typedef struct { int a[0x28]; } H3BC;
typedef struct { char pad[0x14C]; unsigned char b14c; } T3BC;
typedef struct { int a; char name[0x94]; T3BC* f98; } S3BC;
typedef struct { char pad[0x16C]; int f16c; unsigned char b170; char p171[3]; char f174[0x3C]; float m[24]; } O3BC;
extern void func_0036D630(O3BC*);
extern void func_00377C30(char*);
extern void FileMan_FindMember(S3BC*);
extern void FileMan_LoadMemberSync(S3BC*, int*, int);
extern void func_0036D540(O3BC*, char*, int, int);
extern char* strchr(const char*, int);
extern void func_0036E540(H3BC*, char*, O3BC*, int);
extern void Model_Load(char*, H3BC*, int);
extern void FileMan_Release(H3BC*, int);
O3BC* func_003BCC70(O3BC* o, S3BC* src, int arg) {
    H3BC h;
    func_0036D630(o);
    o->f16c = 0;
    func_00377C30(o->f174);
    o->m[0] = 0.0f; o->m[1] = 0.0f; o->m[2] = 0.0f; o->m[3] = 0.0f;
    o->m[4] = 0.0f; o->m[5] = 0.0f; o->m[6] = 0.0f; o->m[7] = 0.0f;
    o->m[8] = 0.0f; o->m[9] = 0.0f; o->m[10] = 0.0f; o->m[11] = 0.0f;
    o->m[12] = 0.0f; o->m[13] = 0.0f; o->m[14] = 0.0f; o->m[15] = 1.0f;
    o->m[16] = 0.0f; o->m[17] = 0.0f; o->m[18] = 0.0f; o->m[19] = 0.0f;
    o->m[20] = 0.0f; o->m[21] = 0.0f; o->m[22] = 0.0f; o->m[23] = 0.0f;
    FileMan_FindMember(src);
    FileMan_LoadMemberSync(src, &o->f16c, 0);
    if (src->f98->b14c == 2) o->b170 = 1;
    else o->b170 = 0;
    func_0036D540(o, src->name, o->f16c, 0);
    {
        char* name = src->name;
        strncpy(strchr(name, '.'), ".VUM", 4);
        func_0036E540(&h, name, o, 0);
    }
    Model_Load(o->f174, &h, arg);
    FileMan_Release(&h, -1);
    return o;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BCC70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003BCC70 */
