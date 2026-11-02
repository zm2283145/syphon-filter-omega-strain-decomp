/*
 * Libs/SFOLib/Source/interface_model: 3 files, 003ED850-003EE360
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003ED850 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_list_cInterfaceElementPtr_end(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* cLListIterator_cInterfaceElementPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cInterfaceElementPtr_begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
static inline void merge_flush_func_003ED850(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003ED850 */

/* merge_units: begin func_003ED880 */
#pragma push /* merge_units */
/* cInterfaceModel::ActuallyDraw (interface_model.cc), matched by lane P1L from the prototype
 * (hash-identical) with the XLib strip helpers of decals.c. The colour components are converted
 * into named locals that are then reassigned, which keeps all four conversions ahead of the
 * products (retail register use); a single-assignment form lets MW forward them. */
#pragma cplusplus on
#pragma inline_depth(8)

struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
} __attribute__((aligned(16)));
struct tPackedRGBA { unsigned char r, g, b, a; };
struct tRGBA {
    float r, g, b, a;
    tRGBA() {}
    tRGBA(float ir, float ig, float ib, float ia) : r(ir), g(ig), b(ib), a(ia) {}
    tRGBA operator*(const tRGBA& o) const { return tRGBA(r * o.r, g * o.g, b * o.b, a * o.a); }
};
struct tUV { float u, v, q, p; tUV() {} tUV(float a, float b, float c, float d) { u = a; v = b; q = c; p = d; } };
struct cXyz { float x, y, z; };
struct cUv { float u, v; };
struct cUvTransform { float offsetU, offsetV, scaleU, scaleV; };
struct cFace { unsigned short xyz[3]; unsigned short uv[3]; unsigned short rgb[3]; };

struct Strip;
typedef struct Ent { char pad[0x24]; Strip* c24; V* pos; V* c2C; V* c30; V* c34; } Ent;
typedef struct Rs {
    char pad[0xFB0];
    Ent ents[1];
} Rs;

struct cInterfaceModel {
    char pad0[0x18];
    int mTexture;
    char pad1c[0x64 - 0x1C];
    unsigned short mXyzSz;
    unsigned short mUvSz;
    unsigned short mRgbSz;
    unsigned short mFaceSz;
    unsigned short mAnimationsSz;
    unsigned short mChildrenSz;
    cXyz* mXyz;
    cUv* mUv;
    tPackedRGBA* mRgb;
    cFace* mFace;
    void* mAnimations;
    cInterfaceModel** mChildren;
    char pad88[0xC0 - 0x88];
    cUvTransform mUvTransform;
};

extern "C" {
typedef struct G {
    int f10; int pad14[3]; int f20; int f24; int f28; int* f2C; int f30; int f34; int f38; int f3C; int pad40[2]; void* f48; int pad4C[33]; int fD0; int padD4; long long fD8;
} G;
extern G D_00539210;
extern char g_Video[];
extern long long D_005381F8;
void XLib_NewStrip(void* s);
void XLib_NextBatchVert(void* s);
void XLib_DrawStrip(void* s);
void cVector_opAssign(V* d, const V* s);
void tIRGBA_opAssign_tRGBAR(V* d, const tRGBA* s);
float tVifFloatToInt_short_4_Bias(void);
V* cVector_ctor_float_float_float_float(V* o, float x, float y, float z, float w);
void cInterfaceModel_Render(cInterfaceModel* m);
}
#define D_00539220 (D_00539210.f20)
#define D_00539224 (D_00539210.f24)
#define D_00539228 (D_00539210.f28)
#define D_0053922C (D_00539210.f2C)
#define D_00539230 (D_00539210.f30)
#define D_00539234 (D_00539210.f34)
#define D_00539238 (D_00539210.f38)
#define D_0053923C (D_00539210.f3C)
#define g_DrawMode (D_00539210.fD0)

#define RS ((Rs*)g_Video)

static inline unsigned char Prim(void) { if (g_DrawMode & 1) return 3; return 2; }
static inline int Mode(void) { if (g_DrawMode & 1) return 0x41; return 0x62; }
static inline void Begin(void)
{
    Ent* e;
    D_00539228 = 0;
    D_00539238 = Prim();
    D_0053923C = Mode();
    D_0053923C &= ~1;
    e = &RS->ents[D_00539210.f10];
    e->pos += D_00539224;
    e->c2C += D_00539224;
    e->c30 += D_00539224;
    e->c34 += D_00539224;
    XLib_NewStrip(g_Video);
    D_00539224 = 0;
}
static inline void Emit(const V& pos, const tRGBA& col, const tUV& uv)
{
    V tmp;
    Ent* e;
    float u;
    XLib_NextBatchVert(g_Video);
    e = &RS->ents[D_00539210.f10];
    cVector_opAssign(&e->pos[D_00539224 - 1], &pos);
    tIRGBA_opAssign_tRGBAR(&e->c30[D_00539224 - 1], &col);
    u = uv.u + tVifFloatToInt_short_4_Bias();
    cVector_opAssign(&e->c34[D_00539224 - 1], cVector_ctor_float_float_float_float(&tmp, u, uv.v + tVifFloatToInt_short_4_Bias(), uv.q, uv.p));
    D_005381F8 = 6LL << 32;
}
static inline void Emit2(const V& pos, const tRGBA& col)
{
    Ent* e;
    XLib_NextBatchVert(g_Video);
    e = &RS->ents[D_00539210.f10];
    cVector_opAssign(&e->pos[D_00539224 - 1], &pos);
    tIRGBA_opAssign_tRGBAR(&e->c30[D_00539224 - 1], &col);
    D_005381F8 = 2LL << 32;
}
struct Strip { int pad[0x20]; int idx[12]; int pad2[4]; };
static inline bool EndStrip(void)
{
    if (D_00539220 > 0 && D_00539230 > 0) {
        int n = D_00539220 - 1;
        if (D_00539234 < 12) {
            Strip* s = RS->ents[D_00539210.f10].c24 + n; int v = D_00539238 - 1 + D_00539230 * D_00539238; s->idx[D_00539234] = v;
            D_00539234++;
        } else {
            if (D_00539220 > 0) D_0053922C[D_00539220 - 1] = D_00539230;
            { int v; int j; Strip* s; v = D_00539238 - 1; s = RS->ents[D_00539210.f10].c24 + D_00539220; j = 0; for (; j < 12; j++) s->idx[j] = v; }
            D_00539230 = 0;
            D_00539234 = 0;
            D_00539228++;
            D_00539220++;
        }
    }
    return true;
}
static inline V XyzV(const cXyz& p) { return V(p.x, p.y, p.z, 1.0f); }

