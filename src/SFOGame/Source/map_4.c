/*
 * SFOGame/Source/map: 4 files, 0026C7E0-0026CA70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0026C7E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "map_types.h"

extern int cMap_NextObjective(MapEntry* entry);
extern int cHudTargetManager_GetObjectiveTarget(MapItem* item);

void cMap_Update(MapEntry* entry) {
    MapItem* item = entry->item;

    if (item->unk24 != 0 && cHudTargetManager_GetObjectiveTarget(item) == 0) {
        cMap_NextObjective(entry);
    }
}
static inline void merge_flush_func_0026C7E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0026C7E0 */

/* merge_units: begin func_0026C830 */
#pragma push /* merge_units */
#include "vslot_pad.h"

typedef struct { char pad[0x24]; int state; } Sub26C8;
typedef struct { Sub26C8* sub; } Self26C8;
typedef struct { char pad[0x10]; int kind; } Obj26C8;
#if 0 /* merge_units */
extern Obj26C8* cHudTargetManager_GetObjectiveTarget(Sub26C8* s);
#endif /* merge_units */
#define cHudTargetManager_GetObjectiveTarget(a0) ((Obj26C8 *)cHudTargetManager_GetObjectiveTarget((MapItem *)(a0))) /* merge_units */

extern void cHudTargetManager_SetObjectiveTarget(Sub26C8* s, int v);
extern void cMap_ObjectiveSelected(Self26C8* s);
#if 0 /* merge_units */
extern void cMap_NextObjective(Self26C8* s);
#endif /* merge_units */
#define cMap_NextObjective(a0) ((void)cMap_NextObjective((MapEntry *)(a0))) /* merge_units */

