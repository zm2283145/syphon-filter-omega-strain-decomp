/*
 * main/SpecFxDefs: range (3 files, 00231F00-00232050)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "v4_asm_copy.h"

/* merge_units: begin func_00231F00 */
#pragma push /* merge_units */
typedef struct { float pos[4]; float dir[4]; float a; float b; float c; } LDesc_f4;
typedef struct { char pad[0x14]; void* vt; } LFx_f4;
LFx_f4* SpawnLightEffect_Construct(LFx_f4* self, LDesc_f4* d); /* gsynth: defined below */typedef struct { __int128 q; } Q231F00;
typedef struct { char p[0x30]; Q231F00 pos; } O231F00;
typedef struct { float sx, sy, sz, pad; Q231F00 pos; int f20; float a; float b; int pad2; } L231F00;
extern void* EffectService_Create(int size);
#if 0 /* merge_units */
extern void SpawnLightEffect_Construct(void* p, L231F00* l);
#endif /* merge_units */
#define SpawnLightEffect_Construct(a0, a1) ((void)SpawnLightEffect_Construct((void *)(a0), (void *)(a1))) /* merge_units */

void Game_SpawnLight(O231F00* o, float a, float b)
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
    p = EffectService_Create(0x18);
    if (p) SpawnLightEffect_Construct(p, &l);
}
#undef SpawnLightEffect_Construct /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00231F00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00231F00 */

/* merge_units: begin func_00231F60 */
#pragma push /* merge_units */
void EffectService_Schedule(void* list, void* owner, float x, float y); /* gsynth: defined below */typedef struct { float x, y, z, w; } V4_f4;


typedef struct { int pad0; void* vt; } LObj_f4;
extern void cLightBundle_dtor();
extern void Effect_Draw();
extern void Effect_Update();
void * const D_004DBB20[8] = { (void*)0x0, (void*)0x0, (void*)cLightBundle_dtor, (void*)Effect_Update, (void*)Effect_Draw, (void*)0x0, (void*)0x0, (void*)0x0 };
extern char g_LightMgr[];
extern char D_004D9200[];
extern void SpecFx_Construct(LFx_f4*);
extern LObj_f4* LightMgr_AllocPoint(void*, int);
extern V4_f4* Vec4_SetFromVec3W(V4_f4*, LDesc_f4*, float);
extern void LevelLight_InitPoint(LObj_f4*, int, V4_f4*, float*, int);
extern void LightEffect_SetInner(LObj_f4*, float);
extern void LightEffect_SetOuter(LObj_f4*, float);
#if 0 /* merge_units */
extern void EffectService_Schedule(LFx_f4*, LObj_f4*, float, float);
#endif /* merge_units */
#define EffectService_Schedule(a0, a1, a2, a3) (EffectService_Schedule((void *)(a0), (void *)(a1), (a2), (a3))) /* merge_units */

LFx_f4* SpawnLightEffect_Construct(LFx_f4* self, LDesc_f4* d)
{
    LObj_f4* o;
    SpecFx_Construct(self);
    self->vt = ((char*)D_004DBB20);
    o = LightMgr_AllocPoint(g_LightMgr, 4);
    if (o) {
        float a, b;
        V4_f4 v;
        b = d->b;
        a = d->a;
        LevelLight_InitPoint(o, 4, Vec4_SetFromVec3W(&v, d, 0.0f), d->dir, 3);
        o->vt = D_004D9200;
        LightEffect_SetInner(o, a);
        LightEffect_SetOuter(o, b);
    }
    if (o) {
        EffectService_Schedule(self, o, 0.0f, d->c);
    }
    return self;
}
#undef EffectService_Schedule /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00231F60(void) {}
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

void EffectService_Schedule(void* list, void* owner, float x, float y) {
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
