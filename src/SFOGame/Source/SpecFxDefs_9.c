/*
 * SFOGame/Source/SpecFxDefs: 5 files, 00231E60-00231F00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00231E60 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cNetShatterMsg_dtor, D_004DE5F0, cMessage_dtor)
static inline void merge_flush_func_00231E60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00231E60 */

/* merge_units: begin func_00231EC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Indexed access into a 16-byte element table.
 */

#include "SpecFxDefs_types.h"

extern char* cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_4(SpecTableOwner* owner, char** it);

/* Returns the address of element index of owner's table. */
char* cCollisionModel_Data_GetVertex(SpecTableOwner* owner, int index) {
    char* it[1];

    it[0] = owner->table;
    return cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_4(owner, it) + (index << 4);
}
static inline void merge_flush_func_00231EC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00231EC0 */

/* merge_units: begin func_00231F00 */
#pragma push /* merge_units */
#include "v4_asm_copy.h"

typedef struct { float pos[4]; float dir[4]; float a; float b; float c; } LDesc_f4;
typedef struct { char pad[0x14]; void* vt; } LFx_f4;
LFx_f4* cLightBundle_ctor(LFx_f4* self, LDesc_f4* d); /* gsynth: defined below */typedef struct { __int128 q; } Q231F00;
typedef struct { char p[0x30]; Q231F00 pos; } O231F00;
typedef struct { float sx, sy, sz, pad; Q231F00 pos; int f20; float a; float b; int pad2; } L231F00;
extern void* cSfxBundle_opNew(int size);
#if 0 /* merge_units */
extern void cLightBundle_ctor(void* p, L231F00* l);
#endif /* merge_units */
#define cLightBundle_ctor(a0, a1) ((void)cLightBundle_ctor((LFx_f4 *)(a0), (LDesc_f4 *)(a1))) /* merge_units */


void SfxLightEffect(O231F00* o, float a, float b)
{
    L231F00 l;
    void* p;
    l.f20 = 0;
l.sx = 1.0f;
l.a = a;
l.sy = 1.0f;
l.sz = 1.0f;
{ Q231F00* s = &o->pos; Q231F00* d = &l.pos; V4Copy(d, s); }
l.b = b;
    p = cSfxBundle_opNew(0x18);
    if (p) cLightBundle_ctor(p, &l);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00231F00(void) {}
#undef cLightBundle_ctor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00231F00 */

/* merge_units: begin func_00231F60 */
#pragma push /* merge_units */
void cSfxScheduler_AddItem(void* list, void* owner, float x, float y); /* gsynth: defined below */typedef struct { float x, y, z, w; } V4_f4;


typedef struct { int pad0; void* vt; } LObj_f4;
extern void cLightBundle_dtor();
extern void cSfxScheduler_Render();
extern void cSfxScheduler_NextFrame();
void * const D_004DBB20[8] = { (void*)0x0, (void*)0x0, (void*)cLightBundle_dtor, (void*)cSfxScheduler_NextFrame, (void*)cSfxScheduler_Render, (void*)0x0, (void*)0x0, (void*)0x0 };
extern char g_LightMgr[];
extern char D_004D9200[];
extern void cSfxBundle_ctor(LFx_f4*);
extern LObj_f4* cLightMan_AddLight(void*, int);
extern V4_f4* tRGBA_ctor_tRGBR_float(V4_f4*, LDesc_f4*, float);
extern void cLightSrc_ctor_eLightSrcTypes_tRGBAR_cVectorR_uint(LObj_f4*, int, V4_f4*, float*, int);
extern void LightEffect_SetInner(LObj_f4*, float);
extern void LightEffect_SetOuter(LObj_f4*, float);
#if 0 /* merge_units */
extern void cSfxScheduler_AddItem(LFx_f4*, LObj_f4*, float, float);
#endif /* merge_units */
#define cSfxScheduler_AddItem(a0, a1, a2, a3) (cSfxScheduler_AddItem((void *)(a0), (void *)(a1), (a2), (a3))) /* merge_units */


LFx_f4* cLightBundle_ctor(LFx_f4* self, LDesc_f4* d)
{
    LObj_f4* o;
    cSfxBundle_ctor(self);
    self->vt = ((char*)D_004DBB20);
    o = cLightMan_AddLight(g_LightMgr, 4);
    if (o) {
        float a, b;
        V4_f4 v;
        b = d->b;
        a = d->a;
        cLightSrc_ctor_eLightSrcTypes_tRGBAR_cVectorR_uint(o, 4, tRGBA_ctor_tRGBR_float(&v, d, 0.0f), d->dir, 3);
        o->vt = D_004D9200;
        LightEffect_SetInner(o, a);
        LightEffect_SetOuter(o, b);
    }
    if (o) {
        cSfxScheduler_AddItem(self, o, 0.0f, d->c);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00231F60(void) {}
#undef cSfxScheduler_AddItem /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00231F60 */

/* merge_units: begin func_00232050 */
#pragma push /* merge_units */
typedef struct {
    void* owner;
    float x;
    float y;
    int pad;
} FxSlot232050;

extern FxSlot232050 D_0055A890[384];
extern int D_0055C090;
extern void* std_list_tItemPtr_push_back(void* list, FxSlot232050** value);

void cSfxScheduler_AddItem(void* list, void* owner, float x, float y) {
    FxSlot232050* found = 0;
    FxSlot232050* tmp;
    float off = *(float*)((char*)list + 0x10);
    float fy = y + off;
    float fx = x + off;
    int i;

    for (i = 0; i < 384; i++) {
        if (D_0055A890[i].owner == 0) {
            found = &D_0055A890[i];
            found->owner = owner;
            found->x = fx;
            found->y = fy;
            D_0055C090++;
            break;
        }
    }
    tmp = found;
    if (found != 0) {
        std_list_tItemPtr_push_back(list, &tmp);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00232050(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00232050 */
