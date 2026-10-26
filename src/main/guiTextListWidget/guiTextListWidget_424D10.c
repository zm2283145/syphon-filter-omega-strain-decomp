/*
 * main/guiTextListWidget: 6 files, 00424D10-00425600
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00424D10 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_00424D10, std_vector_imp_int_1_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00424D10 */

/* merge_units: begin func_00424D70 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(func_00424D70)
#pragma pop /* merge_units */
/* merge_units: end func_00424D70 */

/* merge_units: begin func_00424E60 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Rel* func_00424E60(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end func_00424E60 */

/* merge_units: begin func_00424E80 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "owned_buffer8_dtor.h"

/* Free the owned buffer, optionally delete. */
DEFINE_OWNED_BUFFER8_DTOR(func_00424E80, D_0049AF00)
#pragma pop /* merge_units */
/* merge_units: end func_00424E80 */

/* merge_units: begin func_00424F60 */
#pragma push /* merge_units */
#pragma opt_rebuildconditionals off
#pragma cplusplus on

struct V4 {
    float x, y, z, w;
    V4() {}
    V4(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V4(const V4& s) { *(__int128*)this = *(const __int128*)&s; }
    V4& operator=(const V4& s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&s) : "memory"); void* xx = this; /* dead on purpose: retail keeps this addiu */ return *this; }
} __attribute__((aligned(16)));
typedef struct Mtx { __int128 r[4]; } Mtx;
typedef struct Slot { V4 color; char pad10[0x105 - 0x10]; char b105; char b106; char pad107[0x110 - 0x107]; } Slot;
typedef struct Ent { char pad[0x28]; char* pos; char* c2C; char* c30; char* c34; } Ent;
typedef struct Render {
    char pad0[0xA80];
    Mtx mtx[0x14];
} Render;
typedef struct Rect { float x, y, w, h; } Rect;

extern "C" {
extern char g_Video[];
extern long long D_005381F8;
extern int D_00538C60;
extern int D_00538C64;
extern char D_00538C68;
extern float D_00539170[4];
extern int D_00539210;
extern int D_00539224;
extern int D_00539228;
extern int D_00539238;
extern int D_0053923C;
extern int g_DrawMode;
void XLib_NewStrip(char* r);
void XLib_NextBatchVert(char* r);
void Vec4_Copy(void* d, V4* s);
int* GuiBatch_AddVertexColor(void* out, V4* in);
void XLib_DrawLines(char* r);
void Renderer_FlushBatch(char* r);
}

#define SlotAt(i) ((Slot*)(g_Video + 0x1F0 + (i) * 0x110))
#define EntAt(i) ((Ent*)(g_Video + 0xFB0 + (i) * 0x38))
static inline Mtx* MtxAt(int i) { return &((Render*)g_Video)->mtx[i]; }
static inline void GQR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void UM(void* p) { int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }

static inline V4 Pt(const float& x, const float& y) { return V4(x, y, 1.0f, 0.0f); }

static inline void Vertex(V4* p, V4* c) {
    Ent* e;
    XLib_NextBatchVert(g_Video);
    e = EntAt(D_00539210);
    Vec4_Copy(e->pos + (D_00539224 - 1) * 16, p);
    GuiBatch_AddVertexColor(e->c30 + (D_00539224 - 1) * 16, c);
    D_005381F8 = 0x200000000LL;
}

extern "C" void RenderOutline(Rect* rect, V4* colorp, int alt)
{
    float r[4];
    int save = g_DrawMode;
    { int i = D_00538C64; GQR(MtxAt(i + 1), MtxAt(i)); }
    D_00538C64++;
    UM(MtxAt(D_00538C64));
    g_DrawMode = 0;
    V4 p[4];
    {
        int i = D_00538C60;
        Slot* s;
        float* v;
        D_00538C68 = 1;
        s = SlotAt(i);
        v = D_00539170;
        s->color.x = v[0];
        s->color.y = v[1];
        s->color.z = v[2];
        s->color.w = v[3];
        s->b105 = 1;
        s->b106 = 1;
    }
    {
        r[0] = rect->x; r[1] = rect->y; r[2] = rect->w; r[3] = rect->h;
        r[0] += 1.0f;
        r[1] -= 1.0f;
        r[2] -= 2.0f;
        r[3] -= 2.0f;
        p[0] = Pt(r[0], r[1]);
        p[1] = Pt(r[0] + r[2], r[1]);
        p[2] = Pt(r[0] + r[2], r[1] - r[3]);
        p[3] = Pt(r[0], r[1] - r[3]);
        { unsigned char t; if (g_DrawMode & 1) t = 3; else t = 2; D_00539238 = t; }
        { int m; if (g_DrawMode & 1) m = 0x41; else m = 0x62; D_0053923C = m; }
        D_00539228 = 0;
        {
            int m = D_0053923C;
            Ent* e;
            D_0053923C = m & ~1;
            e = EntAt(D_00539210);
            e->pos += D_00539224 * 16;
            e->c2C += D_00539224 * 16;
            e->c30 += D_00539224 * 16;
            e->c34 += D_00539224 * 16;
            XLib_NewStrip(g_Video);
            D_00539224 = 0;
        }
        Vertex(&p[0], colorp);
        Vertex(&p[1], colorp);
        Vertex(&p[2], colorp);
        Vertex(&p[3], colorp);
        Vertex(&p[0], colorp);
        if (alt) Renderer_FlushBatch(g_Video);
        else XLib_DrawLines(g_Video);
    }
    g_DrawMode = save;
    D_00538C64--;
    D_00538C68 = 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_00424F60 */

/* merge_units: begin func_00425600 */
#pragma push /* merge_units */
Quad* func_00425600(Quad* d, Quad* s) {
    d->a = s->a;
    d->b = s->b;
    d->c = s->c;
    d->d = s->d;
    return d;
}
#pragma pop /* merge_units */
/* merge_units: end func_00425600 */
