/* HudMap_Draw: HUD map draw: push the map transform, draw the map objects sorted by depth through a
 * scene draw map, then draw the map screen with a scaled matrix and restore the camera clip planes. */
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"

typedef struct Mtx { __int128 r[4]; } Mtx;
struct M4 { float m[4][4]; M4& operator=(const M4& o) { void* d = this; __int128 qa; __int128 qb; const void* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); return *this; } } __attribute__((aligned(16)));
typedef struct Slot { char pad0[0xF0]; float fF0; float fF4; float fF8; float fFC; float f100; unsigned char b104; unsigned char b105; unsigned char b106; char pad107[0x110 - 0x107]; } Slot;
typedef struct Render { char pad0[0xA80]; Mtx mtx[0x14]; } Render;

struct DbObj { VPAD16(a) VPAD4(b) virtual void Draw(); char pad[0x34]; int kind; float depth; };
typedef struct { int a, b, c, d; } DbMap;
typedef struct { float f; DbObj* o; } DbPair;
typedef struct { char* p; } DbIt;
struct Scr { char pad[0x60]; unsigned char b60; };
struct Ctx { Scr* scr; };
struct HSelf { char pad0[8]; Ctx* ctx; char padC[4]; char cull[4]; int count; DbObj** objs; char pad1C[4]; Mtx mtx; };

extern "C" {
extern char g_Video[];
extern int D_00538C60;
extern int D_00538C64;
extern char D_00538C68;
extern int g_DrawMode;
extern int D_005382E4;
extern char g_CameraObject[];
extern float D_0048B278;
extern float D_0048B290;
extern float D_0048B298;
extern float D_0048B2B0;
extern Mtx D_0055C0C0;
extern char D_0055C100;
int func_00159570(void* l);
void* List_Front(void* l);
void XLib_ClearZBuffer(char* r);
void HudMap_Cull(void* v);
DbObj** std_vector_cVUM_GOBJPtr_opIndex_uint(void* v, int i);
void IeScreen_Draw(Ctx* c);
void std_tree_pair_float_value_compare_ctor(DbMap* m, void* cmp, void* alloc);
void std_pair_float_cGOBJPtr_ctor(DbPair* p, float* f, DbObj** o);
void SceneDrawMap_Insert(DbIt* out, DbMap* m, DbPair* kv);
void cAssocMultiArray_float_cGOBJPtr_Begin(DbIt* out, DbMap* m);
void cAssocMultiArray_float_cGOBJPtr_End(DbIt* out, DbMap* m);
int cAssocMultiArray_float_cGOBJPtr_Iterator_opNe(DbIt* a, DbIt* b);
DbObj** cAssocMultiArray_float_cGOBJPtr_Iterator_opMul(DbIt* it);
void TreeIter_Increment(DbIt* it);
void cAssocMultiArray_float_cGOBJPtr_dtor(DbMap* m, short del);
}

