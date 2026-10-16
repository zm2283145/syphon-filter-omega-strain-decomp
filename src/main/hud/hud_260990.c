/*
 * main/hud: 8 files, 00260990-00260EC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00260990 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[8]; unsigned char active; char p9[3]; unsigned char c; unsigned char d; char pe[2]; int a10; float v[4]; char p24[4]; float f28; } S_260990;
void ScreenFx_Start(S_260990* s, unsigned char active, float x, float y, float z, float w) {
    s->active = active;
    s->a10 = 0;
    s->v[3] = 0;
    s->v[2] = 0;
    s->v[1] = 0;
    s->v[0] = 0;
    s->c = 0;
    s->d = 0;
    s->v[0] = x;
    s->v[1] = y;
    s->v[2] = z;
    s->v[3] = w;
    if (!s->active) {
        s->f28 = 0.0f;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00260990 */

/* merge_units: begin func_002609E0 */
#pragma push /* merge_units */
typedef struct {
    int target; int current; char pad08[0x28];
    unsigned char b30; unsigned char b31; char pad32[2];
    int f34; float v38; float v3C; float v40; float v44;
} Track2609;
void VisionMgr_SetPendingMode(Track2609* s, int id, int force) {
    if (s->target != id) {
        s->current = id;
        if (force) s->target = id;
    }
    if (s->current == -1 && id != 0) {
        s->current = id;
        s->f34 = 0;
        s->v44 = 0; s->v40 = 0; s->v3C = 0; s->v38 = 0;
        s->b30 = 0;
        s->b31 = 0;
        s->v38 = 0.0f; s->v3C = 1.0f; s->v40 = 0.0f; s->v44 = 0.0f;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_002609E0 */

/* merge_units: begin func_00260A50 */
#pragma push /* merge_units */
typedef struct { char pad[4]; unsigned short w; unsigned short h; } VfxTexInfo;
typedef struct { char pad[0x44]; VfxTexInfo* info; } VfxTexEntry;
typedef struct { int unk00; int unk04; VfxTexEntry** entries; } VfxTexReg;
typedef struct { signed char id; char pad[3]; } VfxFlareId;

typedef struct {
    char pad0[0x19C];
    int tex;
    float w;
    float h;
    char pad1A8[4];
    int x1AC;
    char pad1B0[0x1D4 - 0x1B0];
    int flares[9];
    int x1F8;
} VisionFx;

extern VfxFlareId D_004A7DB0[];
extern VfxTexReg* D_00539248;
extern int* SpecFx_GetEffectDef(int id);

static inline int VfxTexW(int h) { return D_00539248->entries[h]->info->w; }
static inline int VfxTexH(int h) { return D_00539248->entries[h]->info->h; }

void VisionFx_LoadFlareTextures(VisionFx* self)
{
    int i;
    for (i = 0; i < 9; i++) {
        self->flares[i] = *SpecFx_GetEffectDef(D_004A7DB0[i].id);
    }
    self->x1F8 = *SpecFx_GetEffectDef(0x21);
    {
        int t = self->x1F8;
        self->tex = t;
        self->x1AC = 0;
        self->w = VfxTexW(t);
        self->h = VfxTexH(t);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00260A50 */

/* merge_units: begin func_00260B40 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "trivial_dtor.h"

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(func_00260B40)
#pragma pop /* merge_units */
/* merge_units: end func_00260B40 */

/* merge_units: begin func_00260B90 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Fx_260B90 {
    unsigned char active; char p9[3];
    unsigned char c; unsigned char d; char pe[2];
    float a10; float v[4];
    void Reset() { a10 = 0; v[3] = 0; v[2] = 0; v[1] = 0; v[0] = 0; c = 0; d = 0; }
    void Reset2() { a10 = 0.0f; v[3] = 0.0f; v[2] = 0.0f; v[1] = 0.0f; v[0] = 0.0f; c = 0; d = 0; }
};
struct Elem_260B90 {
    float a[3]; float a3;
    float b[4];
    float f20; float f24; float f28;
    unsigned char c2C; unsigned char c2D; char p2E[2];
    float f30;
    char p34[0xC];
    void Init() {
        a[0] = 0.2f; a[1] = 0.2f; a[2] = 0.2f; a3 = 0;
        b[0] = 0.8f; b[1] = 0.8f; b[2] = 0.8f; b[3] = 0.8f;
        f20 = 0; f24 = 0; f28 = 0;
        c2C = 0; c2D = 0;
        f30 = 0.98f;
    }
    void Set(float s, float w, float x) {
        a[0] = s; a[1] = s; a[2] = s; a3 = 0.0f;
        b[0] = 0.8f; b[1] = 0.8f; b[2] = 0.8f; b[3] = 0.8f;
        f20 = 0.0f; f24 = w; f28 = x;
        c2C = 0; c2D = 0;
        f30 = 0.98f;
    }
};
struct Obj_260B90 {
    int f0; int f4;
    Fx_260B90 fx;            /* 0x08 */
    int f24; int f28; float f2C;
    unsigned char b30; unsigned char b31; char p32[2];
    int f34; float v38; float v3C; float v40; float v44;
    char p48[8];
    Elem_260B90 e[5];        /* 0x50 */
    int f190; int f194; float f198; int f19C; float f1A0; float f1A4; float f1A8; int f1AC; float f1B0; float f1B4;
    char p1B8[8];
    float f1C0[4];
};
extern "C" Obj_260B90* func_00260B90(Obj_260B90* o) {
    Elem_260B90* p;
    o->f0 = 0;
    o->f4 = 0;
    o->fx.active = 0;
    o->fx.Reset();
    o->f24 = 0;
    o->f28 = 0;
    o->f2C = 1.0f;
    o->f34 = 0;
    o->v44 = 0; o->v40 = 0; o->v3C = 0; o->v38 = 0;
    o->b30 = 0;
    o->b31 = 0;
    p = o->e; do { p->Init(); p++; } while (p != o->e + 5);
    o->f190 = 0;
    o->f194 = 0;
    o->f198 = 0.0f;
    o->f19C = -1;
    o->f1A0 = 0.0f;
    o->f1A4 = 0.0f;
    o->f1A8 = 1.0f;
    o->f1AC = 0;
    o->f1B0 = 0.0f;
    o->f1B4 = 0.1f;
    o->f1C0[0] = 0.0f; o->f1C0[1] = 0.0f; o->f1C0[2] = 0.0f; o->f1C0[3] = 0.0f;
    o->fx.Reset2();
    o->e[1].Set(2.0f, 20.0f, 0.3f);
    o->e[2].Set(2.0f, 25.0f, 0.5f);
    return o;
}
#pragma pop /* merge_units */
/* merge_units: end func_00260B90 */

/* merge_units: begin func_00260D50 */
#pragma push /* merge_units */
extern void* IeNode_FindChild(void* p);
extern int IeElement_Create(void* obj);

/* Resolves an object with IeNode_FindChild and returns IeElement_Create of it, or 0 if none. */
int Hud_FindOrCreateElement(void* p)
{
    void* obj = IeNode_FindChild(p);
    if (obj)
        return IeElement_Create(obj);
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00260D50 */

/* merge_units: begin func_00260D90 */
#pragma push /* merge_units */
typedef struct { float t, r, g, b; } F260D90_Key;
extern unsigned char D_004F8258;
extern unsigned char D_004F8230;
extern F260D90_Key D_004F8190[];
extern F260D90_Key D_004F80F0[];
float D_0048B0A0 __attribute__((aligned(8))) = 0.9f;
float D_0048B0A8 __attribute__((aligned(8))) = 0.9f;
void Hud_GetLockColour(float* out, float x) {
    int i;
    unsigned char alt = D_004F8258 && D_004F8230;
    F260D90_Key* tab = alt ? D_004F8190 : D_004F80F0;
    for (i = 0; i < 9; i++) {
        float t1 = tab[i + 1].t;
        if (x < t1) {
            F260D90_Key* k = &tab[i];
            float f = (x - k[0].t) / (t1 - k[0].t);
            float r = ((1.0f - f) * k[0].r + f * k[1].r) / 255.0f;
            float g = ((1.0f - f) * k[0].g + f * k[1].g) / 255.0f;
            float b = ((1.0f - f) * k[0].b + f * k[1].b) / 255.0f;
            float a = alt ? D_0048B0A8 : D_0048B0A0;
            out[0] = r;
            out[1] = g;
            out[2] = b;
            out[3] = a;
            return;
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00260D90 */

/* merge_units: begin func_00260EC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


#if 0 /* merge_units */
extern char D_004F8258;
#endif /* merge_units */
#define D_004F8258 (*(char*)&D_004F8258) /* merge_units */


void Hud_SelectColourRamp(int value) {
    D_004F8258 = value;
}
#undef D_004F8258 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00260EC0 */