void cMap_TargetRemoved(Self26C8* s, Obj26C8* o) {
    unsigned char ok = 1;
    if (!(o->kind == 1 || o->kind == 2)) ok = 0;
    if (ok && o == cHudTargetManager_GetObjectiveTarget(s->sub)) {
        if (s->sub->state == 1) {
            cHudTargetManager_SetObjectiveTarget(s->sub, 0);
            cMap_ObjectiveSelected(s);
        } else {
            cMap_NextObjective(s);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0026C830(void) {}
#undef cHudTargetManager_GetObjectiveTarget /* merge_units */
#undef cMap_NextObjective /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0026C830 */

/* merge_units: begin func_0026C8D0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Ctl_26C8D0 { VPAD16(a) VPAD2(b) VPAD1(c) virtual unsigned char IsPlayer(); };
struct Hum_26C8D0 { char pad[0xC]; unsigned int flags; char pad10[0x48]; Ctl_26C8D0* ctl; };
struct G_26C8D0 { char pad[0x60]; unsigned char b60; };
struct S_26C8D0 { int f0; int f4; G_26C8D0** f8; };
struct M_26C8D0 { int id; char pad[0xC]; int f10; };
struct Buf_26C8D0 { char b0; char text[0x8F]; };
extern "C" {
extern unsigned char g_IsMultiplayer;
extern int g_Hud;
Hum_26C8D0* nGobjManager_LookupGOBJ_cObjectIdR(M_26C8D0* id);
#if 0 /* merge_units */
int cHudTargetManager_GetObjectiveTarget(int a);
#endif /* merge_units */
#define cHudTargetManager_GetObjectiveTarget(a0) (cHudTargetManager_GetObjectiveTarget((MapItem *)(a0))) /* merge_units */


#if 0 /* merge_units */
void cHudTargetManager_SetObjectiveTarget(int a, M_26C8D0* m);
#endif /* merge_units */
#define cHudTargetManager_SetObjectiveTarget(a0, a1) (cHudTargetManager_SetObjectiveTarget((Sub26C8 *)(a0), (int)(a1))) /* merge_units */


#if 0 /* merge_units */
void cMap_ObjectiveSelected(S_26C8D0* s);
#endif /* merge_units */
#define cMap_ObjectiveSelected(a0) (cMap_ObjectiveSelected((Self26C8 *)(a0))) /* merge_units */


void Hud_FormatPlayerCalloutName(Buf_26C8D0* b, int key, int c);
void cHud_SetCallout(int a, M_26C8D0* m, char* text, int n, int b, int c, float f0, float f1);
void cMap_TargetAdded(S_26C8D0* s, M_26C8D0* m);
}
static inline unsigned char IsPlayer_26C8D0(Hum_26C8D0* h) { unsigned char r = 0; if (h->ctl && h->ctl->IsPlayer()) r = 1; return r; }
static inline int LocalId_26C8D0(Hum_26C8D0* h) { int id; if (g_IsMultiplayer) { if (IsPlayer_26C8D0(h)) id = ((h->flags & 0x7F000000) >> 24) - 1; else id = -1; } else id = 0; return id; }

void cMap_TargetAdded(S_26C8D0* s, M_26C8D0* m)
{
    bool b = m->f10 == 1 || m->f10 == 2;
    if (b) {
        if (!cHudTargetManager_GetObjectiveTarget(s->f0)) {
            cHudTargetManager_SetObjectiveTarget(s->f0, m);
            cMap_ObjectiveSelected(s);
        }
    } else if (m->f10 == 0 && (*s->f8)->b60) {
        Hum_26C8D0* h = nGobjManager_LookupGOBJ_cObjectIdR(m);
        if (h && IsPlayer_26C8D0(h)) {
            int id = LocalId_26C8D0(h);
            if (id >= 0 && id < 4) {
                Buf_26C8D0 buf;
                buf.b0 = 0;
                Hud_FormatPlayerCalloutName(&buf, id, 1);
                cHud_SetCallout(g_Hud, m, buf.text, 4, 1, 0, -1.0f, -1.0f);
            }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0026C8D0(void) {}
#undef cHudTargetManager_GetObjectiveTarget /* merge_units */
#undef cHudTargetManager_SetObjectiveTarget /* merge_units */
#undef cMap_ObjectiveSelected /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0026C8D0 */

/* merge_units: begin func_0026CA70 */
#pragma push /* merge_units */
/* cMap_Render: HUD map draw: push the map transform, draw the map objects sorted by depth through a
 * scene draw map, then draw the map screen with a scaled matrix and restore the camera clip planes. */
#pragma cplusplus on

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
void* cLList_cCAMERA_GOBJPtr_Front(void* l);
void XLib_ClearZBuffer(char* r);
void ProcessVisibility(void* v);
DbObj** std_vector_cVUM_GOBJPtr_opIndex_uint(void* v, int i);
void cInterface_Render(Ctx* c);
void std_tree_pair_float_value_compare_ctor(DbMap* m, void* cmp, void* alloc);
void std_pair_float_cGOBJPtr_ctor(DbPair* p, float* f, DbObj** o);
void std_tree_pair_float_value_compare_insert_multi(DbIt* out, DbMap* m, DbPair* kv);
void cAssocMultiArray_float_cGOBJPtr_Begin(DbIt* out, DbMap* m);
void cAssocMultiArray_float_cGOBJPtr_End(DbIt* out, DbMap* m);
int cAssocMultiArray_float_cGOBJPtr_Iterator_opNe(DbIt* a, DbIt* b);
DbObj** cAssocMultiArray_float_cGOBJPtr_Iterator_opMul(DbIt* it);
void cAssocMultiArray_float_cGOBJPtr_Iterator_opInc(DbIt* it);
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
static inline void* Front(char* l) { return func_00159570(l) ? cLList_cCAMERA_GOBJPtr_Front(l) : 0; }
static inline float GetNear(Slot* s) { return s->b104 ? s->fF0 : s->fF4; }
static inline float GetFar(Slot* s) { return s->b104 ? s->fF8 : s->fFC; }
static inline void SetClip(Slot* s, float z, float n, float f) { s->f100 = z; s->fF4 = n; s->fFC = f; s->b106 = 1; s->b104 = 0; }

extern "C" void cMap_Render(HSelf* self)
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
    ProcessVisibility(self->cull);
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
        std_tree_pair_float_value_compare_insert_multi(&res, &map, &kv);
    }
    for (cAssocMultiArray_float_cGOBJPtr_Begin(&it, &map); cAssocMultiArray_float_cGOBJPtr_End(&e, &map), cAssocMultiArray_float_cGOBJPtr_Iterator_opNe(&it, &e); cAssocMultiArray_float_cGOBJPtr_Iterator_opInc(&it)) {
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
    cInterface_Render(self->ctx);
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
static inline void merge_flush_func_0026CA70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0026CA70 */