extern "C" void cInterfaceModel_ActuallyDraw(cInterfaceModel* self, const tRGBA& filterColor)
{
    if (self->mFaceSz > 0) {
        Begin();
        unsigned char unkickedPolys = 0;
        tRGBA* scratchColor = (tRGBA*)0x70000000;
        for (int i = 0; i < self->mRgbSz; i++) {
            const tPackedRGBA& c = self->mRgb[i];
            float a = (int)c.a;
            float b = (int)c.b;
            float g = (int)c.g;
            float r = (int)c.r;
            a = 0.003921568f * a * filterColor.a;
            b = 0.003921568f * b * filterColor.b;
            g = 0.003921568f * g * filterColor.g;
            r = 0.003921568f * r * filterColor.r;
            *scratchColor = tRGBA(r, g, b, a);
            scratchColor++;
        }
        tUV* scratchUv = (tUV*)scratchColor;
        for (int i = 0; i < self->mUvSz; i++) {
            const cUv& uv = self->mUv[i];
            *scratchUv = tUV(0.5f + self->mUvTransform.scaleU * (uv.u + self->mUvTransform.offsetU - 0.5f), 0.5f + self->mUvTransform.scaleV * (uv.v + self->mUvTransform.offsetV - 0.5f), 1.0f, 0.0f);
            scratchUv++;
        }
        scratchColor = (tRGBA*)0x70000000;
        scratchUv = (tUV*)(scratchColor + self->mRgbSz);
        for (int i = 0; i < self->mFaceSz; i++) {
            cFace& f = self->mFace[i];
            if (self->mTexture >= 0) {
                Emit(XyzV(self->mXyz[f.xyz[0]]), scratchColor[f.rgb[0]], scratchUv[f.uv[0]]);
                Emit(XyzV(self->mXyz[f.xyz[1]]), scratchColor[f.rgb[1]], scratchUv[f.uv[1]]);
                Emit(XyzV(self->mXyz[f.xyz[2]]), scratchColor[f.rgb[2]], scratchUv[f.uv[2]]);
            } else {
                Emit2(XyzV(self->mXyz[f.xyz[0]]), scratchColor[f.rgb[0]]);
                Emit2(XyzV(self->mXyz[f.xyz[1]]), scratchColor[f.rgb[1]]);
                Emit2(XyzV(self->mXyz[f.xyz[2]]), scratchColor[f.rgb[2]]);
            }
            EndStrip();
            unkickedPolys = 1;
        }
        if (unkickedPolys) {
            XLib_DrawStrip(g_Video);
        }
    }
    for (int i = 0; i < self->mChildrenSz; i++) {
        cInterfaceModel_Render(self->mChildren[i]);
    }
}
static inline void merge_flush_func_003ED880(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003ED880 */

/* merge_units: begin func_003EE360 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } Vec4_003EE360;
typedef struct Node_003EE360 {
    char pad00[0x6E];
    unsigned short count;
    char pad70[0x14];
    struct Node_003EE360** children;
    char pad88[4];
    int hidden;
    char pad90[0x10];
    Vec4_003EE360 color;
} Node_003EE360;
int std_list_imp_voidPtr_size(void* obj);
int cInterfaceModel_IsInstanced(Node_003EE360* self);
int func_003EE5E0(Node_003EE360* self, Vec4_003EE360* v);
void cInterfaceModel_FilterChildren(Node_003EE360* self, Vec4_003EE360* v)
{
    int i;
    for (i = 0; i < self->count; i++) {
        Node_003EE360* c = self->children[i];
        if (c->hidden <= 0) {
            int j;
            c->color.x = v->x;
            c->color.y = v->y;
            c->color.z = v->z;
            c->color.w = v->w;
            for (j = 0; j < c->count; j++) {
                if (std_list_imp_voidPtr_size(&c->children[j]->hidden) <= 0) {
                    Node_003EE360* d = c->children[j];
                    int k;
                    d->color.x = v->x;
                    d->color.y = v->y;
                    d->color.z = v->z;
                    d->color.w = v->w;
                    for (k = 0; k < d->count; k++) {
                        if (cInterfaceModel_IsInstanced(d->children[k]) == 0)
                            func_003EE5E0(d->children[k], v);
                    }
                }
            }
        }
    }
}
static inline void merge_flush_func_003EE360(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EE360 */
