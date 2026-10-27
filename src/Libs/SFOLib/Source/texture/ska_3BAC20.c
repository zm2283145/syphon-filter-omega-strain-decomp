/*
 * main/ska: 6 files, 003BAC20-003BAFC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003BAC20 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
/* lq/sq quad copies written as GCC-style volatile asm; the unused xx reproduces retail's dead addiu.
   The copy ctor splits lq and sq into two asm statements so the destination address is formed after the lq (as retail). */
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float e) { x = a; y = b; z = c; w = e; }
    V(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(q) : "r"(&o) : "memory"); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(q), "r"(this) : "memory"); }
    V& operator=(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M { __int128 q[4];
    M& operator=(const M& o) { void* xx = this; const void* s = &o; __int128 qa; __int128 qb; void* d = this; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); return *this; }
};
struct MN { __int128 q[4];
    MN& operator=(const M& o) { const void* s = &o; void* d = this; __int128 qa; __int128 qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); return *this; }
};
struct SkelNode {
    char pad00[0xC0];
    int fC0;
    MN mD0;
    M m110;
    unsigned char b150, b151; float f154; V v160; float f170;
    V v180, v190, v1A0, v1B0, v1C0;
};
extern "C" {
extern M g_IdentityMatrix;
extern signed char D_004E1D88;
extern V D_004E1D90;
void cXformNode_ctor_void(SkelNode* x);
}
static inline const V& Zero()
{
    if (!D_004E1D88) {
        D_004E1D88 = 1;
        D_004E1D90.x = 0.0f;
        D_004E1D90.y = 0.0f;
        D_004E1D90.z = 0.0f;
        D_004E1D90.w = 0.0f;
    }
    return D_004E1D90;
}
static inline V QZero()
{
    V t;
    __asm__ volatile("sq $0, 0x0(%0)" : : "r"(&t) : "memory");
    return t;
}
extern "C" SkelNode* cBone_ctor_void(SkelNode* d)
{
    cXformNode_ctor_void(d);
    d->fC0 = 0;
    d->mD0 = g_IdentityMatrix;
    d->m110 = g_IdentityMatrix;
    d->b150 = 0;
    d->b151 = 1;
    d->f154 = 0.0f;
    d->v160 = Zero();
    d->f170 = 0.0f;
    d->v180 = Zero();
    d->v190 = V(0.0f, 0.0f, 0.0f, 0.0f);
    d->v1A0 = QZero();
    d->v1B0 = Zero();
    d->v1C0 = QZero();
    return d;
}
#pragma pop /* merge_units */
/* merge_units: end func_003BAC20 */

/* merge_units: begin func_003BAE50 */
#pragma push /* merge_units */
typedef struct { char pad[0x60]; unsigned char a; unsigned char b; } BAE50Item;
typedef struct { int pad[2]; BAE50Item** items; } BAE50Tbl;
typedef struct { int i0; int i1; } BAE50Pair;
extern BAE50Tbl* g_TextureMgr;
int cUserFrameEnv_IsVram(BAE50Pair* p) {
    BAE50Item** arr = g_TextureMgr->items;
    int r = (arr[p->i0]->a & arr[p->i0]->b) != 0;
    if (p->i1 != -1) {
        unsigned char res = 0;
        if (r) {
            if (arr[p->i1]->a & arr[p->i1]->b) res = 1;
        }
        r = res;
    }
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end func_003BAE50 */

/* merge_units: begin func_003BAED0 */
#pragma push /* merge_units */
/* Texture base page (in 32-block units) of the referenced entry, 0 if none. */
typedef struct { unsigned char pad[0x50]; unsigned long long tex0; } Tex_3BAED0;
typedef struct { int pad0[2]; Tex_3BAED0** entries; } Table_3BAED0;
typedef struct { int pad0; int index; } Ref_3BAED0;
#if 0 /* merge_units */
extern Table_3BAED0* g_TextureMgr;
#endif /* merge_units */
#define g_TextureMgr (*(Table_3BAED0 **)&g_TextureMgr) /* merge_units */


unsigned int cUserFrameEnv_GetVramZAddr(Ref_3BAED0* r)
{
    if (r->index != -1)
        return (unsigned int)(int)(g_TextureMgr->entries[r->index]->tex0 & 0x3FFF) >> 5;
    return 0;
}
#undef g_TextureMgr /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BAED0 */

/* merge_units: begin func_003BAF20 */
#pragma push /* merge_units */
typedef struct { char pad[0x50]; unsigned long bits; } Entry50;
typedef struct { char pad[8]; Entry50** entries; } EntryTable;

#if 0 /* merge_units */
extern EntryTable* g_TextureMgr;
#endif /* merge_units */
#define g_TextureMgr (*(EntryTable **)&g_TextureMgr) /* merge_units */


/* Returns bits 5..13 of the 64-bit field at +0x50 of the indexed table entry. */
unsigned int cUserFrameEnv_GetVramAddr(int* index)
{
    return (unsigned int)(int)(g_TextureMgr->entries[*index]->bits & 0x3FFF) >> 5;
}
#undef g_TextureMgr /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BAF20 */

/* merge_units: begin func_003BAF60 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Look up a texture by the index stored in a handle and return a size field
 * of its info header. Original translation unit not identified yet.
 */

#include "loose03_types.h"

#if 0 /* merge_units */
extern TexRegistry* g_TextureMgr;
#endif /* merge_units */
#define g_TextureMgr (*(TexRegistry **)&g_TextureMgr) /* merge_units */


int cUserFrameEnv_GetHeight(int* handle) {
    return g_TextureMgr->entries[*handle]->info->unk06;
}

int cUserFrameEnv_GetWidth(int* handle) {
    return g_TextureMgr->entries[*handle]->info->unk04;
}
#undef g_TextureMgr /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BAF60 */

/* merge_units: begin func_003BAFC0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void* g_TextureMgr;
#endif /* merge_units */
#define g_TextureMgr (*(void **)&g_TextureMgr) /* merge_units */

extern void cTexMan_UnlockVram(void*, int);
typedef struct { int a; int b; } Pair_003BAFC0;
/* Applies the global handler to the first id and, if valid, the second id. */
void cUserFrameEnv_ReleaseVram(Pair_003BAFC0* p) { cTexMan_UnlockVram(g_TextureMgr, p->a); if (p->b != -1) cTexMan_UnlockVram(g_TextureMgr, p->b); }
#undef g_TextureMgr /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BAFC0 */
