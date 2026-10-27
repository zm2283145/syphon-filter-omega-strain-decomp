/*
 * Libs/SFOLib/Source/lights: 2 files, 00373590-00373670
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00373590 */
#pragma push /* merge_units */
#include "types.h"
/* cLightMan_AddLightScoreBox: bounding-sphere test of a light entry, appends (light, key) to the gather list */
typedef struct Pt1TbVec { float x, y, z, w; } __attribute__((aligned(16))) Pt1TbVec;
typedef struct Pt1TbEntry {
    unsigned char flags;
    char pad1[3];
    void* light;
    float range;
    float weight;
    Pt1TbVec pos;
} Pt1TbEntry;
typedef struct Pt1TbCand { void* light; float key; } Pt1TbCand;
typedef struct Pt1TbList { char pad[0x2000]; Pt1TbCand cand[1]; } Pt1TbList;
typedef struct Pt1TbGather {
    char pad0[0x50];
    int count;
    Pt1TbList* list;
} Pt1TbGather;

void cLightMan_AddLightScoreBox(Pt1TbGather* g, Pt1TbVec* pos, Pt1TbEntry* e, float radius)
{
    float key;
    unsigned char ok;
    if (e->flags == 2) {
        key = 0.0f;
        ok = 1;
    } else {
        int r;
        int st;
        int k;
        asm {
            lqc2 vf1, 0x0(pos)
            lqc2 vf2, 0x10(e)
            vsub.xyzw vf3, vf2, vf1
            mfc1 r, radius
            qmtc2 r, vf5
            lqc2 vf6, 0x0(e)
            vaddz.x vf7, vf5, vf6z
            vmul.xyz vf4, vf3, vf3
            vaddw.x vf9, vf0, vf0w
            vmul.x vf8, vf7, vf7
            vmulax.x ACC, vf9, vf4x
            vmadday.x ACC, vf9, vf4y
            vmaddz.x vf10, vf9, vf4z
            vsub.x vf11, vf10, vf8
            vnop
            vnop
            vnop
            vmulw.x vf8, vf10, vf6w
            cfc2 st, vi16
            qmfc2 k, vf8
        }
        {
            /* S flag (bit 1) of dist^2 - (radius + range)^2: inside the light's reach */
            unsigned s = (st >> 1) << 31;
            unsigned zero = 0;
            ok = !(s <= zero);
        }
        asm { mtc1 k, key } /* key bits from VU0 into an FPR */
    }
    if (ok) {
        g->list->cand[g->count].key = key;
        g->list->cand[g->count].light = e->light;
        g->count++;
    }
}
static inline void merge_flush_func_00373590(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00373590 */

/* merge_units: begin func_00373670 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
/* cLightMan_BuildVisibleLightSubset: rebuilds the per-frame light table: takes the
 * current view matrix and a camera vector scaled by the field of view,
 * pushes an identity matrix, runs cLightMan_TestVisibleLight over the three light
 * lists, flushes the table from the data cache and pops the matrix. Types
 * as in cLightMan_TestVisibleLight (cLightMan_TestVisibleLight.c); camera as in
 * cVU1Man_SetView (cVU1Man_SetView.c). */
static inline void GQR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
struct Mtx { __int128 r[4]; Mtx() {} Mtx(const Mtx& o) { const Mtx* s = &o; Mtx* d = this; GQR(d, (void*)s); } };
typedef struct Render { char pad0[0xA80]; Mtx mtx[0x14]; } Render;
struct V { float x, y, z, w; };
struct Cam { char pad0[0xF8]; float fovA; float fovB; float half; unsigned char useA; };
struct L40 { char d[0x40]; };
struct LE0 { char d[0xE0]; };
struct L50 { char d[0x50]; };
struct LEnt { char d[0x20]; };
struct LMgr { int pad0; L50* l50; L40* l40; LE0* lE0; int pad10; int n50; int n40; int nE0; char pad20[0x4C - 0x20]; int count; char pad50[0x10]; LEnt ents[1]; };
extern "C" {
extern char g_Video[];
extern int D_00538C60;
extern int D_00538C64;
extern char D_00538C68;
float Libc_Cosf(float a);
void SyncDCache(void* a, void* b);
void cLightMan_TestVisibleLight(LMgr* self, void* l, Mtx* m, V* cam, float f);
void cLightMan_BuildVisibleLightSubset(LMgr* self);
}
static inline Mtx* MtxAt(int i) { return &((Render*)g_Video)->mtx[i]; }
static inline Cam* CurCam() { return (Cam*)(g_Video + D_00538C60 * 0x110 + 0x1F0); }
static inline void UM(void* p) { int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }

extern "C" void cLightMan_BuildVisibleLightSubset(LMgr* self)
{
    float f;
    int i;
    self->count = 0;
    Mtx m(*MtxAt(D_00538C64));
    V c;
    {
        Cam* cam = CurCam();
        f = 0.5f * (cam->useA ? cam->fovA : cam->fovB);
    }
    c.x = 0.0f;
    c.y = f;
    c.z = 0.0f;
    c.w = 1.0f;
    f = f / Libc_Cosf(CurCam()->half);
    GQR(MtxAt(D_00538C64 + 1), MtxAt(D_00538C64));
    D_00538C64++;
    UM(MtxAt(D_00538C64));
    D_00538C68 = 1;
    for (i = 0; i < self->n40; i++)
        cLightMan_TestVisibleLight(self, &self->l40[i], &m, &c, f);
    for (i = 0; i < self->nE0; i++)
        cLightMan_TestVisibleLight(self, &self->lE0[i], &m, &c, f);
    for (i = 0; i < self->n50; i++)
        cLightMan_TestVisibleLight(self, &self->l50[i], &m, &c, f);
    SyncDCache(&self->ents[0], &self->ents[self->count]);
    D_00538C64--;
    D_00538C68 = 1;
}
static inline void merge_flush_func_00373670(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00373670 */