#define SlotAt(i) ((Slot*)(g_Video + 0x1F0 + (i) * 0x110))
static inline Mtx* MtxAt(int i) { return &((Render*)g_Video)->mtx[i]; }
static inline void GQR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void UM(void* p) { void* pp = p; int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(pp) : "memory"); }
static inline void MM(void* d, void* a, void* b)
{
    __asm__ volatile("lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); lqc2 vf8, 0x0(%2); lqc2 vf9, 0x10(%2); lqc2 vf10, 0x20(%2); lqc2 vf11, 0x30(%2); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; vmulax.xyzw ACC, vf4, vf9x; vmadday.xyzw ACC, vf5, vf9y; vmaddaz.xyzw ACC, vf6, vf9z; vmaddw.xyzw vf13, vf7, vf9w; vmulax.xyzw ACC, vf4, vf10x; vmadday.xyzw ACC, vf5, vf10y; vmaddaz.xyzw ACC, vf6, vf10z; vmaddw.xyzw vf14, vf7, vf10w; vmulax.xyzw ACC, vf4, vf11x; vmadday.xyzw ACC, vf5, vf11y; vmaddaz.xyzw ACC, vf6, vf11z; vmaddw.xyzw vf15, vf7, vf11w; sqc2 vf12, 0x0(%0); sqc2 vf13, 0x10(%0); sqc2 vf14, 0x20(%0); sqc2 vf15, 0x30(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline void* Front(char* l) { return func_00159570(l) ? List_Front(l) : 0; }
static inline float GetNear(Slot* s) { return s->b104 ? s->fF0 : s->fF4; }
static inline float GetFar(Slot* s) { return s->b104 ? s->fF8 : s->fFC; }
static inline void SetClip(Slot* s, float z, float n, float f) { s->f100 = z; s->fF4 = n; s->fFC = f; s->b106 = 1; s->b104 = 0; }

extern "C" void HudMap_Draw(HSelf* self)
{
    DbIt res;
    char cmp[4];
    char alloc[4];
    float f;
    DbObj* o;
    DbIt it;
    DbIt e;
    DbPair kv;
    DbPair tmp;
    DbMap map;
    M4 m208;
    M4 m144;
    M4 m80;
    float nearZ, farZ;
    int i;
    if (!self->ctx->scr->b60)
        return;
    nearZ = GetNear(SlotAt(D_00538C60));
    farZ = GetFar(SlotAt(D_00538C60));
    Front(g_CameraObject);
    { int k = D_00538C64; GQR(MtxAt(k + 1), MtxAt(k)); }
    D_00538C64++;
    GQR(MtxAt(D_00538C64), &self->mtx);
    D_00538C68 = 1;
    SetClip(SlotAt(D_00538C60), D_0048B2B0, D_0048B298, D_0048B290);
    g_DrawMode = 1;
    XLib_ClearZBuffer(g_Video);
    D_005382E4 = 2;
    HudMap_Cull(self->cull);
    std_tree_pair_float_value_compare_ctor(&map, cmp, alloc);
    for (i = 0; i < self->count; i++) {
        if (self->objs[i]->kind == 128)
            continue;
        DbObj* q = *std_vector_cVUM_GOBJPtr_opIndex_uint(self->cull, i);
        float d = (*std_vector_cVUM_GOBJPtr_opIndex_uint(self->cull, i))->depth;
        o = q;
        f = d;
        std_pair_float_cGOBJPtr_ctor(&tmp, &f, &o);
        kv.f = tmp.f;
        kv.o = tmp.o;
        SceneDrawMap_Insert(&res, &map, &kv);
    }
    for (cAssocMultiArray_float_cGOBJPtr_Begin(&it, &map); cAssocMultiArray_float_cGOBJPtr_End(&e, &map), cAssocMultiArray_float_cGOBJPtr_Iterator_opNe(&it, &e); TreeIter_Increment(&it)) {
        DbObj* d = *cAssocMultiArray_float_cGOBJPtr_Iterator_opMul(&it);
        d->Draw();
    }
    cAssocMultiArray_float_cGOBJPtr_dtor(&map, -1);
    g_DrawMode = 0;
    D_00538C68 = 1;
    D_00538C64--;
    XLib_ClearZBuffer(g_Video);
    SetClip(SlotAt(D_00538C60), D_0048B2B0, 1.25f, D_0048B290);
    D_005382E4 = 1;
    UM(&m208);
    {
        M4* pd = &m80;
        M4* pm = &m208;
        float s = D_0048B278;
        m208.m[0][0] *= s; m208.m[0][1] *= s; m208.m[0][2] *= s;
        m208.m[1][0] *= s; m208.m[1][1] *= s; m208.m[1][2] *= s;
        m208.m[2][0] *= s; m208.m[2][1] *= s; m208.m[2][2] *= s;
    MM(pd, &self->mtx, pm);
    }
    m144 = m80;
    *(M4*)&D_0055C0C0 = m144;
    D_0055C100 = 1;
    IeScreen_Draw(self->ctx);
    UM(&D_0055C0C0);
    D_005382E4 = 2;
    D_0055C100 = 0;
    XLib_ClearZBuffer(g_Video);
    {
        Slot* s = SlotAt(D_00538C60);
        s->fF0 = nearZ;
        s->fF8 = farZ;
        s->b106 = 1;
        s->b104 = 1;
    }
}
