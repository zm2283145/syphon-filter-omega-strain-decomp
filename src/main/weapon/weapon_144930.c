/*
 * main/weapon: range (6 files, 00144930-00144B10)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00144930 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "trivial_dtor.h"

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(func_00144930)
#pragma pop /* merge_units */
/* merge_units: end func_00144930 */

/* merge_units: begin func_00144980 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x1C]; unsigned char flag; } F44980;
extern unsigned char g_LevelLightsDirty;
void Light_Disable(F44980* p)
{
    if (p->flag) {
        p->flag = 0;
        g_LevelLightsDirty = 1;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00144980(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00144980 */

/* merge_units: begin func_001449B0 */
#pragma push /* merge_units */
extern char D_004D9280[];
extern int func_003EC950(int);

int func_001449B0(int a0, int a1) {
    int s0, v0, v1;
    int cond;

    s0 = a0;
    cond = s0 == 0;
    if (cond) goto L001449E8;
    v1 = (int)D_004D9280;
    v0 = (short)a1;
    cond = v0 <= 0;
    *(int*)((char*)s0 + 4) = v1;
    if (cond) goto L001449E8;
    v0 = func_003EC950(a0);
L001449E8:;
    v0 = s0;
    goto ret;
ret:
    return v0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001449B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001449B0 */

/* merge_units: begin func_00144A00 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cWeaponVisChangeMsg_dtor, D_004E1140, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00144A00 */

/* merge_units: begin func_00144A60 */
#pragma push /* merge_units */
#pragma cplusplus on
class E7VC {
public:
    int pad0;
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void Disable();
};
struct E7Light { int pad0; void* vt; int id; };
extern "C" {
extern void* D_004D9200[];
extern void* D_004D9240[];
#if 0 /* merge_units */
extern void* D_004D9280[];
#endif /* merge_units */
#define D_004D9280 ((void **)&D_004D9280) /* merge_units */

extern int g_LightMgr;
extern void LightMgr_RemoveFromTable(void* pool, void* p);
E7Light* Light_Destruct(E7Light* p, short flag) {
    if (p) {
        p->vt = D_004D9200;
        if (p) {
            p->vt = D_004D9240;
            p->id = -1;
            ((E7VC*)p)->Disable();
            g_LevelLightsDirty = 1;
            if (p) {
                p->vt = D_004D9280;
            }
        }
        if (flag > 0) {
            LightMgr_RemoveFromTable(&g_LightMgr, p);
        }
    }
    return p;
}
}
#undef D_004D9280 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00144A60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00144A60 */

/* merge_units: begin func_00144B10 */
#pragma push /* merge_units */
#include "vc_copy.h"
#include "v4_asm_copy.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { char pad[0x30]; V4 v30; } C44_O;
static inline unsigned char eq4_(V4* a, V4* b) {
    int k, f, r;
    asm {
        .set noreorder
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vsub.xyzw vf3, vf1, vf2
        and r, zero, zero
        ori k, zero, 0xF
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        bne k, f, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}
#pragma push
#pragma bool off



void Light_SetPosition(C44_O* o, V4* v) {
    if ((eq4_(&o->v30, v) != 0) ^ 1) {
        { V4* d = &o->v30; VCopyF(d, v); }
        g_LevelLightsDirty = 1;
    }
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00144B10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00144B10 */
